//
// Created by Виталий on 15.12.18.
//

#include "feistel.h"
#include <memory.h>
#include "cryptlib.h"
#include "key.h"
#include <iostream>
#include <string>

using namespace std;
void bytetobit(bool *out, const char *in,int bits);
void s_func(bool * fblock, bool * source);
void feistelFunction(bool * fblock, bool * fkey);
void makeXor(bool * first, bool * second, int count);
void epTransform(bool * fblock, bool * sblock,const char * isource, int length);

void changeBlocks(bool * firstBlock, bool * secondBlock, key & fkey, int i);

void feistel::feistelCycle(bool * blockBite, key & fkey) {
    bool * pLeftBlock = &blockBite[0], * pRightBlock = &blockBite[32];

    if(mode) {
        for (int i = 0; i < 16; i++){
            changeBlocks(pRightBlock, pLeftBlock, fkey, i);
            }

    } else for (int i = 15; i >= 0; i--) {
            changeBlocks(pLeftBlock, pRightBlock, fkey, i);
        }

}

void changeBlocks(bool * firstBlock, bool * secondBlock, key & fkey, int i) {
    bool * tempBlock = new bool[halfblock];

    memcpy(tempBlock,firstBlock,halfblock);
    feistelFunction(firstBlock,fkey.getFeistelKey(i));

    makeXor(firstBlock, secondBlock, halfblock);
    memcpy(secondBlock,tempBlock,halfblock);
}

void feistelFunction(bool * fblock, bool * fkey) {
    bool * extentionBlock = new bool[feistelLength];
    epTransform(extentionBlock, fblock, eTable, feistelLength);

    makeXor(extentionBlock, fkey, feistelLength);


    s_func(fblock,extentionBlock);

    epTransform(fblock,fblock,pTable,halfblock);
}

void makeXor(bool * first, bool * second, int count) {
    for (int i = 0; i < count; i++) {
        first[i] ^= second[i];
    }
}

void epTransform(bool * fblock, bool * sblock,const char * isource, int length) {
    static bool tmp[256];
    for(int i=0;i<length;i++)
        tmp[i]=sblock[isource[i]-1];
    memcpy(fblock,tmp,length);
}

void s_func(bool * fblock, bool * source)
{
    for(char i=0,j,k;i<8;i++,source+=6,fblock+=4)
    {
        j=(source[0]<<1)+source[5];
        k=(source[1]<<3)+(source[2]<<2)+(source[3]<<1)+source[4];
        bytetobit(fblock,&s_box[i][j][k],4);
    }
}

void bytetobit(bool *out,const char *in,int bits)
{

    for(int i=0;i<bits;i++){ out[i]=(in[i/8]>>(i%8)) &1; }

}

