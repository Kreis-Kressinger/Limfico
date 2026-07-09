#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

	char userarg[255];
	char outputname[30]  = "key";
	unsigned long long int keylength;
	
	
	if(argv[1] != NULL){
		srand(time(0));
		for(int i = 3; i < 24; i++){
			short int placeholder = rand() % 90;
			while(placeholder < 65) placeholder += 5;
			outputname[i] = (char) placeholder;		
		}
		unsigned char damn[4] = ".txt";
		memcpy(&outputname[24], damn, 4*sizeof(unsigned char));		
		strcpy(userarg, argv[1]);
		keylength = llabs(strtoll(userarg, NULL, 10));
		
		if(keylength <= 0){ 	
			printf("Can't create a key with length '0'");
			exit(1);
		}	
		FILE* output = fopen(outputname, "wb");
		for(long long int i = 0; i < keylength; i++){
			unsigned char rnum = (unsigned char)(rand() % 255);
			fwrite(&rnum, sizeof(unsigned char), 1, output);	
		}
		printf("Key with length [%llu] successfully created", keylength);
		exit(0);	
	}
	
		
	printf("Invalid Argument");
	
return 1;
}
