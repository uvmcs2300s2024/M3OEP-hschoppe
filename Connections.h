//
// Created by darkf on 1/25/2024.
//

#ifndef M1OEP_HSCHOPPE_CONNECTIONS_H
#define M1OEP_HSCHOPPE_CONNECTIONS_H

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

//https://stackoverflow.com/questions/7163069/c-string-to-enum
//Enum of words - used to identify words by their groups
enum class Wordlist { ache = 1, burn = 1, smart = 1, sting = 1,
    guard = 2, mind = 2, tend = 2, watch = 2,
    brain = 3, courage = 3, heart = 3, home = 3,
    answer = 4, two = 4, wrist = 4, wrong = 4};

//Word map, used to convert strings into enum type to allow for comparison
unordered_map<string, Wordlist> const word_map {
        {"ache", Wordlist::ache},
        {"burn", Wordlist::burn},
        {"smart", Wordlist::smart},
        {"sting", Wordlist::sting},
        {"guard", Wordlist::guard},
        {"mind", Wordlist::mind},
        {"tend", Wordlist::tend},
        {"watch", Wordlist::watch},
        {"brain", Wordlist::brain},
        {"courage", Wordlist::courage},
        {"heart", Wordlist::heart},
        {"home", Wordlist::home},
        {"answer", Wordlist::answer},
        {"two", Wordlist::two},
        {"wrist", Wordlist::wrist},
        {"wrong", Wordlist::wrong},
};


class Connections {

private:

    //Grid, used for displaying words
    string grid[4][4] = {{"a", "a", "a", "a"},
                         {"a", "a", "a", "a"},
                         {"a", "a", "a", "a"},
                         {"a", "a", "a", "a"}};

    //All words, one of which is removed from and a constant to use for comparison
    vector<string> words{"ache", "burn", "smart", "sting", "guard", "mind", "tend", "watch", "brain", "courage", "heart", "home", "answer", "two", "wrist", "wrong"};
    vector<string> const wordsBackup{"ache", "burn", "smart", "sting", "guard", "mind", "tend", "watch", "brain", "courage", "heart", "home", "answer", "two", "wrist", "wrong"};


public:

    /*
     * Default Constructor
     * Requires: nothing
     * Modifies: nothing
     * Effects: Scrambles the words in the grid
     */
    Connections();

    /*
     * Prints grid
     * Requires: nothing
     * Modifies: nothing
     * Effects: Prints the grid into the console
     */
    bool  print_grid();

    /*
     * Prints rules
     * Requires: nothing
     * Modifies: nothing
     * Effects: Prints the instructions into the console
     */
    bool print_rules();

    /*
     * Scramble
     * Requires: rows
     * Modifies: grid[][]
     * Effects: Scrambles all of the un-guessed words into the grid
     */
    void scramble(int rows);

    /*
     * Print turn
     * Requires: guesses
     * Modifies: nothing
     * Effects: Prints the message invoking player input
     */
    bool print_turn(int guesses);

    /*
     * Input Validation
     * Requires: guess, rows
     * Modifies: nothing
     * Effects: Verifies that the input is either the call to scramble, print instructions, or is four valid words
     *          Calls verify_guess to make sure the four words are all part of the same group
     *          Returns a number based on what type of response was given and whether or not it was valid
     */
    int input_validation(string guess, int rows);

    /*
     * Verify guess
     * Requires: wordOne, wordTwo, wordThree, wordFour
     * Modifies: nothing
     * Effects: Determines that the four words are all part of the same group
     */
    bool verify_guess(string wordOne, string wordTwo, string wordThree, string wordFour);

    /*
     * Remove words
     * Requires: number
     * Modifies: words
     * Effects: Removes correctly guessed words from the list of words
     */
    bool remove_words(int number);

};

//Overload operator
//Check if two strings in wordlist carry the same value in the enum wordlist
bool inline operator==(string s1, string s2)  {

    //Check if both strings are in the enum
    if (word_map.find(s1) != word_map.end() && word_map.find(s2) != word_map.end()) {
        Wordlist word1 = word_map.at(s1);
        Wordlist word2 = word_map.at(s2);

        if (word1 == word2) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }

}

#endif //M1OEP_HSCHOPPE_CONNECTIONS_H
