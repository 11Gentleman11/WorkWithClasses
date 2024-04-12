// WorkWithClasses.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
#include <iostream>
#include "header.h"
#include<ctime>
#include <stdlib.h>
using namespace std;
class card
{
protected:
    int amount;


};

class comcard : private card
{
    int money;
public:
    comcard()
    {
        amount = 0;
        money = 0;
    }
    comcard(int amount, int
        money) {
        this->amount = amount;
        this->money = money;
    }
    ~comcard() {}

    void SetM(int money)
    {
        this->money = money;
    }
    int GetM() { return money; }
    void SetAM(int amount)
    {
        this->amount = amount;
    }
    int GetAM()
    {
        return amount;
    }

    friend int countcom(const comcard& arr);
};
int countcom(const comcard& arr)
{
    setlocale(LC_ALL, "Rus");
    int cc = 0;
    if (arr.amount == 0)
    {
        cout << "\nКарта этого типа имеет: " << arr.money << " денег на счету";
        cc++;
    }
    return cc;
}

class lgcard :public card
{
    string lgtype;
public:
    lgcard()
    {
        lgtype = "";
        amount = 0;
    }
    lgcard(string lgtype, int amount)
    {
        this->lgtype = lgtype;
        this->amount = amount;
    }
    ~lgcard() {}
    string GetT() { return lgtype; }
    void SetT(string lgtype)
    {
        this->lgtype = lgtype;
    }
    int GetAm()
    {
        return amount;
    }
    void SetAM(int amount)
    {
        this->amount = amount;
    }
    friend int countlg(lgcard& arr);
};
int countlg(lgcard& arr)
{
    setlocale(LC_ALL, "Rus");
    int cc = 0;
    if (arr.amount == 0)
    {
        if (arr.lgtype == "1")
        {
            cout << "\nКарта студента не имеет поездок";
        }
        else { cout << "\nКарта пенсионера не имеет поездок"; }
        cc++;
    }
    return cc;
}
int task2(int size)
{
    int cc = 0;
    comcard a; lgcard b;
    lgcard* arr2 = new lgcard[size];
    comcard* arr1 = new comcard[size];

    for (int i = 0; i < size; i++)
    {
        arr1[i].SetAM(randomm());
        arr1[i].SetM(110);
    }

    for (int i = 0; i < size; i++)
    {
        arr2[i].SetAM(randomm());
        arr2[i].SetT("Инвалид");
    }

    for (int i = 0; i < size; i++)
    {
        cc += summa(arr1[i].GetAM());
    }

    for (int i = 0; i < size; i++)
    {
        cc += summa(arr2[i].GetAm());
    }
    delete[]arr1;
    delete[]arr2;

    return cc;
}

int task1()
{
    setlocale(LC_ALL, "Rus");
    int length = 2;
    int cc = 0;
    comcard* arr2 = new comcard[length];
    lgcard* arr1 = new lgcard[length];
    string lgtype; int amount; int money;
    cout << "\n(1 - студенческая карта. 2 - Пенсионная карта)";
    for (int i = 0; i < length; i++)
    {
        cout << "\nВведите тип льготной карты: ";
        cin >> lgtype; cout << "\nВведите количество поездок для данной карты: "; cin >> amount;
        arr1[i] = lgcard(lgtype, amount);
        cc += countlg(arr1[i]);
    }
    for (int i = 0; i < length; i++)
    {
        cout << "\nВведите количество денег для карты общего пользования: ";
        cin >> money; cout << "\nВведите количество поездок для данной карты: "; cin >> amount;
        arr2[i] = comcard(amount, money);
        cc += countcom(arr2[i]);
    }
    return cc;
}
void main()
{
    cout << "Количество карт без поездок: " << task1();
    cout << "\nКоличество карт без поездок(из другого файла): " << task2(5);
    while (true)
    {
        int choice;
        cout << "\n\nМеню:" << endl;
        cout << "1. Вывод карт без поездок(наследуемое) " << endl;
        cout << "2. Вывод карт без поездок(из другого файла) " << endl;
        cout << "3. Завершить программу " << endl;

        cout << "\nВведите свой выбор: ";
        cin >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Ошибка! Введите ЧИСЛО согласно номеру в меню: ";
            cin >> choice;
        }

        switch (choice)
        {
        case(1): {cout << "Количество карт без поездок: " << task1(); break; }
        case(2): {cout << "\nКоличество карт без поездок(из другого файла): " << task2(5); break; }
        case(3): {exit(0); }
        }
    }
    setlocale(LC_ALL, "Rus");

}
Header.h:
#include <random>
#include <iostream>
using namespace std;

int summa(int a)
{
    int c = 0;
    if (a == 0)
    {
        c++;
    }
    return c;
}

int randomm()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 5);

    return dist(gen);
}
