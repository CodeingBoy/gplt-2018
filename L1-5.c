// L1-5 电子汪
// Language: C

#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    int count = a + b;
    while(count--){
        printf("Wang!");
    }

    return 0;
}
