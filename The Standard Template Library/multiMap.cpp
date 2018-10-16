#include <iostream>
#include <string>
#include <map>

using namespace std;
 
int main(int argc, char const *argv[])
{
    multimap<int,string> lookup;

    lookup.insert(make_pair(30,"Mike"));
    lookup.insert(make_pair(10,"Vishal"));
    lookup.insert(make_pair(30,"Raj"));
    lookup.insert(make_pair(30,"Angel"));

    for(multimap<int,string>::iterator it = lookup.begin(); it != lookup.end(); it++){
        cout << it->first << " : " << it->second << endl;
    }

    cout << endl;
    //In the new C++ standards long variable names like below 
    //'pair<multimap<int,string>::iterator,multimap<int,string>::iterator>'
    //can be replaced using auto keyword - more readability
    pair<multimap<int,string>::iterator,multimap<int,string>::iterator> its = lookup.equal_range(30);

    for(multimap<int,string>::iterator it = its.first; it != its.second; it++){
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}
