#include <stdio.h>
#include <stdbool.h>

bool eh_traingular(int numero){
    int result = 0, pont = 0;
    while(result < numero){
        result = (pont + 1)*(pont + 2)*(pont + 3);

        if(result == numero)
            return true;
        pont ++;
    }
    return false;

}

int main(){
    for(int i = 1; i <= 1000; i++){
        if(eh_traingular(i))
            printf("%d ", i);
    }
    return 0;
}
