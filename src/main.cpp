#include <iostream>
#include "schemaql_lexer.hpp"

int main(int argc, char* argv[]) {
    Designar::Lexer lexer = make_schemaql_lexer();
    
    std::string test_input = 
        "model author \n"
        "  name: text, required \n"
        "  age: int \n"
        "end_model";
    
    try {
        Designar::DynArray<Designar::Token> tokens = tokenize_schemaql(lexer, test_input);
        for (Designar::nat_t i = 0; i < tokens.size(); ++i) {
            std::cout << "[" << tokens[i].name << "] " << tokens[i].lexeme << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    
    return 0;
}