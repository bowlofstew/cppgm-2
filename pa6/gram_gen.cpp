

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


class RuleTerm {
  public:
    enum RuleTermType {
        NONE,
        PLUS,  
        QUES,
        STAR
    };

    string           name;
    RuleTermType     type;
    vector<RuleTerm> terms;

    void dump() {
        if (terms.size() > 0) {
            cout << "(";
            for (unsigned i=0; i<terms.size(); i++) {
                terms[i].dump();
                if (i<terms.size()-1) {
                    cout << " ";
                }
            }
            cout << ")";
        }
        else {
            cout << name;
        }
        
        if (type == PLUS) {
            cout << "+";
        }
        else if (type == STAR) {
            cout << "*";
        }    
        else if (type == QUES) {
            cout << "?";
        }
    }



};


class Rule {
  public:
    string                      name; 
    vector< vector<RuleTerm> >  derives;
    int                         canBeEmpty;
    set<string>                 firstTokens;
    set<string>                 followTokens;

    Rule () {
        canBeEmpty = -1;
    }
    
    void dump() {
        cout << name << ":" << endl;
        for (unsigned i=0 ; i<derives.size() ; i++) 
        {
            cout << "\t";
            for (unsigned j=0; j<derives[i].size(); j++) 
            {
                derives[i][j].dump();
                if (j<derives[i].size()-1) {
                    cout << " ";
                }
            } 
            cout << endl;
        }
    }
};


struct deriveSort {
  bool operator() ( const vector<RuleTerm>& v1, const vector<RuleTerm>& v2)
  {
      return (v1.size() >= v2.size());
  }
} derive_sort;


class GramGen 
{
  public:

    string match() {
        string r = *mit;
        mit++;
        return r;
    }

 
    string match(string s) {
        if (*mit == s) {
            string r = *mit;
            mit++;
            return r;
        }
        else {
            cout << "error!! matching " << s << endl;
            exit(1);
            return "";
        }
    }


    RuleTerm parseTerm() {
        RuleTerm rt;
        rt.type = RuleTerm::NONE;

        if ( *mit == "(" ) {
            match("(");
            while ( *mit != ")" ) {
                rt.terms = parseRuleTerms();
            }
            match(")");
        }
        else {
            rt.name = match();
            rt.type = RuleTerm::NONE;
        }

        if ( *mit == "+") {
            rt.type = RuleTerm::PLUS;
            mit++;
        }
        else if (*mit == "*") {
            rt.type = RuleTerm::STAR;
            mit++;
        }
        else if (*mit == "?") {
            rt.type = RuleTerm::QUES;
            mit++;
        }
        else { 
            // no qualifier
        }

        return rt;
    }



    vector<RuleTerm> parseRuleTerms() {
        vector<RuleTerm> rv;

        while ( *mit != "\n" && *mit != ")" ) {
            RuleTerm rt = parseTerm();
            rv.push_back(rt);
        }

        return rv;
    }


    Rule* parseRule() {
        Rule *rule = new Rule();
        
        rule->name = match();
        match(":");    
        match("\n");

        while ( *mit == "\t") {
            match("\t");
            vector<RuleTerm> terms = parseRuleTerms();
            match("\n");
            rule->derives.push_back( terms );
        }

        return rule;
    }


    bool can_be_empty(Rule& rule) 
    {
        if (rule.canBeEmpty >= 0) 
        {
            return rule.canBeEmpty == 0 ? false : true;
        }

        for (unsigned i=0; i<rule.derives.size() ; i++) 
        {
            bool canBeEmpty = true;

            for (unsigned j=0; j<rule.derives[i].size(); j++)
            {
                canBeEmpty = canBeEmpty && can_be_empty( rule.derives[i][j] ); 
            }

            if (canBeEmpty == true) 
            {
                rule.canBeEmpty = 1;
                return true;
            }
        }
        rule.canBeEmpty = 0;
        return false;
    }


