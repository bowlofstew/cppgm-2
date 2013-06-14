// (C) 2013 CPPGM Foundation www.cppgm.org.  All rights reserved.

#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <memory>
#include <cstring>
#include <cstdint>
#include <climits>
#include <map>

#include "utf16.cpp"
#include "pptoken.cpp"

using namespace std;

// See 3.9.1: Fundamental Types
enum EFundamentalType
{
	// 3.9.1.2
	FT_SIGNED_CHAR,
	FT_SHORT_INT,
	FT_INT,
	FT_LONG_INT,
	FT_LONG_LONG_INT,

	// 3.9.1.3
	FT_UNSIGNED_CHAR,
	FT_UNSIGNED_SHORT_INT,
	FT_UNSIGNED_INT,
	FT_UNSIGNED_LONG_INT,
	FT_UNSIGNED_LONG_LONG_INT,

	// 3.9.1.1 / 3.9.1.5
	FT_WCHAR_T,
	FT_CHAR,
	FT_CHAR16_T,
	FT_CHAR32_T,

	// 3.9.1.6
	FT_BOOL,

	// 3.9.1.8
	FT_FLOAT,
	FT_DOUBLE,
	FT_LONG_DOUBLE,

	// 3.9.1.9
	FT_VOID,

	// 3.9.1.10
	FT_NULLPTR_T
};

