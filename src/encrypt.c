// 1 = encrypt out of file
// 2 = encrypt out of command line
// 3 = decrypt out of file
// 4 = decrypt out of command line


#include <stdio.h>
#include <string.h>
#include <wchar.h>

#define MAX_STR_LENGTH 8192

void encrypt(wchar_t inputbuffer, wchar_t keybuffer, wchar_t* result){	
	static wchar_t lastchar = 'a';
	*result = lastchar = (inputbuffer ^ keybuffer) ^ lastchar;	
}


int mode1(char *input, char *output, char *key){
	FILE *inputfile = fopen(input, "rb");
	FILE *keyfile = fopen(key, "rb");
	FILE *outputfile = fopen(output, "wb");
	wint_t inputbuffer, keybuffer; 
	wchar_t result;

	while((inputbuffer = fgetwc(inputfile)) != WEOF){
		
		if ((keybuffer = fgetwc(keyfile)) == WEOF) {
            		fseek(keyfile, 0, SEEK_SET);
           		 keybuffer = fgetwc(keyfile);
        	}		
		encrypt((wchar_t)inputbuffer, (wchar_t)keybuffer, &result);
		fputwc(result, outputfile);
	}
	
	fclose(outputfile);
	fclose(keyfile);
	fclose(inputfile);
	return 0;
}
int mode2(char *output, char *key){
	wchar_t str[MAX_STR_LENGTH] =  { '\0' };
	FILE *keyfile = fopen(key, "rb");
	FILE *outputfile = fopen(output, "wb");
	wchar_t keybuffer, result;	
	
	printf("Enter string: ");
	fwscanf(stdin, L"%s", str);
	
	for(int i = 0; !(str[i] == '\0'); i++){
			
		if ((keybuffer = fgetwc(keyfile)) == WEOF) {
			fseek(keyfile, 0, SEEK_SET);
           		keybuffer = fgetwc(keyfile);
        	}
		
		encrypt(str[i], keybuffer, &result);
		fputwc(result, outputfile);		
	}

	fclose(keyfile);
	fclose(outputfile);
	return 0;
}