    bool can_be_empty(RuleTerm& term)
    {
        if (term.type == RuleTerm::NONE)
        {
            for (unsigned i=0; i<rules.size() ; i++) 
            {
                if (rules[i]->name == term.name) 
                {
                    return can_be_empty( *rules[i] );
                }        
            }
            return false;
        }
        else if (term.type == RuleTerm::STAR || term.type == RuleTerm::QUES)
        {
            return true;
        }
        else // if (term.type == RuleTerm::PLUS)
        {
            if (term.terms.size() == 0) 
            {
                for (unsigned i=0; i<rules.size() ; i++) 
                {
                    if (rules[i]->name == term.name) 
                    {
                        return can_be_empty( *rules[i] );
                    }        
                }
                return false;
            }
            else 
            {
                for (unsigned i=0; i<term.terms.size(); i++) 
                {
                    if ( can_be_empty( term.terms[i] ) == false) 
                    {
                        return false;
                    } 
                }
                return true;
            }
        }
    }


    void update_empty()
    {
        for (unsigned i=0; i<rules.size(); i++) 
        {
            can_be_empty( *rules[i] );
        }
    }


    set<string> find_FIRST(RuleTerm& term) 
    {
        if (term.type == RuleTerm::NONE) 
        {
            if ( isNonTerminal(term.name) ) {
                map<string, Rule*>::iterator mit = this->nonTerminalMap.find( term.name );
                return find_FIRST( *(mit->second) );
            }
            else {
                // terminal
                set<string> s;
                s.insert( term.name );
                return s;
            }
        }
        else if ( term.type == RuleTerm::QUES || term.type == RuleTerm::PLUS || term.type == RuleTerm::STAR) 
        {
            set<string> s;
            if (term.type == RuleTerm::QUES || term.type == RuleTerm::STAR)
            {
                s.insert("$");
            }

            if (term.terms.size() == 0) 
            {
                if ( isNonTerminal(term.name) ) {
                    map<string, Rule*>::iterator mit = this->nonTerminalMap.find( term.name );
                    set<string> s0 = find_FIRST( *(mit->second) );
                    s.insert(s0.begin(), s0.end());
                }
                else {
                    // terminal
                    s.insert( term.name );
                }
            } 
            else 
            {
                for (unsigned i=0; i<term.terms.size() ; i++) 
                {
                    set<string> s1 = find_FIRST( term.terms[i]);
                    s.insert(s1.begin(), s1.end());
                    if (s1.find("$") == s1.end()) {
                        break; 
                    }
                }
            }
            return s;
        }

        return set<string>();
    }


    set<string> find_FIRST(vector<RuleTerm>& deriveTerms) 
    {
        set<string> rslt;

        for (unsigned i=0; i<deriveTerms.size(); i++) {
            set<string> s = find_FIRST( deriveTerms[i] );
            set<string>::iterator emptyIt = s.find("$");
            bool has_empty = (emptyIt != s.end()) ? true : false;
            
            if ( has_empty  && i < deriveTerms.size()-1) {
                // we can not know whether we could keep "$" in the set or not
                // until the last term of the derive
                s.erase( emptyIt ); 
            }

            rslt.insert(s.begin(), s.end());
            if ( has_empty == false ) {  // when this term has no "$"
                break;
            }
        }
        return rslt;
    }


    set<string> find_FIRST( Rule& rule ) 
    {
        if (rule.firstTokens.size() > 0) {
            return rule.firstTokens;
        }

        set<string> rslt;
        for (unsigned j=0; j<rule.derives.size(); j++) {
            set<string> s = find_FIRST( rule.derives[j] ); 
            rslt.insert(s.begin(), s.end());
        }
        return rslt;
    }

 
    void create_FIRST() 
    {
        for (unsigned i=0; i<rules.size(); i++) 
        {
            set<string> s = find_FIRST( *rules[i] );        
            rules[i]->firstTokens = s;

            // dump for debug
            cout <<  rules[i]->name << " TOKENS: " << endl;
            for (set<string>::iterator sit = s.begin(); sit != s.end(); ++sit)
            {
                cout << "  " << *sit;
            }
            cout << endl << endl;;
        }
    }


