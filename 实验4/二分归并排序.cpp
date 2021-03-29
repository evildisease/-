#include<bits/stdc++.h>
using namespace std;
#define swap(a,b) a^=b^=a^=b
const int maxn=1e6+10;

int data[maxn],temp[maxn];

void MergeSort(int *list,int l,int r,int *copy) {
	if(r-l<1)return ;
	int mid=(r+l)/2;
	MergeSort(list,l,mid,copy);
	MergeSort(list,mid+1,r,copy);
	int p1=l,p2=mid+1,p=l;
	while(p<=r) {
		if(p1>mid||(p2<=r&&list[p1]>list[p2])) {
			copy[p++]=list[p2++];
		} else {
			copy[p++]=list[p1++];
		}
	}
	for(int i=l; i<=r; i++)list[i]=copy[i];
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>data[i];
	}
	MergeSort(data,1,n,temp);
	cout<<"MergeSort:"<<endl;
	for(int i=1;i<=n;i++){
		if(i!=1)cout<<" ";
		cout<<data[i];
	}
	cout<<endl;
	return 0;
}
