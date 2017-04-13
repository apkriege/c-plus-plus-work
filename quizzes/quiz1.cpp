#include <iostream>
using namespace std;

class Numbers{
    public:
    void outputNums(int *ptr){
        int m = min(ptr);
        for(int i; i < 3; i++){
            cout << *(ptr+i) - m << " ";
        }
    }
    int min(int *ptr){
        if(*(ptr) < *(ptr+1) & *(ptr) < *(ptr+1)){
            return *(ptr);
        }
        if(*(ptr+1) < *(ptr) & *(ptr+1) < *(ptr+2)){
            return *(ptr+1);
        }
        if(*(ptr+2) < *(ptr) & *(ptr+2) < *(ptr+1)){
            return *(ptr+2);
        }
    }
};

int main() {
    int nums[3];
    int *ptr;
    ptr = nums;
    
    for(int i=0; i<3; i++){
        cin >> *(ptr+i);
    }
    Numbers x;
    x.outputNums(ptr);
    
    return 0;
}