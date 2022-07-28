#include "Cabecalho.h"
/***
static long int p,q,n,y,e,d,i,j,flag;
static char oMsg; // Mensagem original
static char eMsg; // Mensagem encriptada
static char dMsg; // Mensagem decriptada
static bool isprime = true;

bool prime(long int num){
    for(int i = 2; i<=(num/2);i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
long int calculateD(long int e){
    long int k = 1;
    while(1){
        k = k + y;
        if(k % e == 0){
            return(k/e);
        }
    }
}

void calculateE(){
    for(j=2;j<y;j++){
        if(y%j==0)
            continue;
        isprime = prime(j);
        if(isprime && j!= p && j!=q){
            e = j;
            flag = calculateD(e);
            if(flag>0){
                d = flag;
                break;
            }
        }
    }
}

void criptografar(string line){

}
***/
