#include <iostream>
using namespace std;

int binary_search(int arr[], int low, int high, int target){
    if(low <= high){
        int mid = (high+low)/2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid] < target){
            return binary_search(arr,mid+1,high,target);
        }
        else{
            return binary_search(arr,low,mid-1,target);
        }
    }
    else{
        return -1;
    }
}


int main(){
    int h = 4;
    int arr[h] = {3, 4, 5, 6};
    int target = 6;
    int result = binary_search(arr, 0, h, target);
    cout << result;
}