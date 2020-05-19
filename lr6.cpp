#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;
const float r=0.0373, Ts=22, T0=83;
int main()
{
    setlocale(LC_ALL,"");
    int t=0;
    float t1,T=54;
    t1=-1/r*log((T-Ts)/(T0-Ts));
    cout << "|  t  |   T   |\n";
    cout << "|-----|-------|\n";
    cout.precision(2);
    do
    {
        T=Ts-(Ts-T0)*exp(-r*t);
        cout << "|  ";
        cout.width(2);
        cout << left << t << " | ";
        cout.width(4);
        cout << fixed << T << " |\n";
        t++;
    }
    while(t<t1);
    cin.get();
    return 0;
}
