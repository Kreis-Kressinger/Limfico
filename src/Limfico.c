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
	int mode = 0;
	int confirmflag = 0; // 0 = yes, 1 = no
	char confirmopt = 'y'; 
	char input[256] = ""; // name of input file
	char output[256] = ""; // name of output file
	char key[256] = ""; // name of key
	

	for(int i = 1; i < argc; i++){
		if(argv[i][0] == '-' && argv[i][1] == 'm' && argv[i][2] == '\0' && argv[i+1] != NULL){
			mode = argv[i+1][0] - '0';
		}
		else if(argv[i][0] == '-' && argv[i][1] == 'i' && argv[i][2] == '\0' && argv[i+1] != NULL){
			strcpy(input, argv[i+1]);
		}
		else if(argv[i][0] == '-' && argv[i][1] == 'o' && argv[i][2] == '\0' && argv[i+1] != NULL){
			strcpy(output, argv[i+1]);
		}
		else if(argv[i][0] == '-' && argv[i][1] == 'k' && argv[i][2] == '\0' && argv[i+1] != NULL){
			strcpy(key, argv[i+1]);
		}
		else if(argv[i][0] == '-' && argv[i][1] == 'c' && argv[i][2] == '\0'){
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

	if(confirmflag != 1){
		printf("\n**********\nMode: %d\nInput: %s\nOutput: %s\nKey: %s\n**********\nConfirm?(y/N): ", mode, input, output, key);
		scanf("%c", &confirmopt);
		getchar();
	} else{
		confirmopt = 'y';
	}

	if(confirmopt == 'y' || confirmopt == 'Y'){
		if(mode == 1) exit(mode1(input, output, key));
		if(mode == 2) exit(mode2(input, output, key));	
	}
	
	return 0;
}