    set<string> create_FOLLOW( RuleTerm& term, set<string> follow_tokens ) 
    {
        if (term.terms.size() > 0) 
        {
            // multiple term
            for (int i=(int)term.terms.size()-1; i>=0 ; --i) 
            {
                follow_tokens = create_FOLLOW( term.terms[i], follow_tokens );
            } 
            return follow_tokens;
        }
        else 
        {
            // single term
            if ( isNonTerminal( term.name ) ) 
            {
                Rule* rule = nonTerminalMap.find( term.name )->second;
                rule->followTokens.insert( follow_tokens.begin(), follow_tokens.end());

                set<string> first = rule->firstTokens;
                if (first.find("$") != first.end()) 
                {
                    first.insert( follow_tokens.begin() , follow_tokens.end() );
                    first.erase( "$" );
                }
                return first;
            }
            else 
            {
                if (term.type == RuleTerm::QUES || term.type == RuleTerm::STAR) 
                {
                    follow_tokens.insert( term.name );
                }
                else {
                    follow_tokens.clear();
                    follow_tokens.insert(term.name);
                }
                return follow_tokens;
            }
        }
    }


    void create_FOLLOW_iteration() 
    {
        // the first rule is the root, "translation-unit"

        for (unsigned i=0; i<rules.size(); i++) 
        {
            for (unsigned j=0; j<rules[i]->derives.size() ; j++) 
            {
                // for each derive scan token one by one
                set<string> follow = find_FIRST( rules[i]->derives[j].back() );
                follow.erase( "$" );

                for (int k=(int)rules[i]->derives[j].size() -2; k>=0; k--) 
                {
                    follow = create_FOLLOW( rules[i]->derives[j][k] , follow);
                }
            }

        }

        rules[0]->followTokens.insert("$");

        for (unsigned i=0 ; i<rules.size() ; i++) 
        {
            for (unsigned j=0; j<rules[i]->derives.size() ; j++) 
            {
                set<string> follow = rules[i]->followTokens; 
                for (int k=(int)rules[i]->derives[j].size()-1; k>=0; k--) 
                {
                    follow = create_FOLLOW( rules[i]->derives[j][k] , follow);
                }
            } 
        }



    }


    void create_FOLLOW() {
        int follow_token_count = -1;

        while (1) {
            create_FOLLOW_iteration();
            int count = 0;
            for (unsigned i=0; i<rules.size(); i++) {
                count += rules[i]->followTokens.size(); 
            }
            if (follow_token_count == -1) {
                follow_token_count = count;
            }
            else if (count == follow_token_count) {
                break;
            }
            else {
                follow_token_count = count;
            }
        }

        // dump for debug
        for (unsigned i=0 ; i<rules.size() ; i++) 
        {
            set<string> s = rules[i]->followTokens;
            cout <<  rules[i]->name << " FOLLOW TOKENS: " << endl;
            for (set<string>::iterator sit = s.begin(); sit != s.end(); ++sit)
            {
                cout << "  " << *sit;
            }
            cout << endl << endl;;
        }            


    }
    
    void parse(vector<string> ts) 
    {
        tokens = ts;
        mit = tokens.begin();
        while (mit != tokens.end()) 
        {
            if (*mit == "\n") {
                mit++;
                continue;
            }
            Rule *rule = parseRule();     
            sort( rule->derives.begin(), rule->derives.end(), derive_sort );
            rules.push_back(rule);
            nonTerminalMap[rule->name] = rule;
        }

        update_empty();
        create_FIRST();  // should be after "update_empty", referring to its result
        create_FOLLOW();

        // start to generate code
        //
	    generateCode(); 
    }


    string replaceStr(string s, char a, char b) 
    {
        for (unsigned i=0; i<s.size(); i++) {
            if (s[i] == a) {
                s[i] = b;
            }
        }
        return s;
    }


    string generateTokenName( string t )
    {
        if (t == "identifier") 
        {
            return "PT_SIMPLE";
        }
        else {
            string s = "PT_";
            s += t;
            return s;
        }
    }


    string generateCodeToken(string rID, string token, string indent)
    {
        stringstream code; 
        stringstream tmpss;

        if ( isNonTerminal( token ) ) 
        {
            tmpss << "parse__" << replaceStr( token , '-' , '_') << "();"; 
            code << indent << "CppAstPtr " << rID << " = " << tmpss.str() << endl;

            map<string,Rule*>::iterator mit = this->nonTerminalMap.find( token );
            if (mit->second->canBeEmpty == 0)    
            {
                code << indent << "if (" << rID << "->size()==0) {" << endl;
                code << indent << "    break;" << endl;
                code << indent << "}" << endl;
            }
        }
        else 
        {
            tmpss << "match(" << generateTokenName( token ) << ");"; 
            code << indent << "CppAstPtr " << rID << " = " << tmpss.str() << endl;
            code << indent << "if (" << rID << "->size()==0) {" << endl;
            code << indent << "    break;" << endl;
            code << indent << "}" << endl;
        }

        return code.str();
    }


