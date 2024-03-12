//
// Created by darkf on 1/27/2024.
//

#include "Connections.h"
#include <ctime>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

inline Connections::Connections() {
    scramble(4);
}

bool inline Connections::print_grid() {
    cout << grid[0][0] << "\t" << grid[0][1] << "\t" << grid[0][2] << "\t" << grid[0][3] << endl;
    cout << grid[1][0] << "\t" << grid[1][1] << "\t" << grid[1][2] << "\t" << grid[1][3] << endl;
    cout << grid[2][0] << "\t" << grid[2][1] << "\t" << grid[2][2] << "\t" << grid[2][3] << endl;
    cout << grid[3][0] << "\t" << grid[3][1] << "\t" << grid[3][2] << "\t" << grid[3][3] << endl;
    return true;
}

bool inline Connections::print_rules() {
    cout << "Welcome to Connections, based off the daily New York Times game!" << endl;
    cout << "You will be shown a grid of sixteen words in random order." << endl;
    cout << "These words fit into four secret categories." << endl;
    cout << "It is your job to separate them into these categories to win the game!" << endl;
    return true;
}

void inline Connections::scramble(int rows) {
    //Take all words and randomly assign places in grid
    int randomNumber, listSize;
    string currentWord;

    //Make a backup list to iterate through while sorting
    vector<string> wordsCopy;
    wordsCopy.clear();
    wordsCopy = words;

    //Fill all places with x's
    for (int downOriginal = 0; downOriginal < 4; downOriginal++) {
        for (int acrossOriginal = 0; acrossOriginal < 4; acrossOriginal++) {
            grid[downOriginal][acrossOriginal] = 'x';
        }
    }

    //Now fill the columns that should be filled with random words
    //Number of columns
    for (int down = 0; down < rows; down++) {
        //Number of rows
        for (int across = 0; across < 4; across++) {
            //Now will iterate through from left to right
            listSize = wordsCopy.size();
            bool condition = false;

            while (!condition) {
                randomNumber = (rand() % listSize);

                //Make sure the word chosen has not already been deleted
                if (wordsCopy[randomNumber] != "") {
                    currentWord = wordsCopy[randomNumber];
                    condition = true;
                }
            }

            //Replaces position of grid with current word
            grid[down][across] = currentWord;

            //Removes current word from wordscopy
            wordsCopy.erase(wordsCopy.begin() + randomNumber);

        }
    }

}

bool inline Connections::print_turn(int guesses) {
    cout << "You have " << guesses << " guesses remaining. " << endl;
    cout << "Type your four words separated by commas to guess, type (s) to shuffle words, or type (r) for rules." << endl;
    cout << "Make sure not to have spaces in your guess! Example valid input: first,second,third,fourth " << endl;
    return true;
}

