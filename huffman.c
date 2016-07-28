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

static int letters[] = {
32,
97,
116,
111,
110,
101,
115,
108,
105,
44,
104,
114,
100,
99,
98,
10,
13,
121,
117,
112,
109,
119,
46,
102,
103,
34,
73,
107,
118,
39,
65,
45,
77,
74,
72,
66,
76,
83,
84,
63,
87,
95,
79,
68,
69,
78,
96,
80,
89,
70,
33,
120,
106,
113,
67,
82,
71,
122,
75,
86,
85,
59,
40,
41,
56,
81,
49,
55,
58,
50,
90,
57,
48,
54,
53,
52,
51,
88,
36,
38,
47,
93,
91,
62
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
//string compare
int stringComp(char * a, char *b){
	
	int ai = atoi( a );
	int bi = atoi(b);
	printf("a: %d b: %d\n",ai,bi );
	if(strcmp(a,b)==0){
		return 1;
	}
	if(a==b){
		return 1;
	} else{
		return 0;
	}
}

//Encodes file
void encode(FILE *input, FILE *output){ // char** codes,
	char x;
	int a,b;
	int i;
	while ((x=fgetc(input))!=EOF){
		//a = (int)x - '0';
		for(i=0;i<len;i++){
			// printf("letters: %c %s-\n", *x, letters[i]);
			// strncpy((char *)letters[i],y,sizeof(y));
			//if(strcmp(x,letters[i])==0){
			//if(stringComp(x,(char *)letters[i])){
			if(x==letters[i]){
				// printf("letter: %c\n", x);
				// printf("code: %s\n",codes[i]);
				// printf("i: %d\n",i );

				fputs(codes[i],output);
				break;
			}
		}
		//fputs(codes[x],output);

	}
}


void decode(FILE *input){//, node* n){
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
	////
		// node* temp = n;
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
	char* filename = "text2.txt";
	FILE *input, *output;
    input = fopen(filename, "r");
    output = fopen("output.txt","w");
	
	//////
	// node *n = buildTree(input);

	// static char *codes[128];

	// char *code = (char *)malloc(sizeof(char));
	// buildCodes(n,codes,code);

	// int i;
	// for (i = 0; i < 128; i++){
	// 	if (codes[i]) {
	// 		printf("'%d': %s\n", i, codes[i]);
	// 		//printf("'%s',\n",codes[i]);
	// 	}
	// }

	/////


	printf("before encode\n");
	encode(input, output);
	printf("after encode\n");
	fclose(output);
	output = fopen("output.txt", "r");

	printf("decoded: \n");
	decode(output);//, n);
 	fclose(input);
 	fclose(output);
	return 0;
}