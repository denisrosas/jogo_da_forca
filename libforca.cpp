#include<iostream>
#include<string>
#include "libforca.h"
#include <fstream>
#include <vector>
#include <cstdlib> 
#include <ctime>

using namespace std;

//Global Variables
const unsigned short LIMIT_GUESSES = 10;
const string words_filename = "paises.txt";

string secret_word = "";
string forca_status = "";

vector<string> words_from_file;

void print_game_title(){

    system("figlet -c Jogo da Forca");
    cout << endl << endl;

}

string read_words_from_file_and_rafle(){

    ifstream file;
    string buffer;

    file.open(words_filename);

    ushort nwords = 0;
    cout << "size of nwords = " << sizeof(nwords) << endl;

    file >> nwords; //first line of the file should contain the number of words
    if (!nwords) return ""; //returns an empty string if number is 0

    for (ushort i = 0; i < nwords; i++)
    {
        file >> buffer;
        if(buffer.size()>0)  words_from_file.push_back(buffer);

    }

    // now we'll randomly select a number between 0 and nwords and return its 
    // position on words_from_file
    srand(time(NULL)); 
    return words_from_file.at( rand()%nwords );
}


bool print_wrong_words_list(){

    return false;
}

bool print_forca_status(){
    // for (char letter : forca_status) {
    //     cout << letra << " ";
    // }

    // cout << endl;
    return false;
}

bool letter_has_been_used(){
    return false;
}

bool is_letter_in_secret_word(){
    return false;
}
