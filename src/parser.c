#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "token.h"

extern int Line;
extern int Putback;
extern FILE * zibra;


// Gets the next character, unless it is needed to putback a character if we go too far into the line
static int next(){
	int c; 

	// If there was a character we need to putback we do it here
	if(Putback){
		c = Putback;
		Putback = 0;
		return c;
	}

	c = fgetc(zibra);
	
	if ('\n'==c)
		Line++;

	return c;
}


// Add the character to the putback variable 
static void putback(int c){
	Putback=c;
}

// Skips unwanted characters, utililizing a switch case to do as little comparissons as possible
static int skip() {

  int c = next();

  int flag = 1;

  // Stay in this while until a non-skippable character shows up
  while (flag) {
    switch (c) {
      // Skippable characters
      case ' ':
      case '\n':
      case '\t':
      case '\r':
      case '\f':
        c = next();
        break;
       // Non-skippable character found
      default:
        flag = 0;
        break;
    }
  }

  return c;
}

// After finding a number, this function adds the rest of the digits of said number
static int numberScanner(int c){

	int value = 0;

	while (isdigit(c)){
		value = value * 10 + (c-'0');
		c = next();
	}

	// If it leaves the while loop it means the character found is not a digit so we have to put it back
	putback(c);

	return value;

}

// Creates the next token possible
static int tokenizer(struct token * t){

	int c = skip();
	printf("\nChar : %c", c);
	switch(c){
		case '+':
			t->token = TK_PLUS;
			break;
		case '-':
			t->token = TK_MINUS;
			break;
		case '*':
			t->token = TK_STAR;
			break;
		case '/':
			t->token = TK_SLASH;
			break;
		default:

			//check if the current character is a digit
			if(isdigit(c)){
				t->intvalue = numberScanner(c);
				t->token = TK_INTLIT;
				break;
			}
			// If it gets here it wasn't a valide character 
			exit(1);
	}

	return 0;
}

// Function that creates and print's all the tokens recognized in the file
int parser(){

	struct token t;

	const char * tokenTypes[] = {
  "TK_PLUS", "TK_MINUS", "TK_STAR", "TK_SLASH", "TK_INTLIT"
} ;

	while(!tokenizer(&t)){
		printf("\nToken : %s\n", tokenTypes[t.token]);
		if (t.token==TK_INTLIT){
			printf("Int value : %d\n", t.intvalue);
		}
	}

	return 0;
}
