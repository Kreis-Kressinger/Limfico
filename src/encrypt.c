// 1 = encrypt out of file
// 2 = encrypt out of command line
// 3 = decrypt out of file
// 4 = decrypt out of command line


#include <stdio.h>
#include <string.h>
#include <wchar.h>

void encrypt(wchar_t inputbuffer, wchar_t keybuffer, wchar_t* result){	
	static wchar_t lastchar = 'a';
	*result = lastchar = (inputbuffer ^ lastchar) ^ keybuffer;	
}


int mode1(char *input, char *output, char *key){
	FILE *inputfile = fopen(input, "r");
	FILE *keyfile = fopen(key, "r");
	FILE *outputfile = fopen(output, "w");
	wchar_t inputbuffer, keybuffer, result;

	while(!feof(inputfile)){
		if(feof(keyfile)){
			fseek(keyfile, 0, SEEK_SET);
		}
		keybuffer = fgetwc(keyfile);
		inputbuffer = fgetwc(inputfile);
		encrypt(inputbuffer, keybuffer, &result);
		fputws(&result, outputfile);
	}
	
	fclose(outputfile);
	fclose(keyfile);
	fclose(inputfile);
	return 0;
}
int mode2(char *output, char *key){
return 0;
}
int mode3(char *input, char *output, char *key){
return 0;
}
int mode4(char *output, char *key){
return 0;
}
