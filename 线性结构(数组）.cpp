typedef int Position;
typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	Position Last;
};

/*��ʼ��*/
List MakeEmpty(){
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L -> Last = -1;
	
	return L;
} 

/*����*/
#define ERROR -1

Position Find (List L, ElementType X){
	Position i = 0;
	
	while(i <= L -> Last){
		i++;
	}
	if(i > L -> Last){
		return ERROR;
	}else{
		return i;
	}
} 

/*����*/
bool Insert(List L, ElementType X, Position P){
	/*��L��ָ��λ��Pǰ����һ����Ԫ��X*/
	Position i;
	if(L->Last == MAXSIZE - 1){
		/*��ռ����������ܲ���*/
		printf("����");
		return false; 
	}
	if(P < 0 || P > L->Last + 1){
		/*������λ�úϷ���*/
		printf("λ��%d������Ԫ��",P);
		return false; 
	}
	for(i = L->Last; i >= P; i--){
		L->Data[i+1] = L->Data[i];
		L->Data[P] = X;
		L->Last++;
		return true;
	}
	
	/*ɾ��*/
	bool Delete(List L, Position P){
		Position i;
		if(P < 0 || p > L->Last){
			printf("λ��%d������Ԫ��",P);
			return false;
		}
		for(i = P + 1; i <= L->Last; i++){
			L->Data[i-1] = L->Data[i];
			L->Last--;
			return true;
		}
	} 
} 
