#include<bits/stdc++.h>
using namespace std;

void swap(int root[],int a,int b) {
	int temp=root[a];
	root[a]=root[b];
	root[b]=temp;
}

int a[2];

void partation(int root[],int begin,int end,int number) { //�����number�ķ�Χ
	int less=begin-1;
	int more=end+1;
	int pos=begin;
	while (pos<more) {
		if(root[pos]<number) {
			less++;
			swap(root,pos,less);//��С������ǰ�� 
			pos++;
		} else if(root[pos]==number)
			pos++;
		else {
			more--;
			swap(root,pos,more);//��������ź��� 
		}
	}
	a[0]=less+1; 
	a[1]=more-1;
	//ȷ����Χ 
}

int getMedian(int root[],int beginI,int endI) { //����λ��
	sort(root+beginI,root+endI+1);
	int sum=beginI+endI;
	int mid=(sum/2)+(sum%2);//ȷ��ż������ʱ������м��������ĺ�һ��
	return root[mid];
}

int bfprt(int root[],int begin,int end,int k);
int medianOfMedians(int root[],int beginI,int endI) { //��ÿ��С���ڵ���λ��
	int num=endI-beginI+1;
	int offset=num%5==0?0:1;//����5��Ҳ����ֳ�һ��С��
	int range=num/5+offset;
	int median[range+10];
	for(int i=1; i<=range; i++) {
		int start=beginI+(i-1)*5;
		int finish=start+4;
		median[i]=getMedian(root,start,min(endI,finish));//���������λ�� 
	}
	return bfprt(median,1,range,range/2);
}

int bfprt(int root[],int begin,int end,int k) {
	if(begin==end)//������ֻ��һ����ʱ��ֱ�ӷ���
		return root[begin];
	int divide=medianOfMedians(root,begin,end);
	partation(root,begin,end,divide);
	if(k>=a[0]&&k<=a[1])//�����Ҫ����������ڵ�������ֱ�ӷ���
		return root[k];
	else if(k<a[0])//��ʱ����Ҫ�ҵ�����divideС���ݹ���ǰ�벿��
		return bfprt(root,begin,a[0]-1,k);
	else if(k>a[1])//��ʱ����Ҫ�ҵ�����divide�󣬵ݹ����벿��
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


