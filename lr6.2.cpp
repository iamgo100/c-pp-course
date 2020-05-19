#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;
const float k=0.000436, m0=2, t_last=4500; //Данные для задачи 2
//const float k=0.0168, V0=12, S_last=150; //Данные для задачи 3
int main()
{
    setlocale(LC_ALL,"");
    //Переменные для задачи 2:
    int t=0;
    float m;
    //Переменные для задачи 3:
    //int S=0;
    //float V;
    //Оформление шапки для задачи 2:
    cout << "|   t   |   m    |\n";
    cout << "|-------|--------|\n";
    //Оформление шапки для задачи 3:
    //cout << "|   S   |   V    |\n";
    //cout << "|-------|--------|\n";
    cout.precision(3);
    do
    {
        m=m0*exp(-k*t); //Формула для задачи 2
        //V=V0*exp(-k*S); //Формула для задачи 3
        cout << "|  ";
        cout.width(4);
        cout << left << t << " | "; //для задачи 2
        //cout << left << S << " | "; //для задачи 3
        cout.width(6);
        cout << fixed << m << " |\n"; //для задачи 2
        t += 300; //для задачи 2
        //cout << fixed << V << " |\n"; //для задачи 3
        //S += 10; //для задачи 3
    }
    while(t<=t_last); //Условие для задачи 2
    //while(S<=S_last); //Условие для задачи 3
    cout << " ------- --------\n";
    cin.get();
    return 0;
}
