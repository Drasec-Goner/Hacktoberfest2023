/*
Code for an advanced rock-paper-scissors game in C++:
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main() {
    srand(time(0)); // Seed the random number generator with current time

    std::cout << "Welcome to Rock-Paper-Scissors-Lizard-Spock Game!" << std::endl;

    int playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;
    char playAgain;
    int difficultyLevel;

    do {
        std::cout << "Choose your difficulty level (1 for easy, 2 for medium, 3 for hard): ";
        std::cin >> difficultyLevel;

        // Prompt the player for their choice
        std::cout << "Enter your choice (0 for rock, 1 for paper, 2 for scissors, 3 for lizard, 4 for Spock): ";
        std::cin >> playerChoice;

        // Generate computer's choice
        if (difficultyLevel == 1) {
            computerChoice = rand() % 5;
        } else if (difficultyLevel == 2) {
            std::this_thread::sleep_for(1s); // Add a delay to simulate thinking time
            computerChoice = rand() % 5;
        } else {
            if (playerScore > computerScore) {
                // Computer tries to predict the player's next move based on their previous choices
                if (playerChoice == 0) {
                    computerChoice = 1;
                } else if (playerChoice == 1) {
                    computerChoice = 2;
                } else if (playerChoice == 2) {
                    computerChoice = 3;
                } else if (playerChoice == 3) {
                    computerChoice = 4;
                } else {
                    computerChoice = 0;
                }
            } else {
                computerChoice = rand() % 5;
            }
        }

        // Compare choices and determine the winner
        if (playerChoice == computerChoice) {
            std::cout << "It's a tie!" << std::endl;
        } else if ((playerChoice == 0 && (computerChoice == 2 || computerChoice == 3)) ||
                   (playerChoice == 1 && (computerChoice == 0 || computerChoice == 4)) ||
                   (playerChoice == 2 && (computerChoice == 1 || computerChoice == 3)) ||
                   (playerChoice == 3 && (computerChoice == 1 || computerChoice == 4)) ||
                   (playerChoice == 4 && (computerChoice == 0 || computerChoice == 2))) {
            std::cout << "You win!" << std::endl;
            playerScore++;
        } else {
            std::cout << "Computer wins!" << std::endl;
            computerScore++;
        }

        // Display scores
        std::cout << "Player score: " << playerScore << std::endl;
        std::cout << "Computer score: " << computerScore << std::endl;

        // Ask if the player wants to play again
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thank you for playing! Goodbye!" << std::endl;

    return 0;
}
