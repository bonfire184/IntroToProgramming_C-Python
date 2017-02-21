#include <iostream>
using namespace std;

/*void f(int x){

}*/

int main(int argc, char *argv[]){
    string filename = "boulderData";
    ///works, but what if we want to change filename?
    cout<<argv[0]<<endl;
    cout<<argv[1]<<endl;
    cout<<argc<<endl;
    for(int i = 0; i < argc; i++){
        cout<<argv[i]<<endl;
    }

}
