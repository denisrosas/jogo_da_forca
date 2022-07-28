#include<iostream>
#include<string>
#include "libforca.h"
using namespace std;

int main(){

    //TODO print game title

    //TODO open file, read and fill vector

    //raffle_word

    //TODO inicia variaveis

    //while loop ((wrong_guesses_count<LIMIT_GUESSES) && (missing_letters > 0)){

        char guess = ' ';

        print_game_title();

        secret_word = read_words_from_file_and_rafle();

        cout << "secret word: = " << secret_word << endl;
        
        //Print typed letters
        //Print forca_status
        // Ask user to enter input and wait for reading
        // confirm if letter is valid, and change to uppercase
        // check if letter has already been used

        //check if letter is in word
        //if it is, change state force and congratulations and decrease missing_letters
        //if not, put it in the list of wrong letters and increase the number of wrong attempts

        //
    //}

    //if missing_letters == 0 -> GANHOU
    //else "Sorry, you reached the limit of guesses"

}

