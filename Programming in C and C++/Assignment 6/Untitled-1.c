/*CH-230-A
a6_p6.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>

int main()
{

    int k, n, x, p, y = 1;
    std::cin >> n >> x;
    k = n, p = x;
    while (k > 0)
    {
        if (k % 2 == 0)
        {
            p *= p;
            k /= 2;
        }
        else
        {
            y *= p;
            k--;
        }
        std::cout << "y: " << y << " p: " << p << "\n";
    }
    P(i) is true if and only if x∗ai == αn
    \ return 0;
}