#include "BigRealClass.h"
#include "BigDecimalIntClass.h"
#include <iostream>
#include <string>
using namespace std;

BigReal::BigReal(double realNumber = 0.0)
{

    // convert number to string
    number = to_string(realNumber);

    // check if number is negative and remove sign
    if (number[0] == '-')
    {
        big_sign = '-';
        number.erase(0, 1);
    }
    else if (number[0] == '+')
    {
        number.erase(0, 1);
    }

    // split number into whole and fraction
    int j = 0;
    for (int i = 0; i < number.length(); i++)
    {
        if (j == 0 && number[i] != '.')
        {
            whole_string += number[i];
        }
        else if (number[i] == '.')
        {
            j = 1;
        }
        else if (j == 1)
        {
            fraction_string += number[i];
        }
    }
    // convert string to BigDecimalInt
    whole = BigDecimalInt(whole_string);
    fraction = BigDecimalInt(fraction_string);
};
BigReal::BigReal(string realNumber)
{
    // check if number is negative and remove sign
    if (realNumber[0] == '-')
    {
        big_sign = '-';
        realNumber.erase(0, 1);
    }
    else if (realNumber[0] == '+')
    {
        realNumber.erase(0, 1);
    }

    // split number into whole and fraction
    int j = 0;
    for (int i = 0; i < realNumber.length(); i++)
    {
        if (j == 0 && realNumber[i] != '.')
        {
            whole_string += realNumber[i];
        }
        else if (realNumber[i] == '.')
        {
            j = 1;
        }
        else if (j == 1)
        {
            fraction_string += realNumber[i];
        }
    }
    // convert string to BigDecimalInt
    whole = BigDecimalInt(whole_string);
    fraction = BigDecimalInt(fraction_string);
};
BigReal ::BigReal(BigDecimalInt bigInteger)
{
    whole = bigInteger;
    fraction = BigDecimalInt("0");
};

bool BigReal ::operator<(BigReal anotherReal)
{
    if (whole < anotherReal.whole)
    {
        if (fraction < anotherReal.whole)
        {
            return true;
        }
    }
    return false;
}

bool BigReal ::operator>(BigReal anotherReal)
{
    if (whole > anotherReal.whole)
    {
        if (fraction > anotherReal.fraction)
        {
            return true;
        }
    }
    return false;
}

bool BigReal ::operator==(BigReal anotherReal)
{
    if (whole == anotherReal.whole)
    {
        if (fraction == anotherReal.fraction)
        {
            return true;
        }
    }
    return false;
}

int BigReal ::size()
{
    return whole.size() + fraction.size();
}

char BigReal ::sign()
{
    return big_sign;
}

ostream &operator<<(ostream &output, BigReal num)
{
    output << num.whole << "." << num.fraction;

    return output;
}

/*ostream& operator>> (ostream& input, BigReal num){
    input >> num(number);

    return input;
}*/
