#include <stdio.h>
#include "encrypt.h"

int main(int argc, char *argv[]){	
	int mode = 0; // 0 = uninitialized, 1 = encrypt out of file, 2 = encrypt out of command line
		      // 3 = decrypt out of file, 4 = decrypt out of command line
	int confirmflag = 0; // 0 = yes, 1 = no
	char confirmopt = 'n'; // (y/N) 
	char *input; // name of input / input string
	char *output; // name of output 
	char *key; // name of key
	

	for(int i = 1; i < argc && argv[i+1] != NULL; i++){
		if(argv[i][0] == '-' && argv[i][1] == 'm' && argv[i][2] == '\0'){
			mode = argv[i+1][0] - '0';
		}
		if(argv[i][0] == '-' && argv[i][1] == 'i' && argv[i][2] == '\0'){
			input = &argv[i+1][0];
		}
		if(argv[i][0] == '-' && argv[i][1] == 'o' && argv[i][2] == '\0'){
			output = &argv[i+1][0];
		}
		if(argv[i][0] == '-' && argv[i][1] == 'k' && argv[i][2] == '\0'){
			key = &argv[i+1][0];
		}
		if(argv[i][0] == '-' && argv[i][1] == 'c' && argv[i][2] == '\0'){
			confirmflag = 1;
		}
	}

	if(mode == 0){
		printf("Enter mode: ");
		scanf("%d", &mode);
	}
	if(input == NULL){
		printf("Enter input: ");
		scanf("%s", input);
	}
	if(output == NULL){
		printf("Enter output: ");
		scanf("%s", output);
	}
	if(key == NULL){
		printf("Enter key: ");
		scanf("%s", key);
	}

	if(confirmflag == 0){
		printf("Mode: %d\nInput: %s\nOutput: %s\nKey: %s\nConfirm?(y/N): ", mode, input, output, key);
		scanf("%c", &confirmopt);
	}

	if(confirmopt == 'y' || confirmopt == 'Y'){
		encrypt();
	}
	
	return 0;
}
