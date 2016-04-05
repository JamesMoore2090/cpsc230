// homework 2 madLib
// James Moore
// 8-30-14
// Davies


#include <iostream>
#include <fstream>

using namespace std;

const int MAX_NUM_WORDS = 10000;

string readWord(ifstream & ifs);
string readNonWordChars(ifstream & ifs);
bool isPartOfWord (char c);

int main(int argc, char *argv[]){

	// check to see if the command-line arg is vaild
	if (argc != 2){
		cout << "Usage: madLib [madLibTemplateFile]." << endl;
		return 1;
	} // end if

	//open file. If file does not open print and error message and quit
	ifstream ifs(argv[1]);
	if(!ifs){
		cout << "Could not open template file " << argv[1] << "!" << endl;
		return 2;
	} //end if

	// Read every word in the file and store them in an array
	string words[MAX_NUM_WORDS];
	int wordNum = 0;
	ifs >> words[wordNum];

	while (ifs){
		wordNum++;
		words[wordNum] = readWord(ifs);
		if(ifs) {
			wordNum++;
			words[wordNum]= readNonWordChars(ifs);
		}// end if
	}// end while

	//find every word that starts an underscore in the array and replace 
	//it with an user prompt
	string users_words[MAX_NUM_WORDS];
	int usersWordNum=0;
	for(int i=0; i<wordNum; i++){
		if(words[i][0] == '_') {
			cout << "Gimme a " << words[i].substr(1) << ": ";
			getline(cin, users_words[usersWordNum++]);
		} //end if
	} // end for
	
	// Print out the MadLib!
	usersWordNum = 0;
        for (int i=0; i<=wordNum; i++){
                if(words[i][0] == '_'){
                        cout << users_words[usersWordNum++];
                }// end if
                else {
                        cout << words[i];
                } //end else
        }// end for

}// end main

// helper function to read all words
string readWord(ifstream & ifs){
	string ret_val;
	char c;
	while (ifs && isPartOfWord((char) ifs.peek())){
		ifs.get(c);
		ret_val += c;
	} // end while
	return ret_val;
}// end function

// helper fuction to read all NON-word characters
string readNonWordChars(ifstream & ifs) {
	string ret_val;
	char c;
	while (ifs && !isPartOfWord((char) ifs.peek())){
		ifs.get(c);
		ret_val += c;
	} // end while
	return ret_val;
} // end function

// what is a word!
bool isPartOfWord(char c) {
	return isalpha(c) || c == '_';
} // end function
