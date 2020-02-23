#include <stdio.h>
#include <stdbool.h>

char verify_matriz(int size, int matriz[][size]){
  bool find_value_line=false, find_value_column=false;

  for(int x=0; x < size; x ++){
    for(int y=0; y < size; y ++){

      if(matriz[x][y]){
        if(find_value_line) return 0;
        find_value_line = true;
      }

      if(matriz[y][x]){
        if(find_value_column) return 0;
        find_value_column = true;
      }
    }
    find_value_line = false;
    find_value_column = false;
  }

  return 1;
}

int main() {
  
  int matriz_size = 0;
  scanf("%d", &matriz_size);
  int matriz[matriz_size][matriz_size];
  
  //le matriz
  for(int line=0; line < matriz_size; line ++){
    for(int column=0; column < matriz_size; column ++){
      scanf("%d", &matriz[line][column]);
    }  
  }
  printf("%d", verify_matriz(matriz_size, matriz));
  
}