#include "pustaka.h"
///[FUNCTION TEST]_______________________________________________________











///_____________________________________________________________________


///__________________________________[ FINAL FUNCTION ] Last revision 14 OKT 2018, 09:37________________________________________
/// |Main function|
//Encrypt
void HillEn(char Kata[],char Kunci[],char *Keluar,int carset){
    /*
    IS: 'Kata' 'Kunci' inputan berupa string, 'Keluar' adalah parameter Output berupa string,
        'carset' adalah karakter set, misal a-z adalah 26 karakter
    FS: Prosedur akan menghasillkan Cipher text berupa string yang akan di outputkan melalui
        variabel 'Keluar'
    */
    ///Enkripsi
    //Minimalisir Bug
    AutoFixBug(Kata,Kunci,&carset);

    int pjgKa=strlen(Kata);
    int pjgKu=strlen(Kunci);


    //Ubah Kata menjadi array of float
    float KataF[pjgKa];

    KaltoArrFloat2x3(Kata,KataF,pjgKa,carset);
    //PrintMatriks(KataF,pjgKa);

    //Ubah Kunci menjadi array of float
    float KunciF[pjgKu];
    KaltoArrFloat2x3(Kunci,KunciF,pjgKu,carset);
    //PrintMatriks(KunciF,pjgKu);

    //cipherF = KunciF * KataF
    float cipherF[pjgKa];
    perkalian2x2dgn2x3(KunciF,KataF,pjgKa,cipherF);
    //PrintMatriks(cipherF,pjgKa);

    //chipperF di modulo
    mod(cipherF,pjgKa,carset);
    //PrintMatriks(cipherF,pjgKa);

    intTOchar2X2(cipherF,Keluar,pjgKa,carset);
}
//Decrypt
void HillDe(char Kunci[],char Cipher[],char *Keluar,int carset){
    ///Deskripsi
    //Minimalisir Bug
    AutoFixBug(Cipher,Kunci,&carset);


    int pjgCi=strlen(Cipher);
    int pjgKu=strlen(Kunci);

    //Ubah Kata menjadi array float
    float KunciF[pjgKu];
    KaltoArrFloat2x3(Kunci,KunciF,pjgKu,carset);

    //inverskan
    inversSeper2x2(KunciF,pjgKu,carset);
    //PrintMatriks(KunciF,pjgKu);

    float PlainF[pjgCi];
    float CipherF[pjgCi];
    KaltoArrFloat2x3(Cipher,CipherF,pjgCi,carset);
    //printf("ciper %s",Cipher);
    //PrintMatriks(CipherF,pjgCi);

    perkalian2x2dgn2x3(KunciF,CipherF,pjgCi,PlainF);
    //PrintMatriks(PlainF,pjgCi);

    mod(PlainF,pjgCi,carset);
    //PrintMatriks(PlainF,pjgCi);

    intTOchar2X2(PlainF,Keluar,pjgCi,carset);
}

