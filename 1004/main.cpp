#include <iostream>
#include <cstdio>
using namespace std;

 string Convert(string word,string convert_word)
 {
     string output = "";
     return output;
 }

int main()
{
    string word,convert_word;
    while(cin>>word>>convert_word)
    {
        cout<<"["<<endl;
        string str = Convert(word,convert_word);
        if(str != "")
            cout<<str<<endl;
        cout<<"]"<<endl;
    }

    return 0;
}
