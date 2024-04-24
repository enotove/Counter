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
        std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
        std::cin >> answer;
        if ( (answer == "��") || (answer == "��"))
        {         
            while(flag)
            {
                std::cout << "������� ��������� �������� ��������: ";
                while (!(std::cin >> a))
                {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "������������ ����. ���������.\n";
                    std::cout << "������� ��������� �������� ��������: ";
                }
                
                if (a > 0)
                {
                    flag = false;
                }
                else
                {
                    std::cout << "������������ ����. ���������.\n";
                }
                
            };
        }
        else if ((answer == "���") || (answer == "���"))
        {
            flag = false;    
        }
        else
        {
            std::cout << "�������� ����!" << std::endl;
        }
        
    }
    Counter counter = a != 0 ? Counter(a) : Counter();
    flag = true;
    while (flag)
    {
        char b;
        std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
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
            std::cout << "�� ��������!";
            flag = false;
            break;
        default:
            std::cout << "�������� ����!" << std::endl;
            break;
        }

    }
    return 0;
}
