#pragma warning(disable:4996)

#include <stdio.h>
#include <conio.h>

#define BUFFERSIZE 30
#define DATASIZE 22
#define ELEMENTCOUNT 2
#define ELEMENTSIZE (DATASIZE/ELEMENTCOUNT)
#define FILENAME "FREAD.OUT"

/*
    Source by Microsoft (https://docs.microsoft.com/en-us/cpp)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main() {
    FILE* stream;
    char list[30];
    int  i, numread, numwritten;

    for (i = 0; i < DATASIZE; i++) {
        list[i] = (char)('z' - i);
    }
        
    list[DATASIZE] = '\0'; //terminal null sehingga kita dapat mencetaknya

    //Buka file dalam mode teks:
    if (fopen_s(&stream, FILENAME, "w+t") == 0) {
        //Mencetak karakter DATASIZE untuk streaming
        printf("Contents of buffer before write/read:\n\t%s\n\n", list);
        numwritten = fwrite(list, sizeof(char), DATASIZE, stream);
        printf("Wrote %d items\n\n", numwritten);
        fclose(stream);
    } else {
        printf("Problem opening the file\n");
        return -1;
    }

    if (fopen_s(&stream, FILENAME, "r+t") == 0) {
        //Mencoba membaca karakter dalam 2 blok 11
        numread = fread_s(list, BUFFERSIZE, ELEMENTSIZE, ELEMENTCOUNT, stream);
        printf("Number of %d-byte elements read = %d\n\n", ELEMENTSIZE, numread);
        printf("Contents of buffer after write/read:\n\t%s\n", list);
        fclose(stream);
    } else {
        printf("File could not be opened\n");
        return -1;
    }

    _getch();
    return 0;
}