    string generateCodeTokenTerm(string rID, RuleTerm& ruleTerm, string indent)
    {
        stringstream code; 

        if (ruleTerm.type == RuleTerm::NONE)
        {
            code << generateCodeToken( rID, ruleTerm.name, indent);
        }
        else if (ruleTerm.type == RuleTerm::QUES)
        {
            stringstream tmpss;
            string token = ruleTerm.name;
            if ( isNonTerminal( token ) ) 
            {
                tmpss << "parse__" << replaceStr( token , '-' , '_') << "();"; 
            }
            else 
            {
                tmpss << "match(" << generateTokenName( token ) << ");"; 
            }

            code << indent << "CppAstPtr " << rID << " = " << tmpss.str() << endl;
        }
        else if (ruleTerm.type == RuleTerm::PLUS)
        {
            stringstream tmpss;
            string token = ruleTerm.name;
            int canBeEmpty = 0;

            if ( isNonTerminal( token ) ) 
            {
                tmpss << "parse__" << replaceStr( token , '-' , '_') << "();"; 

                map<string,Rule*>::iterator mit = this->nonTerminalMap.find( token );
                canBeEmpty = mit->second->canBeEmpty;
            }
            else 
            {
                tmpss << "match(" << generateTokenName( token ) << ");"; 
            }


            string ptrStr = rID;
            ptrStr += "_ptr";

            string idxStr = "idx_";
            idxStr += rID;

            code << indent << "CompAst* " << ptrStr << " = new CompAst();" << endl;
            code << indent << "int " << idxStr << " = 0;" << endl;
            code << indent << "CppAstPtr firstPtr = " << tmpss.str() << endl;
            if (canBeEmpty == 0) {
                code << indent << "if (firstPtr->size() == 0) {" << endl;
                code << indent << "    break;" << endl;
                code << indent << "}" << endl;
            }
            code << indent << ptrStr << "->astMap[to_string(" << idxStr << ")] = firstPtr;" << endl;
            code << indent << idxStr << "++;" << endl;
            code << indent << "while (true) {" << endl;
            code << indent << "    CppAstPtr iterPtr = " << tmpss.str() << endl;
            code << indent << "    if (iterPtr->size() == 0) {" << endl; 
            code << indent << "         break;" << endl; 
            code << indent << "    }" << endl; 
            code << indent << "    " << ptrStr << "->astMap[to_string(" << idxStr << ")] = iterPtr;" << endl; 
            code << indent << "    "<< idxStr << "++;" << endl; 
            code << indent << "    continue;" << endl; 
            code << indent << "}" << endl;
            code << indent << "CppAstPtr "<< rID << "(" << ptrStr << ");" << endl;
        }
        else if (ruleTerm.type == RuleTerm::STAR)
        {
            stringstream tmpss;
            string token = ruleTerm.name;

            if ( isNonTerminal( token ) ) 
            {
                tmpss << "parse__" << replaceStr( token , '-' , '_') << "();"; 
            }
            else 
            {
                tmpss << "match(" << generateTokenName( token ) << ");" ; 
            }

            string ptrStr = rID;
            ptrStr += "_ptr";

            string idxStr = "idx_";
            idxStr += rID;

            code << indent << "CompAst* " << ptrStr << " = new CompAst();" << endl;
            code << indent << "int " << idxStr << " = 0;" << endl;
            code << indent << "while (true) {" << endl;
            code << indent << "    CppAstPtr iterPtr = " << tmpss.str() << endl;
            code << indent << "    if (iterPtr->size() == 0) {" << endl; 
            code << indent << "         break;" << endl; 
            code << indent << "    }" << endl; 
            code << indent << "    " << ptrStr << "->astMap[to_string(" << idxStr << ")] = iterPtr;" << endl; 
            code << indent << "    "<< idxStr << "++;" << endl; 
            code << indent << "    continue;" << endl; 
            code << indent << "}" << endl;
            code << indent << "CppAstPtr "<< rID << "(" << ptrStr << ");" << endl;
        }

        return code.str();
    }


