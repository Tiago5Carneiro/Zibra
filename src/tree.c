#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Function to create an AST node
ASTNode* createASTNode(ASTType type, int intvalue, ASTNode* left, ASTNode* right) {
    // Allocate memory for the node
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));

    // Check if memory allocation failed
    if (!node) {
        fprintf(stderr, "Error: Unable to allocate memory for AST node\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the node fields
    node->type = type;
    node->intvalue = intvalue;
    node->left = left;
    node->right = right;

    return node;
}

ASTNode * createLeaf(ASTType type, int intvalue){
    return createASTNode(type,intvalue,NULL,NULL);
}

ASTNode * createUni(ASTType type,int intvalue, ASTNode * left){
    return createASTNode(type,intvalue,left,NULL);
}

ASTNode * createBi(ASTType type,int intvalue,ASTNode * left, ASTNode * right){
    return createASTNode(type,intvalue,left,right);
}