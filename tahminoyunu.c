// tahmin oyunu
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rndm(int a);
int sayi[4];

int main(){
    int p=0,n=0;
    int counter;
    int binb,yb,ob,bb;
    int abinb,ayb,aob,abb;
    int tahmin=0;
    int thmn[4];
    rndm(time(NULL));

    while(p != 4){
        p=0;
        n=0;
        printf("\r\n4 basamakli tahmininizi giriniz:\r\n");
        scanf("%d", &tahmin);
        while(tahmin <= 999 || tahmin >= 10000){
            printf("hatali girdi\r\n");
            scanf("%d", &tahmin);
        }
        thmn[0]= tahmin/1000;
        thmn[1] = (tahmin/100)%10;
        thmn[2] = (tahmin/10) % 10;
        thmn[3]=(tahmin%10);
        
        for(int i=0; i<4; ++i){
            for(int j=0; j<4; ++j ){
                if(thmn[i]==sayi[j]){
                    if(i==j){
                        ++p;
                    }
                    else
                    {
                        --n;
                    }
                    
                }
            }
        }
        printf("%d,%d", p, n);
    }
    printf("Tebrikler Tesekkurler!");
}

void rndm(int a){
    int binb, bb, yb, ob;
    srand(a); 
    while(binb ==0){
        binb = rand()%9;
    }
    bb = rand()%9;
    while (binb==bb){
        binb =rand()%9;
    }
    yb = rand()%9;
    while(binb == yb || bb== yb){
        yb = rand()%9;
    }
    ob = rand()%9;
    while(ob == binb || ob== bb || ob == yb){
        ob = rand()%9;
    }
    sayi[0]= binb;
    sayi[1]= yb;
    sayi[2]= ob;
    sayi[3]= bb;
}
    