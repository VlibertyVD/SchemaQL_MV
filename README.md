# SchemaQL Compiler

## Objective
SchemaQL is a domain-specific language (DSL) compiler written in C++17. Its main goal is to simplify relational database modeling. It translates high-level entity definitions and relationships (such as `many2one` and `many2many`) into native PostgreSQL DDL (Data Definition Language) scripts.

## Architecture
The compiler is divided into four main modules:
1. **Lexer**: Tokenizes the source code.
2. **Parser**: Builds the Abstract Syntax Tree (AST) using the DeSiGNAR library.
3. **Semantic Analyzer**: Validates data types and referential integrity.
4. **Code Generator**: Translates the validated AST into PostgreSQL DDL.

## How to Build and Run
This project uses CMake and requires the DeSiGNAR library linked locally.

1. Configure the project (creates the build directory):
```bash
cmake -S . -B build
cmake --build build

