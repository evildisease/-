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
		printf("方案%lld:",number++);
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
第一行是顶点的个数n，颜色数m（1≤m≤n）。
接下来是顶点之间的相互关系：a b
表示a和b相邻。当a，b同时为0时表示输入结束。
*/

signed main() {
	speed();
	memset(graph,0,sizeof graph);
	printf("输入点数n和颜色数m:\n");
	cin>>n>>m;
	printf("请输入每一个边的顶点:\n");
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
