//租车：双人自行车，最大载重M，
//给出每人体重，最少要租几辆车 
//输入：m n   自行车限重 总人数
//      n个数字   每人体重，且小于等于m
//输出：最少需要的自行车数量 
//用冒泡会超时 
#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
     return (*(int *)a - *(int *)b);
}

int main(){
	int m,n;   //m 自行车限重   n 总人数
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
		if(weight[j] + weight[i] <= m){//i j 坐一辆车 
			i++;
        } 
		count++;
        j--;
		
	}
	if(i == j){//剩一个人，单独一辆车 
		count++;
	} 
	printf("%d",count); 
	return 0;
} 
