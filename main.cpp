#include <iostream>
#include <string>
#include "BigDecimalIntClass.h"
#include "BigDecimalIntClass.cpp"
#include "BigRealClass.h"

int main()
{
    BigDecimalInt b("35434050");
    cout << b;
    BigReal a("-123.456");
    cout << a;
    return 0;
}
