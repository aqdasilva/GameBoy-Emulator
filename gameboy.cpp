#include "gameboy.h"
extern QApplication* app;


unsigned char memoryRead(int);
void memoryWrite(int,unsigned char);
#include “Z80.h”
#include <stdio.h>
#include <iostream>
using namespace std;
#include <fstream>
Z80* z80;
char* rom;
int romSize;
unsigned char memoryRead(int address)
{
  return rom[address];
}
void memoryWrite(int address, unsigned char value)
{
}
int main(int argc, char* argv[])
{
   int n;
   ifstream vidfile("screendump.txt",ios::in);
   for(int i=0; i<8192; i++){
   int n;
   vidfile>>n;
   graphicsRAM[i]=(unsigned char)n;

   ifstream romfile(“testrom.gb”, ios::in|ios::binary|ios::ate);
   streampos size=romfile.tellg();
   rom=new char[size];
   romSize=size;
   romfile.seekg(0,ios::beg);
   romfile.read(rom,size);
   romfile.close();
   z80 = new Z80(memoryRead, memoryWrite);
   z80->reset();
   while(!z80->halted)
   {
       z80->doInstruction();
   }
   cout<<z80->PC<<“\n”;
   cout<<z80->instruction<<“\n”;
   cout<<z80->A<<“\n”;
   cout<<z80->B<<“\n”;
}
