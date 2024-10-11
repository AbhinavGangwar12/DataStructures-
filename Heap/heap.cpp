#include<iostream>
using namespace std;

void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeap(int arr[],int size){
    int temp = arr[size];
    int i = size;
    while(i > 1 && temp > arr[i/2]){
        swap(arr[i],arr[i/2]);
        i /= 2;
    }
    arr[i] = temp;
}

void minHeap(int arr[],int size){
    int temp = arr[size];
    int i = size;
    while(i > 1 && temp < arr[i/2]){
        swap(arr[i],arr[i/2]);
        i /= 2;
    }
    arr[i] = temp;
}

void delHeapMax(int arr[],int size){
    int temp = arr[1];
    arr[1] = arr[size];
    int i = 1,j = i*2;
    while(j <= size-1){
        if(arr[j]<arr[j+1])j++;
        if(arr[i]<arr[j])swap(arr[i],arr[j]);
        else break;
    }
    arr[size] = temp;
}

void heapifyMax(int arr[],int size){
    int i=size,j = 2*i;
    while(i>1){
        if(j<size){
            if(arr[j]<arr[j+1])j++;
            if(arr[i]<arr[j]){
                swap(arr[i],arr[j]);
            }
        }
        i--;
        j = i*2;
    }
}
void heapifyMin(int arr[],int size){
    int i=size,j = 2*i;
    while(i>1){
        if(j<size){
            if(arr[j]>arr[j+1])j++;
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
        i--;
        j = i*2;
    }
}
int main(){
    cout<<"Enter the length of array : ";
    int n,delEle = 0;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<"Entered array : ";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        maxHeap(arr,i);
    }
    cout<<"Max heap : ";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Max heap After deletion : ";
    delHeapMax(arr,n);
    delEle++;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // for(int i=1;i<=n;i++){
    //     minHeap(arr,i);
    // }
    // cout<<"Min heap : ";
    // for(int i=1;i<=n;i++){
    //     cout<<arr[i]<<" ";
    // }
    cout<<endl;
    return 0;
}