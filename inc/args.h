#pragma once

#include "../inc/structs.h"

void parse_cmdargs(int argc, char** argv);

int get_extensions(char* i_file_name,char* o_file_name,extensions_t* extensions);  

int sort_extension(char** ext_vector,char* extension,char* file_name,int extensions_number); 

