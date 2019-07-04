/*sorting algoitmalari karsilastirmalari */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void insertionsort(int d[], int size);
void selectionsort(int d[], int size);
void randomize_array(int seed, int d[], int size, int maxnumber);
void print_array(int d[], int size);
void bubblesort(int d[], int size);

int main(){
    int size=SIZE, maxnumber=20;
    int d[SIZE+1];
    // randomize_array(time(NULL) , d, size, maxnumber);
    // print_array(d, size);
    // insertionsort(d,size);
    // print_array(d, size);
    // printf("\r\n\r\n");
    // randomize_array(time(NULL) , d, size, maxnumber);
    // print_array(d, size);
    // selectionsort(d, size);
    // print_array(d, size);
    // printf("\r\n\r\n");    
    // randomize_array(time(NULL) , d, size, maxnumber);
    // print_array(d, size);
    // bubblesort(d, size);
    // print_array(d, size);
    // printf("\r\n\r\n");

    clock_t t;
    double time_taken;

    randomize_array(time(NULL) , d, size, maxnumber);
    
    t = clock(); 
    bubblesort(d, size);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("bubblesort =  %f\n", time_taken); 

    randomize_array(time(NULL) , d, size, maxnumber);
    
    t = clock(); 
    selectionsort(d, size);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("selectionsort =  %f\n", time_taken); 

    randomize_array(time(NULL) , d, size, maxnumber);

    t = clock(); 
    insertionsort(d, size);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("insertionsort =  %f\n", time_taken); 

}



void randomize_array(int seed, int d[], int size, int maxnumber){
    int i;
    srand(seed);
    for (i=0; i<=size; i++){
        d[i] = rand() % maxnumber;
    }
}

void print_array(int d[], int size){
    for(int i=0; i<size; i++){        
        if( i%10 == 0 ){
            printf("\r\n");
        }

        printf("%4d",d[i] );
    }
    printf("\r\n");
}

void bubblesort(int d[],int size){
    int hold;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size; j++){
            if(d[j]>d[j+1]){
                hold= d[j];
                d[j]=d[j+1];
                d[j+1]= hold;
            }
        }
    }
}    

void selectionsort(int d[], int size){
    int min,i, j, gecici, minid;
    for(int i=0; i<size ;i++){
        min = d[i];
        for(int j=i; j<size; j++){
            if(d[j]<min){
                min = d[j];
                minid=j;
            }
        }
        gecici = d[i];
        d[i] = min;
        d[minid] = gecici;
    }
}

void insertionsort(int d[], int size){
    int temp,i,j,k;

    for(int i=0; i<size ;i++){
        for(int j=0; j<i; j++){
            if(d[i] < d[j]){
                // i degerini yedekle
                temp = d[i];
                // i-j arasini saga kaydir
                for(k=i; k>j; k--) {
                    d[k] = d[k-1];
                }
                // j yerine i yaz
                d[j] = temp;
            }
        }
    }
}
