#include<algorithm>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;
const int maxn=1e3+10;
const int Maxn=1e5+10;
const int inf=0x3f3f3f3f;
int a[maxn];
int n;
int dp[maxn][Maxn],dp2[Maxn];//dp[i][j] 表示前i个作业中A机器花j分钟的时候 B机器所花时间 
int vis[maxn][maxn],sum,ans,res[maxn];

void slove(){//求取最短所需最短时间
    sum=0;
    for(int i=1; i<=n; i++) {
        sum+=a[i];
        for(int j=0; j<=sum; j++) {
            dp[i][j]=dp[i-1][j]+a[i];
            if(j>=a[i]) {
                dp[i][j]=min(dp[i-1][j]+a[i],dp[i-1][j-a[i]]);
            }
        }
    }
    //max(dp[n][i],i) 表示完成前n个作业A机器花i分钟 B机器花dp[n][i]分钟情况下，最迟完工时间
    ans=inf;
    for(int i=0; i<=sum; i++)ans=min(ans,max(dp[n][i],i));
}

void show(int w){//01背包求取方案
    memset(dp,0,sizeof(dp));
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        for(int j=w;j>=a[i];j--){
            if(dp2[j]<dp2[j-a[i]]+a[i]){
               dp2[j]=dp2[j-a[i]]+a[i];
               vis[i][j]=1;
            }else vis[i][j]=0;
        }
    }
    sum=w;
    for(int i=n;i>=1;i--){
        if(vis[i][sum]){
            res[i]=1;
            sum-=a[i];
        }
    }
    printf("The tasks that A machine needs to perform are:\n");
    for(int i=1;i<=n;i++){
        if(res[i]==1)printf("%d%c",i," \n"[i == n]);
    }
    if(res[n]==0)printf("\n");
    printf("The tasks that B machine needs to perform are:\n");
    for(int i=1;i<=n;i++){
        if(res[i]==0)printf("%d%c",i," \n"[i == n]);
    }
    if(res[n]==1)printf("\n");
}

signed main() {
    printf("Please enter the total number of tasks n:\n");
    scanf("%d",&n);
    memset(dp,0,sizeof dp);
    printf("Please input the processing time of each task:\n");
    for(int i=1; i<=n; i++) scanf("%d",&a[i]); 
    slove();
    printf("The final total processing time T is:\n");
    printf("%d\n",ans);
    show(ans);
    return 0;
} 

// 5
// 1 5 2 10 3