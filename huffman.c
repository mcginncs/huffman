#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 //gcc huffman.c -o huffman
//nodes
 typedef struct node_t{
 	int freq;
 	char letter;
 	struct node_t *left;
 	struct node_t *right;
 } node;
//frequency array
int freqs[128];

//for qsort
int compareFreq(const void *a, const void *b){
    const node **x = (const node **) a;
    const node **y = (const node **) b;
    if((*x)->freq == (*y)->freq) return 0;
    else return ((*x)->freq < (*y)->freq) ? 1 : -1;
}
//gets frequencies from file
//creates nodes and adds them to tree
node* buildTree(FILE *input){
	int frequency[128]={0};
	char x;
	while ((x=fgetc(input))!=EOF){
		frequency[(int)x]++;
	}
 	node *queue[128];
 	int count=0;
 	int i=0;
	for(i=0;i<128;i++){
		if(frequency[i]){
			node *n = (node *)malloc(sizeof(node));
			n->letter = i;
			n->freq = frequency[i];
			queue[count++] = n;
		}
	}
	while(count>1){
		node *n = (node *)malloc(sizeof(node));
		qsort(queue,count,sizeof(node *),compareFreq);
		n->left = queue[--count];
		n->right = queue[--count];
		queue[count++] = n;
	}
	return queue[0];
}
//creates the code from the tree
void buildCodes(node *n, char **codes, char *code){
    if(!n->left && !n->right) codes[n->letter] = code;
    else
    {
    	char* result = (char *)malloc(strlen(code) + 2);
    	sprintf(result, "%s%c", code, '0');
        if(n->left) buildCodes(n->left, codes, result );//strcat(code, '0'));
		sprintf(result, "%s%c", code, '1');
        if(n-> right) buildCodes(n->right, codes, result);
        free(code);
    }
}
// not complete
int main(void){
	printf("hui\n");
	char* filename = "text.txt";
	FILE *input, *output;

	int i;
    char buf[1024];
    input = fopen(filename, "r");
    printf("hey1\n");
    output = fopen("output.txt","w");
    printf("hey2\n");
	node *n = buildTree(input);
	static char *code[128];
	char *prefix = (char *)calloc(1, sizeof(char));
	buildCodes(n,code,prefix);


	printf("hey4\n");
	for (i = 0; i < 128; i++){
		if (code[i]) {
			printf("'%c': %s\n", i, code[i]);
		}
	}
	printf("hey5\n");
	fclose(input);
	input = fopen(filename, "r");
	//encode(input, buf);
	//printf("encoded: %s\n", buf);
 
	//printf("decoded: ");
	//decode(buf, hp[1]);
 	fclose(input);
 	fclose(output);
	return 0;
}