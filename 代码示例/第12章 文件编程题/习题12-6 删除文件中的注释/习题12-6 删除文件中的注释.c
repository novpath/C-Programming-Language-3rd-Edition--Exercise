#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1, *fp2;
	char ch, comment[2];
	if((fp1 = fopen("hello.c", "r")) == NULL){
		printf("Can not open the file!\n");
		exit(0);
	}
	if((fp2 = fopen("new_hello.c", "w")) == NULL){
		printf("Can not open the file!\n");
		exit(0);
	}
while (!feof(fp1))
{
	ch = fgetc(fp1);
	if (ch == '/')
	{
		ch = fgetc(fp1);
		//单行注释 ，遇到换行符结束，结束后需输出换行符
		if (ch == '/')
		{
			while (ch != '\n' && ch != EOF)
			{
				ch = fgetc(fp1);
			}
			fputc('\n', fp2);
		}
		/*跨行注释，遇到结束符结束，每次读入两个字符进行比较，若不是则退回一个字符，继续比较*/
		else if (ch == '*')
		{
			fgets(comment, 3, fp1);
			while (strstr(comment, "*/") == NULL)
			{
				fseek(fp1, -1L, SEEK_CUR);
				fgets(comment, 3, fp1);
			}
		}
		//不是注释符，只是单纯的'/'符号，则退回两个字符，读写'/'
		else
		{
			fseek(fp1, -2L, SEEK_CUR);
			ch = fgetc(fp1);
			fputc(ch, fp2);
		}
	}
	else
	{
		fputc(ch, fp2);
	}
}
	if(fclose(fp1)){
		printf("Can not close the file!\n");
		exit(0);
	}
	if(fclose(fp2)){
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}

