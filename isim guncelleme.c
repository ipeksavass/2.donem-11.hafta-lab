#include <stdio.h>
int main(){
        char ismim[20];
        FILE *mfPtr;
        if((mfPtr = fopen("ismim.txt","w")) == NULL){
                printf("dosya acilamadi\n");
                return 0;
        }
         else{
                printf("isim giriniz:");
                gets(ismim);
                fprintf(mfPtr,"%s",ismim);
                fclose(mfPtr);
          }
          printf("yeni isminizi giriniz:");
          gets(ismim);
 
           if((mfPtr = fopen("ismim.txt","r+")) == NULL){
                printf("dosya acilamadi\n");
                return 0;
          }
          
          else{
                fprintf(mfPtr,"%s",ismim);
                fclose(mfPtr);
          }
              
          return 0;
}
