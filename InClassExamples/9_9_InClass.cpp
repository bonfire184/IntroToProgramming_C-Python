#include <iostream>
#include <math.h>
#include <strstream>

using namespace std;

int addNums(int a, int b) {
    return a + b;
}

void printMsg(string msg) {
    cout<<msg<<endl;
}

int Search(int PassedArray[6]){

    cout<<"What value do you want to search for?"<<endl;
    int desiredValue;
    int x;
    bool found = false;
    cin>>desiredValue;
    for(int i = 0; i<6; i++){
        if (PassedArray[i] == desiredValue){
            x = i;
            found = true;
            break;
        }
    }//end for

    if (found == true){
        cout<<"Found your value at index: "<<x<<endl;
    }
    else{
        cout<<"value not found."<<endl;
    }

}

int main() {

 /*   int a;
    string hello = "hello world";
    double e = 4.5;

    cout<<"Hello World"<<endl;
    int x = addNums(5, 6);

    cout<<"x= "<<x<<endl;

    printMsg("hello world");

    // Conditionals and loops
    // Conditions

    int intA = 5;
    if (intA < 5) {
        cout<<"intA < 5"<<endl;
    } else if (intA > 5) {
        cout<<"intA > 5"<<endl;
    } else {
        cout<<"intA = 5"<<endl;
    }

    int intB = 6;
    // Conditional for when intA = 5 and intB = 6
    if (intA == 4 and intB == 6) {
        cout<<"intA and intB"<<endl;
    } else if (intA > 5 or (addNums(5,7) < 10)) {
        cout<<"True that intA > 5 or intB = 6"<<endl;
    } else if (intA == 5 ^ intB == 7) {
        cout<<"xor"<<endl;
    }

    // ==, <, >, <=, >=, !=
    // Loops

    int intCounter = 0;
    while (intCounter <= 5) {
        cout<<intCounter<<endl;
        intCounter++;
        intCounter+= 1;
    }

    for (int i = 0; i < 10; i++) {
        cout<<i<<endl;
    }

    int intArray[10];
    cout<<"array stuff"<<endl;
    for(int i = 0; i < 10; i++){
        intArray[i] = i;
        cout<<intArray[i]<<endl;
    }//end for

        string strArray[10];
        string tmp;
        stringstream ss;
        char buffer[10];
        for(int i = 0; i < 10; i++){
            stringstream ss;
            ss<<i;

            strArray[i] = "string" + ss.str();//to string; //string1, string2
            cout<<strArray[i]<<endl;
        }//end for


    int iArray[10];
    for(int i = 0; i < 10; i++){
        iArray[i] = i;
        cout<<iArray[i]<<endl;
    }

    cout<<"2d array"<<endl;
    int iArray2[5][10];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            iArray2[i][j]=i*j;
            cout<<iArray2[i][j]<<" ";
        }
        cout<<endl;
    }
    iArray2[2][3] = 1000;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            iArray2[i][j]=i*j;
            cout<<iArray2[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    //array operations
    //insert, search, delete

    //SEARCH
    int iSearch[6] = {4, 34, 23, 56, 67, 43};
    int iSearchVal = 56;
    int iSearchIndex = -1;
    int iLength = 6;
    bool found = false;
    int x = 0;
    while(x < iLength && !found){
        if(iSearch[x] == iSearchVal){
            iSearchIndex = x;
            found = true;
        }
        x++;
    }//end while

    if(iSearchIndex != -1){
        cout<<"value found at index: "<<iSearchIndex<<endl;
    }
    else{
        cout<<"value not found"<<endl;
    }

    //write a function called search that returns the index of a value in an array

    Search(iSearch);















    return 0;
}
