#include <iostream>

using namespace std;

//Hayden Lingle
//Tuesday Recitation @ 2pm w/Camilla
//Assignment #4

void calculateSimilarity(double *similarity, string DNA1, string DNA2){//passed in a pointer of similarity variable and two strings

    int HammingDistance = 0;//Hamming distance will start at 0

    for (int i = 0; i < DNA2.length(); i++){
        if(DNA1[i] == DNA2[i]){}//If the characters are identical at index i, Hamming Distance will not go up

        else if(DNA1[i] != DNA2[i]){
            HammingDistance += 1;//If the characters are different at index i, Hamming Distance will go up by 1
        }
    }//end for

    double calc1 = (DNA2.length() - HammingDistance);//split the calculation up into two parts because it was calculating wrong in one piece
    double calc2 = calc1/DNA2.length();

    *similarity = calc2;//value at the pointer gets updated with the finished calculation
}

void calculateBestMatch(int *HamValue, int *IndexOfBestMatch, string SubString, string KnownDNA){
    //cout<<"CalculateBestMatch called"<<endl;

    int BestHamVal = SubString.length();//Initialize BestHamVal at the length of SubString. It can only go down from here
    int NewHamVal;//This will be re-updated after each time it runs through the for loop of KnownDNA, to see if a better string was found

    for (int j = 0; j < KnownDNA.length(); j++){//Starts at an index of the Human or Mouse DNA and checks the SubString versus
        NewHamVal = 0;
        for (int i = 0; i < SubString.length(); i++){//This for loop runs through the length of Substring checking against its new position in the Full DNA Sequence
            if(SubString[i] == KnownDNA[i + j]){}
            else if(SubString[i] != KnownDNA[i + j]){//the i+j offsets the new position of the substring based on the DNA sequence
                NewHamVal += 1;
            }
        }//end for loop #2
        if (NewHamVal < BestHamVal){//If the new ham value was lower than before, the new sequence is more similar.
            BestHamVal = NewHamVal;
            *IndexOfBestMatch = j;
        }
    }//end for loop #1


    if (BestHamVal == SubString.length()){//If the best ham value after checking entire DNA sequence is still the length of substring, no matching values were found.
        cout<<"No matches found for any part of your substring."<<endl;
    }
    else{
        cout<<"Closest Match Found in DNA: ";
        for (int i = *IndexOfBestMatch; i < *IndexOfBestMatch + SubString.length(); i++ ){//Will start printing at the first index of the best match found, and loop until as many values as the length of substring have been printed.
        cout<<KnownDNA[i];
        }
        cout<<"\nFound starting at index: "<< *IndexOfBestMatch<<"\nLowest Ham Achieved of: "<<BestHamVal;
    }
}

int main(){
    double SimilarityHuman, SimilarityMouse;

    double *PtrSim_Human; //creating a pointer variable
    double *PtrSim_Mouse; //creating a pointer variable
    PtrSim_Human = &SimilarityHuman; //PtrSim_Human = Memory Address of Human Similarity
    PtrSim_Mouse = &SimilarityMouse; //PtrSim_Mouse = Memory Address of Mouse Similarity

    string subStr;
    string HumanDNA =   "CGCAAATTTGCCGGATTTCCTTTGCTGTTCCTGCATGTAGTTTAAACGAGATTGCCAGCACCGGGTATCATTCACCATTTTTCTTTTCGTTAACTTGCCGTCAGCCTTTTCTTTGACCTCTTCTTTCTGTTCATGTGTATTTGCTGTCTCTTAGCCCAGACTTCCCGTGTCCTTTCCACCGGGCCTTTGAGAGGTCACAGGGTCTTGATGCTGTGGTCTTCATCTGCAGGTGTCTGACTTCCAGCAACTGCTGGCCTGTGCCAGGGTGCAGCTGAGCACTGGAGTGGAGTTTTCCTGTGGAGAGGAGCCATGCCTAGAGTGGGATGGGCCATTGTTCATG";
    string MouseDNA =   "CGCAATTTTTACTTAATTCTTTTTCTTTTAATTCATATATTTTTAATATGTTTACTATTAATGGTTATCATTCACCATTTAACTATTTGTTATTTTGACGTCATTTTTTTCTATTTCCTCTTTTTTCAATTCATGTTTATTTTCTGTATTTTTGTTAAGTTTTCACAAGTCTAATATAATTGTCCTTTGAGAGGTTATTTGGTCTATATTTTTTTTTCTTCATCTGTATTTTTATGATTTCATTTAATTGATTTTCATTGACAGGGTTCTGCTGTGTTCTGGATTGTATTTTTCTTGTGGAGAGGAACTATTTCTTGAGTGGGATGTACCTTTGTTCTTG";
    string UnknownDNA = "CGCATTTTTGCCGGTTTTCCTTTGCTGTTTATTCATTTATTTTAAACGATATTTATATCATCGGGTTTCATTCACTATTTTTCTTTTCGATAAATTTTTGTCAGCATTTTCTTTTACCTCTTCTTTCTGTTTATGTTAATTTTCTGTTTCTTAACCCAGTCTTCTCGATTCTTATCTACCGGACCTATTATAGGTCACAGGGTCTTGATGCTTTGGTTTTCATCTGCAAGAGTCTGACTTCCTGCTAATGCTGTTCTGTGTCAGGGTGCATCTGAGCACTGATGTGGAGTTTTCTTGTGGATATGAGCCATTCATAGTGTGGGATGTGCCATAGTTCATG";

    calculateSimilarity(PtrSim_Human, UnknownDNA, HumanDNA);//Calculates similarity between Unknown DNA and Human DNA, updates SimilarityHuman variable
    calculateSimilarity(PtrSim_Mouse, UnknownDNA, MouseDNA);//Calculates similarity between Unknown DNA and Mouse DNA, updates SimilarityMouse variable

    if (SimilarityHuman > SimilarityMouse){
        cout<<"Human"<<endl;
        //cout<<"Similarity Human: "<<SimilarityHuman * 100<<"%"<<endl;
    }
    else if(SimilarityMouse > SimilarityHuman){
        cout<<"Mouse"<<endl;
        //cout<<"Similarity Mouse: "<<SimilarityMouse * 100<<"%"<<endl;
    }
    else{
        cout<<"Identity cannot be determined."<<endl;//Either it is weird input, or the similarity is the same to both species
    }

    cout<<"Enter a substring."<<endl;
    getline(cin, subStr);

    int HammingValue;
    int *HamPtr;
    HamPtr = &HammingValue;

    int IndexBestMatch;
    int *BestMatchPtr;
    BestMatchPtr = &IndexBestMatch;

    int choice = 0;
    while (choice != 1 && choice != 2){
        cout<<"1. Compare Substring to Human."<<endl;
        cout<<"2. Compare Substring to Mouse."<<endl;
        cin>>choice;

        if (choice == 1){
            HammingValue = 0;
            IndexBestMatch = 0;
            calculateBestMatch(HamPtr, BestMatchPtr, subStr, HumanDNA);//passes subStr plus the HumanDNA to compare it to
        }
        else if(choice == 2){
            HammingValue = 0;
            IndexBestMatch = 0;
            calculateBestMatch(HamPtr, BestMatchPtr, subStr, MouseDNA);//passes subStr plus the MouseDNA to compare it to
        }
    }//end while
}
