//������
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXN 1000 //�������� 
#define MAXM 1000  //�ʻ������
#define MAXP 20 //���ʳ��� 

char** GetWords(char* p,int *c);
void RemoveDuplicate(char *s);
void SortWords(char *s);
void RemoveDuplicate2(char*); 
int main() {
	char a[1000],b[1000];
	gets(a);
	gets(b);
	int m,n;//����
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
	
	
	
//	//����ȥ�� ������
//	for(int k = 0; k < m; k++){
//		RemoveDuplicate(puzzle[k]);
//		SortWords(puzzle[k]);
//	}
//	for(int k = 0; k < n; k++){
//		RemoveDuplicate(answer2[k]);
//		SortWords(answer2[k]);
//	}

	//�Ƚ�
	int flag = 0;//�ж϶���
	int if_found;//�Ƿ��ҵ� 
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

//ȥ�ؼ����� 
void RemoveDuplicate2(char* s){
	int i, j, val, check;
	j = check = 0;
	for(i = 0; s[i]; i++) {
		val = s[i] - 'a';
		if((check & (1 << val)) == 0) {
			check |= 1 << val;//����check���� 
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
	char** b;//��άָ��
	b =  (char**)malloc(MAXN * sizeof(char*));
	for(i = 0; i < MAXN; i++) {
		b[i] = (char*)malloc(MAXP * sizeof(char));
	}  //��ʼ����ά������
	//��ֵ
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

//����ȥ�� 
void RemoveDuplicate(char *s) {
	int i, j, val, check;
	j = check = 0;
//	printf("old:%s\n",s);
	for(i = 0; s[i]; i++) {
		val = s[i] - 'a';
		if((check & (1 << val)) == 0) {
			s[j++] = s[i];
			check |= 1 << val;//����check���� 
		}
	}
	s[j] = '\0';
//	printf("new:%s\n",s);
}

//���� 
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