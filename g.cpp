//构造最长回文字符串，要求字典序最小

#include <algorithm>
#include <cstdio>
#include <cstring>
#include<stdio.h>
#include<string.h>

void sort(char a[],int n);

int main() {
	char readline[100], ans[100];
	gets(readline);
	int count[52] = {0};
	int mid = 100;

	for(int i = 0; i < strlen(readline); i++) {
		if('A' <= readline[i] && readline[i] <= 'Z') {
			// printf("%d  ",readline[i]-'A');
			count[readline[i]-'A']++;
		}

		if('a' <= readline[i] && readline[i] <= 'z') {
			// printf("%d  ",readline[i]-'a'+26);
			count[readline[i]-'a'+26]++;
		}
	}

//	printf("count[]:");
//	for(int i = 0; i < 52; i++) {
//		printf("%d ",count[i]);
//	}
//	printf("\n");

	int k = 0;
//    char c;
	for(int i = 0; i < 52; i++) {
		if(count[i] >= 2) {
//        	printf("i:%d,count[i]:%d分支1：",i,count[i]);
			if(count[i] % 2 == 0) {
				for(int j = count[i]; j > 0; j -= 2) {
					if(i < 26) {
						ans[k++] = i + 'A';
					} else {
						ans[k++] = i + 'a' - 26;;
					}

				}
			} else {
				for(int j = count[i]; j > 1; j -= 2) {
					if(i < 26) {
						ans[k++] = i + 'A';
					} else {
						ans[k++] = i + 'a' - 26;;
					}
				}
				if(i <= mid) {
					mid = i;
				}
//				printf("  mid:%d",mid);
			}
		} else if(count[i] == 1) {
			if(i <= mid) {
				mid = i;
			}
		}

	}
	printf("%s",ans);
	if(mid != 100) {
		if(mid < 26) {
			printf("%c",mid +'A') ;
		} else {
			printf("%c",mid +'a'-26) ;
		}
	}
	for(int i = k-1; i >= 0; i--) {
		printf("%c",ans[i]);
	}



	return 0;

}


