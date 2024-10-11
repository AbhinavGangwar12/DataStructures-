//Different types of sorting is performed here...
#include<iostream>
using namespace std;

class Sorting{
    public:
        void bubbleSort(int [],int);
        void insertionSort(int [],int);
        void selectionSort(int [],int);
        int partition(int [],int,int);
        void quickSort(int [],int,int);
        void mergeTwo(int [],int,int,int);
        void iMergeSort(int [],int);
        void countSort(int [],int);
        void print(int [],int);
};

void Sorting :: print(int arr[],int size){
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap(int *num1,int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void Sorting :: bubbleSort(int arr[],int size){
    for(int i = 0;i<size-1;i++){
        int flag = 0;//using flag in case when the array is already sorted then it should stop at pass 1
        for(int j = 0; j<size-i-1;j++){
            if(arr[j+1] < arr[j]){
                swap(&arr[j],&arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)break;
    }
}


void Sorting :: insertionSort(int arr[],int size){
    for(int i = 1 ; i < size ; i++){//Window number
        int j = i-1;//j is used to traverse through sorted array
        int buf = arr[i];
        while(j>-1 && buf < arr[j]){
            arr[j+1] = arr[j];//shift one and make space for new element
            j--;
        }
        arr[j+1] = buf;
    }
}


void Sorting :: selectionSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int k = i;
        for(int j=i; j < size ; j++){
            if(arr[j]<arr[k]){
                k = j;
            }
        }
        swap(arr[k],arr[i]);
    }
}



int Sorting :: partition(int arr[],int low,int high){
    int pivot_ele = arr[low];
    int i = low,j = high;
    do{
        do{i++;}while(arr[i]<=pivot_ele);
        do{j--;}while(arr[j]>pivot_ele);
        if(i<j)swap(&arr[i],&arr[j]);

    }while(i<j);
    swap(&arr[j],&arr[low]);
    for(int i = 0;i < high;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return j;
}

void Sorting :: quickSort(int arr[],int low,int high){
    int part;
    if(low < high){
        part = partition(arr,low,high);
        this->quickSort(arr,low,part-1);
        this->quickSort(arr,part+1,high);
    }
}

void Sorting :: mergeTwo(int arr[],int low,int mid,int high){
    
    int i = low,k=low,j = mid+1;
    int buffer[100];

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){buffer[k++] = arr[i++];}
        else if(arr[i]>arr[j]){buffer[k++] = arr[j++];}
        else {buffer[k++] = arr[i++];j++;}
    }

    for(;i<=mid;i++){buffer[k++] = arr[i];}
    for(;j<=high;j++){buffer[k++] = arr[j];}
    
    for(int itr = low;itr<=high;itr++){arr[itr] = buffer[itr];};
}

void Sorting :: iMergeSort(int arr[],int size){
    int lw,hgh,md;
    int lptr = 2;
    for( ; lptr <= size ; lptr = lptr * 2){
        for(int partition = 0;partition + lptr - 1 < size ; partition =partition + lptr){
            int lw = partition;
            int hgh = partition + lptr - 1;
            int md = (lw + hgh)/2;
            this->mergeTwo(arr,lw,md,hgh);
        }
    }
    if((lptr/2) < size)mergeTwo(arr,0,(lptr/2)-1,size);
}

int max(int arr[],int size){
    int max = arr[0];
    for(int j = 1;j<size;j++){  
        if(max < arr[j]){
            max = arr[j];   
        } 
    }
    return max;
}

void Sorting :: countSort(int arr[],int size){
    int largest = max(arr,size);
    int * array = new int[largest+1];
    for(int i=0;i<=largest;i++){array[i]=0;}
    for(int i=0;i<=largest;i++){array[ arr[i] ]++;}
    int i = 0, j = 0;
    while(i <= size){
        if(array[i]>0){
            arr[j++] = i;
            array[i]--;
        }
        else i++;
    }
    delete [] array;
}

int main(){
    int arr[5] = {2,1,5,4,3};
    Sorting sort;
    cout<<"Original array : ";
    sort.print(arr,5);
    // sort.bubbleSort(arr,5);
    // sort.insertionSort(arr,5);
    // sort.selectionSort(arr,5);
    // sort.quickSort(arr,0,5);
    // sort.iMergeSort(arr,5);
    sort.countSort(arr,5);
    cout<<"Sorted array : ";
    sort.print(arr,5);
    return 0;
}