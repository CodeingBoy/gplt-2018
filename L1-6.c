// L1-6 福到了
// Language: C

#include <stdio.h>
#include <stdbool.h>

int main(){
    char symbol = getchar();
    int length;
    scanf("%d", &length);

    while(getchar() != '\n')
        ;

    char matrix[length][length];

    for(int i = 0;i < length;i++){
        for(int j = 0;j < length;j++){
            matrix[i][j] = getchar();
            if(matrix[i][j] != ' '){
                matrix[i][j] = symbol;
            }
        }
        getchar();
    }

    bool mirrored = true;
    for(int i = 0;i < length;i++){
        int reverse_row = length - 1 - i;
        for(int j = 0;j < length;j++){
            int reverse_col = length - 1 - j;
            if(matrix[i][j] != matrix[reverse_row][reverse_col]){
                mirrored = false;
                break;
            }
        }
        if(!mirrored){
            break;
        }
    }

    if(mirrored){
        printf("bu yong dao le\n");
    }

    for(int i = 0;i < length;i++){
        int reverse_row = length - 1 - i;
        for(int j = 0;j < length;j++){
            int reverse_col = length - 1 - j;
            putchar(matrix[reverse_row][reverse_col]);
        }
        putchar('\n');
    }

    return 0;
}
