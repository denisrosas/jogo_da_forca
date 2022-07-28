#include<iostream>
#include<string>
#include "libforca.h"
using namespace std;

int main(){

    char guess_letter = ' ';
    ushort wrong_guesses_count = 0;

    print_game_title();

    secret_word = read_words_from_file_and_raffle();

    if(secret_word.length() == 0){
        cout << "There is a problem with the input words file. Ending game..." << endl;
        return 0;
    }

    cout << "Secret word: " << secret_word << endl;

    start_forca_status();
    ushort missing_letters = secret_word.length();

    while ((wrong_guesses_count<LIMIT_GUESSES) && (missing_letters > 0)){

        print_wrong_letters_list();

        print_forca_status();

        cout << "Please input a letter you guess it's in the secret word:";
        cin >> guess_letter;

        //check if it's a valid letter and convert to Upper case
        if (!isalpha(guess_letter)){
            cout << "Invalid letter!" << endl << endl;
            continue;
        } else{
            guess_letter = (char) toupper(guess_letter);
        }



        // check if letter has already been used

        //check if letter is in word
        //if it is, change state force and congratulations and decrease missing_letters
        //if not, put it in the list of wrong letters and increase the number of wrong attempts

        //
    }

    //if missing_letters == 0 -> GANHOU
    //else "Sorry, you reached the limit of guesses"

}

