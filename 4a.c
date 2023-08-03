/*
二维天线矩阵，天线只能接受发送向东向南的信号
每根天线高度为anth（整数）存在二维数组中
某一方向，某根天线可以接收多跟其他天线信号，X能收到Y的条件：
1.X在Y的东边或南边
2.X Y之间无遮挡或XY中间的都低于XY
给出m行n列矩阵，矩阵存储高度，求出每根天线可以接收到多少根其他的信号
*/

/*
输入：m n 
    anth[0][0]...anth[m-1][n-1](10^5>anth>0)
输出：m n 
    ret[0][0]...ret[m-1][n-1]
*/

/*思路：找到anth[i][j]能接收的天线----确定向东接收信号数量*/
// 三重循环，待优化


#include<stdio.h>
#include<stdlib.h>

int m,n;
int i,j;
int GetRet(int **anth);

int main(){
    scanf("%d %d",&m,&n);
    int **anth = (int**)malloc(sizeof(int*)*m);
    for(i = 0; i < m; i++){
        anth[i] = (int*)malloc(sizeof(int)*n);
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&anth[i][j]);
        } 
    }

    GetRet(anth);
}

int GetRet(int **anth){
    int ret[m][n];//ret初值为0
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            ret[i][j] = 0;
        }
    }

    int k,max;
    //横向计算ret[][],对每一个anth[i][j]找出东边的接收点
    for(i = 0; i < m; i++){
        for(j = 0; j < n-1; j++){
            k = j + 1;
            max = 0;
            while ((k < n) && (anth[i][j] > max))//(anth[i][j] < max时，后面的天线不能再接受信号
            {
                if(anth[i][k] > max){
                    ret[i][k] ++;
                    max = anth[i][k];
                    // printf("i:%d j:%d k:%d max:%d",i,j,k,max);
                }
                k++;
            }            
        }
        // printf("第i行ret数组:");
        // for( j = 0; j < n; j++){
        //     printf("%d ",ret[i][j]);
        // }
        // printf("\n");
    }

    //纵向计算ret[][]
    for(j = 0; j < n; j++){
        for(i = 0; i < m-1; i++){
            k = i + 1;
            max = 0;
            while ((k < m) && (anth[i][j] > max))//(anth[i][j] < max时，后面的天线不能再接受信号
            {
                if(anth[k][j] > max){
                    ret[k][j] ++;
                    max = anth[k][j];
                }
                k++;
            }  
        }
        // printf("第j列ret数组:");
        // for( i = 0; i < m; i++){
        //     printf("%d ",ret[i][j]);
        // }
        // printf("\n");
    }

    printf("%d %d\n",m,n);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%d ",ret[i][j]);
        }
    }

    return 0;
}