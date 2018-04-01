// L1-7 谁是赢家
// Language: C

#include <stdio.h>
#include <stdbool.h>

int main(){
    int vote_audience_count_a, vote_audience_count_b;
    int vote_professor[3];

    scanf("%d %d", &vote_audience_count_a, &vote_audience_count_b);

    bool professor_at_least_one[2] = {false, false};
    bool professor_all[2] = {true, true};
    int professor_count[2] = {0, 0};
    for(int i = 0;i < 3;i++){
        int professor_vote;
        scanf("%d", &professor_vote);
        professor_at_least_one[professor_vote] = true;
        professor_all[!professor_vote] = false;
        professor_count[professor_vote]++;
    }

    int winner = 0;
    if(!((vote_audience_count_a > vote_audience_count_b
                    && professor_at_least_one[winner])
                || professor_all[winner])){
        winner = 1;
    }
    printf("The winner is %c: %d + %d", 'a' + winner,
            winner == 0 ? vote_audience_count_a : vote_audience_count_b,
            professor_count[winner]);

    return 0;
}
