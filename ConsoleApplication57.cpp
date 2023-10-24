#include <iostream>
#include <thread>

void displayLetters(int a, int b)
{
    std::string alphabet = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
    for (int i = a - 1; i < b; i++)
    {
        std::cout << alphabet[i] << " ";
    }
}

int main()
{
    system("chcp 1251>null");
    int first = 0, last = 0;
    while (first <= 0 || first > 33 || last <= 0 || last > 33)
    {
        std::cout << "Введіть діапазон літер:" << std::endl;
        std::cout << "Нижня межа:" << std::endl;
        std::cin >> first;
        std::cout << "Верхня межа:" << std::endl;
        std::cin >> last;
        if (first <= 0 || first > 33)
        {
            std::cout << "ERROR. Ви ввели недопустиму верхню межу!" << std::endl;
        }
        if (last <= 0 || last > 33)
        {
            std::cout << "ERROR. Ви ввели недопустиму нижню межу!" << std::endl;
        }
    }
    std::thread t(displayLetters, first, last);
    t.join();
    
    std::cout << std::endl << "Головний потік закінчив виконання" << std::endl;

}