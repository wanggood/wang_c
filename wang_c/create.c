#include"my.h"
#include<string.h>
struct student {
	char name[20];
	char sex;
	int num;
	struct student *pnext;
};
void scan(){
	scanf("%*[^\n]");
	scanf("%*c");
}
struct student *create(){
	struct student *phead=NULL;
	struct student *pend, *pnew;
	pnew=(struct student*)malloc(sizeof(struct student));
	printf("input then name,sex,num:\n");
	scanf("%s",&pnew->name);
	scanf("%*[^\n]");
	scanf("%*c");
	scanf("%c",&pnew->sex);
	scanf("%*[^\n]");
	scanf("%*c");
	scanf("%d",&pnew->num);
	pnew->pnext=phead;
	pend=pnew;
	phead=pnew;
	pnew=(struct student*)malloc(sizeof(struct student));
	strcpy(pnew->name,"jimi");
	pnew->sex='m';
	pnew->num=99;
	pnew->pnext=NULL;
	pend->pnext=pnew;
	pend=pnew;
	return phead;
}

struct student *lisert(struct student *phead){
	struct student *pnew, *pend, *phea;
	int i=0,num=0;
	phea=phead;
	while(1){
	    phea=phea->pnext;
		if(phea->pnext == NULL){
			break;
		}
	}
	printf("input then number: ");
	scanf("%d",&i);
	while(i != 0){
		pnew=(struct student*)malloc(sizeof(struct student));
		printf("input then name,sex,num:\n");
		scanf("%s",&pnew->name);scan();
		scanf("%c",&pnew->sex);scan();
		scanf("%d",&pnew->num);scan();
		pnew->pnext=NULL;
		phea->pnext=pnew;
		phea=pnew;
		--i;
	}
}

void print(struct student *phead){
	struct student *phea;
	phea=phead;
	while(phea != NULL){
		printf("%6s%6c%6d\n",phea->name,phea->sex,phea->num);
		phea=phea->pnext;
	}
}

int dele(struct student *phead, int num){
	struct student *phea, *pend, *pdel;
	phea=phead;
	int i;
	if(num <= 0 || num > phead_size(phead)){
		printf("Remove the number does not exist\n");return 0;
	}
	for(i=1;i<num-1;++i){
		phea=phea->pnext;
	}
	pend=phea->pnext;
	phea->pnext=pend->pnext;
	free(pend);
}

int phead_size(struct student *phead){
	struct student *phe;
	phe=phead;
	int sum=0;
	while(phe != NULL ){
		phe=phe->pnext;
		sum++;
	}
	return sum;
}

int main(void){
	struct student *phead;
	phead=create();
	lisert(phead);
	print(phead);
	int i;
	printf("input del num:");
	scanf("%d",&i);
	dele(phead,i);
	printf("-------------------\n");
	print(phead);
	printf("the number of list: %d\n",phead_size(phead));
	free(phead);
	return 0;
}
