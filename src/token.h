#include <stdbool.h>

// Tokens
enum TOKEN{
  TK_PLUS, TK_MINUS, TK_STAR, TK_SLASH, TK_INTLIT
} ;

struct token{
	int token;	
	int intvalue;
};