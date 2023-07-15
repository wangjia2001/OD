//猜字谜
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXN 1000 //单词数量 
#define MAXM 1000  //词汇表数量
#define MAXP 20 //单词长度 

char** GetWords(char* p,int *c);
void RemoveDuplicate(char *s);
void SortWords(char *s);
void RemoveDuplicate2(char*); 
int main() {
	char a[1000],b[1000];
	gets(a);
	gets(b);
	int m,n;//行数
	char** puzzle = GetWords(a,&m);
//	printf("m:%d ",m);
	char** answer = GetWords(b,&n);
	char** answer2 = GetWords(b,&n);
	for(int k = 0; k < m; k++){
		RemoveDuplicate2(puzzle[k]);
	}
	for(int k = 0; k < n; k++){
		RemoveDuplicate2(answer2[k]);
	}
	
	
	
//	//单词去重 加排序
//	for(int k = 0; k < m; k++){
//		RemoveDuplicate(puzzle[k]);
//		SortWords(puzzle[k]);
//	}
//	for(int k = 0; k < n; k++){
//		RemoveDuplicate(answer2[k]);
//		SortWords(answer2[k]);
//	}

	//比较
	int flag = 0;//判断逗号
	int if_found;//是否找到 
	for(int i = 0; i < m; i++){
		if_found = 0;
		for(int j = 0; j < n; j++){
			if(strcmp(puzzle[i],answer2[j]) == 0){
				if(!flag){
					flag = 1;				
				} 
				else {
					printf(",");
				}
				printf("%s",answer[j]);
				if_found = 1;
//				break;
			}
		}
		if(!if_found) {
				if(!flag){
					flag = 1;				
				} 
				else {
					printf(",");
				}
				printf("not"); 
				// printf("not:i:%d,%s    ",i,puzzle[i]); 
		}

	} 
	return 0;
}

//去重加排序 
void RemoveDuplicate2(char* s){
	int i, j, val, check;
	j = check = 0;
	for(i = 0; s[i]; i++) {
		val = s[i] - 'a';
		if((check & (1 << val)) == 0) {
			check |= 1 << val;//更新check数组 
		}
	}
	for(val = 0;val < 26; val++){

		if((check & (1 << val)) != 0){
			s[j++] = val + 'a';		
		}
	}
	s[j] = '\0';
//	printf("new:%s\n",s);
}

char** GetWords(char* p,int *c) {
	int i=0,j=0;
	char** b;//二维指针
	b =  (char**)malloc(MAXN * sizeof(char*));
	for(i = 0; i < MAXN; i++) {
		b[i] = (char*)malloc(MAXP * sizeof(char));
	}  //初始化二维数组列
	//赋值
	i = 0;
	while(*p != '\0') {
		while(*p != '\0' && *p != ',') {
			b[i][j++] = *p;
			p++;
		}
		b[i++][j] = '\0';
//		printf("%s",b[i]);
		if(*p == ',') {
//			i++;
			j = 0;
			p++;
		}	
	}
	// int k = 0;
//	for(k=0;k<i;k++){
//		printf("%s ",b[k]);
//	}
	*c = i ;
//	printf("*c:%d ",*c);
	return b;
}

//单词去重 
void RemoveDuplicate(char *s) {
	int i, j, val, check;
	j = check = 0;
//	printf("old:%s\n",s);
	for(i = 0; s[i]; i++) {
		val = s[i] - 'a';
		if((check & (1 << val)) == 0) {
			s[j++] = s[i];
			check |= 1 << val;//更新check数组 
		}
	}
	s[j] = '\0';
//	printf("new:%s\n",s);
}

//排序 
void SortWords(char *s){
	char temp;
	int min;
	for(int i = 0; s[i]; i++) {
		min = i;
		for(int j = i; s[j]; j++){
			if(s[j] < s[min]){
				min = j;
				}			
		}
		temp = s[i];
		s[i] = s[min];
		s[min] = temp;
	}
	printf("new:%s\n",s);	
}
