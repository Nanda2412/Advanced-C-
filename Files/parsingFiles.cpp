#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// There are quite a lot of methods available for trimming different characters out of the given string
// Boost ::trim method is an option - But if it creates too much overhead we can do it with C++ in-built library methods
// boost::trim(s); - removes all leading and trailing white spaces
// boost::trim_if(s,boost::is_any_of("\t")); removes only tabs
// s.erase(std::remove(s.begin(),s.end(),'\t'),s.end()) - if you want to remove all the tabs from the string std::remove exists in <algorithm>
// std::string::size_type begin = s.find_first_not_of('\t');
// std::string::size_type end = s.find_last_not_of('\t');
// std::string trimmed = s.substr(begin,end-begin+1);

int main(){

    string filename = "stats.txt";
    ifstream input;

    input.open(filename);

    if(!input.is_open()){
        return 1;
    }

    while(input){
        string line;
        getline(input,line,':');

        int population;
        input >> population;

        //input.get();
        input >> ws; //C++11 feature - discard the whitespace

        if(!input){
            break;
        }

        cout << "'" << line << "'" << " : '" << population << "'" << endl; 
    }

    return 0;
}