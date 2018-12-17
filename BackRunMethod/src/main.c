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

int main()
{
    setlocale(LC_ALL, "Rus");
    const int size = 7;
    const int inf = 100;
    int C[size][size] =
    {
        { inf,   7,   8,   5,   inf, inf, inf},
        { inf, inf,   inf, inf, 12,  inf, inf},
        { inf, inf, inf,   inf, 8,   9,   inf},
        { inf, inf, inf, inf,   7,   13,  inf},
        { inf, inf, inf, inf, inf,   inf, 9  },
        { inf, inf, inf, inf, inf, inf,   6  },
        { inf, inf, inf, inf, inf, inf, inf  }
    };

    int **D = new int*[size];
    for (int i = 0; i < size; i++)
        D[i] = new int[size];
    for (int i = 0; i < size; i++)  //формирование D0
        for (int j = 0; j < size; j++)
            D[i][j] = C[i][j];
    int **P = new int*[size];
    for (int i = 0; i < size; i++)
        P[i] = new int[size];

    for (int i = 0; i < size; i++)  //формирование P0
        for (int j = 0; j < size; j++)
        {
            if ((D[i][j] == 0) || (D[i][j] == inf))
                P[i][j] = 0;
            else
                P[i][j] = i + 1;
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
                for (int j = 0; j < size; j++)
                    if (D[i][j]>D[i][m] + D[m][j])
                    {
                        D[i][j] = D[i][m] + D[m][j];
                        P[i][j] = P[m][j];
                    }
            }
        // cout << "Матрица D" << m + 1 << endl;
        // Print(D, size);
        // cout << "Матрица P" << m + 1 << endl;
        // Print(P, size);
    }
    cout << "Кратчайший путь из вершины 1 в вершину 7:" << endl;
    cout << 7;
    int start = 0, end = 6;
    int i = P[start][end];
    while (1)
    {
        cout << " " << i;
        i = i - 1;
        i = P[start][i];
        if (i==start) break;
    }
    cout << endl;
}
