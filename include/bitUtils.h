//
// Created by Mainli on 2023/4/9.
//

#ifndef TEST_BITUTILS_H
#define TEST_BITUTILS_H

unsigned int reverse_bit(unsigned int x, unsigned char num) {
    int bit_ = 0;
    int i;
    unsigned int sum = 0;
    for (i = 0; i < num; i++) {
        sum = sum << 1;
        bit_ = 1 & x;
        x = x >> 1;
        sum = sum | bit_;
    }
    return (sum);
}

#endif //TEST_BITUTILS_H
