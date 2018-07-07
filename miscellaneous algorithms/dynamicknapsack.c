#include<stdio.h>

typedef struct {
	int profit,weight;
}item;

int main() {
	int v[20][20]={0},keep[20][20]={0},x[20]={0};
	item itm[20];
	int n,i,m,j,a,b,z,g;
	
	printf("\nEnter number of items: ");
	scanf("%d",&n);
	printf("\nEnter capacity of knapsack: ");
	scanf("%d",&m);
	for(i=1;i<=n;i++) {
		printf("\n_________________________");
		printf("\nEnter profit: ");
		scanf("%d",&itm[i].profit);
		printf("\nEnter weight: ");
		scanf("%d",&itm[i].weight);
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) {
			if(itm[i].weight > j) {
				keep[i][j]=0;
			}else {
				a=itm[i].profit + v[i-1][j - itm[i].weight];
				b=v[i-1][j];
				if(a>b) {
					keep[i][j]=1;
					v[i][j]=a;
				}
				else {
					keep[i][j]=0;
					v[i][j]=b;
				}	 
			}
		}
	}
	g=m;
	for(i=n;i>0;i--){
		if(keep[i][g]==1) {
			x[i]=1;
			g=g-itm[i].weight;
		}else {
			x[i]=0;
		}
	}
	
	printf("\nTotal profit: %d",v[n][m]);
	printf("\nSolution vector:\n");
	for(i=1;i<=n;i++) {
		printf("%d ",x[i]);
	}
	
	return 0;
}

