#include <iostream>
#include <utility>
#include "BigReal.h"
using namespace std;
//------------------------------------------
int BigReal ::size()
{
    return Num.size();
}
//------------------------------------------
int BigReal ::length()
{
    return Num.length();
}
//------------------------------------------
int BigReal::operator[](int index)
{
    return Num[index];
}
//------------------------------------------
void BigReal ::print()
{
    cout << Num;
}
//------------------------------------------
ostream &operator<<(ostream &out, BigReal &num)
{
    out << num.Num;
    return out;
}
//------------------------------------------
istream &operator>>(istream &in, BigReal &num)
{
    in >> num.Num;
    return in;
}
//--------------------------------------------
int BigReal ::Sign()
{
    if (sign == '+')
        return 1;
    else
        return 0;
}
//------------------------------------------
BigReal ::BigReal(BigDecimalInt bigInteger)
{
    Num = bigInteger.get_number();
}
BigReal ::BigReal(double realNumber)
{
    string real = to_string(realNumber);
    Num = real;
}
//------------------------------------------
BigReal ::BigReal(string realNumber)
{
    Num = realNumber;
} // Default constructor
//------------------------------------------

BigReal ::BigReal(const BigReal &other)
{
    Num = other.Num;
} // Copy constructor

BigReal ::BigReal(BigReal &&other)
{
    Num = move(other.Num);

} // Move constructor
BigReal &BigReal ::operator=(BigReal &&other)
{
    Num = move(other.Num);
    return *this;
} // Move assignment

BigReal &BigReal ::operator=(const BigReal &other)
{
    if (this != &other)
    {
        Num = other.Num;
    }
    return *this;
} // Assignment operator

