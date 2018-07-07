/*@author : melwyn95   */

#include<stdio.h>
int isQempty(int a[],int n) {
	int i;
	for(i=0;i<n;i++) {
		if(a[i]!=-1)
			return 0;
	}
	return 1;
}
int search(int a[],int low,int high,int x) {
	int mid;
	mid=(low+high)/2;
	if(a[mid]==x)
		return mid;
	else {
		if(x<a[mid])
			return search(a,low,mid-1,x);
		else
			return search(a,mid+1,high,x);
	}
}
int calmin(int a[],int n) {
	int i,min,j;
	min=a[0];
	for(i=0;i<n;i++) {
		if(a[i]<min) {
			min=a[i];
			j=i;
		}
	}
	return j;
}
int min(int a,int b) {
	if(a<b)
		return a;
	else
		return b;
}
int main() {
	int S[20]={-1},Q[20]={-1},dist[20]={-1};
	int adj[20][20]={0};
	int i,j,n,wt,a,b,nodes;
	int adjacent[20]={-1};

	printf("\nEnter no  of nodes: ");
	scanf("%d",&nodes);
	printf("\nEnter no. of edges: ");
	scanf("%d",&n);

	for(i=0;i<n;i++) {
		printf("\n  Enter source node: ");
		scanf("%d",&a);
		printf("\n  Enter destination node: ");
		scanf("%d",&b);
		printf("\n  Enter weight of edge: ");
		scanf("%d",&wt);
		adj[a][b]=wt;
	}
	for(i=0;i<nodes;i++) {
		for(j=0;j<nodes;j++) {
			if(i!=j && adj[i][j]==0)
				adj[i][j]=999;
		}
	}
	for(i=0;i<nodes;i++) {
		for(j=0;j<nodes;j++) {
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter node to start: ");
	scanf("%d",&a);

	S[0]=a;
	for(i=0;i<n;i++) {
		if(i==a)
			continue;
		Q[i]=i;
	}

	for(i=0;i<nodes;i++) {
			dist[i]=adj[a][i];
	}
	i=1;
	wt=0;
	while(!isQempty(Q,nodes)) {
		int count=0,z=0;

		a=calmin(dist,nodes);
		S[i]=a;
		j=search(Q,0,nodes-1,a);
		Q[j]=-1;
		for(j=0;j<nodes;j++) {
			if(adj[a][j]!=999 && adj[a][j]!=0)
				adjacent[j]=j;
				count++;
		}
		while(count!=0) {
			dist[adjacent[z]]=min(dist[adjacent[z]],(dist[a]+adj[a][adjacent[z]]));
			z++;
			count--;
		}
		i++;
	}

	for(i=0;i<nodes;i++)
		printf("%d ",dist[i]);

	return 0;
}

