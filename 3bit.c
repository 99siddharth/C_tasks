#include<stdio.h>
void main()
{
	int i;
	unsigned char val;
	unsigned int temp;
	val=0;
	for(i=0;i<3;i++)
	{
		printf("Enter the number: ");
		scanf("%d",&temp);
		val|=1<<temp;
//		printf("%d",val);
		getchar();
//		printf("i=%d temp=%d val=%d\n", i, temp, val);
	}
//	printf("%d",val);
	for(i=0;i<8;i++)
	{
		if(val&(1<<i))
			printf("%d",i);

	}
}
