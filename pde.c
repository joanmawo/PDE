#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void condicionesIniciales(float *u_inicial, int n_pasos, int delta_x);
void iteracion(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float r);
void iteracionTemporal(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float r, int n_tiempo);

int main(){

  FILE *datos.txt;
  int n_pasos = 1000;
  int n_tiempo = 100;
  float delta_x = 0.001;
  float delta_t = 0.0005;
  float c = 1.0;
  float r = c*delta_t/delta_x;
  int i = 0;
  int j = 0;

  float *u_inicial;
  float *u_pasada;
  float *u_ahora;
  float *u_nueva;

  u_inicial = malloc(n_pasos*sizeof(float));  
  u_pasada = malloc(n_pasos*sizeof(float));
  u_ahora = malloc(n_pasos*sizeof(float));
  u_nueva = malloc(n_pasos*sizeof(float));

if(!u_inicial || !u_pasada || !u_ahora || !u_nueva){
    printf("Problema con memoria");
    exit(1);
  }

 condicionesIniciales(u_inicial, n_pasos, delta_x);

 iteracionTemporal(u_inicial, u_pasada, u_ahora, u_nueva, n_pasos, r, n_tiempo);

 datos.txt = fopen('datos.txt', 'w');

 fprintf('datos.txt', '%f %f /n', x, u); //NO ESTA LISTO!!!!!!

}

void condicionesIniciales(float *u_inicial, int n_pasos, int delta_x){
  //Se fijan las condiciones iniciales de la ecuacion de onda
  
  int i = 0;
  for(i = 0; i < n_pasos; i ++){
    u_inicial[i] =  exp(-((delta_x*i - 0.3)*(delta_x*i - 0.3))/0.01);

  } 
}

void iteracion(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float r){
  
  int i = 0;
u_inicial[0] = 0.0;
u_inicial[n_pasos - 1] = 0.0;

//Se copia u_inicial en u_nueva
// for(i = 0; i < n_pasos; i ++){
//    u_nueva[i] = u_inicial[i];
//}


//Se construye u_nueva
 for(i = 0; i < n_pasos; i ++){
   u_nueva[i] = u_inicial[i] + ((r*r)/2.0)*(u_inicial[i+1] - 2.0*u_inicial[i] + u_inicial[i-1]);
 }

for(i = 0; i < n_pasos; i ++){
   u_pasada[i] = u_inicial[i];
 }

for(i = 0; i < n_pasos; i ++){
  u_ahora[i] = u_nueva[i];
}

}

void iteracionTemporal(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float r,  int n_tiempo){

  int j = 0;
  for(j = 0; j < n_tiempo; j ++){

    iteracion(u_inicial, u_pasada, u_ahora, u_nueva,  n_pasos, r);

  }

}
