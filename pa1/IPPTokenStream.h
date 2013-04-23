#pragma once

enum PPTokenType {
    PP_WHITESPACE = 0,
    PP_NEWLINE = 1,
    PP_HEADERNAME = 2,
    PP_IDENTIFIER = 3,
    PP_NUMBER = 4,
    PP_CHAR_LITERAL = 5, 
    PP_UD_CHAR_LITERAL = 6, 
    PP_STRING_LITERAL = 7, 
    PP_UD_STRING_LITERAL = 8, 
    PP_OP = 9,
    PP_NONWHITESPACE = 10,
    PP_EOF = 11
};


class PPToken {
public:
    PPToken(PPTokenType t, string s) 
        : type(t), data(s) 
    {
    }
    PPTokenType type;
    string data;
};


struct IPPTokenStream
{
	virtual void emit_whitespace_sequence() = 0;
	virtual void emit_new_line() = 0;
	virtual void emit_header_name(const string& data) = 0;
	virtual void emit_identifier(const string& data) = 0;
	virtual void emit_pp_number(const string& data) = 0;
	virtual void emit_character_literal(const string& data) = 0;
	virtual void emit_user_defined_character_literal(const string& data) = 0;
	virtual void emit_string_literal(const string& data) = 0;
	virtual void emit_user_defined_string_literal(const string& data) = 0;
	virtual void emit_preprocessing_op_or_punc(const string& data) = 0;
	virtual void emit_non_whitespace_char(const string& data) = 0;
	virtual void emit_eof() = 0;

	virtual ~IPPTokenStream() {}
};
