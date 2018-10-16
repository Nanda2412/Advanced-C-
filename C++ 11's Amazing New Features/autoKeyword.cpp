#include <iostream>
#include <string>

using namespace std;

template<class T,class S>
auto testFunction(T value1, S value2) -> decltype(value1+value2){
    return value1 + value2;
}

int get(){
    return 999;
}

auto anotherFunction() -> decltype(get()){
    return get();
}

int main(int argc, char const *argv[])
{
    auto value = 4;
    cout << value << endl;

    auto text = "Hello Nanda";
    cout << text << endl;

    cout << testFunction<int,int>(5,6) << endl;
    cout << testFunction(5,5) << endl;
    //cout << testFunction(6,"asd") << endl; - compiled without any error but two char* throws invalid operands error

    cout << anotherFunction() << endl;
    
    return 0;
}
