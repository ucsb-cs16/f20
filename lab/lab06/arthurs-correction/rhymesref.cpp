/*
/ RHYMES.CPP for CS16, Winter 2021, UCSB
/ Copyright Â© 2017, 2020 by Arthur Gatin. All rights reserved.
/
/ The program reads an input file -- ostensibly a poem with rhymes on adjacent lines.
/ It looks for rhymes between every two lines. A rhyme is simply defined as true if 
/   two words that are being compared share the same 2 last letters.
/ If a word on a line has punctuation marks on it (e.g. "hello?!"), the program must first 
/   remove all non-alphabets from the word (e.g. it becomes "hello").
/ Finally, the program has to state how many rhyming pairs it found, or if it did not find any at all.
/
*/


#include <iostream>
#include <fstream>

using namespace std;

//Your program should define at least 3 functions that only do last-word extraction, word-end comparisons, and word clean-up.


//Do this first
string extractLastWord(string bigstring){

    if(bigstring.find(" ") == -1) return "";

    return bigstring.substr(bigstring.rfind(" ") + 1);
}


//Do this last
bool endsEqual(string lastword1, string lastword2){ 

    if(lastword1.size() < 2 || lastword2.size() < 2) return false;

    return lastword1.substr(lastword1.size()-2) == lastword2.substr(lastword2.size()-2);
}

//Do this second
string cleanWord(string uncleanWord){ //s@#@een -> seen
    //STUB
    string out = "";

    for(size_t i = 0; i < uncleanWord.size(); i++){
        if(isalpha(uncleanWord[i])) out += (uncleanWord[i]);
    }
    return out;
}


int main(){

    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    

    ifstream ifs;
    string filename;
    string tempString1;
    string tempString2;
    string word1, word2;

    int lines  = 1, rhymes = 0;
    

    cout << "Enter filename: ";
    cin >> filename;

    ifs.open(filename);

    if(ifs.fail()){
        cerr << "Input file opening failed." << endl;
        return 1;
    }

    getline(ifs, tempString1);

    if(tempString1 == ""){
        cout <<"There are no rhymes." << endl;
        return 0;
    }

    while(ifs.good()){
        getline(ifs, tempString2);

        lines++;
        //the code for checking for rhyme is here
        word1 = cleanWord(extractLastWord(tempString1));
        word2 = cleanWord(extractLastWord(tempString2));

        if(endsEqual(word1, word2)){
            cout << word1 << " and " << word2 << endl;
            rhymes++;
        }

        tempString1 = tempString2;


    }

    if(rhymes == 0){
        cout << "No rhymes found." << endl;
        cout << "There are " << lines << " lines in this poem." << endl;
    }

    else{
        string plural =  (rhymes > 1 ? "s" : "");
        string refverb = (rhymes > 1 ? "are" : "is");
        cout << "There "  <<  refverb << " " << rhymes << " pair" << plural << " of rhyming words." << endl;
        cout << "There are " << lines << " lines in this poem, so the rhyme-line density is: " << 1.0*rhymes / lines << endl;
    }





    ifs.close();
    return 0;
}

