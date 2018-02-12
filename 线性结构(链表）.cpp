typedef struct LNode *PtrToNode;
struct LNode{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;
typedef PtrToNode List;

/*����*/
#define ERROR NULL

Position Find(List L, ElementType X){
	Position p = L;/*pָ��L�ĵ�һ�����*/ 
	
	while(p&&p->Data != X){
		p = p->Next;
	}
	
	return p;
} 

/*��ͷ���Ĳ���*/
bool Insert(List L, ElementType X, Position P){
	/*Ĭ��L��ͷ���*/
	Position tmp, pre;
	
	/*����P��ǰһ�����*/
	for(pre = L; pre&&pre->Next != P; pre = pre->Next);
	if(pre == NULL){
		printf("����λ�ò�������\n");
		return false;
	} else{
		tmp = (Position)malloc(sizeof(struct LNode));
		tmp->Data = X;
		/*˳���ܵߵ�*/ 
		tmp->Next = P;
		pre->Next = tmp;
		return true; 
	}
} 

/*��ͷ����ɾ��*/
bool Delete(List L, Position P){
	Position tmp, pre;
	
	/*����P��ǰһ�����*/
	for(pre = L; pre&&pre->Next != P; pre = pre->Next);
	if(pre == NULL || P == NULL){
		printf("ɾ��λ�ò�������");
		return false;
	} else{
		pre->Next = P->Next;
		free(P);
		return true;
	}
} 
