#include <stdio.h>
#include <string.h>
int main(void){
	char input_line[1000];
	printf("Input the line: ");
	fgets(input_line, sizeof(input_line), stdin);
	printf("\n\nwords with doubling letters: \n");
	const char *patern = " .,;";
	char *word; 
	word = strtok(input_line, patern);
	int flag = 1;

	while(word != NULL){
		for (int j = 0; j < strlen(word); j++){
			
			if(word[j] == word[j-1]){
				printf("%s\n", word);
				flag = 0;
				break;
			}
		}
		word = strtok(NULL, patern);
	}
	if (flag){printf("all words don't have doubling letters");}

	getchar();
	getchar();
}