#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static char lettersArray[] = {
'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',' ','n','\0','\0','a','\0','\n','\0','t','\0','o','\0','e','\0','\0','\0','\0','\0','\0','\0','r','I','u','\0','\0','\0','\0','\0','\0','d','\0','\0','\0','\0','\0','\0','\0','m','l','\0','\0','\0','i','h','\0','\0','\0','\0','\0','\0','\0','\0','\0','g','s','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','y','\0','\0','\0','\0','\0','\0','\0','k','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','w','\0','\0','\0','\0','\0','.','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','b','c','A','-','\0','\0','\0','N','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','S','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','!','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0',',','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','H','E','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','T','?','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','f','\0','\0','\0','\0','\0','Y','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','W','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','x','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','B','9','G','F','6','5','8','7','U','Q','X','V','K','J','P','M','z','v','\0','\0','j','Z','q','p','2','1','4','3','0','O','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','L','R','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','D','C'
};

static char *indexedCodes[] = {
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"0101",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"111",
"1100010",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"1101110",
"0100011",
"110110",
"",
"100011100",
"100011001",
"100011000",
"100011011",
"100011010",
"100000101",
"100000100",
"100000111",
"100000110",
"100000001",
"",
"",
"",
"",
"",
"01101111",
"",
"0100010",
"100000000",
"110111101",
"110111100",
"01001101",
"100000011",
"100000010",
"01001100",
"00100",
"100001101",
"100001100",
"110001100",
"100001111",
"0100111",
"100011101",
"100001110",
"100001001",
"110001101",
"0110110",
"01101110",
"100001000",
"100001011",
"11000111",
"100001010",
"10001111",
"100010101",
"",
"",
"",
"",
"",
"",
"0011",
"0100000",
"0100001",
"01100",
"1011",
"10001001",
"000100",
"11010",
"11001",
"100010100",
"011010",
"10101",
"10100",
"0000",
"1001",
"100010111",
"100010110",
"00011",
"000101",
"0111",
"00101",
"100010001",
"110000",
"11011111",
"010010",
"100010000",
"",
"",
"",
"",
""
};

// Encodes the file
void encode(FILE *input, FILE *encodedOutput){
  char bytes[20480]; // TODO How big should this be?
  bytes[0] = '\0';
  short int i, numBits = 0;
  char x;

  while((x = fgetc(input))!= EOF){ // Loop through each char in input file
          strcat(bytes, indexedCodes[(int)x]); // Add the code to bytes[]
          numBits += strlen(indexedCodes[(int)x]);
  }
 
 // Add padding - 0100110
 switch(numBits & 7){
   case 7:
     strcat(bytes, "0");
     numBits += 1;
   case 6:
     strcat(bytes, "01"); 
     numBits += 2;
   case 5:
     strcat(bytes, "010"); 
     numBits += 3;
   case 4:
     strcat(bytes, "0100");
     numBits += 4;
   case 3:
     strcat(bytes, "01001"); 
     numBits += 5;
   case 2:
     strcat(bytes, "010011"); 
     numBits += 6;
   case 1:
     strcat(bytes, "0100110");
     numBits += 7;
 }
  
  char sub[9];
 
 // Write to encodedOutput file 1 byte at a time
   for(i = 0; i < (numBits >> 3); i++) {
    strncpy(sub, bytes + (i<<3), 8);
    sub[8] = '\0';
    long l = strtol(sub, 0, 2);
    unsigned char b = l;
    fwrite(&b, 1, 1, encodedOutput);
  }
}

void decode(FILE *input, FILE *output){
	short int i;
 
  char binaryString[16350]; // TODO How big should this be?
  binaryString[0] = '\0';
  int binarySize = 0;
	
	while ((x = fgetc(input))!= EOF){
    for (i = 7; i >= 0; i-=2) { // Take char and shift to read each bit
        binaryString[binarySize] = ((x & (1 << i)) ? '1' : '0' ); // Write each bit individually
        binaryString[binarySize+1] = ((x & (1 << i - 1)) ? '1' : '0' );
        binarySize+=2;
    }
   }
   binaryString[binarySize] = '\0';

   int pos = 1;
   for(i = 0; i < strlen(binaryString); i+=2) { // Loop through binaryString character by character until '\0' reached   
      if(binaryString[i] == '0'){
        __asm { mov pos, pos, asl #1; }
      } else if(binaryString[i] == '1'){
        __asm { mov pos, pos, asl #1; }
        __asm { add pos, pos, #1; }
      }
      if(lettersArray[pos]){ // if the code corresponds to a letter, add it to decodedOutput file and reset position
  		   putc(lettersArray[pos], output);
         __asm { mov pos, #1; }
      }
      if(binaryString[i+1] == '0'){
        __asm { mov pos, pos, asl #1; }
      } else if(binaryString[i+1] == '1'){
        __asm { mov pos, pos, asl #1; }
        __asm { add pos, pos, #1; }
      }
      if(lettersArray[pos]){ 
  		  putc(lettersArray[pos], output);
         __asm { mov pos, #1; }
      }
   }
}

int main(void){
	clock_t timeStart = clock();

	char* filename = "book.txt";
	FILE *input, *encodedOutput, *decodedOutput;
	short int i = 0;

	input = fopen(filename, "r");
	encodedOutput = fopen("encodedOutput.txt","w");

	clock_t timeStartEncoding = clock();
	encode(input, encodedOutput);
	clock_t timeEndEncoding = clock();
	fclose(encodedOutput);

	encodedOutput = fopen("encodedOutput.txt", "r");
	decodedOutput = fopen("decodedOutput.txt","w");
	clock_t timeStartDecoding = clock();
	decode(encodedOutput, decodedOutput);
	clock_t timeEndDecoding = clock();
	fclose(input);
	fclose(encodedOutput);
	fclose(decodedOutput);
	clock_t timeEnd = clock();
	printf("Total Time = %d milliseconds\n", ((int)timeEnd - (int)timeStart) * 1000 / (int)CLOCKS_PER_SEC); 
	printf("Encoding Time = %d milliseconds\n", ((int)timeEndEncoding - (int)timeStartEncoding) * 1000 / (int)CLOCKS_PER_SEC);
	printf("Decoding Time = %d milliseconds\n", ((int)timeEndDecoding - (int)timeStartDecoding) * 1000 / (int)CLOCKS_PER_SEC);
	return 0;
}