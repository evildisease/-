#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define speed(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define ll long long
const int maxn=3e5+10;
const int inf=0x3f3f3f3f;
const int INF=1ll<<62;

int n,c;
int dp[maxn],w[maxn];
multiset<int>se;

void beg(){
	printf("这里是01背包算法：\n");
	for(int i = 1; i <= n; i++){
        for(int j = c; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + 1);
        }
    }
    printf("得到最大数量为:\n"); 
    printf("%lld\n",dp[c]);
}

void best(){
	printf("这里是贪心算法:\n");
	int res=0;
	while(c>=0&&!se.empty()){
		auto it=se.begin();
		se.erase(it);
		if(c<*it)break;
		res+=1;
		c-=*it;
	}
	printf("得到的最大数量为:\n");
	printf("%lld\n",res);
}
signed main() {
	speed();
	printf("输入数量n和最大容量c：\n");
	cin>>n>>c;
	printf("请输入每一个重物的体积:\n");
	for(int i=1;i<=n;i++){
		cin>>w[i];	
		se.insert(w[i]);
	}
	beg();
	best();
	return 0;
}
