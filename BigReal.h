#ifndef BIGREAL_H
#define BIGREAL_H
#include <iostream>
#include <string>

using namespace std;
class BigReal
{
private:
    string Num;
    char sign;
public:
    string get_realnum(){
        return Num;
    }
    BigReal (string realNumber );   //done
    BigReal (double realNumber);   //done
    BigReal(){}                     //done
    BigReal (BigDecimalInt bigInteger);   //done
    BigReal (const BigReal& other); // Copy constructor        //done
    BigReal (BigReal&& other); // Move constructor               //done
    BigReal& operator= (const BigReal& other); // Assignment operator    //done
    BigReal& operator= (BigReal&& other); // Move assignment
    BigReal operator+ (BigReal& other);        //done
    BigReal operator- (BigReal& other);        //done
    bool operator< (BigReal anotherReal);      //done
    bool operator> (BigReal anotherReal);       //done
    bool operator== (BigReal anotherReal);       //done
    int size();     //done
    int Sign();      //done
    void print();    //done
    int length();     //done
    int operator[](int index); //done
    friend ostream& operator << (ostream& out, BigReal &num);  //done
    friend istream& operator >> (istream& in, BigReal &num);  //done

};

void printResult(BigReal c1, string sign, BigReal c2);

#endif // BIGREAL_H
