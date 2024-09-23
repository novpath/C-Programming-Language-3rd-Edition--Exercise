/*cashbox.dat是随机文件，记录资金账户消费流水账记录信息*/
/*程序的功能：添加新流水账记录，查询资金账户最后余额*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
long size;				/*用来保存sizeof(struct LogData)*/
struct LogData{			/*用来记录结构*/
	long logid;			/*记录ID*/
	char logdate[11];	/*记录发生日期*/
	char lognote[15];	/*记录事件说明*/
	double charge;		/*发生费用：负表示支出，正表示收入*/
	double balance;		/*余额*/ 
};

int inputchoice()				/*选择操作函数*/
{
	int mychoice;
	printf("\n");
	printf("      Personal Cashbox Management\n");
	printf("     =============================                   \n");
	printf("      1 - Add a new cash log.\n      2 - List all cash log.\n");
	printf("      3 - Query last cash log.\n      4 - Update a cash log.\n");
	printf("      5 - Delete a cash log.\n      0 - End program.\n"); 
	printf("\n");
	printf("   Enter your choice:");
	scanf("%d",&mychoice);
	return mychoice;
}

long getLogcount(FILE *cfptr)	/*获取文件记录总数*/
{
	long begin, end, logcount;
	fseek(cfptr, 0L, SEEK_SET);
	begin = ftell(cfptr);
	fseek(cfptr, 0L, SEEK_END);
	end = ftell(cfptr);
	logcount = (end - begin) / size;
	return logcount;
}

void ListAllLog(FILE *cfptr)	/*列出所有收支流水账*/
{
	struct LogData log;
	long logcount;
	logcount = getLogcount(cfptr);
	if(logcount > 0)
	{
		fseek(cfptr, 0L, SEEK_SET);
		fread(&log, size, 1, cfptr);
		printf("LogID  LogDate      LogNote            Charge     Balance\n");
		while(!feof(cfptr)){
		printf("%6ld  %-12s %-15s %10.2lf %10.2lf\n", log.logid, log.logdate, log.lognote, log.charge, log.balance);
		fread(&log, size, 1, cfptr);
		}
	}
	else printf("no logs in file!\n");
}

void QueryLastLog(FILE *cfptr)	/*查询显示最后一条记录*/
{
	struct LogData log;
	long logcount;
	logcount = getLogcount(cfptr);
	if(logcount > 0)
	{
		fseek(cfptr, size * (logcount - 1), SEEK_SET);
		fread(&log, size, 1, cfptr);
		printf("The last log is:\n");
		printf("            LogID:%-6ld\n             LogDate:%-11s\n             LogNote:%-15s\n", log.logid, log.logdate, log.lognote);
		printf("            Charge:%-10.2lf\n           *Balance:%-10.2lf\n", log.charge, log.balance);	
	}
	else printf("no logs in file!\n");
}

void AddNewLog(FILE *cfptr)		/*添加新纪录*/
{
	struct LogData log, lastlog;
	long logcount;
	printf("Input logdate (format:2006-01-01):");
	scanf("%s", log.logdate);
	printf("Input lognote:");
	scanf("%s", log.lognote);
	printf("Input Charge: Income+ and expend-:");
	scanf("%lf", &log.charge);
	logcount = getLogcount(cfptr);
	
	if(logcount > 0){
		fseek(cfptr, size * (logcount - 1), SEEK_SET);
		fread(&lastlog, size, 1, cfptr);
		log.logid = lastlog.logid + 1;
		log.balance = log.charge + lastlog.balance;
	}
	else{
		log.logid = 1;
		log.balance = log.charge;
	}
	rewind(cfptr);
	printf("logid = %ld\n", log.logid);
	fwrite(&log, sizeof(struct LogData), 1, cfptr);
	fclose(cfptr);
}

