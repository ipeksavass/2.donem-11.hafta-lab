#include <stdio.h>
#include <stdlib.h>

int main(void){
	int hesapNo;
	char ad[10];
	double bakiye;
	FILE *mfPtr; // musteri.dat dosyasi isaretcisi
	if((mfPtr = fopen("musteri.dat","w")) == NULL)
		printf("dosya acilamadý\n");
	else{
		printf("hesap no,isim ve bakiye girin\n");
		printf("veri girisini bitirmek icin EOF girin\n");
		printf("?\n");
		scanf("%d %s %lf",&hesapNo,ad,&bakiye);
		
		while(!feof(stdin)){
			fprintf(mfPtr,"%d %d %.lf\n",hesapNo,ad,bakiye);
			printf("?\n");
			scanf("%d %s %lf",&hesapNo,ad,&bakiye);
		}
		fclose(mfPtr);
	}
	return 0;
}
