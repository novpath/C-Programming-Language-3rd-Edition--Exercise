#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>			
struct LogData{			
	int accid;			
	char accname[15];	
	double balance;		
};
long size = sizeof(struct LogData);	

int inputchoice()				
{
	int mychoice;
	printf("\n");
	printf("      Account Balance Management\n");
	printf("     =============================                   \n");
	printf("      1 - Add a new cash log.\n");
	printf("      2 - List all cash log.\n");
	printf("      0 - End program.\n"); 
	printf("\n");
	printf("   Enter your choice:");
	scanf("%d", &mychoice);
	return mychoice;
}

void AddNewLog(FILE *cfptr)		
{
	struct LogData log;
	double charge;
	printf("Input accid:");
	scanf("%d", &log.accid);
	printf("Input accname:");
	scanf("%s", log.accname);
	printf("Input Charge: Income+ and expend-:");
	scanf("%lf", &charge);
	fseek(cfptr, (log.accid - 1) * size, SEEK_SET);
	fread(&log, size, 1, cfptr);
	log.balance += charge;
	fseek(cfptr, (log.accid - 1) * size, SEEK_SET);
	fwrite(&log, sizeof(struct LogData), 1, cfptr);
	fclose(cfptr);
}

void ListAllLog(FILE *cfptr)	
{
	struct LogData log;
	if(!feof(cfptr))
	{
		fseek(cfptr, 0L, SEEK_SET);
		fread(&log, size, 1, cfptr);
		printf("AcctNo\t\t    AcctName  \t\t   Balance\n");
		while(!feof(cfptr)){
			printf("%3d\t\t%12s\t\t%10.2lf\n", log.accid, log.accname, log.balance);
			fread(&log, size, 1, cfptr);
		}
	}
	else printf("no logs in file!\n");
}

int main(void)
{
	FILE *fp;
	int choice;
	if((fp = fopen("accbox.dat","rb+")) == NULL){
		printf("can not open file!\n");
		exit(0);
    }
	while((choice = inputchoice()) != 0){
		switch(choice){
			case 1:
				fp = fopen("accbox.dat", "rb+");
				AddNewLog(fp);
				break;
			case 2:
				fp = fopen("accbox.dat", "rb");
				ListAllLog(fp);
				break;
			default:
				printf("Input Error."); break; 
		}
	}
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	return 0;
}