void UpdateLog(FILE *cfptr)		/*查询记录 ID 并更新账户记录*/
{
	struct LogData log, newlog;
	long logid;
	int logidcount = getLogcount(cfptr);
	printf("Input LogID:"); 
	scanf("%ld", &logid);			
	rewind(cfptr);
	fseek(cfptr, (logid - 1) * size, SEEK_SET);
	fread(&log, size, 1, cfptr);
	if(log.logid == logid)
	{
		printf("LogID  LogDate      LogNote            Charge     Balance\n");/*显示当前记录*/
		printf("%5ld  %-12s %-15s %10.2lf %10.2lf\n",
		log.logid, log.logdate, log.lognote, log.charge, log.balance);
		newlog.logid = log.logid;
		printf("Input logdate (format:2006-01-01):");
		scanf("%s", newlog.logdate); 
		printf("Input lognote:");
		scanf("%s", newlog.lognote); 
		printf("Input Charge:Income+ and expend-:");
		scanf("%lf", &newlog.charge);
		newlog.balance = log.balance - log.charge + newlog.charge;
		fseek(cfptr, (logid - 1) * size, SEEK_SET);
		fwrite(&newlog, sizeof(struct LogData), 1, cfptr);
		fseek(cfptr, (logid - 1) * size, SEEK_SET);
		while(logid < logidcount){
			fread(&log, size, 1, cfptr);
			fread(&newlog, size, 1, cfptr);
			newlog.balance = log.balance + newlog.charge;
			fseek(cfptr, logid * size, SEEK_SET);
			fwrite(&newlog, sizeof(struct LogData), 1, cfptr);
			fseek(cfptr, logid * size, SEEK_SET);
			logid ++;
		}
	}
	else 
		printf("Error logid!\n");
	rewind(cfptr);
	fclose(cfptr);
}

void DeleteLog(FILE *cfptr)			/*删除记录 ID 并更新账户记录*/
{
	struct LogData log, nextlog;
	long logid;
	int logidcount = getLogcount(cfptr);
	char ch;
	printf("Input LogID needs to Delete:"); 
	scanf("%ld", &logid);			
	rewind(cfptr);
	fseek(cfptr, (logid - 1) * size, SEEK_SET);
	fread(&log, size, 1, cfptr);
	if(log.logid == logid)
	{
		printf("LogID  LogDate      LogNote            Charge     Balance\n");
		printf("%5ld  %-12s %-15s %10.2lf %10.2lf\n",
		log.logid, log.logdate, log.lognote, log.charge, log.balance);
		printf("Confirm to delete?(Y/N)\n");
		getchar();
		if((ch = getchar()) == 'Y')
		{
			while(logid < logidcount)
			{
				fseek(cfptr, (logid - 1) * size, SEEK_SET);
				fread(&log, size, 1, cfptr);
				fread(&nextlog, size, 1, cfptr);
				if(nextlog.logid == 0)
					break;
				nextlog.logid = log.logid;
				fseek(cfptr, (logid - 1) * size, SEEK_SET);
				fwrite(&nextlog, sizeof(struct LogData), 1, cfptr);
				logid ++;
			}
			fseek(cfptr, (logid - 1) * size, SEEK_SET);
			log.balance = 0;
			log.charge = 0;
			log.logid = 0;
			strcpy(log.logdate, "0000-00-00");
			strcpy(log.lognote, "0");
			fwrite(&log, sizeof(struct LogData), 1, cfptr);
		}
		else
			fclose(cfptr);
	}
	else
		printf("Error logid!\n");
	rewind(cfptr);
	fclose(cfptr);
}

int main(void)
{
	FILE *fp;
	int choice;
	size = sizeof(struct LogData);
	if((fp = fopen("cashbox.dat","ab+")) == NULL){
		printf("can not open file cashbox.dat!\n");
		exit(0);
    }
	while((choice = inputchoice()) != 0){
		switch(choice){
			case 1:
				fp = fopen("cashbox.dat", "ab+");
				AddNewLog(fp);
				break;
			case 2:
				fp = fopen("cashbox.dat", "rb");
				ListAllLog(fp);
				break;
			case 3:
				fp = fopen("cashbox.dat", "rb");
				QueryLastLog(fp);
				break;
			case 4:
				fp = fopen("cashbox.dat", "rb+");
				UpdateLog(fp);
				break;
			case 5:
				fp = fopen("cashbox.dat", "rb+");
				DeleteLog(fp);
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
