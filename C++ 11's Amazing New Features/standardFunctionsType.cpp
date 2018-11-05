#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool check(string& text){
    return text.size() == 3;
}

class Check{
public:
    bool operator()(string& text){
        return text.size() == 5;
    }
}check1;

//std function
void run(function<bool(string&)> check){
    string text = "one";
    cout << check(text) << endl;
}

int addTwoNumbers(int a, int b){
    return a+b;
}

class Addition{
public:
    int operator()(int a,int b){
        return a+b;
    }
}addNumbers;

int main(int argc, char const *argv[])
{
    int size = 5;
    vector<string> texts{"one","two","three"};

    auto lambda = [size](string text){ return text.size() == size;};
    
    //lambda
    int count = count_if(texts.begin(),texts.end(),lambda);
    cout << count << endl;
    //function pointer
    count = count_if(texts.begin(),texts.end(),check);
    cout << count << endl;
    //functor
    count = count_if(texts.begin(),texts.end(),check1);
    cout << count << endl;

    //using lambda, function pointer and functor in the function accepting std::function
    run(lambda);
    run(check);
    run(check1);

    function<int(int,int)> add = [](int a,int b){return a+b;};
    cout << add(7,3) << endl;
    add = addTwoNumbers;
    cout << add(7,4) << endl;
    add = addNumbers;
    cout << add(7,5) << endl;

    return 0;
}
