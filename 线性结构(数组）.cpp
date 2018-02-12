typedef int Position;
typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	Position Last;
};

/*初始化*/
List MakeEmpty(){
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L -> Last = -1;
	
	return L;
} 

/*查找*/
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

/*插入*/
bool Insert(List L, ElementType X, Position P){
	/*在L的指定位置P前插入一个新元素X*/
	Position i;
	if(L->Last == MAXSIZE - 1){
		/*表空间已满，不能插入*/
		printf("表满");
		return false; 
	}
	if(P < 0 || P > L->Last + 1){
		/*检测插入位置合法性*/
		printf("位置%d不存在元素",P);
		return false; 
	}
	for(i = L->Last; i >= P; i--){
		L->Data[i+1] = L->Data[i];
		L->Data[P] = X;
		L->Last++;
		return true;
	}
	
	/*删除*/
	bool Delete(List L, Position P){
		Position i;
		if(P < 0 || p > L->Last){
			printf("位置%d不存在元素",P);
			return false;
		}
		for(i = P + 1; i <= L->Last; i++){
			L->Data[i-1] = L->Data[i];
			L->Last--;
			return true;
		}
	} 
} 
