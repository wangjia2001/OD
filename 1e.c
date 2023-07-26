/*
最佳对手匹配
两只队伍实力允许最大差距d,要求匹配队伍最多且实力差距总和最小
输入：n d //队伍个数 最大差距   2<=n<=50,0<=d<=100
      n个队伍实力值，空格分隔 0-100
输出：差距和，没有匹配则输出-1
*/
//输入用例
// 17 20
// 23 53 66 34 78 34 86 34 23 4 6 3 7 3 9 53 2   
//输出：36

/*思路：队伍实力排序，从左向右看，第i个队伍只需要和第i+1比较（前面的一定是被抛弃或者已经选择的），
当差距满足时，i选择 i+1一定也选择（因为相邻的差距一定最小）*/


#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<limits.h>

int n;//队伍数量
int d;//最大队伍差距
int i,j;
int power[51];//队伍实力
int x[51] = {0};//记录队伍选择情况，1表示选择，0表示不参加,x[0]存放power最小值
int count = 0; //参赛队伍数量
int MaxCount = 0; //最大参赛队伍数
int MinPower = INT_MAX; //最小差值和
int flag [51] = {0};  //用来标记，不能出现两个连续不选的队伍，回溯优化（否则会超时）

int GetMin(int n, int d, int power[]);
int cmp(const void *a, const void *b){
    return(*(int*)a- *(int*)b);
}
void backtrack(int i);

void output(){//输出符合条件的解
    x[0] = 0;//x[0]用来记录当前选择队伍的实力差距
    count = 0;//参赛队伍数
    // printf("解：");
    // for(i = 1; i <= n; i ++){
    //     printf("%d ",x[i]);
    // }
    for(i = 1; i <= n; i ++){
        if(x[i] == 1){//如果i队被选择，那么i+1一定被选了
            x[0] += power[i+1] - power[i];
            count += 2;//一次统计两个队伍
            i++;
        }
    }
    if (count > MaxCount){//选择队伍数量大的
        MaxCount = count;
        MinPower = x[0];
    }else if (MaxCount == count && count != 0){//队伍数量相同，选择差距和小的
        MinPower = (MinPower < x[0]) ? MinPower : x[0];
    }

	// printf("队伍%d 差值和%d   ",count,x[0]);
    // printf("当前最优解：队伍%d 差值和%d\n",MaxCount,MinPower);
}


int main(){
    scanf("%d %d",&n,&d);
    for(i = 1; i <= n; i++){
        scanf("%d",&power[i]);
    }

    GetMin(n, d, power);
    return 0;
}

int GetMin(int n, int d, int power[]){
    qsort(power, n+1, sizeof(power[1]), cmp);//对实力值升序排序
    // printf("power排序：");
    // for(i = 1; i <= n; i ++){
    //     printf("%d ",power[i]);
    // }
    // printf("\n");
    backtrack(1);
    if(MaxCount != 0){//输出最小差距和
        printf("%d",MinPower);
    }else{
        printf("-1");//没有队伍匹配
    }
    return 0;
}

//回溯 得到所有的解
void backtrack(int i){   
    //i用来指示到达的层数
    if(i >= n) {//出口
        output();
    }
    else {
        if(power[i+1] - power[i] <= d){//i和i+1可以被匹配
            //不选择i
            j = 0;//不选
                if(!flag[i-1]){//不允许出现两个连续且正常但不被选择的队伍
                    x[i] = 0;
                    flag[i] = 1;//记录正常但不选的队伍
                    backtrack(i+1); 
                }
            //选择i，i+1一定也被选择
            j = 1;
            x[i] = j;x[i+1] = j;
            flag[i] = 0;flag[i+1] = 0;
            // printf("选%d和%d   ",power[i],power[i+1]);
            backtrack(i+2);//跳过对i+1的判断
            x[i] = 0;x[i+1] = 0;
         }
        else{
            x[i] = 0;
            // printf("%d和%d差距过大,不选%d\n",power[i],power[i+1],power[i]);
            backtrack(i+1);
        }
    }
}


