#include <iostream>
#include <string>

using namespace std;

template<class T,class K>
class Test{
private:
    T _obj;
public:
    Test(T obj){
        this->_obj = obj;
    }
    void print() const{
        cout << _obj << endl;
    }
};

int main(int argc, char const *argv[])
{
    Test<string,int> test1("Hello");
    test1.print();

    return 0;
}
