#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define speed(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define ll long long
const int maxn=3e3+10;
const int inf=0x3f3f3f3f;
const int INF=1ll<<62;

string a,b;
int c[maxn][maxn],m[maxn][maxn];
void lcs(string a,string b) {
	printf("这里是LCS算法\n");
	int lena=a.length();
	int lenb=b.length();
	memset(c,0,sizeof c);
	for(int i=1; i<=lena; i++) {
		for(int j=1; j<=lenb; j++) {
			if(a[i-1]==b[j-1]) {
				c[i][j]=c[i-1][j-1]+1;
				m[i][j]=2;
			} else {
				if(c[i][j-1]>=c[i-1][j]) {
					c[i][j]=c[i][j-1];
					m[i][j]=0;
				} else {
					c[i][j]=c[i-1][j];
					m[i][j]=1;
				}
			}
		}
	}
	printf("结果是:%d\n",c[lena][lenb]);
	printf("操作方法是：\n");
	for(int i=0; i<=lenb; i++) {
		for(int j=0; j<=lena; j++) {
			printf("%d:",m[j][i]);
			if(m[j][i]==2)printf("删除两个 ");
			else if(m[j][i]==1)printf("删除x ");
			else printf("删除y ");
		}
		printf("\n");
	}
}

string res;
void bag(int i,int j) {
	if(i==0||j==0)return;
	if(m[i][j]==2) {
		res+=a[i-1];
		bag(i-1,j-1);
	} else if(m[i][j]==1) {
		bag(i-1,j);
	} else if(m[i][j]==0) {
		bag(i,j-1);
	}
}
signed main() {
	printf("输入字符串a:\n");
	cin>>a;
	printf("输入字符串b：\n");
	cin>>b;
	lcs(a,b);
	printf("这里是背包算法\n");
	bag(a.length(),b.length());
	reverse(res.begin(),res.end());
	cout<<"结果是："<<res<<endl;
	return 0;
}
