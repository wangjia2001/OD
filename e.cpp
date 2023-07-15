//�쳣�Ĵ򿨼�¼��ʵ���豸����ע���豸�Ų�ͬ
//����ͬһԱ�������򿨼�¼ʱ��С����ʮ���Ӳ��Ҵ򿨾��볬��5km
//�����쳣�򿨼�¼��������˳��

#include <cstdio>
#include <cstring>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node {
	int flag ;//�쳣λ���
	int  id; //���ţ�6λ����
	int  time;//ʱ�䣨���ӣ���������0-1000
	int  distance;//�򿨾��루km)��������0-100
	char  actualDeviceNumber[5];//ʵ���豸�ţ���λ��д��ĸ
	char  registerDeviceNumber[5];//ע���豸��
	struct node* next;
} node,*Linklist;

void GetRecords(Linklist &L,int n);
void PrintList(Linklist L);
void GetError(Linklist &L);

int main() {
	int N;//�򿨼�¼��
	scanf("%d",&N);
	getchar();
	Linklist L;
	GetRecords(L,N);//�洢����
	GetError(L);//�ҳ��쳣
	PrintList(L);//��ӡ�쳣
	return 0;
}

void GetRecords(Linklist &L,int N) {
	L = (node*)malloc(sizeof(node));
	L -> next = NULL;
	node* r = L;//βָ��
	for(int i = 0; i < N; i++) {
		char str[1000];
		gets(str);
		node *temp;
		temp = (node*)malloc(sizeof(node));
		//β��
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
		// printf("һ����㴴�����:");
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
			// printf("��%d��ʵ���豸����ע���豸�Ų�ͬ\n",p->id);
		}
		for(q = p->next; q != NULL; q = q->next) {
			if(p->id == q->id && abs(p->time - q->time)<60 && abs(p->distance - q->distance)>5) {
				p->flag = 1;
				q->flag = 1;
				// printf("%dԱ�������򿨼�¼ʱ��С����ʮ���Ӳ��Ҵ򿨾��볬��5km",p->id);
			}

		}


	}
}

void PrintList(Linklist L) {
	// printf("�쳣��\n");
	int fenhao = 0;//�ֺŷ��ж�
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