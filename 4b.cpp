/*5台打印机，每台有自己的待打印队列
队列中的文件有1-10的优先级，数字越大优先级越高，优先级相同的选最早进入队列的
请模拟5台打印机打印过程*/

/*输入：发生事件的数量N（0<N<1000)
        N行事件：IN P NUM 表示优先级NUM文件放到了打印机P队列
                OUT P 表示P进行了一次文件打印，文件从待打队列取出
  输出：对每个OUT P 事件，输出文件编号
        此时没有文件可以打印，输出NULL
        文件编号定义为IN事件发生第几次，从1编号*/
/*用例：
输入:
11
IN 1 8
IN 3 7
IN 5 3
OUT 3
IN 1 9
OUT 3
IN 2 2
OUT 2
IN 4 4
OUT 1
IN 3 6        
输出：
2 
NULL
5
4
*/
//思路：对输入的文件按照优先级排序

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "define.H"

//节点结构 
typedef struct Qnode{
    int index;//文件编号
    int num;//优先级
    struct Qnode *next;
}*LinkQueue;


typedef int Status;

Status InitQueue(LinkQueue &L);
Status EnQueue(LinkQueue &L, int num, int index);//进队，找到合适的位置排序
Status DeQueue(LinkQueue &L);
Status visitQueue(LinkQueue L);//遍历队列


int main(){
    int N;
    scanf("%d",&N);
    int P;//打印机名称
    int num;//文件优先级
    char flag[5];//IN或OUT标识
    int k = 0;//文件编号

    LinkQueue L1,L2,L3,L4,L5;    
    InitQueue(L1);
    InitQueue(L2);
    InitQueue(L3);
    InitQueue(L4);
    InitQueue(L5);
 
    while (N--){
        scanf("%s%d",flag,&P);//输入输入输出标识 打印机  

        if(strcmp(flag,"IN") == 0){//IN状态，将文件输入并排序
            k++;
            scanf("%d",&num);
            switch (P){
            case 1:
                // printf("入队1\n");
                EnQueue(L1,num,k);  
                // visitQueue(L1);
                break;
            case 2:
                EnQueue(L2,num,k); 
                break;
            case 3:
                EnQueue(L3,num,k); 
                break;
            case 4:
                EnQueue(L4,num,k); 
                break;
            case 5:
                EnQueue(L5,num,k); 
                break;
            default:
                break;
            }
        }
        
        else{
            switch (P){//OUT状态，输出文件序号
            case 1:
                // printf("出队1\n");
                DeQueue(L1);
                // visitQueue(L1);
                break;
            case 2:
                DeQueue(L2); 
                break;
            case 3:
                DeQueue(L3);
                break;
            case 4:
                DeQueue(L4);
                break;
            case 5:
                DeQueue(L5);
                break;
            default:
                break;
            }
        }
        // visitQueue(L1);
    }  
    
}


Status InitQueue(LinkQueue &L){
    L = (Qnode*)malloc(sizeof(Qnode));
    L->num = 0;//头结点num存放结点数
    L->index = 0;
    L->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue &L, int num, int index){//进队
    // printf("进队成功");
    Qnode *s = (Qnode*)malloc(sizeof(Qnode));
    Qnode *p = L;
    Qnode *q = p->next;
    s->index = index;
    s->num = num;
    while (q != NULL){
        if((s->num > q->num) || (s->num == q->num  &&  s->index < q->index))//找到插入s的合适位置   
            break;
        p = p->next;
        q = p->next;
    }
    // printf("找到合适s的位置,在文件编号%d的后面",p->index);
    s->next = p->next;
    p->next = s;
    // visitQueue(L);
    return OK;
}

Status DeQueue(LinkQueue &L){
    Qnode *p = L->next;
    if(L->next == NULL){
        printf("NULL");//没有文件可以打印，输出null
    }else{//输出并删除队头元素
        printf("%d",p->index);
        L->next = p->next;
        free(p);
    }
    printf("\n");
    return OK;
}

Status visitQueue(LinkQueue L){
    Qnode* p = L->next; 
    while(p != NULL){
        printf("num:%d index:%d     ",p->num,p->index);
        p = p->next;
    }
    printf("\n");
    return OK;
}
