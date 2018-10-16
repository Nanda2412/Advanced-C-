#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

template<typename T>
class ring{
private:
    int _pos;
    int _size;
    T* _elements;

public:
    ring(initializer_list<string> texts, int size):_pos(0),_size(size),_elements(NULL){
        _elements = new T[size];
        //updated for the usage of initializer_list args
        for(auto text : texts){
            add(text);
        }
    }

    ~ring(){
        delete [] _elements;
    }

    void add(T value){
        _elements[_pos++] = value;

        if(_pos == _size){
            _pos = 0;
        }
    }

    T& get(int pos) const{
        return _elements[pos];
    }

    int size() const{
        return _size;
    }

    class iterator;
};

template<typename T>
class ring<T>::iterator{
public:
    void print(){
        cout << "Hello from iterator : " << T() << endl;
    }
};

int main(int argc, char const *argv[])
{
    /*ring<string> textString(3);

    textString.add("one");
    textString.add("two");
    textString.add("three");
    textString.add("four");*/

    //initializer_list
    ring<string> textString({"one","two","three","four"},3);

    for(int i = 0; i < textString.size(); i++){
        cout << textString.get(i) << endl;
    }

    return 0;
}
