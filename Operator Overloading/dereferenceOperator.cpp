#include <iostream>
#include <string>

using namespace std;

// Adding dereference operator overloading...
// for finding the conjugate
/*
**Operators that can't be overloaded
1> Scope Resolution Operator  (::)    
2> Pointer-to-member Operator (.*)    
3> Member Access or Dot operator  (.)    
4> Ternary or Conditional Operator (?:) 
5> Object size Operator   (sizeof) 
6> Object type Operator   (typeid)
*/
class Complex{
private:
    double _real;
    double _imaginary;

public:
    Complex():_real(0),_imaginary(0){

    }
    Complex(double real,double imaginary):_real(real),_imaginary(imaginary){

    }
    Complex(const Complex& other){
        *this = other;
    }
    const Complex& operator=(const Complex& other){
        _real = other._real;
        _imaginary = other._imaginary;

        return *this;
    }
    double getReal() const{
        return _real;
    }
    double getImaginary() const{
        return _imaginary;
    }

    bool operator==(const Complex& other) const{
        return (_real == other._real) && (_imaginary == other._imaginary);
    }

    bool operator!=(const Complex& other) const{
        return !(*this == other);
    }

    Complex operator*() const{
        return Complex(_real,-_imaginary);
    }

    ~Complex(){

    }
};

ostream& operator<<(ostream& out,const Complex& c){
    //Modified to incorporate conjugate
    if(c.getImaginary() > 0){
        out << c.getReal() << " + i" << c.getImaginary();
    }
    else{
        out << c.getReal() << " - i" << -c.getImaginary();
    }
    
    return out;
}

Complex operator+(const Complex& c1,const Complex& c2){
    return Complex(c1.getReal()+c2.getReal(),c1.getImaginary()+c2.getImaginary());
}

Complex operator+(const Complex& c1,double d){
    return Complex(c1.getReal()+d,c1.getImaginary());
}

Complex operator+(double d,const Complex& c1){
    return Complex(c1.getReal()+d,c1.getImaginary());
}

int main(int argc, char const *argv[])
{
    Complex c1(2,4);
    cout << "c1 : " << c1 << endl;
    Complex c2 = c1;
    cout << "c2 : " << c2 << endl;

    cout << "c1 + c2 : " << c1 + c2 << endl;
    Complex c3 = c1 + c2;
    cout << "c3 : " << c3 << endl;

    cout <<"1st Arg - Adding 7 : " << 7 + c3 << endl;
    cout <<"2nd Arg - Adding 10 : " << c3 + 10 << endl;
    
    //Chaining
    cout << "Multiple addition : " << 4 + c1 + 8 + c2 + c3 + 10 << endl;

    Complex c4(6,9);
    Complex c5(6,9);

    if(c4 == c5){
        cout << "Equal" << endl;
    }
    else{
        cout << "Not Equal" << endl;
    }

    Complex c6(6,9);
    Complex c7(7,9);

    if(c6 != c7){
        cout << "Not Equal" << endl;
    }
    else{
        cout << "Equal" << endl;
    }

    Complex c8(12,18);
    cout << "c8 : " << c8 << endl;
    cout << "c8 Conjugate : " << *c8 << endl;

    Complex c9 = *c8;
    cout << "c9 : " << c9 << endl;

    return 0;
}
