#include <iostream>
using namespace std;

// problem1
// Precondition: output params string for output and pointer
// Postconditin: outputs 
void output(string pre, int *p){
    cout << pre << " swapping: First number = " << *p << " and Second number = " << *(p+1) << endl;
}

// Precondition: accepts ptr variable 
// Postcondition: swaps ptr index values and returns ptr
int *swap(int *ptr){
    int temp;  
    temp = *ptr;         //set temp to first index value of ptr
    *ptr = *(ptr + 1);   //set first index value of ptr to second index value of ptr
    *(ptr + 1) = temp;   //set second index valur of ptr to temp
    return ptr;
}

int main() {
    int arr[2];
    int *ptr = arr;              // set pointer var to array
    cin >> arr[0] >> arr[1];     // gets input from user
    
    output("Before", ptr);
    output("After", swap(ptr));  // runs output after swaping vals in ptr

    return 0;
}

// problem2
// Precondition: accepts ptr and size variable
// Postcondition: loops through array and outputs each value*2
void makeDouble(int *ptr, int size) {
    int x;
    for(int i=0; i < size; i++){
        x = *(ptr+i) * 2;    //multiples value of pointer at index by 2
        cout << x << endl;   //outputs value
    }
}
    
int main() {
    int nums[3];
    int *ptr = nums;
    int size = (sizeof(nums)/sizeof(*nums));

    cout << "Enter " << size << " numbers: ";
    for(int i=0; i < size; i++){
        cin >> *(ptr + i);       //get input from user and ptr value at index
    }
    
    makeDouble(ptr, size);       //run makeDouble with params pointer and size var

    return 0;
}

// problem3
// Precondition: accepts pointer and size variable
// Postcondition: starting with end and decremeting by 1, loops through the array outputing each pointer value
void reverse_array(char *p, int size){
    for (int index = size; index >= 0; index--) {
        cout << *(p+index);
    }
}

int main() {
    int size = 12;
    char input[size];
    char *ptr = input;        // set pointer var to input array
    
    cin.getline(input,size);  // get input from user
    
    reverse_array(ptr,size);  // run reverse_array with pointer and size vars
}

