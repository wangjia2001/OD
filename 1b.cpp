//n��ľ�壬��i�鳤��ai
//����mľ�ϣ� �����п�ƴ��ľ��
//Ҫ����̵�ľ�御�������ӳ��������ľ��ĳ��� 
//���룺�������� n��1-1000��,m ��1-10^6�� 
//      n����������a1,a2,..��1-10^6�� 
//�����һ�������������ľ��ĳ��������� 

//̰�ģ���������̰壬ÿ�θ���̵ļ�

#include<stdio.h>
#include<stdlib.h>

int complement(int m, int n, int a[]);
int complement1(int m, int n, int a[]);
int cmp(const void *a,const void *b){
	return (*(int*)a-*(int *)b);
}

int main(){
	int m,n;
	scanf("%d %d",&n,&m);
//	getchar();
	int i = 0;
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	printf("%d",complement(m, n, a));
	return 0;
} 

//ʱ�临�Ӷ�O(m) 
int complement(int m, int n, int a[]){
	//����
	qsort(a,n,sizeof(a[0]),cmp);//�������� 
	int i = 0;
	while(m > 0){
        if((i == n) || (a[i] >= a[0] && i != 0)){
//if( (a[i] >= a[0] && i != 0)){
            i = 0;
        }else{
            a[i]++;
//            printf("i:%d   ",i);
//            for(int i = 0; i < n; i++){
//		        printf("%d ",a[i]);
//	        }
//            printf("\n");
            m--;
            i++;
        }
    }
    if (i == n) return a[0];
	return a[i];
}


//O(n)
int complement1(int m, int n, int a[]){
	//�������ӣ�ֵ��ͬ��ͬʱ��� 
}