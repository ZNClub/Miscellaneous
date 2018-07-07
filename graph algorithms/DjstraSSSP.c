/** NEVIL   DSOUZA      7059    **/
/** DJstra's Algorithm for Single Source Shortest Path  **/
/** @author:Nevil Dsouza    **/

#include<stdio.h>
#include<stdlib.h>
#define I 9999

int i,j,k;
int dist[5][10];
//hardcode
int a[10][10]={ {0,0,0,0,0,0},{0,0,10,9999,30,100},{0,9999,0,50,9999,9999},{0,9999,9999,0,9999,10},
{0,9999,9999,20,0,60},{0,9999,9999,9999,9999,0} };

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
    */

}

void display(int a[10][10],int dist[5][10],int v,int s[],int q[]){
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
    printf("\n\n\n\n\n");
}
void compute(int a[10][10],int dist[5][10],int v){
    int source;
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

    display(a,dist,v,s,q);

    for(k=2;k<=v;k++){

        int min=9999;
        for(i=1;i<=v;i++){
            if(dist[3][i]<min && dist[4][i]!=1){
                min=dist[3][i];
                s[k]=i;
            }
        }
        dist[4][s[k]]=1;
        q[s[k]]=0;

        for(i=1;i<=v;i++){
            if(a[s[k]][i]==0 || a[s[k]][i]==9999){
                continue;
            }
            if(dist[3][i]>(a[s[k]][i]+dist[3][s[k]])){
                dist[3][i]=(a[s[k]][i]+dist[3][s[k]]);
                dist[1][i]=s[k];
            }
        }
        display(a,dist,v,s,q);
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
6
Enter
Source(s)       Destination(d)  Weight(w)

Enter Source
1

         0        10      9999        30       100
      9999         0        50      9999      9999
      9999      9999         0      9999        10
      9999      9999        20         0        60
      9999      9999      9999      9999         0
S={         1         0         0         0         0   }
Q={         0         2         3         4         5   }

predecessor              0         1         1         1         1
vertice                  1         2         3         4         5
cost                     0        10      9999        30       100
visited                  1         0         0         0         0





         0        10      9999        30       100
      9999         0        50      9999      9999
      9999      9999         0      9999        10
      9999      9999        20         0        60
      9999      9999      9999      9999         0
S={         1         2         0         0         0   }
Q={         0         0         3         4         5   }

predecessor              0         1         2         1         1
vertice                  1         2         3         4         5
cost                     0        10        60        30       100
visited                  1         1         0         0         0





         0        10      9999        30       100
      9999         0        50      9999      9999
      9999      9999         0      9999        10
      9999      9999        20         0        60
      9999      9999      9999      9999         0
S={         1         2         4         0         0   }
Q={         0         0         3         0         5   }

predecessor              0         1         4         1         4
vertice                  1         2         3         4         5
cost                     0        10        50        30        90
visited                  1         1         0         1         0





         0        10      9999        30       100
      9999         0        50      9999      9999
      9999      9999         0      9999        10
      9999      9999        20         0        60
      9999      9999      9999      9999         0
S={         1         2         4         3         0   }
Q={         0         0         0         0         5   }

predecessor              0         1         4         1         3
vertice                  1         2         3         4         5
cost                     0        10        50        30        60
visited                  1         1         1         1         0





         0        10      9999        30       100
      9999         0        50      9999      9999
      9999      9999         0      9999        10
      9999      9999        20         0        60
      9999      9999      9999      9999         0
S={         1         2         4         3         5   }
Q={         0         0         0         0         0   }

predecessor              0         1         4         1         3
vertice                  1         2         3         4         5
cost                     0        10        50        30        60
visited                  1         1         1         1         1


*/













