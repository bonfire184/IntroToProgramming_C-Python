#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

struct Word{
    string abbrev;
    string translate;
};

int main(){

    Word myWord;
    myWord.abbrev = "lol";
    myWord.translate = "laugh out loud";

    int arrayLength = 4267;
    Word abbreviations[arrayLength];//array of type Word

    int x = 1234;
    double y = 4.5;

    stringstream ss2;
    ss2<<y;
    ss2>>x;

    //string x2;
    //ss2>>x2;
    cout<<x;


    ifstream words;
    words.open("textToEnglish.csv"); //csv file, saved in same directory

    if(words.fail()){
        cout<<"Something went wrong"<<endl;
    }
    else{
        //read the file
        string word;
        int lineIndex = 0;
        while(getline(words, word, '\r')){//loops over every line in the file
            //cout<<word<<endl;
            //get the individual strings out of each column
            //stringstream, creates a stream out of a string
            stringstream ss;
            ss<<word;

            int wordIndex = 0;//controls index in this while

            while(getline(ss, word,',')){//loops over each string in line
                //cout<<word<<endl;
                if(wordIndex = 0){
                   abbreviations[lineIndex].abbrev = word;
                }else if(wordIndex == 1){
                    abbreviations[lineIndex].translate = word;
                }
                wordIndex++;
            }
            lineIndex++;

        }
    }
    //write something that is searchable
    for(int i = 0; i < arrayLength; i++){
        cout<<abbreviations[i].abbrev<<" "<<abbreviations[i].translate<<endl;
    }

    //how do you ask the user for an abbreviation and return the translation?
    cout<<"Enter an abbreviation: ";
    string abbr;
    getline(cin, abbr);

    for(int i = 0; i < arrayLength; i++){
        if(abbreviations.abbrev[i] == abbr){
            cout<<"Translation: "<<abbreviations[i].translate<<endl;
        }
    }



}
