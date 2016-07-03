#include<stdio.h>  

void merge(int arr[],int begin,int mid,int end,int temp[]){
	int m=mid,n=end;
	int i=begin,j=mid+1;
	int k=0;
	while(i<=m&&j<=n){
		if(arr[i]>arr[j]){
			temp[k++]=arr[j++];
		}else{
			temp[k++]=arr[i++];
		}
	}
	while(i<=m){
		temp[k++]=arr[i++];
	}
	while(j<=n){
		temp[k++]=arr[j++];
	}
	for(int s=0;s<k;s++){
		arr[begin+s]=temp[s];
	}
}

void top_merge_sort(int arr[],int begin ,int end,int temp[]){

	if(end>begin)
	{
	int mid=(end+begin)/2;
	top_merge_sort(arr,begin,mid,temp);
	top_merge_sort(arr,mid+1,end,temp);
	merge(arr,begin,mid,end,temp);
	} 
	
}

//Ò»ÌËÅÅĞò 
void merge_pass(int arr[],int gap,int length,int temp[]){
	int begin=0;
	int end=length-1;
	int i=begin;
	for(;i+2*gap-1<end;i=i+gap*2){
		merge(arr,i,i+gap-1,i+gap*2-1,temp);
	} 
	if(i+gap-1<length){
		merge(arr,i,i+gap-1,length-1,temp);
	}
}

void bottom_merge_sort(int arr[],int length,int temp[]){
	int gap=1;
	for(;gap<length;gap*=2){
		merge_pass(arr,gap,length,temp);
	}

}


int main(){
	int num[11]={2,5,9,3,6,10,1,0,7,4,8};  
    int temp[11];  
//    top_merge_sort(num,0,10,temp);  
	bottom_merge_sort(num,11,temp);
    for(int i=0;i<11;i++)  
    {  
        printf("%d,",num[i]);  
    }  
    printf("\n");  
	return 1;
} 
