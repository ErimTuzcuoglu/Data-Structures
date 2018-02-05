#include<stdio.h>
#include<conio.h>

main(){
	
	int dizi[10],takas;

for (int i = 0; i < 10 ; i++){
	printf("%d. sayiyi giriniz: ",(i+1));
	scanf("%d ",&dizi[i]);
}
for(int i = 0; i < 10; i++){
	for(int j = 0; j < 10; j++){
		if(dizi[j]>dizi[j+1]){
			takas = dizi[j];
			dizi[j] = dizi[j+1];
			dizi[j+1] = takas;
		}
	}
}
for(int q = 0 ; q < 10 ; q++){
	printf("%d.) : %d\n",q+1,dizi[q]);
}
	
}
