#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct nodetype{
	int val;
	struct nodetype * sonraki;
	struct nodetype * onceki;
};

typedef struct nodetype node;

node * olustur(int deger){
	node * ls = (node *) malloc(sizeof(node));
	ls -> sonraki = NULL;
	ls -> onceki = NULL;
	ls -> val = deger;
	return ls;
}

node * sonaekle(node * ls , int deger){
	if(ls == NULL) return olustur(deger);
	node * yedek = ls;
	while(yedek -> sonraki != NULL){
		yedek = yedek -> sonraki;
	}
	yedek -> sonraki = olustur(deger);
	yedek -> sonraki -> onceki = yedek;
	return ls;
}

node * siraliekle(node * ls, int deger){
	if(ls == NULL) return olustur(deger);
	node * yedek = ls;
	node * yeni = olustur(deger);
	if(yedek -> val > deger){
		yeni -> sonraki = yedek;
		yedek -> onceki = yeni;
		return yeni;
	}
	while(yedek -> sonraki != NULL && yedek -> sonraki -> val < deger){
		yedek = yedek -> sonraki;
	}
	if(yedek -> sonraki == NULL){
		yedek -> sonraki = yeni;
		yeni -> onceki = yedek;
		return ls;
	}else{
		yeni -> sonraki = yedek -> sonraki;
		yedek -> sonraki -> onceki = yeni;
		yedek -> sonraki = yeni;
		yeni -> onceki = yedek;
		return ls;
	}
}

node * arayaekle(node*  ls, int deger ,int indis){
	node * yeni = olustur(deger);
	if(indis == 0){
		yeni -> sonraki = ls;
		ls -> onceki = yeni;
		return yeni;
	}
	node * yedek = ls;
	int sayac = 0;
	while(yedek -> sonraki != NULL && sayac < (indis-1) ){
		yedek = yedek -> sonraki;
		sayac++;
	}
	if(yedek -> sonraki == NULL){
		yedek -> sonraki = yeni;
		yeni -> onceki = yedek;
		return ls;
	}else{
		yeni -> sonraki = yedek -> sonraki;
		yedek -> sonraki -> onceki = yeni;
		yedek -> sonraki = yeni;
		yeni -> onceki = yedek;
		return ls;
	}
}

void ara(node * ls,int deger){
	if(ls -> val == deger){
		printf("Aradiginiz deger 0. indistedir.\n");
		return;
	}
	int sayac = 0;
	node * yedek = ls;
	while(yedek -> sonraki != NULL && yedek -> sonraki -> val != deger){
		yedek = yedek -> sonraki;
		sayac ++;
	}
	if(yedek -> sonraki == NULL){
		printf("Deger Bulunamadi.\n");
	}else{
		printf("Aradiginiz deger %d. indistedir\n",sayac+1);
	}
}

node * sil(node * ls,int deger){
	if(ls -> val == deger){
		ls = ls -> sonraki;
		ls -> onceki = NULL;
		return ls;
	}
	node * yedek = ls;
	while(yedek -> sonraki != NULL && yedek -> sonraki -> val != deger){
		yedek = yedek -> sonraki;
	}
	if(yedek -> sonraki == NULL){
		printf("Deger Bulunamadi \n");
		return ls;
	}else if(yedek -> sonraki -> sonraki == NULL){
		yedek -> sonraki = NULL;
		return ls;
	}
	else{
		yedek -> sonraki = yedek -> sonraki -> sonraki;
		yedek -> sonraki -> onceki = yedek;
		return ls;
	}
}


void bubblesort(node * ls){
	if(ls == NULL || ls -> sonraki == NULL) return;
		
		int takas = 1;
		node * yedek = ls;
		while(yedek -> sonraki != NULL && takas == 1){
			takas = 0;
			node * yedek2 = ls;
			while(yedek2 -> sonraki != NULL){
				if(yedek2 -> val > yedek2 -> sonraki -> val){
					int tut = yedek2 -> val;
					yedek2 -> val = yedek2 -> sonraki -> val;
					yedek2 -> sonraki -> val = tut;
					takas = 1;
				}
				yedek2 = yedek2 -> sonraki;
			}
			yedek = yedek -> sonraki;
		}
}


void yazdir(node *ls,int yon){
	if(yon == 1){
		while(ls != NULL){
			printf("%d   ",ls -> val);
			ls = ls -> sonraki;
		}
	}
	else{
		while(ls -> sonraki != NULL){
			ls = ls -> sonraki;
		}
		while(ls != NULL){
			printf("%d   ",ls-> val);
			ls = ls -> onceki;
		}
	}
	
}

main(){
	node * ls = NULL;
	ls = sonaekle(ls,5);
	ls = sonaekle(ls,86);
	ls = sonaekle(ls,74);
	ls = sonaekle(ls,34);
	ls = sonaekle(ls,79);
	ls = sonaekle(ls,8754);
	ls = sonaekle(ls,4554);
	ls = sonaekle(ls,14987);
	ls = arayaekle(ls, 9887,7);
	
	//ls = sil(ls,5);
	ara(ls,14987);
	
	//bubblesort(ls);
	
	yazdir(ls,1);
	printf("\n");
	yazdir(ls,9);
}
