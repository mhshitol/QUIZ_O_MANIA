#include<stdio.h>
#include<conio.h>
#include<windows.h> //windows header is used to implement the the sleep operation
int main()
{
	int h=0,m=0,s=10,ms=0; //here h=hour m=minute s=seconds ms=milisecond
				while(1)
				{
					printf("      \r%d:%d:%d",h,m,s);
					Sleep(1000); //it is approximately 1 second
					if(s!=0)
					{
						s--;
					}
					if(s==0 && m!=0)
					{
						s=59;
						m--;
					}
					if(s==0 && m==0 && h!=0)
					{
						h--;
						m=59;
						s=59;
					}
					if(h==0 && m==0 && s==0)
					{
						exit(0);
					}
				}
}
