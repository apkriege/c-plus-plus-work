#include <iostream>
using namespace std;

/* Precondition: arr is int array, first is first elem, last is last elem, key is number being searched
   Postcondition: loops through array resetting mid point until it equals key */
int binSearch(int arr[], int first, int last, int key) {
   if (first <= last) {
       int mid = (first + last) / 2;  // compute mid point.
       if (key == arr[mid]) 
           return mid;   // found it.
       else if (key < arr[mid]) 
           // Call ourself for the lower part of the arr
           return binSearch(arr, first, mid-1, key);
       else
           // Call ourself for the upper part of the arr
           return binSearch(arr, mid+1, last, key);
   }
   return -(first + 1);    // failed to find key
}

int main() {

    int nums[20];
    int key;
    int elems;
    
    cout << "Enter number of elements: ";
    cin >> elems;
    
	cout << "Enter integers: ";
	int size = 0;
	while (size < elems) {
		cin >> nums[size];
		size++;
	}
	cout << "Enter number to find: ";
	cin >> key;
	
	int ret = binSearch(nums, 0, size-1, key);
	if(ret >= 0)
        cout << "Item Found at index: " << ret << endl;
    else 
        cout << "Not Found! " << ret << endl;
	
}
