// L1-3 打折
// Language: C

#include <stdio.h>

int main(){
    int price, discount;
    scanf("%d %d", &price, &discount);

    printf("%.2f", price * (double)discount / 10);

    return 0;
}
