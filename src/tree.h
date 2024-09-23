// Abstract Syntax Tree 
enum AST{
  AST_ADD, AST_SUB, AST_MULT, AST_DIV, AST_INTLIT
} ;

typedef struct ASTNode{
  enum AST type;
  int intvalue;
  struct ASTNode *left; // to binary operations
  struct ASTNode *right; // to binary operations
} ASTNode;

#endif