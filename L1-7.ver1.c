// L1-7 谁是赢家
// Language: C

#include <stdio.h>
#include <stdbool.h>

int main(){
    int vote_audience_count_a, vote_audience_count_b;
    int vote_professor[3];

    scanf("%d %d", &vote_audience_count_a, &vote_audience_count_b);
    for(int i = 0;i < 3;i++){
        scanf("%d", vote_professor + i);
    }

    bool professor_at_least_one_a = false, professor_at_least_one_b = false;
    bool professor_all_a = true, professor_all_b = true;
    int professor_count_a = 0, professor_count_b = 0;
    for(int i = 0;i < 3;i++){
        if(vote_professor[i] == 0){
            professor_at_least_one_a = true;
            professor_all_b = false;
            professor_count_a++;
        }else{
            professor_at_least_one_b = true;
            professor_all_a = false;
            professor_count_b++;
        }
    }

    printf("The winner is ");
    if((vote_audience_count_a > vote_audience_count_b
                && professor_at_least_one_a)
            || professor_all_a){
        printf("%c: %d + %d", 'a',
                vote_audience_count_a, professor_count_a);
    }else{
        printf("%c: %d + %d", 'b',
                vote_audience_count_b, professor_count_b);
    }

    return 0;
}
