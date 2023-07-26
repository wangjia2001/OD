/*有number种商品，每件商品最大数量item[idex],
每件商品价格item_price[item_idex][day];
给出days天获得最大利润
输入：number
	days
	itme[idex]  //4 5 6
	days列  //1 2 3
	          4 5 6 
*/

#include<stdio.h>
#include<stdlib.h>

int MaxProfit(int number, int item[], int days, int **item_price);//c中声明函数二维数组不能是变量 
// int MaxProfit(int number, int item[], int days, int **item_price);

int main(){
	int number,days;
	// printf("number:");
	scanf("%d",&number);
	// printf("days")5;
	scanf("%d",&days);
	int item[number];
	for(int i = 0; i < number; i++){
		scanf("%d",&item[i]);
	}
	int **item_price = (int**)malloc(sizeof(int*)*number);
	// int item_price[number][days];
	for(int i = 0; i < number; i++){
		item_price[i] = (int*)malloc(sizeof(int)*days);
	}
	for(int i = 0; i < number; i++){
		for(int j = 0; j < days; j++){
			scanf("%d",&item_price[i][j]);
		}
	}

	
    // MaxProfit(number,item, days, item_price);
	printf("%d",MaxProfit(number,item, days, item_price));
	return 0;
}


int MaxProfit(int number, int item[], int days,  int **item_price){
	int profit = 0;
    //只在递增序列首尾买进卖出
    int min,max;
    if(number == 0) return 0;
    for(int i = 0; i < number; i++){
        min =0; max = 0;
        // profit = 0;
        for(int j = 1; j < days; j++){
            if(item_price[i][j] >= item_price[i][j-1]){
                // printf("%d > %d",item_price[i][j+1],item_price[i][j]);
                max = j;
                // if (j == days - 1){
                //     printf("%d买进%d卖出，利润是%d\n",min,max,(item_price[i][max] - item_price[i][min]));
                //     profit += (item_price[i][max] - item_price[i][min]) ;
                // }
                // printf("max改变：%d",max);
            }else {
                profit += (item_price[i][max] - item_price[i][min]) * item[i];
                // printf("%d买进%d卖出，利润是%d\n",min,max,(item_price[i][max] - item_price[i][min]));
                // profit += (item_price[i][max] -// printf("第%d的总利润：%d\n",i,profit); item_price[i][min]) ;
                min = max = j;
            }
        }
        if(max == days-1 && min!= max){
            // printf("%d买进%d卖出，利润是%d\n",min,max,(item_price[i][max] - item_price[i][min]));
            profit += (item_price[i][max] - item_price[i][min]) * item[i];
        }
        // printf("第%d的总利润：%d\n",i,profit);
    }
	// printf("总利润：%d\n",profit);
	return profit;
}