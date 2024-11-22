#include <bits/stdc++.h>
using namespace std;
#define n 4
#define big 999999
void print(int Path[][n]);
int counter = 0;
void floyd(int Path[][n])
{
    for (int k = 0; k < n; k++)
    {
        cout<<" 1 . here we choose the D (" << k << ")" << endl;
        for (int i = 0; i < n; i++)
        {
             

            for (int j = 0; j < n; j++)
            {
                cout<< "2 . in here we choose the "<< j << " to compare with " << i << endl; 
                counter ++;
                if (Path[i][j] > (Path[i][k] + Path[k][j]) && (Path[k][j] != big && Path[i][k] != big))
                    Path[i][j] = Path[i][k] + Path[k][j];
            }
        }
    }
    cout<<"The complexity is O(n^3) and now we have "<< counter << " compare from "<< n << endl;
    print(Path);
}

void print(int Path[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Path[i][j] == big)
                cout << "big"
                     << " ";

            else
                cout << Path[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{

    int Graph[n][n] = {
        {0, 5, big, big},
        {50, 0, 15, 5},
        {30, big, 0, 15},
        {15, big, 5, 0}};

    floyd(Graph);
}