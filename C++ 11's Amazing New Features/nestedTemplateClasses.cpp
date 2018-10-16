#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class ring{
public:
    ring():_size(0){}
    ring(int size) : _size(size),_currentIndex(0){
        _dataArray.resize(_size);
    }

    //public interfaces
    void add(T data){
        assert(_size > 0);
        if(_currentIndex == _size){
            _currentIndex = 0;
        }
        if(_currentIndex < _size){
            _dataArray[_currentIndex] = data;
            _currentIndex++;
        }
    }

    T get(int i) const{
        assert(i >= 0 && i < _size);
        return _dataArray[i];
    }

    void display() const{
        //cout << typeid(*this).name();
        for(auto data : _dataArray){
            cout << data << endl;
        }
    }

private:
    vector<T> _dataArray;
    int _size;
    int _currentIndex;
};

template<class T>
class nestedClass {
public:
    class iterator;
};

template<class T>
class nestedClass<T>::iterator {
public:
    void print(){
        cout << "Hello from iterator : " << T() << endl;
    }
};

int main(int argc, char const *argv[])
{

    ring<string> textring(3);
    
    textring.add("one");
    textring.add("two");
    textring.add("three");
    
    textring.display();
    
    textring.add("four");
    cout << endl;
    textring.display();
    
    textring.add("five");
    cout << endl;
    textring.display();
    
    textring.add("six");
    cout << endl;
    textring.display();
    
    textring.add("seven");
    cout << endl;
    textring.display();
    
    textring.add("eight");
    cout << endl;
    textring.display();
    
    textring.add("nine");
    cout << endl;
    textring.display();

    ring<string> anotherOne = textring;
    cout << endl;
    anotherOne.display();

    //ring<string> test; //To check assert failure
    //test.add("Testing");

    nestedClass<int>::iterator it;
    it.print();

    return 0;
}
