#ifndef FACTORIZATION_H
#define FACTORIZATION_H

#include <cstdint>
#include <algorithm>


/*

https://stackoverflow.com/questions/31953836/decompose-a-number-into-2-prime-co-factors

https://github.com/michaeljclark/bignum

*/



int randint(int a, int b)
{
    return (rand() % (b - a)) + a;
}


template <typename T>
T abs(const T &v) { return v < 0 ? -v : v; }


template <typename T>
T gcd(T a, T b) 
{
    while (b != 0) {
        a %= b;
        if (a == 0)
            return b;
        b %= a;
    }
    
    return a;
}



template <typename T>
T PollardRho(const T &n)
{
    if (n % 2 == 0)
        return 2;

    T x, c, g, y;
    
    x = randint(1, 1000);
    c = randint(1, 1000);
    g = 1;
    y = x;
    
    while (g == 1) {
        x = ((x * x) % n + c) % n;
        y = ((y * y) % n + c) % n;
        y = ((y * y) % n + c) % n;
        g = gcd(abs(x - y), n);
    }

    return g;
    
}

template <typename T>
T BrentRichard(const T &n)
{
    if (n % 2 == 0)
        return 2;
        
    T y, c, m;
    y = randint(1, 1000);
    c = randint(1, 1000);
    m = randint(1, 1000);

    T g, r, q;
    g = r = q = 1;

    T x, ys;
    x = ys = 0;

    while (g == 1) {
        x = y;
        
        for (T i = 0; i < r; ++i) {
            y = ((y * y) % n + c) % n;
        }
            
        T k = 0;
        while (k < r && g == 1) {
            ys = y;
            for (T i = 0; i < std::min(m, r - k); ++i) {
                y = ((y * y) % n + c) % n;
                q = q * (abs(x - y)) % n;
            }

            g = gcd(q, n);
            k += m;
        }
        
        r *= 2;
    }

    if (g == n) {
        while (1) {
            ys = ((ys * ys) % n + c) % n;
            g = gcd(abs(x - ys), n);
            if (g > 1)
                break;
        }
    }

    return g;
}


#endif


