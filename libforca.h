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

/**
 * @brief Reads all words from words_filename and randomly return one of them
 * 
 * @return string 
 */
string read_words_from_file_and_raffle();

/**
 * @brief Prints the list of wrong letters used already
 * 
 */
void print_wrong_letters_list();

/**
 * @brief Adds a  '_' for every letter of secret_word as the user didn't 
 * guess any letter yet
 * 
 */
void start_forca_status();

/**
 * @brief Prints the current status of the forca, showing just the letters 
 * of the secret word that the player already entered. For example:
 * "A _ E _ A N _ A" -> for ALEMANHA. 
 */
void print_forca_status();

/**
 * @brief Checks if the guessed letter is part of the secret word
 * 
 */
bool is_letter_in_secret_word();

/**
 * @brief Checks in both list_wrong_letters and list_correct_letters
 * if the guessed letter was used already
 */
bool was_letter_used();
