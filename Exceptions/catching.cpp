#include <iostream>
#include <exception>

using namespace std;

void goesWrong(){
    bool error1Detected = true;
    bool error2Detected = false;

    if(error1Detected){
        throw bad_alloc();
    }
    if(error2Detected){
        throw exception();
    }
}

int main(){

    try{
        goesWrong();
    }
    //Catch sub-class exception before parent class - catching order of exception matters
    catch(exception& e){
        cout << "Caught exception : exception()" << endl;
    }
    catch(bad_alloc& e){
        cout << "Caught exception : bad_alloc()" << endl;
    }


    return 0;
}