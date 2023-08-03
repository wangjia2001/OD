/*最快到医院的方法
医院A距离X公里，医院B距离Y公里
到医院A只能搭乘计程车，计程车平均速度M米/分钟，上车平均等待时间L分钟
到医院B只能步行，平均速度N米/分钟
输入：X Y M L N
输出：Taxi 或 Walk 或 Same*/

#include<stdio.h>

int main(){
    float X;
    float Y;
    float M;
    float L;
    float N;
    scanf("%f %f %f %f %f",&X,&Y,&M,&L,&N);
    // printf("%f %f %f %f %f   ",X,Y,M,L,N);
    float timeX ;
    float timeY;
    timeX = (X * 1000 ) / M + L;
    timeY = (Y*1000) / N;
    if(timeX > timeY){
        printf("Walk");
    }else if (timeX < timeY)
    {
        printf("Taxi");
    }else{
        printf("Same");
    }
    return 0 ;
    
}