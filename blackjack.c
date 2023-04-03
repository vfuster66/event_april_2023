#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sum = 0;
    int aces = 0;
    int max_sum = 0;
    char *cards = argv[1];
    int len = strlen(cards);

    for (int i = 0; i < len; i++) {
        char card = cards[i];

        if (card >= '2' && card <= '9') {
            sum += card - '0';
        } else if (card == 'T' || card == 'J' || card == 'Q' || card == 'K') {
            sum += 10;
        } else if (card == 'A') {
            aces++;
            sum += 11;
        }
    }

    max_sum = sum;

    while (aces > 0 && max_sum > 21) {
        max_sum -= 10;
        aces--;
    }

    if (max_sum == 21 && len == 4) {
        printf("Blackjack!\n");
    } else {
        printf("%d\n", max_sum);
    }

    return 0;
}

