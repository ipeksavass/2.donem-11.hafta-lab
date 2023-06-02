#include <stdio.h>

int main(void){
	int secim,hesapNo;
	double bakiye;
	char ad[30];
	FILE *mfPtr;
	if((mfPtr = fopen("musteri.dat","r")) == NULL)
		printf("dosya acilamadi\n");
	else
	{
		printf("Secim yapiniz\n"
			   "1-Hesapta para olmayan hesaplar\n"
			   "2-Borclu olan hesaplar\n"
			   "3-Hesapta para olan hesaplar\n"
			   "4-Cikis\n");
		scanf("%d",&secim);
		
		while(secim != 4)
		{
			fscanf(mfPtr,"%d %s %lf",&hesapNo,ad,&bakiye);
			switch(secim)
			{
				case'1':
					printf("\nPara olmayan hesaplar:\n");
					while(!feof(mfPtr))
					{
						if(bakiye == 0)
							printf("%-10d %-13s %7.2lf\n",hesapNo,ad,bakiye);
						fscanf(mfPtr,"%d %s %lf",&hesapNo,ad,&bakiye);
					}
					break;
				case '2':
					printf("\nPara olmayan hesaplar:\n");
					while(!feof(mfPtr))
					{
						if(bakiye < 0)
							printf("%-10d %-13s %7.2lf\n",hesapNo,ad,bakiye);
						fscanf(mfPtr,"%d %s %lf",&hesapNo,ad,&bakiye);
					}
					break;
				case '3':
					printf("\nHesapta para olan hesaplar:\n");
					while(!feof(mfPtr))
					{
						if(bakiye > 0)
							printf("%-10d %-13s %7.2lf\n",hesapNo,ad,bakiye);
						fscanf(mfPtr,"%d %s %lf",&hesapNo,ad,&bakiye);
					}
					break;
			}
			rewind(mfPtr);//dosyanin en basina gider
			printf("?\n");
			scanf("%d",&secim);
		}
		printf("Program sonlandi\n");
		fclose(mfPtr);
	}
}
