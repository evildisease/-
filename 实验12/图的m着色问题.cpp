#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
#define speed(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define ll long long
const int maxn=3e2+10;
const int inf=0x3f3f3f3f;
const int INF=1ll<<62;

int a,b,n,res,m;
int graph[maxn][maxn],color[maxn];

bool ok(int i) {
	for(int j=1; j<=n; j++) {
		if(graph[i][j]&&color[i]==color[j]) {
			return false;
		}
	}
	return true;
}

int number=1;
void dfs(int cur) {
	if(cur>n) {
		printf("����%lld:",number++);
		for(int i=1; i<=n; i++) {
			printf("%lld ",color[i]);
		}
		res++;
		printf("\n");
	} else {
		for(int i=1; i<=m; i++) {
			color[cur]=i;
			if(ok(cur)) {
				dfs(cur+1);
			}
			color[cur]=0;
		}
	}
}

/*
��һ���Ƕ���ĸ���n����ɫ��m��1��m��n����
�������Ƕ���֮����໥��ϵ��a b
��ʾa��b���ڡ���a��bͬʱΪ0ʱ��ʾ���������
*/

signed main() {
	speed();
	memset(graph,0,sizeof graph);
	printf("�������n����ɫ��m:\n");
	cin>>n>>m;
	printf("������ÿһ���ߵĶ���:\n");
	for(int i=1;; i++) {
		cin>>a>>b;
		if(a==0&&b==0)break;
		graph[a][b]=1;
		graph[b][a]=1;
	}
	dfs(1);
	if(res==0)printf("No\n");
	else printf("Total=%lld\n",res);
	return 0;
}
