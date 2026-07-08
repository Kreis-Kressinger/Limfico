// 1 = encrypt out of file
// 2 = encrypt out of command line
// 3 = decrypt out of file
// 4 = decrypt out of command line


#include <stdio.h>
#include <string.h>
#include <wchar.h>

#define MAX_STR_LENGTH 8192

void encrypt(unsigned char input, unsigned char key, unsigned char *result){
    static unsigned char lastchar = 'a';
    *result = (input ^ key) ^ lastchar;
    lastchar = input;
}

void decrypt(unsigned char input, unsigned char key, unsigned char *result){
    static unsigned char lastchar = 'a';
    *result = (input ^ key) ^ lastchar;
    lastchar = *result;
}

int mode1(char *input, char *output, char *key){
	FILE *inputfile = fopen(input, "rb");
	FILE *keyfile = fopen(key, "rb");
	FILE *outputfile = fopen(output, "wb");

	if (!inputfile || !keyfile || !outputfile){
    		return -1;
	}

	unsigned char inputbuffer, keybuffer, result;

	while (fread(&inputbuffer, 1, 1, inputfile) == 1) {

    		if (fread(&keybuffer, 1, 1, keyfile) != 1) {
        		fseek(keyfile, 0, SEEK_SET);
        		fread(&keybuffer, 1, 1, keyfile);
    		}

    		encrypt(inputbuffer, keybuffer, &result);
    		fwrite(&result, 1, 1, outputfile);
	}
	
	fclose(outputfile);
	fclose(keyfile);
	fclose(inputfile);
	return 0;
}

int mode2(char *input, char *output, char *key){
	FILE *inputfile = fopen(input, "rb");
	FILE *keyfile = fopen(key, "rb");
	FILE *outputfile = fopen(output, "wb");

	if (!inputfile || !keyfile || !outputfile){
    		return -1;
	}

	unsigned char inputbuffer, keybuffer, result;

	while (fread(&inputbuffer, 1, 1, inputfile) == 1) {

    		if (fread(&keybuffer, 1, 1, keyfile) != 1) {
        		fseek(keyfile, 0, SEEK_SET);
        		fread(&keybuffer, 1, 1, keyfile);
    		}

    		decrypt(inputbuffer, keybuffer, &result);
    		fwrite(&result, 1, 1, outputfile);
	}
	
	fclose(outputfile);
	fclose(keyfile);
	fclose(inputfile);
	return 0;
}


