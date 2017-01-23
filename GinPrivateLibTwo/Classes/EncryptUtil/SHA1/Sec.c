//
//  Sec.c
//  以太优选
//
//  Created by ian X on 1/21/15.
//  Copyright (c) 2015 EtherCap. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

uint32_t lfsr113_z1 = 0, lfsr113_z2 = 0, lfsr113_z3 = 0, lfsr113_z4 = 0;

void lfsr113_srand(uint32_t seed) {
    lfsr113_z1 = seed;
    lfsr113_z2 = seed;
    lfsr113_z3 = seed;
    lfsr113_z4 = seed;
}

uint32_t lfsr113_rand(void)
{
    uint32_t b;
    b  = ((lfsr113_z1 << 6) ^ lfsr113_z1) >> 13;
    lfsr113_z1 = ((lfsr113_z1 & 4294967294U) << 18) ^ b;
    b  = ((lfsr113_z2 << 2) ^ lfsr113_z2) >> 27;
    lfsr113_z2 = ((lfsr113_z2 & 4294967288U) << 2) ^ b;
    b  = ((lfsr113_z2 << 13) ^ lfsr113_z2) >> 21;
    lfsr113_z2 = ((lfsr113_z2 & 4294967280U) << 7) ^ b;
    b  = ((lfsr113_z4 << 3) ^ lfsr113_z4) >> 12;
    lfsr113_z4 = ((lfsr113_z4 & 4294967168U) << 13) ^ b;
    return (lfsr113_z1 ^ lfsr113_z2 ^ lfsr113_z3 ^ lfsr113_z4);
}

uint32_t fibonacci_loop(uint32_t idx, uint32_t p1, uint32_t p2) {
    if (idx == 0) {
        return p1;
    } else if (idx == 1) {
        return p2;
    } else {
        return fibonacci_loop(idx-1, p2, p1+p2);
    }
}

uint32_t fibonacci(uint32_t idx) {
    if (idx == 0 || idx == 1) {
        return 1;
    }
    return fibonacci_loop(idx, 1, 1);
}

uint32_t loop0(uint32_t k, uint32_t kk, uint32_t seed) {
    return (k<<1)/fibonacci(3)+(kk>>1)/fibonacci(6) + (seed<<1)/fibonacci(8);
}

uint32_t loop1(uint32_t k, uint32_t kk, uint32_t seed) {
    return abs(k*fibonacci(2)-(kk>>fibonacci(2))/fibonacci(5)) + (seed<<2)/fibonacci(6);
}

uint32_t loop2(uint32_t k, uint32_t kk, uint32_t seed) {
    return k*(kk>>3)/fibonacci(10) + seed/fibonacci(7) + 1;
}

uint32_t genSecurityCode(uint32_t seed) {
    lfsr113_srand(seed*3+fibonacci(40));
    uint32_t k = lfsr113_rand();
    uint32_t len = fibonacci(18);
    for(uint32_t i=0; i < len; i++) {
        uint32_t loop = lfsr113_rand()%fibonacci(5)+fibonacci(6);
        for (uint32_t j=0; j<loop; j++) {
            lfsr113_rand();
        }
        uint32_t op = lfsr113_rand();
        seed = (k<<1)+(seed>>2)*13+i*(i<<1);
        lfsr113_srand(seed);
        loop = lfsr113_rand()%fibonacci(6)+fibonacci(5);
        for (uint32_t j=0; j<loop; j++) {
            lfsr113_rand();
        }
        uint32_t kk = lfsr113_rand();
        if (op%3 == 0) {
            k = loop0(k, kk, seed);
        } else if(op%3 == 1) {
            k = loop1(k, kk, seed);
        } else if (op%3 == 2) {
            k = loop2(k, kk, seed);
        }
    }
    return (uint32_t)k;
}