    string generateCodeTerm(string rID, RuleTerm& ruleTerm, string indent)
    {
        stringstream code;

        if (ruleTerm.terms.size() == 0) 
        {
            return generateCodeTokenTerm(rID, ruleTerm, indent);
        }
        else if (ruleTerm.type == RuleTerm::QUES)
        {
            vector<string> subIDs;

            string ptrStr = rID;
            ptrStr += "_ptr";

            string idxStr = "idx_";
            idxStr += rID;

            string bakStr = "bakPos_";
            bakStr += rID;

            string sub_indent = indent;                 
            sub_indent += "    ";

            // code << indent << "PtIt " << bakStr << " = _ptIt;" << endl; 
            code << indent << "CompAst* " << ptrStr << " = new CompAst();"  << endl; 
            code << indent << "do {" << endl; 
            //code << indent << "for (int rich=0; rich<1 ; rich++) {" << endl; 
            for (unsigned i=0; i<ruleTerm.terms.size(); i++) 
            {
                string sub_rID = rID;
                sub_rID += to_string(i);
                                
                code << generateCodeTokenTerm(sub_rID, ruleTerm.terms[i], sub_indent);

                subIDs.push_back( sub_rID );
            }

            for (unsigned j=0; j<subIDs.size(); j++) 
            {
                code << sub_indent << ptrStr << "->astMap[\"" << subIDs[j] << "\"] = " << subIDs[j] << ";" << endl;
            }
            // code << sub_indent <<  bakStr << " = _ptIt;" << endl;
            // code << sub_indent <<  "cout << \"BACKTO :\" <<  _ptIt->source << endl;" << endl;

            code << indent << "}" << endl; 
            code << indent << "while (false);" << endl; 
            // code << indent << "_ptIt = " << bakStr << ";" << endl;
            code << indent << "CppAstPtr " << rID << "( " << ptrStr << " );" << endl;

        }
        else if (ruleTerm.type == RuleTerm::STAR)
        {
            vector<string> subIDs;

            string ptrStr = rID;
            ptrStr += "_ptr";

            string idxStr = "idx_";
            idxStr += rID;

            string bakStr = "bakPos_";
            bakStr += rID;

            string sub_indent = indent;                 
            sub_indent += "    ";

            // code << indent << "PtIt " << bakStr << " = _ptIt;" << endl; 
            code << indent << "CompAst* " << ptrStr << " = new CompAst();"  << endl; 
            code << indent << "while (true) {" << endl; 
            for (unsigned i=0; i<ruleTerm.terms.size(); i++) 
            {
                string sub_rID = rID;
                sub_rID += to_string(i);
                                
                code << generateCodeTokenTerm(sub_rID, ruleTerm.terms[i], sub_indent);

                subIDs.push_back( sub_rID );
            }

            for (unsigned j=0; j<subIDs.size(); j++) 
            {
                code << sub_indent << ptrStr << "->astMap[\"" << subIDs[j] << "\"] = " << subIDs[j] << ";" << endl;
            }
            // code << sub_indent <<  bakStr << " = _ptIt;" << endl; 

            code << indent << "}" << endl; 
            // code << indent << "_ptIt = " << bakStr << ";" << endl; 
            code << indent <<  "cout << \"BACKTO :\" <<  _ptIt->source << endl;" << endl;

            // if (ruleTerm.type == RuleTerm::PLUS)
            // {
            //     code << indent << "if (" << ptrStr << "->size()==0) {"  << endl;
            //     code << indent << "    break;"  << endl;
            //     code << indent << "}"  << endl;
            // }
            code << indent << "CppAstPtr " << rID << "( " << ptrStr << " );" << endl;
        }
        else if (ruleTerm.type == RuleTerm::PLUS)
        {
            vector<string> subIDs;

            string ptrStr = rID;
            ptrStr += "_ptr";

            string idxStr = "idx_";
            idxStr += rID;

            string bakStr = "bakPos_";
            bakStr += rID;

            string sub_indent = indent;                 
            sub_indent += "    ";

            // code << indent << "PtIt " << bakStr << " = _ptIt;" << endl; 
            code << indent << "CompAst* " << ptrStr << " = new CompAst();"  << endl; 
            code << indent << "while (true) {" << endl; 
            for (unsigned i=0; i<ruleTerm.terms.size(); i++) 
            {
                string sub_rID = rID;
                sub_rID += to_string(i);
                                
                code << generateCodeTokenTerm(sub_rID, ruleTerm.terms[i], sub_indent);

                subIDs.push_back( sub_rID );
            }

            for (unsigned j=0; j<subIDs.size(); j++) 
            {
                code << sub_indent << ptrStr << "->astMap[\"" << subIDs[j] << "\"] = " << subIDs[j] << ";" << endl;
            }
            // code << sub_indent <<  bakStr << " = _ptIt;" << endl; 

            code << indent << "}" << endl; 
            // code << indent << "_ptIt = " << bakStr << ";" << endl; 
            code << indent <<  "cout << \"BACKTO :\" <<  _ptIt->source << endl;" << endl;

            if (ruleTerm.type == RuleTerm::PLUS)
            {
                code << indent << "if (" << ptrStr << "->size()==0) {"  << endl;
                code << indent << "    break;"  << endl;
                code << indent << "}"  << endl;
            }
            code << indent << "CppAstPtr " << rID << "( " << ptrStr << " );" << endl;
        }


        return code.str();
    }


