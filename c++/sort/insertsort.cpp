#include <iostream>
using namespace std; 

void insert_sort(int arr[], int n){
    for(int i = 1;i < n;i++){
        int x = arr[i];
        int j = i;
        while(j > 0 and x < arr[j-1]){
            arr[j] = arr[j-1];
            j -= 1;
        }
        arr[j] = x;
    }
}

int main()
{
    int n = 3;
    int arr[n] = {2, 1, 3};
    insert_sort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }
}