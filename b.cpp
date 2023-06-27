#include<stdio.h>
#define MAX 65536 //误码id范围1~65535 
int getResult(int a[]);
int arrLen(int a[],int m,int n);

int main() {
	int n;//误码总数，0-255
	scanf("%d",&n);
	if(n==0) printf("0");
	else {
		int a[n+1];//误码频度数组
		a[0]=n;//a[0]存数组长度
		int i=0;
		for(i=1; i<n+1; i++) scanf("%d",&a[i]);
//		while(scanf("%d",&a[++i])!=EOF && getchar()!='\n') {	}
		getResult(a);
	}
	return 0;
}


int getResult(int a[]) {
	int b[MAX]= {0}; //计数数组
	//扫描a,计数存入b
	for(int i = 1; i <= a[0]; i++) {
		b[a[i]] ++;
//		printf("b[%d]:%d ", a[i],b[a[i]]);
	}
	//找出频度最高的数
	int max=0;//最高频度
	int maxi;//最高频度对应的位置
	for(int i=1; i<MAX; i++) {
		if(b[i]==max && max!=0) {
			if(arrLen(a,i,b[i]) < arrLen(a,maxi,b[maxi])) {
				max=b[i];
				maxi=i ;
			}
		} 
		else if(b[i]>max) {
			max=b[i];
			maxi=i;
		}
	}
	printf("%d",arrLen(a,maxi,b[maxi])) ;
	return 0;
}

//获取子数组长度
int arrLen(int a[],int m,int n) { //n是频度 m是要找的数
	int len=0;//子数组的长度
	int flag=0;//是否找到第一个元素
	for(int i=1; i<=a[0] && n>0; i++) {
		if(a[i]==m) {
			n--;
			if(!flag) flag=1;
			if(flag) len++;
		} else {
			if(flag) len++;
		}

	}
	return len;
}
