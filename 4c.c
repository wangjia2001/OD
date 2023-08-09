/*每名采样员效率不同，为N人/小时，效率会以M人/小时为粒度发生变化，
M为采样效率浮动粒度，M=N*10%，输入保证N*10%的结果为整数
效率浮动规则：一名志愿者协助才能发挥正常效率，每增加一名志愿者，效率提升1M，最多提升3M；如果没有志愿者协助组织，效率下降2M。
怎么安排速度最快？求总最快检测效率
*/

/*
输入:
采样员人数[1, 100] 志愿者人数[1, 500]
各采样员基准效率值[60, 600]
输出:
总最快检测效率
用例:
输入	2 2
200 200
输出	400
*/

#include<stdio.h>
#include<stdlib.h>

void MaxEff(int s,int v,int **eff);
int cmp(const void *a,const void *b){
    int *c = *(int**)a;
    int *d = *(int**)b;
    return(d[0] - c[0]);
}

int main(){
    int staff;//采样员人数
    int volunteer;//志愿者人数
    scanf("%d %d",&staff,&volunteer);
    int i,j;
    int **eff = (int **)malloc(sizeof(int*)*staff);
    for(i = 0; i < staff; i++){
        eff[i] = (int *)malloc(sizeof(int)*2);
    }   
    for(i = 0; i < staff; i++){
        scanf("%d",&eff[i][0]);
        eff[i][1] = 0;
    }

    MaxEff(staff, volunteer, eff);

    for(i = 0; i < staff; i++){
        free(eff[i]);
    }
    free(eff);

    return 0;
}

void MaxEff(int s,int v,int **eff){
    int maxE = 0; //最大总效率
    qsort(eff, s, sizeof(eff[0]), cmp);
    int i,j;

    if(v >= s*4){//志愿者充足，此时每人分配四个志愿者，且效率达到最大
        for(i = 0; i < s; i++){
            maxE += eff[i][0]*1.3;
        } 
    }
    
    else if(v <= s){//志愿者小于采样员人数
        //优先给高效率的人分配一个志愿者
        for(j = 0; j < s; j++){
            if(j < v){
                eff[j][1] = 1;
                maxE += eff[j][0];  
            }else{
                maxE += (eff[j][0]*0.8);
            } 
        }   
        //然后剥夺低效率的分配给高效的
        i = 0; j = v-1;
        while (i < j){   
            // printf("i:%d  j:%d  ",i,j);
            if(eff[i][1] == 4){
                // printf("采样员%d志愿者已足够",i);
                i++;
            }
            if(eff[j][0]*0.2 < eff[i][0]*0.1){
                eff[i][1]++;
                eff[j][1]--;
                // printf("采样员%d新增1个志愿者，共有%d个志愿者  ",i,eff[i][1]);
                maxE = maxE - eff[j][0]*0.2 + eff[i][0]*0.1; 
                j--;
            }else{
                break;
            }
        }        
    }
    
    else{//志愿者人数大于采样员人数，但小于采样员工四倍
        //优先每人分配一个，达到正常效率
        for(i = 0; i < s; i++){
            eff[i][1] = 1;
            maxE += eff[i][0]; 
            v--;  
        }
        //依次给高效率每人分配三个
        for(i = 0; i < (v/3); i++){
            // printf("采样员%d新增3个志愿者\n",i);
            eff[i][1] = 4;
            maxE += eff[i][0] * 0.3;
        }        
        eff[i][1] += v%3;
        maxE += eff[i][0] * 0.1 * (v%3);
        //剥夺低效率分配给高效率
        j = s-1;
        while (i < j){
            if(eff[i][1] == 4){
                // printf("采样员%d志愿者已足够",i);
                i++;
            }
            if(eff[j][0]*0.2 < eff[i][0]*0.1){
                eff[i][1]++;
                eff[j][1]--;
                // printf("采样员%d新增1个志愿者，共有%d个志愿者  ",i,eff[i][1]);
                maxE = maxE - eff[j][0]*0.2 + eff[i][0]*0.1;
                j--;
            }else{
                break;
            }
        }     
    }

    // for(i = 0; i < s; i++){
    //     printf("采样员%d分配%d个志愿者，",i,eff[i][1]);
    // }

    printf("%d ",maxE);    
}