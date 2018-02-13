typedef struct Node *PtrToNode;
struct Node{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode{
	Position Front, Rear;
	int MaxSize;
};
typedef struct QNode *Queue;

bool IsEmpty(Queue Q){
	return (Q->Front == NULL);
}

ElementType DeleteQ(Queue Q){
	Position FrontCell;
	ElementType FrontElem;
	
	if(IsEmpty(Q)){
		printf("���п�");
		return ERROR;
	}else{
		FrontCell = Q->Front;
		if(Q->Front == Q->Rear){/*�������ֻ��һ��Ԫ��*/ 
			Q->Front = Q->Rear = NULL;
		}else{
			Q->Front = Q->Front->Next;
		}
		FrontElem = FrontCell->Data;
		
		free(FrontCell);
		return FrontElem;
	}
}
