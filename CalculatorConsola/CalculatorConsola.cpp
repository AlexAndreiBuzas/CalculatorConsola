#include "Read.h"
#include <iostream>
#include <math.h>

int main()
{
    Read read;
    char v[100], a[99];
    read.read(v, a);

    int temp = 1;
    int result = 0;
    int k = 0, i = 0, j = 0;
    bool loop = 1;
    char op = '+';

    do
    {
        std::cin >> temp;

        switch (op)
        {
        case '+':
        {
            a[j] = 1;
            i++;
            j++;
            k++;
            v[i] = temp;
            break;
        }
        case '-':
        {
            a[j] = 2;
            i++;
            j++;
            k++;
            v[i] = temp;
            break;
        }
        case '*':
        {
            v[i] *= temp;
            break;
        }
        case '/':
        {
            if (temp == 0)
                std::cout << "Error\n";
            else
                v[i] /= temp;
            break;
        }
        default:
        {
            std::cout << "Error\n";
            break;
        }
        }

        std::cin >> op;

        if (op == '=') loop = 0;
    }while (loop);

    result = v[0];
    i = 1;

    for (i = 1; i < k; i++)
    {
        if (a[i - 1] == 1)
            result += v[i];
        else
            if (a[i - 1] == 2)
                result -= v[i];
            else
                if (a[i - 1] == 0)
                    break;
                else
                    std::cout << "Error\n";
    }

    std::cout << result;
    std::cin >> result;

    return 0;
}