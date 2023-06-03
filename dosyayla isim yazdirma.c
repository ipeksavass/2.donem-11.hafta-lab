#include <stdio.h>
#include <stdlib.h>
 int main(void){
 	char ismim[20];
 	FILE *mfPtr;
 	if((mfPtr = fopen("ismim.dat","w")) == NULL)
 		printf("dosya acilamadi");
 	else
 	{
 		printf("isminizi giriniz:\n");
 		printf("veri girisini sonlandirmak icin EOF gir\n"); //EOF = ctrl+z
 		printf("?\n");
 		scanf("%s",ismim);
 		
 		while(!feof(stdin))
 		{
 			fprintf(mfPtr,"%s\n",ismim);
 			printf("?\n");
 			scanf("%s",ismim);
		}
		fclose(mfPtr);
	}
	return 0;
 }
