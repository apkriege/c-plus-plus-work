#include <iostream>
using namespace std;

// problem 2
// Precondition: accepts int x and y number variables
// Postcondition: divides the numbers and returns the int value 
int divide(int x, int y){
    return (x/y);
}
// Precondition: accepts int x and y number variables
// Postcondition: divides the numbers and returns the int value 
float divide(float x, float y){
    return (x/y);
}
// Precondition: accepts int x and y number variables
// Postcondition: divides the numbers and returns the int value 
double divide(double x, double y){
    return (x/y);
}

int main() {
    int ix, iy, choice;
    float fx, fy;
    double dx, dy;
    
    cout << "Enter your choice: 1 for int, 2 for float, 3 for double: ";
    cin >> choice;
    
    cout << "Enter two integers: ";

    if(choice == 1){         //if choice == 1, inputs are ints and runs the int divide function
        cin >> ix >> iy;
        try{                 //try if dy == 0 throw exception that user cannot divide by zero
            if (iy == 0) throw iy;
            cout << divide(ix, iy);
        }
        catch(int y){ cout << "Error!! Cannot divide by zero!!"; } // throw int error
    }
    if(choice == 2){         //if choice == 2, inputs are floats and runs the float divide function
        cin >> fx >> fy;
        try{                 //try if dy == 0 throw exception that user cannot divide by zero
            if (fy == 0) throw fy;
            cout << divide(fx, fy);
        }
        catch(float y) { cout << "Error!! Cannot divide by zero!!"; } //throw float error
    }
    if(choice == 3){         //if choice == 3, inputs are doubles and runs the double divide function
        cin >> dx >> dy;
        try{                 //try if dy == 0 throw exception that user cannot divide by zero
            if (dy == 0) throw dy;
            cout << divide(dx, dy);
        }
        catch(double y) { cout << "Error!! Cannot divide by zero!!"; } //throw double error
    }
    
    return 0;
}



// problem 1
// Precondition: accepts int x and y number variables
// Postcondition: divides the numbers and returns the int value 
// int divide(int x, int y){
//     return (x/y);
// }
// // Precondition: accepts float x and y number variables
// // Postcondition: divides the numbers and returns the float value 
// float divide(float x, float y){
//     return (x/y);
    
// }
// // Precondition: accepts double x and y number variables
// // Postcondition: divides the numbers and returns the double value 
// double divide(double x, double y){
//     return (x/y);
// }

// int main() {
//     int ix, iy, choice;
//     float fx, fy;
//     double dx, dy;

//     cout << "Enter your choice: 1 for int, 2 for float, 3 for double: ";
//     cin >> choice;
    
//     cout << "Enter two numbers: "
//     if(choice == 1){            //if choice == 1, inputs are ints and runs the int divide function
//         cin >> ix >> iy;           
//         cout << ix << "/" << iy << " = " << divide(ix, iy) << endl;
//     }
//     if(choice == 2){            //if choice == 2, inputs are floats and runs the float divide function
//         cin >> fx >> fy;
//          cout << fx << "/" << fy << " = " << divide(fx, fy) << endl;
//     }
//     if(choice == 3){
//          cin >> dx >> dy;       //if choice == 3, inputs are doubls and runs the double divide function
//           cout << dx << "/" << dy << " = " << divide(dx, dy) << endl;
//     }
         
//     system("PAUSE");
//     return 0;
// }
