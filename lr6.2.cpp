#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;
const float k=0.000436, m0=2, t_last=4500; //������ ��� ������ 2
//const float k=0.0168, V0=12, S_last=150; //������ ��� ������ 3
int main()
{
    setlocale(LC_ALL,"");
    //���������� ��� ������ 2:
    int t=0;
    float m;
    //���������� ��� ������ 3:
    //int S=0;
    //float V;
    //���������� ����� ��� ������ 2:
    cout << "|   t   |   m    |\n";
    cout << "|-------|--------|\n";
    //���������� ����� ��� ������ 3:
    //cout << "|   S   |   V    |\n";
    //cout << "|-------|--------|\n";
    cout.precision(3);
    do
    {
        m=m0*exp(-k*t); //������� ��� ������ 2
        //V=V0*exp(-k*S); //������� ��� ������ 3
        cout << "|  ";
        cout.width(4);
        cout << left << t << " | "; //��� ������ 2
        //cout << left << S << " | "; //��� ������ 3
        cout.width(6);
        cout << fixed << m << " |\n"; //��� ������ 2
        t += 300; //��� ������ 2
        //cout << fixed << V << " |\n"; //��� ������ 3
        //S += 10; //��� ������ 3
    }
    while(t<=t_last); //������� ��� ������ 2
    //while(S<=S_last); //������� ��� ������ 3
    cout << " ------- --------\n";
    cin.get();
    return 0;
}
