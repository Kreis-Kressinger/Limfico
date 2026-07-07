#include <stdio.h>
#include <string.h>
#include "encrypt.h"

int main(int argc, char *argv[]){	
	int mode = 0; // 0 = uninitialized, 1 = encrypt out of file, 2 = encrypt out of command line
		      // 3 = decrypt out of file, 4 = decrypt out of command line
	int confirmflag = 0; // 0 = yes, 1 = no
	char confirmopt = 'n'; // (y/N) 
	char input[256] = ""; // name of input / input string
	char output[256] = ""; // name of output 
	char key[256] = ""; // name of key
	

	for(int i = 1; i < argc && argv[i+1] != NULL; i++){
		if(argv[i][0] == '-' && argv[i][1] == 'm' && argv[i][2] == '\0'){
			mode = argv[i+1][0] - '0';
		}
		if(argv[i][0] == '-' && argv[i][1] == 'i' && argv[i][2] == '\0'){
			strcpy(input, argv[i+1]);
		}
		if(argv[i][0] == '-' && argv[i][1] == 'o' && argv[i][2] == '\0'){
			strcpy(output, argv[i+1]);
		}
		if(argv[i][0] == '-' && argv[i][1] == 'k' && argv[i][2] == '\0'){
			strcpy(key, argv[i+1]);
		}
		if(argv[i][0] == '-' && argv[i][1] == 'c' && argv[i][2] == '\0'){
			confirmflag = 1;
		}
	}

	if(mode == 0){
		printf("Enter mode: ");
		scanf("%d", &mode);
		getchar();
	}
	if(input[0] == '\0'){
		printf("Enter input: ");
		scanf("%255s", input);
		getchar();
	}
	if(output[0] == '\0'){
		printf("Enter output: ");
		scanf("%255s", output);
		getchar();
	}
	if(key[0] == '\0'){
		printf("Enter key: ");
		scanf("%255s", key);
		getchar();
	}

	if(confirmflag == 0){
		printf("Mode: %d\nInput: %s\nOutput: %s\nKey: %s\nConfirm?(y/N): ", mode, input, output, key);
		scanf("%c", &confirmopt);
		getchar();
	}

	if(confirmopt == 'y' || confirmopt == 'Y'){
		return encrypt(mode, input, output, key);
	}
	
	return 0;
}
