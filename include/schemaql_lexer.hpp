#ifndef SCHEMAQL_LEXER_HPP
#define SCHEMAQL_LEXER_HPP

#include <lexer.hpp>
#include <string>

// Creates the Lexer configured for SchemaQL tokens.
Designar::Lexer make_schemaql_lexer();

// Tokenizes the input and filters out whitespaces and comments.
Designar::DynArray<Designar::Token> tokenize_schemaql(const Designar::Lexer& lexer, const std::string& input);

#endif