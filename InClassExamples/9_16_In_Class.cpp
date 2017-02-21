#include <iostream>

using namespace std;

int Function1(int x, int y){
    int sum = x + y;
    return sum;

}

void Function2(int x, int y, int *xPtr){
    *xPtr = x + y;
    cout<<"c = "<<xPtr<<endl;
    cout<<"*c = "<<*xPtr<<endl;
}

void Function3(int a, int b, int *sumPtr, int *differencePtr, int *productPtr){
    *sumPtr = a + b;
    *differencePtr = a - b;
    *productPtr = a * b;
}




int main(){

    // int *xPtr = &x
    // equivalent to//int *xPtr;
                    //xPtr = &x
    // &x means address of x, xPtr stores the ADDRESS of x
    // *xPtr => when you put an astrix it dereferences the ADDRESS to find the value STORED at that address

    int x;
    int *xPtr;
    xPtr = &x;

    cout<<Function1(5,4)<<endl;

    Function2(4, 5, xPtr);
    cout<<x<<endl;

    //sum product difference function stuff
    int sum;
    int product;
    int difference;

    int *sumPtr = &sum;
    int *productPtr = &product;
    int *differencePtr = &difference;

    Function3(4, 5, sumPtr, productPtr, differencePtr);

    cout<<sum<<" "<<product<<" "<<difference<<" "<<endl;

    return 0;

    /*ASSIGNMENT 4 MENU UN-USED

    int choice = 0;//Initialize menu selection so the loop will begin below
    while (choice != 4){
        cout<<"1. Calculate similarity between Unknown DNA and Human DNA."<<endl;
        cout<<"2. Calculate similarity between Unknown DNA and Mouse DNA."<<endl;
        cout<<"3. Enter a substring and search for a match."<<endl;
        cout<<"4. Quit."<<endl;

        cin>>choice;

        if(choice == 1){
            calculateSimilarity(PtrSim_Human, UnknownDNA, HumanDNA);
            cout<<"Similarity Human: "<<SimilarityHuman * 100<<"%"<<endl;
        }
        else if(choice == 2){
            calculateSimilarity(PtrSim_Mouse, UnknownDNA, MouseDNA);
            cout<<"Similarity Mouse: "<<SimilarityMouse * 100<<"%"<<endl;
        }

    }//end While loop*/
}
