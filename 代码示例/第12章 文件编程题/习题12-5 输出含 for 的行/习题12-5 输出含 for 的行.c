#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *strstr(const char *s1, const char *s2);
int main()
{
	FILE *fp;
	char str[100];
	if((fp = fopen("test.txt", "r")) == NULL){
		printf("Can not open the file!\n");
		exit(0);
	}
	while(!feof(fp)){
		fgets(str, sizeof(str), fp);
		if(strstr(str, "for"))
			printf("%s", str);
	}
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}