// FundamentalTypeOf: convert fundamental type T to EFundamentalType
// for example: `FundamentalTypeOf<long int>()` will return `FT_LONG_INT`
template<typename T> constexpr EFundamentalType FundamentalTypeOf();
template<> constexpr EFundamentalType FundamentalTypeOf<signed char>() { return FT_SIGNED_CHAR; }
template<> constexpr EFundamentalType FundamentalTypeOf<short int>() { return FT_SHORT_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<int>() { return FT_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<long int>() { return FT_LONG_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<long long int>() { return FT_LONG_LONG_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<unsigned char>() { return FT_UNSIGNED_CHAR; }
template<> constexpr EFundamentalType FundamentalTypeOf<unsigned short int>() { return FT_UNSIGNED_SHORT_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<unsigned int>() { return FT_UNSIGNED_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<unsigned long int>() { return FT_UNSIGNED_LONG_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<unsigned long long int>() { return FT_UNSIGNED_LONG_LONG_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<wchar_t>() { return FT_WCHAR_T; }
template<> constexpr EFundamentalType FundamentalTypeOf<char>() { return FT_CHAR; }
template<> constexpr EFundamentalType FundamentalTypeOf<char16_t>() { return FT_CHAR16_T; }
template<> constexpr EFundamentalType FundamentalTypeOf<char32_t>() { return FT_CHAR32_T; }
template<> constexpr EFundamentalType FundamentalTypeOf<bool>() { return FT_BOOL; }
template<> constexpr EFundamentalType FundamentalTypeOf<float>() { return FT_FLOAT; }
template<> constexpr EFundamentalType FundamentalTypeOf<double>() { return FT_DOUBLE; }
template<> constexpr EFundamentalType FundamentalTypeOf<long double>() { return FT_LONG_DOUBLE; }
template<> constexpr EFundamentalType FundamentalTypeOf<void>() { return FT_VOID; }
template<> constexpr EFundamentalType FundamentalTypeOf<nullptr_t>() { return FT_NULLPTR_T; }

// convert EFundamentalType to a source code
const map<EFundamentalType, string> FundamentalTypeToStringMap
{
	{FT_SIGNED_CHAR, "signed char"},
	{FT_SHORT_INT, "short int"},
	{FT_INT, "int"},
	{FT_LONG_INT, "long int"},
	{FT_LONG_LONG_INT, "long long int"},
	{FT_UNSIGNED_CHAR, "unsigned char"},
	{FT_UNSIGNED_SHORT_INT, "unsigned short int"},
	{FT_UNSIGNED_INT, "unsigned int"},
	{FT_UNSIGNED_LONG_INT, "unsigned long int"},
	{FT_UNSIGNED_LONG_LONG_INT, "unsigned long long int"},
	{FT_WCHAR_T, "wchar_t"},
	{FT_CHAR, "char"},
	{FT_CHAR16_T, "char16_t"},
	{FT_CHAR32_T, "char32_t"},
	{FT_BOOL, "bool"},
	{FT_FLOAT, "float"},
	{FT_DOUBLE, "double"},
	{FT_LONG_DOUBLE, "long double"},
	{FT_VOID, "void"},
	{FT_NULLPTR_T, "nullptr_t"}
};

// token type enum for `simples`
enum ETokenType
{
	// keywords
	KW_ALIGNAS = 0,
	KW_ALIGNOF,
	KW_ASM,
	KW_AUTO,
	KW_BOOL,
	KW_BREAK,
	KW_CASE,
	KW_CATCH,
	KW_CHAR,
	KW_CHAR16_T,
	KW_CHAR32_T,
	KW_CLASS,
	KW_CONST,
	KW_CONSTEXPR,
	KW_CONST_CAST,
	KW_CONTINUE,
	KW_DECLTYPE,
	KW_DEFAULT,
	KW_DELETE,
	KW_DO,
	KW_DOUBLE,
	KW_DYNAMIC_CAST,
	KW_ELSE,
	KW_ENUM,
	KW_EXPLICIT,
	KW_EXPORT,
	KW_EXTERN,
	KW_FALSE,
	KW_FLOAT,
	KW_FOR,
	KW_FRIEND,
	KW_GOTO,
	KW_IF,
	KW_INLINE,
	KW_INT,
	KW_LONG,
	KW_MUTABLE,
	KW_NAMESPACE,
	KW_NEW,
	KW_NOEXCEPT,
	KW_NULLPTR,
	KW_OPERATOR,
	KW_PRIVATE,
	KW_PROTECTED,
	KW_PUBLIC,
	KW_REGISTER,
	KW_REINTERPET_CAST,
	KW_RETURN,
	KW_SHORT,
	KW_SIGNED,
	KW_SIZEOF,
	KW_STATIC,
	KW_STATIC_ASSERT,
	KW_STATIC_CAST,
	KW_STRUCT,
	KW_SWITCH,
	KW_TEMPLATE,
	KW_THIS,
	KW_THREAD_LOCAL,
	KW_THROW,
	KW_TRUE,
	KW_TRY,
	KW_TYPEDEF,
	KW_TYPEID,
	KW_TYPENAME,
	KW_UNION,
	KW_UNSIGNED,
	KW_USING,
	KW_VIRTUAL,
	KW_VOID,
	KW_VOLATILE,
	KW_WCHAR_T,
	KW_WHILE,

	// operators/punctuation
	OP_LBRACE,
	OP_RBRACE,
	OP_LSQUARE,
	OP_RSQUARE,
	OP_LPAREN,
	OP_RPAREN,
	OP_BOR,
	OP_XOR,
	OP_COMPL,
	OP_AMP,
	OP_LNOT,
	OP_SEMICOLON,
	OP_COLON,
	OP_DOTS,
	OP_QMARK,
	OP_COLON2,
	OP_DOT,
	OP_DOTSTAR,
	OP_PLUS,
	OP_MINUS,
	OP_STAR,
	OP_DIV,
	OP_MOD,
	OP_ASS,
	OP_LT,
	OP_GT,
	OP_PLUSASS,
	OP_MINUSASS,
	OP_STARASS,
	OP_DIVASS,
	OP_MODASS,
	OP_XORASS,
	OP_BANDASS,
	OP_BORASS,
	OP_LSHIFT,
	OP_RSHIFT,
	OP_RSHIFTASS,
	OP_LSHIFTASS,
	OP_EQ,
	OP_NE,
	OP_LE,
	OP_GE,
	OP_LAND,
	OP_LOR,
	OP_INC,
	OP_DEC,
	OP_COMMA,
	OP_ARROWSTAR,
	OP_ARROW,
};

// StringToETokenTypeMap map of `simple` `preprocessing-tokens` to ETokenType
const unordered_map<string, ETokenType> StringToTokenTypeMap =
{
	// keywords
	{"alignas", KW_ALIGNAS},
	{"alignof", KW_ALIGNOF},
	{"asm", KW_ASM},
	{"auto", KW_AUTO},
	{"bool", KW_BOOL},
	{"break", KW_BREAK},
	{"case", KW_CASE},
	{"catch", KW_CATCH},
	{"char", KW_CHAR},
	{"char16_t", KW_CHAR16_T},
	{"char32_t", KW_CHAR32_T},
	{"class", KW_CLASS},
	{"const", KW_CONST},
	{"constexpr", KW_CONSTEXPR},
	{"const_cast", KW_CONST_CAST},
	{"continue", KW_CONTINUE},
	{"decltype", KW_DECLTYPE},
	{"default", KW_DEFAULT},
	{"delete", KW_DELETE},
	{"do", KW_DO},
	{"double", KW_DOUBLE},
	{"dynamic_cast", KW_DYNAMIC_CAST},
	{"else", KW_ELSE},
	{"enum", KW_ENUM},
	{"explicit", KW_EXPLICIT},
	{"export", KW_EXPORT},
	{"extern", KW_EXTERN},
	{"false", KW_FALSE},
	{"float", KW_FLOAT},
	{"for", KW_FOR},
	{"friend", KW_FRIEND},
	{"goto", KW_GOTO},
	{"if", KW_IF},
	{"inline", KW_INLINE},
	{"int", KW_INT},
	{"long", KW_LONG},
	{"mutable", KW_MUTABLE},
	{"namespace", KW_NAMESPACE},
	{"new", KW_NEW},
	{"noexcept", KW_NOEXCEPT},
	{"nullptr", KW_NULLPTR},
	{"operator", KW_OPERATOR},
	{"private", KW_PRIVATE},
	{"protected", KW_PROTECTED},
	{"public", KW_PUBLIC},
	{"register", KW_REGISTER},
	{"reinterpret_cast", KW_REINTERPET_CAST},
	{"return", KW_RETURN},
	{"short", KW_SHORT},
	{"signed", KW_SIGNED},
	{"sizeof", KW_SIZEOF},
	{"static", KW_STATIC},
	{"static_assert", KW_STATIC_ASSERT},
	{"static_cast", KW_STATIC_CAST},
	{"struct", KW_STRUCT},
	{"switch", KW_SWITCH},
	{"template", KW_TEMPLATE},
	{"this", KW_THIS},
	{"thread_local", KW_THREAD_LOCAL},
	{"throw", KW_THROW},
	{"true", KW_TRUE},
	{"try", KW_TRY},
	{"typedef", KW_TYPEDEF},
	{"typeid", KW_TYPEID},
	{"typename", KW_TYPENAME},
	{"union", KW_UNION},
	{"unsigned", KW_UNSIGNED},
	{"using", KW_USING},
	{"virtual", KW_VIRTUAL},
	{"void", KW_VOID},
	{"volatile", KW_VOLATILE},
	{"wchar_t", KW_WCHAR_T},
	{"while", KW_WHILE},

	// operators/punctuation
	{"{", OP_LBRACE},
	{"<%", OP_LBRACE},
	{"}", OP_RBRACE},
	{"%>", OP_RBRACE},
	{"[", OP_LSQUARE},
	{"<:", OP_LSQUARE},
	{"]", OP_RSQUARE},
	{":>", OP_RSQUARE},
	{"(", OP_LPAREN},
	{")", OP_RPAREN},
	{"|", OP_BOR},
	{"bitor", OP_BOR},
	{"^", OP_XOR},
	{"xor", OP_XOR},
	{"~", OP_COMPL},
	{"compl", OP_COMPL},
	{"&", OP_AMP},
	{"bitand", OP_AMP},
	{"!", OP_LNOT},
	{"not", OP_LNOT},
	{";", OP_SEMICOLON},
	{":", OP_COLON},
	{"...", OP_DOTS},
	{"?", OP_QMARK},
	{"::", OP_COLON2},
	{".", OP_DOT},
	{".*", OP_DOTSTAR},
	{"+", OP_PLUS},
	{"-", OP_MINUS},
	{"*", OP_STAR},
	{"/", OP_DIV},
	{"%", OP_MOD},
	{"=", OP_ASS},
	{"<", OP_LT},
	{">", OP_GT},
	{"+=", OP_PLUSASS},
	{"-=", OP_MINUSASS},
	{"*=", OP_STARASS},
	{"/=", OP_DIVASS},
	{"%=", OP_MODASS},
	{"^=", OP_XORASS},
	{"xor_eq", OP_XORASS},
	{"&=", OP_BANDASS},
	{"and_eq", OP_BANDASS},
	{"|=", OP_BORASS},
	{"or_eq", OP_BORASS},
	{"<<", OP_LSHIFT},
	{">>", OP_RSHIFT},
	{">>=", OP_RSHIFTASS},
	{"<<=", OP_LSHIFTASS},
	{"==", OP_EQ},
	{"!=", OP_NE},
	{"not_eq", OP_NE},
	{"<=", OP_LE},
	{">=", OP_GE},
	{"&&", OP_LAND},
	{"and", OP_LAND},
	{"||", OP_LOR},
	{"or", OP_LOR},
	{"++", OP_INC},
	{"--", OP_DEC},
	{",", OP_COMMA},
	{"->*", OP_ARROWSTAR},
	{"->", OP_ARROW}
};

// map of enum to string
const map<ETokenType, string> TokenTypeToStringMap =
{
	{KW_ALIGNAS, "KW_ALIGNAS"},
	{KW_ALIGNOF, "KW_ALIGNOF"},
	{KW_ASM, "KW_ASM"},
	{KW_AUTO, "KW_AUTO"},
	{KW_BOOL, "KW_BOOL"},
	{KW_BREAK, "KW_BREAK"},
	{KW_CASE, "KW_CASE"},
	{KW_CATCH, "KW_CATCH"},
	{KW_CHAR, "KW_CHAR"},
	{KW_CHAR16_T, "KW_CHAR16_T"},
	{KW_CHAR32_T, "KW_CHAR32_T"},
	{KW_CLASS, "KW_CLASS"},
	{KW_CONST, "KW_CONST"},
	{KW_CONSTEXPR, "KW_CONSTEXPR"},
	{KW_CONST_CAST, "KW_CONST_CAST"},
	{KW_CONTINUE, "KW_CONTINUE"},
	{KW_DECLTYPE, "KW_DECLTYPE"},
	{KW_DEFAULT, "KW_DEFAULT"},
	{KW_DELETE, "KW_DELETE"},
	{KW_DO, "KW_DO"},
	{KW_DOUBLE, "KW_DOUBLE"},
	{KW_DYNAMIC_CAST, "KW_DYNAMIC_CAST"},
	{KW_ELSE, "KW_ELSE"},
	{KW_ENUM, "KW_ENUM"},
	{KW_EXPLICIT, "KW_EXPLICIT"},
	{KW_EXPORT, "KW_EXPORT"},
	{KW_EXTERN, "KW_EXTERN"},
	{KW_FALSE, "KW_FALSE"},
	{KW_FLOAT, "KW_FLOAT"},
	{KW_FOR, "KW_FOR"},
	{KW_FRIEND, "KW_FRIEND"},
	{KW_GOTO, "KW_GOTO"},
	{KW_IF, "KW_IF"},
	{KW_INLINE, "KW_INLINE"},
	{KW_INT, "KW_INT"},
	{KW_LONG, "KW_LONG"},
	{KW_MUTABLE, "KW_MUTABLE"},
	{KW_NAMESPACE, "KW_NAMESPACE"},
	{KW_NEW, "KW_NEW"},
	{KW_NOEXCEPT, "KW_NOEXCEPT"},
	{KW_NULLPTR, "KW_NULLPTR"},
	{KW_OPERATOR, "KW_OPERATOR"},
	{KW_PRIVATE, "KW_PRIVATE"},
	{KW_PROTECTED, "KW_PROTECTED"},
	{KW_PUBLIC, "KW_PUBLIC"},
	{KW_REGISTER, "KW_REGISTER"},
	{KW_REINTERPET_CAST, "KW_REINTERPET_CAST"},
	{KW_RETURN, "KW_RETURN"},
	{KW_SHORT, "KW_SHORT"},
	{KW_SIGNED, "KW_SIGNED"},
	{KW_SIZEOF, "KW_SIZEOF"},
	{KW_STATIC, "KW_STATIC"},
	{KW_STATIC_ASSERT, "KW_STATIC_ASSERT"},
	{KW_STATIC_CAST, "KW_STATIC_CAST"},
	{KW_STRUCT, "KW_STRUCT"},
	{KW_SWITCH, "KW_SWITCH"},
	{KW_TEMPLATE, "KW_TEMPLATE"},
	{KW_THIS, "KW_THIS"},
	{KW_THREAD_LOCAL, "KW_THREAD_LOCAL"},
	{KW_THROW, "KW_THROW"},
	{KW_TRUE, "KW_TRUE"},
	{KW_TRY, "KW_TRY"},
	{KW_TYPEDEF, "KW_TYPEDEF"},
	{KW_TYPEID, "KW_TYPEID"},
	{KW_TYPENAME, "KW_TYPENAME"},
	{KW_UNION, "KW_UNION"},
	{KW_UNSIGNED, "KW_UNSIGNED"},
	{KW_USING, "KW_USING"},
	{KW_VIRTUAL, "KW_VIRTUAL"},
	{KW_VOID, "KW_VOID"},
	{KW_VOLATILE, "KW_VOLATILE"},
	{KW_WCHAR_T, "KW_WCHAR_T"},
	{KW_WHILE, "KW_WHILE"},
	{OP_LBRACE, "OP_LBRACE"},
	{OP_RBRACE, "OP_RBRACE"},
	{OP_LSQUARE, "OP_LSQUARE"},
	{OP_RSQUARE, "OP_RSQUARE"},
	{OP_LPAREN, "OP_LPAREN"},
	{OP_RPAREN, "OP_RPAREN"},
	{OP_BOR, "OP_BOR"},
	{OP_XOR, "OP_XOR"},
	{OP_COMPL, "OP_COMPL"},
	{OP_AMP, "OP_AMP"},
	{OP_LNOT, "OP_LNOT"},
	{OP_SEMICOLON, "OP_SEMICOLON"},
	{OP_COLON, "OP_COLON"},
	{OP_DOTS, "OP_DOTS"},
	{OP_QMARK, "OP_QMARK"},
	{OP_COLON2, "OP_COLON2"},
	{OP_DOT, "OP_DOT"},
	{OP_DOTSTAR, "OP_DOTSTAR"},
	{OP_PLUS, "OP_PLUS"},
	{OP_MINUS, "OP_MINUS"},
	{OP_STAR, "OP_STAR"},
	{OP_DIV, "OP_DIV"},
	{OP_MOD, "OP_MOD"},
	{OP_ASS, "OP_ASS"},
	{OP_LT, "OP_LT"},
	{OP_GT, "OP_GT"},
	{OP_PLUSASS, "OP_PLUSASS"},
	{OP_MINUSASS, "OP_MINUSASS"},
	{OP_STARASS, "OP_STARASS"},
	{OP_DIVASS, "OP_DIVASS"},
	{OP_MODASS, "OP_MODASS"},
	{OP_XORASS, "OP_XORASS"},
	{OP_BANDASS, "OP_BANDASS"},
	{OP_BORASS, "OP_BORASS"},
	{OP_LSHIFT, "OP_LSHIFT"},
	{OP_RSHIFT, "OP_RSHIFT"},
	{OP_RSHIFTASS, "OP_RSHIFTASS"},
	{OP_LSHIFTASS, "OP_LSHIFTASS"},
	{OP_EQ, "OP_EQ"},
	{OP_NE, "OP_NE"},
	{OP_LE, "OP_LE"},
	{OP_GE, "OP_GE"},
	{OP_LAND, "OP_LAND"},
	{OP_LOR, "OP_LOR"},
	{OP_INC, "OP_INC"},
	{OP_DEC, "OP_DEC"},
	{OP_COMMA, "OP_COMMA"},
	{OP_ARROWSTAR, "OP_ARROWSTAR"},
	{OP_ARROW, "OP_ARROW"}
};

// convert integer [0,15] to hexadecimal digit
char ValueToHexChar(int c)
{
	switch (c)
	{
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';
	default: throw logic_error("ValueToHexChar of nonhex value");
	}
}


// convert integer [0,15] to hexadecimal digit
int HexCharToValue(char c)
{
	switch (c)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case 'a': 
	case 'A': return 10;
	case 'b':
	case 'B': return 11;
	case 'c':
	case 'C': return 12;
	case 'd':
	case 'D': return 13;
	case 'e':
	case 'E': return 14;
	case 'f':
	case 'F': return 15;
	default: throw logic_error("HexCharToValue of nonhex char");
	}
}



// hex dump memory range
string HexDump(const void* pdata, size_t nbytes)
{
	unsigned char* p = (unsigned char*) pdata;

	string s(nbytes*2, '?');

	for (size_t i = 0; i < nbytes; i++)
	{
		s[2*i+0] = ValueToHexChar((p[i] & 0xF0) >> 4);
		s[2*i+1] = ValueToHexChar((p[i] & 0x0F) >> 0);
	}

	return s;
}

// DebugPostTokenOutputStream: helper class to produce PA2 output format
struct DebugPostTokenOutputStream
{
	// output: invalid <source>
	void emit_invalid(const string& source)
	{
		cout << "invalid " << source << endl;
	}

	// output: simple <source> <token_type>
	void emit_simple(const string& source, ETokenType token_type)
	{
		cout << "simple " << source << " " << TokenTypeToStringMap.at(token_type) << endl;
	}

	// output: identifier <source>
	void emit_identifier(const string& source)
	{
		cout << "identifier " << source << endl;
	}

	// output: literal <source> <type> <hexdump(data,nbytes)>
	void emit_literal(const string& source, EFundamentalType type, const void* data, size_t nbytes)
	{
		cout << "literal " << source << " " << FundamentalTypeToStringMap.at(type) << " " << HexDump(data, nbytes) << endl;
	}

	// output: literal <source> array of <num_elements> <type> <hexdump(data,nbytes)>
	void emit_literal_array(const string& source, size_t num_elements, EFundamentalType type, const void* data, size_t nbytes)
	{
		cout << "literal " << source << " array of " << num_elements << " " << FundamentalTypeToStringMap.at(type) << " " << HexDump(data, nbytes) << endl;
	}

	// output: user-defined-literal <source> <ud_suffix> character <type> <hexdump(data,nbytes)>
	void emit_user_defined_literal_character(const string& source, const string& ud_suffix, EFundamentalType type, const void* data, size_t nbytes)
	{
		cout << "user-defined-literal " << source << " " << ud_suffix << " character " << FundamentalTypeToStringMap.at(type) << " " << HexDump(data, nbytes) << endl;
	}

	// output: user-defined-literal <source> <ud_suffix> string array of <num_elements> <type> <hexdump(data, nbytes)>
	void emit_user_defined_literal_string_array(const string& source, const string& ud_suffix, size_t num_elements, EFundamentalType type, const void* data, size_t nbytes)
	{
		cout << "user-defined-literal " << source << " " << ud_suffix << " string array of " << num_elements << " " << FundamentalTypeToStringMap.at(type) << " " << HexDump(data, nbytes) << endl;
	}

	// output: user-defined-literal <source> <ud_suffix> <prefix>
	void emit_user_defined_literal_integer(const string& source, const string& ud_suffix, const string& prefix)
	{
		cout << "user-defined-literal " << source << " " << ud_suffix << " integer " << prefix << endl;
	}

	// output: user-defined-literal <source> <ud_suffix> <prefix>
	void emit_user_defined_literal_floating(const string& source, const string& ud_suffix, const string& prefix)
	{
		cout << "user-defined-literal " << source << " " << ud_suffix << " floating " << prefix << endl;
	}

	// output : eof
	void emit_eof()
	{
		cout << "eof" << endl;
	}
};


// use these 3 functions to scan `floating-literals` (see PA2)
// for example PA2Decode_float("12.34") returns "12.34" as a `float` type
float PA2Decode_float(const string& s)
{
	istringstream iss(s);
	float x;
	iss >> x;
	return x;
}

double PA2Decode_double(const string& s)
{
	istringstream iss(s);
	double x;
	iss >> x;
	return x;
}

long double PA2Decode_long_double(const string& s)
{
	istringstream iss(s);
	long double x;
	iss >> x;
	return x;
}



class PostTokenizerException : public exception
{
  public:
    PostTokenizerException(const char* msg)
        : _errMsg(msg)
    {
    } 

    virtual ~PostTokenizerException() throw()
    {
    }

    virtual const char* what() const throw()
    {
        return _errMsg.c_str();
    }

  private:
    string _errMsg;
};


enum EPostTokenType
{
    PT_WHITESPACE=0,
    PT_NEWLINE,
    PT_EOF,

    PT_HEADERNAME,
    PT_SIMPLE,

    PT_LITERAL,
    PT_UD_LITERAL,

    PT_INVALID,  // for testing

	PT_KW_ALIGNAS,
	PT_KW_ALIGNOF,
	PT_KW_ASM,
	PT_KW_AUTO,
	PT_KW_BOOL,
	PT_KW_BREAK,
	PT_KW_CASE,
	PT_KW_CATCH,
	PT_KW_CHAR,
	PT_KW_CHAR16_T,
	PT_KW_CHAR32_T,
	PT_KW_CLASS,
	PT_KW_CONST,
	PT_KW_CONSTEXPR,
	PT_KW_CONST_CAST,
	PT_KW_CONTINUE,
	PT_KW_DECLTYPE,
	PT_KW_DEFAULT,
	PT_KW_DELETE,
	PT_KW_DO,
	PT_KW_DOUBLE,
	PT_KW_DYNAMIC_CAST,
	PT_KW_ELSE,
	PT_KW_ENUM,
	PT_KW_EXPLICIT,
	PT_KW_EXPORT,
	PT_KW_EXTERN,
	PT_KW_FALSE,
	PT_KW_FLOAT,
	PT_KW_FOR,
	PT_KW_FRIEND,
	PT_KW_GOTO,
	PT_KW_IF,
	PT_KW_INLINE,
	PT_KW_INT,
	PT_KW_LONG,
	PT_KW_MUTABLE,
	PT_KW_NAMESPACE,
	PT_KW_NEW,
	PT_KW_NOEXCEPT,
	PT_KW_NULLPTR,
	PT_KW_OPERATOR,
	PT_KW_PRIVATE,
	PT_KW_PROTECTED,
	PT_KW_PUBLIC,
	PT_KW_REGISTER,
	PT_KW_REINTERPET_CAST,
	PT_KW_RETURN,
	PT_KW_SHORT,
	PT_KW_SIGNED,
	PT_KW_SIZEOF,
	PT_KW_STATIC,
	PT_KW_STATIC_ASSERT,
	PT_KW_STATIC_CAST,
	PT_KW_STRUCT,
	PT_KW_SWITCH,
	PT_KW_TEMPLATE,
	PT_KW_THIS,
	PT_KW_THREAD_LOCAL,
	PT_KW_THROW,
	PT_KW_TRUE,
	PT_KW_TRY,
	PT_KW_TYPEDEF,
	PT_KW_TYPEID,
	PT_KW_TYPENAME,
	PT_KW_UNION,
	PT_KW_UNSIGNED,
	PT_KW_USING,
	PT_KW_VIRTUAL,
	PT_KW_VOID,
	PT_KW_VOLATILE,
	PT_KW_WCHAR_T,
	PT_KW_WHILE,

	// operators/punctuation
	PT_OP_LBRACE,
	PT_OP_RBRACE,
	PT_OP_LSQUARE,
	PT_OP_RSQUARE,
	PT_OP_LPAREN,
	PT_OP_RPAREN,
	PT_OP_BOR,
	PT_OP_XOR,
	PT_OP_COMPL,
	PT_OP_AMP,
	PT_OP_LNOT,
	PT_OP_SEMICOLON,
	PT_OP_COLON,
	PT_OP_DOTS,
	PT_OP_QMARK,
	PT_OP_COLON2,
	PT_OP_DOT,
	PT_OP_DOTSTAR,
	PT_OP_PLUS,
	PT_OP_MINUS,
	PT_OP_STAR,
	PT_OP_DIV,
	PT_OP_MOD,
	PT_OP_ASS,
	PT_OP_LT,
	PT_OP_GT,
	PT_OP_PLUSASS,
	PT_OP_MINUSASS,
	PT_OP_STARASS,
	PT_OP_DIVASS,
	PT_OP_MODASS,
	PT_OP_XORASS,
	PT_OP_BANDASS,
	PT_OP_BORASS,
	PT_OP_LSHIFT,
	PT_OP_RSHIFT,
	PT_OP_RSHIFTASS,
	PT_OP_LSHIFTASS,
	PT_OP_EQ,
	PT_OP_NE,
	PT_OP_LE,
	PT_OP_GE,
	PT_OP_LAND,
	PT_OP_LOR,
	PT_OP_INC,
	PT_OP_DEC,
	PT_OP_COMMA,
	PT_OP_ARROWSTAR,
	PT_OP_ARROW,

    PT_OP_HASH,      // #
    PT_OP_HASHHASH   // ##
};



struct PostToken
{
    EPostTokenType type;
    string source;
    string udSuffix;

    // for literal
    //
    EFundamentalType ltype;
    int   size;
    void* data;
};


class PostTokenizer
{
  public:
    class PostTokenString
    {
      public:
        vector<int> chars;
        string source;
        string udSuffix;
        int char_width;
    };

    PostTokenizer(vector<PPToken>& pplst)
        : _pplst(pplst)
    {
    }
   

    ~PostTokenizer() 
    {
    }

    vector<PostToken>  _tokens;


    void addToken(EPostTokenType type, string src="", string udSuffix="", EFundamentalType ltype=FT_NULLPTR_T, int size=0, const void* addr=0)
    {
        PostToken pt;
        pt.type = type;
        pt.source = src;
        pt.udSuffix = udSuffix;
        pt.ltype = ltype;
        pt.size = size;
        
        // for different type
        if (size > 0)
        {
            int bsize = size;
            if (ltype==FT_SIGNED_CHAR || ltype==FT_UNSIGNED_CHAR || ltype==FT_CHAR || ltype==FT_BOOL)
            {
                bsize *= 1;
            }
            else if (ltype==FT_SHORT_INT || ltype==FT_UNSIGNED_SHORT_INT || ltype==FT_CHAR16_T)
            {
                bsize *= 2;
            }
            else if (ltype==FT_INT || ltype==FT_UNSIGNED_INT || ltype==FT_CHAR32_T || ltype==FT_WCHAR_T || ltype==FT_FLOAT)
            {
                bsize *= 4;
            }
            else if (ltype==FT_LONG_INT || ltype==FT_LONG_LONG_INT || ltype==FT_UNSIGNED_LONG_INT || ltype==FT_UNSIGNED_LONG_LONG_INT || ltype==FT_DOUBLE || ltype==FT_NULLPTR_T)
            {
                bsize *= 8;
            }
            else if (ltype==FT_LONG_DOUBLE)
            {
                bsize *= 16;
            }

            char* ary = new char[bsize];
            memcpy(ary, (char*)addr, size); 
            pt.data = ary;
        }
        else
        {
            pt.data = 0;
        }

        _tokens.push_back(pt);
    }



    void parse()
    {
        vector<PostTokenString> ppStrLst;
        vector<PPToken>::iterator it = _pplst.begin();

        while (it != _pplst.end())
        {
            PPTokenType type = (*it).type;
            string str = UTF8Encoder::encode( (*it).data );

            if (type < PP_STRING_LITERAL || type > PP_UD_RAW_STRING_LITERAL )
            {
                // otherwise, no need to output concat strings yet.
                if (type != PP_WHITESPACE && type != PP_NEWLINE)
                {
                    emit_strLst(ppStrLst);
                }
            }  

            if (type == PP_WHITESPACE)
            {
                // do nothing, no-op
                addToken(PT_WHITESPACE);
            }
            else if ( type == PP_NEWLINE)
            {
                // do nothing, no-op
                addToken(PT_NEWLINE);
            }
            else if (type == PP_HEADERNAME)
            {
                _out.emit_invalid(UTF8Encoder::encode( (*it).data ));
                addToken(PT_HEADERNAME, UTF8Encoder::encode( (*it).data ));
            }
            else if (type == PP_NONWHITESPACE)
            {
                _out.emit_invalid(UTF8Encoder::encode( (*it).data ));
                addToken(PT_INVALID, UTF8Encoder::encode( (*it).data ));
            }
            else if (type == PP_EOF)
            {
                _out.emit_eof();
                addToken(PT_EOF);
            }
            else if (type == PP_OP || type == PP_IDENTIFIER)
            {
                unordered_map<string, ETokenType>::const_iterator eit = StringToTokenTypeMap.find(str);
                if (eit == StringToTokenTypeMap.end())
                {
                    if ( str == "#" || str == "%:" )
                    {
                        _out.emit_invalid( str );
                        addToken(PT_OP_HASH);
                    }
                    else if (str == "##" || str == "%:%:")
                    {
                        _out.emit_invalid( str );
                        addToken(PT_OP_HASHHASH);
                    }
                    else 
                    {
                        _out.emit_identifier( str );
                        addToken(PT_SIMPLE, str);
                    }
                }
                else
                {
                    // op
                    _out.emit_simple(str, eit->second); 
                    addToken((EPostTokenType) ((int) eit->second + (int)PT_INVALID));
                }
            }
            else if ( type == PP_NUMBER )
            {
                parse_ppnumber( (*it).data );
            }
            else if ( type == PP_CHAR_LITERAL || type == PP_UD_CHAR_LITERAL )
            {
                parse_ppchar( (*it).data );
            }
            else if ( type == PP_STRING_LITERAL || type == PP_RAW_STRING_LITERAL || type == PP_UD_STRING_LITERAL || type == PP_UD_RAW_STRING_LITERAL)
            {
                string source;
                string suffix;
                vector<int> chars;
                vector<int> udSuffix;
                int char_width;
                if (parse_string( (*it).data, source, chars, udSuffix, char_width) == true)
                {
                    PostTokenString p;
                    p.source = source;
                    p.chars = chars;
                    p.char_width = char_width;
                    p.udSuffix = UTF8Encoder::encode(udSuffix); 
                    ppStrLst.push_back(p);
                }
                else
                {
                    emit_strLst(ppStrLst);
                    _out.emit_invalid(source);
                    addToken(PT_INVALID, source);
                }
            }
            else
            {
                throw PostTokenizerException("Bad Tokens");
            }
            it++; 
        }

        emit_strLst(ppStrLst);
    }


    void emit_strLst( vector<PostTokenString>& ppStrLst )
    {
        if (ppStrLst.size() == 0)
            return;

        bool bErr = false;
        string suffix;
        int char_width = 0;
        vector<int> concatChars;
        string      concatSource;

        //--- Check error, when there are two different suffix or two different types
        //
        for (unsigned int i=0 ; i<ppStrLst.size(); i++)
        {
            if (suffix != "" && ppStrLst[i].udSuffix != "" && suffix != ppStrLst[i].udSuffix)
            {
                bErr = true; 
                break;
            }
            else if (suffix == "" && ppStrLst[i].udSuffix != "")
            {
                suffix = ppStrLst[i].udSuffix;
            }

            if (char_width==0)
            {
                char_width = ppStrLst[i].char_width; 
            }
            else if (ppStrLst[i].char_width != 0 && char_width != ppStrLst[i].char_width)
            {
                bErr = true;
                break;
            }

            if (i==ppStrLst.size()-1)
            {
                concatChars.insert(concatChars.end(), ppStrLst[i].chars.begin(),  ppStrLst[i].chars.end());
            }
            else
            {
                concatChars.insert(concatChars.end(), ppStrLst[i].chars.begin(),  ppStrLst[i].chars.end()-1);
            }

            
            if (i==0)
                concatSource += ppStrLst[i].source;
            else
            {
                concatSource += " ";
                concatSource += ppStrLst[i].source;
            }
        }

        //--- prepare the error message;
        //
        if (bErr || (suffix!="" && suffix[0]!='_'))
        {
            string errStr = ppStrLst[0].source;
            for (unsigned int i=1; i<ppStrLst.size() ; i++)
            {
                errStr += " ";
                errStr += ppStrLst[i].source;
            }

            _out.emit_invalid(errStr);
            addToken(PT_INVALID, errStr);
            ppStrLst.clear();
            return;
        }

        //--- otherwise, output the concated string
        //
        if (char_width == 0 || char_width == 1)
        {
            string es = UTF8Encoder::encode(concatChars);
            if (suffix == "")
            {
                _out.emit_literal_array(concatSource, es.size(), FundamentalTypeOf<char>(), es.c_str(), es.size());
                addToken(PT_LITERAL, concatSource, suffix, FT_CHAR, es.size(), es.c_str());
            }
            else 
            {
	            _out.emit_user_defined_literal_string_array(concatSource, suffix, es.size(), FundamentalTypeOf<char>(), es.c_str(), es.size());
                addToken(PT_UD_LITERAL, concatSource, suffix, FT_CHAR, es.size(), es.c_str());
            }
        }
        else if (char_width == 2)
        {
            vector<short> utf16_codes = UTF16Encoder::encode( concatChars );
            char16_t* data = new char16_t[utf16_codes.size()];
            for (unsigned int i=0; i<utf16_codes.size(); ++i)
            {
                data[i] = utf16_codes[i];
            }
            if (suffix == "")
            {
                _out.emit_literal_array(concatSource, utf16_codes.size(), FundamentalTypeOf<char16_t>(), data, utf16_codes.size()*2);
                addToken(PT_LITERAL, concatSource, suffix, FT_CHAR16_T, utf16_codes.size(), data);
            }
            else
            {
	            _out.emit_user_defined_literal_string_array(concatSource, suffix, utf16_codes.size(), FundamentalTypeOf<char16_t>(), data, utf16_codes.size()*2);
                addToken(PT_UD_LITERAL, concatSource, suffix, FT_CHAR16_T, utf16_codes.size(), data);
            }
        } 
        else if (char_width == 3)
        {
            char32_t* data = new char32_t[concatChars.size()];
            for (unsigned int i=0; i<concatChars.size(); ++i)
            {
                data[i] = concatChars[i];
            }
            if (suffix == "")
            {
                _out.emit_literal_array(concatSource, concatChars.size(), FundamentalTypeOf<char32_t>(), data, concatChars.size()*4);
                addToken(PT_LITERAL, concatSource, suffix, FT_CHAR32_T, concatChars.size(), data);
            }
            else
            {
	            _out.emit_user_defined_literal_string_array(concatSource, suffix, concatChars.size(), FundamentalTypeOf<char32_t>(), data, concatChars.size()*4);
                addToken(PT_UD_LITERAL, concatSource, suffix, FT_CHAR32_T, concatChars.size(), data);
            }

        } 
        else if (char_width == 4)
        {
            wchar_t* data = new wchar_t[concatChars.size()];
            for (unsigned int i=0; i<concatChars.size(); ++i)
            {
                data[i] = concatChars[i];
            }
            if (suffix == "")
            {
                _out.emit_literal_array(concatSource, concatChars.size(), FundamentalTypeOf<wchar_t>(), data, concatChars.size()*4);
                addToken(PT_LITERAL, concatSource, suffix, FT_WCHAR_T, concatChars.size(), data);
            }
            else
            {
	            _out.emit_user_defined_literal_string_array(concatSource, suffix, concatChars.size(), FundamentalTypeOf<wchar_t>(), data, concatChars.size()*4);
                addToken(PT_UD_LITERAL, concatSource, suffix, FT_WCHAR_T, concatChars.size(), data);
            }
        }


        //--- clear the list every time it is used
        // 
        ppStrLst.clear();
    }


    bool parse_string(vector<int>& codes, string& source, vector<int>& chars, vector<int>& udSuffix, int& char_width)
    {
        int la = -1;
        int state = 0;
        bool isChar8 = false;
        bool isChar16 = false;
        bool isChar32 = false;
        bool isWchar  = false;
        bool stop = false;
        source = UTF8Encoder::encode(codes);
        vector<int> rawSuffix;
        vector<int> rawPrefix;
        bool isRawSuffix = false;

        vector<int>::iterator idx = codes.begin();
        while ( idx != codes.end() )
        {
            la = (*idx);
            switch (state)
            {
                case 0:
                    if ( la == 'u' )
                    {
                        state = 1;
                        isChar16 = true;
                    }
                    else if ( la == 'U')
                    {
                        state = 2;
                        isChar32 = true;
                    }
                    else if ( la == 'L')
                    {
                        state = 3;
                        isWchar = true;
                    }
                    else if ( la == 'R')
                    {
                        state = 5;
                    }
                    else if (la == '"')
                    {
                        state = 6;
                    }
                    else
                    {
                        stop = true;
                    }
                    break;
                case 1:
                    if (la=='8')
                    {
                        isChar8 = true;
                        isChar16 = false;
                        state = 4;
                    }
                    else if (la =='R')
                        state = 5;
                    else if (la =='"')
                        state = 6;
                    else
                        stop = true;
                    break;
                case 2:
                case 3:
                case 4:
                    if (la == 'R')
                        state = 5;
                    else if (la=='"')
                        state = 6;
                    else
                        stop = true;
                    break;
                case 5:
                    if (la == '"')
                        state = 9;
                    else
                        stop = true;
                    break;
                case 6:
                    if (la == '"')
                        state = 8;
                    else if (la == '\\')
                        state = 7;
                    else
                    {
                        chars.push_back(la);
                        state = 6;
                    }
                    break;
                case 7:
                    if (la=='\'' || la=='"' || la == '\?' || la == '\\')
                        chars.push_back(la);
                    else if (la == 'a')
                        chars.push_back('\a');
                    else if (la == 'b')
                        chars.push_back('\b');
                    else if (la == 'f')
                        chars.push_back('\f');
                    else if (la == 'n')
                        chars.push_back('\n');
                    else if (la == 'r')
                        chars.push_back('\r');
                    else if (la == 't')
                        chars.push_back('\t');
                    else if (la == 'v')
                        chars.push_back('\v');
                    else if ( isOctal(la) )
                    {
                        chars.push_back( HexCharToValue(la) );
                        state = 14;
                        break;
                    }
                    else if (la == 'x')
                    {
                        state = 11;
                        break;
                    }
                    state = 6;
                    break;
                case 8:
                    udSuffix.push_back(la);
                    state = 8;
                    break;
                case 9:
                    if (la == '(')
                        state = 10;
                    else 
                    {
                        rawPrefix.push_back(la);
                        state = 9;
                    }
                    break;
                case 10:
                    if (la == ')')
                    {
                        if (isRawSuffix)
                        {
                            chars.push_back(')');
                            chars.insert(chars.end(), rawSuffix.begin(), rawSuffix.end());
                        }
                        isRawSuffix = true;
                        rawSuffix.clear();
                    }
                    else if (la == '"')
                    {
                        if (isRawSuffix)
                        {
                            if (compareCodeToCode(rawPrefix, rawSuffix) == true)
                            {
                                state = 8; 
                                break;
                            }
                            else
                            {
                                chars.push_back(')');
                                chars.insert(chars.end(), rawSuffix.begin(), rawSuffix.end());
                                chars.push_back('"');
                                isRawSuffix = false;
                                rawSuffix.clear();
                            }
                        } 
                        else
                        {
                             chars.push_back(la);
                        }
                    }
                    else
                    {                    
                        if (isRawSuffix)
                            rawSuffix.push_back(la);
                        else
                            chars.push_back(la);
                    }
                    state = 10;
                    break;
                case 11:
                    if ( isHex(la) )
                    {
                        chars.push_back( HexCharToValue(la) );
                        state = 13;
                    } 
                    else
                        stop = true;
                    break;
                case 12:
                    if ( isOctal(la) )
                    {
                        chars.push_back( HexCharToValue(la) );
                        state = 14;
                    }
                    else
                        stop = true;
                    break;
                case 13:
                    if ( isHex(la) )
                    {
                        chars[chars.size()-1] = (chars[chars.size()-1]<<4) + HexCharToValue(la);
                        state = 13;
                    }
                    else if (la == '"')
                        state = 8;
                    else if (la == '\\')
                        state = 7;
                    else 
                    {
                        chars.push_back(la);
                        state = 6;
                    }
                    break;
                case 14:
                    if ( isOctal(la) )
                    {
                        chars[chars.size()-1] = (chars[chars.size()-1]<<3) + HexCharToValue(la);
                        state = 14;
                    }
                    else if (la == '"')
                        state = 8;
                    else if (la == '\\')
                        state = 7;
                    else 
                    {
                        chars.push_back(la);
                        state = 6;
                    }
                    break;
                default:
                    stop = true;
                    break;
            }

            if (stop)
            {
                break;
            }
            idx++;
        }  

        if (state != 8)
            return false;
        else
        {
            chars.push_back(0);  //string end
            if (isChar8)
                char_width = 1;
            else if (isChar16)
                char_width = 2;
            else if (isChar32)
                char_width = 3;
            else if (isWchar)
                char_width = 4;
            else
                char_width = 0;
            return true;
        }
    }


    void parse_ppchar(vector<int>& codes)
    {
        int la = -1;
        int state = 0;
        bool isChar16 = false;
        bool isChar32 = false;
        bool isWchar  = false;
        bool stop = false;
        string source = UTF8Encoder::encode(codes);
        vector<unsigned int> cchars;
        vector<int> suffix;

        vector<int>::iterator idx = codes.begin();
        while ( idx != codes.end() )
        {
            la = (*idx);
            switch (state)
            {
                case 0:
                    if ( la == 'u' || la == 'U' || la == 'L')
                    {
                        if (la == 'u') 
                            isChar16 = true;
                        else if (la=='U')
                            isChar32 = true;
                        else
                            isWchar = true;
                        state = 1;
                    }
                    else if ( la == '\'' )
                    {
                        state = 2;
                    }
                    else 
                    {
                        stop = true;
                    }
                    break;
                case 1:
                    if ( la == '\'')
                        state = 2;
                    else
                        stop = true;
                    break;
                case 2:
                    if (la == '\\')
                        state = 3; 
                    else
                    {
                        cchars.push_back(la);
                        state = 8; 
                    }
                    break;
                case 3:
                    if (la=='\'' || la=='"' || la == '\?' || la == '\\')
                        cchars.push_back(la);
                    else if (la == 'a')
                        cchars.push_back('\a');
                    else if (la == 'b')
                        cchars.push_back('\b');
                    else if (la == 'f')
                        cchars.push_back('\f');
                    else if (la == 'n')
                        cchars.push_back('\n');
                    else if (la == 'r')
                        cchars.push_back('\r');
                    else if (la == 't')
                        cchars.push_back('\t');
                    else if (la == 'v')
                        cchars.push_back('\v');
                    else if ( isOctal(la) )
                    {
                        cchars.push_back( HexCharToValue(la) );
                        state = 5;
                        break;
                    }
                    else if (la == 'x')
                    {
                        state = 6;
                        break;
                    }
                    state = 4;
                    break;
                case 4:
                    if (la=='\'')
                        state = 10;
                    else
                        stop = true;
                    break;
                case 5:
                    if ( isOctal(la) )
                    {
                        cchars[cchars.size()-1] = (cchars[cchars.size()-1] << 3) + HexCharToValue(la);
                        state = 5;
                    }
                    else if (la == '\'')
                        state = 10;
                    else
                        stop = true;
                    break;
                case 6:
                    if ( isHex(la) )
                    {
                        cchars.push_back( HexCharToValue(la) );
                        state = 7;
                    }
                    else
                        stop = true;
                    break;
                case 7:
                    if ( isHex(la) )
                    {
                        cchars[cchars.size()-1] = (cchars[cchars.size()-1] << 4) + HexCharToValue(la);
                        state = 7;
                    }
                    else if (la == '\'')
                        state = 10;
                    else
                        stop = true;
                    break;
                case 8:
                    if (la == '\'')
                        state = 10;
                    else
                        stop = true;
                    break;
                case 10:
                    // success
                    suffix.push_back(la);
                    state = 10;
                    break;
            }

            if (stop == true) // invalid
            {
                _out.emit_invalid(source);
                addToken(PT_INVALID, source);
                return;
            }
            idx++;
        }


        if (cchars.size() > 1)
        {
            _out.emit_invalid(source);
            addToken(PT_INVALID, source);
        }
        else if (suffix.size() > 0 && suffix[0] != '_')
        {
            _out.emit_invalid(source);
            addToken(PT_INVALID, source);
        }
        else 
        {
            string cs = UTF8Encoder::encode(suffix);
            unsigned int c = cchars[0];
            if (isChar32)
            {
                if (cs == "")
                {
	                _out.emit_literal(source, FundamentalTypeOf<char32_t>(), &c, 4);
                    addToken(PT_LITERAL, source, cs, FT_CHAR32_T, 1, &c);
                }
                else 
                {
	                _out.emit_user_defined_literal_character(source, cs, FundamentalTypeOf<char32_t>(), &c, 4);
                    addToken(PT_UD_LITERAL, source, cs, FT_CHAR32_T, 1, &c);
                }
            }
            else if (isChar16)
            {
                if (c > 0xFFFF)
                {
                    _out.emit_invalid(source);
                    addToken(PT_INVALID, source);
                }
                else
                {
                    if (cs =="")
                    {
	                    _out.emit_literal(source, FundamentalTypeOf<char16_t>(), &c, 2);
                        addToken(PT_LITERAL, source, cs, FT_CHAR16_T, 1, &c);
                    }
                    else 
                    {
	                    _out.emit_user_defined_literal_character(source, cs, FundamentalTypeOf<char16_t>(), &c, 2);
                        addToken(PT_UD_LITERAL, source, cs, FT_CHAR16_T, 1, &c);
                    }
                }
            }
            else if (isWchar)
            {
                if (cs == "")
                {
	                _out.emit_literal(source, FundamentalTypeOf<wchar_t>(), &c, 4);
                    addToken(PT_LITERAL, source, cs, FT_WCHAR_T, 1, &c);
                }
                else
                {
	                _out.emit_user_defined_literal_character(source, cs, FundamentalTypeOf<wchar_t>(), &c, 4);
                    addToken(PT_UD_LITERAL, source, cs, FT_WCHAR_T, 1, &c);
                }
            }
            else
            {
                if (c > 0xFF)
                {
                    if (cs == "")
                    {
	                    _out.emit_literal(source, FundamentalTypeOf<int>(), &c, 4);
                        addToken(PT_LITERAL, source, cs, FT_INT, 1, &c);
                    }
                    else 
                    {
	                    _out.emit_user_defined_literal_character(source, cs, FundamentalTypeOf<int>(), &c, 4);
                        addToken(PT_UD_LITERAL, source, cs, FT_INT, 1, &c);
                    }
                }
                else
                {
                    if (cs == "")
                    {
	                    _out.emit_literal(source, FundamentalTypeOf<char>(), &c, 1);
                        addToken(PT_LITERAL, source, cs, FT_INT, 1, &c);
                    }
                    else
                    {
	                    _out.emit_user_defined_literal_character(source, cs, FundamentalTypeOf<char>(), &c, 1);
                        addToken(PT_UD_LITERAL, source, cs, FT_INT, 1, &c);
                    }
                }
            }
        }

    }


    bool checkValidUserDefineSuffix(string& s)
    {
        if (s=="")
            return true;

        if (s[0] != '_')
            return false;

        for (unsigned int i=0; i<s.size(); i++)
        {
            if (s[i] == '+' || s[i] == '-')
                return false;
        }

        return true;
    }


    void parse_ppnumber(vector<int>& codes)
    {
        int la = -1;
        int state = 0;  // initial state 
        vector<int>::iterator idx = codes.begin();
        bool stop = false;
       
        while ( idx != codes.end() )
        {
            la = (*idx);
       
            switch (state)
            { 
                case 0 :
                    if (la == '0')
                    {
                        state = 1;
                    }
                    else if (la == '.')
                    {
                        state = 6;
                    }
                    else if (la >= '1' && la <= '9')
                    {
                        state = 7;
                    }
                    else 
                    {
                        throw PostTokenizerException("Bad number state 0");
                    }
                    break;
                case 1:
                    if (la == 'x')
                    {
                        state = 2;
                    }
                    else if ( isOctal(la) )
                    {
                        state = 4;
                    } 
                    else if (la == '8' || la == '9') // non-octal
                    {
                        state = 5;
                    }
                    else if (la == '.')
                    {
                        state = 6;
                    }
                    else if (la == 'e' || la == 'E')
                    {
                        state = 8;
                    }
                    else
                    {
                        stop = true;
                    }
                    break;
                case 2:
                    if ( isHex(la) ) 
                    {
                        state = 3; 
                    }
                    else
                    {
                        stop = true;
                    }
                    break;
                case 3:
                    if ( isHex(la) )
                    {
                        state = 3;
                    }
                    else
                    {
                        stop = true;
                    }
                    break;
                case 4:
                    if ( isOctal(la) )
                    {
                        state = 4;
                    }
                    else if (la == '8' || la == '9') // non-octal
                    {
                        state = 5;
                    }
                    else if (la == '.')
                    {
                        state = 6;
                    }
                    else 
                    {
                        stop = true;
                    }
                    break; 
                case 5:
                    if ( isDecimal(la) )
                    {
                        state = 5;
                    }
                    else if ( la == '.')
                    {
                        state = 6;
                    }
                    else if ( la == 'e' || 'E' )
                    {
                        state = 8;
                    }
                    else
                    {
                        stop = true;
                    }
                    break;
                case 6:
                    if ( isDecimal(la) )
                    {
                        state = 6;
                    }
                    else if (la == 'e' || la == 'E')
                    {
                        state = 8;
                    }
                    else
                    {
                        stop = true;
                    }
                    break;
                case 7:
                    if ( isDecimal(la) )
                    {
                        state = 7;
                    }
                    else if (la == '.')
                    {
                        state = 6;
                    }
                    else if (la == 'e' || la == 'E')
                    {
                        state = 8;
                    }
                    else
                    {
                        stop = true;
                    }
                    break;
                case 8:
                    if ( la == '+' || la == '-' || isDecimal(la) )
                    {
                        state = 9;
                    }
                    else 
                    {
                        throw PostTokenizerException("Bad number state 8");
                    }
                    break;
                case 9:
                    if ( isDecimal(la) )
                    {
                        state = 9;
                    }
                    else
                    {
                        stop = true;
                    }
                    break;
                default:
                    throw PostTokenizerException("Bad number");
                    break;
            }

            // break the loop and start to handle the suffix part
            if (stop == true)
            {
                break;
            }
            idx++;
        }

        string source = code2string(codes);
        vector<int> numV(codes.begin(), idx);
        string numS = code2string(numV);
        bool isUnsigned = false;
        bool isLong = false;
        bool isLonglong = false;
        bool isFloat = false;
        // dispatch
        bool isHexInteger = false;
        bool isOctalInteger = false;
        bool isDecimalInteger = false;
        bool isFloatPoint = false;
        if (state == 1 || state == 5 || state == 7)  // decimial integer
        {
            isDecimalInteger = true;
        }
        else if (state == 3)  // hex 
        {
            isHexInteger = true;
        }
        else if (state == 4) // octal
        {
            isOctalInteger = true;
        }
        else if (state == 6 || state == 9)
        {
            isFloatPoint = true;
        }
        else  // invalid
        {
	        _out.emit_invalid(source);
            addToken(PT_INVALID, source);
            return;
        }
        
        if (stop == true)
        {
            // suffix string
            vector<int> rest(idx, codes.end());
            string s = code2string(rest);

            //--- user defined suffix
            //
            if (s[0] == '_' && checkValidUserDefineSuffix(s))
            {
                float f = PA2Decode_float( numS );
                if (state == 6 || state == 9)
                {
                    _out.emit_user_defined_literal_floating(source, s, numS);
                    addToken(PT_UD_LITERAL, source, s, FT_FLOAT, 1, &f);
                }
                else
                {
	                _out.emit_user_defined_literal_integer(source, s, numS);
                    addToken(PT_UD_LITERAL, source, s, FT_FLOAT, 1, &f);
                }
            }
            else if ( checkNumberLiteralSuffix(s, isUnsigned, isLong, isLonglong, isFloat) )
            {
                unsigned long long value;
                int bs;
                if (isDecimalInteger)  // decimial integer
                {
                    bs = decimalBits( numS , value );
                }
                else if (isHexInteger)  // hex 
                {
                    bs = hexBits ( numS , value);
                }
                else if (isOctalInteger) // octal
                {
                    bs = octalBits ( numS , value);
                }
                else if (isFloatPoint)
                {
                    // float
                    float f = PA2Decode_float( numS );
    	            _out.emit_literal(source, FundamentalTypeOf<float>(), &f, 4);
                    addToken(PT_LITERAL, source, s, FT_FLOAT, 1, &f);
                }

                if (isDecimalInteger || isHexInteger || isOctalInteger)
                {
                    if ( bs > 64 )
                    {
                        // error 
	                    _out.emit_invalid(source);
                        addToken(PT_INVALID, source);
                    } 
                    else if ( bs == 64)
                    {
                        if (isUnsigned && isLong)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<unsigned long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_INT, 1, &value);
                        }
                        else if (isUnsigned && isLonglong)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<unsigned long long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_LONG_INT, 1, &value);
                        }
                        else if (isUnsigned)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<unsigned long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_INT, 1, &value);
                        }
                        else if (isLong) // long , long long
                        {
                            if (isDecimalInteger)
                            {
	                            _out.emit_invalid(source);
                                addToken(PT_INVALID, source);
                            }
                            else
                            {
    	                        _out.emit_literal(source, FundamentalTypeOf<unsigned long>(), &value, 8);
                                addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_INT, 1, &value);
                            }
                        }
                        else // (isLonglong)
                        {
                            if (isDecimalInteger)
                            {
	                            _out.emit_invalid(source);
                                addToken(PT_INVALID, source);
                            }
                            else
                            {
    	                        _out.emit_literal(source, FundamentalTypeOf<unsigned long long>(), &value, 8);
                                addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_LONG_INT, 1, &value);
                            }
                        }

                    }
                    else if ( bs > 32)
                    {
                        // long
                        if (isUnsigned && isLong)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<unsigned long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_INT, 1, &value);
                        }
                        else if (isUnsigned && isLonglong)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<unsigned long long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_INT, 1, &value);
                        }
                        else if (isUnsigned)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<unsigned long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_INT, 1, &value);
                        }
                        else if (isLong)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_LONG_INT, 1, &value);
                        }
                        else // long long
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<long long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_LONG_LONG_INT, 1, &value);
                        }
                    }
                    else if (bs == 32)
                    {
                        if (isUnsigned && isLong)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<unsigned long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_INT, 1, &value);
                        }
                        else if (isUnsigned && isLonglong)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<unsigned long long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_LONG_INT, 1, &value);
                        }
                        else if (isUnsigned)
                        {
	                        _out.emit_literal(source, FundamentalTypeOf<unsigned int>(), &value, 4);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_INT, 1, &value);
                        }
                        else if (isLong)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_LONG_INT, 1, &value);
                        }
                        else // long long
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<long long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_LONG_LONG_INT, 1, &value);
                        }
                    }
                    else
                    {
                        if (isUnsigned && isLong)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<unsigned long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_INT, 1, &value);
                        }
                        else if (isUnsigned && isLonglong)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<unsigned long long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_LONG_INT, 1, &value);
                        }
                        else if (isUnsigned)
                        {
	                        _out.emit_literal(source, FundamentalTypeOf<unsigned int>(), &value, 4);
                            addToken(PT_LITERAL, source, s, FT_UNSIGNED_INT, 1, &value);
                        }
                        else if (isLong)
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_LONG_INT, 1, &value);
                        }
                        else // long long
                        {
    	                    _out.emit_literal(source, FundamentalTypeOf<long long>(), &value, 8);
                            addToken(PT_LITERAL, source, s, FT_LONG_LONG_INT, 1, &value);
                        }
                    }
                }
            }
            else //invalid
            {
	            _out.emit_invalid(source);
                addToken(PT_INVALID, source);
            }
        }
        else
        {
            string s="";
            if (isDecimalInteger || isHexInteger || isOctalInteger)
            {
                unsigned long long value;
                int bs;
                if (isDecimalInteger)  // decimial integer
                {
                    bs = decimalBits( numS , value );
                }
                else if (isHexInteger)  // hex 
                {
                    bs = hexBits ( numS , value);
                }
                else // octal
                {
                    bs = octalBits ( numS , value);
                }
    
                if ( bs > 64 )
                {
                    // error 
	                _out.emit_invalid(source);
                    addToken(PT_INVALID, source);
                } 
                else if ( bs == 64)
                {
                    if (isDecimalInteger)
                    {
	                    _out.emit_invalid(source);
                        addToken(PT_INVALID, source);
                    }
                    else
                    {
	                    _out.emit_literal(numS, FundamentalTypeOf<unsigned long>(), &value, 8);
                        addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_INT, 1, &value);
                    }
                }
                else if ( bs > 32)
                {
                    // long
	                _out.emit_literal(numS, FundamentalTypeOf<long>(), &value, 8);
                    addToken(PT_LITERAL, source, s, FT_LONG_INT, 1, &value);
                }
                else if (bs == 32)
                {
                    if (isDecimalInteger)
                    {
	                    _out.emit_literal(numS, FundamentalTypeOf<long>(), &value, 8);
                        addToken(PT_LITERAL, source, s, FT_LONG_INT, 1, &value);
                    }
                    else 
                    {
	                    _out.emit_literal(numS, FundamentalTypeOf<unsigned int>(), &value, 4);
                        addToken(PT_LITERAL, source, s, FT_UNSIGNED_LONG_INT, 1, &value);
                    }
                }
                else
                {
                    // int
	                _out.emit_literal(numS, FundamentalTypeOf<int>(), &value, 4);
                    addToken(PT_LITERAL, source, s, FT_INT, 1, &value);
                }
            }
            else if (isFloatPoint)  // float
            {
                double value = PA2Decode_double(numS);
	            _out.emit_literal(numS, FundamentalTypeOf<double>(), &value, 8);
                addToken(PT_LITERAL, source, s, FT_DOUBLE, 1, &value);
            }
            else
            {
            }
        }
        
    }

    
    int hexBits(string s, unsigned long long& val)
    {
        unsigned long long value = 0;
        int size = 0; 
        bool gotFirstNonZero = false;
        for (unsigned i=2; i<s.size(); i++)
        {
            int tmp = HexCharToValue( s[i] ) ;
            value = (value << 4) +  tmp;
            if (tmp != 0 && gotFirstNonZero==false)
            {
                gotFirstNonZero = true;
                if (tmp >= 8)
                    size += 4;
                else if (tmp >= 4)
                    size += 3;
                else if (tmp >= 2)
                    size += 2;
                else
                    size += 1;
            } 
            else if (gotFirstNonZero==true)
            { 
                size += 4;
            }
        } 
        val = value;
        return size;
    }
   

    int decimalBits(string s, unsigned long long& value)
    {
        unsigned long long val = 0;
        int hb = 0;

        for (unsigned i=0; i<s.size() ; i++)
        {
            int tmp = s[i] - '0';
            val = val * 10 + tmp;
            int tmp_hb = highestBit( val );
            if (tmp_hb < hb)
            {
                // over flow, give something bigger than 64
                return 65;
            }
            else 
            {
                hb = tmp_hb;
            }
        }
        value = val;
        return hb;
    }


    int octalBits(string s, unsigned long long& value)
    {
        unsigned long long val = 0;
        int size = 0; 
        bool gotFirstNonZero = false;
        for (unsigned i=0; i<s.size(); i++)
        {
            int tmp = HexCharToValue( s[i] ) ;
            val = (val << 3) + tmp;
            if (tmp != 0 && gotFirstNonZero==false)
            {
                gotFirstNonZero = true;
                if (tmp >= 4)
                    size += 3;
                else if (tmp >= 2)
                    size += 2;
                else
                    size += 1;
            } 
            else if (gotFirstNonZero==true)
            { 
                size += 3;
            }
        } 
        value = val;
        return size;
    }


    int highestBit(unsigned long long v)
    {
        int idx=0;
        while (v != 0)
        {
            v = v>>1;
            idx++;
        }
        return idx;
    }


    bool checkNumberLiteralSuffix(string s, bool& isUnsigned, bool& isLong, bool& isLonglong, bool& isFloat)
    {
        if (s == "u" || s == "U")
        {
            isUnsigned = true;
        }
        else if (s=="l" || s == "L")
        {
            isLong = true;
        }
        else if (s=="f" || s == "F")
        {
            isFloat = true;
        }
        else if (s == "ll" || s == "LL")
        {
            isLonglong = true;
        }
        else if (s=="ul" || s == "uL" || s=="Ul" || s=="UL" || s=="lu" || s == "lU" || s=="Lu" || s=="LU")
        {
            isUnsigned = true;
            isLong = true;
        }
        else if (s=="ull" || s=="uLL" || s=="Ull" || s=="ULL" || s=="llu" || s=="llU" || s=="LLu" || s=="LLU")
        {
            isUnsigned = true;
            isLonglong = true;
        }
        else
        {
            return false;
        }
        return true;
    } 

   
  private:
    vector<PPToken>            _pplst;
    DebugPostTokenOutputStream _out;
};




#ifdef PA2
int main()
{
	// TODO:
	// 1. apply your code from PA1 to produce `preprocessing-tokens`
	// 2. "post-tokenize" the `preprocessing-tokens` as described in PA2
	// 3. write them out in the PA2 output format specifed
    try
    {
        ostringstream oss;
        oss << cin.rdbuf();
        string input = oss.str();

        // Decode input stream (UTF-8) to UNC
        vector<int> uncTokens;
        int code_unit;
        UTF8Decoder utf8Decoder(&input);
        while ((code_unit = utf8Decoder.nextCode()) > 0)
        {
            uncTokens.push_back(code_unit);
        }
        if (uncTokens.size()>0 && uncTokens[uncTokens.size()-1]!='\n')
        {
            uncTokens.push_back('\n');
        }

        PPTokenizer ppTokenizer;
        ppTokenizer.parse(uncTokens);

        // PA2 start
        PostTokenizer postTokenizer(ppTokenizer._elst);         
        postTokenizer.parse();
    }
    catch (exception& e)
    {
        cerr << "ERROR: " << e.what() << endl;
        return EXIT_FAILURE;
    }

}
#endif
