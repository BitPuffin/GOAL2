
#include <stdio.h>
#include <stdlib.h>
#include "parse.h"

#define SOURCE_BUFSIZE 102400
char srcbuf[SOURCE_BUFSIZE];
int main()
{
	{	/* read source */
		FILE* testfile = fopen("test.soal", "r");
		size_t readcount = fread(srcbuf, 1, SOURCE_BUFSIZE, testfile);
		if(readcount >= SOURCE_BUFSIZE-1) {
			fprintf(stderr, "well we don't support a source file this big yet\n");
			fclose(testfile); /* :( */
			return EXIT_FAILURE;
		}
		srcbuf[readcount] = '\0';
		fclose(testfile);
	}
	parse(srcbuf, "test.soal");
}


#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"
