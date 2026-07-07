// 1 = encrypt out of file
// 2 = encrypt out of command line
// 3 = decrypt out of file
// 4 = decrypt out of command line


char* encrypt(char *contentbuffer, char *keybuffer){
	char result[256] = "";
		


	
	return result;
}


int mode1(char *input, char *output, char *key){
	FILE *inputfile = fopen(input, "r");
	FILE *keyfile = fopen(key, "r");
	FILE *outputfile = fopen(output, "w");
	
	
	
	
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
