#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    const int width = 20;
    const int height = 10;
    int x_position = 0;
    int y_position = 0;
    bool movingRight = true;
    bool movingDown = true;

    int colorIndex = 0;

    while (true) {

        SetConsoleCursorPosition(hConsole, { static_cast<SHORT>(x_position), static_cast<SHORT>(y_position) });
        cout << " ";
        SetConsoleTextAttribute(hConsole, colorIndex);

        if (movingRight) {
            x_position++;
            if (x_position >= width) {
                movingRight = false;
                x_position = width - 1;
                y_position++;
                colorIndex = (colorIndex + 1) % 16;
            }
        }
        else {
            x_position--;
            if (x_position < 0) {
                y_position++;
                movingRight = true;
                x_position = 0;
                colorIndex = (colorIndex + 1) % 16;
            }
        }

        if (movingDown) {
            if (y_position >= height) {
                movingDown = false;
                y_position = height - 1;
            }
        }
        else {
            y_position = 0;
            x_position = 0;
            movingDown = true;
            movingRight = true;
        }

        SetConsoleCursorPosition(hConsole, { static_cast<SHORT>(x_position), static_cast<SHORT>(y_position) });
        cout << "%";
        Sleep(10);
    }

    return 0;
}
