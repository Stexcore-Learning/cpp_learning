#include <iostream>
#include "utils.h"

/**
 * Entrada de la aplicacion
 */
int main(void) {
    int x = 2, y = 2;
    int z = x + y;
    signed int signedInt = 0;
    unsigned int unsignedInt = 0U;
    signed short int signedShortInt = 0;
    unsigned short int unsignedShortInt = 0U;
    signed short signedShort = 0;
    unsigned short unsignedShort = 0U;
    signed long int signedLongInt = 0L;
    unsigned long int unsignedLongInt = 0UL;
    signed long signedLong = 0L;
    unsigned long unsignedLong = 0UL;
    signed long long signedLongLong = 1LL;
    unsigned long long unsignedLongLong = 1ULL;
    bool b = true;
    float floating = 1.f;
    double doubling = 20.;
    long double longDoubling = 20.0L;
    enum STATUS {
        READY,
        CONNECTED,
        DISCONNECTED
    } statusConnection;

    statusConnection = READY;

    std::cout << "signedInt: " << sizeof(signedInt) << std::endl;
    std::cout << "unsignedInt: " << sizeof(unsignedInt) << std::endl;
    std::cout << "signedShortInt: " << sizeof(signedShortInt) << std::endl;
    std::cout << "unsignedShortInt: " << sizeof(unsignedShortInt) << std::endl;
    std::cout << "signedShort: " << sizeof(signedShort) << std::endl;
    std::cout << "unsignedShort: " << sizeof(unsignedShort) << std::endl;
    std::cout << "signedLongInt: " << sizeof(signedLongInt) << std::endl;
    std::cout << "unsignedLongInt: " << sizeof(unsignedLongInt) << std::endl;
    std::cout << "signedLong: " << sizeof(signedLong) << std::endl;
    std::cout << "unsignedLong: " << sizeof(unsignedLong) << std::endl;
    std::cout << "signedLongLong: " << sizeof(signedLongLong) << std::endl;
    std::cout << "b: " << sizeof(b) << std::endl;
    std::cout << "char: " << sizeof('1') << std::endl;
    std::cout << "floating: " << sizeof(floating) << std::endl;
    std::cout << "doubling: " << sizeof(doubling) << std::endl;
    std::cout << "longDoubling: " << sizeof(longDoubling) << std::endl;

    ::Mayor(2, 3);
    
    if(int variable = 1) {
        std::cout << variable;
    }

    int value;

    std::cin >> value;
    std::cout << "El entero recibido es:" << value;
    std::cin.get();
    
    return 0;
}

