/*静态扫描:
扫描成本与文件大小相关，文件大小N，扫描成本N金币
缓存一个报告需要M金币,缓存后后续不需要再扫描
求解缓存策略，最少需要金币数*/
// 输入：缓存一个报告所需金币数M，L<=M<=100
//     文件标识序列：F1,F2,...Fn  1<=n<=1000
//     文件大小序列：S1,S2...Sn  1<=Si<=10

#define N 10001
#include<stdio.h>

int GetResult(int M, int F[], int S[]);
int main(){
    int M,n;
    scanf("%d",&M);
    int F[N] = {0};
    int S[N] = {0};
    int k,i = 0;
    do{
        scanf("%d",&F[i++]);
    }while(getchar() != '\n');
    n = i;i = 0;
    while(n--){
        // printf("%d",n);
       scanf("%d",&S[i++]);}

    printf("%d",GetResult(M, F, S));
    return 0;
}

int GetResult(int M, int F[], int S[]){
    //文件取出   第一次出现：扫描   第二次：扫描或者缓存
    //考虑：扫描一次加缓存 和扫描n次  代价
    ///统计代价
    int money = 0;
    int count[N] = {0};
    int size[N] = {0};
    int i,k = 0;
    // for(i = 0; S[i]; i++){
    //     printf("%d",S[i]);
    // }
    for(i = 0; F[i]; i++){
        count[F[i]]++;
        size[F[i]] = S[i];
        // printf("文件%d个数+1,大小%d",F[i],size[F[i]]);
        k++;//统计文件个数
    }
    for(i = 0; i < N; i++){
        if(!k){
            break;
        }else if(count[i] != 0){
                // printf("文件%d共有%d个,大小%d  ",i,count[i],size[i]);
                // printf("每次扫描花费%2d, 扫描缓存结合花费%2d,   \n",(count[i] * size[i]) ,(size[i] + M));   
                money +=( (count[i] * size[i]) > (size[i] + M)) ? (size[i] + M): (count[i] * size[i]);
                k--;
            } 
    }
    //二重循环
    // int count;//文件个数
    // int i = 0;
    // int j;
    // for(i = 0; i < n; i++){
    //     if(F[i] != 0){
    //         // printf("文件%d",F[i]);
    //         int k = F[i];
    //         count = 0;
    //         for(j = i; j < n; j++){
    //             if(F[j] == k){
    //                 count++;
    //                 F[j] = 0;
    //             }
    //         }
    //         // printf("共有%d个,  ",count);
    //         money +=( (count * S[i]) > (S[i] + M)) ? (S[i] + M):(count * S[i]);
    //         // printf("每次扫描花费%d,  扫描缓存结合花费%d,   ",(count * S[i]),(S[i] + M));   
    //     } 
    // }
    // printf("选择%d\n",money);
    return money;

}