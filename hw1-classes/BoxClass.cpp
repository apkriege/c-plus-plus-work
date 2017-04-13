#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Box {
    public:
        Box(float l, float w, float h){
            setDimensions(l, w, h);
        };
        /*
        Precondition: voulume accepts private variables
        Postcondition: multiplies values together and returns as float
        */
        float volume(){
            return length * width * height;
        }   
        /*
        Precondition: setDimensions accepts values from Box constructor
        Postcondition: sets the private variables length, width, and height
        */
        void setDimensions(float l, float w, float h){
            length = l;
            width = w;
            height = h;
        }
    
    private:
    float length;
    float width;
    float height;
};

int main() {
    ifstream input("data.txt");

    if(input.is_open()){
        vector<Box> box;
        box.reserve(5);
    
        double a, b, c;
        while(input >> a >> b >> c){
            box.push_back(Box(a,b,c));
        }
        
        cout << "Box 1 " << box[0].volume() << endl;
        cout << "Box 2 " << box[1].volume() << endl;
        cout << "Box 3 " << box[2].volume() << endl;
    }
    else{
        cout  << "Could not locate file." << endl;
    }

    
    return 0;
}
