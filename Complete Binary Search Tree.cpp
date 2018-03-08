//Complete Binary Search Tree

void solve(int ALeft, int ARight, int TRoot){
	//初始调用为 solve(0, N-1, 0)
	n = ARight - ALeft + 1;
	if(n == 0) return; //已经排好序 
	L = GetLeftLength(n); //计算出n个结点的树其左子树 有多少个结点
	T[TRoot] = A[ALeft + L];
	LeftTRoot = TRoot * 2 + 1;
	RightTRoot = LeftTRoot + 1;
	//递归
	solve(ALeft, ALeft+L-1, LeftTRoot); //解决左子树
	solve(ALeft+L+1, ARight, RightTRoot); //解决右子树 
} 

//在建搜索序列前，需要先将完全二叉树数组按顺序排好
#include<stdlib.h>
int main(){
	......
	qsort(A, N, sizeof(int), compare); //其中compare是比较大小的函数,根据需要编写 
	...... 
} 

int compare(const void*a, const void*b){
	return *(int*)a - *(int*)b;
} 

//计算左子树规模
int GetLeftLength(int n){
	H = log(n+1)/log2; //计算层数，向下取整
	X = n -  pow(2, H) + 1;
	if(X > pow(2, H)){
		X = pow(2, H);
	}
	L = pow(2, H-1) - 1 + X; //左子树规模
	
	return L;
}
