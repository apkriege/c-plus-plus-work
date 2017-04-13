#include <iostream>
using namespace std;

class TwoDBOX{
   public: 
       double length, width;
       void init2D(double len, double wid){
           length = len;
           width = wid;
       }
       double area(){
            return length * width;
       }
       void output2D(){
           cout << "Area of the box is: " << area() << endl;
       }
};

class ThreeDBOX : public TwoDBOX{
    public: 
        double height;
        void init3D(double h){
            height = h;
        }
        double volume(){
            return area() * height;
        }
        void output3D(){
            cout << "Volume of the box is: "  << volume() << endl;
        }
};


int main() {
    double l, w, h;
    cout << "Enter the length: ";
    cin >> l;
    cout << "Enter the width: ";
    cin >> w;
    cout << "Enter the height: ";
    cin >> h;
    
    try{
        if(l < 0 || w < 0 || h < 0) throw l;
        ThreeDBOX threeD;
        threeD.init2D(l,w);
        threeD.init3D(h);
        
        threeD.output2D(); 
        threeD.output3D();
    }
    catch(double i) {
        cout << "Invalid input! Negative numbers not allowed.";
    }
    
}

