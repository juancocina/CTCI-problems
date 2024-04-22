/*
    5.8 Draw Line: A monochrome screen is stored as a single array of bytes, alloing
    eight consecutive pixels to be stored in one byte. The screen has width w,
    where w is divisible by 8 (that is, no byte will be split across rows).
    The height of the screen, of course, can be derived from the the length of the array
    and the width. Implement a function that draws a horizontal line from 
    (x1, y) to (x2, y)

    The method signature should look something like:
    drawLine(byte[] screen, int width, int x1, int x2, y)

    -----
    So something that I didn't know was that you can create a vector/array where
    each index has 8 bits (1 byte), using char
*/

#include<iostream>
#include<math.h>

using namespace std;

void drawLine(char screen[], int width, int x1, int x2, int y)
{
    // figure out the starts
    int startPixel = x1 % 8;
    int startFullSet = x1 / 8;
    if( startPixel != 0) startFullSet++;

    int endPixel = x2 % 8;
    int endFullSet = x2 / 8;
    if( endPixel != 7) endFullSet--;

    // set the bytes with full pixels
    for(int b = startFullSet; b <= endFullSet; b++){
        screen[(width/8) * y + b] = 0xff;
    }

    // make the masks for the start bit
    char startMask = 0xff << startPixel;
    char endMask   = ~( 0xff << endPixel+1);

    // use the masks to set the bits
    if((x1/8) == (x2/8)) 
    {
        screen[(width/8) * y + (x1/8)] |= (startMask & endMask);
    } else {
        if(startPixel != 0) 
        {
            int byteNum = (width/8) * y + startFullSet-1;
            screen[byteNum] |= startMask;
        }
        if(endPixel != 7)
        {
            int byteNum = (width/8) * y + endFullSet+1;
            screen[byteNum] |= endMask;
        }
    }
}

void printScreen(char screen[], int width, int n)
{
    for(int i = 0; i < n; i++)
    {
        char c = screen[i];
        for(int b = 0; b < 8; b++) // iterate through 8 bits
        {
            //print either 1 or 0 depending on if the bit is set
            if((c&1) == 1) cout << "1";
            else if((c&1) == 0) cout << "0";
            c >>= 1;    // shift char to the right
        }
        cout << " ";

        // start a new line according the width of our screen
        if((i+1) % (width/8) == 0) cout << endl; 
    }
}

int main()
{
    // lets say our screen has a width of 32 pixels
    const int width = 32;
    // and a height of 32 pixels
    const int height = 32;
    const int sizeInBytes = (width*height) / 8;

    char screen[sizeInBytes] = { 0 }; // having the {0} sets all the values to 0x00 or x00
    // cout << "first print" << endl;
    // printScreen(screen,width, sizeInBytes)

    drawLine(screen, width, 3, 20, 17);
    cout << endl << "print after mod" << endl;
    printScreen(screen, width, sizeInBytes);
    return 0;
}