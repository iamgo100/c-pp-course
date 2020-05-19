#include <iostream>
#include <locale.h>
using namespace std;
const int n = 4;
int main()
{
    setlocale(LC_ALL,"");
    float a[n][n+1]={{5,7,6,5,23},{7,10,8,7,32},{6,8,10,9,33},{5,7,9,10,31}};
    float aid,aii;
    int i,j,d;

    cout.setf(ios::left);
    cout << "Ваша матрица:\n";
    for (i=0;i<n;i++)
        {
            cout << "|";
            for (j=0;j<n;j++)
            {
                cout.width(5);
                cout << a[i][j] << "|";
            }
            cout << "|";
            cout.width(5);
            cout << a[i][n] << "|";
            cout << endl;
        }
    cout << endl;

    for (d=0;d<n;d++)
    {
        aii=a[d][d];
        if(aii!=1)
            for(j=d;j<n+1;j++)
                a[d][j]=a[d][j]/aii;
        for (i=0;i<n;i++)
        {
            aid=a[i][d];
            for (j=d;j<n+1;j++)
            {
                if (i==d) break;
                else a[i][j]=a[i][j]-aid*a[d][j];
            }
        }
    }

    cout << "Преобразованная матрица:\n";
    for (i=0;i<n;i++)
        {
            cout << "|";
            for (j=0;j<n;j++)
            {
                cout.width(5);
                cout.precision(1);
                cout << fixed << a[i][j];
                cout << "|";
            }
            cout << "|";
            cout.width(5);
            cout.precision(1);
            cout << fixed << a[i][n] << "|";
            cout << endl;
        }
    cout << endl;

    cout << "Найденные X:\n";
    for (i=0;i<n;i++)
        cout << "x[" << i << "] = " << a[i][n] << endl;
    cin.get();
    return 0;
}
