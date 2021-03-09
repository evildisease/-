#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
#define speed() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

const int maxn=1e6+100;
const int inf=0x3f3f3f3f;

struct node {
	int u,v,w;//uΪ��㣬vΪ�յ㣬wΪ���� 
	bool operator <(const node a)const {
		return a.w>w;//��С�������� 
	}
} a[maxn];//��ͼ 

int n,m,vis[maxn],len[maxn];

int Prim(int u) {
	int res=0;
	memset(vis,0,sizeof vis);
	memset(len,inf,sizeof len);
	vis[u]=1;//������ 
	for(int i=1; i<=m; i++)
		if(a[i].u==u)len[a[i].v]=a[i].w;//������� 
//	for(int i=1;i<=n;i++)cout<<len[i]<<endl;
	int flag=1;
	while(flag==1) {
		flag=0;
		int maxlen=inf,maxi=0;
		for(int i=1; i<=n; i++) {
			if(len[i]!=inf&&len[i]<maxlen&&vis[i]!=1) {
				maxlen=len[i];
				maxi=i;
				flag=1;
			}
		}//�ҵ���̾��� 
		if(flag==0)break;
		cout<<"to:"<<maxi<<" len:"<<len[maxi]<<endl;//���·�� 
		vis[maxi]=1;
		res+=len[maxi];
		for(int i=1; i<=m; i++)
			if(a[i].u==maxi)len[a[i].v]=min(a[i].w,len[a[i].v]);//���³��� 
	}
	return res;
}

void Kruskal() {
	int res;
	memset(vis,0,sizeof vis);
	sort(a+1,a+1+m);//���� 
//	for(int i=1; i<=m; i++) {
//		cout<<a[i].u<<a[i].v<<a[i].w<<endl;
//	}
	int cnt=0,now=1;
	while(cnt!=n&&now!=(m+1)){
		int u=a[now].u,v=a[now].v;
		if(vis[u]==0||vis[v]==0){
			cout<<"u:"<<u<<" v:"<<v<<" w:"<<a[now].w<<endl;//���·�� 
			res+=a[now].w;//��Ӿ��� 
			if(vis[u]==0)cnt++;
			if(vis[v]==0)cnt++;//������� 
			vis[u]++;
			vis[v]++;//��� 
		}
		now++;
	}
	cout<<"��С����Ϊ"<<res<<endl;
}

int main() {
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>a[i].u>>a[i].v>>a[i].w;
	}

	cout<<"Prim�㷨"<<endl;
	cout<<"��̾���Ϊ"<<Prim(1)<<endl;
	cout<<"Kruskal�㷨"<<endl;
	Kruskal(); 
	
	return 0;
}
//������ 
//5 7
//1 2 2
//1 5 3
//2 3 1
//2 4 2
//2 5 5
//3 4 3
//3 5 4

