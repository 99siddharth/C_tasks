#include <stdio.h>
#include<stdlib.h>
int main()

{
    int a[8];
    int flag,status,intr;
    int m,i,x,y;
     for(m=0;m<8;m++)
	    a[m]=0;
    printf("Enter the number: ");
    scanf("%d",&x);
    if(x>=256||x<0)
	{
		sleep(2);
		printf("Out of bounds\n");
	    exit(0);
	}
    for(i=0;x>0;i++)
    {
        y=x%2;
        x=x/2;
        a[i]=y;
    //	printf("%d",a[i]);   
    }
 //   printf("\n");
   // for(m=0;m<8;m++)
//	    printf("%d",a[m]);
    status=(a[0])+(a[1]*2)+(a[2]*4);
    intr=(a[3])+(a[4]*2)+(a[5]*4);
    flag=(a[6])+(a[7]*2);
	
    printf("\n Status= %d\n Interrupt= %d\n flag= %d\n",status,intr,flag);
/*
    printf("\nBinary ");
    for(j=7;j>=0;j--)
    {
        printf("%d",a[j]);
    }
  */
    return 0;

}
