#include <iostream>
#include <locale.h>
using namespace std;
const int n = 3; //дл€ задачи 1
//const int n = 4; //дл€ задачи 2
int main()
{
    setlocale(LC_ALL,"");
    float a[n][n+1]={{2,3,4,17},{4,1,1,15},{1,4,3,13}}; //матрица дл€ задачи 1
    //float a[n][n+1]={{-1,0,0,-1,-9.8},{1,-1,0,-1,0.098},{0,1,-1,-1,0.098},{0,0,1,-1,0.098}}; //матрица дл€ задачи 2
    float aid,aii;
    int i,j,d;

    cout.setf(ios::left);
    cout << "¬аша матрица:\n";
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

    cout << "Ќайденные значени€ (по пор€дку):\n";
    for (i=0;i<n;i++)
        cout << "x[" << i + 1 << "] = " << a[i][n] << endl;
    cin.get();
    return 0;
}
