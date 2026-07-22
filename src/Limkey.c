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

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32

#include <windows.h>
#include <bcrypt.h>


#elif defined (__unix__)

#include <sys/random.h>

#endif


int main(int argc, char *argv[]){

	char userarg[255];
	char outputname[30]  = "key";
	long long int keylength;
	
	
	if(argv[1] != NULL){
		srand(time(0));
		for(int i = 3; i < 24; i++){
			short int placeholder = rand() % 90;
			while(placeholder < 65) placeholder += 5;
			outputname[i] = (char) placeholder;		
		}
		unsigned char damn[4] = ".bin";
		memcpy(&outputname[24], damn, 4*sizeof(unsigned char));		
		strcpy(userarg, argv[1]);
		keylength = strtoll(userarg, NULL, 10);
		
		if(keylength <= 0){ 	
			printf("Invalid params: Can't create a key with length 0 or below\n");
			exit(1);
		}	
		FILE* output = fopen(outputname, "wb");
		for(long long int i = 0; i < keylength; i++){
			unsigned char rnum;
#ifdef _WIN32
			BCryptGenRandom(NULL, (PUCHAR)&rnum, sizeof(rnum), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
#elif defined(__unix__)
			getrandom(&rnum, sizeof(rnum), 0);

#endif
			fwrite(&rnum, sizeof(unsigned char), 1, output);	
		}
		printf("Key with length [%llu] successfully created\n", keylength);
		exit(0);	
	}
	
		
	printf("Invalid parameters\n");
	
return 2;
}
