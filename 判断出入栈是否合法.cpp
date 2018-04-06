#include<stdio.h> 
#include<stdbool.h>

bool Legal(char IO[]);

int main(){
	bool result;
	char IO[100], ch;
	for(int i=0; i<100; i++){
		scanf("%c", &ch);
		if(ch == 'I' || ch == 'O') IO[i] = ch;
		else break;
	}
	if(Legal(IO)) printf("true");
	else printf("false"); 
	return 0;
}

bool Legal(char IO[]){
	int i = 0, j = 0;
	int length = sizeof(IO)/sizeof(char);
	for(int t=0; t<length; t++){
		if(IO[t] == 'I') i++;
		if(IO[t] == 'O') j++;
		if(i<j) return false;
	}
	if(i != j) return false;
	return true;
}
