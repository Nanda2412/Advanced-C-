#include <iostream>
#include <string>

using namespace std;

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
    // Not really following encapsulation
    // friend ostream& operator<<(ostream& out,const Complex& instance){
    //     out << instance._real << " + i" <<  instance._imaginary;
    //     return out; 
    // }
    // Workaround
    double getReal() const{
        return _real;
    }
    double getImaginary() const{
        return _imaginary;
    }

    ~Complex(){

    }
};

ostream& operator<<(ostream& out,const Complex& c){
    out << c.getReal() << " + i" << c.getImaginary();
    return out;
}

int main(int argc, char const *argv[])
{
    Complex c1(2,4);
    cout << c1 << endl;
    Complex c2 = c1;
    cout << c2 << endl;
    return 0;
}
