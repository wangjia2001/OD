/*学校和学生家在一条直线上，要求到校距离和最短，求学校选址
输入：n   //1-1000,家庭数
    m    //0-10000,表示每户家庭位置，所有家庭位置不同
输出：一个整数，确定学校位置，有多个输出最小的*/

// 提示：所有数与中位数的绝对差之和最小
#include<stdio.h>
#include<stdlib.h>

int n;
int i;
int Position(int n, int m[]);
int cmp(const void *a, const void *b){
    return(*(int *)a - *(int *)b);
}

int main(){
    scanf("%d",&n);
    int m[n];
    for(i = 0; i < n; i++){
        scanf("%d",&m[i]);
    }
    Position(n, m);
    return 0 ;
}

int Position(int n,int m[]){
    qsort(m, n, sizeof(m[0]), cmp);
    printf("%d",m[(n-1)/2]);
}