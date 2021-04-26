#include<bits/stdc++.h>

using namespace std;
const int maxn=1e4+10;

int m,n;
int f[maxn][maxn];
int F[maxn][maxn];

void slove(){
	memset(F,0,sizeof F);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=j;k++){
				if(f[i][k]+F[i-1][j-k]>F[i][j]){
					F[i][j]=f[i][k]+F[i-1][j-k];
				}		
			}
		}
	} 
}
void print(){
	for(int i=0;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",F[j][i]);
		}
		printf("\n");
	}
}
int main(){
	scanf("%d %d",&m,&n);
	memset(f,0,sizeof f);
	for(int i=0;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>f[j][i];
		}
	}
	slove();
	print();
	return 0;
} 

//
//5 4
//0 0 0 0
//11 0 2 20
//12 5 10 21
//13 10 30 22
//14 15 32 23
//15 20 40 24