/// |Support Function|
///A. Fungsi Perhitungan
//Determinan Matrik 3x3
float det3F(float data[]){
    /*
    IS: array 'data' tidak boleh kosong, length 9
    FS: fungsi akan menghasilkan determinan dari matriks 3x3
    */
    float hasil=0;
    int i,j,k;
    float tamp[4];
    int arFOR1[4]={4,5,7,8};
    int arFOR2[4]={3,5,6,8};
    int arFOR3[4]={3,4,6,7};
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            if(i==0){tamp[j]=data[arFOR1[j]];}
            else if(i==1){tamp[j]=data[arFOR2[j]];}
            else if(i==2){tamp[j]=data[arFOR3[j]];}
        }
        if(i%2==0||i==0){hasil=hasil+(data[i]*det2F(tamp));}
        else{hasil=hasil-(data[i]*det2F(tamp));}
    }
    return hasil;
}
//Determinan Matrik 2x2
float det2F(float data[]){
    /*
    IS: 'data' adalah array of float ber length 4
    FS: fungsi akan mereturnkan determinan dari matriks 2x2
    */
    return (data[0]*data[3])-(data[1]*data[2]);
}
//Fungsi Determinants’ Reciprocals Modulo
void mod(float data[],int len,int modulo){
    /*
    IS: array of float 'data' , 'len' adalah panjang dari array,
        'modulo' adalah bilangan untuk memodulo nilai dalam array of float
    FS: nilai dalam array ter mod
    */
    int i,b=0;
    for(i=0;i<len;i++){
        b=data[i];
        if(b<=0){data[i]=modmin(b,modulo);}
        else{data[i]=b%modulo;}
    }
}
int modSatuAngka(int b,int modulo){
    /*
    IS: 'b' adalah Integer yang akan di mod, 'modulo' adalah bilangan utk me modulo 'b'
    FS: 'b' ter mod oleh 'modulo'
    */
    int i;
    if(b<=0){return modmin(b,modulo);}
    else{return b%modulo;}
}
int modmin(int data,int modulo){
    /*
    Fungsi tambahan untuk modulo
    */
    if(data<modulo*-1){
        data=data%modulo;
    }
    return modulo+data;
}
//Fungsi SeperZ
int seperZ(int data,int modulo){
    /*
    IS:
    FS:
    */
    int i,Z1,Z=1,sepZ=1;
    for (Z1=1;Z1<modulo;Z1++){
        for (i=1;i<modulo;i++){
            if ((Z1*i)%modulo==1){
               if(Z1*Z==data){
                   return i*sepZ;
               }
            }
        }
    }
    return 0;
}
//Invers SeperZ
void inversSeper2x2(float m1[],int len,int carset){
    int i,deter,sep;
    adj2x2(m1);
    deter=modSatuAngka(det2F(m1),carset);
    sep=seperZ(deter,carset);
    if(sep<1||sep>26){
        puts("Kunci tidak bisa di invers");
        exit(1);
    }
    for(i=0;i<len;i++){
            m1[i]=m1[i]*sep;
    }
    mod(m1,len,carset);
}
//Perkalian matriks 2x2 dgn 2x3
void perkalian2x2dgn2x3(float m1[],float m2[],int m2len, float keluar[]){
    /*
    13 12   x   21  9  21
    1  21       4  14  19

    0 1 2   x   0 1 2 3
    3 4 5       4 5 6 7

    sample
    0 1 2       6
    3 4 5

    0 1 2 3     8
    4 5 6 7

    0 1 2 3 4   10
    5 6 7 8 9
    */
    int i,a=0,b=m2len/2;
    for(i=0;i<m2len;i++){
        if(i<m2len/2){
            keluar[i]= (m1[0]*m2[a])+(m1[1]*m2[b]);
            a++;b++;
        }
        else{
            keluar[i]= (m1[2]*m2[a])+(m1[3]*m2[b]);
            a++;b++;
        }
        if(a==m2len/2&&b==m2len){
            a=0;
            b=m2len/2;
        }
    }
}
//Adjoin2x2
void adj2x2(float m1[]){
    float tamp=m1[0];
    m1[0]=m1[3];
    m1[3]=tamp;
    m1[1]=m1[1]*-1;
    m1[2]=m1[2]*-1;
}

///B.Fungsi Translate

///Perhatian !!!!
//Silahkan Setting karakter apa saja yang di butuhkan untuk enkripsi di Variabel global ini
char KarakterSet[27]={"abcdefghijklmnopqrstuvwxyz "};

