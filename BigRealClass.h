#ifndef BIGREALCLASS_H_INCLUDED
#define BIGREALCLASS_H_INCLUDED
#include "BigDecimalIntClass.h"

class BigReal
{
    friend ostream &operator<<(ostream &output, BigReal num);
    friend ostream &operator>>(ostream &input, BigReal num);

private:
    BigDecimalInt whole;
    BigDecimalInt fraction;
    string whole_string;
    string fraction_string;
    string number;
    char big_sign = '+';

public:
    BigReal(double realNumber);
    BigReal(string realNumber);
    BigReal(BigDecimalInt bigInteger);
    bool operator<(BigReal anotherReal);
    bool operator>(BigReal anotherReal);
    bool operator==(BigReal anotherReal);
    int size();
    char sign();
};

#endif // BIGREALCLASS_H_INCLUDED
