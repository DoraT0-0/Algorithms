#include <iostream>
using namespace std;

void Merge(int arr[], int mid, int right){
    int leftSize = mid+1,rightSize = right-mid;
    int leftArray[leftSize], rightArray[rightSize];

    for(int i = 0; i < leftSize; i++)
        leftArray[i] = arr[i];
    for(int j = 0; j < rightSize; j++)
        rightArray[j] = arr[j+mid+1];

    int i = 0, j = 0, k = 0;
    while(i < leftSize and j < rightSize){
        if(leftArray[i] <= rightArray[j])
            arr[k++] = leftArray[i++];
        else
            arr[k++] = rightArray[j++];
    }

    while(i < leftSize)
        arr[k++] = leftArray[i++];
    while(j < rightSize)
        arr[k++] = rightArray[j++];
}


void MergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = (right+left)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        Merge(arr, mid, right);
    }
}

int main() 
{ 
    int array[] = {10, 2, 7, 32, 53, 1};
    int size = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
    MergeSort(array, 0, size-1);
    cout << endl;
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
} 