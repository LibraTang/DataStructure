#include<stdio.h>

#define MAXN 1001

typedef int ElementType; //Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ 
typedef int SetName;  //Ĭ���ø������±���Ϊ��������
typedef ElementType SetType[MAXN]; //���輯��Ԫ���±��0��ʼ

void Input_connection(SetType S);
void Check_connection(SetType S);
void Check_network(SetType S, int n);
SetName Find(SetType S, ElementType X);
void Union(SetType S, SetName Root1, SetName Root2); 
void Initialization(SetType S, int n);

int main(){
	SetType S;
	int n;
	char in;
	scanf("%d\n", &n);
	Initialization(S, n);
	do{
		scanf("%c", &in);
		switch(in){
			case 'I': Input_connection(S); break;
			case 'C': Check_connection(S); break;
			case 'S': Check_network(S, n); break;
		}
	}while(in != 'S');
	
	return 0;
}

void Input_connection(SetType S){
	ElementType u, v;
	SetName Root1, Root2;
	scanf("%d %d\n", &u, &v);
	Root1 = Find(S, u-1);
	Root2 = Find(S, v-1);
	if(Root1 != Root2){
		Union(S, Root1, Root2);
	}
}

void Check_connection(SetType S){
	ElementType u, v;
	SetName Root1, Root2;
	scanf("%d %d\n", &u, &v);
	Root1 = Find(S, u-1);
	Root2 = Find(S, v-1);
	if(Root1 == Root2){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}

void Check_network(SetType S, int n){
	int i, cnt = 0;
	for(i = 0; i < n; i++){
		if(S[i] < 0){
			cnt++;
		}
	}
	if(cnt == 1){
		printf("The network is connected.\n");
	}else{
		printf("There are %d components.\n", cnt);
	}
}

SetName Find(SetType S, ElementType X){
	if(S[X] < 0){
		return X;
	}else{
		return S[X] = Find(S, S[X]); //���ҵ������Ѹ����X�ĸ���㣻�ٷ��ظ� 
	}
}

void Union(SetType S, SetName Root1, SetName Root2){ //S[Root] = -Ԫ�ظ��� 
	if(S[Root2] < S[Root1]){
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}else{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

void Initialization(SetType S, int n){
	for(int i = 0; i < n; i++){
		S[i] = -1;
	}
}
