#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct nodetip{
	int val;
	struct nodetip * next;
};

typedef struct nodetip node;

node * nodeekle(int deger){
	node * ls = (node *)malloc(sizeof(node));
	ls -> val = deger;
	ls -> next = NULL;
	return ls;
}


node * ekle(node * ls , int deger){
	if(ls == NULL) return nodeekle(deger);
	node * yedek = ls;
	while(yedek -> next != NULL){
		yedek = yedek -> next;
	}
	yedek -> next = nodeekle(deger);
	return ls;
}


node * siraliekle(node * ls, int deger){
	if(ls == NULL) return nodeekle(deger);
	node * yedek = ls;
	if(deger < yedek -> val){
		node * yeni = nodeekle(deger);
		yeni -> next = ls;
		return yeni;
	}
	while(yedek -> next != NULL && yedek -> next -> val < deger)
		yedek = yedek -> next;
	if(yedek -> next == NULL){
		yedek -> next = nodeekle(deger);
		return ls;
	}else{
		node * yeni = nodeekle(deger);
		yeni -> next = yedek -> next;
		yedek -> next = yeni;
		return ls;
	}
}

node * arayaekle(node * ls,int deger,int indis){
	if(indis == 0){
		node * yeni = nodeekle(deger);
		yeni -> next = ls ;
		return yeni;
	}
	int sayac = 0;
	node * yedek = ls;
	while(yedek -> next != NULL && sayac < (indis - 1)){
		yedek = yedek -> next;
		sayac += 1;
	}
	node * yeni = nodeekle(deger);
	yeni -> next = yedek -> next;
	yedek -> next = yeni;
	return ls;
}

void ara(node * ls,int deger){
	if(ls == NULL){
		printf("Liste Boş");
	}
	else if(ls -> val == deger){
		printf("Aranan deger %d , 0. indistedir\n", deger);
	}
	else{
		node * yedek = ls;
		int sayac = 0;
		while(yedek != NULL && yedek -> val != deger){
			yedek = yedek -> next;
			sayac++;
		}
		if(yedek == NULL)
			printf("Deger Bulunamadi\n");
		else{
			printf("Aradiginiz deger %d , %d. indistedir\n\n",deger , sayac);
		}
	}
	
}

node * sil (node * ls, int deger){
	if(ls == NULL){
		printf("Liste Bostur.\n");
		return ls;
	}
	if(ls -> val == deger){
		ls = ls -> next;
		return ls;
	}
	node * yedek = ls;
	while(yedek != NULL && yedek -> next -> val != deger){
		yedek = yedek -> next;
	}
	if(yedek != NULL ){
		yedek -> next = yedek -> next -> next;
		return ls;
	}
	else{
		printf("Deger Bulunamadi.\n");
		return ls;
	}
}

void bubblesort(node * ls){
	if(ls == NULL || ls -> next == NULL) return;
	
	int takas = 1;
	node * yedek = ls;
	while(yedek -> next != NULL && takas == 1){
		node * ptr = ls;
		takas = 0;
		while(ptr -> next != NULL){
			if(ptr -> val > ptr -> next -> val){
				int yedekint = ptr -> val;
				ptr -> val = ptr -> next -> val;
				ptr -> next -> val = yedekint;
				takas = 1;
			}
			ptr = ptr -> next;
		}
		yedek = yedek -> next;
	}
}

void tersyazdir(node * ls){
	if(ls != NULL){
		tersyazdir(ls -> next);
		printf("%d   ",ls -> val);
		
	}
}

void yazdir(node * ls){
	while(ls != NULL){
		printf("%d   ",ls -> val);
		ls = ls -> next;
	}
}

main(){
	node * list = NULL;
	list = ekle(list,5);
	list = ekle(list,9);
	list = ekle(list,7);
	list = ekle(list,5768);
	list = ekle(list,135);
	list = ekle(list,14);
	list = ekle(list,79);
	list = arayaekle(list,999,9);
	
	//list = sil(list,7);
	//ara(list,999);
	bubblesort(list);
	
	yazdir(list);
	printf("\n\n");
	tersyazdir(list);
}
