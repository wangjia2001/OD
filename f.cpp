//输出打卡top5员工id，空格隔开
//次数相同，较早的排在前
//时间相同，id较小的排在前

#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <string.h>

struct employees{
    int count ;
    int firstday;
    int id;
};
void sort(struct employees employee[],int n);

int main(){
    int N;//员工数量1-100,编号0~N-1
    scanf("%d",&N);
    int dayCount[30];//每天打卡员工数量
    int i = 0;
    while(i<30){
        scanf("%d",&dayCount[i++]);
    }
    struct employees employee[N];//每个员工的打卡情况统计 
    for(i = 0; i < N; i++){
    	employee[i].count = 0;
    	employee[i].firstday = 31;
        employee[i].id = i;
	} 
    int k;
    
    for(i = 0; i < 30; i++){
        for(int j = 0; j < dayCount[i]; j++){
            scanf("%d",&k);
            employee[k].count++;
            if(employee[k].firstday == 31){
                employee[k].firstday = i;
            }
            //  printf("%d第%d次打卡\n",k,employee[k].count);
        }
    }
    //  for(i = 0; i < N; i++){
    //      printf("员工id：%d,打卡次数：%d,初次打卡日期：%d\n",employee[i].id,employee[i].count,employee[i].firstday);
    //  }

    //排序
   sort(employee,N);
//    printf("排序后：\n");
//     for(i = 0; i < N; i++){
//          printf("员工id：%d,打卡次数：%d,初次打卡日期：%d\n",employee[i].id,employee[i].count,employee[i].firstday);
//      }
    for(i = 0; (N >= 5) ? (i < 5) :(i < N); i++){
        if(employee[i].count != 0){
            printf("%d ",employee[i].id);
            }
    }
    return 0;
}


void sort(struct employees employee[],int n){
    int maxid = 0;
    int tempcount;
    int tempday;
    int tempid;
    int i = 0;
    for(int i = 0; (n >= 5) ? (i < 5) :(i < n); i++){
        maxid = i;
        for(int j = i + 1  ; j < n; j++){
            if(employee[maxid].count != employee[j].count){
                if(employee[maxid].count < employee[j].count){
                    maxid = j;
                }

            }else if(employee[maxid].firstday != employee[j].firstday){
                if(employee[maxid].firstday > employee[j].firstday){
                    maxid = j;
                }
            }else if(employee[maxid].id > employee[j].id) {
                 maxid = j;
            }
        }
        //交换maxid和i
        tempcount = employee[i].count;
        tempday = employee[i].firstday;
        tempid = employee[i].id;
        employee[i].count = employee[maxid].count;
        employee[i].firstday = employee[maxid].firstday;
        employee[i].id = employee[maxid].id;
        employee[maxid].count = tempcount;
        employee[maxid].firstday = tempday;
        employee[maxid].id = tempid;
    }

}
