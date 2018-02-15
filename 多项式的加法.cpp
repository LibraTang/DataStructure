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

//读入多项式
polynomial readPoly(){
	polynomial p, rear, t;
	int n, c, e;
	
	printf("Enter n:"); //多项式项数 
	scanf("%d", &n);
	p = (polynomial)malloc(sizeof(struct polyNode)); //链表头空结点
	p->link = NULL;
	rear = p; 
	printf("Enter coef and expon:");
	while(n--){
		scanf("%d %d", &c, &e);
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
	polynomial t1, t2, p, rear;
	
	t1 = p1; t2 = p2;
	p = (polynomial)malloc(sizeof(struct polyNode)); //构造空结点 
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
	//有点不明白 
	rear->link = NULL;
	t2 = p;
	p = p->link;
	free(t2);
	return p;
}

polynomial mult(polynomial p1, polynomial p2){
	//逐项插入
	polynomial p, rear, t1, t2, t;
	int c, e;
	
	if(!p1 || !p2){
		return NULL;
	} 
	
	t1 = p1; t2 = p2;
	p = (polynomial)malloc(sizeof(struct polyNode)); //构造空结点
	p->link = NULL;
	rear = p;
	while(t2){ //先用p1的第一项乘以p2，得到p 
		attach(t1->coef * t2->coef, t1->expon + t2->expon, &rear);
		t2 = t2->link;
	} 
	t1 = t1->link;
	while(t1){
		t2 = p2; rear = p;
		while(t2){
			e = t1->expon + t2->expon;
			c = t1->coef * t2->coef;
			while(rear->link && rear->link->expon > e){ //判断指数是否小于下一项 
				rear = rear->link;
			}
			if(rear->link && rear->link->expon == e){ //若指数相等 
				if(rear->link->coef + c){
					rear->link->coef += c;
				}else{ //如果系数和为0，删除结点 
					t = rear->link;
					rear->link = t->link;
					free(t);
				}
			}else{ //插入链中 
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

