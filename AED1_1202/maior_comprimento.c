#include<stdio.h>
#include<string.h>

#define W_SIZE 100

int update_largest(int old_value, int new_value){
  if(new_value > old_value){
    return new_value;
  }
  return old_value;
}

int main(){
  
  char word[W_SIZE];
  int largest = 0, word_count = 0, index = 0;
  fgets(word, sizeof(word), stdin);

  while(word[index] != '\n'){

    if(word[index] == ' '){
      largest = update_largest(largest, word_count);
      word_count = 0;
    }else{
      word_count ++;
    }

    index ++;
  }
  largest = update_largest(largest, word_count);

  printf("%d", largest);
  
}