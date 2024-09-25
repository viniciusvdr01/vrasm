#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/structs.h"
#include "../inc/args.h"

extensions_t io_exts;


/* TODO : implement compiler optons bases on io_exts
for now , only manual compilation to test the microcontroller is fine*/ 

int main(int argc, char **argv)
{

	parse_cmdargs(argc,argv,&io_exts);

	free(io_exts.out_ext); // free this somewhere else after using :)
	free(io_exts.in_ext);


return 0;
}



