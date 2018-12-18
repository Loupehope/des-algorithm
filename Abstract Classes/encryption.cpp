//
// Created by Виталий on 15.12.18.
//

#include "encryption.h"
#include "fileEditor.h"
#include "feistel.h"
#include "key.h"
#include <memory.h>
#include <iostream>
#include "File.h"

void makeBlockTransformation(bool * text, const char * table, int size);

bool * encryption::getContent(bool * text, File * file) {
    feistel f(mode); key mkey(keyNumber);
    bool * newtext = new bool[block];
    memcpy(newtext, text, block);

    makeBlockTransformation(newtext, initialTable, block);
    f.feistelCycle(newtext, mkey);
    makeBlockTransformation(newtext, lastTable, block);

    file->writing(newtext);

}

void makeBlockTransformation(bool * text, const char * table, int size) {
    bool * newtext = new bool[size];
    for (int i = 0; i < size; i++) newtext[i] = text[table[i] - 1];
    memcpy(text, newtext, size);
}
