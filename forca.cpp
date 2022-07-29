#include<iostream>
#include<string>
#include "libforca.h"
using namespace std;

int main(){

    char guessed_letter = ' ';

    print_game_title();

    secret_word = read_words_from_file_and_raffle();

    if(secret_word.length() == 0){
        cout << "There is a problem with the input words file. Ending game..." << endl;
        return 0;
    }

    start_forca_status();
    missing_letters = secret_word.length();

    while ((wrong_guesses_count<LIMIT_GUESSES) && (missing_letters > 0)){

        print_wrong_letters_list();

        print_forca_status();

        cout << "Please input a letter you guess it's in the secret word:" << endl;
        cin >> guessed_letter;

        //check if it's a valid letter and convert to Upper case
        if (!isalpha(guessed_letter)){
            cout << "Invalid letter!" << endl << endl;
            continue;
        } else{
            guessed_letter = (char) toupper(guessed_letter);
        }

        //check if the tiped letter was previously used
        if (was_letter_used(guessed_letter)){
            cout << "Letter used already" << endl << endl;
            continue;
        } 

        //check if the guessed letter is in the secret word
        if (is_letter_in_secret_word(guessed_letter)){
            cout << "Good guess!!" << endl << endl;
            list_correct_letters.push_back(guessed_letter);
        } else{
            list_wrong_letters.push_back(guessed_letter);
            wrong_guesses_count++;
            cout << "Letter not in secret word. You have used " << wrong_guesses_count << 
            " guesses of " << LIMIT_GUESSES << "" << endl << endl;
        }

    }

    if (missing_letters == 0){
        print_forca_status();
        cout << "Congratulations! You've got the word correct" << endl << endl;
    }
    else
        cout << "Sorry, you reached the limit of guesses. Try again!" << endl << endl;

}

