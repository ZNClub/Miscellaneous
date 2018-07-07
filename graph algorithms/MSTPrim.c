/**  NEVIL   DSOUZA      7059    **/
/**  MST by Prim's Alogrithm     **/
/**  i adjacent to k     dist[k]=min{dist[k],dist[i]+cost(i,k)}  **/
/**  @author:Nevil Dsouza     **/

#include<stdio.h>
#include<stdlib.h>
#define I 9999

int i,j,k;
int dist[5][10];

//hardcode
//int a[10][10]={0};
int a[10][10]={ {0,0,0,0,0,0,0},{0,0,6,3,9999,9999,9999},{0,6,0,2,5,9999,9999},{0,3,2,0,3,4,9999},
{0,9999,5,3,0,2,3},{0,9999,9999,4,2,0,5},{0,9999,9999,9999,3,5,0}   };


void read(int a[10][10],int v,int e){

    printf("Enter\nSource(s)\tDestination(d)\tWeight(w)\n");
    int ro,co,we;
    /*
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            if(i==j)   {
            a[i][j]=0;
            }
            else{
            a[i][j]=I;
            }
        }
    }
    for(i=1;i<=e;i++){
        printf("\ns=");
        scanf("%d",&ro);
        printf("\nd=");
        scanf("%d",&co);
        printf("\nw=");
        scanf("%d",&we);
        a[ro][co]=a[co][ro]=we;
    }

    /*
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            if(i==j)    {   a[i][j]=0;continue;}
            printf("Enter cost for [%d][%d]",i,j);
            scanf("%d",&a[i][j]);
        }
    }*/
}
void display(int a[10][10],int dist[5][10],int v,int s[],int q[],int cost){
    for(i=1;i<=v;i++){

        printf("\n");
        for(j=1;j<=v;j++){
            printf("%10d",a[i][j]);
        }
    }

    printf("\nS={");
    for(j=1;j<=v;j++){
        printf("%10d",s[j]);
    }

    printf("\t}\nQ={");
    for(j=1;j<=v;j++){
        printf("%10d",q[j]);
    }

    printf("\t}\n\npredecessor\t");
    for(j=1;j<=v;j++){
        printf("%10d",dist[1][j]);
    }

    printf("\nvertice\t\t");
    for(j=1;j<=v;j++){
        printf("%10d",dist[2][j]);
    }

    printf("\ncost\t\t");
    for(j=1;j<=v;j++){
        printf("%10d",dist[3][j]);
    }

    printf("\nvisited\t\t");
    for(j=1;j<=v;j++){
        printf("%10d",dist[4][j]);
    }
    printf("\n\n\tC O S T = %d\n\n\n",cost);
}
void compute(int a[10][10],int dist[5][10],int v){
    int source,cost=0;
    int q[v+1],s[v+1];

    printf("\nEnter Source\n");
    scanf("%d",&source);
    s[1]=source;
    for(i=1;i<=v;i++)   {
        if(i==source){
            dist[1][i]=0;
            q[i]=0;
            dist[2][i]=i;
            dist[3][i]=0;
            dist[4][i]=1;
        }
        else{
        dist[1][i]=source;
        q[i]=dist[2][i]=i;
        dist[3][i]=a[source][i];
        s[i]=dist[4][i]=0;
        }

    }

    display(a,dist,v,s,q,cost);

    for(k=2;k<=v;k++){

        int min=9999;
        for(i=1;i<=v;i++){
            if(dist[3][i]<min && dist[4][i]!=1){
                min=dist[3][i];
                s[k]=i;
            }
        }
        cost+=dist[3][s[k]];
        dist[4][s[k]]=1;
        q[s[k]]=0;

        for(i=1;i<=v;i++){
            if(a[s[k]][i]==0 || a[s[k]][i]==9999){
                continue;
            }
            if(dist[3][i]>a[s[k]][i] && dist[4  ][i]!=1){
                dist[3][i]=a[s[k]][i];
                dist[1][i]=s[k];
            }
        }
        display(a,dist,v,s,q,cost);
    }

}

int main(){
    int ve,ed;
    printf("Enter no of vertices and edges\n");
    scanf("%d%d",&ve,&ed);

    read(a,ve,ed);

    compute(a,dist,ve);

    return 0;

}
/*

Enter no of vertices and edges
5
7
Enter
Source(s)       Destination(d)  Weight(w)

Enter Source
1

         0         6         3      9999      9999
         6         0         2         5      9999
         3         2         0         3         4
      9999         5         3         0         2
      9999      9999         4         2         0
S={         1         0         0         0         0   }
Q={         0         2         3         4         5   }

predecessor              0         1         1         1         1
vertice                  1         2         3         4         5
cost                     0         6         3      9999      9999
visited                  1         0         0         0         0

        C O S T = 0



         0         6         3      9999      9999
         6         0         2         5      9999
         3         2         0         3         4
      9999         5         3         0         2
      9999      9999         4         2         0
S={         1         3         0         0         0   }
Q={         0         2         0         4         5   }

predecessor              0         3         1         3         3
vertice                  1         2         3         4         5
cost                     0         2         3         3         4
visited                  1         0         1         0         0

        C O S T = 3



         0         6         3      9999      9999
         6         0         2         5      9999
         3         2         0         3         4
      9999         5         3         0         2
      9999      9999         4         2         0
S={         1         3         2         0         0   }
Q={         0         0         0         4         5   }

predecessor              0         3         1         3         3
vertice                  1         2         3         4         5
cost                     0         2         3         3         4
visited                  1         1         1         0         0

        C O S T = 5



         0         6         3      9999      9999
         6         0         2         5      9999
         3         2         0         3         4
      9999         5         3         0         2
      9999      9999         4         2         0
S={         1         3         2         4         0   }
Q={         0         0         0         0         5   }

predecessor              0         3         1         3         4
vertice                  1         2         3         4         5
cost                     0         2         3         3         2
visited                  1         1         1         1         0

        C O S T = 8



         0         6         3      9999      9999
         6         0         2         5      9999
         3         2         0         3         4
      9999         5         3         0         2
      9999      9999         4         2         0
S={         1         3         2         4         5   }
Q={         0         0         0         0         0   }

predecessor              0         3         1         3         4
vertice                  1         2         3         4         5
cost                     0         2         3         3         2
visited                  1         1         1         1         1

        C O S T = 10

*/














