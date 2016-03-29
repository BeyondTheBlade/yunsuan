// asd.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	FILE *fp1,*fp2,*fp3;
	int result,num[2];
	int i,k,n;	//i计数题数，n为总题数，k计数单个题目运算符数，m为单个题目总运算符数
	int sign,rage;	//sign计数四则运算类型，rage为四则运算范围

	srand((unsigned int)time(NULL));
	if(!(fp1 = fopen("Exercises.txt","w+")))	/*以只写方式打开*/
	{
		printf("Destination file 1 cannot be opened\n");
		exit(1);
	}
	if(!(fp2 = fopen("Answers.txt","w+")))
	{
		printf("Destination file 1 cannot be opened\n");
		exit(1);
	}
	if(!(fp3 = fopen("Grade.txt","w+")))
	{
		printf("Destination file 1 cannot be opened\n");
		exit(1);
	}

	printf("请输入你想要打印的四则运算题目个数：");
	scanf("%d",&n);
	printf("请输入你想要打印的四则运算计算范围：");
	scanf("%d",&rage);

	for(i = 0; i < n; i++)
	{
		sign = rand() % 4;
		for(k = 0; k < 2 ; k++)
			*(num+k) = rand() % rage;	

		fprintf(fp1,"%d. %d",i+1,*num);
		result = *num;
		switch(sign)
		{
		case 0:
			fprintf(fp1," + %d",*(num+1));
			result = *num + *(num+1);
			break;
		case 1:
			result = *num + *(num+1);
			while(result < *(num+1))
				*(num+1) = rand() % rage;
			fprintf(fp1," - %d",*(num+1));
			result = *num + *(num+1);
			break;
		case 2:
			fprintf(fp1," * %d",*(num+1));
			result = *num * *(num+1);	
			break;
		case 3:
			while(*(num+1) == 0)
				*(num+1) = rand() % rage;
			result = *num / *(num+1);
			fprintf(fp1," / %d",*(num+1));
			break;
		default:
			fprintf(fp1,"Unkwon fault happened.\n");
			exit(1);
		}
		fprintf(fp1," = \n");
		fprintf(fp2,"%d. %d\n",i+1,result);
	}
	system("PAUSE");
	return 0;
}



