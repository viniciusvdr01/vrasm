#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/structs.h"
#include "../inc/args.h"


int main(int argc, char **argv)
{

	parse_cmdargs(argc,argv);

	free(io_exts.out_ext); // free this somewhere else after using :)
	free(io_exts.in_ext);


return 0;
}
