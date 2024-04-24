#include <iostream>
#include <string>
#include <Windows.h>


class Counter
{
public:
    Counter()
    {
        this->counter = 1;
    }
    Counter(int counter)
    {
        this->counter = counter;
    }
    void counterAdd() { this->counter += 1; }
    void counterSub() { this->counter -= this->counter > 0 ? 1 : 0; }
    void counterPrint() { std::cout << "Counter: " << this->counter << '\n'; }
private:
    int counter = 0;

};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");
    std::string answer;
    int a = 0;
    bool flag = true;
    while (flag)
    {
        std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> answer;
        if ( (answer == "Да") || (answer == "да"))
        {         
            while(flag)
            {
                std::cout << "Введите начальное значение счётчика: ";
                while (!(std::cin >> a))
                {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Неправильный ввод. Повторите.\n";
                    std::cout << "Введите начальное значение счётчика: ";
                }
                
                if (a > 0)
                {
                    flag = false;
                }
                else
                {
                    std::cout << "Неправильный ввод. Повторите.\n";
                }
                
            };
        }
        else if ((answer == "Нет") || (answer == "нет"))
        {
            flag = false;    
        }
        else
        {
            std::cout << "Неверный ввод!" << std::endl;
        }
        
    }
    Counter counter = a != 0 ? Counter(a) : Counter();
    flag = true;
    while (flag)
    {
        char b;
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> b;
        switch (b)
        {
        case '+':
            counter.counterAdd();
            break;
        case '-':
            counter.counterSub();
            break;
        case '=':
            counter.counterPrint();
            break;
        case 'x':
            std::cout << "До свидания!";
            flag = false;
            break;
        default:
            std::cout << "Неверный ввод!" << std::endl;
            break;
        }

    }
    return 0;
}
