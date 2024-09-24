#include <stdio.h>
#include "parser.h"

FILE * zibra;
int Putback;
int Line;

// Tests if the parse functions are working
int testParse(int argc, char * argv[]){
	printf("Path : %s", argv[1]);

	zibra = fopen(argv[1],"r");
	Putback = 0;
	Line = 0;
	parser();

	return 0;
}

// Tests for the abstract syntax tree
int testTree(){
	
}

int main(int argc, char * argv[]){
	testParse(argc,argv);
}