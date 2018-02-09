#include<stdio.h>

int MaxSubseqSum4(int A[], int N);

int main(){
	int a[10] = {10,5,8,4,-9,4,-7,-1,0,6};
	int MaxSum = MaxSubseqSum4(a,10);
	printf("%d",MaxSum);
	
	return 0;
} 

int MaxSubseqSum4(int A[], int N){
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for(i = 0; i < N; i++){
		ThisSum += A[i];
		if(ThisSum > MaxSum){
			MaxSum = ThisSum;
		}else if(ThisSum < 0){/*小于0的数不会让子列和变大，因此将和归0并继续计算*/
			ThisSum = 0;
		}
	}
	
	return MaxSum;
}
