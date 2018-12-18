//
// Created by Виталий on 15.12.18.
//

#ifndef PROG_FEISTEL_H
#define PROG_FEISTEL_H
#pragma once
#include "key.h"

class feistel {
    int mode;

public:
    feistel(int mode) : mode(mode) {}

    void feistelCycle(bool * block, key & fkey);
};


#endif //PROG_FEISTEL_H
