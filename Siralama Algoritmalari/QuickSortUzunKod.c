#include <stdio.h>
#include <conio.h>
# define boyut 15
void DiziYazdir(int dizi[])
{
	//dizinin ekrana yazdırılmasını yapan fonksiyon.
		int i;
		printf("\n");
		for (i=0;i<boyut;i++)
		printf("%d  ",dizi[i]);
}
void QuickSort(int dizi[], int bas, int son)
{
	int pivotindis=(bas+son)/2;
//	int pivotindis=son;	
//  int pivotindis=bas;
	int pivotdeger=dizi[pivotindis];
	int sol=bas;//dizinin en sol indisi
	int sag=son; // dizinin en sağ indisi
	int gecici;
		DiziYazdir(dizi); //dizinin çalışmasını adım adım görmek için yazıldı.
		printf("pivot=%d,   sol=%d,    sag=%d",pivotdeger,sol,sag);
		getch();
	do{
		while(dizi[sol]<pivotdeger)
			sol++;
		while(dizi[sag]>pivotdeger)
			sag--;
		if(sol<=sag) //2 ayrı indisin gösterdiği yerdeki elemanları değiştir
		{
			gecici=dizi[sol];
			dizi[sol]=dizi[sag];
			dizi[sag]=gecici;
			sol++; //göstericiler yeni konumlarına hareket etti
			sag--;
		}
		
	} while (sol<=sag);
	DiziYazdir(dizi);
	if (bas<sag) QuickSort(dizi,bas, sag);
	if (son>sol) QuickSort(dizi,sol, son);	
	return;
}
int main()
{
	int dizi[]={5,6,8,4,3,1,0,2,10,9,15,2,16,18,1};
	//int dizi[]={10,9,8,7,6,5,4,3,2,1,0};
	//int dizi[]={0,1,2,3,4,5,6,7,8,9,10};
	int bas=0;
	int son=boyut-1;
	int i;
	printf("Dizinin Sırasız şekli\n-----------------------\n");
	DiziYazdir(dizi);
		
	QuickSort(dizi,bas,son);
	
	DiziYazdir(dizi);
	getch();
	return 0;
}
