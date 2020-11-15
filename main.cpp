#include <iostream>
#include <windows.h>
#include <algorithm>
using namespace std;

void printMatrix(char matrix[]);

int main() {

    cout << "*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*" << endl;
    cout << " Welcome to the MatrixLottery!"  << endl;
    cout << "*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*" << endl;

    string userInput = "";
    while (userInput != "p") {
        cout << "\nPress P to Pull the Lever" << endl;
        cin >> userInput;
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
    }

    system("CLS");

    //creates the matrix (character array) and fills it with O's
    char matrix[100];
    for (int i = 0; i < 100; i++) {
        matrix[i] = 'O';
    }

    //three random O's turn into X's
    int x1 = rand() % 100;
    int x2 = rand() % 100;
    int x3 = rand() % 100;
    int x4 = rand() % 100;
    int x5 = rand() % 100;

    matrix[x1] = 'X';
    matrix[x2] = 'X';
    matrix[x3] = 'X';
    matrix[x4] = 'X';
    matrix[x5] = 'X';

    //how far the @ cursor will travel, between 80 to 200 squares
    int launchDistance = rand() % 200 + 80;
    //here is a line of code to help debugging (it guarantees a win)
    //int launchDistance = x2;
    
    //modulo operation to get a 0-99 index from the launchDistance
    int finalIndex = launchDistance % 100;

    bool continueLoop = true;
    int distanceRemaining = launchDistance;
    
    for (int cursorIndex = 0; distanceRemaining >= 0; cursorIndex++) {

        if (cursorIndex == 100) {
            cursorIndex = 0;
        }

        //animation slows down as you approach your last square
        if (distanceRemaining < 10) {
            Sleep(300);
        } else {
            Sleep(50);
        }

        //placeholder
        char currentChar = matrix[cursorIndex];
        matrix[cursorIndex] = 'M';

        printMatrix(matrix);

        matrix[cursorIndex] = currentChar;
        distanceRemaining--;

        cout << "\n";

    }
    
    if (finalIndex == x1 || finalIndex == x2 || finalIndex == x3 ||
        finalIndex == x4 || finalIndex == x5) {

        cout << "Congratulations! You won (nothing)!" << endl;
    } else {

        cout << "Sorry, you did not win.";
    }

    return 0;
}

void printMatrix(char matrix[]) {

    for (int i = 0; i < 100; i++) {

        cout << matrix[i] << "  ";

        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << "\n\n\n";
}