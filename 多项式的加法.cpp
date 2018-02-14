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

//�������ʽ
polynomial readPoly(){
	polynomial p, rear, t;
	int n, c, e;
	
	printf("Enter n:"); //����ʽ���� 
	scanf("%d", &n);
	p = (polynomial)malloc(sizeof(struct polyNode)); //����ͷ�ս��
	p->link = NULL;
	rear = p; 
	while(n--){
		printf("Enter coef and expon:");
		scanf("%d%d", &c, &e);
		attach(c, e, &rear);
	}
	//ɾ����ʱ���ɵ�ͷ��� 
	t = p;
	p = p->link;
	free(t);
	
	return p;
} 

void attach(int c, int e, polynomial *pRear){ //pRear��ָ��ָ���ָ�� 
	polynomial p;
	
	p = (polynomial)malloc(sizeof(struct polyNode));
	p->coef = c; //���½�㸳ֵ 
	p->expon = e;
	p->link = NULL;
	(*pRear)->link = p;
	*pRear = p; //�޸�pRearֵ 
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
	//�㲻�� 
	rear->link = NULL;
	temp = p;
	p = p->link;
	free(temp);
	return p;
}

polynomial mult(polynomial p1, polynomial p2){
	
}

void printPoly(polynomial p){
	int flag = 0; //�������������ʽ��
	
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
//	int coef; //ϵ�� 
//	int expon; //ָ��
//	struct PolyNode *link; //ָ����һ����ָ�� 
//};
//typedef struct PolyNode *Polynomial;
//Polynomial P1, P2;
//
//Polynomial PolyAdd(Polynomial P1, Polynomial P2){
//	Polynomial front, rear, temp;
//	int sum;
//	rear = (Polynomial)malloc(sizeof(struct PolyNode));
//	front = rear; //��front��¼�������ʽ����ͷ���
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
////		��δ���������һ������ʽ�����н�����θ��Ƶ��������ʽ��ȥ
//		for(; P1; P1 = P1->link){
//			Attach(P1->coef, P1->expon, &rear);
//		} 
//		for(; P2; P2 = P2->link){
//			Attach(P2->coef, P2->expon, &rear);
//		}
//		rear->link = NULL;
//		temp = front;
//		front = front->link; //��frontָ��������ʽ��һ��������
//		free(temp); //�ͷ���ʱ�ձ�ͷ���
//		return front; 
//	} 
//}
//
//void Attach(int c, int e, Polynomial *pRear){
////	���ڱ���������Ҫ�ı䵱ǰ������ʽβ��ָ���ֵ��
//// 	���Ժ������ݽ������ǽ��ָ��ĵ�ַ��*pRearָ��β��
//	Polynomial P;
//	
//	P = (Polynomial)malloc(sizeof(struct PolyNode)); //�����½�� 
//	P->coef = c;
//	P->expon = e;
//	P->link = NULL;
//	(*pRear)->link = P;
//	*pRear = P; //�޸�pRearֵ 
//}
