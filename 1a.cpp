//�⳵��˫�����г����������M��
//����ÿ�����أ�����Ҫ�⼸���� 
//���룺m n   ���г����� ������
//      n������   ÿ�����أ���С�ڵ���m
//�����������Ҫ�����г����� 
//��ð�ݻᳬʱ 
#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
     return (*(int *)a - *(int *)b);
}

int main(){
	int m,n;   //m ���г�����   n ������
	while(scanf("%d %d",&m,&n)!=2){ }
    // printf("%d,%d",m,n);
	int weight[n]; 
    int i = 0;
    while(scanf("%d",&weight[i]) != EOF){
        i++;
    }
    qsort(weight, n, sizeof(weight[0]), cmp);
    i = 0;
    int j = n-1, count = 0;
	while(i < j){
		if(weight[j] + weight[i] <= m){//i j ��һ���� 
			i++;
        } 
		count++;
        j--;
		
	}
	if(i == j){//ʣһ���ˣ�����һ���� 
		count++;
	} 
	printf("%d",count); 
	return 0;
} 