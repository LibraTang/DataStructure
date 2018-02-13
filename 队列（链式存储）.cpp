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
		printf("队列空");
		return ERROR;
	}else{
		FrontCell = Q->Front;
		if(Q->Front == Q->Rear){/*如果队列只有一个元素*/ 
			Q->Front = Q->Rear = NULL;
		}else{
			Q->Front = Q->Front->Next;
		}
		FrontElem = FrontCell->Data;
		
		free(FrontCell);
		return FrontElem;
	}
}
