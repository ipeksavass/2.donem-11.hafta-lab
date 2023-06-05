#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	int s_id;
	char name[15];
	int midG;
	int finG;
}Student;

void createFile(){
	FILE *f;
	if((f = fopen("data.txt","w")) == NULL)
		printf("File could not be opened!\n");
	fclose(f);
}

void addRecord(){
	Student std;
	int id,me,fe;
	char n[50];
	FILE *f;
	if((f = fopen("data.txt","a+")) == NULL)
	{
		printf("File could not be opened!\n");
		return;
	}
	
	printf("Student ID: ");         scanf("%d",&std.s_id);
	
	fscanf(f,"%d%s%d%d",&id,n,&me,&fe);
	while(!feof(f)){
		if(id == std.s_id){
			printf("There is a student with given ID\n");
			fclose(f);
			return;
		}
		fscanf(f,"%d%s%d%d",&id,n,&me,&fe);
	}
	printf("Student Name: ");       scanf("%s",std.name);
	printf("Student Midterm: ");    scanf("%d",&std.midG);
	printf("Student Final: ");      scanf("%d",&std.finG);
	fprintf(f,"%d %s %d %d",std.s_id,std.name,std.midG,std.finG);
	fclose(f);
}
	
void listRecords(){
	int id,me,fe;
	char n[50];
	FILE *f;
	if((f = fopen("data.txt","r")) == NULL)
	{
		printf("File could not be opened!\n");
		return;
	}
	fscanf(f, "%d%s%d%d",&id,n,&me,&fe);
	printf("%-10s %-10s %-10s %-15s\n","ID","NAME","MIDTERM","FINAL");
	while(!feof(f)){
		printf("%-10d %-10s %-10d %-15d\n",id,n,me,fe);
		fscanf(f,"%d %s %d %d",&id,n,&me,&fe);
	}
	fclose(f);
}

void ListOver60(){
	int id,me,fe;
	char n[50];
	FILE *f;
	if((f = fopen("data.txt","r")) == NULL)
	{
		printf("File could not be opened!\n");
		return;
	}
	fscanf(f, "%d%s%d%d",&id,n,&me,&fe);
	printf("%-10s %-10s %-10s %-15s\n","ID","NAME","MIDTERM","FINAL");
	while(!feof(f)){
		if((me*0.4 + fe*0.6) >= 60){
		printf("%-10d %-10s %-10d %-15d\n",id,n,me,fe);
		}
		fscanf(f,"%d %s %d %d",&id,n,&me,&fe);
	}
	fclose(f);
}

void sepFailSuccess(){
	FILE *f, *fileS, *fileF;
	int id,me,fe;
	char n[50];
	f = fopen("data.txt","r");
	fileS = fopen("success.txt","w");
	fileF = fopen("fain.txt","w");
	fscanf(f,"%d%s%d%d",&id,n,&me,&fe);
	while(!feof(f)){
		if((me*0.4 + fe*0.6) >= 60){
			fprintf(fileS,"%d %s %d %d",id,n,me,fe);
		}
		else{
			fprintf(fileF,"%d %s %d %d",id,n,me,fe);
		}
		fscanf(f,"%d %s %d %d",&id,n,&me,&fe);
	}
	fclose(f);
	fclose(fileS);
	fclose(fileF);
	
}
int main(){
	char secim;
	while(1){
		printf("*************************************\n");
		printf("1-Create a File\n"
			   "2-Add Record\n"
			   "3-List Records\n"
			   "4-List Over 60\n"
			   "5-Separate Fail and Success\n"
			   );
		secim = getch();
		switch (secim){
			case'1':
				createFile();
				break;
			case'2':
				addRecord();
				listRecords();
				break;
			case'3':
				listRecords();
				break;
			case'4':
				ListOver60();
				break;
			case'5':
				sepFailSuccess();
				break;
		}	   
	}
}

