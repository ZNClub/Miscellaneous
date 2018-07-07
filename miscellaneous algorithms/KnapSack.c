/**  NEVIL   DSOUZA      7059    **/
/**  Fractional KnapSack by Greedy Approach  **/
/**  @author:Nevil Dsouza     **/


#include<stdio.h>
#include<stdlib.h>

typedef struct{
    double prft,wt,pbw;
}items;

double tp;

//hardcode
double prfts[]={40.0,50.0,60.0};
double wts[]={13.0,19.0,11.0};
double cap=30;

double compute(double prfts[],double wts[],double cap){
    //prft/wt[]
    items temp;
    items it[3];
    int i;
    double iscap,fr,tp;
    iscap=cap;
    tp=0.0;

    //int pbw[4]={0};
    printf("\nPROFIT\t\tWEIGHT\t\tP / W \t\n");
    for(i=0;i<3;i++){

        it[i].prft=prfts[i];
        printf("\n%f",it[i].prft);

        it[i].wt=wts[i];
        printf("\t%f",it[i].wt);

        it[i].pbw=0.0;
        it[i].pbw=it[i].prft/it[i].wt;

        printf("\t%f",it[i].pbw);

        //sort // not possible here
        if(i!=2){
            if(it[i].pbw<it[i+1].pbw){
                temp=it[i];
                it[i]=it[i+1];
                it[i+1]=temp;
            }
        }
    }

    //greedy method
    for(i=0;i<3;i++){       //printf("\n\n%f\n",it[i].wt);
        iscap-=it[i].wt;    //printf("%d=%5f\n",i,iscap);
        if(iscap<=0){       //printf("if\n");
            return tp;
        }
        else if(iscap<1){   //printf("ELSE if\n");
            fr=iscap/cap;
            tp+=fr*it[i].prft;
        }
        else{
            fr=1.0;              // printf("ELSE\n");
            tp+=fr*it[i].prft;  //printf("%d=%5f\n",i,tp);
        }
    }
    return tp;
}

int main(){

    //call
    tp=compute(prfts,wts,cap);

    printf("\n\nTOTAL PROFIT=%2f\n",tp);

    return 0;

}
/*

PROFIT          WEIGHT          P / W

40.000000       13.000000       3.076923
50.000000       19.000000       2.631579
60.000000       11.000000       5.454545

TOTAL PROFIT=40.000000

*/
