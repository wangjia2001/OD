#include<stdio.h>
#include<string.h>
#include <malloc.h>

typedef struct node {
	char word[1000];//������󳤶�
	int cnt;//���ʳ��ִ���
	int length;//���ʳ���
	struct node* next;
} node,*Linklist;

void WordToLinkList(Linklist &L,char* s);
void InitList(Linklist &L);
void GetWord(char *str,Linklist &L);
void StrSort(Linklist &L) ;
void WordSort(char *a);
void PrintList(Linklist L);

int main() {
	//�洢�ַ�����һά����
	int i=0;
	char str[1000],c;
	while(scanf("%c",&c)!=EOF)
	//while(scanf("%c",&c) && c!='\n') 
	{
		str[i++]=c;
	}
	str[i] = '\0';
	// printf("%s",str);
	Linklist L;
	InitList(L);
	//����ת�浽������+����
	GetWord(str,L);
	//������
	 StrSort(L);
	PrintList(L);
	return 0;
}


void InitList(Linklist &L) { //��ʼ������
	L = (node*)malloc(sizeof(node));
	L->word[0] = '\0';
	L->cnt = 0;//�������
	L->next = NULL;
}

void GetWord(char *str,Linklist &L) {
	char *p;
	p=strtok(str, " ");//�������ָ���������Ϊ'\0',��û�����ɶ���ַ���
	while(p!=NULL) {
		WordToLinkList(L,p);  //��ÿһ�����ʴ��������У����ɽ��
		p = strtok(NULL," ");  //p����ָ����һ���ַ�����ͷ
	}
}

//�Ѵ������ĵ������ӵ�������
void WordToLinkList(Linklist &L,char* s) {
	WordSort(s); //�Ե����ڲ�����
	int newflag;//�Ƿ�Ϊ�µ���
	node *q;
	newflag=0;
	q= L->next;
	//ÿ�α�������,���õ����Ƿ��Ѿ�����
	while(q) {
		if(strcmp(q->word,s)==0) { //���ڽ�㣬����cnt+1
			q->cnt++;
			newflag=1;
			break;
		}
		q = q->next;
	}
	if(!newflag) { //�����ڽ�㣺�½�
		node *temp;
		temp = (node*)malloc(sizeof(node));
		strcpy(temp->word,s);
		temp->cnt=1;
		temp->next = L->next;
		L->next = temp;
		temp->length = strlen(s);
		L->cnt++;//�ڵ�����
	}
}

//���ʼ�˳����� ð��
void  StrSort(Linklist &L) {
	node *p,*q,*r; //p�������βָ��//q�ǵ�ǰ�ڵ㣬r��q����һ�����
	int i,j;
	for (i=0; i<(L->cnt-1); i++) {
		p=L;
		q=p->next;
		r=q->next;
		for(j=0; j<L->cnt-i-1; j++) {
			if(
			    (q->cnt > r->cnt)||
			    (q->cnt == r->cnt && q->length < r->length)||
			    (q->cnt == r->cnt && q->length == r->length && strcmp(q->word,r->word)<0)) {
				q=q->next;
//				continue;
			}
			//�����������
			else {
				q->next = r->next;
				r->next = q;
				p->next = r;

			}
			p=p->next;
			r=q->next;
		}
	}
}



//�����ڲ��ֵ�������
void WordSort(char *a) {
	int n=strlen(a);
	int i,j;
	char temp;
	//ð��
	for	(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if((a[i]-a[j])>0) {
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
//	printf("a���飺��%s\n",a);
}

void PrintList(Linklist L) { //��������и�����ֵ
	node *p = L->next;
	int i;
	int flag=0;
	while(p!=NULL) {
		i=p->cnt;
//		if(flag==0) printf(" ")
		while(i--) {
			if(flag) {
				printf(" ");
				printf("%s",p->word);
			}
			else {
				flag=1;
				printf("%s",p->word);
			}
		
		}
//		printf("%s:%d:%d\n",p->word,p->cnt,p->length);
		p = p->next;
	}
}