BigReal BigReal ::operator+(BigReal &other)
{

    string frc_x = "", frc_y = "", nfrc_x = "", nfrc_y = "";

    for (int i = 0; i < Num.length() - 1; i++)
    {
        if (Num[i] == '.')
            break;
        nfrc_x += Num[i];
    }
    for (int i = 0; i < other.length() - 1; i++)
    {
        if (other[i] == '.')
            break;
        nfrc_y += other[i];
    }
    for (int i = 0; i < Num.length() - 1; i++)
    {
        if (Num[i] == '.')
        {
            for (int j = i + 1; j < Num.length(); j++)
            {
                frc_x += Num[j];
            }
        }
    }

    for (int i = 0; i < other.length() - 1; i++)
    {
        if (other[i] == '.')
        {
            for (int j = i + 1; j < other.length(); j++)
            {
                frc_y += other[j];
            }
        }
    }

    if (frc_x.length() > frc_y.length())
        while (frc_x.length() > frc_y.length())
            frc_y.push_back('0');

    if (frc_y.length() > frc_x.length())
        while (frc_y.length() > frc_x.length())
            frc_x.push_back('0');

    if (nfrc_x == "")
        nfrc_x = "0";
    if (nfrc_y == "")
        nfrc_y = "0";
    string add_frc, add_nfrc;
    string add2 = "";
    string add1 = "";
    int carry = 0, ctoi = 0;
    for (int i = frc_x.length() - 1; i >= 0; i--)
    {
        string tmpstr1 = "", tmpstr2 = "";
        tmpstr1 += frc_x[i];
        tmpstr2 += frc_y[i];
        int tmp1 = stoi(tmpstr1); // turn each char in the string into int
        int tmp2 = stoi(tmpstr2); // turn each char in the string into int
        tmp1 += carry;
        int result = 0;
        if (i == 0)
        {
            if (tmp1 + tmp2 > 9)
            {
                int j = nfrc_x.length() - 1;
                while (nfrc_x[j] == '9')
                {
                    nfrc_x[j] -= 9;
                    j--;
                    if (j == 0)
                    {
                        if (nfrc_x[j] == '9')
                        {
                            nfrc_x[j] -= 9;
                            add2 += '1';
                            goto skip;
                        }
                    }
                }
                nfrc_x[j] += 1;
            skip:
                while (nfrc_x.length() < nfrc_y.length())
                {
                    string zero = "0";
                    zero += nfrc_x;
                    nfrc_x = zero;
                }
            }
        }
        if (tmp1 + tmp2 > 9)
        {
            carry = 1;
            result = (tmp1 + tmp2) - 10;
            add_frc += to_string(result);
        }
        else
        {
            carry = 0;
            result = tmp1 + tmp2;
            add_frc += to_string(result);
        }
    }

    for (int i = add_frc.length() - 1; i >= 0; i--)
    {
        add1 += add_frc[i];
    }

    BigDecimalInt b1(nfrc_x), b2(nfrc_y);
    BigDecimalInt b3 = b1 + b2;
    add2 += b3.get_number();
    if (add1 == "")
        add1 += "00";
    string fin = add2 + '.' + add1;
    return fin;
}
bool BigReal ::operator>(BigReal other)
{
    string frc_x = "", frc_y = "", nfrc_x = "", nfrc_y = "";

    for (int i = 0; i < Num.length() - 1; i++)
    {
        if (Num[i] == '.')
            break;
        nfrc_x += Num[i];
    }
    for (int i = 0; i < other.length() - 1; i++)
    {
        if (other[i] == '.')
            break;
        nfrc_y += other[i];
    }
    for (int i = 0; i < Num.length() - 1; i++)
        if (Num[i] == '.')
            for (int j = i + 1; j < Num.length(); j++)
                frc_x += Num[j];

    for (int i = 0; i < other.length() - 1; i++)
        if (other[i] == '.')
            for (int j = i + 1; j < other.length(); j++)
                frc_y += other[j];

    for (int i = 0; i < 1; i++)
    {
        if (nfrc_x[0] == '-' && nfrc_y[0] != '-')
        {
            return false;
            break;
        }
        if (nfrc_x[0] != '-' && nfrc_y[0] == '-')
        {
            return true;
            break;
        }
        if (nfrc_x[0] != '-' && nfrc_y[0] != '-')
        {
            if (nfrc_x > nfrc_y)
            {
                return true;
                break;
            }
            if (nfrc_x < nfrc_y)
            {
                return false;
                break;
            }
            if (nfrc_x == nfrc_y)
            {
                if (frc_x.length() > frc_y.length())
                    while (frc_x.length() > frc_y.length())
                        frc_y.push_back('0');

                if (frc_y.length() > frc_x.length())
                    while (frc_y.length() > frc_x.length())
                        frc_x.push_back('0');
                int counter = 0;
                for (int j = 0; j < frc_x.length(); j++)
                {
                    if (frc_x[j] == frc_y[j])
                    {
                        counter++;
                        continue;
                    }
                    if (frc_x[j] > frc_y[j])
                    {
                        return true;
                        break;
                    }
                    if (frc_x[j] < frc_y[j])
                    {
                        return false;
                        break;
                    }
                }
                if (counter == frc_x.length())
                {
                    return false;
                    break;
                }
            }
        }
        if (nfrc_x[0] == '-' && nfrc_y[0] == '-')
        {
            string x = "", y = "";
            for (int i = 1; i < nfrc_x.length() - 1; i++)
            {
                x += nfrc_x[i];
            }
            for (int i = 1; i < nfrc_y.length() - 1; i++)
            {
                y += nfrc_y[i];
            }
            if (x < y)
            {
                return true;
                break;
            }
            if (x > y)
            {
                return false;
                break;
            }
            if (x == y)
            {
                if (frc_x.length() > frc_y.length())
                    while (frc_x.length() > frc_y.length())
                        frc_y.push_back('0');

                if (frc_y.length() > frc_x.length())
                    while (frc_y.length() > frc_x.length())
                        frc_x.push_back('0');

                int counter = 0;
                for (int j = 0; j < frc_x.length(); j++)
                {
                    if (frc_x[j] == frc_y[j])
                    {
                        counter++;
                        continue;
                    }
                    if (frc_x[j] > frc_y[j])
                    {
                        return false;
                        break;
                    }
                    if (frc_x[j] < frc_y[j])
                    {
                        return true;
                        break;
                    }
                }
                if (counter == frc_x.length())
                {
                    return false;
                    break;
                }
            }
        }
    }
}
bool BigReal ::operator<(BigReal other)
{
    string frc_x = "", frc_y = "", nfrc_x = "", nfrc_y = "";

    for (int i = 0; i < Num.length() - 1; i++)
    {
        if (Num[i] == '.')
            break;
        nfrc_x += Num[i];
    }
    for (int i = 0; i < other.length() - 1; i++)
    {
        if (other[i] == '.')
            break;
        nfrc_y += other[i];
    }
    for (int i = 0; i < Num.length() - 1; i++)
        if (Num[i] == '.')
            for (int j = i + 1; j < Num.length(); j++)
                frc_x += Num[j];

    for (int i = 0; i < other.length() - 1; i++)
        if (other[i] == '.')
            for (int j = i + 1; j < other.length(); j++)
                frc_y += other[j];

    for (int i = 0; i < 1; i++)
    {
        if (nfrc_x[0] == '-' && nfrc_y[0] != '-')
        {
            return true;
            break;
        }
        if (nfrc_x[0] != '-' && nfrc_y[0] == '-')
        {
            return false;
            break;
        }
        if (nfrc_x[0] != '-' && nfrc_y[0] != '-')
        {
            if (nfrc_x > nfrc_y)
            {
                return false;
                break;
            }
            if (nfrc_x < nfrc_y)
            {
                return true;
                break;
            }
            if (nfrc_x == nfrc_y)
            {
                if (frc_x.length() > frc_y.length())
                    while (frc_x.length() > frc_y.length())
                        frc_y.push_back('0');

                if (frc_y.length() > frc_x.length())
                    while (frc_y.length() > frc_x.length())
                        frc_x.push_back('0');
                int counter = 0;
                for (int j = 0; j < frc_x.length(); j++)
                {
                    if (frc_x[j] == frc_y[j])
                    {
                        counter++;
                        continue;
                    }
                    if (frc_x[j] > frc_y[j])
                    {
                        return false;
                        break;
                    }
                    if (frc_x[j] < frc_y[j])
                    {
                        return true;
                        break;
                    }
                }
                if (counter == frc_x.length())
                {
                    return false;
                    break;
                }
            }
        }
        if (nfrc_x[0] == '-' && nfrc_y[0] == '-')
        {
            string x = "", y = "";
            for (int i = 1; i < nfrc_x.length() - 1; i++)
            {
                x += nfrc_x[i];
            }
            for (int i = 1; i < nfrc_y.length() - 1; i++)
            {
                y += nfrc_y[i];
            }
            if (x < y)
            {
                return false;
                break;
            }
            if (x > y)
            {
                return true;
                break;
            }
            if (x == y)
            {
                if (nfrc_x == nfrc_y)
                {
                    if (frc_x.length() > frc_y.length())
                        while (frc_x.length() > frc_y.length())
                            frc_y.push_back('0');

                    if (frc_y.length() > frc_x.length())
                        while (frc_y.length() > frc_x.length())
                            frc_x.push_back('0');
                    int counter = 0;
                    for (int j = 0; j < frc_x.length(); j++)
                    {
                        if (frc_x[j] == frc_y[j])
                        {
                            counter++;
                            continue;
                        }
                        if (frc_x[j] < frc_y[j])
                        {
                            return false;
                            break;
                        }
                        if (frc_x[j] > frc_y[j])
                        {
                            return true;
                            break;
                        }
                    }
                    if (counter == frc_x.length())
                    {
                        return false;
                        break;
                    }
                }
            }
        }
    }
}
bool BigReal ::operator==(BigReal other)
{
    string frc_x = "", frc_y = "", nfrc_x = "", nfrc_y = "";

    for (int i = 0; i < Num.length() - 1; i++)
    {
        if (Num[i] == '.')
            break;
        nfrc_x += Num[i];
    }
    for (int i = 0; i < other.length() - 1; i++)
    {
        if (other[i] == '.')
            break;
        nfrc_y += other[i];
    }
    for (int i = 0; i < Num.length() - 1; i++)
        if (Num[i] == '.')
            for (int j = i + 1; j < Num.length(); j++)
                frc_x += Num[j];

    for (int i = 0; i < other.length() - 1; i++)
        if (other[i] == '.')
            for (int j = i + 1; j < other.length(); j++)
                frc_y += other[j];

    BigDecimalInt o1(nfrc_x), o2(nfrc_y);
    if (o1 > o2 || o1 < o2)
    {
        return false;
    }
    if (o1 == o2)
    {
        BigDecimalInt o3(frc_x), o4(frc_y);
        if (o3 > o4 || o3 < o4)
        {
            return false;
        }
        if (o3 == o4)
        {
            return true;
        }
    }
}

