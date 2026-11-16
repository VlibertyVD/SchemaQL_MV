# SchemaQL Compiler

## Project Objective
SchemaQL is a custom domain-specific language (DSL) designed to simplify relational database modeling. This compiler reads SchemaQL source code and translates it directly into PostgreSQL Data Definition Language (DDL) scripts, handling tables and relationships.

## Delivery 1: Lexical Analyzer (Lexer)
The Lexer represents the first phase of the compilation process. Its primary function is to read the raw source code character by character, group them into meaningful lexemes, and convert them into a sequence of valid tokens. 

**Implementation Details:**
- **Library Integration:** The implementation relies on the `Designar::Lexer` tool from the local DeSiGNAR library, instantiating the lexer and registering specific regular expressions for each language construct.
- **Token Priority:** Tokens are registered in a strict priority order. Keywords (`model`, `end_model`) and native data types (`int`, `text`, `bool`, `float`, `date`) are added first to prevent reserved words from being misclassified as general identifiers.

- **Token Filtering and Stream Sanitization:** The lexer registers patterns for whitespaces, carriage returns, and line comments (`//`). After the engine generates the initial token array, a filtering loop automatically discards these non-essential tokens. This ensures the subsequent parser receives a clean, strictly syntactic token stream (`Designar::DynArray<Designar::Token>`).

### Lexer Tokens Supported
| Token Name | Description | Example / Regex Match |
|---|---|---|
| `KW_MODEL` | Model definition keywords | `model`, `end_model` |
| `DATA_TYPE` | Native data types | `int`, `text`, `bool`, `float`, `date` |
| `REL_TYPE` | Relational constraints | `one2many`, `many2one`, `many2many` |
| `MODIFIER` | Field modifiers | `required`, `unique`, `default`, `cascade` |
| `BOOL_LIT` | Boolean literals | `true`, `false` |
| `ID` | Identifiers (names) | `author`, `user_id`, `age` |
| `NUM_FLOAT` | Floating-point numbers | `3.14`, `0.99` |
| `NUM_INT` | Integer numbers | `42`, `0` |
| `STRING` | Text strings | `"Hello World"` |
| `OP_COLON` | Colon symbol | `:` |
| `COMMA` | Comma symbol | `,` |
| `LPAREN` / `RPAREN` | Parentheses | `(`, `)` |

## Architecture
The compiler architecture is structured in four core phases:
1. Lexer: Tokenizes the source code stream.
2. Parser: Analyzes the token stream and constructs the Abstract Syntax Tree (AST).
3. Semantic Analyzer: Traverses the AST to validate logical constraints, referential integrity, and data types.
4. Code Generator: Translates the validated AST structure into standard PostgreSQL DDL.
```
## Project Structure
📁 SchemaQL_MV 
 ├── 📁 include          # C++ Header files (.hpp)
 ├── 📁 src              # Source code implementations (.cpp)
 │    ├── 📁 lexer       # Lexical analyzer module
 │    ├── 📁 parser      # Parser and grammar module
 │    ├── 📁 semantic    # Semantic analyzer module
 │    ├── 📁 codegen     # Code generator module
 │    └── main.cpp       # Main compiler entry point
 ├── 📁 tests            # Directory for large-scale test files
 │    └── test.schemaql  # Main evaluation file
 ├── CMakeLists.txt /    # Build configuration
 └── README.md           # Project documentation
```
## Dependencies: DeSiGNAR Library
This project strictly requires the DeSiGNAR library provided by CeSiMo (ULA). 
To ensure CMake finds the library, the DeSiGNAR folder must be located in the same parent directory as this repository and must be compiled beforehand.
```
Directory structure expected:
📁 parent_folder 
 ├── 📁 DeSiGNAR (compiled) 
 └── 📁 SchemaQL_MV 
```
## How to Build and Run
1. Configure the project:
   cmake -S . -B build

2. Build the compiler:
   cmake --build build

3. Run the program (it defaults to reading tests/test.schemaql):
   ./build/SchemaQL

4. Run the program with a custom file:
   ./build/SchemaQL path/to/your/file.schemaql