//Translate Huruf
int TransHuruf(char huruf,int carset){
    /**
    IS: inputan char 'huruf'
    FS: mereturnkan integer hasil translate
    **/
    if(carset<26){carset=26;puts("set karakter minimal 26");}
    char dataSet[carset];
    strcpy(dataSet,KarakterSet);
    int i,o=1;
    for(i=0;i<carset;i++){
        if(huruf==dataSet[i]){return o;}
        o++;
        if(o==carset){o=0;}
    }
    return 0;
}
//Merubah Float Menjadi String
void intTOchar2X2(float dat[],char keluar[],int len,int carset){
    char data[carset];
    strcpy(data,KarakterSet);
    int j,ky=0;
    int set[len];
    bacaF(set,len);

    for(j=0;j<len;j++){
        ky=dat[set[j]];
        if(ky==0){ky=carset-1;}
        else if(ky>=1&&ky<=carset-1){ky--;}
        keluar[j]=data[ky];
    }
    keluar[len]='\0';
}
//Print matriks
void PrintMatriks(float data[],int len){
    /**
    IS: input 'data' (array of float) , variabel 'len' adalah length dari array 'data'
    FS: nilai dari array akan tercetak dilayar
    **/
    int i,j=0,breaker=len/2;
    puts("_____________________________________");
    for(i=0;i<len;i++){
        if(j==breaker){
            puts("");
            j=0;
        }
        j++;
        printf("%.1f ",data[i]);
    }
    puts("");
    puts("_____________________________________");
}
//Kalimat to Array of float
void KaltoArrFloat2x3(char data[],float keluar[],int len,int carset){
    /*
    IS: string data tidak boleh kosong, array of float 'keluar' merupakan hasil terjemahan kalimat
        len adalah panjang array keluar
    FS: Merubah kalimat menjadi array of float
    */
    int dd[len];
    bacaF(dd,len);
    int i;
    for(i=0;i<len;i++){
        keluar[dd[i]]=TransHuruf(data[i],carset);
    }
}
void bacaF(int data[],int len){
    /**
    0 1 2       6
    3 4 5

    0 1 2 3     8
    4 5 6 7

    0 1 2 3 4   10
    5 6 7 8 9
    **/
    int j,gn=0,gj=len/2;
    for(j=0;j<len;j++){
        if(j%2==0){
            data[j]=gn;
            gn++;
        }
        else{
            data[j]=gj;
            gj++;
        }
    }
}

///C.Fungsi Minimalisir Bug
//Auto MengGenapkan Plain text
void AutoFixBug(char Kalimat[],char Kunci[],int *carset){
    int len=strlen(Kalimat);
    int lenK=strlen(Kunci);
    if(*carset<26||*carset>30){
        *carset=26;
    }

    if(len==0){
        strcpy(Kalimat,"example text");
    }
    if(lenK==0){
        puts("Kamu Belum Memasukkan Kunci, sebagai contoh aku beri kunci'kopi'");
        strcpy(Kunci,"kopi");
    }
    if(len%2!=0){
        Kalimat[len]=Kalimat[len-1];
    }
    if(lenK!=4){
        puts("Kunci Harus 4 karakter");
        strcpy(Kunci,"kopi");
    }
    if(!ValKunci(Kunci,*carset)){
        puts("Kunci tidak bisa di invers");
        puts("Gunakan Kunci Lain");
        exit(1);
    }

}
//Fungsi validasi kunci
int ValKunci(char data[],int carset){
    int len=strlen(data);
    float m1[len];
    KaltoArrFloat2x3(data,m1,len,carset);

    int i,deter,panjang=0;
    adj2x2(m1);

    deter=modSatuAngka(det2F(m1),carset);
    int sep=seperZ(deter,carset);
    int arr[100];

    cariInvArr(arr,&panjang,carset);
    for(i=0;i<panjang;i++){
       if(sep==arr[i]){
         return 1;
        }
    }
    return 0;
}
void cariInvArr(int data[],int *len,int modulo){
    //Cari seperZ
    int iter=0,i,Z1,Z=1,sepZ=1;
    for (Z1=1;Z1<modulo;Z1++){
        for (i=1;i<modulo;i++){
            if ((Z1*i)%modulo==1){
               data[iter]=Z1*Z;
               iter++;
            }
        }
    }
    *len=iter;
}
