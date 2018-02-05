#include<stdio.h>
#include<conio.h>
void QuickSort(int dizi[],int bas,int son){
	int sol = bas;
	int sag = son;
	int gecici;
	int i;
	int pivot = (bas + son) / 2;
	do{
		while(dizi[sol] < dizi[pivot])
		sol++;
		while(dizi[sag] > dizi[pivot])
		sag--;
		if(sol <= sag){
			gecici = dizi[sol];
			dizi[sol] = dizi[sag];
			dizi[sag] = gecici;
			sol++;
			sag--;
		}
	}while(sol <= sag);
	
	for(i = 0; i < 10 ; i++){
		printf("%d   ", dizi[i]);
	}
	printf("\n");
	if(bas < sag) QuickSort(dizi,bas,sag);
	if(son > sol) QuickSort(dizi,sol,son);
}
main(){
	int dizi[] = {5,9,88,75,65,23,4,2,89,65};
	int bas = 0;
	int son = 10;
	QuickSort(dizi,bas,son);
}