typedef struct SNode *PtrToSNode;
struct SNode{
	ElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack(){
	/*构建一个堆栈的头结点，返回该结点指针*/
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S; 
}

bool IsEmpty(Stack S){
	return (S->Next == NULL);
}

bool Push(Stack S, ElementType X){
	PtrToSNode TmpCell;
	
	TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	TmpCell->Data = X;
	S->Next = TmpCell;
	return true;
}

ElementType Pop(Stack S){
	PtrToSNode FirstCell;
	ElementType TopElem;
	
	if(IsEmpty(S)){
		printf("堆栈空");
		return ERROR;
	}else{
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next =  FirstCell->Next;
		free(FirstCell);
		return TopElem; 
	}
}
