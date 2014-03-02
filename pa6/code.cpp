    bool is_first_translation_unit ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_ASM, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_NAMESPACE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STATIC_ASSERT, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TEMPLATE, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_USING, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_SEMICOLON, type ) ||  matchType( PT_ST_EOF, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_primary_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_type_name ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_class_name ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_T, type )) {
            return true;
        }
        return false;
    }

    bool is_first_enum_name ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER_E, type )) {
            return true;
        }
        return false;
    }

    bool is_first_namespace_name ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER_N, type )) {
            return true;
        }
        return false;
    }

    bool is_first_template_name ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER_T, type )) {
            return true;
        }
        return false;
    }

    bool is_first_typedef_name ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_simple_template_id ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER_T, type )) {
            return true;
        }
        return false;
    }

    bool is_first_id_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_unqualified_id ( EPostTokenType type )
    {
        if ( matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_T, type )) {
            return true;
        }
        return false;
    }

    bool is_first_qualified_id ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_nested_name_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_nested_name_specifier_root ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_nested_name_specifier_suffix ( EPostTokenType type )
    {
        if ( matchType( PT_KW_TEMPLATE, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_T, type )) {
            return true;
        }
        return false;
    }

    bool is_first_lambda_expression ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LSQUARE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_lambda_introducer ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LSQUARE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_lambda_capture ( EPostTokenType type )
    {
        if ( matchType( PT_KW_THIS, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_ASS, type ) ||  matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_capture_default ( EPostTokenType type )
    {
        if ( matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_ASS, type )) {
            return true;
        }
        return false;
    }

    bool is_first_capture_list ( EPostTokenType type )
    {
        if ( matchType( PT_KW_THIS, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_capture ( EPostTokenType type )
    {
        if ( matchType( PT_KW_THIS, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_lambda_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LPAREN, type )) {
            return true;
        }
        return false;
    }

    bool is_first_postfix_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_postfix_root ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_postfix_suffix ( EPostTokenType type )
    {
        if ( matchType( PT_OP_ARROW, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_DOT, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_expression_list ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_THROW, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LBRACE, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_pseudo_destructor_name ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_unary_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_unary_operator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type )) {
            return true;
        }
        return false;
    }

    bool is_first_new_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_NEW, type ) ||  matchType( PT_OP_COLON2, type )) {
            return true;
        }
        return false;
    }

    bool is_first_new_placement ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LPAREN, type )) {
            return true;
        }
        return false;
    }

    bool is_first_new_type_id ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_new_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LAND, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_noptr_new_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LSQUARE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_new_initializer ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LBRACE, type ) ||  matchType( PT_OP_LPAREN, type )) {
            return true;
        }
        return false;
    }

    bool is_first_delete_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DELETE, type ) ||  matchType( PT_OP_COLON2, type )) {
            return true;
        }
        return false;
    }

    bool is_first_noexcept_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_NOEXCEPT, type )) {
            return true;
        }
        return false;
    }

    bool is_first_cast_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_cast_operator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LPAREN, type )) {
            return true;
        }
        return false;
    }

    bool is_first_pm_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_pm_operator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_ARROWSTAR, type ) ||  matchType( PT_OP_DOTSTAR, type )) {
            return true;
        }
        return false;
    }

    bool is_first_multiplicative_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_multiplicative_operator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_DIV, type ) ||  matchType( PT_OP_MOD, type ) ||  matchType( PT_OP_STAR, type )) {
            return true;
        }
        return false;
    }

    bool is_first_additive_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_additive_operator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type )) {
            return true;
        }
        return false;
    }

    bool is_first_shift_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_shift_operator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LSHIFT, type ) ||  matchType( PT_ST_RSHIFT_1, type )) {
            return true;
        }
        return false;
    }

    bool is_first_relational_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_relational_operator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_GE, type ) ||  matchType( PT_OP_GT, type ) ||  matchType( PT_OP_LE, type ) ||  matchType( PT_OP_LT, type )) {
            return true;
        }
        return false;
    }

    bool is_first_equality_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_equality_operator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_EQ, type ) ||  matchType( PT_OP_NE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_and_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_exclusive_or_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_inclusive_or_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_logical_and_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_logical_or_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_conditional_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_assignment_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_THROW, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_assignment_operator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_ASS, type ) ||  matchType( PT_OP_BANDASS, type ) ||  matchType( PT_OP_BORASS, type ) ||  matchType( PT_OP_DIVASS, type ) ||  matchType( PT_OP_LSHIFTASS, type ) ||  matchType( PT_OP_MINUSASS, type ) ||  matchType( PT_OP_MODASS, type ) ||  matchType( PT_OP_PLUSASS, type ) ||  matchType( PT_OP_RSHIFTASS, type ) ||  matchType( PT_OP_STARASS, type ) ||  matchType( PT_OP_XORASS, type )) {
            return true;
        }
        return false;
    }

    bool is_first_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_THROW, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_constant_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_statement ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_ASM, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_BREAK, type ) ||  matchType( PT_KW_CASE, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_CONTINUE, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DEFAULT, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DO, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FOR, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_GOTO, type ) ||  matchType( PT_KW_IF, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_NAMESPACE, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_RETURN, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STATIC_ASSERT, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_SWITCH, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_THROW, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TRY, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_USING, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_KW_WHILE, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LBRACE, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_SEMICOLON, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_labeled_statement ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_CASE, type ) ||  matchType( PT_KW_DEFAULT, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_expression_statement ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_THROW, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_SEMICOLON, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_compound_statement ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LBRACE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_selection_statement ( EPostTokenType type )
    {
        if ( matchType( PT_KW_IF, type ) ||  matchType( PT_KW_SWITCH, type )) {
            return true;
        }
        return false;
    }

    bool is_first_condition_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_condition ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_THROW, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_iteration_statement ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DO, type ) ||  matchType( PT_KW_FOR, type ) ||  matchType( PT_KW_WHILE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_for_init_statement ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_THROW, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_SEMICOLON, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_for_range_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_for_range_initializer ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_THROW, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LBRACE, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_jump_statement ( EPostTokenType type )
    {
        if ( matchType( PT_KW_BREAK, type ) ||  matchType( PT_KW_CONTINUE, type ) ||  matchType( PT_KW_GOTO, type ) ||  matchType( PT_KW_RETURN, type )) {
            return true;
        }
        return false;
    }

    bool is_first_declaration_statement ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_ASM, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_NAMESPACE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STATIC_ASSERT, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_USING, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_ASM, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_NAMESPACE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STATIC_ASSERT, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TEMPLATE, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_USING, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_SEMICOLON, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_block_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_ASM, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_NAMESPACE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STATIC_ASSERT, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_USING, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_alias_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_USING, type )) {
            return true;
        }
        return false;
    }

    bool is_first_simple_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_static_assert_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_STATIC_ASSERT, type )) {
            return true;
        }
        return false;
    }

    bool is_first_empty_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_OP_SEMICOLON, type )) {
            return true;
        }
        return false;
    }

    bool is_first_attribute_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_OP_LSQUARE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_decl_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_decl_specifier_seq ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_storage_class_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_THREAD_LOCAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_function_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_VIRTUAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_type_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_trailing_type_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_type_specifier_seq ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_trailing_type_specifier_seq ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_simple_type_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_decltype_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_elaborated_type_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_UNION, type )) {
            return true;
        }
        return false;
    }

    bool is_first_enum_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ENUM, type )) {
            return true;
        }
        return false;
    }

    bool is_first_enum_head ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ENUM, type )) {
            return true;
        }
        return false;
    }

    bool is_first_opaque_enum_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ENUM, type )) {
            return true;
        }
        return false;
    }

    bool is_first_enum_key ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ENUM, type )) {
            return true;
        }
        return false;
    }

    bool is_first_enum_base ( EPostTokenType type )
    {
        if ( matchType( PT_OP_COLON, type )) {
            return true;
        }
        return false;
    }

    bool is_first_enumerator_list ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_enumerator_definition ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_enumerator ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_namespace_definition ( EPostTokenType type )
    {
        if ( matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_NAMESPACE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_namespace_body ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_ASM, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_NAMESPACE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STATIC_ASSERT, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TEMPLATE, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_USING, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_SEMICOLON, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_namespace_alias_definition ( EPostTokenType type )
    {
        if ( matchType( PT_KW_NAMESPACE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_qualified_namespace_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_using_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_USING, type )) {
            return true;
        }
        return false;
    }

    bool is_first_using_directive ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_USING, type ) ||  matchType( PT_OP_LSQUARE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_asm_definition ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ASM, type )) {
            return true;
        }
        return false;
    }

    bool is_first_linkage_specification ( EPostTokenType type )
    {
        if ( matchType( PT_KW_EXTERN, type )) {
            return true;
        }
        return false;
    }

    bool is_first_attribute_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_OP_LSQUARE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_alignment_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type )) {
            return true;
        }
        return false;
    }

    bool is_first_attribute_list ( EPostTokenType type )
    {
        if ( matchType( PT_OP_COMMA, type ) ||  matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_attribute_part ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_attribute ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_attribute_token ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_attribute_scoped_token ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_attribute_namespace ( EPostTokenType type )
    {
        if ( matchType( PT_TT_IDENTIFIER, type )) {
            return true;
        }
        return false;
    }

    bool is_first_attribute_argument_clause ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LPAREN, type )) {
            return true;
        }
        return false;
    }

    bool is_first_balanced_token ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LBRACE, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_ST_NONPAREN, type )) {
            return true;
        }
        return false;
    }

    bool is_first_init_declarator_list ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LAND, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_init_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LAND, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LAND, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_ptr_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LAND, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_noptr_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_noptr_declarator_root ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_noptr_declarator_suffix ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_parameters_and_qualifiers ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LPAREN, type )) {
            return true;
        }
        return false;
    }

    bool is_first_trailing_return_type ( EPostTokenType type )
    {
        if ( matchType( PT_OP_ARROW, type )) {
            return true;
        }
        return false;
    }

    bool is_first_ptr_operator ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LAND, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_cv_qualifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_VOLATILE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_ref_qualifier ( EPostTokenType type )
    {
        if ( matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_LAND, type )) {
            return true;
        }
        return false;
    }

    bool is_first_declarator_id ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_type_id ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_abstract_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_ARROW, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LAND, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_ptr_abstract_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LAND, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_noptr_abstract_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_noptr_abstract_declarator_root ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_abstract_pack_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LAND, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_noptr_abstract_pack_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_OP_DOTS, type )) {
            return true;
        }
        return false;
    }

    bool is_first_parameter_declaration_clause ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_parameter_declaration_list ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_parameter_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_function_definition ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_function_body ( EPostTokenType type )
    {
        if ( matchType( PT_KW_TRY, type ) ||  matchType( PT_OP_ASS, type ) ||  matchType( PT_OP_COLON, type ) ||  matchType( PT_OP_LBRACE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_initializer ( EPostTokenType type )
    {
        if ( matchType( PT_OP_ASS, type ) ||  matchType( PT_OP_LBRACE, type ) ||  matchType( PT_OP_LPAREN, type )) {
            return true;
        }
        return false;
    }

    bool is_first_brace_or_equal_initializer ( EPostTokenType type )
    {
        if ( matchType( PT_OP_ASS, type ) ||  matchType( PT_OP_LBRACE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_initializer_clause ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_THROW, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LBRACE, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_initializer_list ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_THROW, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LBRACE, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_initializer_clause_dots ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_THROW, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LBRACE, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_braced_init_list ( EPostTokenType type )
    {
        if ( matchType( PT_OP_LBRACE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_class_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_UNION, type )) {
            return true;
        }
        return false;
    }

    bool is_first_class_head ( EPostTokenType type )
    {
        if ( matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_UNION, type )) {
            return true;
        }
        return false;
    }

    bool is_first_class_head_name ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_class_virt_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_ST_FINAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_class_key ( EPostTokenType type )
    {
        if ( matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_UNION, type )) {
            return true;
        }
        return false;
    }

    bool is_first_member_specification ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_PRIVATE, type ) ||  matchType( PT_KW_PROTECTED, type ) ||  matchType( PT_KW_PUBLIC, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STATIC_ASSERT, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TEMPLATE, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_USING, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_member_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STATIC_ASSERT, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TEMPLATE, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_USING, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_member_declarator_list ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LAND, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_member_declarator ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LAND, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_virt_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_ST_FINAL, type ) ||  matchType( PT_ST_OVERRIDE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_pure_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_OP_ASS, type )) {
            return true;
        }
        return false;
    }

    bool is_first_base_clause ( EPostTokenType type )
    {
        if ( matchType( PT_OP_COLON, type )) {
            return true;
        }
        return false;
    }

    bool is_first_base_specifier_list ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_PRIVATE, type ) ||  matchType( PT_KW_PROTECTED, type ) ||  matchType( PT_KW_PUBLIC, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_base_specifier_dots ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_PRIVATE, type ) ||  matchType( PT_KW_PROTECTED, type ) ||  matchType( PT_KW_PUBLIC, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_base_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_PRIVATE, type ) ||  matchType( PT_KW_PROTECTED, type ) ||  matchType( PT_KW_PUBLIC, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_class_or_decltype ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_base_type_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_access_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_PRIVATE, type ) ||  matchType( PT_KW_PROTECTED, type ) ||  matchType( PT_KW_PUBLIC, type )) {
            return true;
        }
        return false;
    }

    bool is_first_conversion_function_id ( EPostTokenType type )
    {
        if ( matchType( PT_KW_OPERATOR, type )) {
            return true;
        }
        return false;
    }

    bool is_first_conversion_type_id ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_ctor_initializer ( EPostTokenType type )
    {
        if ( matchType( PT_OP_COLON, type )) {
            return true;
        }
        return false;
    }

    bool is_first_mem_initializer_list ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_mem_initializer_dots ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_mem_initializer ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_mem_initializer_id ( EPostTokenType type )
    {
        if ( matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_operator_function_id ( EPostTokenType type )
    {
        if ( matchType( PT_KW_OPERATOR, type )) {
            return true;
        }
        return false;
    }

    bool is_first_literal_operator_id ( EPostTokenType type )
    {
        if ( matchType( PT_KW_OPERATOR, type )) {
            return true;
        }
        return false;
    }

    bool is_first_template_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_TEMPLATE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_template_parameter_list ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TEMPLATE, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_template_parameter ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONSTEXPR, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_EXPLICIT, type ) ||  matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_FRIEND, type ) ||  matchType( PT_KW_INLINE, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_MUTABLE, type ) ||  matchType( PT_KW_REGISTER, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STATIC, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TEMPLATE, type ) ||  matchType( PT_KW_THREAD_LOCAL, type ) ||  matchType( PT_KW_TYPEDEF, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VIRTUAL, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_type_parameter ( EPostTokenType type )
    {
        if ( matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_TEMPLATE, type ) ||  matchType( PT_KW_TYPENAME, type )) {
            return true;
        }
        return false;
    }

    bool is_first_template_id ( EPostTokenType type )
    {
        if ( matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_TT_IDENTIFIER_T, type )) {
            return true;
        }
        return false;
    }

    bool is_first_template_argument_list ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_template_argument_dots ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_template_argument ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNOF, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_CONST_CAST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DELETE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_DYNAMIC_CAST, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FALSE, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_NEW, type ) ||  matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_NULLPTR, type ) ||  matchType( PT_KW_OPERATOR, type ) ||  matchType( PT_KW_REINTERPET_CAST, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_SIZEOF, type ) ||  matchType( PT_KW_STATIC_CAST, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_THIS, type ) ||  matchType( PT_KW_TRUE, type ) ||  matchType( PT_KW_TYPEID, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_AMP, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_COMPL, type ) ||  matchType( PT_OP_DEC, type ) ||  matchType( PT_OP_INC, type ) ||  matchType( PT_OP_LNOT, type ) ||  matchType( PT_OP_LPAREN, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_OP_MINUS, type ) ||  matchType( PT_OP_PLUS, type ) ||  matchType( PT_OP_STAR, type ) ||  matchType( PT_TT_IDENTIFIER, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type ) ||  matchType( PT_TT_LITERAL, type )) {
            return true;
        }
        return false;
    }

    bool is_first_typename_specifier ( EPostTokenType type )
    {
        if ( matchType( PT_KW_TYPENAME, type )) {
            return true;
        }
        return false;
    }

    bool is_first_explicit_instantiation ( EPostTokenType type )
    {
        if ( matchType( PT_KW_EXTERN, type ) ||  matchType( PT_KW_TEMPLATE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_explicit_specialization ( EPostTokenType type )
    {
        if ( matchType( PT_KW_TEMPLATE, type )) {
            return true;
        }
        return false;
    }

    bool is_first_try_block ( EPostTokenType type )
    {
        if ( matchType( PT_KW_TRY, type )) {
            return true;
        }
        return false;
    }

    bool is_first_function_try_block ( EPostTokenType type )
    {
        if ( matchType( PT_KW_TRY, type )) {
            return true;
        }
        return false;
    }

    bool is_first_handler ( EPostTokenType type )
    {
        if ( matchType( PT_KW_CATCH, type )) {
            return true;
        }
        return false;
    }

    bool is_first_exception_declaration ( EPostTokenType type )
    {
        if ( matchType( PT_KW_ALIGNAS, type ) ||  matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_OP_DOTS, type ) ||  matchType( PT_OP_LSQUARE, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_throw_expression ( EPostTokenType type )
    {
        if ( matchType( PT_KW_THROW, type )) {
            return true;
        }
        return false;
    }

    bool is_first_exception_specification ( EPostTokenType type )
    {
        if ( matchType( PT_KW_NOEXCEPT, type ) ||  matchType( PT_KW_THROW, type )) {
            return true;
        }
        return false;
    }

    bool is_first_dynamic_exception_specification ( EPostTokenType type )
    {
        if ( matchType( PT_KW_THROW, type )) {
            return true;
        }
        return false;
    }

    bool is_first_type_id_list ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_type_id_dots ( EPostTokenType type )
    {
        if ( matchType( PT_KW_AUTO, type ) ||  matchType( PT_KW_BOOL, type ) ||  matchType( PT_KW_CHAR, type ) ||  matchType( PT_KW_CHAR16_T, type ) ||  matchType( PT_KW_CHAR32_T, type ) ||  matchType( PT_KW_CLASS, type ) ||  matchType( PT_KW_CONST, type ) ||  matchType( PT_KW_DECLTYPE, type ) ||  matchType( PT_KW_DOUBLE, type ) ||  matchType( PT_KW_ENUM, type ) ||  matchType( PT_KW_FLOAT, type ) ||  matchType( PT_KW_INT, type ) ||  matchType( PT_KW_LONG, type ) ||  matchType( PT_KW_SHORT, type ) ||  matchType( PT_KW_SIGNED, type ) ||  matchType( PT_KW_STRUCT, type ) ||  matchType( PT_KW_TYPENAME, type ) ||  matchType( PT_KW_UNION, type ) ||  matchType( PT_KW_UNSIGNED, type ) ||  matchType( PT_KW_VOID, type ) ||  matchType( PT_KW_VOLATILE, type ) ||  matchType( PT_KW_WCHAR_T, type ) ||  matchType( PT_OP_COLON2, type ) ||  matchType( PT_TT_IDENTIFIER_C, type ) ||  matchType( PT_TT_IDENTIFIER_E, type ) ||  matchType( PT_TT_IDENTIFIER_N, type ) ||  matchType( PT_TT_IDENTIFIER_T, type ) ||  matchType( PT_TT_IDENTIFIER_Y, type )) {
            return true;
        }
        return false;
    }

    bool is_first_noexcept_specification ( EPostTokenType type )
    {
        if ( matchType( PT_KW_NOEXCEPT, type )) {
            return true;
        }
        return false;
    }

    CppAstPtr parse__translation_unit ()
    {
        if ( !is_first_translation_unit(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "translation-unit" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__declaration();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = match(PT_ST_EOF);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__primary_expression ()
    {
        if ( !is_first_primary_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "primary-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LPAREN);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__expression();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_RPAREN);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__lambda_expression();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__id_expression();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_KW_THIS);
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = match(PT_TT_LITERAL);
            if (t_4_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = match(PT_KW_NULLPTR);
            if (t_5_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = match(PT_KW_FALSE);
            if (t_6_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_7_0 = match(PT_KW_TRUE);
            if (t_7_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_7_0"] = t_7_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__type_name ()
    {
        if ( !is_first_type_name(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "type-name" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__simple_template_id();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__typedef_name();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__enum_name();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = parse__class_name();
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__class_name ()
    {
        if ( !is_first_class_name(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "class-name" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__simple_template_id();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_TT_IDENTIFIER_C);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__enum_name ()
    {
        if ( !is_first_enum_name(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "enum-name" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_TT_IDENTIFIER_E);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__namespace_name ()
    {
        if ( !is_first_namespace_name(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "namespace-name" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_TT_IDENTIFIER_N);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__template_name ()
    {
        if ( !is_first_template_name(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "template-name" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_TT_IDENTIFIER_T);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__typedef_name ()
    {
        if ( !is_first_typedef_name(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "typedef-name" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_TT_IDENTIFIER_Y);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__simple_template_id ()
    {
        if ( !is_first_simple_template_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "simple-template-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__template_name();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_ST_LT);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__template_argument_list();

            CppAstPtr t_0_3 = match(PT_ST_GT);
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__id_expression ()
    {
        if ( !is_first_id_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "id-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__qualified_id();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__unqualified_id();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__unqualified_id ()
    {
        if ( !is_first_unqualified_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "unqualified-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_COMPL);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__decltype_specifier();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_COMPL);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = parse__class_name();
            if (t_1_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__template_id();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = parse__literal_operator_id();
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = parse__conversion_function_id();
            if (t_4_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = parse__operator_function_id();
            if (t_5_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = match(PT_TT_IDENTIFIER);
            if (t_6_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__qualified_id ()
    {
        if ( !is_first_qualified_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "qualified-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__nested_name_specifier();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_KW_TEMPLATE);

            CppAstPtr t_0_2 = parse__unqualified_id();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__nested_name_specifier ()
    {
        if ( !is_first_nested_name_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "nested-name-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__nested_name_specifier_root();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__nested_name_specifier_suffix();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__nested_name_specifier_root ()
    {
        if ( !is_first_nested_name_specifier_root(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "nested-name-specifier-root" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__decltype_specifier();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_COLON2);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__namespace_name();
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_OP_COLON2);
            if (t_1_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__type_name();
            if (t_2_0->size()==0) {
                break;
            }

            CppAstPtr t_2_1 = match(PT_OP_COLON2);
            if (t_2_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_OP_COLON2);
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__nested_name_specifier_suffix ()
    {
        if ( !is_first_nested_name_specifier_suffix(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "nested-name-specifier-suffix" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_TEMPLATE);

            CppAstPtr t_0_1 = parse__simple_template_id();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_COLON2);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_TT_IDENTIFIER);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_OP_COLON2);
            if (t_1_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__lambda_expression ()
    {
        if ( !is_first_lambda_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "lambda-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__lambda_introducer();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__lambda_declarator();

            CppAstPtr t_0_2 = parse__compound_statement();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__lambda_introducer ()
    {
        if ( !is_first_lambda_introducer(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "lambda-introducer" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LSQUARE);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__lambda_capture();

            CppAstPtr t_0_2 = match(PT_OP_RSQUARE);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__lambda_capture ()
    {
        if ( !is_first_lambda_capture(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "lambda-capture" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__capture_default();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_COMMA);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__capture_list();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__capture_list();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__capture_default();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__capture_default ()
    {
        if ( !is_first_capture_default(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "capture-default" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_ASS);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_AMP);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__capture_list ()
    {
        if ( !is_first_capture_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "capture-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__capture();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_DOTS);

            CompAst* t_0_2_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_20 = match(PT_OP_COMMA);
                if (t_0_20->size()==0) {
                    break;
                }
                CppAstPtr t_0_21 = parse__capture();
                if (t_0_21->size()==0) {
                    break;
                }
                CppAstPtr t_0_22 = match(PT_OP_DOTS);
                t_0_2_ptr->astMap["t_0_20"] = t_0_20;
                t_0_2_ptr->astMap["t_0_21"] = t_0_21;
                t_0_2_ptr->astMap["t_0_22"] = t_0_22;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_2( t_0_2_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__capture ()
    {
        if ( !is_first_capture(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "capture" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_AMP);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_TT_IDENTIFIER);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_THIS);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_TT_IDENTIFIER);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__lambda_declarator ()
    {
        if ( !is_first_lambda_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "lambda-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LPAREN);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__parameter_declaration_clause();

            CppAstPtr t_0_2 = match(PT_OP_RPAREN);
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_KW_MUTABLE);

            CppAstPtr t_0_4 = parse__exception_specification();

            CompAst* t_0_5_ptr = new CompAst();
            int idx_t_0_5 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_5_ptr->astMap[to_string(idx_t_0_5)] = iterPtr;
                idx_t_0_5++;
                continue;
            }
            CppAstPtr t_0_5(t_0_5_ptr);

            CppAstPtr t_0_6 = parse__trailing_return_type();

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            ret->astMap["t_0_5"] = t_0_5;
            ret->astMap["t_0_6"] = t_0_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__postfix_expression ()
    {
        if ( !is_first_postfix_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "postfix-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__postfix_root();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__postfix_suffix();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__postfix_root ()
    {
        if ( !is_first_postfix_root(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "postfix-root" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_CONST_CAST);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_ST_LT);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__type_id();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_ST_GT);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = match(PT_OP_LPAREN);
            if (t_0_4->size()==0) {
                break;
            }

            CppAstPtr t_0_5 = parse__expression();
            if (t_0_5->size()==0) {
                break;
            }

            CppAstPtr t_0_6 = match(PT_OP_RPAREN);
            if (t_0_6->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            ret->astMap["t_0_5"] = t_0_5;
            ret->astMap["t_0_6"] = t_0_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_REINTERPET_CAST);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_ST_LT);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__type_id();
            if (t_1_2->size()==0) {
                break;
            }

            CppAstPtr t_1_3 = match(PT_ST_GT);
            if (t_1_3->size()==0) {
                break;
            }

            CppAstPtr t_1_4 = match(PT_OP_LPAREN);
            if (t_1_4->size()==0) {
                break;
            }

            CppAstPtr t_1_5 = parse__expression();
            if (t_1_5->size()==0) {
                break;
            }

            CppAstPtr t_1_6 = match(PT_OP_RPAREN);
            if (t_1_6->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            ret->astMap["t_1_4"] = t_1_4;
            ret->astMap["t_1_5"] = t_1_5;
            ret->astMap["t_1_6"] = t_1_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_STATIC_CAST);
            if (t_2_0->size()==0) {
                break;
            }

            CppAstPtr t_2_1 = match(PT_ST_LT);
            if (t_2_1->size()==0) {
                break;
            }

            CppAstPtr t_2_2 = parse__type_id();
            if (t_2_2->size()==0) {
                break;
            }

            CppAstPtr t_2_3 = match(PT_ST_GT);
            if (t_2_3->size()==0) {
                break;
            }

            CppAstPtr t_2_4 = match(PT_OP_LPAREN);
            if (t_2_4->size()==0) {
                break;
            }

            CppAstPtr t_2_5 = parse__expression();
            if (t_2_5->size()==0) {
                break;
            }

            CppAstPtr t_2_6 = match(PT_OP_RPAREN);
            if (t_2_6->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            ret->astMap["t_2_3"] = t_2_3;
            ret->astMap["t_2_4"] = t_2_4;
            ret->astMap["t_2_5"] = t_2_5;
            ret->astMap["t_2_6"] = t_2_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_KW_DYNAMIC_CAST);
            if (t_3_0->size()==0) {
                break;
            }

            CppAstPtr t_3_1 = match(PT_ST_LT);
            if (t_3_1->size()==0) {
                break;
            }

            CppAstPtr t_3_2 = parse__type_id();
            if (t_3_2->size()==0) {
                break;
            }

            CppAstPtr t_3_3 = match(PT_ST_GT);
            if (t_3_3->size()==0) {
                break;
            }

            CppAstPtr t_3_4 = match(PT_OP_LPAREN);
            if (t_3_4->size()==0) {
                break;
            }

            CppAstPtr t_3_5 = parse__expression();
            if (t_3_5->size()==0) {
                break;
            }

            CppAstPtr t_3_6 = match(PT_OP_RPAREN);
            if (t_3_6->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            ret->astMap["t_3_1"] = t_3_1;
            ret->astMap["t_3_2"] = t_3_2;
            ret->astMap["t_3_3"] = t_3_3;
            ret->astMap["t_3_4"] = t_3_4;
            ret->astMap["t_3_5"] = t_3_5;
            ret->astMap["t_3_6"] = t_3_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = match(PT_KW_TYPEID);
            if (t_4_0->size()==0) {
                break;
            }

            CppAstPtr t_4_1 = match(PT_OP_LPAREN);
            if (t_4_1->size()==0) {
                break;
            }

            CppAstPtr t_4_2 = parse__type_id();
            if (t_4_2->size()==0) {
                break;
            }

            CppAstPtr t_4_3 = match(PT_OP_RPAREN);
            if (t_4_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            ret->astMap["t_4_1"] = t_4_1;
            ret->astMap["t_4_2"] = t_4_2;
            ret->astMap["t_4_3"] = t_4_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = match(PT_KW_TYPEID);
            if (t_5_0->size()==0) {
                break;
            }

            CppAstPtr t_5_1 = match(PT_OP_LPAREN);
            if (t_5_1->size()==0) {
                break;
            }

            CppAstPtr t_5_2 = parse__expression();
            if (t_5_2->size()==0) {
                break;
            }

            CppAstPtr t_5_3 = match(PT_OP_RPAREN);
            if (t_5_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            ret->astMap["t_5_1"] = t_5_1;
            ret->astMap["t_5_2"] = t_5_2;
            ret->astMap["t_5_3"] = t_5_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = parse__typename_specifier();
            if (t_6_0->size()==0) {
                break;
            }

            CppAstPtr t_6_1 = match(PT_OP_LPAREN);
            if (t_6_1->size()==0) {
                break;
            }

            CppAstPtr t_6_2 = parse__expression_list();

            CppAstPtr t_6_3 = match(PT_OP_RPAREN);
            if (t_6_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            ret->astMap["t_6_1"] = t_6_1;
            ret->astMap["t_6_2"] = t_6_2;
            ret->astMap["t_6_3"] = t_6_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_7_0 = parse__simple_type_specifier();
            if (t_7_0->size()==0) {
                break;
            }

            CppAstPtr t_7_1 = match(PT_OP_LPAREN);
            if (t_7_1->size()==0) {
                break;
            }

            CppAstPtr t_7_2 = parse__expression_list();

            CppAstPtr t_7_3 = match(PT_OP_RPAREN);
            if (t_7_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_7_0"] = t_7_0;
            ret->astMap["t_7_1"] = t_7_1;
            ret->astMap["t_7_2"] = t_7_2;
            ret->astMap["t_7_3"] = t_7_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_8_0 = parse__typename_specifier();
            if (t_8_0->size()==0) {
                break;
            }

            CppAstPtr t_8_1 = parse__braced_init_list();
            if (t_8_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_8_0"] = t_8_0;
            ret->astMap["t_8_1"] = t_8_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_9_0 = parse__simple_type_specifier();
            if (t_9_0->size()==0) {
                break;
            }

            CppAstPtr t_9_1 = parse__braced_init_list();
            if (t_9_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_9_0"] = t_9_0;
            ret->astMap["t_9_1"] = t_9_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_10_0 = parse__primary_expression();
            if (t_10_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_10_0"] = t_10_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__postfix_suffix ()
    {
        if ( !is_first_postfix_suffix(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "postfix-suffix" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_ARROW);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_KW_TEMPLATE);

            CppAstPtr t_0_2 = parse__id_expression();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_DOT);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_KW_TEMPLATE);

            CppAstPtr t_1_2 = parse__id_expression();
            if (t_1_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_OP_LPAREN);
            if (t_2_0->size()==0) {
                break;
            }

            CppAstPtr t_2_1 = parse__expression_list();

            CppAstPtr t_2_2 = match(PT_OP_RPAREN);
            if (t_2_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_OP_LSQUARE);
            if (t_3_0->size()==0) {
                break;
            }

            CppAstPtr t_3_1 = parse__braced_init_list();
            if (t_3_1->size()==0) {
                break;
            }

            CppAstPtr t_3_2 = match(PT_OP_RSQUARE);
            if (t_3_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            ret->astMap["t_3_1"] = t_3_1;
            ret->astMap["t_3_2"] = t_3_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = match(PT_OP_LSQUARE);
            if (t_4_0->size()==0) {
                break;
            }

            CppAstPtr t_4_1 = parse__expression();
            if (t_4_1->size()==0) {
                break;
            }

            CppAstPtr t_4_2 = match(PT_OP_RSQUARE);
            if (t_4_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            ret->astMap["t_4_1"] = t_4_1;
            ret->astMap["t_4_2"] = t_4_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = match(PT_OP_ARROW);
            if (t_5_0->size()==0) {
                break;
            }

            CppAstPtr t_5_1 = parse__pseudo_destructor_name();
            if (t_5_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            ret->astMap["t_5_1"] = t_5_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = match(PT_OP_DOT);
            if (t_6_0->size()==0) {
                break;
            }

            CppAstPtr t_6_1 = parse__pseudo_destructor_name();
            if (t_6_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            ret->astMap["t_6_1"] = t_6_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_7_0 = match(PT_OP_DEC);
            if (t_7_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_7_0"] = t_7_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_8_0 = match(PT_OP_INC);
            if (t_8_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_8_0"] = t_8_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__expression_list ()
    {
        if ( !is_first_expression_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "expression-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__initializer_list();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__pseudo_destructor_name ()
    {
        if ( !is_first_pseudo_destructor_name(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "pseudo-destructor-name" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__nested_name_specifier();

            CppAstPtr t_0_1 = match(PT_OP_COMPL);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__type_name();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_COMPL);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = parse__decltype_specifier();
            if (t_1_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__unary_expression ()
    {
        if ( !is_first_unary_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "unary-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_SIZEOF);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_DOTS);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_LPAREN);
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_TT_IDENTIFIER);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = match(PT_OP_RPAREN);
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_ALIGNOF);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_OP_LPAREN);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__type_id();
            if (t_1_2->size()==0) {
                break;
            }

            CppAstPtr t_1_3 = match(PT_OP_RPAREN);
            if (t_1_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_SIZEOF);
            if (t_2_0->size()==0) {
                break;
            }

            CppAstPtr t_2_1 = match(PT_OP_LPAREN);
            if (t_2_1->size()==0) {
                break;
            }

            CppAstPtr t_2_2 = parse__type_id();
            if (t_2_2->size()==0) {
                break;
            }

            CppAstPtr t_2_3 = match(PT_OP_RPAREN);
            if (t_2_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            ret->astMap["t_2_3"] = t_2_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_KW_SIZEOF);
            if (t_3_0->size()==0) {
                break;
            }

            CppAstPtr t_3_1 = parse__unary_expression();
            if (t_3_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            ret->astMap["t_3_1"] = t_3_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = parse__unary_operator();
            if (t_4_0->size()==0) {
                break;
            }

            CppAstPtr t_4_1 = parse__cast_expression();
            if (t_4_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            ret->astMap["t_4_1"] = t_4_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = parse__delete_expression();
            if (t_5_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = parse__new_expression();
            if (t_6_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_7_0 = parse__noexcept_expression();
            if (t_7_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_7_0"] = t_7_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_8_0 = parse__postfix_expression();
            if (t_8_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_8_0"] = t_8_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__unary_operator ()
    {
        if ( !is_first_unary_operator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "unary-operator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_COMPL);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_LNOT);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_OP_MINUS);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_OP_PLUS);
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = match(PT_OP_AMP);
            if (t_4_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = match(PT_OP_STAR);
            if (t_5_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = match(PT_OP_DEC);
            if (t_6_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_7_0 = match(PT_OP_INC);
            if (t_7_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_7_0"] = t_7_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__new_expression ()
    {
        if ( !is_first_new_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "new-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_COLON2);

            CppAstPtr t_0_1 = match(PT_KW_NEW);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__new_placement();

            CppAstPtr t_0_3 = match(PT_OP_LPAREN);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = parse__type_id();
            if (t_0_4->size()==0) {
                break;
            }

            CppAstPtr t_0_5 = match(PT_OP_RPAREN);
            if (t_0_5->size()==0) {
                break;
            }

            CppAstPtr t_0_6 = parse__new_initializer();

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            ret->astMap["t_0_5"] = t_0_5;
            ret->astMap["t_0_6"] = t_0_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_COLON2);

            CppAstPtr t_1_1 = match(PT_KW_NEW);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__new_placement();

            CppAstPtr t_1_3 = parse__new_type_id();
            if (t_1_3->size()==0) {
                break;
            }

            CppAstPtr t_1_4 = parse__new_initializer();

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            ret->astMap["t_1_4"] = t_1_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__new_placement ()
    {
        if ( !is_first_new_placement(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "new-placement" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LPAREN);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__expression_list();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_RPAREN);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__new_type_id ()
    {
        if ( !is_first_new_type_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "new-type-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__type_specifier_seq();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__new_declarator();

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__new_declarator ()
    {
        if ( !is_first_new_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "new-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__ptr_operator();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__noptr_new_declarator();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_1_0_ptr = new CompAst();
            int idx_t_1_0 = 0;
            CppAstPtr firstPtr = parse__ptr_operator();
            if (firstPtr->size() == 0) {
                break;
            }
            t_1_0_ptr->astMap[to_string(idx_t_1_0)] = firstPtr;
            idx_t_1_0++;
            while (true) {
                CppAstPtr iterPtr = parse__ptr_operator();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_0_ptr->astMap[to_string(idx_t_1_0)] = iterPtr;
                idx_t_1_0++;
                continue;
            }
            CppAstPtr t_1_0(t_1_0_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__noptr_new_declarator ()
    {
        if ( !is_first_noptr_new_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "noptr-new-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LSQUARE);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__expression();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_RSQUARE);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* t_0_3_ptr = new CompAst();
            int idx_t_0_3 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_3_ptr->astMap[to_string(idx_t_0_3)] = iterPtr;
                idx_t_0_3++;
                continue;
            }
            CppAstPtr t_0_3(t_0_3_ptr);

            CompAst* t_0_4_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_40 = match(PT_OP_LSQUARE);
                if (t_0_40->size()==0) {
                    break;
                }
                CppAstPtr t_0_41 = parse__constant_expression();
                if (t_0_41->size()==0) {
                    break;
                }
                CppAstPtr t_0_42 = match(PT_OP_RSQUARE);
                if (t_0_42->size()==0) {
                    break;
                }
                CompAst* t_0_43_ptr = new CompAst();
                int idx_t_0_43 = 0;
                while (true) {
                    CppAstPtr iterPtr = parse__attribute_specifier();
                    if (iterPtr->size() == 0) {
                         break;
                    }
                    t_0_43_ptr->astMap[to_string(idx_t_0_43)] = iterPtr;
                    idx_t_0_43++;
                    continue;
                }
                CppAstPtr t_0_43(t_0_43_ptr);
                t_0_4_ptr->astMap["t_0_40"] = t_0_40;
                t_0_4_ptr->astMap["t_0_41"] = t_0_41;
                t_0_4_ptr->astMap["t_0_42"] = t_0_42;
                t_0_4_ptr->astMap["t_0_43"] = t_0_43;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_4( t_0_4_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__new_initializer ()
    {
        if ( !is_first_new_initializer(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "new-initializer" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LPAREN);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__expression_list();

            CppAstPtr t_0_2 = match(PT_OP_RPAREN);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__braced_init_list();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__delete_expression ()
    {
        if ( !is_first_delete_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "delete-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_COLON2);

            CppAstPtr t_0_1 = match(PT_KW_DELETE);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_LSQUARE);
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_RSQUARE);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = parse__cast_expression();
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_COLON2);

            CppAstPtr t_1_1 = match(PT_KW_DELETE);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__cast_expression();
            if (t_1_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__noexcept_expression ()
    {
        if ( !is_first_noexcept_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "noexcept-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_NOEXCEPT);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LPAREN);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__expression();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_RPAREN);
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__cast_expression ()
    {
        if ( !is_first_cast_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "cast-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__cast_operator();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__cast_expression();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__unary_expression();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__cast_operator ()
    {
        if ( !is_first_cast_operator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "cast-operator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LPAREN);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__type_id();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_RPAREN);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__pm_expression ()
    {
        if ( !is_first_pm_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "pm-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__cast_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = parse__pm_operator();
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__cast_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__pm_operator ()
    {
        if ( !is_first_pm_operator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "pm-operator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_ARROWSTAR);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_DOTSTAR);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__multiplicative_expression ()
    {
        if ( !is_first_multiplicative_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "multiplicative-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__pm_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = parse__multiplicative_operator();
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__pm_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__multiplicative_operator ()
    {
        if ( !is_first_multiplicative_operator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "multiplicative-operator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_MOD);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_DIV);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_OP_STAR);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__additive_expression ()
    {
        if ( !is_first_additive_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "additive-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__multiplicative_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = parse__additive_operator();
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__multiplicative_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__additive_operator ()
    {
        if ( !is_first_additive_operator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "additive-operator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_MINUS);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_PLUS);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__shift_expression ()
    {
        if ( !is_first_shift_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "shift-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__additive_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = parse__shift_operator();
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__additive_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__shift_operator ()
    {
        if ( !is_first_shift_operator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "shift-operator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_ST_RSHIFT_1);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_ST_RSHIFT_2);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_LSHIFT);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__relational_expression ()
    {
        if ( !is_first_relational_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "relational-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__shift_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = parse__relational_operator();
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__shift_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__relational_operator ()
    {
        if ( !is_first_relational_operator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "relational-operator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_GE);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_LE);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_OP_GT);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_OP_LT);
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__equality_expression ()
    {
        if ( !is_first_equality_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "equality-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__relational_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = parse__equality_operator();
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__relational_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__equality_operator ()
    {
        if ( !is_first_equality_operator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "equality-operator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_NE);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_EQ);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__and_expression ()
    {
        if ( !is_first_and_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "and-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__equality_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_AMP);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__equality_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__exclusive_or_expression ()
    {
        if ( !is_first_exclusive_or_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "exclusive-or-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__and_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_XOR);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__and_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__inclusive_or_expression ()
    {
        if ( !is_first_inclusive_or_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "inclusive-or-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__exclusive_or_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_BOR);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__exclusive_or_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__logical_and_expression ()
    {
        if ( !is_first_logical_and_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "logical-and-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__inclusive_or_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_LAND);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__inclusive_or_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__logical_or_expression ()
    {
        if ( !is_first_logical_or_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "logical-or-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__logical_and_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_LOR);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__logical_and_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__conditional_expression ()
    {
        if ( !is_first_conditional_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "conditional-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__logical_or_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            do {
                CppAstPtr t_0_10 = match(PT_OP_QMARK);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__expression();
                if (t_0_11->size()==0) {
                    break;
                }
                CppAstPtr t_0_12 = match(PT_OP_COLON);
                if (t_0_12->size()==0) {
                    break;
                }
                CppAstPtr t_0_13 = parse__assignment_expression();
                if (t_0_13->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
                t_0_1_ptr->astMap["t_0_12"] = t_0_12;
                t_0_1_ptr->astMap["t_0_13"] = t_0_13;
            }
            while (false);
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__assignment_expression ()
    {
        if ( !is_first_assignment_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "assignment-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__logical_or_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__assignment_operator();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__initializer_clause();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__throw_expression();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__conditional_expression();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__assignment_operator ()
    {
        if ( !is_first_assignment_operator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "assignment-operator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_BORASS);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_XORASS);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_OP_BANDASS);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_OP_LSHIFTASS);
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = match(PT_OP_RSHIFTASS);
            if (t_4_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = match(PT_OP_MINUSASS);
            if (t_5_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = match(PT_OP_PLUSASS);
            if (t_6_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_7_0 = match(PT_OP_MODASS);
            if (t_7_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_7_0"] = t_7_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_8_0 = match(PT_OP_DIVASS);
            if (t_8_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_8_0"] = t_8_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_9_0 = match(PT_OP_STARASS);
            if (t_9_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_9_0"] = t_9_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_10_0 = match(PT_OP_ASS);
            if (t_10_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_10_0"] = t_10_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__expression ()
    {
        if ( !is_first_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__assignment_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__assignment_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__constant_expression ()
    {
        if ( !is_first_constant_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "constant-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__conditional_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__statement ()
    {
        if ( !is_first_statement(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "statement" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__try_block();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_1_0_ptr = new CompAst();
            int idx_t_1_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_0_ptr->astMap[to_string(idx_t_1_0)] = iterPtr;
                idx_t_1_0++;
                continue;
            }
            CppAstPtr t_1_0(t_1_0_ptr);

            CppAstPtr t_1_1 = parse__jump_statement();
            if (t_1_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_2_0_ptr = new CompAst();
            int idx_t_2_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_2_0_ptr->astMap[to_string(idx_t_2_0)] = iterPtr;
                idx_t_2_0++;
                continue;
            }
            CppAstPtr t_2_0(t_2_0_ptr);

            CppAstPtr t_2_1 = parse__iteration_statement();
            if (t_2_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_3_0_ptr = new CompAst();
            int idx_t_3_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_3_0_ptr->astMap[to_string(idx_t_3_0)] = iterPtr;
                idx_t_3_0++;
                continue;
            }
            CppAstPtr t_3_0(t_3_0_ptr);

            CppAstPtr t_3_1 = parse__selection_statement();
            if (t_3_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            ret->astMap["t_3_1"] = t_3_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_4_0_ptr = new CompAst();
            int idx_t_4_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_4_0_ptr->astMap[to_string(idx_t_4_0)] = iterPtr;
                idx_t_4_0++;
                continue;
            }
            CppAstPtr t_4_0(t_4_0_ptr);

            CppAstPtr t_4_1 = parse__compound_statement();
            if (t_4_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            ret->astMap["t_4_1"] = t_4_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_5_0_ptr = new CompAst();
            int idx_t_5_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_5_0_ptr->astMap[to_string(idx_t_5_0)] = iterPtr;
                idx_t_5_0++;
                continue;
            }
            CppAstPtr t_5_0(t_5_0_ptr);

            CppAstPtr t_5_1 = parse__expression_statement();
            if (t_5_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            ret->astMap["t_5_1"] = t_5_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = parse__declaration_statement();
            if (t_6_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_7_0 = parse__labeled_statement();
            if (t_7_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_7_0"] = t_7_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__labeled_statement ()
    {
        if ( !is_first_labeled_statement(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "labeled-statement" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = match(PT_KW_CASE);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__constant_expression();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_COLON);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = parse__statement();
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_1_0_ptr = new CompAst();
            int idx_t_1_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_0_ptr->astMap[to_string(idx_t_1_0)] = iterPtr;
                idx_t_1_0++;
                continue;
            }
            CppAstPtr t_1_0(t_1_0_ptr);

            CppAstPtr t_1_1 = match(PT_KW_DEFAULT);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = match(PT_OP_COLON);
            if (t_1_2->size()==0) {
                break;
            }

            CppAstPtr t_1_3 = parse__statement();
            if (t_1_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_2_0_ptr = new CompAst();
            int idx_t_2_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_2_0_ptr->astMap[to_string(idx_t_2_0)] = iterPtr;
                idx_t_2_0++;
                continue;
            }
            CppAstPtr t_2_0(t_2_0_ptr);

            CppAstPtr t_2_1 = match(PT_TT_IDENTIFIER);
            if (t_2_1->size()==0) {
                break;
            }

            CppAstPtr t_2_2 = match(PT_OP_COLON);
            if (t_2_2->size()==0) {
                break;
            }

            CppAstPtr t_2_3 = parse__statement();
            if (t_2_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            ret->astMap["t_2_3"] = t_2_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__expression_statement ()
    {
        if ( !is_first_expression_statement(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "expression-statement" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__expression();

            CppAstPtr t_0_1 = match(PT_OP_SEMICOLON);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__compound_statement ()
    {
        if ( !is_first_compound_statement(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "compound-statement" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LBRACE);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__statement();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CppAstPtr t_0_2 = match(PT_OP_RBRACE);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__selection_statement ()
    {
        if ( !is_first_selection_statement(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "selection-statement" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_IF);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LPAREN);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__condition();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_RPAREN);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = parse__statement();
            if (t_0_4->size()==0) {
                break;
            }

            CppAstPtr t_0_5 = match(PT_KW_ELSE);
            if (t_0_5->size()==0) {
                break;
            }

            CppAstPtr t_0_6 = parse__statement();
            if (t_0_6->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            ret->astMap["t_0_5"] = t_0_5;
            ret->astMap["t_0_6"] = t_0_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_SWITCH);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_OP_LPAREN);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__condition();
            if (t_1_2->size()==0) {
                break;
            }

            CppAstPtr t_1_3 = match(PT_OP_RPAREN);
            if (t_1_3->size()==0) {
                break;
            }

            CppAstPtr t_1_4 = parse__statement();
            if (t_1_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            ret->astMap["t_1_4"] = t_1_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_IF);
            if (t_2_0->size()==0) {
                break;
            }

            CppAstPtr t_2_1 = match(PT_OP_LPAREN);
            if (t_2_1->size()==0) {
                break;
            }

            CppAstPtr t_2_2 = parse__condition();
            if (t_2_2->size()==0) {
                break;
            }

            CppAstPtr t_2_3 = match(PT_OP_RPAREN);
            if (t_2_3->size()==0) {
                break;
            }

            CppAstPtr t_2_4 = parse__statement();
            if (t_2_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            ret->astMap["t_2_3"] = t_2_3;
            ret->astMap["t_2_4"] = t_2_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__condition_declaration ()
    {
        if ( !is_first_condition_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "condition-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__decl_specifier_seq();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__declarator();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_ASS);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = parse__initializer_clause();
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_1_0_ptr = new CompAst();
            int idx_t_1_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_0_ptr->astMap[to_string(idx_t_1_0)] = iterPtr;
                idx_t_1_0++;
                continue;
            }
            CppAstPtr t_1_0(t_1_0_ptr);

            CppAstPtr t_1_1 = parse__decl_specifier_seq();
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__declarator();
            if (t_1_2->size()==0) {
                break;
            }

            CppAstPtr t_1_3 = parse__braced_init_list();
            if (t_1_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__condition ()
    {
        if ( !is_first_condition(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "condition" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__condition_declaration();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__iteration_statement ()
    {
        if ( !is_first_iteration_statement(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "iteration-statement" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_FOR);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LPAREN);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__for_init_statement();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = parse__condition();

            CppAstPtr t_0_4 = match(PT_OP_SEMICOLON);
            if (t_0_4->size()==0) {
                break;
            }

            CppAstPtr t_0_5 = parse__expression();

            CppAstPtr t_0_6 = match(PT_OP_RPAREN);
            if (t_0_6->size()==0) {
                break;
            }

            CppAstPtr t_0_7 = parse__statement();
            if (t_0_7->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            ret->astMap["t_0_5"] = t_0_5;
            ret->astMap["t_0_6"] = t_0_6;
            ret->astMap["t_0_7"] = t_0_7;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_FOR);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_OP_LPAREN);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__for_range_declaration();
            if (t_1_2->size()==0) {
                break;
            }

            CppAstPtr t_1_3 = match(PT_OP_COLON);
            if (t_1_3->size()==0) {
                break;
            }

            CppAstPtr t_1_4 = parse__for_range_initializer();
            if (t_1_4->size()==0) {
                break;
            }

            CppAstPtr t_1_5 = match(PT_OP_RPAREN);
            if (t_1_5->size()==0) {
                break;
            }

            CppAstPtr t_1_6 = parse__statement();
            if (t_1_6->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            ret->astMap["t_1_4"] = t_1_4;
            ret->astMap["t_1_5"] = t_1_5;
            ret->astMap["t_1_6"] = t_1_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_DO);
            if (t_2_0->size()==0) {
                break;
            }

            CppAstPtr t_2_1 = parse__statement();
            if (t_2_1->size()==0) {
                break;
            }

            CppAstPtr t_2_2 = match(PT_KW_WHILE);
            if (t_2_2->size()==0) {
                break;
            }

            CppAstPtr t_2_3 = match(PT_OP_LPAREN);
            if (t_2_3->size()==0) {
                break;
            }

            CppAstPtr t_2_4 = parse__expression();
            if (t_2_4->size()==0) {
                break;
            }

            CppAstPtr t_2_5 = match(PT_OP_RPAREN);
            if (t_2_5->size()==0) {
                break;
            }

            CppAstPtr t_2_6 = match(PT_OP_SEMICOLON);
            if (t_2_6->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            ret->astMap["t_2_3"] = t_2_3;
            ret->astMap["t_2_4"] = t_2_4;
            ret->astMap["t_2_5"] = t_2_5;
            ret->astMap["t_2_6"] = t_2_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_KW_WHILE);
            if (t_3_0->size()==0) {
                break;
            }

            CppAstPtr t_3_1 = match(PT_OP_LPAREN);
            if (t_3_1->size()==0) {
                break;
            }

            CppAstPtr t_3_2 = parse__condition();
            if (t_3_2->size()==0) {
                break;
            }

            CppAstPtr t_3_3 = match(PT_OP_RPAREN);
            if (t_3_3->size()==0) {
                break;
            }

            CppAstPtr t_3_4 = parse__statement();
            if (t_3_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            ret->astMap["t_3_1"] = t_3_1;
            ret->astMap["t_3_2"] = t_3_2;
            ret->astMap["t_3_3"] = t_3_3;
            ret->astMap["t_3_4"] = t_3_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__for_init_statement ()
    {
        if ( !is_first_for_init_statement(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "for-init-statement" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__simple_declaration();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__expression_statement();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__for_range_declaration ()
    {
        if ( !is_first_for_range_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "for-range-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__decl_specifier_seq();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__declarator();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__for_range_initializer ()
    {
        if ( !is_first_for_range_initializer(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "for-range-initializer" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__braced_init_list();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__expression();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__jump_statement ()
    {
        if ( !is_first_jump_statement(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "jump-statement" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_GOTO);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_TT_IDENTIFIER);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_SEMICOLON);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_RETURN);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = parse__braced_init_list();
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = match(PT_OP_SEMICOLON);
            if (t_1_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_RETURN);
            if (t_2_0->size()==0) {
                break;
            }

            CppAstPtr t_2_1 = parse__expression();

            CppAstPtr t_2_2 = match(PT_OP_SEMICOLON);
            if (t_2_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_KW_CONTINUE);
            if (t_3_0->size()==0) {
                break;
            }

            CppAstPtr t_3_1 = match(PT_OP_SEMICOLON);
            if (t_3_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            ret->astMap["t_3_1"] = t_3_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = match(PT_KW_BREAK);
            if (t_4_0->size()==0) {
                break;
            }

            CppAstPtr t_4_1 = match(PT_OP_SEMICOLON);
            if (t_4_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            ret->astMap["t_4_1"] = t_4_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__declaration_statement ()
    {
        if ( !is_first_declaration_statement(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "declaration-statement" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__block_declaration();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__declaration ()
    {
        if ( !is_first_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__attribute_declaration();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__empty_declaration();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__namespace_definition();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = parse__linkage_specification();
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = parse__explicit_specialization();
            if (t_4_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = parse__explicit_instantiation();
            if (t_5_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = parse__template_declaration();
            if (t_6_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_7_0 = parse__function_definition();
            if (t_7_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_7_0"] = t_7_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_8_0 = parse__block_declaration();
            if (t_8_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_8_0"] = t_8_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__block_declaration ()
    {
        if ( !is_first_block_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "block-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__opaque_enum_declaration();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__alias_declaration();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__static_assert_declaration();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = parse__using_directive();
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = parse__using_declaration();
            if (t_4_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = parse__namespace_alias_definition();
            if (t_5_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = parse__asm_definition();
            if (t_6_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_7_0 = parse__simple_declaration();
            if (t_7_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_7_0"] = t_7_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__alias_declaration ()
    {
        if ( !is_first_alias_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "alias-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_USING);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_TT_IDENTIFIER);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* t_0_2_ptr = new CompAst();
            int idx_t_0_2 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_2_ptr->astMap[to_string(idx_t_0_2)] = iterPtr;
                idx_t_0_2++;
                continue;
            }
            CppAstPtr t_0_2(t_0_2_ptr);

            CppAstPtr t_0_3 = match(PT_OP_ASS);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = parse__type_id();
            if (t_0_4->size()==0) {
                break;
            }

            CppAstPtr t_0_5 = match(PT_OP_SEMICOLON);
            if (t_0_5->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            ret->astMap["t_0_5"] = t_0_5;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__simple_declaration ()
    {
        if ( !is_first_simple_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "simple-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__decl_specifier_seq();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__init_declarator_list();

            CppAstPtr t_0_3 = match(PT_OP_SEMICOLON);
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__static_assert_declaration ()
    {
        if ( !is_first_static_assert_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "static_assert-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_STATIC_ASSERT);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LPAREN);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__constant_expression();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_COMMA);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = match(PT_TT_LITERAL);
            if (t_0_4->size()==0) {
                break;
            }

            CppAstPtr t_0_5 = match(PT_OP_RPAREN);
            if (t_0_5->size()==0) {
                break;
            }

            CppAstPtr t_0_6 = match(PT_OP_SEMICOLON);
            if (t_0_6->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            ret->astMap["t_0_5"] = t_0_5;
            ret->astMap["t_0_6"] = t_0_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__empty_declaration ()
    {
        if ( !is_first_empty_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "empty-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_SEMICOLON);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__attribute_declaration ()
    {
        if ( !is_first_attribute_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "attribute-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            CppAstPtr firstPtr = parse__attribute_specifier();
            if (firstPtr->size() == 0) {
                break;
            }
            t_0_0_ptr->astMap[to_string(idx_t_0_0)] = firstPtr;
            idx_t_0_0++;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = match(PT_OP_SEMICOLON);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__decl_specifier ()
    {
        if ( !is_first_decl_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "decl-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_CONSTEXPR);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_TYPEDEF);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_FRIEND);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = parse__function_specifier();
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = parse__type_specifier();
            if (t_4_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = parse__storage_class_specifier();
            if (t_5_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__decl_specifier_seq ()
    {
        if ( !is_first_decl_specifier_seq(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "decl-specifier-seq" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            CppAstPtr firstPtr = parse__decl_specifier();
            if (firstPtr->size() == 0) {
                break;
            }
            t_0_0_ptr->astMap[to_string(idx_t_0_0)] = firstPtr;
            idx_t_0_0++;
            while (true) {
                CppAstPtr iterPtr = parse__decl_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__storage_class_specifier ()
    {
        if ( !is_first_storage_class_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "storage-class-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_MUTABLE);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_EXTERN);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_THREAD_LOCAL);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_KW_STATIC);
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = match(PT_KW_REGISTER);
            if (t_4_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__function_specifier ()
    {
        if ( !is_first_function_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "function-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_EXPLICIT);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_VIRTUAL);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_INLINE);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__type_specifier ()
    {
        if ( !is_first_type_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "type-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__enum_specifier();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__class_specifier();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__trailing_type_specifier();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__trailing_type_specifier ()
    {
        if ( !is_first_trailing_type_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "trailing-type-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__cv_qualifier();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__typename_specifier();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__elaborated_type_specifier();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = parse__simple_type_specifier();
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__type_specifier_seq ()
    {
        if ( !is_first_type_specifier_seq(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "type-specifier-seq" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            CppAstPtr firstPtr = parse__type_specifier();
            if (firstPtr->size() == 0) {
                break;
            }
            t_0_0_ptr->astMap[to_string(idx_t_0_0)] = firstPtr;
            idx_t_0_0++;
            while (true) {
                CppAstPtr iterPtr = parse__type_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__trailing_type_specifier_seq ()
    {
        if ( !is_first_trailing_type_specifier_seq(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "trailing-type-specifier-seq" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            CppAstPtr firstPtr = parse__trailing_type_specifier();
            if (firstPtr->size() == 0) {
                break;
            }
            t_0_0_ptr->astMap[to_string(idx_t_0_0)] = firstPtr;
            idx_t_0_0++;
            while (true) {
                CppAstPtr iterPtr = parse__trailing_type_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__simple_type_specifier ()
    {
        if ( !is_first_simple_type_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "simple-type-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__nested_name_specifier();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_KW_TEMPLATE);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__simple_template_id();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__nested_name_specifier();

            CppAstPtr t_1_1 = parse__type_name();
            if (t_1_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_CHAR);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = parse__decltype_specifier();
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = match(PT_KW_CHAR16_T);
            if (t_4_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = match(PT_KW_WCHAR_T);
            if (t_5_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = match(PT_KW_AUTO);
            if (t_6_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_7_0 = match(PT_KW_VOID);
            if (t_7_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_7_0"] = t_7_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_8_0 = match(PT_KW_DOUBLE);
            if (t_8_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_8_0"] = t_8_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_9_0 = match(PT_KW_FLOAT);
            if (t_9_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_9_0"] = t_9_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_10_0 = match(PT_KW_UNSIGNED);
            if (t_10_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_10_0"] = t_10_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_11_0 = match(PT_KW_LONG);
            if (t_11_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_11_0"] = t_11_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_12_0 = match(PT_KW_SIGNED);
            if (t_12_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_12_0"] = t_12_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_13_0 = match(PT_KW_INT);
            if (t_13_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_13_0"] = t_13_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_14_0 = match(PT_KW_SHORT);
            if (t_14_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_14_0"] = t_14_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_15_0 = match(PT_KW_BOOL);
            if (t_15_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_15_0"] = t_15_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_16_0 = match(PT_KW_CHAR32_T);
            if (t_16_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_16_0"] = t_16_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__decltype_specifier ()
    {
        if ( !is_first_decltype_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "decltype-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_DECLTYPE);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LPAREN);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__expression();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_RPAREN);
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__elaborated_type_specifier ()
    {
        if ( !is_first_elaborated_type_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "elaborated-type-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__class_key();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__nested_name_specifier();

            CppAstPtr t_0_2 = match(PT_KW_TEMPLATE);

            CppAstPtr t_0_3 = parse__simple_template_id();
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__class_key();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* t_1_1_ptr = new CompAst();
            int idx_t_1_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_1_ptr->astMap[to_string(idx_t_1_1)] = iterPtr;
                idx_t_1_1++;
                continue;
            }
            CppAstPtr t_1_1(t_1_1_ptr);

            CppAstPtr t_1_2 = parse__nested_name_specifier();

            CppAstPtr t_1_3 = match(PT_TT_IDENTIFIER);
            if (t_1_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_ENUM);
            if (t_2_0->size()==0) {
                break;
            }

            CppAstPtr t_2_1 = parse__nested_name_specifier();

            CppAstPtr t_2_2 = match(PT_TT_IDENTIFIER);
            if (t_2_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__enum_specifier ()
    {
        if ( !is_first_enum_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "enum-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__enum_head();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LBRACE);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__enumerator_list();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_COMMA);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = match(PT_OP_RBRACE);
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__enum_head();
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_OP_LBRACE);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__enumerator_list();

            CppAstPtr t_1_3 = match(PT_OP_RBRACE);
            if (t_1_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__enum_head ()
    {
        if ( !is_first_enum_head(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "enum-head" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__enum_key();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CppAstPtr t_0_2 = parse__nested_name_specifier();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_TT_IDENTIFIER);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = parse__enum_base();

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__enum_key();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* t_1_1_ptr = new CompAst();
            int idx_t_1_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_1_ptr->astMap[to_string(idx_t_1_1)] = iterPtr;
                idx_t_1_1++;
                continue;
            }
            CppAstPtr t_1_1(t_1_1_ptr);

            CppAstPtr t_1_2 = match(PT_TT_IDENTIFIER);

            CppAstPtr t_1_3 = parse__enum_base();

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__opaque_enum_declaration ()
    {
        if ( !is_first_opaque_enum_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "opaque-enum-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__enum_key();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CppAstPtr t_0_2 = match(PT_TT_IDENTIFIER);
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = parse__enum_base();

            CppAstPtr t_0_4 = match(PT_OP_SEMICOLON);
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__enum_key ()
    {
        if ( !is_first_enum_key(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "enum-key" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_ENUM);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_KW_STRUCT);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_ENUM);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_KW_CLASS);
            if (t_1_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_ENUM);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__enum_base ()
    {
        if ( !is_first_enum_base(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "enum-base" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_COLON);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__type_specifier_seq();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__enumerator_list ()
    {
        if ( !is_first_enumerator_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "enumerator-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__enumerator_definition();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__enumerator_definition();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__enumerator_definition ()
    {
        if ( !is_first_enumerator_definition(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "enumerator-definition" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__enumerator();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_ASS);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__constant_expression();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__enumerator();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__enumerator ()
    {
        if ( !is_first_enumerator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "enumerator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_TT_IDENTIFIER);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__namespace_definition ()
    {
        if ( !is_first_namespace_definition(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "namespace-definition" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_INLINE);

            CppAstPtr t_0_1 = match(PT_KW_NAMESPACE);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_TT_IDENTIFIER);

            CppAstPtr t_0_3 = match(PT_OP_LBRACE);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = parse__namespace_body();

            CppAstPtr t_0_5 = match(PT_OP_RBRACE);
            if (t_0_5->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            ret->astMap["t_0_5"] = t_0_5;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__namespace_body ()
    {
        if ( !is_first_namespace_body(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "namespace-body" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__declaration();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__namespace_alias_definition ()
    {
        if ( !is_first_namespace_alias_definition(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "namespace-alias-definition" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_NAMESPACE);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_TT_IDENTIFIER);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_ASS);
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = parse__qualified_namespace_specifier();
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = match(PT_OP_SEMICOLON);
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__qualified_namespace_specifier ()
    {
        if ( !is_first_qualified_namespace_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "qualified-namespace-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__nested_name_specifier();

            CppAstPtr t_0_1 = parse__namespace_name();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__using_declaration ()
    {
        if ( !is_first_using_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "using-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_USING);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_KW_TYPENAME);

            CppAstPtr t_0_2 = parse__nested_name_specifier();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = parse__unqualified_id();
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = match(PT_OP_SEMICOLON);
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_USING);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_OP_COLON2);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__unqualified_id();
            if (t_1_2->size()==0) {
                break;
            }

            CppAstPtr t_1_3 = match(PT_OP_SEMICOLON);
            if (t_1_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__using_directive ()
    {
        if ( !is_first_using_directive(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "using-directive" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = match(PT_KW_USING);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_KW_NAMESPACE);
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = parse__nested_name_specifier();

            CppAstPtr t_0_4 = match(PT_TT_IDENTIFIER);
            if (t_0_4->size()==0) {
                break;
            }

            CppAstPtr t_0_5 = match(PT_OP_SEMICOLON);
            if (t_0_5->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            ret->astMap["t_0_5"] = t_0_5;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__asm_definition ()
    {
        if ( !is_first_asm_definition(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "asm-definition" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_ASM);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LPAREN);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_TT_LITERAL);
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_RPAREN);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = match(PT_OP_SEMICOLON);
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__linkage_specification ()
    {
        if ( !is_first_linkage_specification(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "linkage-specification" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_EXTERN);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_TT_LITERAL);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_LBRACE);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* t_0_3_ptr = new CompAst();
            int idx_t_0_3 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__declaration();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_3_ptr->astMap[to_string(idx_t_0_3)] = iterPtr;
                idx_t_0_3++;
                continue;
            }
            CppAstPtr t_0_3(t_0_3_ptr);

            CppAstPtr t_0_4 = match(PT_OP_RBRACE);
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_EXTERN);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_TT_LITERAL);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__declaration();
            if (t_1_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__attribute_specifier ()
    {
        if ( !is_first_attribute_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "attribute-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LSQUARE);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LSQUARE);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__attribute_list();

            CppAstPtr t_0_3 = match(PT_OP_RSQUARE);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = match(PT_OP_RSQUARE);
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__alignment_specifier();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__alignment_specifier ()
    {
        if ( !is_first_alignment_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "alignment-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_ALIGNAS);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LPAREN);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__assignment_expression();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_DOTS);

            CppAstPtr t_0_4 = match(PT_OP_RPAREN);
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_ALIGNAS);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_OP_LPAREN);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__type_id();
            if (t_1_2->size()==0) {
                break;
            }

            CppAstPtr t_1_3 = match(PT_OP_DOTS);

            CppAstPtr t_1_4 = match(PT_OP_RPAREN);
            if (t_1_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            ret->astMap["t_1_4"] = t_1_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__attribute_list ()
    {
        if ( !is_first_attribute_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "attribute-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__attribute_part();

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__attribute_part();
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__attribute_part ()
    {
        if ( !is_first_attribute_part(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "attribute-part" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__attribute();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_DOTS);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__attribute();

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__attribute ()
    {
        if ( !is_first_attribute(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "attribute" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__attribute_token();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__attribute_argument_clause();

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__attribute_token ()
    {
        if ( !is_first_attribute_token(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "attribute-token" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__attribute_scoped_token();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_TT_IDENTIFIER);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__attribute_scoped_token ()
    {
        if ( !is_first_attribute_scoped_token(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "attribute-scoped-token" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__attribute_namespace();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_COLON2);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_TT_IDENTIFIER);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__attribute_namespace ()
    {
        if ( !is_first_attribute_namespace(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "attribute-namespace" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_TT_IDENTIFIER);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__attribute_argument_clause ()
    {
        if ( !is_first_attribute_argument_clause(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "attribute-argument-clause" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LPAREN);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__balanced_token();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CppAstPtr t_0_2 = match(PT_OP_RPAREN);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__balanced_token ()
    {
        if ( !is_first_balanced_token(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "balanced-token" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LBRACE);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__balanced_token();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CppAstPtr t_0_2 = match(PT_OP_RBRACE);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_LSQUARE);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* t_1_1_ptr = new CompAst();
            int idx_t_1_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__balanced_token();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_1_ptr->astMap[to_string(idx_t_1_1)] = iterPtr;
                idx_t_1_1++;
                continue;
            }
            CppAstPtr t_1_1(t_1_1_ptr);

            CppAstPtr t_1_2 = match(PT_OP_RSQUARE);
            if (t_1_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_OP_LPAREN);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* t_2_1_ptr = new CompAst();
            int idx_t_2_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__balanced_token();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_2_1_ptr->astMap[to_string(idx_t_2_1)] = iterPtr;
                idx_t_2_1++;
                continue;
            }
            CppAstPtr t_2_1(t_2_1_ptr);

            CppAstPtr t_2_2 = match(PT_OP_RPAREN);
            if (t_2_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_ST_NONPAREN);
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__init_declarator_list ()
    {
        if ( !is_first_init_declarator_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "init-declarator-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__init_declarator();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__init_declarator();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__init_declarator ()
    {
        if ( !is_first_init_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "init-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__declarator();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__initializer();

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__declarator ()
    {
        if ( !is_first_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__noptr_declarator();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__trailing_return_type();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__ptr_declarator();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__ptr_declarator ()
    {
        if ( !is_first_ptr_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "ptr-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__ptr_operator();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__noptr_declarator();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__noptr_declarator ()
    {
        if ( !is_first_noptr_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "noptr-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__noptr_declarator_root();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = parse__noptr_declarator_suffix();
                if (t_0_10->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__noptr_declarator_root ()
    {
        if ( !is_first_noptr_declarator_root(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "noptr-declarator-root" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LPAREN);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__ptr_declarator();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_RPAREN);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__declarator_id();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* t_1_1_ptr = new CompAst();
            int idx_t_1_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_1_ptr->astMap[to_string(idx_t_1_1)] = iterPtr;
                idx_t_1_1++;
                continue;
            }
            CppAstPtr t_1_1(t_1_1_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__noptr_declarator_suffix ()
    {
        if ( !is_first_noptr_declarator_suffix(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "noptr-declarator-suffix" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LSQUARE);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__constant_expression();

            CppAstPtr t_0_2 = match(PT_OP_RSQUARE);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* t_0_3_ptr = new CompAst();
            int idx_t_0_3 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_3_ptr->astMap[to_string(idx_t_0_3)] = iterPtr;
                idx_t_0_3++;
                continue;
            }
            CppAstPtr t_0_3(t_0_3_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__parameters_and_qualifiers();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__parameters_and_qualifiers ()
    {
        if ( !is_first_parameters_and_qualifiers(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "parameters-and-qualifiers" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LPAREN);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__parameter_declaration_clause();

            CppAstPtr t_0_2 = match(PT_OP_RPAREN);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* t_0_3_ptr = new CompAst();
            int idx_t_0_3 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__cv_qualifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_3_ptr->astMap[to_string(idx_t_0_3)] = iterPtr;
                idx_t_0_3++;
                continue;
            }
            CppAstPtr t_0_3(t_0_3_ptr);

            CppAstPtr t_0_4 = parse__ref_qualifier();

            CppAstPtr t_0_5 = parse__exception_specification();

            CompAst* t_0_6_ptr = new CompAst();
            int idx_t_0_6 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_6_ptr->astMap[to_string(idx_t_0_6)] = iterPtr;
                idx_t_0_6++;
                continue;
            }
            CppAstPtr t_0_6(t_0_6_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            ret->astMap["t_0_5"] = t_0_5;
            ret->astMap["t_0_6"] = t_0_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__trailing_return_type ()
    {
        if ( !is_first_trailing_return_type(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "trailing-return-type" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_ARROW);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__trailing_type_specifier_seq();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__abstract_declarator();

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__ptr_operator ()
    {
        if ( !is_first_ptr_operator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "ptr-operator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__nested_name_specifier();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_STAR);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* t_0_2_ptr = new CompAst();
            int idx_t_0_2 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_2_ptr->astMap[to_string(idx_t_0_2)] = iterPtr;
                idx_t_0_2++;
                continue;
            }
            CppAstPtr t_0_2(t_0_2_ptr);

            CompAst* t_0_3_ptr = new CompAst();
            int idx_t_0_3 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__cv_qualifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_3_ptr->astMap[to_string(idx_t_0_3)] = iterPtr;
                idx_t_0_3++;
                continue;
            }
            CppAstPtr t_0_3(t_0_3_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_STAR);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* t_1_1_ptr = new CompAst();
            int idx_t_1_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_1_ptr->astMap[to_string(idx_t_1_1)] = iterPtr;
                idx_t_1_1++;
                continue;
            }
            CppAstPtr t_1_1(t_1_1_ptr);

            CompAst* t_1_2_ptr = new CompAst();
            int idx_t_1_2 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__cv_qualifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_2_ptr->astMap[to_string(idx_t_1_2)] = iterPtr;
                idx_t_1_2++;
                continue;
            }
            CppAstPtr t_1_2(t_1_2_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_OP_LAND);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* t_2_1_ptr = new CompAst();
            int idx_t_2_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_2_1_ptr->astMap[to_string(idx_t_2_1)] = iterPtr;
                idx_t_2_1++;
                continue;
            }
            CppAstPtr t_2_1(t_2_1_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_OP_AMP);
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* t_3_1_ptr = new CompAst();
            int idx_t_3_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_3_1_ptr->astMap[to_string(idx_t_3_1)] = iterPtr;
                idx_t_3_1++;
                continue;
            }
            CppAstPtr t_3_1(t_3_1_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            ret->astMap["t_3_1"] = t_3_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__cv_qualifier ()
    {
        if ( !is_first_cv_qualifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "cv-qualifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_VOLATILE);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_CONST);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__ref_qualifier ()
    {
        if ( !is_first_ref_qualifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "ref-qualifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LAND);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_AMP);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__declarator_id ()
    {
        if ( !is_first_declarator_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "declarator-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_DOTS);

            CppAstPtr t_0_1 = parse__id_expression();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__type_id ()
    {
        if ( !is_first_type_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "type-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__type_specifier_seq();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__abstract_declarator();

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__abstract_declarator ()
    {
        if ( !is_first_abstract_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "abstract-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__noptr_abstract_declarator();

            CppAstPtr t_0_1 = parse__trailing_return_type();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__abstract_pack_declarator();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__ptr_abstract_declarator();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__ptr_abstract_declarator ()
    {
        if ( !is_first_ptr_abstract_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "ptr-abstract-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__ptr_operator();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__noptr_abstract_declarator();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_1_0_ptr = new CompAst();
            int idx_t_1_0 = 0;
            CppAstPtr firstPtr = parse__ptr_operator();
            if (firstPtr->size() == 0) {
                break;
            }
            t_1_0_ptr->astMap[to_string(idx_t_1_0)] = firstPtr;
            idx_t_1_0++;
            while (true) {
                CppAstPtr iterPtr = parse__ptr_operator();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_0_ptr->astMap[to_string(idx_t_1_0)] = iterPtr;
                idx_t_1_0++;
                continue;
            }
            CppAstPtr t_1_0(t_1_0_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__noptr_abstract_declarator ()
    {
        if ( !is_first_noptr_abstract_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "noptr-abstract-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__noptr_abstract_declarator_root();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__noptr_declarator_suffix();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_1_0_ptr = new CompAst();
            int idx_t_1_0 = 0;
            CppAstPtr firstPtr = parse__noptr_declarator_suffix();
            if (firstPtr->size() == 0) {
                break;
            }
            t_1_0_ptr->astMap[to_string(idx_t_1_0)] = firstPtr;
            idx_t_1_0++;
            while (true) {
                CppAstPtr iterPtr = parse__noptr_declarator_suffix();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_0_ptr->astMap[to_string(idx_t_1_0)] = iterPtr;
                idx_t_1_0++;
                continue;
            }
            CppAstPtr t_1_0(t_1_0_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__noptr_abstract_declarator_root ()
    {
        if ( !is_first_noptr_abstract_declarator_root(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "noptr-abstract-declarator-root" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LPAREN);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__ptr_abstract_declarator();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_RPAREN);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__noptr_declarator_suffix();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__abstract_pack_declarator ()
    {
        if ( !is_first_abstract_pack_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "abstract-pack-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__ptr_operator();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__noptr_abstract_pack_declarator();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__noptr_abstract_pack_declarator ()
    {
        if ( !is_first_noptr_abstract_pack_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "noptr-abstract-pack-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_DOTS);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__noptr_declarator_suffix();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__parameter_declaration_clause ()
    {
        if ( !is_first_parameter_declaration_clause(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "parameter-declaration-clause" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__parameter_declaration_list();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_COMMA);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_DOTS);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__parameter_declaration_list();

            CppAstPtr t_1_1 = match(PT_OP_DOTS);

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__parameter_declaration_list ()
    {
        if ( !is_first_parameter_declaration_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "parameter-declaration-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__parameter_declaration();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__parameter_declaration();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__parameter_declaration ()
    {
        if ( !is_first_parameter_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "parameter-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__decl_specifier_seq();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__declarator();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* t_0_3_ptr = new CompAst();
            do {
                CppAstPtr t_0_30 = match(PT_OP_ASS);
                if (t_0_30->size()==0) {
                    break;
                }
                CppAstPtr t_0_31 = parse__initializer_clause();
                if (t_0_31->size()==0) {
                    break;
                }
                t_0_3_ptr->astMap["t_0_30"] = t_0_30;
                t_0_3_ptr->astMap["t_0_31"] = t_0_31;
            }
            while (false);
            CppAstPtr t_0_3( t_0_3_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_1_0_ptr = new CompAst();
            int idx_t_1_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_0_ptr->astMap[to_string(idx_t_1_0)] = iterPtr;
                idx_t_1_0++;
                continue;
            }
            CppAstPtr t_1_0(t_1_0_ptr);

            CppAstPtr t_1_1 = parse__decl_specifier_seq();
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__abstract_declarator();

            CompAst* t_1_3_ptr = new CompAst();
            do {
                CppAstPtr t_1_30 = match(PT_OP_ASS);
                if (t_1_30->size()==0) {
                    break;
                }
                CppAstPtr t_1_31 = parse__initializer_clause();
                if (t_1_31->size()==0) {
                    break;
                }
                t_1_3_ptr->astMap["t_1_30"] = t_1_30;
                t_1_3_ptr->astMap["t_1_31"] = t_1_31;
            }
            while (false);
            CppAstPtr t_1_3( t_1_3_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__function_definition ()
    {
        if ( !is_first_function_definition(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "function-definition" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__decl_specifier_seq();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__declarator();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* t_0_3_ptr = new CompAst();
            int idx_t_0_3 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__virt_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_3_ptr->astMap[to_string(idx_t_0_3)] = iterPtr;
                idx_t_0_3++;
                continue;
            }
            CppAstPtr t_0_3(t_0_3_ptr);

            CppAstPtr t_0_4 = parse__function_body();
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__function_body ()
    {
        if ( !is_first_function_body(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "function-body" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_ASS);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_KW_DELETE);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_SEMICOLON);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_ASS);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_KW_DEFAULT);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = match(PT_OP_SEMICOLON);
            if (t_1_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__ctor_initializer();

            CppAstPtr t_2_1 = parse__compound_statement();
            if (t_2_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = parse__function_try_block();
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__initializer ()
    {
        if ( !is_first_initializer(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "initializer" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LPAREN);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__expression_list();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_RPAREN);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__brace_or_equal_initializer();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__brace_or_equal_initializer ()
    {
        if ( !is_first_brace_or_equal_initializer(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "brace-or-equal-initializer" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_ASS);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__initializer_clause();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__braced_init_list();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__initializer_clause ()
    {
        if ( !is_first_initializer_clause(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "initializer-clause" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__braced_init_list();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__assignment_expression();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__initializer_list ()
    {
        if ( !is_first_initializer_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "initializer-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__initializer_clause_dots();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__initializer_clause_dots();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__initializer_clause_dots ()
    {
        if ( !is_first_initializer_clause_dots(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "initializer-clause-dots" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__initializer_clause();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_DOTS);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__braced_init_list ()
    {
        if ( !is_first_braced_init_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "braced-init-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_LBRACE);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__initializer_list();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_COMMA);

            CppAstPtr t_0_3 = match(PT_OP_RBRACE);
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_OP_LBRACE);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_OP_RBRACE);
            if (t_1_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__class_specifier ()
    {
        if ( !is_first_class_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "class-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__class_head();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LBRACE);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* t_0_2_ptr = new CompAst();
            int idx_t_0_2 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__member_specification();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_2_ptr->astMap[to_string(idx_t_0_2)] = iterPtr;
                idx_t_0_2++;
                continue;
            }
            CppAstPtr t_0_2(t_0_2_ptr);

            CppAstPtr t_0_3 = match(PT_OP_RBRACE);
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__class_head ()
    {
        if ( !is_first_class_head(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "class-head" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__class_key();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CppAstPtr t_0_2 = parse__class_head_name();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = parse__class_virt_specifier();

            CppAstPtr t_0_4 = parse__base_clause();

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__class_key();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* t_1_1_ptr = new CompAst();
            int idx_t_1_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_1_ptr->astMap[to_string(idx_t_1_1)] = iterPtr;
                idx_t_1_1++;
                continue;
            }
            CppAstPtr t_1_1(t_1_1_ptr);

            CppAstPtr t_1_2 = parse__base_clause();

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__class_head_name ()
    {
        if ( !is_first_class_head_name(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "class-head-name" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__nested_name_specifier();

            CppAstPtr t_0_1 = parse__class_name();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__class_virt_specifier ()
    {
        if ( !is_first_class_virt_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "class-virt-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_ST_FINAL);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__class_key ()
    {
        if ( !is_first_class_key(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "class-key" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_UNION);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_STRUCT);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_CLASS);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__member_specification ()
    {
        if ( !is_first_member_specification(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "member-specification" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__access_specifier();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_COLON);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__member_declaration();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__member_declaration ()
    {
        if ( !is_first_member_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "member-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__decl_specifier_seq();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__member_declarator_list();

            CppAstPtr t_0_3 = match(PT_OP_SEMICOLON);
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__function_definition();
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_OP_SEMICOLON);

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__alias_declaration();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = parse__template_declaration();
            if (t_3_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = parse__static_assert_declaration();
            if (t_4_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = parse__using_declaration();
            if (t_5_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__member_declarator_list ()
    {
        if ( !is_first_member_declarator_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "member-declarator-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__member_declarator();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__member_declarator();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__member_declarator ()
    {
        if ( !is_first_member_declarator(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "member-declarator" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_TT_IDENTIFIER);

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CppAstPtr t_0_2 = match(PT_OP_COLON);
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = parse__constant_expression();
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__declarator();
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = parse__brace_or_equal_initializer();

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__declarator();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* t_2_1_ptr = new CompAst();
            int idx_t_2_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__virt_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_2_1_ptr->astMap[to_string(idx_t_2_1)] = iterPtr;
                idx_t_2_1++;
                continue;
            }
            CppAstPtr t_2_1(t_2_1_ptr);

            CppAstPtr t_2_2 = parse__pure_specifier();

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__virt_specifier ()
    {
        if ( !is_first_virt_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "virt-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_ST_FINAL);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_ST_OVERRIDE);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__pure_specifier ()
    {
        if ( !is_first_pure_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "pure-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_ASS);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_ST_ZERO);
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__base_clause ()
    {
        if ( !is_first_base_clause(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "base-clause" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_COLON);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__base_specifier_list();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__base_specifier_list ()
    {
        if ( !is_first_base_specifier_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "base-specifier-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__base_specifier_dots();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__base_specifier_dots();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__base_specifier_dots ()
    {
        if ( !is_first_base_specifier_dots(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "base-specifier-dots" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__base_specifier();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_DOTS);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__base_specifier ()
    {
        if ( !is_first_base_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "base-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CppAstPtr t_0_1 = parse__access_specifier();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_KW_VIRTUAL);

            CppAstPtr t_0_3 = parse__base_type_specifier();
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_1_0_ptr = new CompAst();
            int idx_t_1_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_0_ptr->astMap[to_string(idx_t_1_0)] = iterPtr;
                idx_t_1_0++;
                continue;
            }
            CppAstPtr t_1_0(t_1_0_ptr);

            CppAstPtr t_1_1 = match(PT_KW_VIRTUAL);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__access_specifier();

            CppAstPtr t_1_3 = parse__base_type_specifier();
            if (t_1_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_2_0_ptr = new CompAst();
            int idx_t_2_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_2_0_ptr->astMap[to_string(idx_t_2_0)] = iterPtr;
                idx_t_2_0++;
                continue;
            }
            CppAstPtr t_2_0(t_2_0_ptr);

            CppAstPtr t_2_1 = parse__base_type_specifier();
            if (t_2_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__class_or_decltype ()
    {
        if ( !is_first_class_or_decltype(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "class-or-decltype" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__nested_name_specifier();

            CppAstPtr t_0_1 = parse__class_name();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__decltype_specifier();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__base_type_specifier ()
    {
        if ( !is_first_base_type_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "base-type-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__class_or_decltype();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__access_specifier ()
    {
        if ( !is_first_access_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "access-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_PUBLIC);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_PROTECTED);
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_PRIVATE);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__conversion_function_id ()
    {
        if ( !is_first_conversion_function_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "conversion-function-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_OPERATOR);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__conversion_type_id();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__conversion_type_id ()
    {
        if ( !is_first_conversion_type_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "conversion-type-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__type_specifier_seq();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__ptr_operator();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__ctor_initializer ()
    {
        if ( !is_first_ctor_initializer(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "ctor-initializer" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_OP_COLON);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__mem_initializer_list();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__mem_initializer_list ()
    {
        if ( !is_first_mem_initializer_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "mem-initializer-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__mem_initializer_dots();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__mem_initializer_dots();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__mem_initializer_dots ()
    {
        if ( !is_first_mem_initializer_dots(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "mem-initializer-dots" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__mem_initializer();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_DOTS);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__mem_initializer ()
    {
        if ( !is_first_mem_initializer(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "mem-initializer" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__mem_initializer_id();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LPAREN);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__expression_list();

            CppAstPtr t_0_3 = match(PT_OP_RPAREN);
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__mem_initializer_id();
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = parse__braced_init_list();
            if (t_1_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__mem_initializer_id ()
    {
        if ( !is_first_mem_initializer_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "mem-initializer-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_TT_IDENTIFIER);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__class_or_decltype();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__operator_function_id ()
    {
        if ( !is_first_operator_function_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "operator-function-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_OPERATOR);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_KW_DELETE);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_OP_LSQUARE);
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_RSQUARE);
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_OPERATOR);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_KW_NEW);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = match(PT_OP_LSQUARE);
            if (t_1_2->size()==0) {
                break;
            }

            CppAstPtr t_1_3 = match(PT_OP_RSQUARE);
            if (t_1_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_OPERATOR);
            if (t_2_0->size()==0) {
                break;
            }

            CppAstPtr t_2_1 = match(PT_OP_LSQUARE);
            if (t_2_1->size()==0) {
                break;
            }

            CppAstPtr t_2_2 = match(PT_OP_RSQUARE);
            if (t_2_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_KW_OPERATOR);
            if (t_3_0->size()==0) {
                break;
            }

            CppAstPtr t_3_1 = match(PT_OP_LPAREN);
            if (t_3_1->size()==0) {
                break;
            }

            CppAstPtr t_3_2 = match(PT_OP_RPAREN);
            if (t_3_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            ret->astMap["t_3_1"] = t_3_1;
            ret->astMap["t_3_2"] = t_3_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = match(PT_KW_OPERATOR);
            if (t_4_0->size()==0) {
                break;
            }

            CppAstPtr t_4_1 = match(PT_ST_RSHIFT_1);
            if (t_4_1->size()==0) {
                break;
            }

            CppAstPtr t_4_2 = match(PT_ST_RSHIFT_2);
            if (t_4_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            ret->astMap["t_4_1"] = t_4_1;
            ret->astMap["t_4_2"] = t_4_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = match(PT_KW_OPERATOR);
            if (t_5_0->size()==0) {
                break;
            }

            CppAstPtr t_5_1 = match(PT_KW_NEW);
            if (t_5_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            ret->astMap["t_5_1"] = t_5_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_6_0 = match(PT_KW_OPERATOR);
            if (t_6_0->size()==0) {
                break;
            }

            CppAstPtr t_6_1 = match(PT_OP_DIV);
            if (t_6_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_6_0"] = t_6_0;
            ret->astMap["t_6_1"] = t_6_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_7_0 = match(PT_KW_OPERATOR);
            if (t_7_0->size()==0) {
                break;
            }

            CppAstPtr t_7_1 = match(PT_OP_LT);
            if (t_7_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_7_0"] = t_7_0;
            ret->astMap["t_7_1"] = t_7_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_8_0 = match(PT_KW_OPERATOR);
            if (t_8_0->size()==0) {
                break;
            }

            CppAstPtr t_8_1 = match(PT_OP_ARROW);
            if (t_8_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_8_0"] = t_8_0;
            ret->astMap["t_8_1"] = t_8_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_9_0 = match(PT_KW_OPERATOR);
            if (t_9_0->size()==0) {
                break;
            }

            CppAstPtr t_9_1 = match(PT_OP_ARROWSTAR);
            if (t_9_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_9_0"] = t_9_0;
            ret->astMap["t_9_1"] = t_9_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_10_0 = match(PT_KW_OPERATOR);
            if (t_10_0->size()==0) {
                break;
            }

            CppAstPtr t_10_1 = match(PT_OP_COMMA);
            if (t_10_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_10_0"] = t_10_0;
            ret->astMap["t_10_1"] = t_10_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_11_0 = match(PT_KW_OPERATOR);
            if (t_11_0->size()==0) {
                break;
            }

            CppAstPtr t_11_1 = match(PT_OP_DEC);
            if (t_11_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_11_0"] = t_11_0;
            ret->astMap["t_11_1"] = t_11_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_12_0 = match(PT_KW_OPERATOR);
            if (t_12_0->size()==0) {
                break;
            }

            CppAstPtr t_12_1 = match(PT_OP_INC);
            if (t_12_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_12_0"] = t_12_0;
            ret->astMap["t_12_1"] = t_12_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_13_0 = match(PT_KW_OPERATOR);
            if (t_13_0->size()==0) {
                break;
            }

            CppAstPtr t_13_1 = match(PT_OP_LOR);
            if (t_13_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_13_0"] = t_13_0;
            ret->astMap["t_13_1"] = t_13_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_14_0 = match(PT_KW_OPERATOR);
            if (t_14_0->size()==0) {
                break;
            }

            CppAstPtr t_14_1 = match(PT_OP_LE);
            if (t_14_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_14_0"] = t_14_0;
            ret->astMap["t_14_1"] = t_14_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_15_0 = match(PT_KW_OPERATOR);
            if (t_15_0->size()==0) {
                break;
            }

            CppAstPtr t_15_1 = match(PT_OP_GE);
            if (t_15_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_15_0"] = t_15_0;
            ret->astMap["t_15_1"] = t_15_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_16_0 = match(PT_KW_OPERATOR);
            if (t_16_0->size()==0) {
                break;
            }

            CppAstPtr t_16_1 = match(PT_OP_GT);
            if (t_16_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_16_0"] = t_16_0;
            ret->astMap["t_16_1"] = t_16_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_17_0 = match(PT_KW_OPERATOR);
            if (t_17_0->size()==0) {
                break;
            }

            CppAstPtr t_17_1 = match(PT_OP_NE);
            if (t_17_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_17_0"] = t_17_0;
            ret->astMap["t_17_1"] = t_17_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_18_0 = match(PT_KW_OPERATOR);
            if (t_18_0->size()==0) {
                break;
            }

            CppAstPtr t_18_1 = match(PT_OP_EQ);
            if (t_18_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_18_0"] = t_18_0;
            ret->astMap["t_18_1"] = t_18_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_19_0 = match(PT_KW_OPERATOR);
            if (t_19_0->size()==0) {
                break;
            }

            CppAstPtr t_19_1 = match(PT_OP_LSHIFTASS);
            if (t_19_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_19_0"] = t_19_0;
            ret->astMap["t_19_1"] = t_19_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_20_0 = match(PT_KW_OPERATOR);
            if (t_20_0->size()==0) {
                break;
            }

            CppAstPtr t_20_1 = match(PT_OP_RSHIFTASS);
            if (t_20_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_20_0"] = t_20_0;
            ret->astMap["t_20_1"] = t_20_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_21_0 = match(PT_KW_OPERATOR);
            if (t_21_0->size()==0) {
                break;
            }

            CppAstPtr t_21_1 = match(PT_OP_LAND);
            if (t_21_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_21_0"] = t_21_0;
            ret->astMap["t_21_1"] = t_21_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_22_0 = match(PT_KW_OPERATOR);
            if (t_22_0->size()==0) {
                break;
            }

            CppAstPtr t_22_1 = match(PT_OP_LSHIFT);
            if (t_22_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_22_0"] = t_22_0;
            ret->astMap["t_22_1"] = t_22_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_23_0 = match(PT_KW_OPERATOR);
            if (t_23_0->size()==0) {
                break;
            }

            CppAstPtr t_23_1 = match(PT_OP_BORASS);
            if (t_23_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_23_0"] = t_23_0;
            ret->astMap["t_23_1"] = t_23_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_24_0 = match(PT_KW_OPERATOR);
            if (t_24_0->size()==0) {
                break;
            }

            CppAstPtr t_24_1 = match(PT_OP_BANDASS);
            if (t_24_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_24_0"] = t_24_0;
            ret->astMap["t_24_1"] = t_24_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_25_0 = match(PT_KW_OPERATOR);
            if (t_25_0->size()==0) {
                break;
            }

            CppAstPtr t_25_1 = match(PT_OP_XORASS);
            if (t_25_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_25_0"] = t_25_0;
            ret->astMap["t_25_1"] = t_25_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_26_0 = match(PT_KW_OPERATOR);
            if (t_26_0->size()==0) {
                break;
            }

            CppAstPtr t_26_1 = match(PT_OP_MODASS);
            if (t_26_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_26_0"] = t_26_0;
            ret->astMap["t_26_1"] = t_26_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_27_0 = match(PT_KW_OPERATOR);
            if (t_27_0->size()==0) {
                break;
            }

            CppAstPtr t_27_1 = match(PT_OP_DIVASS);
            if (t_27_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_27_0"] = t_27_0;
            ret->astMap["t_27_1"] = t_27_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_28_0 = match(PT_KW_OPERATOR);
            if (t_28_0->size()==0) {
                break;
            }

            CppAstPtr t_28_1 = match(PT_OP_STARASS);
            if (t_28_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_28_0"] = t_28_0;
            ret->astMap["t_28_1"] = t_28_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_29_0 = match(PT_KW_OPERATOR);
            if (t_29_0->size()==0) {
                break;
            }

            CppAstPtr t_29_1 = match(PT_OP_MOD);
            if (t_29_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_29_0"] = t_29_0;
            ret->astMap["t_29_1"] = t_29_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_30_0 = match(PT_KW_OPERATOR);
            if (t_30_0->size()==0) {
                break;
            }

            CppAstPtr t_30_1 = match(PT_OP_PLUSASS);
            if (t_30_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_30_0"] = t_30_0;
            ret->astMap["t_30_1"] = t_30_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_31_0 = match(PT_KW_OPERATOR);
            if (t_31_0->size()==0) {
                break;
            }

            CppAstPtr t_31_1 = match(PT_OP_MINUSASS);
            if (t_31_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_31_0"] = t_31_0;
            ret->astMap["t_31_1"] = t_31_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_32_0 = match(PT_KW_OPERATOR);
            if (t_32_0->size()==0) {
                break;
            }

            CppAstPtr t_32_1 = match(PT_OP_PLUS);
            if (t_32_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_32_0"] = t_32_0;
            ret->astMap["t_32_1"] = t_32_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_33_0 = match(PT_KW_OPERATOR);
            if (t_33_0->size()==0) {
                break;
            }

            CppAstPtr t_33_1 = match(PT_OP_ASS);
            if (t_33_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_33_0"] = t_33_0;
            ret->astMap["t_33_1"] = t_33_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_34_0 = match(PT_KW_OPERATOR);
            if (t_34_0->size()==0) {
                break;
            }

            CppAstPtr t_34_1 = match(PT_OP_LNOT);
            if (t_34_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_34_0"] = t_34_0;
            ret->astMap["t_34_1"] = t_34_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_35_0 = match(PT_KW_OPERATOR);
            if (t_35_0->size()==0) {
                break;
            }

            CppAstPtr t_35_1 = match(PT_OP_COMPL);
            if (t_35_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_35_0"] = t_35_0;
            ret->astMap["t_35_1"] = t_35_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_36_0 = match(PT_KW_OPERATOR);
            if (t_36_0->size()==0) {
                break;
            }

            CppAstPtr t_36_1 = match(PT_OP_BOR);
            if (t_36_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_36_0"] = t_36_0;
            ret->astMap["t_36_1"] = t_36_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_37_0 = match(PT_KW_OPERATOR);
            if (t_37_0->size()==0) {
                break;
            }

            CppAstPtr t_37_1 = match(PT_OP_XOR);
            if (t_37_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_37_0"] = t_37_0;
            ret->astMap["t_37_1"] = t_37_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_38_0 = match(PT_KW_OPERATOR);
            if (t_38_0->size()==0) {
                break;
            }

            CppAstPtr t_38_1 = match(PT_OP_AMP);
            if (t_38_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_38_0"] = t_38_0;
            ret->astMap["t_38_1"] = t_38_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_39_0 = match(PT_KW_OPERATOR);
            if (t_39_0->size()==0) {
                break;
            }

            CppAstPtr t_39_1 = match(PT_KW_DELETE);
            if (t_39_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_39_0"] = t_39_0;
            ret->astMap["t_39_1"] = t_39_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_40_0 = match(PT_KW_OPERATOR);
            if (t_40_0->size()==0) {
                break;
            }

            CppAstPtr t_40_1 = match(PT_OP_MINUS);
            if (t_40_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_40_0"] = t_40_0;
            ret->astMap["t_40_1"] = t_40_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_41_0 = match(PT_KW_OPERATOR);
            if (t_41_0->size()==0) {
                break;
            }

            CppAstPtr t_41_1 = match(PT_OP_STAR);
            if (t_41_1->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_41_0"] = t_41_0;
            ret->astMap["t_41_1"] = t_41_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__literal_operator_id ()
    {
        if ( !is_first_literal_operator_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "literal-operator-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_OPERATOR);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_ST_EMPTYSTR);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_TT_IDENTIFIER);
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__template_declaration ()
    {
        if ( !is_first_template_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "template-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_TEMPLATE);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_ST_LT);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__template_parameter_list();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_ST_GT);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = parse__declaration();
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__template_parameter_list ()
    {
        if ( !is_first_template_parameter_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "template-parameter-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__template_parameter();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__template_parameter();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__template_parameter ()
    {
        if ( !is_first_template_parameter(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "template-parameter" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__parameter_declaration();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__type_parameter();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__type_parameter ()
    {
        if ( !is_first_type_parameter(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "type-parameter" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_TEMPLATE);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_ST_LT);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__template_parameter_list();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_ST_GT);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = match(PT_KW_CLASS);
            if (t_0_4->size()==0) {
                break;
            }

            CppAstPtr t_0_5 = match(PT_TT_IDENTIFIER);

            CppAstPtr t_0_6 = match(PT_OP_ASS);
            if (t_0_6->size()==0) {
                break;
            }

            CppAstPtr t_0_7 = parse__id_expression();
            if (t_0_7->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            ret->astMap["t_0_5"] = t_0_5;
            ret->astMap["t_0_6"] = t_0_6;
            ret->astMap["t_0_7"] = t_0_7;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_TEMPLATE);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_ST_LT);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__template_parameter_list();
            if (t_1_2->size()==0) {
                break;
            }

            CppAstPtr t_1_3 = match(PT_ST_GT);
            if (t_1_3->size()==0) {
                break;
            }

            CppAstPtr t_1_4 = match(PT_KW_CLASS);
            if (t_1_4->size()==0) {
                break;
            }

            CppAstPtr t_1_5 = match(PT_OP_DOTS);

            CppAstPtr t_1_6 = match(PT_TT_IDENTIFIER);

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            ret->astMap["t_1_4"] = t_1_4;
            ret->astMap["t_1_5"] = t_1_5;
            ret->astMap["t_1_6"] = t_1_6;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_KW_TYPENAME);
            if (t_2_0->size()==0) {
                break;
            }

            CppAstPtr t_2_1 = match(PT_TT_IDENTIFIER);

            CppAstPtr t_2_2 = match(PT_OP_ASS);
            if (t_2_2->size()==0) {
                break;
            }

            CppAstPtr t_2_3 = parse__type_id();
            if (t_2_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            ret->astMap["t_2_1"] = t_2_1;
            ret->astMap["t_2_2"] = t_2_2;
            ret->astMap["t_2_3"] = t_2_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_3_0 = match(PT_KW_CLASS);
            if (t_3_0->size()==0) {
                break;
            }

            CppAstPtr t_3_1 = match(PT_TT_IDENTIFIER);

            CppAstPtr t_3_2 = match(PT_OP_ASS);
            if (t_3_2->size()==0) {
                break;
            }

            CppAstPtr t_3_3 = parse__type_id();
            if (t_3_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_3_0"] = t_3_0;
            ret->astMap["t_3_1"] = t_3_1;
            ret->astMap["t_3_2"] = t_3_2;
            ret->astMap["t_3_3"] = t_3_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_4_0 = match(PT_KW_TYPENAME);
            if (t_4_0->size()==0) {
                break;
            }

            CppAstPtr t_4_1 = match(PT_OP_DOTS);

            CppAstPtr t_4_2 = match(PT_TT_IDENTIFIER);

            CompAst* ret = new CompAst();
            ret->astMap["t_4_0"] = t_4_0;
            ret->astMap["t_4_1"] = t_4_1;
            ret->astMap["t_4_2"] = t_4_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_5_0 = match(PT_KW_CLASS);
            if (t_5_0->size()==0) {
                break;
            }

            CppAstPtr t_5_1 = match(PT_OP_DOTS);

            CppAstPtr t_5_2 = match(PT_TT_IDENTIFIER);

            CompAst* ret = new CompAst();
            ret->astMap["t_5_0"] = t_5_0;
            ret->astMap["t_5_1"] = t_5_1;
            ret->astMap["t_5_2"] = t_5_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__template_id ()
    {
        if ( !is_first_template_id(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "template-id" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__literal_operator_id();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_ST_LT);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__template_argument_list();

            CppAstPtr t_0_3 = match(PT_ST_GT);
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__operator_function_id();
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = match(PT_ST_LT);
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = parse__template_argument_list();

            CppAstPtr t_1_3 = match(PT_ST_GT);
            if (t_1_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__simple_template_id();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__template_argument_list ()
    {
        if ( !is_first_template_argument_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "template-argument-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__template_argument_dots();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__template_argument_dots();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__template_argument_dots ()
    {
        if ( !is_first_template_argument_dots(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "template-argument-dots" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__template_argument();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_DOTS);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__template_argument ()
    {
        if ( !is_first_template_argument(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "template-argument" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__id_expression();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__type_id();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = parse__constant_expression();
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__typename_specifier ()
    {
        if ( !is_first_typename_specifier(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "typename-specifier" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_TYPENAME);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__nested_name_specifier();
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_KW_TEMPLATE);

            CppAstPtr t_0_3 = parse__simple_template_id();
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = match(PT_KW_TYPENAME);
            if (t_1_0->size()==0) {
                break;
            }

            CppAstPtr t_1_1 = parse__nested_name_specifier();
            if (t_1_1->size()==0) {
                break;
            }

            CppAstPtr t_1_2 = match(PT_TT_IDENTIFIER);
            if (t_1_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__explicit_instantiation ()
    {
        if ( !is_first_explicit_instantiation(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "explicit-instantiation" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_EXTERN);

            CppAstPtr t_0_1 = match(PT_KW_TEMPLATE);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__declaration();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__explicit_specialization ()
    {
        if ( !is_first_explicit_specialization(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "explicit-specialization" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_TEMPLATE);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_ST_LT);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = match(PT_ST_GT);
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = parse__declaration();
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__try_block ()
    {
        if ( !is_first_try_block(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "try-block" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_TRY);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__compound_statement();
            if (t_0_1->size()==0) {
                break;
            }

            CompAst* t_0_2_ptr = new CompAst();
            int idx_t_0_2 = 0;
            CppAstPtr firstPtr = parse__handler();
            if (firstPtr->size() == 0) {
                break;
            }
            t_0_2_ptr->astMap[to_string(idx_t_0_2)] = firstPtr;
            idx_t_0_2++;
            while (true) {
                CppAstPtr iterPtr = parse__handler();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_2_ptr->astMap[to_string(idx_t_0_2)] = iterPtr;
                idx_t_0_2++;
                continue;
            }
            CppAstPtr t_0_2(t_0_2_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__function_try_block ()
    {
        if ( !is_first_function_try_block(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "function-try-block" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_TRY);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__ctor_initializer();

            CppAstPtr t_0_2 = parse__compound_statement();
            if (t_0_2->size()==0) {
                break;
            }

            CompAst* t_0_3_ptr = new CompAst();
            int idx_t_0_3 = 0;
            CppAstPtr firstPtr = parse__handler();
            if (firstPtr->size() == 0) {
                break;
            }
            t_0_3_ptr->astMap[to_string(idx_t_0_3)] = firstPtr;
            idx_t_0_3++;
            while (true) {
                CppAstPtr iterPtr = parse__handler();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_3_ptr->astMap[to_string(idx_t_0_3)] = iterPtr;
                idx_t_0_3++;
                continue;
            }
            CppAstPtr t_0_3(t_0_3_ptr);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__handler ()
    {
        if ( !is_first_handler(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "handler" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_CATCH);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LPAREN);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__exception_declaration();
            if (t_0_2->size()==0) {
                break;
            }

            CppAstPtr t_0_3 = match(PT_OP_RPAREN);
            if (t_0_3->size()==0) {
                break;
            }

            CppAstPtr t_0_4 = parse__compound_statement();
            if (t_0_4->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            ret->astMap["t_0_4"] = t_0_4;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__exception_declaration ()
    {
        if ( !is_first_exception_declaration(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "exception-declaration" );
    
        PtIt bakPos = _ptIt;
        do {
            CompAst* t_0_0_ptr = new CompAst();
            int idx_t_0_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_0_ptr->astMap[to_string(idx_t_0_0)] = iterPtr;
                idx_t_0_0++;
                continue;
            }
            CppAstPtr t_0_0(t_0_0_ptr);

            CompAst* t_0_1_ptr = new CompAst();
            int idx_t_0_1 = 0;
            CppAstPtr firstPtr = parse__type_specifier();
            if (firstPtr->size() == 0) {
                break;
            }
            t_0_1_ptr->astMap[to_string(idx_t_0_1)] = firstPtr;
            idx_t_0_1++;
            while (true) {
                CppAstPtr iterPtr = parse__type_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_1_ptr->astMap[to_string(idx_t_0_1)] = iterPtr;
                idx_t_0_1++;
                continue;
            }
            CppAstPtr t_0_1(t_0_1_ptr);

            CompAst* t_0_2_ptr = new CompAst();
            int idx_t_0_2 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_0_2_ptr->astMap[to_string(idx_t_0_2)] = iterPtr;
                idx_t_0_2++;
                continue;
            }
            CppAstPtr t_0_2(t_0_2_ptr);

            CppAstPtr t_0_3 = parse__declarator();
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CompAst* t_1_0_ptr = new CompAst();
            int idx_t_1_0 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_0_ptr->astMap[to_string(idx_t_1_0)] = iterPtr;
                idx_t_1_0++;
                continue;
            }
            CppAstPtr t_1_0(t_1_0_ptr);

            CompAst* t_1_1_ptr = new CompAst();
            int idx_t_1_1 = 0;
            CppAstPtr firstPtr = parse__type_specifier();
            if (firstPtr->size() == 0) {
                break;
            }
            t_1_1_ptr->astMap[to_string(idx_t_1_1)] = firstPtr;
            idx_t_1_1++;
            while (true) {
                CppAstPtr iterPtr = parse__type_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_1_ptr->astMap[to_string(idx_t_1_1)] = iterPtr;
                idx_t_1_1++;
                continue;
            }
            CppAstPtr t_1_1(t_1_1_ptr);

            CompAst* t_1_2_ptr = new CompAst();
            int idx_t_1_2 = 0;
            while (true) {
                CppAstPtr iterPtr = parse__attribute_specifier();
                if (iterPtr->size() == 0) {
                     break;
                }
                t_1_2_ptr->astMap[to_string(idx_t_1_2)] = iterPtr;
                idx_t_1_2++;
                continue;
            }
            CppAstPtr t_1_2(t_1_2_ptr);

            CppAstPtr t_1_3 = parse__abstract_declarator();

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            ret->astMap["t_1_1"] = t_1_1;
            ret->astMap["t_1_2"] = t_1_2;
            ret->astMap["t_1_3"] = t_1_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_2_0 = match(PT_OP_DOTS);
            if (t_2_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_2_0"] = t_2_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__throw_expression ()
    {
        if ( !is_first_throw_expression(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "throw-expression" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_THROW);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = parse__assignment_expression();

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__exception_specification ()
    {
        if ( !is_first_exception_specification(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "exception-specification" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__noexcept_specification();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        do {
            CppAstPtr t_1_0 = parse__dynamic_exception_specification();
            if (t_1_0->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_1_0"] = t_1_0;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__dynamic_exception_specification ()
    {
        if ( !is_first_dynamic_exception_specification(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "dynamic-exception-specification" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_THROW);
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_LPAREN);
            if (t_0_1->size()==0) {
                break;
            }

            CppAstPtr t_0_2 = parse__type_id_list();

            CppAstPtr t_0_3 = match(PT_OP_RPAREN);
            if (t_0_3->size()==0) {
                break;
            }

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            ret->astMap["t_0_2"] = t_0_2;
            ret->astMap["t_0_3"] = t_0_3;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__type_id_list ()
    {
        if ( !is_first_type_id_list(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "type-id-list" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__type_id_dots();
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            while (true) {
                CppAstPtr t_0_10 = match(PT_OP_COMMA);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__type_id_dots();
                if (t_0_11->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
            }
            cout << "BACKTO :" <<  _ptIt->source << endl;
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__type_id_dots ()
    {
        if ( !is_first_type_id_dots(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "type-id-dots" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = parse__type_id();
            if (t_0_0->size()==0) {
                break;
            }

            CppAstPtr t_0_1 = match(PT_OP_DOTS);

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


    CppAstPtr parse__noexcept_specification ()
    {
        if ( !is_first_noexcept_specification(_ptIt->type) ) {
            return CppAstPtr( new EmptyAst() );
        }
        Autocat ac( "noexcept-specification" );
    
        PtIt bakPos = _ptIt;
        do {
            CppAstPtr t_0_0 = match(PT_KW_NOEXCEPT);
            if (t_0_0->size()==0) {
                break;
            }

            CompAst* t_0_1_ptr = new CompAst();
            do {
                CppAstPtr t_0_10 = match(PT_OP_LPAREN);
                if (t_0_10->size()==0) {
                    break;
                }
                CppAstPtr t_0_11 = parse__constant_expression();
                if (t_0_11->size()==0) {
                    break;
                }
                CppAstPtr t_0_12 = match(PT_OP_RPAREN);
                if (t_0_12->size()==0) {
                    break;
                }
                t_0_1_ptr->astMap["t_0_10"] = t_0_10;
                t_0_1_ptr->astMap["t_0_11"] = t_0_11;
                t_0_1_ptr->astMap["t_0_12"] = t_0_12;
            }
            while (false);
            CppAstPtr t_0_1( t_0_1_ptr );

            CompAst* ret = new CompAst();
            ret->astMap["t_0_0"] = t_0_0;
            ret->astMap["t_0_1"] = t_0_1;
            return CppAstPtr( ret );
        }
        while (false);
        _ptIt = bakPos;
        cout << "BACKTO :" <<  _ptIt->source << endl;
        return CppAstPtr( new EmptyAst() );
    }


