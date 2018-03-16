#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *data;
	int length;
	int capacity; 
}TList;
TList *plist;

TList* list_init(int num){
	TList *p = (TList*)malloc(sizeof(TList));
	if(!p){printf("申请空间失败"); exit(0); }
	p->length = 0;
	p->capacity = num;
	int nsize = sizeof(int) * num;
	p->data = (int *)malloc(sizeof(nsize));
	if(!p->data){printf("申请空间失败"); free(p); exit(0); }
	return p;
}

void list_destroy(TList *p){
	if(p){
		if(p->data){
			free(p->data)
		}
		free(p);
	}
}

int get_item(TList *L, int idx){
	if((idx >= 0)&&(idx < L->length)){
		return L->data[idx];
	}else{
		printf("元素位置不合法");
		exit(0); 
	}
}

int list_locate(TList *L, int e){
	int i = 0;
	while((i < L->length)&&(L->data[i] != e)){
		i++;
	}
	if(i < L->length) return i;
	else{
		printf("查找的元素不存在");
		return 0;
	}
}

int list_insert(TList *L, int idx, int e){
	int i;
	if(L->length > L->capacity) return 1;
	else if(idx < 0) return -1;
	else{
		for(i = L->length; i > idx; i--){
			L->data[i] = L->data[i-1];
		}
		L->data[idx] = e;
		L->length++;
	}
	return 0;
}
