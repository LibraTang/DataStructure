#include<stdio.h>

int main(){
	
}

int locString(char s[], char t[]){
	int slength = sizeof(s)/sizeof(char), tlength = sizeof(t)/sizeof(char);
	int i, j, k;
	if(slength < tlength) return -1;
	for(i=slength-tlength; i>0; i--){
		for(j=i, k=0; j<slength && k<tlength && s[j] == t[k]; j++, k++);
		if(k == tlength) return i;
	}
	return -1;
}
