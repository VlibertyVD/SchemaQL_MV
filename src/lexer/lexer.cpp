#include "schemaql_lexer.hpp"

using namespace Designar;

Lexer make_schemaql_lexer() {

    Lexer lexer;
    

    // Keywords must be added first for higher priority
    lexer.add_token("KW_MODEL", "(model|end_model)");
    lexer.add_token("DATA_TYPE", "(int|text|bool|float|date)");
    lexer.add_token("REL_TYPE", "(one2many|many2one|many2many)");
    lexer.add_token("MODIFIER", "(required|unique|default|cascade)");
    lexer.add_token("BOOL_LIT", "(true|false)");
    

    // Explicit OR regex 
    std::string letters = "(a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|_)";
    std::string alnum = "(a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|0|1|2|3|4|5|6|7|8|9|_)";
    lexer.add_token("ID", letters + alnum + "*");
    
    // Numbers
    std::string digits = "(0|1|2|3|4|5|6|7|8|9)";
    lexer.add_token("NUM_FLOAT", digits + "+\\." + digits + "+");
    lexer.add_token("NUM_INT", digits + "+");
    
    // Strings and comments
    std::string common_chars = "(a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|0|1|2|3|4|5|6|7|8|9|_| |:|,|\\(|\\)|\\.|\\-)";
    lexer.add_token("STRING", "\\\"" + common_chars + "*\\\"");
    lexer.add_token("COMMENT_LINE", "//" + common_chars + "*");
    
    
    // Symbols
    lexer.add_token("OP_COLON", ":");
    lexer.add_token("COMMA", ",");
    lexer.add_token("LPAREN", "\\(");
    lexer.add_token("RPAREN", "\\)");
    
    // Whitespaces
    lexer.add_token("WS", "( |\t|\n|\r)+");
    
    return lexer;
}

DynArray<Token> tokenize_schemaql(const Lexer& lexer, const std::string& input) {
    DynArray<Token> all = lexer.tokenize(input);
    DynArray<Token> tokens;

    for (nat_t i = 0; i < all.size(); ++i) {
        if (all[i].name != "WS" && all[i].name != "COMMENT_LINE") {
            tokens.append(all[i]);
        }
    }
    return tokens;
}