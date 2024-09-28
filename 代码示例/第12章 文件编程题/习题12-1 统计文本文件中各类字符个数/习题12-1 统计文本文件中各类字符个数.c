#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	int letter, number, others;
	letter = number = others = 0;
	if((fp = fopen("f12-1.txt", "r")) == NULL){
		printf("Can not open the file!\n");
		exit(0);
	}
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch != EOF){
			if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
				letter ++;
			else if(ch >= '0' && ch <= '9')
				number ++;
			else
				others ++;
		}
	}
	printf("letter:%d number:%d others:%d", letter, number, others);
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}

