#include <stdio.h>
#define arr_size 10
int binary_search(int *ptr , int size , int Num)
{
	int Lo=0 , Hi=size-1 , Mid;
	while(Hi>= Lo)
	{
		Mid=(Hi+Lo)/2;
		if (ptr[Mid]>Num)
			Hi=Mid-1;
		else if(ptr[Mid]<Num)
			Lo=Mid+1;
		else 
			return Mid ;
	}
	return -1 ;
}

int main(void)
{
	int arr[]={5,8,13,14,15,18,20,55,60,90};
	int key = 55 ;
	int index = binary_search(arr,arr_size,key);
	if (index<0)
	{
		printf("Number not found\n");
	}
	else
	{
	printf("the number index = %d\n",index);
	}
	return 0 ;
}
