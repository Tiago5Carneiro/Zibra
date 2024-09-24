#ifndef TREE_H
#define TREE_H

// Enum for different types of AST nodes
typedef enum {
    AST_ADD,    // Addition operation
    AST_SUB,    // Subtraction operation
    AST_MULT,   // Multiplication operation
    AST_DIV,    // Division operation
    AST_INTLIT  // Integer literal
} ASTType;

// Struct for AST node
typedef struct ASTNode {
    ASTType type;        // Type of the node (operation or literal)
    int intvalue;        // Value for integer literals
    struct ASTNode* left;  // Pointer to the left child (used for binary operations)
    struct ASTNode* right; // Pointer to the right child (used for binary operations)
} ASTNode;

#endif // TREE_H
