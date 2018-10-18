#ifndef PUSTAKA_H_INCLUDED
#define PUSTAKA_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

///Fungsi utama
void HillEn(char Kata[],char Kunci[],char *Keluar,int carset);
void HillDe(char Kunci[],char Cipher[],char *Keluar,int carset);




///Fungsi pendukung
int TransHuruf(char huruf,int carset);
void PrintMatriks(float data[],int len);
float det3F(float data[]);
float det2F(float data[]);

void KaltoArrFloat2x3(char data[],float keluar[],int len,int carset);
void intTOchar2X2(float dat[],char keluar[],int len,int carset);
void perkalian2x2dgn2x3(float m1[],float m2[],int m2len, float keluar[]);
void adj2x2(float m1[]);

#endif // PUSTAKA_H_INCLUDED
