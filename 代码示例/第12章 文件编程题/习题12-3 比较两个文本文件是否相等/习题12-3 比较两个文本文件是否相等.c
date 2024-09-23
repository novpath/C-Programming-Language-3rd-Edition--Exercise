#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1, *fp2;
	char ch1, ch2;
	int row, col;
	row = col = 0;
	if((fp1 = fopen("f12-3 a.txt", "r")) == NULL){
		printf("Can not open the file!\n");
		exit(0);
	}
	if((fp2 = fopen("f12-3 b.txt", "r")) == NULL){
		printf("Can not open the file!\n");
		exit(0);
	}
	while(!feof(fp1) && !feof(fp2)){
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);
		col ++;
		if(ch1 != ch2)
		{
			printf("row = %d, col = %d", row + 1, col);
			break;
		}
		if(ch1 == '\n')
		{
			row ++;
			col = 0;
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

