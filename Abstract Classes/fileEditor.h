//
// Created by Виталий on 15.12.18.
//

#ifndef PROG_FILEEDITOR_H
#define PROG_FILEEDITOR_H


#pragma once
#include <fstream>
#include "File.h"
#include <string>
#include "encryption.h"
#include <fstream>

class editor: public File {
    std::string pathNoExt;
    std::string path;
    int mode;
    int size;
    void getPathAtrributies();
public:
    editor(std::string path, int mode);

    void reading();
    void writing(bool *);
};


#endif //PROG_FILEEDITOR_H
