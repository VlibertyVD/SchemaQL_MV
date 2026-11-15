#include <iostream>
#include "schemaql_lexer.hpp"
#include "schemaql_parser.hpp"

int main(int argc, char* argv[]) {
    Designar::Lexer lexer = make_schemaql_lexer();
    
    std::string test_input = 
        "model author \n"
        "  name: text, required \n"
        "  age: int \n"
        "end_model";
    
    try {
        std::cout << "--- SchemaQL Lexer ---\n";
        Designar::DynArray<Designar::Token> tokens = tokenize_schemaql(lexer, test_input);
        for (Designar::nat_t i = 0; i < tokens.size(); ++i) {
            std::cout << "[" << tokens[i].name << "] " << tokens[i].lexeme << "\n";
        }
        
        std::cout << "\n--- SchemaQL Parser ---\n";
        Designar::ParseTreeNode* ast = parse_schemaql(tokens);
        
        if (ast != nullptr) {
            std::cout << "SUCCESS: Abstract Syntax Tree (AST) built correctly.\n";
        } else {
            std::cout << "ERROR: Parser failed to build the AST.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Compiler Error: " << e.what() << "\n";
    }
    
    return 0;
}