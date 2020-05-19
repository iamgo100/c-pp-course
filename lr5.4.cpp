#include <iostream>
#include <locale.h>
using namespace std;
const int n = 4;
int main()
{
    setlocale(LC_ALL,"");
    float a[n+1][n+1]={{5,7,6,5,23},{7,10,8,7,32},{6,8,10,9,33},{5,7,9,10,31},{1,2,3,4,5}};
    float x[n]={0};
    float aii,aid,s=0,m,t;
    int i,j,k,d,mj;

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

    for(d=0;d<n;d++)
    {
        if(d!=n-1)
        {
            //Находим максимальный элемент в строке
            m=a[d][d];
            for(j=d+1;j<n;j++)
                if(abs(a[d][j])>abs(m))
                {
                    mj=j;
                    m=a[d][j];
                }
        }
        if(mj!=d)
        {
            //Меняем столбцы
            for(i=0;i<n+1;i++)
            {
                t=a[i][mj];
                a[i][mj]=a[i][d];
                a[i][d]=t;
            }
        }
        //Ход метода
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
                cout << "|";
            }
            cout << "|";
            cout.width(5);
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
    {
        cout << "x[";
        cout.precision(0);
        cout << a[n][i] << "] = ";
        cout.precision(1);
        cout <<  x[i] << endl;
    }
    cin.get();
    return 0;
}
