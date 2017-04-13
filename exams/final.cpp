#include <iostream>
using namespace std;

void sort(int arr[], int size){
    int tmp;
    for(int a = 0; a < size; a++){
        for(int b = 0; b < size; b++){
            if(arr[a] > arr[b]){
                tmp = arr[b];
                arr[b] = arr[a];
                arr[a] = tmp;
            }
        }
    }
    
    for(int a = 0; a < size; a++){
        cout << arr[a];
    }
    
}

int main() {
    int arr[10] = {2, 4, 6, 1, 3, 5, 7, 8, 0, 9};
    sort(arr, 10);
}