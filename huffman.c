#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//gcc huffman.c -o huffman
// Each char in the input file has a corresponding node
 typedef struct node_t{
 	int freq; // # of times this char appears in the input file
 	char letter;
 	struct node_t *left;
 	struct node_t *right;
 } node;
 
// Frequency array - has an element for each char
int freqs[128];
static char *codes2[] = {
	'110010',
	'110001',
	'00',
	'11000011110',
	'0100100',
	'0100111101100001000',
	'0100111101100101101',
	'11000010',
	'110000110100000',
	'010011110110011',
	'101101',
	'010010111',
	'1001011',
	'01001111011000010011',
	'11000011010001100',
	'1100001101000010',
	'0100111101100100',
	'010011110110010111',
	'010011110110000101',
	'110000110100011011',
	'01001111011001010',
	'0100111101100011',
	'0100111101100000',
	'01001111011000011',
	'1100001101000011',
	'110000110100010',
	'01001111011000010010',
	'0100101101',
	'010011100',
	'1100000001',
	'110000110101',
	'11000000000',
	'01001110111',
	'01001011001',
	'110000110001',
	'0100111110',
	'11000001',
	'010010101',
	'0100111101101',
	'0100111111',
	'110000001',
	'11000011001',
	'01001011000',
	'01001110110',
	'1100001101000111',
	'010011110111',
	'0100111100',
	'1100001110',
	'11000011010010',
	'11000011010011',
	'0100101001',
	'110000110100011010',
	'11000000001',
	'0100111101100010',
	'01001111011001011001',
	'01001111011001011000',
	'0100101000',
	'01001111010',
	'0111',
	'010000',
	'100100',
	'10111',
	'1111',
	'101000',
	'101001',
	'11101',
	'11011',
	'11000011011',
	'1001010',
	'10011',
	'101011',
	'0101',
	'0110',
	'010001',
	'11000011111',
	'11010',
	'11100',
	'1000',
	'110011',
	'0100110',
	'101100',
	'0100111010',
	'101010',
	'110000110000'
}

// For qsort
int compareFreq(const void *a, const void *b){
    const node **n1 = (const node **) a;
    const node **n2 = (const node **) b;
    if((*n1)->freq == (*n2)->freq){
    	return 0;
    } else if ((*n1)->freq < (*n2)->freq){
		return 1;
	} else {
		return -1;
	}
}

//Concat 2 strings because it doesnt work my other way
char *concat(char *a, char b){
    char *cat = (char *)malloc(strlen(a) + 2);
    sprintf(cat, "%s%c", a, b);
    return cat;
}

// Adds nodes to tree based on frequency
node* buildTree(FILE *input){
	int frequency[128]={0};
	char x;
	while ((x=fgetc(input))!=EOF){
		frequency[(int)x]++; // Increment the frequency of this char
	}
	//128 characters
 	node *nodes[128]; // Array of node pointers, one for each char (some may be 0).
	
 	int count=0;
 	int i=0;
	for(i=0;i<128;i++){ // Loop through each char
		if(frequency[i]){ // If this char appears in the text file add its node to the array of ndoes
			node *n = (node *)malloc(sizeof(node));
			n->letter = i;
			n->freq = frequency[i];
			nodes[count++] = n;
		}
	}
	//Sort nodes
	//get the lowest 2 freq nodes and create a parent node for that and add it back to queue
	while(count>1){ 
		node *n = (node *)malloc(sizeof(node));
		qsort(nodes,count,sizeof(node *),compareFreq);
		n->left = nodes[--count];
		n->right = nodes[--count];
		if(!n->freq){
			n->freq = n->left->freq + n->right->freq;
		}
		nodes[count++] = n;
	}
	return nodes[0];
}


// Traverse the tree to create the codes for each node
void buildCodes(node *n, char **codes, char *code){
	//printf("buildCodes(char = %c)\n", n->letter);
	// I think this way is more simple
	if(n->letter){
		codes[n->letter] = code;
		return;
	}
	buildCodes(n->left, codes, concat(code, '0'));
    buildCodes(n->right, codes, concat(code, '1'));
 //    if(!n->left && !n->right) {
	// 	codes[n->letter] = code;
	// } else {
 //        if(n->left) buildCodes(n->left, codes, concat(code, '0'));
 //        if(n->right) buildCodes(n->right, codes, concat(code, '1'));
 //    }
}

//Encodes file
void encode(FILE *input, char** codes, FILE *output){
	char x;
	while ((x=fgetc(input))!=EOF){
		fputs(codes[x],output);

	}
}

void decode(FILE *input, node* n){
	char x;
	char code;
	node* temp = n;
	while ((x=fgetc(input))!=EOF){
		int i;
		for (i = 0; i < 128; i++){
			strcat(x,code);
			if (stcmp(codes[i],code)) {
				//match
				printf("%c",i);
				free(code);
				break;
			}
		}
	// 	if(x=='1'){
	// 		temp = temp->right;
	// 	} else {
	// 		temp = temp->left;
	// 	}
	// 	if(temp->letter){
	// 		//putchar(temp->letter);
	// 		temp = n;
	// 	}
	// }
}

// not complete
int main(void){
	char* filename = "text.txt";
	FILE *input, *output;
    input = fopen(filename, "r");
    output = fopen("output.bin","wb");
	
	node *n = buildTree(input);

	static char *codes[128];

	char *code = (char *)malloc(sizeof(char));
	buildCodes(n,codes,code);

	int i;
	for (i = 0; i < 128; i++){
		if (codes[i]) {
			//printf("'%c': %s\n", i, codes[i]);
			//printf("'%s',\n",codes[i]);
		}
	}

	//rewind(input);
	// encode(input, codes,output);

	// fclose(output);
	// output = fopen("output.bin", "rb");

	// printf("decoded: ");
	// decode(output, n);
 // 	fclose(input);
 // 	fclose(output);
	// return 0;
}