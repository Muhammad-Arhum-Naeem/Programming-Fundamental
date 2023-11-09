#include <iostream>
using namespace std;

int main()
{
    int num1=0, num2=0, num3=0, max = 0, max_prime=0;
    bool flag1 = true, flag2 = true, flag3 = true;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter third number: ";
    cin >> num3;

    for (int i = 2; i <= num1 / 2; i++)
    {
        if (num1 % i == 0)
        {
            flag1 = false;
            break;
        }
    }
    for (int j = 2; j <= num2 / 2; j++)
    {
        if (num2 % j == 0)
        {
            flag2 = false;
            break;
        }
    }
    for (int k = 2; k <= num3 / 2; k++)
    {
        if (num3 % k == 0)
        {
            flag3 = false;
            break;
        }
    }

    if (flag1 == true && (num1>num2 && num1>num3))
    {
        max_prime = num1;
    }
    else if (flag2 == true && (num2>num3))
    {
        max_prime = num2;
    }
    else if (flag3 == true)
    {
        max_prime = num3;
    }

    cout<<"Max Prime Number is : "<<max_prime;
}