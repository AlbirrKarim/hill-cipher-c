void intTOchar(float dat[],char keluar[],int len){
    char data[26]={"abcdefghijklmnopqrstuvwxyz"};
    int j;
    int ky=0;
    strcpy(keluar,"");
    for(j=0;j<len;j++){
        ky=dat[j];
        if(ky==0){
            ky=25;
        }
        else if(ky>=1&&ky<=24){
            ky--;
        }
        keluar[j]=data[ky];
    }
}
///Menginverskan matriks 3x3 seperZ
void invers3x3SeperZ(float m1[],float keluar[]){
    /**
    IS: m1 adalah inputan array yang mempunyai length 9
    FS: keluar adalah array untuk output mempunyai length 9
    **/
    int deter=det3F(m1);
    int seper=seperZ(deter%26);
    //printf("B %d\n\n",seper);

    keluar[0]=seper*((m1[4]*m1[8])-(m1[7]*m1[5]));
    //printf("A %f\n\n",((m1[4]*m1[8])-(m1[7]*m1[5])));
    keluar[1]=seper*((m1[7]*m1[2])-(m1[1]*m1[8]));
    keluar[2]=seper*((m1[1]*m1[5])-(m1[4]*m1[2]));

    keluar[3]=seper*((m1[5]*m1[6])-(m1[8]*m1[3]));
    keluar[4]=seper*((m1[8]*m1[0])-(m1[2]*m1[6]));
    keluar[5]=seper*((m1[2]*m1[3])-(m1[5]*m1[0]));

    keluar[6]=seper*((m1[3]*m1[7])-(m1[6]*m1[4]));
    keluar[7]=seper*((m1[6]*m1[1])-(m1[0]*m1[7]));
    keluar[8]=seper*((m1[0]*m1[4])-(m1[3]*m1[1]));
    mod(keluar,9);

}
///Menginverskan matriks 3x3
void invers3x3(float m1[],float keluar[]){
    /**
    IS: m1 adalah inputan array yang mempunyai length 9
    FS: keluar adalah array untuk output mempunyai length 9
    **/
    float seper=10/det3F(m1)*0.1;

    keluar[0]=seper*((m1[4]*m1[8])-(m1[7]*m1[5]));
    keluar[1]=seper*((m1[7]*m1[2])-(m1[1]*m1[8]));
    keluar[2]=seper*((m1[1]*m1[5])-(m1[4]*m1[2]));

    keluar[3]=seper*((m1[5]*m1[6])-(m1[8]*m1[3]));
    keluar[4]=seper*((m1[8]*m1[0])-(m1[2]*m1[6]));
    keluar[5]=seper*((m1[2]*m1[3])-(m1[5]*m1[0]));

    keluar[6]=seper*((m1[3]*m1[7])-(m1[6]*m1[4]));
    keluar[7]=seper*((m1[6]*m1[1])-(m1[0]*m1[7]));
    keluar[8]=seper*((m1[0]*m1[4])-(m1[3]*m1[1]));
}
///Perkalian matriks 3x3
void PerkalianMatrik3x3(float m1[],float m2[],float dat[]){
    /**
    IS: m1,m2 tidak kosong length 9
    FS: dat berisi hasil perkalian antara matrik m1 dan m2
    **/
    float a,b;
    int i,j,k=0,e=0;
    int op[3]={0,3,6};
    for(j=0;j<3;j++){
        for(i=0;i<3;i++){
            a=((m1[op[j]]*(m2[i]))+(m1[op[j]+1]*(m2[i+3]))+((m1[op[j]+2])*(m2[i+6])));
            dat[k]=a;
            k++;
            e++;
        }
    }
}
///Kalimat to Array of float
void KaltoArrFloat(char data[],float keluar[]){
    /**
    IS: string data tidak boleh kosong, array of float 'keluar' merupakan hasil terjemahan kalimat
    FS: Merubah kalimat menjadi array of float
    **/
    int i;
    for(i=0;i<strlen(data);i++){
        keluar[i]=TransHuruf(data[i]);
    }
}
///Input array satu dimensi
void input(float data[],int a){
    /**
    IS: array of float 'data' mungkin kosong,  variabel a adalah length dari array 'data'
    FS: array 'data' akan diberi nilai <float> oleh user
    **/
    int i;
    for(i=0;i<a;i++){
        printf("=> ");scanf("%f",&data[i]);
    }
}
