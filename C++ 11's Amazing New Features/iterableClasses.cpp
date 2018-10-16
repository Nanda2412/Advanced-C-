#include <iostream>
#include <string>

using namespace std;

template<typename T>
class ring{
private:
    int _pos;
    int _size;
    T* _elements;

    ring(const ring& other){}
    ring& operator=(const ring& other){}

public:
    class iterator;
    ring(int size):_pos(0),_size(size),_elements(NULL){
        _elements = new T[size];
    }
    ~ring(){
        delete [] _elements;
    }

    T& get(int pos){
        return _elements[pos];
    }

    void add(T element){
        _elements[_pos++] = element;

        if(_pos == _size){
            _pos = 0;
        }
    }

    //for making the class iterable
    iterator begin(){
        return iterator(0,*this);
    }

    iterator end(){
        return iterator(_size,*this);
    }
};

template<typename T>
class ring<T>::iterator{
private:
    int _pos;
    ring& _iterableRing;

public:
    iterator(int pos, ring& instance):_pos(pos),_iterableRing(instance){

    }

    //post-increment
    iterator& operator++(int){
        _pos++;

        return *this;
    }

    //pre-increment
    iterator& operator++(){
        ++_pos;

        return *this;
    }

    T& operator*(){
        return _iterableRing.get(_pos);
    }

    bool operator!=(const iterator& other) const{
        return _pos != other._pos;
    }
};

int main(int argc, char const *argv[])
{
    ring<string> textString(3);

    textString.add("one");
    textString.add("two");
    textString.add("three");

    //C++ 98 style
    for(ring<string>::iterator it = textString.begin(); it != textString.end(); it++){
        cout << *it << endl;
    }

    cout << endl;
    
    //C++ 11 style
    for(auto element : textString){
        cout << element << endl;
    }

    return 0;
}
