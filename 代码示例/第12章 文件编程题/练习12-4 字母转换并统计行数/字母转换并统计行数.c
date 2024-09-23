#include<stdio.h>

int main()
{
	FILE *fp;
	int count = 0;
	char ch;
	if((fp = fopen("a.txt", "r")) == NULL){
		printf("Can not open the file!\n");
		exit(0);
	} 
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch == '\n')
			count ++;
		if(ch != EOF) {
			if(ch >= 'A' && ch <= 'Z')
				printf("%c", ch - 'A' + 'a');
			else
				printf("%c", ch);
		}
	}
	printf("\n");
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	printf("The number of enter is %d", count + 1);
	return 0;
}
