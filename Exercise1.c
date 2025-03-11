#include <stdio.h>

void scorefind(score){
    
}
int main(){
    int score;
    printf("Enter 0 or 1 to STOP\n");
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }
        scorefind(score);
    }
    return 0;
}
