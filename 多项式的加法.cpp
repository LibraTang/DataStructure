#include<stdio.h>

typedef struct polyNode *polynomial;
struct polyNode{
	int coef;
	int expon;
	polynomial link;
};

polynomial readPoly();
void attach(int c, int e, polynomial *pRear);
polynomial add(polynomial p1, polynomial p2);
polynomial mult(polynomial p1, polynomial p2);
void printPoly(polynomial p);

int main(){
	polynomial p1, p2, pp, ps;
	
	p1 = readPoly();
	p2 = readPoly();
	pp = mult(p1,p2);
	printPoly(pp);
	ps = add(p1,p2);
	printPoly(ps);
	
	return 0;
}

//读入多项式
polynomial readPoly(){
	polynomial p, rear, t;
	int n, c, e;
	
	printf("Enter n:"); //多项式项数 
	scanf("%d", &n);
	p = (polynomial)malloc(sizeof(struct polyNode)); //链表头空结点
	p->link = NULL;
	rear = p; 
	while(n--){
		printf("Enter coef and expon:");
		scanf("%d%d", &c, &e);
		attach(c, e, &rear);
	}
	//删除临时生成的头结点 
	t = p;
	p = p->link;
	free(t);
	
	return p;
} 

void attach(int c, int e, polynomial *pRear){ //pRear是指向指针的指针 
	polynomial p;
	
	p = (polynomial)malloc(sizeof(struct polyNode));
	p->coef = c; //给新结点赋值 
	p->expon = e;
	p->link = NULL;
	(*pRear)->link = p;
	*pRear = p; //修改pRear值 
}

polynomial add(polynomial p1, polynomial p2){
	polynomial t1, t2, p, rear, temp;
	
	t1 = p1; t2 = p2;
	p = (polynomial)malloc(sizeof(struct polyNode));
	p->link = NULL;
	rear = p;
	while(t1&&t2){
		if(t1->expon == t2->expon){
			p->coef = t1->coef + t2->coef;
			if(p->coef){
				attach(p->coef, t1->expon, &rear);
			}
			t1 = t1->link;
			t2 = t2->link;
		}else if(t1->expon > t2->expon){
			attach(t1->coef, t1->expon, &rear);
			t1 = t1->link;
		}else{
			attach(t2->coef, t2->expon, &rear);
			t2 = t2->link;
		}
	}
	while(t1){
		attach(t1->coef, t1->expon, &rear);
		t1 = t1->link;
	}
	while(t2){
		attach(t2->coef, t2->expon, &rear);
		t2 = t2->link;
	}
	//搞不懂 
	rear->link = NULL;
	temp = p;
	p = p->link;
	free(temp);
	return p;
}

polynomial mult(polynomial p1, polynomial p2){
	
}

void printPoly(polynomial p){
	int flag = 0; //辅助调整输出格式用
	
	if(!p){
		printf("0 0\n");
		return;
	} 
	while(p){
		if(!flag){
			flag = 1;
		}else{
			printf(" ");
			printf("%d%d",p->coef, p->expon);
			p = p->link;
		}
		printf("\n");
	}
}









//struct PolyNode{
//	int coef; //系数 
//	int expon; //指数
//	struct PolyNode *link; //指向下一结点的指针 
//};
//typedef struct PolyNode *Polynomial;
//Polynomial P1, P2;
//
//Polynomial PolyAdd(Polynomial P1, Polynomial P2){
//	Polynomial front, rear, temp;
//	int sum;
//	rear = (Polynomial)malloc(sizeof(struct PolyNode));
//	front = rear; //由front记录结果多项式链表头结点
//	while(P1&&P2){
//		switch(Compare(P1->expon, P2->expon)){
//			case 1:
//				Attach(P1->coef, P1->expon, &rear);
//				P1 = P1->link;
//				break;
//			case -1:
//				Attach(P2->coef, P2->expon, &rear);
//				P2 = P2->link;
//				break;
//			case 0:
//				sum = P1->coef + P2->coef;
//				if(sum){
//					Attach(sum, P1->expon, &rear);
//				}
//				P1 = P1->link;
//				P2 = P2->link;
//				break;
//		}
////		将未处理完的另一个多项式的所有结点依次复制到结果多项式中去
//		for(; P1; P1 = P1->link){
//			Attach(P1->coef, P1->expon, &rear);
//		} 
//		for(; P2; P2 = P2->link){
//			Attach(P2->coef, P2->expon, &rear);
//		}
//		rear->link = NULL;
//		temp = front;
//		front = front->link; //令front指向结果多项式第一个非零项
//		free(temp); //释放临时空表头结点
//		return front; 
//	} 
//}
//
//void Attach(int c, int e, Polynomial *pRear){
////	由于本函数中需要改变当前结果表达式尾项指针的值，
//// 	所以函数传递进来的是结点指针的地址，*pRear指向尾项
//	Polynomial P;
//	
//	P = (Polynomial)malloc(sizeof(struct PolyNode)); //申请新结点 
//	P->coef = c;
//	P->expon = e;
//	P->link = NULL;
//	(*pRear)->link = P;
//	*pRear = P; //修改pRear值 
//}
