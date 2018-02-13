struct PolyNode{
	int coef; //ϵ�� 
	int expon; //ָ��
	struct PolyNode *link; //ָ����һ����ָ�� 
};
typedef struct PolyNode *Polynomial;
Polynomial P1, P2;

Polynomial PolyAdd(Polynomial P1, Polynomial P2){
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear; //��front��¼�������ʽ����ͷ���
	while(P1&&P2){
		switch(Compare(P1->expon, P2->expon)){
			case 1:
				Attach(P1->coef, P1->expon, &rear);
				P1 = P1->link;
				break;
			case -1:
				Attach(P2->coef, P2->expon, &rear);
				P2 = P2->link;
				break;
			case 0:
				sum = P1->coef + P2->coef;
				if(sum){
					Attach(sum, P1->expon, &rear);
				}
				P1 = P1->link;
				P2 = P2->link;
				break;
		}
//		��δ���������һ������ʽ�����н�����θ��Ƶ��������ʽ��ȥ
		for(; P1; P1 = P1->link){
			Attach(P1->coef, P1->expon, &rear);
		} 
		for(; P2; P2 = P2->link){
			Attach(P2->coef, P2->expon, &rear);
		}
		rear->link = NULL;
		temp = front;
		front = front->link; //��frontָ��������ʽ��һ��������
		free(temp); //�ͷ���ʱ�ձ�ͷ���
		return front; 
	} 
}

void Attach(int c, int e, Polynomial *pRear){
//	���ڱ���������Ҫ�ı䵱ǰ������ʽβ��ָ���ֵ��
// 	���Ժ������ݽ������ǽ��ָ��ĵ�ַ��*pRearָ��β��
	Polynomial P;
	
	P = (Polynomial)malloc(sizeof(struct PolyNode)); //�����½�� 
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P; //�޸�pRearֵ 
}
