//
// Created by darkf on 1/25/2024.
//
#include "Connections.cpp"
using namespace std;

int main() {
    Connections connections;
    connections.print_rules();

    //The number of guesses the player is allowed
    int guesses = 5;

    //Starts with four rows, or the full grid
    int rows = 4;
    string guess;

    //Repeat until player runs out of guesses or guesses every word
    while (guesses > 0 && rows > 0) {
        connections.scramble(rows);
        connections.print_grid();
        connections.print_turn(guesses);

        //Used to check when looping until a valid answer is provided
        bool condition = false;

        //Repeat until a guess is made correctly or incorrectly
        while (!condition) {
            getline(cin, guess);

            //Validates the input and determines what response is given
            int inputReturn = connections.input_validation(guess, rows);

            if (inputReturn == 1) {

                //Reset or scramble, condition does not change
                connections.print_grid();
                connections.print_turn(guesses);
            }

            else if (inputReturn == 2) {

                //The guess is correct!
                rows -= 1;
                condition = true;
            }

            else if (inputReturn == 3) {

                //Valid guesses but not correct
                guesses -= 1;
                cout << "This is not a correct group. You have " << guesses << " guesses remaining." << endl;
                condition = true;
            }

            else {

                //The inputted response was not valid. The loop will iterate again
                cout << "Invalid input" << endl;
                connections.print_turn(guesses);
            }
        }
    }

    //Lose condition
    if (guesses == 0 || guesses < 0) {
        cout << "Game Over! You Lose." << endl;
    }

    //Win condition
    if (rows == 0) {
        cout << "Congratulations! You win! " << endl;
    }
}