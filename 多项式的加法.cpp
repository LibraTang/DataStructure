#include<stdio.h>
#include<stdlib.h>

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
	printf("Enter coef and expon:");
	while(n--){
		scanf("%d %d", &c, &e);
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
	polynomial t1, t2, p, rear;
	
	t1 = p1; t2 = p2;
	p = (polynomial)malloc(sizeof(struct polyNode)); //����ս�� 
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
	//�е㲻���� 
	rear->link = NULL;
	t2 = p;
	p = p->link;
	free(t2);
	return p;
}

polynomial mult(polynomial p1, polynomial p2){
	//�������
	polynomial p, rear, t1, t2, t;
	int c, e;
	
	if(!p1 || !p2){
		return NULL;
	} 
	
	t1 = p1; t2 = p2;
	p = (polynomial)malloc(sizeof(struct polyNode)); //����ս��
	p->link = NULL;
	rear = p;
	while(t2){ //����p1�ĵ�һ�����p2���õ�p 
		attach(t1->coef * t2->coef, t1->expon + t2->expon, &rear);
		t2 = t2->link;
	} 
	t1 = t1->link;
	while(t1){
		t2 = p2; rear = p;
		while(t2){
			e = t1->expon + t2->expon;
			c = t1->coef * t2->coef;
			while(rear->link && rear->link->expon > e){ //�ж�ָ���Ƿ�С����һ�� 
				rear = rear->link;
			}
			if(rear->link && rear->link->expon == e){ //��ָ����� 
				if(rear->link->coef + c){
					rear->link->coef += c;
				}else{ //���ϵ����Ϊ0��ɾ����� 
					t = rear->link;
					rear->link = t->link;
					free(t);
				}
			}else{ //�������� 
				t = (polynomial)malloc(sizeof(struct polyNode));
				t->coef = c; t->expon = e;
				t->link = rear->link;
				rear->link = t;
				rear = rear->link; 
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = p;
	p = p->link;
	free(t2);
	
	return p;
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

