#include<stdio.h>

int MaxSubseqSum2(int A[], int N);

int main(){
	int a[10] = {10,5,8,4,-9,4,-7,-1,0,6};
	int MaxSum = MaxSubseqSum2(a,10);
	printf("%d",MaxSum);
	
	return 0;
}

int MaxSubseqSum2(int A[], int N){
	int ThisSum, MaxSum = 0;
	int i, j;
	for(i = 0; i < N; i++){
		ThisSum = 0;
		for(j = i; j < N; j++){
			ThisSum += A[j];
			if(ThisSum > MaxSum){
				MaxSum = ThisSum;
			}
		}
	}
	
	return MaxSum;
}
