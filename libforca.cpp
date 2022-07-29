#include<iostream>
#include<string>
#include "libforca.h"
#include <fstream>
#include <vector>
#include <cstdlib> 
#include <ctime>

using namespace std;

//Global Variables
const unsigned short LIMIT_GUESSES = 5;
ushort missing_letters = 0;
ushort wrong_guesses_count = 0;
const string words_filename = "countries.txt";

string secret_word = "";
string forca_status = "";

vector<string> words_from_file;
vector<char> list_wrong_letters;
vector<char> list_correct_letters;

void print_game_title(){

    cout << "           _____                   _        ____                      " << endl;
    cout << "          |  ___|__  _ __ ___ __ _( )___   / ___| __ _ _ __ ___   ___ " << endl;
    cout << "          | |_ / _ \\| '__/ __/ _` |// __| | |  _ / _` | '_ ` _ \\ / _ \\" << endl;
    cout << "          |  _| (_) | | | (_| (_| | \\__ \\ | |_| | (_| | | | | | |  __/" << endl;
    cout << "          |_|  \\___/|_|  \\___\\__,_| |___/  \\____|\\__,_|_| |_| |_|\\___|" << endl;
    cout << "" << endl;

}

string read_words_from_file_and_raffle(){

    ifstream file;
    string buffer;

    file.open(words_filename);

    ushort nwords = 0;

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


void print_wrong_letters_list(){

    cout << "List of wrong guessed letters: ";

    if(list_wrong_letters.size() == 0){
        cout << "(EMPTY)";
    } else {
        for(char letter : list_wrong_letters){
            cout << letter << ", ";
        }
    }
    cout << endl;
}

void start_forca_status(){
    for(char letter : secret_word){
        forca_status.push_back('_');
    }
}

void print_forca_status(){
    cout << "Secret word: ";
    for (char letter : forca_status) {
        cout << letter << " ";
    }

    cout << endl;
}

bool is_letter_in_secret_word(char guessed_letter){
    bool result = false;
    ushort index = 0;

    for(char letter : secret_word){
        if(letter == guessed_letter){
            result = true;
            missing_letters--;
            forca_status[index] = guessed_letter;
        }
        index++;
    }
    return result;
}

bool was_letter_used(char guessed_letter){

    for(char letter : list_wrong_letters){
        if (letter == guessed_letter) 
            return true;
    }

    for(char letter : list_correct_letters){
        if (letter == guessed_letter) 
            return true;
    }

    return false;
}