    string generateCode_First()
    {
        stringstream ss;
        string indent = "    ";
        for (unsigned i=0; i<rules.size(); i++)
        {
            string nonTerminal = rules[i]->name;
            nonTerminal = replaceStr( nonTerminal, '-', '_');
            ss << indent << "bool is_first_" << nonTerminal << " ( EPostTokenType type )" << endl;
            ss << indent << "{" << endl;
            ss << indent << indent << "if ("; 
            for (set<string>::iterator it=rules[i]->firstTokens.begin() ; it!=rules[i]->firstTokens.end() ; ) 
            {
                if ( *it == "$" ) {
                    ++it;
                    continue;
                }

                ss << " matchType( " << generateTokenName( *it ) << ", type )";
                ++it;
                if (it != rules[i]->firstTokens.end()) {
                    ss << " || ";
                }
            }
            ss << ") {" << endl;
            ss << indent << indent << indent << "return true;"<< endl;
            ss << indent << indent << "}" << endl;
            ss << indent << indent << "return false;"<< endl;
            ss << indent << "}" << endl;
            ss << endl;
        }

        return ss.str();
    }

    string generateCode_FOLLOW()
    {
        stringstream ss;
        string indent = "    ";
        for (unsigned i=0; i<rules.size(); i++)
        {
            string nonTerminal = rules[i]->name;
            nonTerminal = replaceStr( nonTerminal, '-', '_');
            if (nonTerminal == "translation_unit") {
                continue;
            }
            ss << indent << "bool is_follow_" << nonTerminal << " ( EPostTokenType type )" << endl;
            ss << indent << "{" << endl;
            ss << indent << indent << "if ("; 
            for (set<string>::iterator it=rules[i]->followTokens.begin() ; it!=rules[i]->followTokens.end() ; ) 
            {
                if ( *it == "$" ) {
                    ++it;
                    continue;
                }
                ss << " matchType( " << generateTokenName( *it ) << ", type )";
                ++it;
                if (it != rules[i]->followTokens.end()) {
                    ss << " || ";
                }
            }
            ss << ") {" << endl;
            ss << indent << indent << indent << "return true;"<< endl;
            ss << indent << indent << "}" << endl;
            ss << indent << indent << "return false;"<< endl;
            ss << indent << "}" << endl;
            ss << endl;
        }

        return ss.str();
    }




