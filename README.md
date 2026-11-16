# SchemaQL Compiler

## Project Objective
SchemaQL is a custom domain-specific language (DSL) designed to simplify relational database modeling. This compiler reads SchemaQL source code and translates it directly into PostgreSQL Data Definition Language (DDL) scripts, handling tables and relationships.

## Delivery 1: Lexical Analyzer (Lexer)
The Lexer represents the first phase of the compilation process. Its primary function is to read the raw source code and convert it into a sequence of valid tokens.

**Implementation Details:**
* **Library:** The implementation relies on the Designar::Lexer tool from the local DeSiGNAR library.
* **Token Recognition:** The lexer successfully identifies the custom language grammar, including keywords (model, end_model), data types (int, text, bool, date), relational structures (one2many, many2one, many2many), and structural symbols (:, ,).
* **Regex Compatibility:** Due to limitations in the DeSiGNAR regex engine regarding standard character classes, the alphabet and digit structures were explicitly defined using logical OR sequences to accurately match identifiers and literals.
* **Stream Sanitization:** The Lexer automatically discards whitespace, carriage returns, and line comments, ensuring the parser receives a clean token stream.

## Architecture
The compiler architecture is structured in four core phases:
1. Lexer: Tokenizes the source code stream.
2. Parser: Analyzes the token stream and constructs the Abstract Syntax Tree (AST).
3. Semantic Analyzer: Traverses the AST to validate logical constraints, referential integrity, and data types.
4. Code Generator: Translates the validated AST structure into standard PostgreSQL DDL.

## Dependencies: DeSiGNAR Library
This project strictly requires the DeSiGNAR library provided by CeSiMo (ULA). 
To ensure CMake finds the library, the DeSiGNAR folder must be located in the same parent directory as this repository and must be compiled beforehand.

Directory structure expected:
📁 parent_folder
 ├── 📁 DeSiGNAR (compiled)
 └── 📁 SchemaQL_MV

## How to Build and Run
1. Configure the project:
   cmake -S . -B build

2. Build the compiler:
   cmake --build build

3. Run the program:
   ./build/SchemaQL
