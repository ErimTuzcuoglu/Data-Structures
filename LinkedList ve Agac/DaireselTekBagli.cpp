#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct nodetype{
	int val;
	struct nodetype * sonraki;
};

typedef struct nodetype node;


node * olustur(int deger){
	node * ls = (node *)malloc(sizeof(node));
	ls -> val = deger; 
	ls -> sonraki = ls;
	return ls;
}

node * sonaekle(node *ls , int deger){
	if(ls == NULL) return olustur(deger);
	node * yedek = ls;
	while(yedek -> sonraki != ls){
		yedek = yedek -> sonraki;
	}
	yedek -> sonraki = olustur(deger);
	yedek -> sonraki -> sonraki = ls;
	return ls;
}

node * siraliekle(node * ls, int deger){
	if(ls == NULL) return olustur(deger);
	node * yeni = olustur(deger);
	
	if(ls -> val > deger){
		yeni -> sonraki = ls;
		while(ls -> sonraki != ls){
			ls = ls -> sonraki;
		}
		ls -> sonraki = yeni;
		return yeni;
	}
	
	node * yedek = ls;
	while(yedek -> sonraki != ls && yedek -> sonraki -> val < deger){
		yedek = yedek -> sonraki;
	}
	if(yedek -> sonraki == ls){
		yedek -> sonraki = yeni;
		yeni -> sonraki = ls;
		return ls;
	}
	yeni -> sonraki = yedek -> sonraki;
	yedek -> sonraki = yeni;
	return ls;
}


node * arayaekle(node * ls,int deger,int indis){
	node * yeni = olustur(deger);
	node * yedek = ls;
	if(indis == 0){
		yeni -> sonraki = ls;
		while(ls -> sonraki != yedek)
			ls = ls -> sonraki;
		ls -> sonraki = yeni;
		return yeni;
	}
	int sayac = 0;
	while(yedek -> sonraki != ls && sayac < (indis - 1)){
		yedek = yedek -> sonraki;
		sayac++;
	}
	if(yedek -> sonraki == ls){
		yeni -> sonraki = ls;
		yedek -> sonraki = yeni;
		return ls;
	}else{
		yeni -> sonraki = yedek -> sonraki;
		yedek -> sonraki = yeni;
		return ls;
	}
}

void ara(node * ls,int deger){
	if(ls -> val == deger){
		printf("Aradiginiz deger % d, 0. indistedir.\n",deger);
		return;
	}
	int sayac = 0;
	node * yedek = ls;
	while(yedek -> sonraki != ls && yedek -> val != deger){
		yedek = yedek -> sonraki;
		sayac++;
	}
	if(yedek -> sonraki == ls && yedek -> val != deger){
		printf("Deger Bulunamadi.\n");
	}
	else{
		printf("Aradiginiz deger %d, %d. indistedir.\n",deger , sayac);
	}
}

void yazdir(node * ls){
	node * yedek = ls;
	do{
		printf("%d   ",ls -> val);
		ls = ls -> sonraki;
	}while(ls != yedek);
}

node * sil(node * ls, int deger){
	node * yedek = ls;
	if(ls -> val == deger){
		while(yedek -> sonraki != ls){
			yedek = yedek -> sonraki;
		}
		yedek -> sonraki = yedek -> sonraki -> sonraki;
		ls = ls -> sonraki;
		return ls;
	}
	while(yedek -> sonraki != ls && yedek -> sonraki -> val != deger){
		yedek = yedek -> sonraki;
	}
	if(yedek -> sonraki == ls){
		printf("Deger Bulunamadi.\n");
		return ls;
	}else{
		yedek -> sonraki = yedek -> sonraki -> sonraki;
		return ls;
	}
}

void bubblesort(node * ls){
	if (ls-> sonraki == ls ) return;
	
	int takas = 1;
	node * ptr = ls;
	while(ptr -> sonraki != ls && takas == 1){
		node * ptr2 = ls;
		takas = 0;
		while(ptr2 -> sonraki != ls){
			if(ptr2 -> val > ptr2 -> sonraki -> val){
				int sakla = ptr2 -> val;
				ptr2 -> val = ptr2 -> sonraki -> val;
				ptr2 -> sonraki -> val = sakla;
				takas = 1;
			}
			ptr2 = ptr2 -> sonraki;
		}
		ptr = ptr ->  sonraki;
	}
}


main(){
	node * list = NULL;
	list = sonaekle(list, 5);
	list = sonaekle(list, 534);
	list = sonaekle(list, 2424);
	list = sonaekle(list, 74);
	list = sonaekle(list, 39);
	list = sonaekle(list, 16);
	list = sonaekle(list, 436);
	
	list = arayaekle(list, 999, 9);
	ara(list,534);
	list = sil(list, 5);
	
	bubblesort(list);
	
	printf("\n\n");
	yazdir(list);
}
