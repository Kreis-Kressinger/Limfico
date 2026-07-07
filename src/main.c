/*
 *	Copyright (C) 2026  Kreis Kressinger
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"

int main(int argc, char *argv[]){	
	int8_t mode = 0; // 0 = uninitialized, 1 = encrypt out of file, 2 = encrypt out of command line
		      // 3 = decrypt out of file, 4 = decrypt out of command line
	int8_t confirmflag = 0; // 0 = yes, 1 = no
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
	if( (input[0] == '\0' && mode == 1) || (input[0] == '\0' && mode == 3) ){
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
		printf("\n**********\nMode: %d\nInput: %s\nOutput: %s\nKey: %s\n**********\nConfirm?(y/N): ", mode, input, output, key);
		scanf("%c", &confirmopt);
		getchar();
	}

	if(confirmopt == 'y' || confirmopt == 'Y'){
		switch(mode){
			case 1:
				exit(mode1(input, output, key));
				break;
			
			case 2: 
				exit(mode2(output, key));
				break;

			case 3: 
				exit(mode3(input, output, key));
				break;

			case 4: 
				exit(mode4(output, key));
				break;
		}
	}
	
	return 0;
}
