#include<stdio.h>
#include<string.h>

int compare(char *version1,char *version2);

int main() {
	char version1[50],version2[50];
	gets(version1);
	gets(version2);
	int ret =compare(version1,version2);
	if(ret < 0) {
		printf("%s",version2);
	} else {
		printf("%s",version1);
	}
	return 0;
}

int compare(char *version1,char *version2) {
	int num1=0,num2=0;
	int flag1=0,flag2=0;
	char *p=NULL,*q=NULL;
	while(*version1 != 0 && *version2 != 0 ) {
		//主、次、增量（如果有）部分比较
		//version1数字部分
		while(*version1 != '.' && *version1 != 0 && *version1 != '-') {
			num1 = num1*10+*version1-'0';
			version1++;
		}
		//version2数字部分
		while(*version2 != '.' && *version2 != 0 && *version2 != '-') {
			num2 = num2*10+*version2 - '0';
			version2++;
		}
		if(num1 > num2) {
			return 1;
		} else if(num1 < num2) {
			return -1;
		}

		if(*version1 != 0) {
			if(*version1 == '-') {
				version1++;
				p = version1;
				if(*version2 == '.') { //v1没有增量，v2有增量
					return -1;  
				}
			} else if(*version1 == '.' && *version2 == '-') { //v1有增量，v2没有增量
				return 1;
			} else  
				version1++;
		}
		if(*version2 != 0) {
			if(*version2 == '-') {//v2有增量 
				version2++;
				q = version2;
			} else
				version2++;
		}
		if(p !=NULL ) {
			if(q !=NULL) {//v1 v2有增量 
				return(strcmp(p,q));
			} else  
				return 1;
		}
		if(p == NULL &&  q !=NULL) {
			return -1;
		}
		num1 = 0;
		num2 = 0;
	}
	if(*version1 == 0 && *version2 != 0) return -1;// v1没有增量，v2有增量
	if(*version1 != 0 && *version2 == 0) return 1;// v2没有增量，v1有增量
	return 0;
}







