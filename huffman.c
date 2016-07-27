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
	node* temp = n;
	while ((x=fgetc(input))!=EOF){
		if(x=='1'){
			temp = temp->right;
		} else {
			temp = temp->left;
		}
		if(temp->letter){
			putchar(temp->letter);
			temp = n;
		}
	}
}

// not complete
int main(void){
	char* filename = "text.txt";
	FILE *input, *output;
    input = fopen(filename, "r");
    output = fopen("output.txt","w");
	
	node *n = buildTree(input);

	static char *codes[128];
	char *code = (char *)malloc(sizeof(char));
	buildCodes(n,codes,code);

	int i;
	for (i = 0; i < 128; i++){
		if (codes[i]) {
			printf("'%c': %s\n", i, codes[i]);
		}
	}

	rewind(input);
	encode(input, codes,output);

	fclose(output);
	output = fopen("output.txt", "r");

	printf("decoded: ");
	decode(output, n);
 	fclose(input);
 	fclose(output);
	return 0;
}