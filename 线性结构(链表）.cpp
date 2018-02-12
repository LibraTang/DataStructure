typedef struct LNode *PtrToNode;
struct LNode{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;
typedef PtrToNode List;

/*查找*/
#define ERROR NULL

Position Find(List L, ElementType X){
	Position p = L;/*p指向L的第一个结点*/ 
	
	while(p&&p->Data != X){
		p = p->Next;
	}
	
	return p;
} 

/*带头结点的插入*/
bool Insert(List L, ElementType X, Position P){
	/*默认L有头结点*/
	Position tmp, pre;
	
	/*查找P的前一个结点*/
	for(pre = L; pre&&pre->Next != P; pre = pre->Next);
	if(pre == NULL){
		printf("插入位置参数错误\n");
		return false;
	} else{
		tmp = (Position)malloc(sizeof(struct LNode));
		tmp->Data = X;
		/*顺序不能颠倒*/ 
		tmp->Next = P;
		pre->Next = tmp;
		return true; 
	}
} 

/*带头结点的删除*/
bool Delete(List L, Position P){
	Position tmp, pre;
	
	/*查找P的前一个结点*/
	for(pre = L; pre&&pre->Next != P; pre = pre->Next);
	if(pre == NULL || P == NULL){
		printf("删除位置参数错误");
		return false;
	} else{
		pre->Next = P->Next;
		free(P);
		return true;
	}
} 
