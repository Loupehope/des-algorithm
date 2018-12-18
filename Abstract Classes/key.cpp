//
// Created by Виталий on 15.12.18.
//
#include "key.h"
#include "memory.h"
#include "cryptlib.h"

using namespace std;

void charToBits(bool * bites, const char * text, int bits); // переводит char в "биты"
void makeKeyMix(bool * toKey, bool * fromKey, const char * table, int len);
void cycleShift(bool * key, int len, int shift);

key::key(const char * key) {
    charToBits(mainKey, key, block);
    makeKeyMix(mainKey, mainKey, genKeyTable, keyLength);
    generateFeistelKeys(mainKey);
}

void charToBits(bool * bites, const char * text, int bits) {
    for(int i = 0; i < bits; i++)
        bites[i] = (text[i/8] >> (i % 8)) & 1;
}

void key::generateFeistelKeys(bool * key) {
    bool * lkey = key, * rkey = key + keyLength / 2; // указатели на первый элемент

    for(int i = 0; i < 16; i++) {
        cycleShift(lkey,28,cyclicalShiftKey[i]);
        cycleShift(rkey,28,cyclicalShiftKey[i]);
        makeKeyMix(fkeys[i], key, genKeyFeistel, feistelLength);
    }
}

void cycleShift(bool * key, int len, int shift) {
    bool temp[256]; // Надо подумать над Числом

    memcpy(temp, key, shift);
    memcpy(key, key + shift, len - shift);
    memcpy(key + len - shift, temp, shift);
}

void makeKeyMix(bool * toKey, bool * fromKey, const char * table, int length) {
    bool * tmp = new bool[length];
    for(int i = 0;i < length; i++) tmp[i] = fromKey[table[i] - 1];
    memcpy(toKey, tmp, length);
}

bool * key::copyKey(bool * key, short length) const {
    bool * finalKey = new bool[length];
    memcpy(finalKey, key, length);
    return finalKey;
}

bool * key::getFeistelKey(int i) {
    bool * temp = copyKey(fkeys[i], feistelLength);
    return temp;
}

