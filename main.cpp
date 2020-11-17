#include <iostream>
#include "factorize.h"
#include "bignum/wideint.h"


/*

g++ main.cpp -o hello.app && ./hello.app

*/


#ifdef __SIZEOF_INT128__
    using int128_t = __int128_t;
#else
    using int128_t = wideint<128, true, 32>;
#endif


int main(int argc, char const *argv[])
{
    int128_t pq;
    int128_t p, q;
    
    pq = 3102221862710776733U;
    
    p = BrentRichard(pq);
    q = pq / p;
    

    std::cout << pq << " " << p << " " << q << "\n";
    
    return 0;
}

