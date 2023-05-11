#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <iostream>

using namespace std;

class BigDecimalInt
{
private:
    string decimalNum;

public:
    BigDecimalInt(string decStr)
    {
        decimalNum = decStr;
        //     if(regex_match("(-|\\+)?[0-9]+")){
        //         decStr = decimalNum;
        //     }else{
        //         cout << "Invalid input !! " << endl;
        //     }
    }
    BigDecimalInt(long long decInt)
    {
        string dec = to_string(decInt);
        decimalNum = dec;
    }
    BigDecimalInt() {}
    //*******************************
    //  operator +
    //*******************************
    BigDecimalInt operator+(BigDecimalInt anotherDec);
    // ******************************
    // operator -
    // ******************************
    BigDecimalInt operator-(BigDecimalInt anotherDec);
    // ******************************
    // operators < , > , ==
    // ******************************
    bool operator<(BigDecimalInt anotherDec);
    bool operator>(BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);
    //*******************************
    // operator =
    //*******************************
    BigDecimalInt operator=(BigDecimalInt anotherDec);
    int size();
    int sign();
    int operator[](int index);
    friend ostream &operator<<(ostream &out, BigDecimalInt &b); // done
    friend istream &operator>>(istream &in, BigDecimalInt &b);  // done
    string get_number();
};

void printResult(BigDecimalInt c1, string sign, BigDecimalInt c2);

#endif
