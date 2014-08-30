// homework 2 madLib
// James Moore
// 8-27-14
// Davies


#include <iostream>
#include <fstream>

using namespace std;

const int MAX_NUM_WORDS = 10000;

string readWord(ifstream & ifs);
string readNonWordChars(ifstream & ifs);
bool isPartofWord (char c);

