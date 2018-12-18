#include "memory.h"
#include "stdio.h"
#include <fstream>
#include "fileEditor.h"
#include <iostream>

int main()
{
    editor file("/Users/Vitaliy/Desktop/Влада 2/book2.txt", 0);
    file.reading();
    return 0;
}
