#include<stdio.h>
#include<conio.h>
main(){
	int dizi[10] = {4,99,87,5,2,15,68,7,1,9};
	int takas;
	
	for(int i = 0; i < 10; i++){
		for(int j = i;j < 10; j++){
			if(dizi[i] > dizi [j]){
				takas = dizi[j];
				dizi[j] = dizi[i];
				dizi[i] = takas;
			}
		}
	}
	
	for(int i = 0;i < 10; i++){
		printf("%d.) : %d\n",(i+1),dizi[i]);
	}
	
}
