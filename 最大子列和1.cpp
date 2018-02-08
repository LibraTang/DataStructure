#include<stdio.h>

int MaxSubseqSum1(int A[], int N);

int main(){
	int a[10] = {10,5,8,4,-9,4,-7,-1,0,6};
	int MaxSum = MaxSubseqSum1(a,10);
	printf("%d",MaxSum);
	
	return 0;
} 

int MaxSubseqSum1(int A[], int N){
	int ThisSum, MaxSum = 0;
	int i,j,k;
	for(i = 0; i < N; i++){
		for(j = i; j < N; j++){
			ThisSum = 0;
			for(k = i; k <= j; k++){
				ThisSum += A[k];
				if(ThisSum > MaxSum){
					MaxSum = ThisSum;
				}
			}
		}
	}
	
	return MaxSum;
}
