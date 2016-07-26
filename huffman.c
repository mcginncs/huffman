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
    const node **x = (const node **) a;
    const node **y = (const node **) b;
    if((*x)->freq == (*y)->freq) return 0;
    else return ((*x)->freq < (*y)->freq) ? 1 : -1;
}

// Adds nodes to tree based on frequency
node* buildTree(FILE *input){
	int frequency[128]={0};
	char x;
	while ((x=fgetc(input))!=EOF){
		frequency[(int)x]++; // Increment the frequency of this char
	}
 	node *queue[128]; // Array of node pointers, one for each char (some may be 0).
	
 	int count=0;
 	int i=0;
	for(i=0;i<128;i++){ // Loop through each char
		if(frequency[i]){ // If this char appears in the text file add its node to the queue
			node *n = (node *)malloc(sizeof(node));
			n->letter = i;
			n->freq = frequency[i];
			queue[count++] = n;
		}
	}
	
	// Sort the queue (I think?)
	while(count>1){ 
		node *n = (node *)malloc(sizeof(node));
		qsort(queue,count,sizeof(node *),compareFreq);
		n->left = queue[--count];
		n->right = queue[--count];
		queue[count++] = n;
	}
	
	return queue[0];
}

// Traverse the tree to create the codes for each node
void buildCodes(node *n, char **codes, char *code){
	printf("buildCodes(char = %c)\n", n->letter);
    if(!n->left && !n->right) {
		codes[n->letter] = code;
	}
    else
    {
    	char* result = (char *)malloc(strlen(code) + 2);
    	sprintf(result, "%s%c", code, '0');
        if(n->left) buildCodes(n->left, codes, result );//strcat(code, '0'));
		sprintf(result, "%s%c", code, '1');
        if(n-> right) buildCodes(n->right, codes, result);
    }
}

//Encodes file
void encode(FILE *input, char *out, char** codes){
	char x;
	while ((x=fgetc(input))!=EOF){
		strcpy(out, codes[x]);
		out += strlen(codes[x++]);
	}
}


// not complete
int main(void){
	char* filename = "text.txt";
	FILE *input, *output;

	int i;
    char buf[1024];
    input = fopen(filename, "r");
    output = fopen("output.txt","w");
	
	node *n = buildTree(input);

	
	static char *codes[128];
	
	char *prefix = (char *)calloc(1, sizeof(char));
	
	buildCodes(n,codes,prefix);
	printf("THIS WON'T DISPLAY UNTIL buildCodes() BUG IS FIXED\n");
	
	for (i = 0; i < 128; i++){
		if (codes[i]) {
			printf("'%c': %s\n", i, codes[i]);
		}
	}

	printf("hey5\n");
	// fclose(input);
	// input = fopen(filename, "r");
	rewind(input);
	encode(input, buf, codes);
	printf("hey6\n");
	printf("encoded: %s\n", buf);
 
	printf("decoded: ");
	//decode(buf, n);
 	// fclose(input);
 	// fclose(output);
	return 0;
}