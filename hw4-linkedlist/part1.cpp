#include <iostream>
using namespace std;

int add(int *arr, int size){
    int num; 
    for(int i=0;i<size;i++){
        num += arr[i];
    }
    return num;
}

int main() {
    int len;
    cout << "Enter number of elements: ";
    cin>>len;
    
    int* array=new int[len];
    
    cout << "Enter values: ";
    for(int i=0; i<len; i++){
        
        cin >> array[i];
    }
    
    cout << "Sum of numbers = " << add(array, len);
    return 0;
}