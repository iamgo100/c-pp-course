#include <iostream>
#include <locale.h>
using namespace std;
const int n = 4;
int main()
{
    setlocale(LC_ALL,"");
    float a[n][n+1]={{5,7,6,5,23},{7,10,8,7,32},{6,8,10,9,33},{5,7,9,10,31}};
    float x[n]={0};
    float aii,aid,s=0;
    int i,j,d;
    cout.setf(ios::left);
    cout << "Ваша матрица:\n";
    for (i=0;i<n;i++)
        {
            cout << "|";
            for (j=0;j<n;j++)
            {
                cout.width(3);
                cout << a[i][j];
            }
            cout << "|";
            cout.width(2);
            cout << a[i][n] << "|";
            cout << endl;
        }
    cout << endl;
    for (d=0;d<n;d++)
    {
        aii=a[d][d];
        for (i=d;i<n;i++)
        {
            aid=a[i][d];
            for (j=d;j<n+1;j++)
            {
                if (i==d) a[i][j]=a[i][j]/aii;
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
            }
            cout << "|";
            cout.width(4);
            cout.precision(1);
            cout << fixed << a[i][n] << "|";
            cout << endl;
        }
    cout << endl;
    x[n-1]=a[n-1][n];
    for (i=n-2;i>=0;i--)
    {
        s=0;
        for (j=i+1;j<n;j++)
            s+=a[i][j]*x[j];
        x[i]=a[i][n]-s;
    }
    cout << "Найденные X:\n";
    for (i=0;i<n;i++)
        cout << "x[" << i << "] = " << x[i] << endl;
    cin.get();
    return 0;
}
