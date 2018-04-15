#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
	char *pch;
	int length;
}String, *Pstr;

Pstr InitString(int n);
void StrAssign(Pstr pstr, char cstr[]);
Pstr InitString(int n);
int BF(Pstr s, Pstr t);
void GetNext(Pstr t, int next[]);
void GetNextval(Pstr t, int nextval[]);
int KMP(Pstr s, Pstr t, int *next);
int BKMP(Pstr s, Pstr t, int *nextval);

int main(){
	Pstr s = InitString(25), t = InitString(13);
	char str1[25] = {'a','b','c','a','b','c','d','a','b','c','d','e','a','b','c','d','e','f','a','b','c','d','e','f','g'}; 
	char str2[13] = {'a','b','c','d','e','a','b','c','d','e','f','a','b'};
	int next[13], nextval[13];
	int i;
	printf("目标串s: ");
	for(i = 0; i<25; i++){
		printf("%c", str1[i]);
	}
	printf("\n");
	printf("模式串t: ");
	for(i = 0; i<13; i++){
		printf("%c", str2[i]);
	}
	printf("\n");
	StrAssign(s, str1); StrAssign(t, str2);
	GetNext(t, next); GetNextval(t, nextval);
	printf("Use BF: %d\n", BF(s, t));
	printf("Use KMP: %d\n", KMP(s, t, next));
	printf("Use better KMP: %d\n", BKMP(s, t, nextval));
	return 0;
}

//初始化串 
Pstr InitString(int n){
	Pstr pstr = (Pstr)malloc(sizeof(String));
	if(!pstr){
		printf("为串分配内存失败");
		exit(0);
	}
	char *pch = (char*)malloc(n);
	if(pch){
		pstr->pch = pch;
		pstr->length = 0;
	}else{
		printf("为字符数组分配内存失败");
		free(pstr);
		pstr = NULL;
	}
	return pstr;
}

//填充串 
void StrAssign(Pstr pstr, char cstr[]){
	int i;
	for(i = 0; cstr[i] != '\0'; i++){
		pstr->pch[i] = cstr[i];
	}
	pstr->length = i;
}

//暴力算法 
int BF(Pstr s, Pstr t){
	int i = 0, j = 0;
	int m = s->length, n = t->length;
	while(i <= (m-n)){
		j = 0;
		while(s->pch[i] == t->pch[j]){
			i++; j++;
			if(j == n) return (i-n);
		}
		i = i-j+1;
	}
	return -1;
}

//填充next数组 
void GetNext(Pstr t, int next[]){
	int j = 0, k = -1;
	next[0] = -1;
	while(j < t->length-1){
		if(k == -1 || t->pch[j] == t->pch[k]){
			j++; k++;
			next[j] = k;
		}
		else k = next[k]; //k回退 
	}
}

//填充nextval数组 
void GetNextval(Pstr t, int nextval[]){
	int j = 0, k = -1;
	nextval[0] = -1;
	while(j < t->length-1){
		if(k == -1 || t->pch[j] == t->pch[k]){
			j++; k++;
			if(t->pch[j] != t->pch [k]){
				nextval[j] = k;
			}else{
				nextval[j] = nextval[k];
			}
		}else{
			k = nextval[k]; //k回退 
		}
	}
}

//KMP算法 
int KMP(Pstr s, Pstr t, int *next){
	int i = 0, j = 0, m = s->length, n = t->length;
	while(i <= m-n){
		while(j == -1 || (j < n && s->pch[i] == t->pch[j])){
			i++; j++;
		}
		if(j == n) return (i-n); //匹配成功 
		j = next[j]; //j回溯 
	}
	return -1;
}

//改进的KMP算法 
int BKMP(Pstr s, Pstr t, int *nextval){
	int i = 0, j = 0, m = s->length, n = t->length;
	while(i < m-n){
		while(j == -1 || (j<n && s->pch[i] == t->pch[j])){
			i++; j++;
		}
		if(j == n) return (i-n);
		j = nextval[j];
	}
	return -1; 
}
