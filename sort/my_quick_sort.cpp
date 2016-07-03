#include<stdio.h>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}

void swap(int arr[],int i,int j){
	if(i==j)return;
	arr[i]=arr[i]^arr[j];
	arr[j]=arr[i]^arr[j];
	arr[i]=arr[i]^arr[j];
}

//双向遍历数组 分元 
int partition1(int arr[],int start,int end,int key){
	int i=start,j=end;
	int pivot=arr[key];
	while(i<j){
		while(i<j&&arr[j]>=pivot)
			j--; //向前搜索 
		arr[i]=arr[j];
		while(i<j&&arr[i]<=pivot)
			i++; //向后搜索 
		arr[j]=arr[i];
	}
	arr[i]=pivot;
	return i;	
}
int get_key(int arr[],int start, int end){
//	int key=start+((end-start)>>1);
    int key=(start+end)/2;
	swap(arr,start,key);
	return start;
}


//快速排序 
void quick_sort(int arr[],int start, int end){
	if(start>=end)return;
	//此处为方便取了区间的第一个值为比较值, 可以更改pivot的取值以优化最坏情况
	int key=get_key(arr,start,end);
	//对指定区间指定值,将pivot排在正确的位置 
	int mid=partition1(arr,start,end,key);
	//分治
	quick_sort(arr,start,mid-1);
	quick_sort(arr,mid+1,end);
	
}

int main(){
	int num[11]={2,5,9,3,6,10,1,0,7,4,8};   
	int length=0;
	GET_ARRAY_LEN(num,length);
	quick_sort(num,0,length);
    for(int i=0;i<11;i++)  
    {  
        printf("%d,",num[i]);  
    }  
    printf("\n");  
	return 1;
} 
