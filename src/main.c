#include <stdio.h>
#include "parser.h"

int main(int argc, char * argv[]){
	printf("Path : %s", argv[1]);

	FILE * zibra = fopen(argv[1],"r");

	file_parser(zibra);

	return 0;
}