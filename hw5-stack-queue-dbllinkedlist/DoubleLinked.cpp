#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node *next, *prev;
        Node(int x) {
            value = x;
            next = prev = NULL;
        }
};

class dList {
    Node *front;
    Node *back;
    public:
    dList()
    {  front = NULL; back = NULL; }
    void insertHead(int x);
    void insertTail(int x);
    void insert(int x, int pos);
    void deleteHead();
    void deleteTail();
    void deletePos(int pos);
    void display();
    int elems();
};

/* Precondition: q is head
   Postcondition: starting with head, loops through all elements adding to cnt and then returning cnt*/
int dList::elems(){
    Node *q = front;
    int cnt = 0;
    while (q != NULL) {
        q = q->next;
        cnt++;
    }
    return cnt;
}

/* Precondition: tmp is head
   Postcondition: finds first element and then deletes it */
void dList::deleteHead(){
    Node *tmp, *q;
    tmp = front;
    front = front->next;  
    front->prev = NULL;
    delete tmp;
}

/* Precondition: q is head
   Postcondition: loops through all until finding the last and then deletes it */
void dList::deleteTail(){
    Node *tmp, *q;
    q = front;
    while (q->next->next != NULL){
        q = q->next;
    }
    tmp = q->next;
    delete tmp;
    q->next = NULL;
}

/* Precondition: pos is lists index that is to be deleted
   Postcondition: deletes element at index of pos and resets prev and next pointers */
void dList::deletePos(int pos){
    Node *tmp, *q;
    // first elem deletion
    if(pos == 1) {
        deleteHead();
        return;
    }
    // last elem deletion
    if(pos == elems()){ 
        cout << "END" << endl;
        deleteTail();
        return;
    }
    // delete elem by pos
    q = front;
    for(int i=1; i<=elems(); i++){
        cout << "i: " << i << "pos: " << pos <<endl;
        if(i == pos-1){
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            delete tmp;
            return;
        }
        q = q->next;
    }
}

/* Precondition: x is value and pos is index of doubly linked list
   Postcondition: adds value at pos index and sets prev and next pointers */
void dList::insert(int x, int pos){
    if (front == NULL) {
        insertHead(x);
        return;
    }

    Node *tmp, *q;
    int i;
    q = front;
    for (i = 0;i < pos - 1;i++) {
        q = q->next;
        if (q == NULL)
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    tmp = new Node(x);
    tmp->value = x;
    if (q->next == NULL) {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    }
    else {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element Inserted"<<endl;
}
 
 /* Precondition: x is value that is to be inserted in head
   Postcondition: sets prev and next pointers and adds x to new node in front*/
void dList::insertHead(int x) {
    Node *n = new Node(x);
    if( front == NULL) {
        front = n;
        back = n;
    }
    else {
        front->prev = n;
        n->next = front;
        front = n;
    }
}

/* Precondition: x is value that is to be inserted in rear
   Postcondition: sets next and prev pointers and adds x to new node at back */
void dList::insertTail(int x) {
    Node *n = new Node(x);
    if( back == NULL) {
        front = n;
        back = n;
    }
    else {
        back->next = n;
        n->prev = back;
        back = n;
    }
}

/* Precondition: front points to the head;
   Postcondition: Starting at the head loops through and prints out the elements */
void dList::display(){
    Node *temp = front;
    cout << "List of elements: ";
    
    while(temp != NULL) {
        cout << temp->value << " " ;
        temp = temp->next;
    }
    cout << endl;
}


int main (){
    dList list;
    int choice, addchoice, delchoice, val, pos;
    while (1)
    {
        cout<<"Operations for doubly linked list"<<endl;
        cout<<"1.Add"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout << "1. Add at beginning" << endl;
            cout << "2. Add at end" << endl;
            cout << "3. Add at position" << endl;
            cout << "Enter choice for adding element: ";
            cin >> addchoice;
            switch(addchoice){
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    list.insertHead(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    list.insertTail(val);
                    break;
                case 3: 
                    cout << "Enter value: ";
                    cin >> val;
                    cout << "Enter postion: ";
                    cin >> pos;
                    list.insert(val, pos);
                    break;
            }
            break;
        case 2:
            cout << "1. Delete beginning" << endl;
            cout << "2. Delete end" << endl;
            cout << "3. Delete by position" << endl;
            cout << "Enter choice for deleting: ";
            cin >> delchoice;
            switch(delchoice){
                case 1:
                    list.deleteHead();
                    break;
                case 2:
                    list.deleteTail();
                    break;
                case 3:
                    cout << "Enter postion: ";
                    cin >> pos;
                    list.deletePos(pos);
                    break;
            }
            break;
        case 3:
            list.display();
            cout<<endl;
            break;
        case 4:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    
    return 0;
}