int inline Connections::input_validation(string guess, int rows) {
    //Test if a single letter input, for scramble or rules.
    char singleLetter = guess.at(0);

    if (singleLetter == 'r' && guess.length() == 1) {
        print_rules();
        return 1;
    }
    else if (singleLetter == 's' && guess.length() == 1) {
        scramble(rows);
        return 1;
    }
    else {
        //We are looking for four separate words, separated by a comma.

        //https://www.simplilearn.com/tutorials/cpp-tutorial/string-stream-in-cpp#:~:text=StringStream%20in%20C%2B%2B%20is,defined%20in%20the%20StringStream%20class.
        stringstream ss(guess);
        string wordOne, wordTwo, wordThree, wordFour;
        string singleWord;
        int counter = 1;

        //Separate into four words - if more than four, fails
        while(ss.good()) {
            //Separates words by comma
            getline(ss, singleWord, ',');

            //Puts the four split words into variables
            if (counter == 1) {
                wordOne = singleWord;
                counter++;

            } else if (counter == 2) {
                wordTwo = singleWord;
                counter++;

            } else if (counter == 3) {
                wordThree = singleWord;
                counter++;

            } else if (counter == 4) {
                wordFour = singleWord;
                counter++;

            } else {
                return 0;
            }
        }

        //Verifies that you do not have fewer than four words
        if (counter != 5) {
            return 0;
        }

        //Make a copy of the vector
        vector<string> wordsCopy;
        wordsCopy = words;
        int counting = 0;

        //Verify that words are in the list
        for (int i = 0; i < words.size(); i++) {

            if (wordOne == wordsBackup[i]) {
                counting++;
            }

            if (wordTwo == wordsBackup[i]) {
                counting++;
            }

            if (wordThree == wordsBackup[i]) {
                counting++;
            }

            if (wordFour == wordsBackup[i]) {
                counting++;
            }
        }

        //Verify that all words are not the same
        //We do this character by character because for strings, the == is overloaded to just see if they are members of the same group
        if (wordOne.at(0) == wordTwo.at(0) && wordOne.at(1) == wordTwo.at(1) && wordOne.at(2) == wordTwo.at(2)) {
            return 0;
        }
        else if (wordOne.at(0) == wordThree.at(0) && wordOne.at(1) == wordThree.at(1) && wordOne.at(2) == wordThree.at(2)) {
            return 0;
        }
        else if (wordOne.at(0) == wordFour.at(0) && wordOne.at(1) == wordFour.at(1) && wordOne.at(2) == wordFour.at(2)) {
            return 0;
        }

        //Tests that all four were removed from the copy, meaning all four words still existed in possibilities
        int comparisonSize = words.size();
        if (counting == 16 && wordsCopy.size() == comparisonSize) {
            //Verify that the guessed words are all in the same group
            if (verify_guess(wordOne, wordTwo, wordThree, wordFour)) {
                return 2;
            }
            else {
                return 3;
            }
        }
    }

    return 0;
}

bool inline Connections::verify_guess(string wordOne, string wordTwo, string wordThree, string wordFour) {

    //Tests that all four words are in the same group using the overloaded operator in Connections.h
    if (wordOne == wordTwo &&  wordTwo == wordThree && wordThree == wordFour) {
        //Get what the group number is from the enum
        int number = 0;
        Wordlist wordTest = word_map.at(wordOne);

        //Goes through each possible group to see which the words are equal to
        if (wordTest == Wordlist::ache) {
            number = 1;
        }
        else if (wordTest == Wordlist::guard) {
            number = 2;
        }
        else if (wordTest == Wordlist::brain) {
            number = 3;
        }
        else if (wordTest == Wordlist::answer) {
            number = 4;

        }

        //Removes the words within that group
        remove_words(number);
        return true;

    }
    else {
        return false;
    }

}

bool inline Connections::remove_words(int number) {

    //Number is the number in enum. We have to take this number and remove words
    cout << "Congratulations! You found one of the groups!" << endl;

    //For word in list, if word == word in enum region that is being removed, delete from list
    for (int i = 0; i < words.size(); i++) {
        Wordlist wordCheck;

        //If statement to make sure not already empty, which will interfere with unordered map .at()
        if (words[i] != "") {
            wordCheck = word_map.at(words[i]);

            if (number == 1) {
                if (wordCheck == Wordlist::ache) {
                    //remove words[i]
                    words[i].erase(0);
                }

            }
            else if (number == 2) {
                if (wordCheck == Wordlist::guard) {
                    //remove words[i]
                    words[i].erase(0);
                }

            }
            if (number == 3) {
                if (wordCheck == Wordlist::brain) {
                    //remove words[i]
                    words[i].erase(0);
                }

            }
            if (number == 4) {
                if (wordCheck == Wordlist::answer) {
                    //remove words[i]
                    words[i].erase(0);
                }
            }
        }

    }

    //Print what group was guessed. Group numbers are predetermined
    if (number == 1) {
        cout << "Group One : Hurt" << endl;
    }
    else if (number == 2) {
        cout << "Group Two : Look After" << endl;
    }
    else if (number == 3) {
        cout << "Group Three : Sought After in The Wizard Of Oz" << endl;
    }
    else if (number == 4) {
        cout << "Group Four : Silent W" << endl;
    }

    return true;
}
