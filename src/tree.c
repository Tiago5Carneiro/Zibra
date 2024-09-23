#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Create as AST node
ASTNode* createASTNode(enum AST type, int intvalue, ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode* )malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Unable to allocate memory for AST node\n");
        exit(1);
    }
    node->type = type;
    node->intvalue = intvalue;
    node->left = left;
    node->right = right;
    return node;
}