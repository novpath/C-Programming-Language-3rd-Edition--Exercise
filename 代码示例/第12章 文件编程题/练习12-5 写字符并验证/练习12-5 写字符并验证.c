#include<stdio.h>

int main(void)
{
	FILE *fp;
	int i = 0;
	char ch, str[100];
	if((fp = fopen("f3.txt", "w+")) == NULL){
		printf("Can not open the file!\n");
		exit(0);
	}
	while((ch = getchar()) != '\n')	{
		str[i] = ch;
		i ++;
	}
	str[i] = '\0';
	fprintf(fp, "%s", str);
	rewind(fp);
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch != EOF) printf("%c", ch);
	}
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	
	return 0;
}
