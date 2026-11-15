#ifndef SCHEMAQL_PARSER_HPP
#define SCHEMAQL_PARSER_HPP

#include <grammar.hpp>
#include <llparser.hpp>
#include <lexer.hpp> 

// Creates the LL(1) Grammar for SchemaQL
Designar::Grammar make_schemaql_grammar();


// Parses the token stream and builds the Abstract Syntax Tree
Designar::ParseTreeNode* parse_schemaql(const Designar::DynArray<Designar::Token>& tokens);

#endif 