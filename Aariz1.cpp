#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

map<string, int> leaderboard;

void playGame() {
    string name;
    cout << "Enter your Name: ";
    cin >> name;

    int minNum, maxNum;
    cout << "Enter the minimum number: ";
    cin >> minNum;
    cout << "Enter the maximum number: ";
    cin >> maxNum;

    int randomNumber = rand() % (maxNum - minNum + 1) + minNum;
    cout << "┌───────────────────────────────────────────┐" << endl;
    cout << "│ Let's Play Guess a Number... │" << endl;
    cout << "└───────────────────────────────────────────┘" << endl;
    cout << "The number is between " << minNum << " and " << maxNum << "." << endl;

    bool win = false;
    int guess, attempts = 0;
    const int maxAttempts = 10;
    while (!win && attempts < maxAttempts) {
        cout << "Guess a Number: ";
        cin >> guess;
        attempts++;

        if (guess == randomNumber) {
            cout << "Congratulations! You guessed the number in " << attempts << " tries." << endl;
            win = true;
            leaderboard[name]++;
        } else if (guess < randomNumber) {
            cout << "Too low. Guess again." << endl;
        } else {
            cout << "Too high. Guess again." << endl;
        }
    }

    if (!win) {
        cout << "You failed the game. The correct number was " << randomNumber << "." << endl;
    }
}

void displayLeaderboard() {
    cout << "\nLeaderboard:\n";
    cout << "Name\tScore\n";
    cout << "-------------------\n";
    for (auto& [name, score] : leaderboard) {
        cout << name << "\t" << score << endl;
    }
    cout << "-------------------\n";
}

void displayMenu() {
    int choice;
    do {
        cout << "\nOptions:\n"
             << "1. Play\n"
             << "2. View Leaderboard\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                displayLeaderboard();
                break;
            case 3:
                cout << "Thanks for playing. See you soon!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);
}

int main() {
    displayMenu();
    return 0;
}
