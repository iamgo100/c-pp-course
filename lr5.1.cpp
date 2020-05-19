#include <iostream>
#include <locale.h>
using namespace std;
const int n = 4;
int main()
{
    setlocale(LC_ALL,"");
    float a[n][n+1]={{5,7,6,5,23},{7,10,8,7,32},{6,8,10,9,33},{5,7,9,10,31}};
    float x[n]={0};
    float ak,s=0;
    int i,j,k;
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
    for (i=0;i<n;i++)
        for (k=i+1;k<n;k++)
        {
            ak=a[k][i]/a[i][i];
            for (j=i;j<n+1;j++)
                a[k][j]=a[k][j]-ak*a[i][j];
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
    for (i=n-1;i>=0;i--)
    {
        s=0;
        for (j=i+1;j<n;j++)
            s+=a[i][j]*x[j];
        x[i]=(a[i][n]-s)/a[i][i];
    }
    cout << "Найденные X:\n";
    for (i=0;i<n;i++)
        cout << "x[" << i << "] = " << x[i] << endl;
    cin.get();
    return 0;
}
