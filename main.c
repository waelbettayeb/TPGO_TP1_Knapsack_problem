#include <stdio.h>
#include <stdbool.h>

struct Data{
    bool added;
    unsigned int weight;
    unsigned int value;
}typedef Data;

unsigned int length = 4;

Data data[] = {{0, 3 ,2}, {0, 5, 4}, {0, 1, 2}, {0, 2, 3}};

int max(int a,int b){
    return (a > b ? a : b);
}
void printDataVector(Data* data, unsigned int length){
    unsigned int nbObjets, totalWeight,totalValue;
    //init
    nbObjets = 0;
    totalWeight = 0;
    totalValue = 0;
    //printing
    for(int i = 0; i < length ;i++){
        if(data[i].added){
            nbObjets += 1;
            totalWeight += data[i].weight;
            totalValue += data[i].value;

        }
        printf("data[%d] : {\t%d \t%d \t%d}\n", i, data[i].added, data[i].weight, data[i].value);
    }
    //printing total
    printf("Number of objects = %d\nTotal weight = %d\nTotal value = %d\n", nbObjets, totalWeight, totalValue);

}
unsigned int f(unsigned int n,unsigned int vmax){

    unsigned int f1, f2;
    if(n == 0)
        return 0;
    else{
        f1 = f(n-1,vmax) ;
        f2 = f(n-1, vmax - data[n-1].weight ) + data[n-1].value ;
        if(f1 > f2)
            return f1;
        else {
            data[n-1].added = 1;
            return  f2 ;
        }
    }
}

int main() {

    int val = f(length, 7);
    printf("La value optimale : %d\n",val);

    printDataVector(data, length);
}