#include <stdio.h>

int main(int argc, char *argv[]){	
	int mode = 0; // 0 = use limfico menu, 1 = encrypt out of file, 2 = encrypt out of command line
		      // 3 = decrypt out of file, 4 = decrypt out of command line
	char* input;
	char* output;	
	char* key;
	
	for(int i = 1; i < argc; i++){
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
	}


	
	
	
	
	
	return 0;
}
