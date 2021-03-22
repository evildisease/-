#include<map>
#include<stdio.h>
using namespace std;
const int maxn=1e6+10;

int T[maxn],n;
map<int,int>mp;
int Binary_Search(int x){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(T[mid]==x){
			return mid;
		}
		else if(T[mid]>x){
			r=mid-1;
		}
		else l=mid+1;
	}
	return 0;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&T[i]);
		mp[T[i]]=i;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		printf("Binary Search:\n");
		printf("j==%d\n",Binary_Search(x));
		printf("Hash_Search:\n");
		printf("j==%d\n",mp[x]);
	}
	return 0;
}
