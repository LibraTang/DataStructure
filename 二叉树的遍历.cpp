void InorderTraversal(BinTree BT){ //中序遍历 
	if(BT){
		InorderTraversal(BT->Left);
		printf("%d",BT->Data);
		InorderTraversal(BT->Right);
	}
}

void PreorderTraversal(BinTree BT){ //先序遍历 
	if(BT){
		printf("%d",BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void PostorderTraversal(BinTree BT){ //后序遍历 
	if(BT){
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf("%d",BT->Data);
	}
}

void LevelorderTraversal(BinTree BT){ //层序遍历 
	Queue Q;
	BinTree T;
	
	if(!BT){
		return;
	}
	
	Q = CreateQueue(); //创建空队列
	AddQ(Q, BT);
	while(!IsEmpty(Q)){
		T = DeleteQ(Q);
		printf("%d",T->Data); //访问取出队列的结点
		if(T->Left){
			AddQ(Q, T->Left);
		} 
		if(T->Right){
			AddQ(Q, T->Right); 
		}
	} 
}
