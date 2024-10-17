#include <iostream>
using namespace std;


int main(){
    
    double arr[] = {-51, -548, 703, -869};
    int n = 4;

    for(int i = 0;i < n-1;i++){
        for(int j = 0;j < n-1-i;j++){
            if(arr[i] > arr[j+1]){
                double b = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = b;
            }
        }
    }

    for(int i = 0;i < n;i++) cout << arr[i] << " ";

}