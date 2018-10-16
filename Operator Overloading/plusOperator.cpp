#include <iostream>
#include <string>

using namespace std;

// Adding plus operator overloading...
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

    ~Complex(){

    }
};

ostream& operator<<(ostream& out,const Complex& c){
    out << c.getReal() << " + i" << c.getImaginary();
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

    // int a = 1 ,b = 2, c = 3;
    // (a=b)=c;
    // cout << a << b << c << endl;

    return 0;
}
