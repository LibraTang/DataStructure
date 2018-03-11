#include<stdio.h>
 
void Merge(int a[],int b[], int start, int mid, int end){
	//合并a、b数组并排序 
    int i = start, j=mid+1, k = start;
    while(i!=mid+1 && j!=end+1){
        if(a[i] > a[j]) b[k++] = a[j++];
        else b[k++] = a[i++];
    }
    while(i != mid+1) b[k++] = a[i++];
    while(j != end+1) b[k++] = a[j++];
    for(i=start; i<=end; i++) a[i] = b[i];
}

void MergeSort(int a[], int b[], int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        MergeSort(a, b, start, mid);
        MergeSort(a, b, mid+1, end);
        Merge(a, b, start, mid, end);
    }
}

int main(){
    int a[8] = {55,48,11,2,11,694,36,87};
    int b[8];
    MergeSort(a, b, 0, 7);
    for(int i=0; i<8; i++) 
		printf("%d ", a[i]);
}

