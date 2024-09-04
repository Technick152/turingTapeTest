/** 
 *<h2>Turing Tape Test</h2>
 *<p>A program to practice a very simple turing tape system</p>
 *
 *This program will read a file for 7 key characters {<(move left), >(move right), +(to increments by 1), -(to decrease by 1),
 *[(starts loop while currentNum is not equal to zero), ](closes loop}, .(prints current number)
 *
 *@author Nicolas Alvarez
 *@Version 1.0
 **/

#include <stdio.h>

FILE* fp;

void main(){
	
	fp = fopen("turingTape.txt", "r");

	int memory[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int position = 0;
	char command = '.';

	while(!feof(fp)){
			
		fscanf(fp, "%c\n", &command);
		switch(command){
			case '.':
				printf("%d", memory[position]);
				break;
			case '<':
				position--;
				break;
			case '>':
				position++;
				break;
			case '+':
				memory[position]++;
				break;
			case '-':
				memory[position]--;
				break;
			default:
				printf("\nERROR INVALID TAPE ENTRY: %c \n", command);
				break;
		}
	}

	fclose(fp);
}

