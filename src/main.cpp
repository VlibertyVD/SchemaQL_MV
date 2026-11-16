#include <iostream>
#include <fstream>
#include <sstream>
#include "schemaql_lexer.hpp"
#include "schemaql_parser.hpp"

// TODO: Include semantic and codegen headers here when implemented

int main(int argc, char* argv[]) {
    
    // Default test file if no argument is provided
    std::string file_path = "tests/test.schemaql";
    if (argc > 1) {
        file_path = argv[1];
    }

    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "[ERROR] Could not open file: " << file_path << "\n";
        return 1;
    }

    // Read the entire file into a string
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string source_code = buffer.str();

    Designar::Lexer lexer = make_schemaql_lexer();
    
    try {
        std::cout << "--- SchemaQL Compiler ---\n";
        std::cout << "Reading source file: " << file_path << "\n";
        
        // 1. Lexical Analysis
        Designar::DynArray<Designar::Token> tokens = tokenize_schemaql(lexer, source_code);
        
        // 2. Syntax Analysis (Parser)
        Designar::ParseTreeNode* ast = parse_schemaql(tokens);
        
        if (ast != nullptr) {
            std::cout << "[OK] Abstract Syntax Tree (AST) built correctly.\n";
            
            // TODO: Traverse and print the 'ast' structure to the terminal for debugging
            
            // TODO: Execute Semantic Analysis (Phase 3)
            
            // TODO: Execute Code Generation (Phase 4)

        } else {
            std::cerr << "[ERROR] Parser failed to build the AST.\n";
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Compiler Error: " << e.what() << "\n";
    }
    
    return 0;
}
