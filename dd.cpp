/* задача 6 аххх */
#include <iostream>
#include <vector>

using namespace std;

// Названия направлений для вывода лога 
string dirNames[] = {"Вправо", "Вниз", "Влево", "Вверх"};

// Функция для отображения доски
void showBoard(int board[4][4], int robotX, int robotY) {
    cout << "\n  Текущее состояние:" << endl;
    cout << "  | A B C D |" << endl;
    cout << "--+---------+" << endl;
    
    for (int row = 0; row < 4; row++) {
        cout << (4 - row) << " | ";
        for (int col = 0; col < 4; col++) {
            if (col == robotX && row == robotY) {
                cout << "R "; // Робот
            } else if (board[row][col] == 1) {
                cout << "■ "; // Закрашенная клетка
            } else {
                cout << "· "; // Пустая клетка
            }
        }
        cout << "|" << endl;
    }
    cout << "--+---------+" << endl;
}

int main() {
    // Размер доски 
    const int SIZE = 4;
    
    int board[SIZE][SIZE] = {0};
    // Закрашенные клетки 
    board[1][1] = 1; // B3
    board[2][2] = 1; // C2
    board[3][2] = 1; // D2

    // Точка где стоит Робот 
    int x = 0; // Столбец A
    int y = 2; // Строка 3 
    int dir = 0; 

    // Движение вперед 
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    cout << "Робот начинает в A3, идет в сторону B3" << endl;
    showBoard(board, x, y);

    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // Проверка
        bool canGoStraight = (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[ny][nx] == 0);

        if (canGoStraight) {
            x = nx;
            y = ny;
            cout << "\nШаг вперед в клетку: " << (char)('A' + x) << (4 - y) << endl;
            showBoard(board, x, y);
        } else {
            // Препятствие
            cout << "\nПрепятствие! Поворот направо." << endl;
            dir = (dir + 1) % 4;

            // Проверяем, можно ли идти после поворота
            int rx = x + dx[dir];
            int ry = y + dy[dir];
            bool canGoAfterTurn = (rx >= 0 && rx < SIZE && ry >= 0 && ry < SIZE && board[ry][rx] == 0);

            if (!canGoAfterTurn) {
                // Если и после поворота нельзя идти — остановка
                cout << "\nДвижение невозможно ни вперед, ни вправо." << endl;
                showBoard(board, x, y);
                break;
            }
            // Если можно, то на следующей итерации цикла он пойдет в новом направлении
        }
    }

    cout << "---------------------------" << endl;
    cout << "ИТОГ: Робот остановился в " << (char)('A' + x) << (4 - y) << endl;
    showBoard(board, x, y);

    return 0;
}