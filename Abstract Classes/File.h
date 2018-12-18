//
// Created by Виталий on 15.12.18.
//

#ifndef PROG_FILE_H
#define PROG_FILE_H
#pragma once
#include <string>

class File {

public:
    virtual void reading() = 0;
    virtual void writing(bool *) = 0;

};


#endif //PROG_FILE_H
