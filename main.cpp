#include <iostream>
#include "Functions.cpp"
#include "BigReal.cpp"
using namespace std;

int main()
{

    BigReal n1, n2;
    string sign;
    cin >> n1 >> sign >> n2;

    printResult(n1, sign, n2);
}
