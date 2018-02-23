#define MAXN 1000 //集合最大元素个数
typedef int ElementType; //默认元素可以用非负整数表示 
typedef int SetName;  //默认用根结点的下标作为集合名称
typedef ElementType SetType[MAXN] //假设集合元素下标从0开始
typedef struct{
	ElementType Data;
	int Parent; //负数表示根结点，非负数表示双亲结点的下标 
}SetType;

void Union(SetType S, SetName Root1, SetName Root2){
	//这里默认Root1和Root2是不同集合的根结点
	//保证小集合并入大集合
	if(S[Root2] < S[Root1]){ //如果集合2比较大 
		S[Root2] += S[Root1]; //集合1并入集合2
		S[Root1] = Root2; 
	}else{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	} 
} 

SetName Find(SetType S, ElementType X){
	if(S[X] < 0){
		return X; //找到集合的根 
	}else{
		return S[X] = Find(S, S[X]);
	}
}
