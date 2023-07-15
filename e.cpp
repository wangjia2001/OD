//异常的打卡记录：实际设备号与注册设备号不同
//或者同一员工两个打卡记录时间小于六十分钟并且打卡距离超过5km
//返回异常打卡记录（按输入顺序）

#include <cstdio>
#include <cstring>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node {
	int flag ;//异常位标记
	int  id; //工号，6位数字
	int  time;//时间（分钟），整数，0-1000
	int  distance;//打卡距离（km)，整数，0-100
	char  actualDeviceNumber[5];//实际设备号，四位大写字母
	char  registerDeviceNumber[5];//注册设备号
	struct node* next;
} node,*Linklist;

void GetRecords(Linklist &L,int n);
void PrintList(Linklist L);
void GetError(Linklist &L);

int main() {
	int N;//打卡记录数
	scanf("%d",&N);
	getchar();
	Linklist L;
	GetRecords(L,N);//存储数据
	GetError(L);//找出异常
	PrintList(L);//打印异常
	return 0;
}

void GetRecords(Linklist &L,int N) {
	L = (node*)malloc(sizeof(node));
	L -> next = NULL;
	node* r = L;//尾指针
	for(int i = 0; i < N; i++) {
		char str[1000];
		gets(str);
		node *temp;
		temp = (node*)malloc(sizeof(node));
		//尾插
		temp->next = NULL;
		temp->flag = 0;
		r->next = temp;
		r = temp;
		char *p;
		p = strtok(str,",");
		temp->id = atoi(p);
		p = strtok(NULL,",");
		temp->time = atoi(p);
		p = strtok(NULL,",");
		temp->distance = atoi(p);
		p = strtok(NULL,",");
		strcpy(temp->actualDeviceNumber,p);
		p = strtok(NULL,",");
		strcpy(temp->registerDeviceNumber, p);
		// printf("一个结点创建完毕:");
		// printf("%d,%d,%d,%s,%s\n",temp->id,temp->time,temp->distance,temp->actualDeviceNumber,temp->registerDeviceNumber);
	}
}

void GetError(Linklist &L) {
	node *p,*q;
	// p = L->next;
	// q = L->next;
	for(p = L->next; p != NULL; p = p->next) {
		// printf("%d,%d,%d,%s,%s\n",p->id,p->time,p->distance,p->actualDeviceNumber,p->registerDeviceNumber);
		if(strcmp(p->actualDeviceNumber, p->registerDeviceNumber) != 0) {
			p->flag = 1;
			// printf("第%d个实际设备号与注册设备号不同\n",p->id);
		}
		for(q = p->next; q != NULL; q = q->next) {
			if(p->id == q->id && abs(p->time - q->time)<60 && abs(p->distance - q->distance)>5) {
				p->flag = 1;
				q->flag = 1;
				// printf("%d员工两个打卡记录时间小于六十分钟并且打卡距离超过5km",p->id);
			}

		}


	}
}

void PrintList(Linklist L) {
	// printf("异常：\n");
	int fenhao = 0;//分号符判断
	node* p;
	p = L->next;
	while(p != NULL) {
		if(p->flag) {
			if(!fenhao) {
				fenhao = 1;
			} else {
				printf(";");
			}
			printf("%06d,%d,%d,%s,%s",p->id,p->time,p->distance,p->actualDeviceNumber,p->registerDeviceNumber);
		}
		p = p->next;
	}
	if(!fenhao) {
		printf("null");
	}

}
