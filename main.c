#include "pustaka.h"
/**
Nama    : AL BIRR KARIM SUSANTO
NIM     : A11.2017.10642
Kelompok: A11.4301u
Github  : https://github.com/AlbirrKarim
Email   : albirkarim1@gmail.com
License : Free to use, don't remove credit link
**/

void test1(){
    /// Untuk Test Encrypt & Decrypt
    char kunci[100];
    strcpy(kunci,"asus");
    char kalimat[100];
    strcpy(kalimat,"namaku albirr karim susanto aku kuliah di udinus");

    char chipper[100];
    printf("Kalimat (Plain text) : %s\n",kalimat);
    printf("Kunci   (key)        : %s\n\n\n",kunci);

    puts("[Encrypt]________________________");
    HillEn(kalimat,kunci,chipper,27);
    printf("Key            : %s\n",kunci);
    printf("Encrypted text : %s\n\n",chipper);

    char Plain[100];

    puts("[Decrypt]________________________");
    HillDe(kunci,chipper,Plain,27);
    printf("Key            : %s\n",kunci);
    printf("Decrypted text : %s\n\n",Plain);
}

void test2(){
    /// Untuk Tes satu persatu Fungsi
    char mboh[10]={"sap"};
    int k;
    AutoFixBug(mboh,"kopi",&k);
    printf("mboh %s",mboh);
}



int main(){
    test1();
    //test2();
    return 0;
}
