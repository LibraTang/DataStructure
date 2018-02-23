#include<stdio.h>

#define MAXN 1001
#define MINH -10001

void Create();
 
int H[MAXN], size;
void Insert(int X);
int IsFull(int n);

int main(){
	int n, m, x, i, j;
	
	scanf("%d %d", &n, &m);
	Create(); //堆初始化
	for(i = 0; i < n; i++){
		if(!IsFull(n)){
			return 0;
		}
		scanf("%d", &x);
		Insert(x);
	} 
	for(i = 0; i < m; i++){
		scanf("%d", &j);
		printf("%d ", H[j]);
		while(j > 1){ //沿根方向输出各结点 
			j /= 2;
			printf("%d ", H[j]);
		}
		printf("\n");
	}
	return 0;
} 

void Create(){
	size = 0;
	H[0] = MINH; //设置“岗哨” 
}

void Insert(int X){
	int i;
	for(i = ++size; H[i/2] > X; i /= 2){
		H[i] = H[i/2];
	}
	H[i] = X;
}

int IsFull(int n){
	return n <= MAXN;
}


