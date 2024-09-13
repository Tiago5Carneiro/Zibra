#include <stdio.h>
#include "parser.h"

int main(int argc, char * argv[]){
	printf("Path : %s", argv[1]);

	FILE * zibra = fopen(argv[1],"r");
	int Putback = 0;
	int Line = 0;
	parser(zibra);

	return 0;
}