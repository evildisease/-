#include<bits/stdc++.h>
using namespace std;

void swap(int root[],int a,int b) {
	int temp=root[a];
	root[a]=root[b];
	root[b]=temp;
}

int a[2];

void partation(int root[],int begin,int end,int number) { //求等于number的范围
	int less=begin-1;
	int more=end+1;
	int pos=begin;
	while (pos<more) {
		if(root[pos]<number) {
			less++;
			swap(root,pos,less);//将小的数放前面 
			pos++;
		} else if(root[pos]==number)
			pos++;
		else {
			more--;
			swap(root,pos,more);//将大的数放后面 
		}
	}
	a[0]=less+1; 
	a[1]=more-1;
	//确定范围 
}

int getMedian(int root[],int beginI,int endI) { //求中位数
	sort(root+beginI,root+endI+1);
	int sum=beginI+endI;
	int mid=(sum/2)+(sum%2);//确保偶数个数时求的是中间两个数的后一个
	return root[mid];
}

int bfprt(int root[],int begin,int end,int k);
int medianOfMedians(int root[],int beginI,int endI) { //求每个小组内的中位数
	int num=endI-beginI+1;
	int offset=num%5==0?0:1;//不足5个也将其分成一个小组
	int range=num/5+offset;
	int median[range+10];
	for(int i=1; i<=range; i++) {
		int start=beginI+(i-1)*5;
		int finish=start+4;
		median[i]=getMedian(root,start,min(endI,finish));//求各数组中位数 
	}
	return bfprt(median,1,range,range/2);
}

int bfprt(int root[],int begin,int end,int k) {
	if(begin==end)//数组中只有一个数时，直接返回
		return root[begin];
	int divide=medianOfMedians(root,begin,end);
	partation(root,begin,end,divide);
	if(k>=a[0]&&k<=a[1])//如果需要求的数正好在等于区域，直接返回
		return root[k];
	else if(k<a[0])//此时我们要找的数比divide小，递归求前半部分
		return bfprt(root,begin,a[0]-1,k);
	else if(k>a[1])//此时我们要找的数比divide大，递归求后半部分
		return bfprt(root,a[1]+1,end,k);
}

int main() {
	int n;
	scanf("%d",&n);
	int a[100010];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int k;
	scanf("%d",&k);
	printf("%d\n",bfprt(a,1,n,k));
	return 0;
}


