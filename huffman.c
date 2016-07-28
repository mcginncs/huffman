//gcc huffman.c -o huffman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
// Frequency array - has an element for each char
int freqs[128];

static char letters[] = {
' ',
'e',
'a',
'o',
't',
'n',
's',
'r',
'd',
'h',
'l',
'i',
'm',
',',
'u',
'g',
'w',
'y',
'p',
'c',
'b',
'f',
'k',
'\"',
'\n',
'.',
'v',
'\\',
'I',
'\'',
'A',
'J',
'M',
'-',
'B',
'H',
'x',
'L',
'S',
'T',
'W',
'?',
'_',
'E',
'F',
'!',
'O',
'q',
'j',
'N',
'D',
'Y',
'P',
'`',
'C',
'z',
'R',
'G',
'K',
'V',
'U',
'(',
')',
';',
'7',
'2',
'1',
'Q',
'Z',
':',
'8',
'9',
'6',
'0',
'X',
'4',
'3',
'5',
'&',
'$',
'/',
']',
'>',
'[',
};

static char *codes[] = {
"00",
"1111",
"0111",
"0110",
"1000",
"0101",
"11100",
"11010",
"10111",
"11101",
"10011",
"11011",
"101011",
"101101",
"110011",
"101001",
"101100",
"101010",
"010001",
"100100",
"010000",
"101000",
"1001010",
"0100100",
"110010",
"1001011",
"0100110",
"110001",
"11000001",
"11000010",
"010011100",
"010010101",
"110000001",
"010010111",
"1100000001",
"0100111110",
"0100111010",
"0100111111",
"0100111100",
"1100001110",
"0100101001",
"0100101101",
"0100101000",
"01001110111",
"01001011001",
"11000011110",
"01001011000",
"11000011111",
"11000011011",
"11000011001",
"11000000000",
"11000000001",
"01001110110",
"01001111010",
"110000110101",
"110000110000",
"010011110111",
"110000110001",
"0100111101101",
"11000011010011",
"11000011010010",
"110000110100000",
"010011110110011",
"110000110100010",
"0100111101100011",
"0100111101100100",
"1100001101000010",
"1100001101000111",
"0100111101100010",
"1100001101000011",
"0100111101100000",
"01001111011000011",
"01001111011001010",
"11000011010001100",
"110000110100011010",
"010011110110000101",
"010011110110010111",
"110000110100011011",
"0100111101100101101",
"0100111101100001000",
"01001111011000010011",
"01001111011001011000",
"01001111011000010010",
"01001111011001011001"
};
int len = sizeof(letters)/sizeof(letters[0]);



//Encodes file
void encode(FILE *input, FILE *output){
	char x;
	int a,b;
	int i;
	while ((x = fgetc(input))!= EOF){ // Loop through each char in input file
		for(i = 0; i < len; i++){ // Loop through each char in our lookup table
      printf("x = %c, letters[i] = %c\n", x, letters[i]);
			if(x == letters[i]){ // If you find a match, put the corresponding code into the output file
				fputs(codes[i], output);
				break;
			}
		}
	}
}

void decode(FILE *input){
	char x;
	char code[25]; 
	char code2[25];
	int i;
	int count = 0;
	while ((x=fgetc(input))!=EOF){
		code[count++] = x;

		printf("Code: %s i: %c\n",code,x);
		for (i = 0; i < 128; i++){
			//strcat(code,x);
			//code = concat(code,x);
			strcpy(code2,codes[i]);
			if (strcmp(code2,code)==0) {
				//match
				//printf("Letter: %c i: %d\n",letters[i],i);
				//free(code);
				//memset(code, 0, 25);
				//break;
			}
		}
	}
}

// not complete
int main(void){
	char* filename = "text.txt";
	FILE *input, *output;
  input = fopen(filename, "r");
  output = fopen("output.txt","w");

	printf("before encode\n");
	encode(input, output);
	printf("after encode\n");
 
	fclose(output);
	//output = fopen("output.txt", "r");

	//printf("decoded: \n");
	//decode(output);//, n);
 	fclose(input);
 	//fclose(output);
	return 0;
}