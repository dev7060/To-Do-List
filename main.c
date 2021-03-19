#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//244 to be done
//245 deleted
struct entry{
	int day;
	int month;
	int year;
	int status;
	char name[1000];	
}obj;
int main(){
	system("title To-Do by github.com/dev7060");
	system("color 03");
	int ch;
	while(1){
		system("cls");
		printf("1) add 2) delete 3) view\n\n$ ");
		scanf("%d", &ch);
		if(ch==1){
			system("cls");
			time_t now;
			time(&now);
			struct tm *local = localtime(&now);
    		obj.day = local->tm_mday;
    		obj.month = local->tm_mon+1;
    		obj.year = local->tm_year+1900;
    		FILE *fp=fopen("data", "a");
    		obj.status=244;
    		printf("name: ");
    		scanf("%s", &obj.name);
    		fprintf(fp, "%s %d %d %d %d\n", obj.name, obj.day, obj.month, obj.year, obj.status);
    		fclose(fp);
    		system("pause");
		}else if(ch==2){
			system("cls");
			FILE *fp=fopen("data", "r");
			FILE *fp2=fopen("temp", "w");
			char ch[1000];
			printf("Input name: ");
			scanf("%s", &ch);
			while(fscanf(fp, "%s %d %d %d %d\n", &obj.name, &obj.day, &obj.month, &obj.year, &obj.status)!=EOF){
				fprintf(fp2, "%s %d %d %d ", obj.name, obj.day, obj.month, obj.year);
				if(strcmp(obj.name, ch)==0){
					obj.status=245;
					//printf("entered");
					fprintf(fp2, "%d\n", obj.status);
				}
				else if(strcmp(obj.name, ch)!=0 && obj.status==245){
					obj.status=245;
					//printf("entered");
					fprintf(fp2, "%d\n", obj.status);
				}
				else{
					obj.status=244;
					fprintf(fp2, "%d\n", obj.status);
				}
			}
			fclose(fp); fclose(fp2);
			system("del data");
			system("ren temp data");
			system("pause");
		}else if(ch==3){
			system("cls");
			FILE *fp=fopen("data", "r");
			while(fscanf(fp, "%s %d %d %d %d\n", &obj.name, &obj.day, &obj.month, &obj.year, &obj.status)!=EOF){
				if(obj.status!=245){
					printf("Name: %s, Added on: %d-%d-%d\n", obj.name, obj.day, obj.month, obj.year);
				}
			}
			fclose(fp);
			system("pause");
		}else{
			printf("invalid choice!");
		}
	}
	return 0;
}
