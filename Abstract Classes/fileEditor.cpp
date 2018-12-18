//
// Created by Виталий on 15.12.18.
//

#include "fileEditor.h"
#include <fstream>
#include "cryptlib.h"
#include "encryption.h"
#include <string>

using namespace std;
const string extention = ".txt";
int getFileSize(string pathFile);
bool * convertToBits(const char * symbols, int size);
char * convertToChar( bool * bites, int size);

void editor::reading() {
    bool * bits;
    ifstream readFile(path);
    encryption content(mode);

    char * symbols = new char[blockLength];
    for (int i = 0; i < blockLength; i++) symbols[i] = 0;

    while (size >= 8){
        readFile.read(symbols, blockLength);
        bits = convertToBits(symbols, block);
        content.getContent(bits, this);
        size -= blockLength;
    }
    if (size < 8 && size) {
        readFile.read(symbols, blockLength);
        for (int i = size; i < blockLength; i++) { symbols[i] = ' '; }
        bits = convertToBits(symbols, block);
        content.getContent(bits, this);
    }


}

editor::editor(string path, int mode) : path(path), mode(mode){
    getPathAtrributies();
    size = getFileSize(path);
}


void editor::writing(bool * bites) {
    char * symbols = convertToChar(bites, block);
    ofstream writeFile("/Users/Vitaliy/Desktop/Влада 2/book3.txt", ios::app);
    string t = pathNoExt + " Enc" + extention;
    /*
    if (mode)
        writeFile.open(pathNoExt + " Enc" + extention, ios::app);
    else
        writeFile.open(pathNoExt + " Dec" + extention, ios::app);
        */
    if (writeFile.is_open()) {
        for (int i = 0; i < 8; i++) {
            writeFile << symbols[i];
        }
    }
}

bool * convertToBits(const char * symbols, int size) {
    bool * bits = new bool[size];
        for (int i = 0; i < size; i++)
            bits[i] = (symbols[i / 8] >> (i % 8)) & 1;
    return bits;
}

char * convertToChar( bool * bites, int size) {
    char * letters = new char[size / 8];
    memset(letters, 0, (size + 7) / 8);

    for(int i = 0; i < size; i++) letters[i/8] |= bites[i] << (i % 8);
    return letters;
}

void editor::getPathAtrributies() {
    string newpath = path;
    pathNoExt = (newpath.erase(newpath.length() - 4, newpath.length()));
}

int getFileSize(string pathFile) {
    fstream file(pathFile, ios::in|ios::ate);
    return file.tellg();
}


