#include <iostream>
#include <ctime>
using namespace std;

void gameOutput(char** field) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

int winCheck(char** field, char symbol) {
    if (field[0][0] == field[0][1] && field[0][0] == field[0][2] && field[0][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return 1;
    }
    else if (field[1][0] == field[1][1] && field[1][0] == field[1][2] && field[1][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return 1;
    }
    else if (field[2][0] == field[2][1] && field[2][0] == field[2][2] && field[2][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return 1;
    }
    else if (field[0][0] == field[1][0] && field[0][0] == field[2][0] && field[0][0] != '+') {
        cout << "Winner is: " << symbol << endl;
        return 1;
    }
    else if (field[0][1] == field[1][1] && field[0][1] == field[2][1] && field[0][1] != '+') {
        cout << "Winner is: " << symbol << endl;
        return 1;
    }
    else if (field[0][2] == field[1][2] && field[0][2] == field[2][2] && field[0][2] != '+') {
        cout << "Winner is: " << symbol << endl;
        return 1;
    }
    else if (field[0][0] == field[1][1] && field[0][0] == field[2][2] && field[1][1] != '+') {
        cout << "Winner is: " << symbol << endl;
        return 1;
    }
    else if (field[0][2] == field[1][1] && field[0][2] == field[2][0] && field[1][1] != '+') {
        cout << "Winner is: " << symbol << endl;
        return 1;
    }
}

int checkingDraw(int amountOfFreePlaces) {
    if (amountOfFreePlaces > 0) {
        return 0;
    }
    else {
        cout << "Draw" << endl;
        return 1;
    }
}

char** selectionOutputPlayer(char** field, char symbol) {
    int x, y;
    cout << "Enter a row of place: ";
    cin >> x;
    cout << endl << "Enter a column of place: ";
    cin >> y;

    while (field[x][y] != '+') {
        cout << "Enter a row of place: ";
        cin >> x;
        cout << endl << "Enter a column of place: ";
        cin >> y;
    }

    field[x][y] = symbol;
    return field;
}

char** selectionOutputBot(char** field, char symbol) {
    int x, y;
    srand(time(NULL));
    x = rand() % 3;
    y = rand() % 3;

    while (field[x][y] != '+') {
        srand(time(NULL));
        x = rand() % 3;
        y = rand() % 3;
    }

    field[x][y] = symbol;
    return field;
}

void main()
{
    char** field = new char* [3];

    for (int i = 0; i < 3; i++) {
        field[i] = new char[3];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            field[i][j] = '+';
        }
    }

    int character;
    char charCharacter;
    int error;
    do {
        cout << "Choose your character X or O pls: ";
        cin >> charCharacter;
        if (charCharacter == 'X' || charCharacter == 'x') {
            character = 1;
            error = 1;
        }
        else if (charCharacter == 'O' || charCharacter == '0' || charCharacter == 'o') {
            character = 2;
            error = 1;
        }
        else {
            error = 0;
        }
    } while (error == 0);

    bool isGameOver = false;
    char symbol = 'X';
    int countOfSteps = 1;
    int amountOfFreePlaces = 9;

    while (!isGameOver) {
        if (character == 2) {
            if (countOfSteps % 2 == 0) {
                symbol = 'O';
                selectionOutputPlayer(field, symbol);
            }
            else {
                symbol = 'X';
                cout << "Bot Step: " << endl;
                selectionOutputBot(field, symbol);
            }
        }
        if (character == 1) {
            if (countOfSteps % 2 == 0) {
                symbol = 'O';
                cout << "Bot Step: " << endl;
                selectionOutputBot(field, symbol);
            }
            else {
                symbol = 'X';
                selectionOutputPlayer(field, symbol);
            }
        }

        countOfSteps++;
        gameOutput(field);
        amountOfFreePlaces--;
        if (winCheck(field, symbol) == 1) {
            break;
        }
        if (checkingDraw(amountOfFreePlaces) == 0) {
            continue;
        }
        if (checkingDraw(amountOfFreePlaces) == 1) {
            break;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete[] field[i];
    }

    delete[] field;
    field = nullptr;
}

