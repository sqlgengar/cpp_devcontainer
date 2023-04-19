#include<stdio.h>
#include<stdlib.h>
#define m 20

void rellenar(int [20]);
int numeros_primos(int tes);
void mostrar(int x[20], int a);
void ordenar(int x[20]);
int comparar( const void *_a,const void *_b);

int main(){
int i,j=0,a=0,x;
int vec_ori[m];
int vec_pri[m];
int vec_comp[m];
rellenar(vec_ori);
for(i=0;i<19;i++){
    x=numeros_primos(vec_ori[i]);
        if(x==0){
            vec_pri[j]=vec_ori[i];
            j++;
        }else{
            vec_comp[a]=vec_ori[i];
            a++;
        }
}
printf("Vec original: \n");
mostrar(vec_ori,m);
printf("Vec primos: \n");
mostrar(vec_pri,j);
printf("Vec compuestos: \n");
mostrar(vec_comp,a);

ordenar(vec_ori);
printf("vector ordenado: \n");
mostrar(vec_ori,m);

return 0;
}

void rellenar(int vec_ori[20]){
    int i;
    time_t t;
    srand((unsigned) time(&t));
    for(i=0;i<19;i++){
        vec_ori[i]=rand() % 200;
    }
}

int numeros_primos(int tes){
    int i;
    if(tes == 0 || tes == 1 || tes == 4){
        return 1;
    }
    for(i=2;i<100;i++){
        if(tes%i == 0){
            return 1;
        }else{
            return 0;
        }
    }
}

void mostrar(int x[20], int a){
    int i;
    for(i=0;i<a;i++){
        printf("%d. %d\n",i,x[i]);
    }
}

void ordenar(int x[20]){
    qsort(x,20,4,&comparar);
}

int comparar( const void *_a,const void *_b){
    int *a,*b;
    a=(int *)_a;
    b=(int *)_b;

return (*b-*a);
}
