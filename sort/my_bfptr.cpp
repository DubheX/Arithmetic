#include<stdio.h>

const int N = 10005;  
   
int a[N];
void swap(int arr[],int i ,int j){
	if(i==j)return;
	arr[i]=arr[i]^arr[j];
	arr[j]=arr[i]^arr[j];
	arr[i]=arr[i]^arr[j];
}

void insert_sort(int arr[],int left,int right){
	int j;
	int ai;
	for(int i=left+1;i<=right;i++){
		ai=arr[i];
		for(j=i-1;j>=left;j--){
			if(	arr[j]>ai){
				arr[j+1]=arr[j];
			}else{
				break;
			}
		}
		arr[j+1]=ai;
	} 
}

void find_5mid(int arr[],int left,int right){
	int i,j;
	int n=left;
	for(i=left;i+5<=right;i+=5){
		insert_sort(arr,i,i+4);
		swap(arr,n++,i+2);
	}
	if(i<right){
		insert_sort(arr,i,right);
		swap(arr,n,(i+right)/2);
	}
	insert_sort(arr,left,n);
	swap(arr,left,(left+n)/2);	
} 


int partition(int arr[],int left,int right){
	int i=left,j=right;
	int pivot_value=arr[left];
	while(i<j){
		while(i<j&&arr[j]>=pivot_value)
			j--;
		arr[i]=arr[j];
		while(i<j&&arr[i]<=pivot_value)
			i++;
		arr[j]=arr[i];
	}
	arr[i]=pivot_value;
	return i;
}




int BFPTR(int arr[],int left,int right,int k){
	find_5mid(arr,left,right);
	int pivot=partition(arr,left,right);
	int m=pivot-left+1;
	if(k==m)return arr[pivot];
	if(k>m)return BFPTR(arr,pivot+1,right,k-m);
	return BFPTR(arr,left,pivot-1,k);
	
	return 1;
}


int main(){
	int n, k;  
    scanf("%d", &n);  
    for(int i = 0; i < n; i++)  
        scanf("%d", &a[i]);  
    scanf("%d", &k);  
    printf("The %d th number is : %d\n", k, BFPTR(a, 0, n - 1, k));  
    for(int i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    puts("");  
	return 1;
}