    void generateCode() 
    {
        stringstream code; 

        code << generateCode_First();
        // code << generateCode_FOLLOW();

        for (unsigned i=0 ; i<rules.size(); i++) 
        {
            string nonTerminal = rules[i]->name;
            string indent1 = "    ";
            string indent2 = "        ";
            string indent3 = "            ";
            nonTerminal = replaceStr( nonTerminal, '-', '_'); 

            code << indent1 << "CppAstPtr parse__" << nonTerminal << " ()" << endl;
            code << indent1 << "{" << endl;
            code << indent1 << "    if ( !is_first_" << nonTerminal << "(_ptIt->type) ) {" << endl;
            code << indent1 << "        return CppAstPtr( new EmptyAst() );" << endl;
            code << indent1 << "    }" << endl;
            code << indent1 << endl;
            code << indent1 << "    PtIt bakPos = _ptIt;" << endl;
            code << indent1 << "    Autocat ac( \"" << rules[i]->name << "\" );" << endl;

            for (unsigned j=0; j<rules[i]->derives.size() ; j++)
            {
                vector<string> termIds;
                vector<RuleTerm> derive = rules[i]->derives[j]; 

                code << indent1 << "    do {" << endl;
                // code << indent1 << "    for (int rich=0; rich<1; rich++) {" << endl;
                for (unsigned k=0; k<derive.size(); k++)  
                {
                    stringstream tID;  
                    tID << "t_" << j << "_" << k; 
                    code << generateCodeTerm(tID.str(), derive[k], indent3) << endl;
                    termIds.push_back( tID.str() );

                    // when the last term is done, prepare to return value
                    //
                    if (k==derive.size()-1) 
                    {
                        code << indent3 << "CompAst* ret = new CompAst();" << endl;;
                        for (vector<string>::iterator idIt = termIds.begin(); idIt != termIds.end(); idIt++)
                        {
                            code << indent3 << "ret->astMap[\"" << *idIt << "\"] = " << *idIt << ";" << endl;
                        }
                        code << indent3 << "return CppAstPtr( ret );" << endl;;
                    }
                }
                code << indent1 << "    }" << endl; 
                code << indent1 << "    while (false);" << endl;
                code << indent1 << "    _ptIt = bakPos;" << endl;
                code << indent1 << "    cout << \"BACKTO :\" <<  _ptIt->source << endl;" << endl;
            }

            code << indent1 << "    return CppAstPtr( new EmptyAst() );" << endl;
            code << indent1 << "}" << endl;
            code << endl << endl;
        }

        ofstream myfile;
        myfile.open("code.cpp");
        myfile << code.str();
        myfile.close();
    }

    bool isNonTerminal(string s) 
    {
        map<string, Rule*>::iterator mit = nonTerminalMap.find(s);
        if (mit == nonTerminalMap.end()) {
            return false;
        }
        else {
            return true;
        }
    }

    void dump() {
        for (unsigned i=0; i<rules.size(); i++) {
            rules[i]->dump();
            cout << endl;
        }
    }


    
    

    map<string, Rule*>        nonTerminalMap;         
    vector<string>            tokens;
    vector<string>::iterator  mit;
    vector<Rule*>             rules;
};



void process(string& gramTxt) {
    vector<string> tokens;

    string t = "";
    for (unsigned i=0; i<gramTxt.size(); i++) {
        if (gramTxt[i] == ' ' ) {
            if (t.size() != 0) {
                tokens.push_back( t );
                t = "";
            } 
        }
        else if (gramTxt[i]== '?'  || gramTxt[i]== '+' || gramTxt[i]=='*' || 
                 gramTxt[i]== '('  || gramTxt[i]== ')' ||
                 gramTxt[i]== '\t' || gramTxt[i] == '\n' || gramTxt[i]==':') 
        {
            if (t.size() != 0) {
                tokens.push_back( t );
            }
            t = gramTxt[i];
            tokens.push_back( t );
            t = "";
        }
        else if (gramTxt[i] == '\\') {
            if (gramTxt[i+1] == '\n') {
                i++;
            }
        }
        else {
            t += gramTxt[i];
        }
    }


    GramGen gramgen;
    gramgen.parse( tokens );
    gramgen.dump();    



    
}



int main(int argc, char** args) {
    
    if (argc < 2) {
        cout << "Usage: Input the grammar file." << endl;
    }

    fstream fs; 
    fs.open(args[1], fstream::in);
    stringstream ss;
    ss << fs.rdbuf();
    string gramTxt = ss.str(); 
    fs.close();

    process( gramTxt );

    return 0;
}
