#include <stdio.h>

void scorefind(int maxscore){ //function to find the score
    //Create variables for each score with their respective values
    int ttd=8;
    int tdfg=7;
    int td=6;
    int fg=3;
    int sft=2;
    int score;
    //Nested for loop logic was assisted by ChatGPT to troubleshoot initial bugs, had the idea to initally use the nested for loops, but GPT helped with the logic to to the maxscore / by score
    for (int i = 0; i <= maxscore / ttd; i++) { // iterate i from 0 to the maximum possible 2 pt  + touchdowns
        for (int j = 0; j <= maxscore / tdfg; j++) { //iterate j from 0 to the maximum possible 1 point + touchdown
            for (int k = 0; k <= maxscore / td; k++) { //iterate k from 0 to the maximum possible touchdown
                for (int l = 0; l <= maxscore / fg; l++) { //iterate l from 0 to the maximum possible fg
                    for (int m = 0; m <= maxscore / sft; m++) { //iterate from m from 0 to the maximum possible safety
                        score = i * ttd + j * tdfg + k * td + l * fg + m * sft; //add up each possible score
                        if (score == maxscore) { //Only print these combinations out if the total adds up to the maximum score that we wanted
                            if (i > 0){ //if we use 2pt+TD
                                printf("%d TD + 2pt, ", i); //print amount used
                            } 
                            else { //if the score isn't used
                            printf("0 TD + 2pt, "); //print 0
                            }
                            if (j > 0){ //if a td+fg is used in the score calculation
                                printf("%d TD + FG, ", j); //print combination
                            }  
                            else{ //if score isn't used
                            printf("0 TD + FG, "); //print 0
                            }
                            if (k > 0) { //if just the touchdown used in calculation
                                printf("%d TD, ", k); //print combination
                            }
                            else { //if score isn't used
                            printf("0 TD, "); //print 0 
                            }
                            if (l > 0) { //if fg used in calculation
                                printf("%d FG, ", l); //output it
                            }
                            else { //if not used
                            printf("0 FG, "); //print 0
                            }
                            if (m > 0){ //if safety is used in calculation
                                printf("%d Safety\n", m); //print out combination, then a new line for the next one
                            }
                            else { //otherwise
                            printf("0 Safety\n"); //print 0 if not
                            }
                        }
                    }
                }
            }
        }
    }
    
}
int main(){
    int maximumscore; //create a score variable
    printf("Enter 0 or 1 to STOP\n"); //If user wants to stop, input those
    while (1) { //Until they enter 0/1
        printf("Enter the NFL score: "); //Prompt user to input
        scanf("%d", &maximumscore); //score input
        if (maximumscore <= 1) { //if less than equal to 1 (Impossible to print)
            break; //end loop
        }
        scorefind(maximumscore); //run the function
    }
    return 0;
}
