#include "array.hpp"
#include <string>
#include <iostream>
using namespace std;
int main()
{
    Deque<string> a1;
    a1 + string("10");
    string("20") + a1;
    cout<<a1.GetRight()->GetElement()<<endl;
    cout<<a1.GetLeft()->GetElement()<<endl;


    List<float> a2;
    List<float> a3;

    a2 + (float)0.5;
    a3 + (float)0.3;
    cout<<(a2==a3)<<endl;
    a2 = a3;
    cout<<(a2==a3)<<endl;

    Array<char*> a5;
    Array<char*> a6;

    char str[7] = "Lolkek";
    char *ptr = str;
    a5 + ptr;
    cout<<a5[1]<<endl;

    a6 + ptr;
    cout<<a6[1]<<endl;
    cout<<(a5==a6)<<endl;
    a6--;
    cout<<(a5==a6)<<endl;
}
