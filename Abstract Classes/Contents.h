//
// Created by Виталий on 15.12.18.
//

#ifndef PROG_CONTENTS_H
#define PROG_CONTENTS_H
#pragma once
#include "File.h"

class Contents {

public:
    virtual bool * getContent(bool *, File *) = 0;

};


#endif //PROG_CONTENTS_H
