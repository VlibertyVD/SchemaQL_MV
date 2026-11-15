#include "schemaql_parser.hpp"

using namespace Designar;

Grammar make_schemaql_grammar() {
    Grammar g;
    
    g.set_start_symbol("Program");
    
    // LL(1) Grammar rules for SchemaQL
    // Empty brackets {} represent an epsilon (empty) production
    
    // Root
    g.add_production("Program", {"ModelList"});
    
    //Model List (Recursividad por la derecha para LL1)
    g.add_production("ModelList", {"Model", "ModelList"});
    g.add_production("ModelList", {}); 
    
    // Model Structure
    g.add_production("Model", {"KW_MODEL", "ID", "FieldList", "KW_MODEL"});
    
    //Field List
    g.add_production("FieldList", {"Field", "FieldList"});
    g.add_production("FieldList", {});
    
    // Field Definition
    g.add_production("Field", {"ID", "OP_COLON", "FieldType", "Modifiers"});
    
    //Field Types
    g.add_production("FieldType", {"DATA_TYPE"});
    g.add_production("FieldType", {"REL_TYPE", "ID"}); // ej. many2one author
    
    // Modifiers
    g.add_production("Modifiers", {"COMMA", "MODIFIER", "Modifiers"});
    g.add_production("Modifiers", {});
    
    return g;
}
ParseTreeNode* parse_schemaql(const DynArray<Token>& tokens) {
    Grammar grammar = make_schemaql_grammar();
    LLParser parser(grammar);
    
    // Build and return the AST pointer
    return parser.parse(tokens);
}