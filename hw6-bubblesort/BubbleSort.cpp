#include <iostream>
using namespace std;

/*  Precondition: items is the array to traverse, elems in number of elements
    Postcondition: sorts the values of the arr in ascending order
*/
template <typename Y>
void bubble(Y items[], int elems){
  Y y;
  for(int a=1; a<elems; a++){
    for(int b=elems-1; b>=a; b--){
      if(items[b-1] > items[b]) {
        y = items[b-1];
        items[b-1] = items[b];
        items[b] = y;
      }
    }
  }
}

/*  Precondition: arr is the array to populate, elems in number of elements
    Postcondition: saves the vaules to the array
*/
template <typename X>
void getdata(X arr[], int elems){
  int size = 0;
  while (size < elems) {
  		cin >> arr[size];
  		size++;
  	}
}

/*  Precondition: nums is the array to traverse, elems in number of elements
    Postcondition: outputs the values of the array
*/
template <typename Z>
void display(Z arr[], int elems){
  cout << "Here is the sorted array: ";
    for(int i=0;  i<elems; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main(){
  int const elems = 10;
  int sel;
  int inums[elems];
  double dnums[elems];
  char cnums[elems];
  
  cout << "Select data type (1)int (2)double (3)charater: ";
  cin >> sel;
  
  if(sel == 1){
    cout << "Enter 10 integers: ";
    getdata<int>(inums, elems);
  	bubble<int>(inums, elems);
  	display<int>(inums, elems);
  }
  
  if(sel == 2){
    cout << "Enter 10 doubles: ";
    getdata<double>(dnums, elems);
  	bubble<double>(dnums, elems);
    display<double>(dnums, elems);
  }
  
  if(sel == 3){
    cout << "Enter 10 charaters: ";
    getdata<char>(cnums, elems);
  	bubble<char>(cnums, elems);
  	display<char>(cnums, elems);
  }
  
  system("PAUSE");
  return 0;
};