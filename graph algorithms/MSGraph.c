/* Multi Stage Graph : Min Cost SOURCE to DESTINATION */

#include<stdio.h>
#include<stdlib.h>
#define S 10
#define I 9999

typedef struct{
    int no;
    int stage;
    int cost;
}node;

typedef struct{
    int src;
    int des;
    int wt;
}edge;

edge e[S];
node nd[S];
int i,j,k,source,destination,stages,ed,ve,stage_i;

void displayN(){

    printf("\nsource\t%d",source);
    printf("\ndestination\t%d",destination);

    printf("\nNODE NO\tSTAGE\tCOST\n");
    for(i=1;i<=ve;i++){
        printf("%d\t%d\t%d\n",nd[i].no,nd[i].stage,nd[i].cost);
    }

}


void read(){

    printf("\nEnter SOURCE in STAGE 1_\n");
    scanf("%d",&source);

    printf("\nEnter DESTINATION in STAGE %d_\n",stages);
    scanf("%d",&destination);

    for(i=1,k=1;i<=stages;i++){
        printf("\nEnter no of nodes in STAGE %d\n",i);
        scanf("%d",&stage_i);
        for(j=1;j<=stage_i && k<=ve;j++,k++){
            printf("\tenter node %d\n",j);
            scanf("%d",&nd[k].no);
            nd[k].stage=i;
            nd[k].cost=0;
        }

    }

    printf("Enter\nSource(s)\tDestination(d)\tWeight(w)\n");


    for(i=1;i<=ed;i++){
        /*printf("\ns=");
        scanf("%d",&e[i].src);
        printf("\nd=");
        scanf("%d",&e[i].des);
        printf("\nw=");
        scanf("%d",&e[i].wt);
        */
        e[i].src=so[i];
        e[i].des=de[i];
        e[i].wt=we[i];

    }


}

int main(){

    printf("Enter No of Nodes and Edges and Stages of graph\n");
    scanf("%d%d%d",&ve,&ed,&stages);

    read();

    displayN();


    return 0;
}
