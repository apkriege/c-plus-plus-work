#include <iostream>
using namespace std;
#define size 7 //maximum size of the array that will store Queue. 

class Queue{
    private:
        int front, rear, array[size];
    public:
        Queue(){
		    front = -1; 
		    rear = -1;
	    }
        void Enqueue(int x){
            if(rear == size - 1){
                cout << "somethign over";
                return;
            }
            else{
                rear = rear + 1;
                array[rear] = x;
            }
        }
        void Dequeue(){
            if(front == rear){
                cout << "queue empty";
            }
            else{
                front = front + 1;
                array[front] = front;
            }
        }
        void Output(){
            for(int i = front; i < rear; i++){
                cout << array[i+1] << " ";
            }
            cout << endl;
        }
    
};

int main() {
    Queue Q;
    Q.Enqueue(5);
    Q.Enqueue(10);
    Q.Enqueue(15);
    Q.Output();
    
    Q.Dequeue();
    Q.Output();
    
}
