// asd.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	FILE *fp1,*fp2,*fp3;
	int result,num[2];
	int i,k,n;	//i����������nΪ��������k����������Ŀ���������mΪ������Ŀ���������
	int sign,rage;	//sign���������������ͣ�rageΪ�������㷶Χ

	srand((unsigned int)time(NULL));
	if(!(fp1 = fopen("Exercises.txt","w+")))	/*��ֻд��ʽ��*/
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

	printf("����������Ҫ��ӡ������������Ŀ������");
	scanf("%d",&n);
	printf("����������Ҫ��ӡ������������㷶Χ��");
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



