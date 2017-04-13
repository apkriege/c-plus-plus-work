#include <iostream>
using namespace std;

class Node { 
    private:
        // int data;    // different data type for other apps 
        string fname, lname;
        int id;
        Node *next;  // the link pointer to next item 
    public: 
        Node(int x=0, string fname="", Node * ptr=NULL); // constructor 
        int getData( ); 
        Node *getNext( ); 
        void setData(int x); 
        void setNext(Node *ptr); 
};

Node::Node(int id, string fname, Node *p){ id=id; fname=fname;next=p;};
int Node::getData( ){return data;};
Node * Node::getNext( ){return next;};
void Node::setData(int x) {data=x;};
void Node::setNext(Node *ptr){next=ptr;};

class List { 
    private:
        Node *head_ptr; 
        Node *tail_ptr; 
        int numOfItems; 
    public:
        List( ); // constructor int size( );      
        Node *getHead( );      
        Node *getTail( ); 
        bool isEmpty( ); 
        Node *search(int x);         
        Node *itemAt(int position);
        void removeHead(); 
        void removeTail(); 
        void remove(int x); // delete leftmost item having x 
        void insertHead(int x, string fname);       
        void insertTail(int x);
        void insert(Node *p, int x);
        int size();
        void output();
};

List::List( ){head_ptr= NULL; tail_ptr=NULL; numOfItems=0; };
int List::size( ){return numOfItems;};
Node * List::getHead( ) {return head_ptr;};
Node * List::getTail( ) {return tail_ptr;};
bool List::isEmpty() {return (numOfItems==0);};

void List::output(){
    Node * currentPtr = head_ptr;
    for(int i=0; i<numOfItems; i++){
        cout << currentPtr->getData();
        currentPtr = currentPtr->getNext();
    }
}
void List::insertHead(int x, string name){
    Node * newHead = new Node(x, name, head_ptr);
    head_ptr= newHead; 
    if (tail_ptr == NULL) // only one item in list 
        tail_ptr = head_ptr; 
    numOfItems++;
};
void List::insertTail(int x){
    if (isEmpty()) 
        insertHead(x); 
    else{
        Node * newTail = new Node(x); 
        tail_ptr->setNext(newTail); 
        tail_ptr = newTail;  
        numOfItems++;
    }
};
void List::insert(Node *p, int x){
    Node *currentPtr = head_ptr;
    while(currentPtr !=NULL && currentPtr != p)
        currentPtr = currentPtr->getNext();
        if (currentPtr != NULL ) { // p is found
            Node *newNd=new Node(x,p->getNext());
            p->setNext(newNd); 
            numOfItems++;
        }
};
void List::removeHead( ){
    if (numOfItems == 0) return; 
    Node * currentPtr = getHead( ); 
    head_ptr=head_ptr->getNext( ); 
    delete currentPtr; 
    numOfItems--;
};

void List::removeTail( ){ 
    if (numOfItems == 0)
        return;
    if (head_ptr == tail_ptr){
        head_ptr=NULL; 
        tail_ptr= NULL; 
        numOfItems=0; 
        return; 
    } 
    Node * beforeLast = itemAt(numOfItems-2); 
    beforeLast->setNext(NULL); // beforeLast becomes last delete 
    tail_ptr;   // deletes the last object 
    tail_ptr=beforeLast; 
    numOfItems--;
};

// search based on number
Node *List::search(int x){
    Node * currentPtr = getHead( ); 
    while (currentPtr != NULL){
        if (currentPtr->getData( ) == x) 
            return currentPtr;
        else
            currentPtr = currentPtr->getNext();
    } 
    return NULL; // Now x is not, so return NULL
};

Node *List::itemAt(int position){
    if (position<0 || position>=numOfItems)
        return NULL;
    Node * currentPtr = getHead( ); 
    for(int k=0;k != position; k++)
        currentPtr = currentPtr -> getNext( );
    return currentPtr; 
};

class Test{
    public:
        int id, age;
        Test(int x, int y){id = x; age = y; }
};

int main() {
    //prompt which operation to preform
    int *p;
    List test;
    test.insertHead(23, "Adam");
    cout << test.getTail()->getData();
    return 0;
}
