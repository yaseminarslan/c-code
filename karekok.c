# include<stdio.h> 
# include<math.h> 

float karekok ( int sayi );

int main(){
    int sayi;
    float a; 
    printf("Bir sayi giriniz:");
    scanf("%d", &sayi);
    if(sayi>0){
        a = karekok(sayi);
        printf("%.15f\r\n", a);
        printf("%.15f\r\n",sqrt(sayi)); 
        }
    else
    {
        printf("0dan baska sayi giriniz:");
    }
    

    return 0;
}

float karekok ( int sayi ){
    float guess = (sayi/2.0);
    int i;
    for(i=0; i<6; i++){
        guess = 0.5 * (guess+(sayi/guess));
    }
    return guess;
}
