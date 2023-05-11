#include <iostream>
#include "Functions.h"
#include <regex>
#include <string>
#include <math.h>

string BigDecimalInt :: get_number(){
    return decimalNum;
}
void printResult(BigDecimalInt c1, string sign, BigDecimalInt c2)
{
    BigDecimalInt c3;
    if (c1[0] == '-' && sign == "+" && c2[0] != '-')
    {
        c3 = c2 - c1;
        cout << c3;
    }
    else if (c2[0] == '-' && sign == "+" && c1[0] != '-')
    {
        c3 = c1 - c2;
        cout << c3;
    }
    else if (c1[0] == '-' && sign == "+" && c2[0] == '-')
    {
        c3 = c1 + c2;
        cout << c3;
    }
    else if (c1[0] == '-' && sign == "-" && c2[0] != '-')
    {
        c3 = c2 + c1;
        cout << "-" << c3;
    }
    else if (c2[0] == '-' && sign == "-" && c1[0] != '-')
    {
        c3 = c1 + c2;
        cout << c3;
    }
    else if (c1[0] == '-' && sign == "-" && c2[0] == '-')
    {
        c3 = c2 - c1;
        cout << c3;
    }
    else if (c1[0] != '-' && sign == "+" && c2[0] != '-')
    {
        c3 = c1 + c2;
        cout << c3;
    }
    else if (c1[0] != '-' && sign == "-" && c2[0] != '-')
    {
        c3 = c1 - c2;
        cout << c3;
    }
}

ostream &operator<<(ostream &out, BigDecimalInt &b)
{
    out << b.decimalNum;
    return out;
}
istream &operator>>(istream &in, BigDecimalInt &b)
{
    in >> b.decimalNum;
}

