#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Test{
private:
    string _name;
public:
    Test(string name):_name(name){

    }
    ~Test(){
        cout << "Object destroyed" << endl;
    }
    void print(){
        cout << _name << endl;
    }
};

int main(int argc, char const *argv[])
{
    //LIFO
    stack<Test> testStack;

    testStack.push(Test("Mike")); // Temporary object creation and destruction
    testStack.push(Test("John"));
    testStack.push(Test("Sue"));

    cout << endl;

    Test test = testStack.top(); // Here again copy will happen - More efficient way is to use a reference 
    test.print();

    /*
    ** Invalid code... Unreliable... Here the reference is invalidated before use... Undefined behaviour...
    Test &test1 = testStack.top(); 
    testStack.pop();
    test1.print();
    */

    while(testStack.size() > 0){
        Test &test2 = testStack.top();
        test2.print();
        testStack.pop();
    }

    testStack.pop();

    test.print();

    //FIFO
    queue<Test> testQueue;

    testQueue.push(Test("Mike")); // Temporary object creation and destruction
    testQueue.push(Test("John"));
    testQueue.push(Test("Sue"));

    cout << endl;

    testQueue.back().print();

    /*
    ** Invalid code... Unreliable... Here the reference is invalidated before use... Undefined behaviour...
    Test &test1 = testStack.top(); 
    testStack.pop();
    test1.print();
    */

    while(testQueue.size() > 0){
        Test &test2 = testQueue.front();
        test2.print();
        testQueue.pop();
    }


    return 0;
}
