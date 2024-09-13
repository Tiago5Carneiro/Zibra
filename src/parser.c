#include <stdio.h>
#include "parser.h"
#include "token.h"

extern int Line;
extern int Putback;
extern FILE * zibra;


// Parses the file stream
int parser(struct token * TOKEN){

	int c = skip();

	switch(c){
		case '+':
			t->token = T_PlUS;
			break;
		case '-':
			t->token = T_MINUS;
			break;
		case '*':
			t->token = T_STAR;
			break;
		case '/':
			t->token = T_SLASH;
			break;
		default:
			break;
	}

	return 0;
}

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

	return c;;
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






