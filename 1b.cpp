//n块木板，第i块长度ai
//长度m木料， 任意切块拼接木板
//要求最短的木板尽量长，加长后求最短木板的长度 
//输入：两个整数 n（1-1000）,m （1-10^6） 
//      n个正整数，a1,a2,..（1-10^6） 
//输出：一个正整数：最短木板的长度最大多少 

//贪心，尽量补足短板，每次给最短的加

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

//时间复杂度O(m) 
int complement(int m, int n, int a[]){
	//排序
	qsort(a,n,sizeof(a[0]),cmp);//板子升序 
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
	//调整板子，值相同的同时相加 
}
