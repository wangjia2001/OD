#include<stdio.h>
#define MAX 65536 //����id��Χ1~65535 
int getResult(int a[]);
int arrLen(int a[],int m,int n);

int main() {
	int n;//����������0-255
	scanf("%d",&n);
	if(n==0) printf("0");
	else {
		int a[n+1];//����Ƶ������
		a[0]=n;//a[0]�����鳤��
		int i=0;
		for(i=1; i<n+1; i++) scanf("%d",&a[i]);
//		while(scanf("%d",&a[++i])!=EOF && getchar()!='\n') {	}
		getResult(a);
	}
	return 0;
}


int getResult(int a[]) {
	int b[MAX]= {0}; //��������
	//ɨ��a,��������b
	for(int i = 1; i <= a[0]; i++) {
		b[a[i]] ++;
//		printf("b[%d]:%d ", a[i],b[a[i]]);
	}
	//�ҳ�Ƶ����ߵ���
	int max=0;//���Ƶ��
	int maxi;//���Ƶ�ȶ�Ӧ��λ��
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

//��ȡ�����鳤��
int arrLen(int a[],int m,int n) { //n��Ƶ�� m��Ҫ�ҵ���
	int len=0;//������ĳ���
	int flag=0;//�Ƿ��ҵ���һ��Ԫ��
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