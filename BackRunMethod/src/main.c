#include <iostream>
#include <iomanip>
using namespace std;

void Print(int** A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << setw(4) << A[i][j];
        cout << endl;
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");
    const int size = 7;
    const int inf = 100;
    int C[size][size] =
    {
        { 0,   7,   8,   5,   inf, inf, inf},
        { inf, 0,   inf, inf, 12,  inf, inf},
        { inf, inf, 0,   inf, 8,   9,   inf},
        { inf, inf, inf, 0,   7,   13,  inf},
        { inf, inf, inf, inf, 0,   inf, 9  },
        { inf, inf, inf, inf, inf, 0,   6  },
        { inf, inf, inf, inf, inf, inf, 0  }
    };

    int **D = new int*[size];
    for (int i = 0; i < size; i++)
        D[i] = new int[size];
    for (int i = 0; i < size; i++)  //формирование D0
        for (int j = i; j < size; j++) {
            D[i][j] = C[i][j];
            D[j][i] = C[i][j];
        }
    int **P = new int*[size];
    for (int i = 0; i < size; i++)
        P[i] = new int[size];

    for (int i = 0; i < size; i++)  //формирование P0
        for (int j = i; j < size; j++)
        {
            if ((D[i][j] == 0) || (D[i][j] == inf))
                P[i][j] = 0;
            else
                P[i][j] = i + 1;
            P[j][i] = P[i][j];
        }
    cout << "Матрица D0" << endl;
    Print(D, size);
    cout << "Матрица P0" << endl;
    Print(P, size);

    for (int m = 0; m < size; m++)
    {
        for (int i = 0; i < size; i++)
            if ((i != m) || (D[i][m] != inf))
            {
                for (int j = i; j < size; j++)
                    if (D[i][j] > D[i][m] + D[m][j])
                    {
                        D[i][j] = D[i][m] + D[m][j];
                        D[j][i] = D[i][j];
                        P[j][i] = P[m][j];
                        P[i][j] = P[j][m];
                    }
            }
        // cout << "Матрица D" << m + 1 << endl;
        // Print(D, size);
        // cout << "Матрица P" << m + 1 << endl;
        // Print(P, size);
    }
    cout << endl;
    cout << "D" << endl;
    Print(D, size);
    cout << "P" << endl;
    Print(P, size);
    cout << endl;
    int start = argc > 1 ? atoi(argv[1]) - 1 : 0;
    int end = argc > 2 ? atoi(argv[2]) - 1 : 6;
    cout << "Кратчайший путь из вершины "<< start + 1 <<" в вершину " << end + 1<< ":" << endl;
    int i = P[end][start]; 
    cout << end + 1;
    while (1)
    {
        cout << " " << i;
        i = P[i][start] - 1;
        if (i==start) break;
        if (i==0) break;
    }
    cout << " = " << D[end][start];
    cout << endl;
}
