//
// Created by Виталий on 15.12.18.
//

#ifndef PROG_KEY_H
#define PROG_KEY_H
#pragma  once
#include "cryptlib.h"

class key {

    bool mainKey[block];
    bool fkeys[16][feistelLength];

    // Функции
    void generateFeistelKeys(bool * k);
    bool * copyKey(bool * k, short length) const;

public:
    /*
     * коструктор
     */
     key(const char * k);

    /*
     * получить данные одного из ключей
     */
    bool * getFeistelKey(int i);

};


#endif //PROG_KEY_H
