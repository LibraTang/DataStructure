#define MAXN 1000 //�������Ԫ�ظ���
typedef int ElementType; //Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ 
typedef int SetName;  //Ĭ���ø������±���Ϊ��������
typedef ElementType SetType[MAXN] //���輯��Ԫ���±��0��ʼ
typedef struct{
	ElementType Data;
	int Parent; //������ʾ����㣬�Ǹ�����ʾ˫�׽����±� 
}SetType;

void Union(SetType S, SetName Root1, SetName Root2){
	//����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ����
	//��֤С���ϲ���󼯺�
	if(S[Root2] < S[Root1]){ //�������2�Ƚϴ� 
		S[Root2] += S[Root1]; //����1���뼯��2
		S[Root1] = Root2; 
	}else{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	} 
} 

SetName Find(SetType S, ElementType X){
	if(S[X] < 0){
		return X; //�ҵ����ϵĸ� 
	}else{
		return S[X] = Find(S, S[X]);
	}
}
