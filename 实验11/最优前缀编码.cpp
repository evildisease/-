#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
#define speed(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define ll long long
const int maxn=3e5+10;
const int inf=0x3f3f3f3f;
const int INF=1ll<<62;

int n,a;
priority_queue<int, vector<int>, greater<int> >qu;
queue<int>res;

void slove(){
	while(qu.size()!=1){
		int a=qu.top();
		qu.pop();
		int b=qu.top();
		qu.pop();
		int c=a+b;
		res.push(a);
		res.push(b);
		qu.push(c);
	}
	printf("��������Ϊ:\n");
	while(!res.empty()){
		printf("����%lld��",res.front());
		res.pop();
		printf("%lld\n",res.front());
		res.pop();
	}
	printf("���ս��Ϊ:%lld\n",qu.top()); 
}

signed main() {
	speed();
	printf("��������n\n");
	cin>>n;
	printf("������ÿһ���ַ���Ƶ��:\n");
	for(int i=1;i<=n;i++){
		cin>>a;
		qu.push(a);
	}
	slove();
	return 0;
}
