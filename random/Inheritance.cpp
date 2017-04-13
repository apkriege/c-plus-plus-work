#include <iostream>
using namespace std;

class Student{
    public: 
        int student_id;
        string student_name;
        void init(int id, string name){
            student_id = id;
            student_name = name;
        };
        float average(float x, float y){
            return (x + y) / 2;
        };
};

class CS216 : virtual public Student{
    public: 
        float quiz1, quiz2, cs216Avg;
        void init216(float q1, float q2){
            quiz1 = q1;
            quiz2 = q2;
            cs216Avg = average(quiz1, quiz2);
        };
        void outputCS216(){
            cout << "average score in CS216 is " << cs216Avg;
        }
};

class CS316 : virtual public Student{
    public:
        double quiz3, quiz4, cs316Avg;
        void init316(float q1, float q2){
            quiz3 = q1;
            quiz4 = q2;
            cs316Avg = average(quiz3, quiz4);
        };
        void outputCS316(){
            cout << "average score in CS316 is " << cs316Avg;
        }
};

class Midterm : public CS216, public CS316{
     public:
         float midterm1, midterm2, mAvg;
         void initMidterm(float m1, float m2){
             midterm1 = m1;
             midterm2 = m2;
             mAvg = average(midterm1, midterm2);
         };
         void outputMidterm(){
             cout << "average midterm score is " << mAvg;
         }
};

int main() {
    int id;
    string name;
    double q1, q2, q3, q4, m1, m2;
    
    cout << "Enter the First Name: ";
    cin >> name;
    cout << "Enter the ID: ";
    cin >> id;
    cout << "Enter CS316 Quiz1 score: ";
    cin >> q1;
    cout << "Enter CS316 Quiz2 score: ";
    cin >> q2;
    cout << "Enter CS216 Quiz1 score: ";
    cin >> q3;
    cout << "Enter CS216 Quiz2 score: ";
    cin >> q4;
    cout << "Enter Midterm1 score: ";
    cin  >> m1;
    cout << "Enter Midterm2 score: ";
    cin >> m2;
    cout << endl;
    Midterm s;
    s.init(id, name);
    s.init316(q1, q2);
    s.init216(q3, q4);
    s.initMidterm(m1, m2);
    
    cout << s.student_name << "'s " << "(" << s.student_id << ") ";
    s.outputCS316();
    cout << ", ";
    s.outputCS216();
    cout << ", ";
    s.outputMidterm();
}
