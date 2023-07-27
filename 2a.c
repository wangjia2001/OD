/*
输入数组s，表示山脉高度
选择山脉上两个点做蓄水库边界，边界内蓄水，排除山脉空间
蓄水量高度为两边界最小值
多个边界，选择距离最近的边界
输出边界下表（0开始）和最大蓄水量，如果无法蓄水，返回0不返回边界
输出格式：左边界 右边界:蓄水量*/

/*思路：考虑山峰比较困难，因此纵向思考
当山峰确定时，水位线是确定的，因此可以在对每一条水位线确定最大蓄水量，反推山峰位置*/


#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int n = 0;
void GetResult(int s[]);
int cmp(const void *a, const void *b){
    return(*(int *)a - *(int *)b);
}

int main(){
    int s[10001];//0<=s[i]<=10000
    do{
        scanf("%d",&s[n++]);
    // }while (getchar() != '\n' || getchar()!= ' ');
    }while(getchar() != EOF);

    GetResult(s);
    return 0;
}

void GetResult(int s[]){
    int left[n];//第i个山峰左边最高的山峰,不包括自己
    int right[n];//第i个山峰右边最高的山峰，不包括自己
    int water;//第i山峰最多储水量   water[i] = max(min(left[i],right[i])-s[i], 0)
    int lines[n]; // lines[i] 记录 第 i 个山峰的水位线高度
    int i = 0;
    int result[3] = {0, 0, 0};//记录结果，左边界，有边界，蓄水量

    left[0] = 0;
    for(i = 1; i < n; i++){
        left[i] = (left[i-1] > s[i-1]) ? left[i-1] : s[i-1];
        // printf("%d ",left[i]);
    }

    right[n-1] = 0;
    for(i = n-2; i >= 0; i--){
        right[i] = (right[i+1] > s[i+1]) ? right[i+1] : s[i+1];
        // printf("%d ",right[i]);
    }

    for(i = 0; i < n; i++){//记录水位线
        int min = (left[i] < right[i]) ? left[i] : right[i];
        if(min > s[i]) {
            water = min - s[i];//储水量为左右最高山峰中较小的那个与自己的差
        }else{
            water = 0;//第i个山峰高于 左或右最高
        }
        if(water != 0){//如果第i个山峰可以储水，记录水位线
            lines[i] = water + s[i]; //水位线等于储水量加山峰高

        }else{
            lines[i] = 0;
        }
        // printf("water:%d line:%d   ",water,lines[i]);
    }

    //遍历水位线
    // qsort(lines, n, sizeof(lines[0]), cmp); //对水位线排序
    // for(i = 0; i < n; i++){//记录水位线
    // printf("%d   ",lines[i]);}
    int L;//  满足该水位线的最左侧山峰位置L
    int R;// 满足该水位线的最右侧山峰位置R
    int j;
    for(i = 1; i < n; i++){
        if(lines[i] != 0 ){
            //    printf("%d   ",lines[i]);}
            L = 0;
            R = n-1; 
            while ((lines[L] < lines[i]) || (s[L] >= lines[i])){//找到能被水淹住的最远边界
                // printf( );
                // printf("%d,%d,%d,%d    ",i,lines[L],lines[i],s[L]);
                L += 1;
            }
            while (lines[R] < lines[i]  || s[R] >= lines[i]){
                R -= 1;
            }  
            // printf("i；%d,水位线%d 边界%d %d\n",i,lines[i],L,R);

            //该水位线最大储水量
            int total = 0;
            for(j = L; j <= R; j++){
                total += ((lines[i] - s[j]) > 0) ? (lines[i] - s[j]) : 0; 
                // printf("total:%d   ",((lines[i] - s[j]) > 0) ? (lines[i] - s[j]) : 0);
            }
            // printf("i:%d  边界： %d,%d   蓄水量：%d      ",i,L,R,total);
            if(total > result[2]){//当前储水量更大
                result[0] = L;
                result[1] = R;
                result[2] = total;
            }else if (total == result[2])  {//储水量相同，选择距离更小的
                if((R-L) < (result[1]-result[0])){
                    result[0] = L;
                    result[1] = R;
                    result[2] = total;
                }
            }
            // printf("当前最优边界： %d,%d   蓄水量：%d\n",result[0],result[1],result[2]);
        }   
    }
    // printf("最优边界： %d,%d   蓄水量：%d\n",result[0],result[1],result[2]);
    if(result[2]  != 0){
        printf("%d %d:%d",result[0]-1,result[1]+1,result[2]);
    }else {
        printf("0");
    }

}