int BigDecimalInt::size()
{
    return decimalNum.size();
}
// ******************************
// operator <
// ******************************
bool BigDecimalInt::operator<(BigDecimalInt anotherDec)
{
    for(int i = 0;i < 1;i++){
        if(decimalNum[0] == '-' && anotherDec.decimalNum[0] != '-'){
            return true;
            break;
        }
        if(decimalNum[0] != '-' && anotherDec.decimalNum[0] == '-'){
            return false;
            break;
        }
        if(decimalNum[0] != '-' && anotherDec.decimalNum[0] != '-'){
            if(decimalNum.size() > anotherDec.decimalNum.size()){
                return false;
                break;
            }
            else if(decimalNum.size() < anotherDec.decimalNum.size()){
                return true;
                break;
            }
            else if(decimalNum.size() == anotherDec.decimalNum.size()){
                if(decimalNum > anotherDec.decimalNum || decimalNum == anotherDec.decimalNum){
                    return false;
                    break;
                }
                if(decimalNum < anotherDec.decimalNum ){
                    return true;
                    break;
                }
            }
        }
        if(decimalNum[0] == '-' && anotherDec.decimalNum[0] == '-'){
            string dec = "",ano = "";
            for(int i = 1; i < decimalNum.size()-1;i++){
                dec += decimalNum[i];
            }
            for(int i = 1; i < anotherDec.decimalNum.size()-1;i++){
                dec += anotherDec.decimalNum[i];
            }
            cout<<"\tdec = \t"<<dec;
            cout<<"\ano = \t"<<ano;
            decimalNum = dec;anotherDec.decimalNum = ano;
            if(decimalNum.size() > anotherDec.decimalNum.size()){
                return true;
                break;
            }
            else if(decimalNum.size() < anotherDec.decimalNum.size()){
                return false;
                break;
            }
            else if(decimalNum.size() == anotherDec.decimalNum.size()){
                if(decimalNum > anotherDec.decimalNum  || decimalNum == anotherDec.decimalNum){
                    return true;
                    break;
                }
                if(decimalNum < anotherDec.decimalNum){
                    return false;
                    break;
                }
            }

        }
    }

}
// ******************************
// operator >
// ******************************
bool BigDecimalInt::operator>(BigDecimalInt anotherDec)
{
    for(int i = 0;i < 1;i++){
        if(decimalNum[0] == '-' && anotherDec.decimalNum[0] != '-'){
            return false;
            break;
        }
        if(decimalNum[0] != '-' && anotherDec.decimalNum[0] == '-'){
            return true;
            break;
        }
        if(decimalNum[0] != '-' && anotherDec.decimalNum[0] != '-'){
            if(decimalNum.size() > anotherDec.decimalNum.size()){
                return true;
                break;
            }
            else if(decimalNum.size() < anotherDec.decimalNum.size()){
                return false;
                break;
            }
            else if(decimalNum.size() == anotherDec.decimalNum.size()){
                if(decimalNum > anotherDec.decimalNum){
                    return true;
                    break;
                }
                if(decimalNum < anotherDec.decimalNum || decimalNum == anotherDec.decimalNum){
                    return false;
                    break;
                }
            }
        }
        if(decimalNum[0] == '-' && anotherDec.decimalNum[0] == '-'){
            string dec = "",ano = "";
            for(int i = 1; i < decimalNum.size()-1;i++){
                dec += decimalNum[i];
            }
            for(int i = 1; i < anotherDec.decimalNum.size()-1;i++){
                dec += anotherDec.decimalNum[i];
            }
            decimalNum = dec;anotherDec.decimalNum = ano;
            if(decimalNum.size() > anotherDec.decimalNum.size()){
                return true;
                break;
            }
            else if(decimalNum.size() < anotherDec.decimalNum.size()){
                return false;
                break;
            }
            else if(decimalNum.size() == anotherDec.decimalNum.size()){
                if(decimalNum > anotherDec.decimalNum){
                    return true;
                    break;
                }
                if(decimalNum < anotherDec.decimalNum || decimalNum == anotherDec.decimalNum){
                    return false;
                    break;
                }
            }

        }
    }

}
// ******************************
// operator ==
// ******************************
bool BigDecimalInt::operator==(BigDecimalInt anotherDec)
{

    if(decimalNum == anotherDec.decimalNum)
        return true;
    else
        return false;
}
// ******************************
// operator -
// ******************************
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec)
{
    string temp_string1, temp_string2;
    string add = "";
    string add1 = "";

    int sub;
    string temp_string3;
    // add the small number zeros
    if ((anotherDec[0] == '-' && decimalNum[0] == '-') || (anotherDec[0] == '+' && decimalNum[0] == '+') || (anotherDec[0] == '-' && decimalNum[0] == '+') || (anotherDec[0] == '+' && decimalNum[0] == '-'))
    {
        for (int i = 1; i < anotherDec.size(); i++)
            temp_string2 += anotherDec[i];
        for (int i = 1; i < decimalNum.size(); i++)
            temp_string1 += decimalNum[i];
    }
    else if ((decimalNum[0] == '-' && anotherDec[0] != '-') || (anotherDec[0] == '+' && decimalNum[0] != '+'))
    {
        for (int i = 0; i < anotherDec.size(); i++)
            temp_string2 += anotherDec[i];
        for (int i = 1; i < decimalNum.size(); i++)
            temp_string1 += decimalNum[i];
    }
    else if ((decimalNum[0] != '-' && anotherDec[0] == '-') || (anotherDec[0] != '+' && decimalNum[0] == '+'))
    {
        for (int i = 1; i < anotherDec.size(); i++)
            temp_string2 += anotherDec[i];
        for (int i = 0; i < decimalNum.size(); i++)
            temp_string1 += decimalNum[i];
    }
    else
    {
        // if the two numbers are positive
        for (int i = 0; i < anotherDec.size(); i++)
            temp_string2 += anotherDec[i];
        for (int i = 0; i < decimalNum.size(); i++)
            temp_string1 += decimalNum[i];
    }

    if (temp_string1.length() < temp_string2.length())
    {
        while (temp_string1.length() < temp_string2.length())
        {
            string zero = "0";
            zero += temp_string1;
            temp_string1 = zero;
        }
    }
    if (temp_string2.length() < temp_string1.length())
    {
        while (temp_string2.length() < temp_string1.length())
        {
            string zero = "0";
            zero += temp_string2;
            temp_string2 = zero;
        }
    }
    if (temp_string2 > temp_string1)
    {
        temp_string3 = temp_string1;
        temp_string1 = temp_string2;
        temp_string2 = temp_string3;
        add1 += "-";
    }

    for (int i = temp_string2.length() - 1; i >= 0; i--)
    {
        string fs = "", sc = "";
        fs += temp_string1[i];
        sc += temp_string2[i];

        if (temp_string1[i] >= temp_string2[i])
        {
            sub = stoi(fs) - stoi(sc);
            add += to_string(sub);
        }
        else
        {
            if (temp_string1[i - 1] == '0')
            {
                int j = 1;
                while (temp_string1[i - j] == '0')
                {
                    temp_string1[i - j] += 9;
                    j++;
                }
                temp_string1[i - j] -= 1;
                fs = to_string(stoi(fs) + 10);
                sub = stoi(fs) - stoi(sc);
                add += to_string(sub);
            }
            else
            {
                temp_string1[i - 1] -= 1;
                fs = to_string(stoi(fs) + 10);
                sub = stoi(fs) - stoi(sc);
                add += to_string(sub);
            }
        }
    }
    for (int i = add.length() - 1; i >= 0; i--)
    {
        add1 += add[i];
    }

    return add1;
}
// ******************************
// operator +
// ******************************
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec)
{
    string temp_string1, temp_string2;
    string add;
    int carry = 0;
    // if the two numbers are negative
    if ((anotherDec[0] == '-' && decimalNum[0] == '-') || (anotherDec[0] == '+' && decimalNum[0] == '+') || (anotherDec[0] == '-' && decimalNum[0] == '+') || (anotherDec[0] == '+' && decimalNum[0] == '-'))
    {
        for (int i = 1; i < anotherDec.size(); i++)
            temp_string2 += anotherDec[i];
        for (int i = 1; i < decimalNum.size(); i++)
            temp_string1 += decimalNum[i];
    }
    else if ((decimalNum[0] == '-' && anotherDec[0] != '-') || (anotherDec[0] == '+' && decimalNum[0] != '+'))
    {
        for (int i = 0; i < anotherDec.size(); i++)
            temp_string2 += anotherDec[i];
        for (int i = 1; i < decimalNum.size(); i++)
            temp_string1 += decimalNum[i];
    }
    else if ((decimalNum[0] != '-' && anotherDec[0] == '-') || (anotherDec[0] != '+' && decimalNum[0] == '+'))
    {
        for (int i = 1; i < anotherDec.size(); i++)
            temp_string2 += anotherDec[i];
        for (int i = 0; i < decimalNum.size(); i++)
            temp_string1 += decimalNum[i];
    }
    else
    {
        // if the two numbers are positive
        for (int i = 0; i < anotherDec.size(); i++)
            temp_string2 += anotherDec[i];
        for (int i = 0; i < decimalNum.size(); i++)
            temp_string1 += decimalNum[i];
    }
    // add the small number zeros
    if (temp_string1.length() < temp_string2.length())
    {
        while (temp_string1.length() < temp_string2.length())
        {
            string zero = "0";
            zero += temp_string1;
            temp_string1 = zero;
        }
    }
    if (temp_string2.length() < temp_string1.length())
    {
        while (temp_string2.length() < temp_string1.length())
        {
            string zero = "0";
            zero += temp_string2;
            temp_string2 = zero;
        }
    }
    // add and carry
    for (int i = temp_string1.length() - 1; i >= 0; i--)
    {
        string tmpstr1 = "", tmpstr2 = "";
        tmpstr1 += temp_string1[i];
        tmpstr2 += temp_string2[i];
        int tmp1 = stoi(tmpstr1); // turn each char in the string into int
        int tmp2 = stoi(tmpstr2); // turn each char in the string into int
        tmp1 += carry;
        int result = 0;
        if (tmp1 + tmp2 > 9)
        {
            carry = 1;
            result = (tmp1 + tmp2) - 10;
            add += to_string(result);
        }
        else
        {
            carry = 0;
            result = tmp1 + tmp2;
            add += to_string(result);
        }
        if (i == 0 && tmp1 + tmp2 > 9)
        {
            add += to_string(carry);
        }
    }
    // return the final result if the two numbers are negative
    if (anotherDec[0] == '-' && decimalNum[0] == '-')
    {
        string add1 = "-";
        for (int i = add.length() - 1; i >= 0; i--)
        {
            add1 += add[i];
        }
        return add1;
    }
    else
    {
        // return the final result if the two numbers are positive
        string add1 = "";
        for (int i = add.length() - 1; i >= 0; i--)
        {
            add1 += add[i];
        }

        return add1;
    }
}
// ******************************
// operator =
// ******************************
BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec)
{
    decimalNum = anotherDec.decimalNum;
    return decimalNum;
};
// ******************************
// operator []
// ******************************
int BigDecimalInt::operator[](int index)
{
    return decimalNum[index];
}
