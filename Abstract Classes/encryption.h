//
// Created by Виталий on 15.12.18.
//

#ifndef PROG_ENCRYPTION_H
#define PROG_ENCRYPTION_H

#pragma once
#include <fstream>
#include <string>
#include "Contents.h"
#include "File.h"

class encryption: public Contents {
int mode;

public:
    encryption(int mode) : mode(mode) {}
     bool * getContent(bool *, File *);
};

#endif //PROG_ENCRYPTION_H
