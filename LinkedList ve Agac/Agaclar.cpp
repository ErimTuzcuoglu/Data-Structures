#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct nodetype{
	int val;
	struct nodetype * sol;
	struct nodetype * sag;
};

typedef struct nodetype node;

node * olustur(int deger){
	node * yeni = (node *) malloc(sizeof(node));
	yeni -> val = deger;
	yeni -> sol = NULL;
	yeni -> sag = NULL;
	return yeni;
}

node * ekle(node *kok ,int deger){
	if(kok == NULL) return olustur(deger);
	if(deger < kok -> val){
		kok -> sol = ekle(kok -> sol,deger);
	}else{
		kok -> sag = ekle(kok -> sag,deger);
	}
	return kok;
}

int derinlikbul(node * kok){
	if(kok == NULL) return -1;
	else{
		int solderinlik,sagderinlik;
		solderinlik = derinlikbul(kok -> sol);
		sagderinlik = derinlikbul(kok -> sag);
		if(solderinlik > sagderinlik){
			return solderinlik +=1;
		}else{
			return sagderinlik +=1;
		}
	}
}


int enkck(node * kok){
	while(kok -> sol != NULL){
		kok = kok -> sol;
	}
	return kok -> val;
}

int enbyk(node * kok){
	while(kok -> sag != NULL){
		kok = kok -> sag;
	}
	return kok -> val;
}

void preorder(node * kok){
	if(kok != NULL){
		printf("%d   ", kok -> val);
		preorder(kok -> sol);
		preorder(kok -> sag);
	}
}

void postorder(node * kok){
	if(kok != NULL){
		postorder(kok -> sag);
		printf("%d   ",kok -> val);
		postorder(kok -> sol);
	}
}

void inorder(node * kok){
	if(kok != NULL){
		inorder(kok -> sol);
		printf("%d   ",kok -> val);
		inorder(kok -> sag);
	}
}


node * sil(node * kok,int deger){
	if(kok == NULL) return NULL;
	if(kok -> val == deger){
		if(kok -> sag == kok -> sol){
			return NULL;
		}else if(kok -> sag == NULL){
			return kok -> sol;
		}else if(kok -> sol == NULL){
			return kok -> sag;
		}else{
			int sagdakienkucuk = enkck(kok -> sag);
			kok->val=sagdakienkucuk;
         	kok->sag=sil(kok->sag,sagdakienkucuk);
         	return kok;
		}
	}
	if(deger < kok -> val){
		kok -> sol = sil(kok -> sol, deger);
	}else{
		kok -> sag = sil(kok -> sag, deger);
	}
	return kok;
}

main(){
	
	node * root = NULL;
	root = ekle(root,97);
	root = ekle(root,1775);
	root = ekle(root,54);
	root = ekle(root,196);
	root = ekle(root,374);
	root = ekle(root,16);
	root = ekle(root,468);
	root = ekle(root,752);
	
	printf("Derinlik : %d \nEn Buyuk : %d \nEn Kucuk : %d\n",derinlikbul(root),enbyk(root),enkck(root));
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	inorder(root);
}
