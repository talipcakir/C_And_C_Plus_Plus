#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//uygulama denemesi

int main()
{
	setlocale(LC_ALL, "Turkish"); //türkçe desteði için locasyon belirledik.
	
	int girdi1,girdi2;
	
	printf("Uygulamamýza hoþgeldiniz.\n");
	printf("1. alt alta yaz\n");
	printf("2. yan yana yaz\n");
	printf("3. kare yaz\n");
	printf("4. yýldýz yaz\n");
	printf("5. içi boþ kare yaz\n");
	
	scanf("%d", &girdi1);
	
	printf("Kaç karakterli olsun.\n");
	scanf("%d", &girdi2);
	
	if(girdi1 ==1)
	{
		for(int i=0;i<girdi2;i++)
		{
			printf("*\n");
		}
	}
	if(girdi1 ==2)
	{
		for(int i=0;i<girdi2;i++)
		{
			printf("*");
		}
	}
	if(girdi1 == 3)
	{
		for(int i=0;i<girdi2;i++)
		{
			for(int j=0;j<girdi2;j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	if(girdi1 == 4)
	{
		for(int i=0;i<girdi2;i++)
		{
			for(int j=0;j<i+1;j++)
			{
				printf("*");	
			}
			printf("\n");
		}
	}
	if(girdi1 == 5)
	{
		for(int i=0;i<girdi2;i++)
		{
			printf("*");
		}
		printf("\n");
		for(int i=0;i<girdi2;i++)
		{
			for(int j=0;j<1;j++)
			printf("*");
			for(int k=0;k<girdi2-2;k++)
			printf(" ");
			for(int l=0;l<1;l++)
			printf("*");
			printf("\n");
		}
		for(int i=0;i<girdi2;i++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	printf("\n\n\nTalip ÇAKIR\n\n\n");
	system("PAUSE");
}
