#include <iostream>

using namespace std;

int addNumbers(int a, int b){
    return a + b;
}

double divNumbers(double a, double b){
    return a/b;
}

//when a function doesn't return anything
void printMessage(string msg){
    cout<<msg<<endl;
    //no return statement behbeee
}

int main(){

    /*
    cout<<"hello world"<<endl;
    int n;
    cout<<"enter an integer!!!!!!!!: ";
    //cin>>n;
    //cin.ignore(); //Tells the computer to ignore the buffer items before this

    cout<<"n = "<<n<<endl;

    string s;
    cout<<"Type a string: ";
    getline(cin, s, '\n');
    cout<<s<<endl;

    string strA = "this is a string";
    int x = strA.find('a');
    cout<<"value of x: "<<x<<endl;
    cout<<strA[x]<<endl;

    //char
    char chrFoo[20]; //allocates space for 20 chars

    //create and set values in one line
    char chrWord[] = {'H', 'e', 'l', 'l', 'o', '\n'};
    cout<<chrWord[0]<<endl;
    cout<<chrWord[1]<<endl;
    cout<<chrWord[2]<<endl;
    */

    //functions
    cout<<addNumbers(3,4)<<endl;

    double e = divNumbers(5,6);
    cout<<e<<endl;

    printMessage("hello world");




    return 0;



}
