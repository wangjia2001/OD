#include<stdio.h>
#include<string.h>
#include <malloc.h>

typedef struct node {
	char word[1000];//单词最大长度
	int cnt;//单词出现次数
	int length;//单词长度
	struct node* next;
} node,*Linklist;

void WordToLinkList(Linklist &L,char* s);
void InitList(Linklist &L);
void GetWord(char *str,Linklist &L);
void StrSort(Linklist &L) ;
void WordSort(char *a);
void PrintList(Linklist L);

int main() {
	//存储字符串到一维数组
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
	//单词转存到链表中+内排
	GetWord(str,L);
	//外排序
	 StrSort(L);
	PrintList(L);
	return 0;
}


void InitList(Linklist &L) { //初始化链表
	L = (node*)malloc(sizeof(node));
	L->word[0] = '\0';
	L->cnt = 0;//结点数量
	L->next = NULL;
}

void GetWord(char *str,Linklist &L) {
	char *p;
	p=strtok(str, " ");//函数将分隔符都设置为'\0',并没有生成多个字符串
	while(p!=NULL) {
		WordToLinkList(L,p);  //将每一个单词传进链表中，生成结点
		p = strtok(NULL," ");  //p继续指向下一个字符串开头
	}
}

//把传进来的单词添加到链表中
void WordToLinkList(Linklist &L,char* s) {
	WordSort(s); //对单词内部调整
	int newflag;//是否为新单词
	node *q;
	newflag=0;
	q= L->next;
	//每次遍历链表,看该单词是否已经出现
	while(q) {
		if(strcmp(q->word,s)==0) { //存在结点，次数cnt+1
			q->cnt++;
			newflag=1;
			break;
		}
		q = q->next;
	}
	if(!newflag) { //不存在结点：新建
		node *temp;
		temp = (node*)malloc(sizeof(node));
		strcpy(temp->word,s);
		temp->cnt=1;
		temp->next = L->next;
		L->next = temp;
		temp->length = strlen(s);
		L->cnt++;//节点总数
	}
}

//单词间顺序调整 冒泡
void  StrSort(Linklist &L) {
	node *p,*q,*r; //p有序结点的尾指针//q是当前节点，r是q的下一个结点
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
			//交换两个结点
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



//单词内部字典序排序
void WordSort(char *a) {
	int n=strlen(a);
	int i,j;
	char temp;
	//冒泡
	for	(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if((a[i]-a[j])>0) {
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
//	printf("a数组：：%s\n",a);
}

void PrintList(Linklist L) { //输出链表中各结点的值
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