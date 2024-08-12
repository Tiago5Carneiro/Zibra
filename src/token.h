#include <bool.h>
#include <string.h>

enum TokenType{
	string,
	return
}

struct Token{
	TokenType type;
	bool optional;
	string * value;
}