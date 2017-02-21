#include <iostream> //iostream.h includes all input and output functions are defined. Within this, namespace std is included
#include <math.h>
using namespace std;


int main()
{
    cout<<"Hello World"<<endl;//cout is included in namespace std
    cout<<"Hi Again"<<endl;

    //variables
    //int - whole numbers
    //float, double - decimal numbers
    //string - alphanumeric literals
    //char - single character
    //bool - T/F, 0/1, 1 bit

    //define an integer
    int a = 5;
    cout<<a<<endl;
    int b = 6;
    cout<<"b = "<<b<<endl;

    float c = 5.6;
    double e = 4.5;

    string x = "4.5";
    string y = "5.6";

    bool myBool = true;
    cout<<myBool<<endl;

    //addition on numbers
    int d = a + b;
    cout<<"a + b = "<<d<<endl;

    //addition on strings
    string z = x + y;
    cout<<"z = "<<z<<endl;
    string s = "hello word ";
    string s2 = "how are you";
    cout<<s + s2<<endl;
//    cout<<s + d<<endl;

    //division
    float f = c/e;
    cout<<f<<endl;
    cout<<a/b<<endl;
    cout<<b/a<<endl;
    //dividing strings won't work

    //multiplying
    double z2 = a*b;
    cout<<z2<<endl;

    //exponents (you must include another library)
    z2 = pow(a,2);

    int z3 = a * (int)c;
    cout<<z3<<endl;
    float z4 = a * c;
    cout<<z4<<endl;
    double z5 = a + (b * z3) / a;

    //order of operations
    //(), *, /, %(mod), +, -
    a = 75;
    b = 50;
    int c2 = a % b;
    cout<<"c2 = "<<c2<<endl;
    z5 = (double)a/(double)b;





    return 0;
}
