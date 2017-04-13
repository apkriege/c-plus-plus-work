#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

class Stack {
    public:
        int top = 0;
        int s[30];
        Stack(){}
        
        /* Precondition: arr is char array read in from file
        Postcondition: loops through elements and pushes the value to s array*/
        void process(char arr[]){
            for(int i=0; i<strlen(arr); i++){
                char x  = arr[i];
                if(x == '+' || x == '-' || x == '*' || x == '/'){
                    int a = s[top];
                    pop();
                    int b = s[top];
                    pop();
                    int c;
                    switch (x) {                     
                        case '+': c = (a + b); break;                     
                        case '-': c = (b - a); break;                     
                        case '*': c = (b * a); break;                     
                        case '/': c = (b / a); break;             
                    }
                    push(c);
                }
                else {
                    push(x-48);
                }
            }
            cout << s[top] << endl;
        }
        /* Precondition: char x is value to be added
        Postcondition: adds x value to s array */
        void push(char x){
        	s[++top] = x;
        }
        /* Precondition: s array
        Postcondition: removes top element */
        void pop(){
            s[top--];
        }
};

int main() {
    
    Stack test;

    ifstream inFile("numbers.txt");
    if (!inFile) {
        cout  << "File numbers.txt not found." << endl;
        return -1;
    }

    string line;
    while (getline(inFile, line)) {
    if (line.empty()) continue;
        char t[30] = {};
        int c = 0;
        if(line[0] != '0'){
            for(int i=0; i < line.length(); i++){
                if(line[i] != ' '){
                    t[c] = line[i];
                    c++;
                }
            }
            test.process(t);
        }
    }
  
    inFile.close();
    return 0;
}
