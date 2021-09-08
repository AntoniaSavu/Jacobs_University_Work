/*CH-230-A
a4_p7.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
/*void matrixform(int n, int a[n][n])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);

        printf("\n");
    }
}
void underdiagonal(int n, int a[n][n])
{
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            printf("%d ", a[i][j]);
}
*/
#include <iostream>
using namespace std;

int a[20][20], n;
void citire()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}
void matrixform()
{
    cout << "The entered matrix:" << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}
void underdiagonal()
{
    cout << "Under the main diagonal:" << '\n';
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            cout << a[i][j] << ' ';
}
int main()
{

    citire();
    matrixform();
    underdiagonal();
    return 0;
}