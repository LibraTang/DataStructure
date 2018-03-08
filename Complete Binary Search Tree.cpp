//Complete Binary Search Tree

void solve(int ALeft, int ARight, int TRoot){
	//��ʼ����Ϊ solve(0, N-1, 0)
	n = ARight - ALeft + 1;
	if(n == 0) return; //�Ѿ��ź��� 
	L = GetLeftLength(n); //�����n���������������� �ж��ٸ����
	T[TRoot] = A[ALeft + L];
	LeftTRoot = TRoot * 2 + 1;
	RightTRoot = LeftTRoot + 1;
	//�ݹ�
	solve(ALeft, ALeft+L-1, LeftTRoot); //���������
	solve(ALeft+L+1, ARight, RightTRoot); //��������� 
} 

//�ڽ���������ǰ����Ҫ�Ƚ���ȫ���������鰴˳���ź�
#include<stdlib.h>
int main(){
	......
	qsort(A, N, sizeof(int), compare); //����compare�ǱȽϴ�С�ĺ���,������Ҫ��д 
	...... 
} 

int compare(const void*a, const void*b){
	return *(int*)a - *(int*)b;
} 

//������������ģ
int GetLeftLength(int n){
	H = log(n+1)/log2; //�������������ȡ��
	X = n -  pow(2, H) + 1;
	if(X > pow(2, H)){
		X = pow(2, H);
	}
	L = pow(2, H-1) - 1 + X; //��������ģ
	
	return L;
}
