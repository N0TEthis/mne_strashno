/* задача 6 аххх */
#include <iostream>
#include <vector>

using namespace std;

// Названия направлений для вывода лога 
string dirNames[] = {"Вправо", "Вниз", "Влево", "Вверх"};

int main() {
    // Размер доски 
    const int SIZE = 4;
    
    int board[SIZE][SIZE] = {0};
      // Закрашенные клетки 
    board[1][1] = 1; 
    board[2][2] = 1; 
    board[3][2] = 1; 

   // Точка где стоит Робот 
    int x = 0; // Столбец A
    int y = 2; // Строка 2 
    int dir = 0; 

    // Движение вперед 
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    cout << "Робот начинает в A2, идет в сторону B2" << endl;

    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // Проверка
        bool canGoStraight = (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[ny][nx] == 0);

        if (canGoStraight) {
            x = nx;
            y = ny;
            cout << "Шаг вперед в клетку: " << (char)('A' + x) << (4 - y) << endl;
        } else {
            // Препятствие
            cout << "Препятствие! Поворот направо." << endl;
            dir = (dir + 1) % 4;

            // Проверяем, можно ли идти после поворота
            int rx = x + dx[dir];
            int ry = y + dy[dir];
            bool canGoAfterTurn = (rx >= 0 && rx < SIZE && ry >= 0 && ry < SIZE && board[ry][rx] == 0);

            if (!canGoAfterTurn) {
                // Если и после поворота нельзя идти — остановка
                cout << "Движение невозможно ни вперед, ни вправо." << endl;
                break;
            }
            // Если можно, то на следующей итерации цикла он пойдет в новом направлении
        }
    }

    cout << "---------------------------" << endl;
    cout << "ИТОГ: Робот остановился в " << (char)('A' + x) << (4 - y) << endl;

    return 0;
}
