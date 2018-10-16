#include <iostream>
#include <string>

using namespace std;

template<class T, class K>
class Test{
    T _obj1;
    K _obj2;
public:
    Test(T obj1,K obj2){
        this->_obj1 = obj1;
        this->_obj2 = obj2;
    }

    void print(){
        cout << _obj << " : " << _obj2 << endl;
    }
};

int main(int argc, char const *argv[])
{
    Test<string,int> test1("Nandakumar Puzhankara",28);
    test1.print();
    return 0;
}