void printResult(BigReal c1, string sign, BigReal c2)
{
    BigReal c3;
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
        cout << '-' << c3;
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
    else if (sign == "==")
    {
        c3 = c1 == c2;
        cout << c3;
    }
    else if (sign == ">")
    {
        c3 = c1 > c2;
        cout << c3;
    }
    else if (sign == "<")
    {
        c3 = c1 < c2;
        cout << c3;
    }
}

BigReal BigReal::operator-(BigReal &other)
{
    string frc_x = "", frc_y = "", nfrc_x = "", nfrc_y = "", sub = "", sub2 = "", nodot_x, nodot_y;

    if (Num[0] == '-' || Num[0] == '+')
    {
        for (int i = 1; i <= Num.length() - 1; i++)
        {
            if (Num[i] == '.')
                break;
            nfrc_x += Num[i];
        }
    }
    else
    {
        for (int i = 0; i <= Num.length() - 1; i++)
        {
            if (Num[i] == '.')
                break;
            nfrc_x += Num[i];
        }
    }

    if (other[0] == '-' || other[0] == '+')
    {
        for (int i = 1; i <= other.length() - 1; i++)
        {
            if (other[i] == '.')
                break;
            nfrc_y += other[i];
        }
    }
    else
    {
        for (int i = 0; i <= other.length() - 1; i++)
        {
            if (other[i] == '.')
                break;
            nfrc_y += other[i];
        }
    }

    for (int i = 0; i < Num.length() - 1; i++)
    {
        if (Num[i] == '.')
        {
            for (int j = i + 1; j < Num.length(); j++)
            {
                frc_x += Num[j];
            }
        }
    }

    for (int i = 0; i < other.length() - 1; i++)
    {
        if (other[i] == '.')
        {
            for (int j = i + 1; j < other.length(); j++)
            {
                frc_y += other[j];
            }
        }
    }

    if (frc_x.length() > frc_y.length())
        while (frc_x.length() > frc_y.length())
            frc_y.push_back('0');

    if (frc_y.length() > frc_x.length())
        while (frc_y.length() > frc_x.length())
            frc_x.push_back('0');

    if (nfrc_x == "")
        nfrc_x = "0";
    if (nfrc_y == "")
        nfrc_y = "0";

    while (nfrc_x.length() < nfrc_y.length())
    {
        string zero = "0";
        zero += nfrc_x;
        nfrc_x = zero;
    }
    while (nfrc_y.length() < nfrc_x.length())
    {
        string zero = "0";
        zero += nfrc_y;
        nfrc_y = zero;
    }

    nodot_x = nfrc_x + frc_x;
    nodot_y = nfrc_y + frc_y;

    BigDecimalInt b1(nodot_x), b2(nodot_y);
    BigDecimalInt b3 = b1 - b2;
    sub += b3.get_number();

    if (sub[0] == '-')
    {
        for (int i = 0; i <= sub.length() - 1; i++)
        {
            if (i == nfrc_x.length() + 1)
            {
                sub2 += '.';
            }
            sub2 += sub[i];
        }
    }
    else
    {
        for (int i = 0; i <= sub.length() - 1; i++)
        {
            if (i == nfrc_x.length())
            {
                sub2 += '.';
            }
            sub2 += sub[i];
        }
    }

    return sub2;
}