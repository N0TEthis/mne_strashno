#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
Проверка корректности системы счисления
@param n - система счисления
@return true если n корректно, иначе false
*/
bool check_n(int n) {
    bool flag = true;
    
    if (n == 2)  { flag = false; }
    if (n == 8)  { flag = false; }
    if (n == 10) { flag = false; }
    if (n == 16) { flag = false; }
    if (n > 30)  { flag = false; }
    if (n < 2)   { flag = false; }
    
    return flag;
}

/*
Преобразование числа в строку в заданной системе счисления
@param num - число для преобразования
@param base - система счисления
@return строковое представление числа
*/
string to_base_string(int num, int base) {
    if (num == 0) return "0";
    
    string result = "";
    bool negative = false;
    
    if (num < 0) {
        negative = true;
        num = -num;
    }
    
    while (num > 0) {
        int remainder = num % base;
        if (remainder < 10) {
            result = char('0' + remainder) + result;
        } else {
            result = char('A' + remainder - 10) + result;
        }
        num /= base;
    }
    
    if (negative) {
        result = "-" + result;
    }
    
    return result;
}

/*
Вывод таблицы умножения в заданной системе счисления
@param base - система счисления
*/
void print_multiplication_table(int base) {
    const int SIZE = base - 1; // Умножаем от 1 до base-1
    int max_width = 0;
    
    // Определяем максимальную ширину для выравнивания
    int max_product = (base - 1) * (base - 1);
    string max_product_str = to_base_string(max_product, base);
    max_width = max_product_str.length() + 1;
    
    // Вывод заголовка
    cout << "\nТаблица умножения в " << base << "-чной системе счисления:\n\n";
    
    // Вывод заголовков столбцов
    cout << setw(max_width) << "×";
    for (int i = 1; i <= SIZE; i++) {
        cout << setw(max_width) << to_base_string(i, base);
    }
    cout << "\n";
    
    // Вывод разделительной линии
    cout << string((SIZE + 1) * max_width, '-') << "\n";
    
    // Вывод самой таблицы умножения
    for (int i = 1; i <= SIZE; i++) {
        // Вывод заголовка строки
        cout << setw(max_width) << to_base_string(i, base) << "|";
        
        // Вывод значений умножения
        for (int j = 1; j <= SIZE; j++) {
            int product = i * j;
            cout << setw(max_width) << to_base_string(product, base);
        }
        cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    // Вывод информации об аргументах командной строки
    cout << "Количество аргументов: " << argc << endl;
    for (int i = 0; i < argc; ++i) {
        cout << "Аргумент " << i << ": " << argv[i] << endl;
    }
    
    setlocale(LC_ALL, "RU");
    
    int n; // Система счисления
    cout << "\nВведите систему счисления (3 ≤ n ≤ 30, n ≠ 2,8,10,16): ";
    cin >> n;
    
    if (check_n(n)) {
        print_multiplication_table(n);
    } 
    else { 
        cerr << "Ошибка: n некорректно! \n";
        cerr << "Допустимые значения: 3-30, кроме 2, 8, 10, 16\n";
    }
    
    return 0;
}