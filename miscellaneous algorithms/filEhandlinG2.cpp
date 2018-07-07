#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int weekday;
    int shift;
    int prodqty;
    int defect;

}shift_rec;


int main(){
    int i,j;
    shift_rec vshift;
    FILE *fp;
    fp=fopen("weekrec.dat","rb");
    if(fp==NULL){
        printf("ERROR");
        exit(1);

    }
    fseek(fp,-sizeof(shift_rec),2);
    printf("DAY\tSHIFT\tQTY\tDEFECT\n");
    for(i=1;i<=7;i++){
        for(j=1;j<=3;j++){
            fread(&vshift,sizeof(shift_rec),1,fp);
            printf("\n%d\t%d\t%d\t%d\t",vshift.weekday,vshift.shift,vshift.prodqty,vshift.defect);
            fseek(fp,(-2*sizeof(shift_rec)),1);

        }
    }
    printf("\n");
    fclose(fp);
    return 0;
}

