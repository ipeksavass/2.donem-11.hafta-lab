#include <stdio.h>
#include <stdlib.h>
 int main(void){
 	char ismim[20];
 	FILE *mfPtr;
 	if((mfPtr = fopen("ismim.txt","w")) == NULL)
 		printf("dosya acilamadi");
 	else
 	{
 		printf("isminizi giriniz:\n");
 		gets(ismim);
		fprintf(mfPtr,"%s",ismim);
		fclose(mfPtr);
	}
	return 0;
 }
