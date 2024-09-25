#include "../inc/args.h"
#include "../inc/structs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char* helpstr = 
			"Usage :  vrasm [options] files\n"
			"Options : \n"
			"-i         Specifies path to input .asm file to be compiled or manualy compiled ASCII hexadecimals in .txt file.\n"
			"-o         Specifies path and extension [.bin,.coe,.mcs or .hex] of output compiled file.\n"
			"--help     Print this help message.\n"
			"--info     Print compiler useful informations.\n"
			"\n"
			"Examples of usage : \n"
			"\n"
			"vrasm -i main.asm -o out.coe\n"
			"vrasm -i code.asm -o out.hex\n"
			"vrasm -i opcodes.txt -o out.bin\n";

const char* infostr = 
			"vrasm - is an assembler that compiles .asm files for uRego 8-bit fpga-microcontroller into .bin , .coe, .mcs  or .hex files used as fpga's block ram memory initialiazion files from multiple manufactures.\n";

const char* argsErrorStr = 
			"VRASM : Fatal error : Illegal arguments, see --help.\n";

extensions_t io_exts;


int get_extensions(char* i_file_name,char* o_file_name, extensions_t* extensions)
{
	int ext_pos,in_exts_number = 2,out_exts_number = 4;
	register int i;
	
	char **possible_in_exts = (char **) malloc(in_exts_number*sizeof(char *));
	char **possible_out_exts = (char **) malloc(out_exts_number*sizeof(char*));
		
	if(possible_in_exts == NULL || possible_out_exts == NULL){printf("Memory allocation failure.\n");return 0;}
	
	possible_in_exts[0] = strdup(".txt");
	possible_in_exts[1] = strdup(".asm");

	possible_out_exts[0] = strdup(".coe");
	possible_out_exts[1] = strdup(".bin");
	possible_out_exts[2] = strdup(".hex");
	possible_out_exts[3] = strdup(".mcs");
	
	// Dont forger to free this after using.

        extensions->in_ext = (char*)malloc(5*sizeof(char));
	extensions->out_ext = (char*)malloc(5*sizeof(char));
	
	if(extensions->in_ext == NULL || extensions->out_ext == NULL){printf("Memory allocation failure.\n");return 0;}

	if(sort_extension(possible_in_exts,extensions->in_ext,i_file_name,in_exts_number))free(possible_in_exts);
	else{free(possible_in_exts);return 0;}

	if(sort_extension(possible_out_exts,extensions->out_ext,o_file_name,out_exts_number)){free(possible_out_exts); return 1;}
	else {free(possible_out_exts); return 0;}

}


int sort_extension(char** ext_vector,char* extension,char* file_name,int extensions_number)
{

// Problem :

	register int i,ext_pos=0;

	for (i =0 ; i <= strlen(file_name) ; i++)
	{
		if( file_name[i] == '.')
		{
			ext_pos = i;
		}
		else if(i == strlen(file_name) -1 )
		{
			else if ((i-ext_pos ) != 3) {printf("VRASM  :  Error : Invalid file extension format \n"); return 0;}
		}
		
	}

	for (i = 0; i <=3; i++) extension[i] = file_name[ext_pos+i];

	for (i =0 ; i< extensions_number; i++)
	{
		if ( !strcmp(ext_vector[i],extension) )
		{
			return 1;
		}
		else if (i == extensions_number-1) 
		{
			printf("VRASM  :  Error : Invalid file extension format\n");
			return 0;

		}

	}
}


void parse_cmdargs(int argc, char** argv)
{

switch (argc)
{
	case 1 : 
		puts(argsErrorStr);
		exit(0);
		break;
	case 2 : 
		if(!strcmp(argv[1],"--info")) {puts(infostr); exit(0);}
		else if(!strcmp(argv[1],"--help")) { puts(helpstr); exit(0);}
		else {puts(argsErrorStr); exit(0);}
		break;
	case 5 :
		if(strcmp(argv[1],"-i")) puts(argsErrorStr);
		else if( strcmp(argv[3],"-o")) puts(argsErrorStr);
		else if(!get_extensions(argv[2],argv[4],&io_exts) ) puts(argsErrorStr);
		else{
			printf("Starting compilation...\n");
		}
		break;
	default: 
		puts(argsErrorStr);
		exit(0);
		break;
}

}


