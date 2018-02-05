#include <stdio.h>
#include <conio.h>
# define boyut 15

void DiziYazdir(int dizi[],int b)
{
	//dizinin ekrana yazdırılmasını yapan fonksiyon.
		int i;
		printf("\n");
		for (i=0;i<b;i++)
		printf("%d  ",dizi[i]);
}

void Birlestir(int dizi[], int sol, int orta, int sag)
{
	int i,j,k;
	
	//sol ve sağ yarım parçaların değerlerini saklayacak olan geçisi dizilerin boyuları
	int solboyut=orta-sol+1; //sol dizi boyutu
	int sagboyut=sag-orta; //sağ dizi boyutu
	
	//sol ve sağ yarımları tutan dizilerin tanımlanması
	int soldizi[solboyut];
	int sagdizi[sagboyut];
	
	//sol ve sağ yarım dizilere değerlerin aktarılması
	for(i=0;i<solboyut;i++)
		soldizi[i]=dizi[sol+i];
	for(i=0;i<sagboyut;i++)
		sagdizi[i]=dizi[orta+1+i];
			
	//dizilerin birleştirilmesi
	i=0;j=0; //yarım dizilerin indisleri için
	k=sol; //tam dizinin kopyalama noktası için
	
	//yarım diziler karşılaştırılarak kücük olan değer tam diziye aktarılıyor
	while(i<solboyut && j<sagboyut)
	{
		if (soldizi[i]<=sagdizi[j])
		{
			dizi[k]=soldizi[i];
			i++;
		}
		else
		{
			dizi[k]=sagdizi[j];
			j++;
		}
		k++;
	}
	
//	DiziYazdir(dizi, boyut);
	
	//yarım dizilerden soldakinde kopyalanmayan eleman varsa tam diziye kopyalanıyor
	while(i<solboyut)
	{
		dizi[k]=soldizi[i];
		i++;
		k++;
	}
	
	while(j<sagboyut)
	{
		dizi[k]=sagdizi[j];
		j++;
		k++;
	}	
}

void MergeSort(int dizi[], int sol, int sag)
{
	if (sol<sag) //tek elemanlı dizi oluncaya kadar diziyi böler.
	{
		int orta=sol+(sag-sol)/2;//dizinin orta noktasını buluyor tek yada çift sayılı olması bir şeyi değiştirmez
		
		MergeSort(dizi,sol,orta);
		MergeSort(dizi, orta+1, sag);
		
		Birlestir(dizi,sol,orta,sag);
	}	
}
int main()
{
		int dizi[]={10,9,8,11,8,1,5,6,11,16,0,3,6,17,10};
		
		printf("Dizi Sırasız\n");
		DiziYazdir(dizi, boyut);
		
		MergeSort(dizi,0,boyut-1);
		
		printf("\n\nDizi Sıralı\n");
		DiziYazdir(dizi, boyut);
		getch();
		return 0;		
}
