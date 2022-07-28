#pragma once 

#include<iostream>
#include<string>
using namespace std;

extern const unsigned short LIMIT_GUESSES;

extern string secret_word;
extern string forca_status;

/**
 * @brief This function just prints the Title of the game 'Jogo da Forca'
 * in a banner way 
 */
void print_game_title();


string read_words_from_file_and_rafle();

void raffle_word();

bool print_wrong_words_list();

bool print_forca_status();

bool letter_has_been_used();

bool is_letter_in_secret_word();