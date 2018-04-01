// L1-2 倒数第N个字符串
// Language: C

#include <stdio.h>

int main(){
    int length, reverse_order;
    scanf("%d %d", &length, &reverse_order);

    int digits[length];
    for(int i = 0;i < length;i++){
        digits[i] = 26;
    }

    reverse_order--;
    int pos = length - 1;
    while(pos >= 0 && reverse_order > 0){
        int digit = reverse_order % 26;
        digits[pos] -= digit;
        reverse_order /= 26;
        pos--;
    }

    for(int i = 0;i < length;i++){
        putchar('a' + digits[i] - 1);
    }

    return 0;
}
