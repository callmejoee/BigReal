#include "BigRealClass.h"
#include "BigDecimalIntClass.h"
#include <iostream>
#include <string>
using namespace std;

BigReal::BigReal(double realNumber = 0.0){

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

BigReal::BigReal(BigDecimalInt bigInteger)
{
    whole = bigInteger;
    fraction = BigDecimalInt("0");
};

//Copy Constructor
BigReal::BigReal(const BigReal& other){
        (*this).whole = BigDecimalInt {other.whole};
        (*this).fraction = BigDecimalInt {other.fraction};
        (*this).big_sign = char{other.big_sign};
};

// Move Constructor
BigReal::BigReal(BigReal&& other){
    this->whole = other.whole;
    this->fraction = other.fraction;
    this->big_sign = other.big_sign;
    other.whole = BigDecimalInt("0");
    other.fraction = BigDecimalInt("0");
    other.big_sign = '+';

};

// Assignment Operator
BigReal& BigReal::operator=(const BigReal& other){
    this->whole = BigDecimalInt(0);
    this->fraction = BigDecimalInt(0);
    whole = other.whole;
    fraction = other.fraction;
    big_sign = other.big_sign;
    return *this;
};

// Move Assignment
BigReal& BigReal::operator= (BigReal&& other){
    if(this != &other){
        this->whole = BigDecimalInt(0);
        this->fraction = BigDecimalInt(0);
        whole = other.whole;
        fraction = other.fraction;
        big_sign = other.big_sign;
        other.whole = BigDecimalInt("0");
        other.fraction = BigDecimalInt("0");
        other.big_sign = '+';
        return *this;
    }
};
////////////////////////////////////////////

/*BigReal :: BigReal operator+ (BigReal& other){

}

BigReal :: Bigreal operator- (BigReal& other){

}*/

////////////////////////////////////////////
bool BigReal ::operator<(BigReal anotherReal)
{
    if(big_sign == anotherReal.big_sign){
        if(whole < anotherReal.whole){
            return true;
        }
        else if(whole == anotherReal.whole){
            if(fraction < anotherReal.fraction){
                return true;
            }
            return false;
        }
        else{
            return false;
        }
    }
    else if(big_sign == '-' && anotherReal.big_sign == '+'){
        return true;
    }
    else{
        return false;
    }
}

bool BigReal ::operator>(BigReal anotherReal)
{
    if(big_sign == '-' && anotherReal == '-'){
        if(whole < anotherReal.whole){
            return true;
        }
        else if(whole == anotherReal.whole){
            if(fraction < anotherReal.fraction){
                return true;
            }
            return false;
        }
        return false;
    }
    else if(big_sign == '+' && anotherReal.big_sign == '+'){
        if(whole > anotherReal.whole){
            return true;
        }
        return false;
    }
    else if(big_sign == '-' && anotherReal.big_sign == '+'){
        return false;
    }
    else{
        return true;
    }
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

ostream& operator<<(ostream& output, const BigReal& num)
{
    output << num.whole << ". " << num.fraction;

    return output;
}

istream& operator>>(istream& input, BigReal& num){
    cout << "Enter BigReal number: ";
    input >> num.number;

    int j = 0;
    num.whole_string.clear();
    num.fraction_string.clear();

    for (int i = 0; i < num.number.length(); i++){
        if (j == 0 && num.number[i] != '.'){
            num.whole_string += num.number[i];
        }

        else if (num.number[i] == '.'){
            j = 1;
        }

        else if (j == 1){
            num.fraction_string += num.number[i];
        }
    }

    num.whole = BigDecimalInt (num.whole_string);
    num.fraction = BigDecimalInt(num.fraction_string);

    return input;
}
