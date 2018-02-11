#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
	int value;
	struct _node *next;
} Node;

typedef struct _list{
	Node *head;
} List;
 
void add(List *pList, int number);
void print(List *pList);

int main(){
	Node *head = NULL;
	List list;
	int number;
	list.head = NULL;
	do{
		scanf("%d",&number);
		if(number != -1){
			add(&list, number);
		}
	}while(number != -1);
	print(&list);
	//Á´±íËÑË÷ 
	scanf("%d",&number);
	Node *p;
	int isFound = 0;
	for(p = list.head; p; p = p->next){
		if(p->value == number){
			printf("Found\n");
			isFound = 1;
			break;
		}
	}
	if(!isFound){
		printf("Not found\n");
	} 
	//Á´±íÉ¾³ý
	 Node *q;
	for( q = NULL, p = list.head; p; q = p, p = p->next){
		if(p->value == number){
			if(q){
				q->next = p->next;
			}else{
				list.head = p->next;
			}
			free(p);
			break;
		}
	}
	//Á´±íÇå³ý
	for(p = head; p; p = q){
		q = p->next;
		free(p);
	}
	
	return 0;
}

void add(List *pList, int number){
	//add to linked-list
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	//find the last
	Node *last = pList->head;
	if(last){
		while(last->next){
			last = last->next;
		}
		//attach
		last->next = p;
	}else{
		pList->head = p;
	}
}

void print(List *pList){
	Node *p;
	for(p = pList->head; p; p = p->next){
		printf("%d\t",p->value);
	}
	printf("\n");
}
