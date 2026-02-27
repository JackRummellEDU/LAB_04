

#include <stdio.h>

int main(){
    /*
        Score Values
        A - 8 pts   (Touchdown + 2)
        B - 7 pts   (Touchdown + 1)
        C - 6 pts   (Touchdown)
        D - 3 pts   (Field Goal)
        E - 2 pts   (Safety)
    */
    const int A = 8, B = 7, C = 6, D = 3, E = 2;
    int score;

    // Promt the user for a score
    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
    scanf("%d", &score);

    // Calculate possible scores
    while(score > 1)
    {
        int a_cnt = 0;
        while(a_cnt*A <= score)
        {
            int b_cnt = 0;
            while(a_cnt*A + b_cnt*B <= score)
            {
                int c_cnt = 0;
                while(a_cnt*A + b_cnt*B + c_cnt*C <= score)
                {
                    int d_cnt = 0;
                    while(a_cnt*A + b_cnt*B + c_cnt*C + d_cnt*D <= score)
                    {
                        int e_cnt = 0;
                        while(a_cnt*A + b_cnt*B + c_cnt*C + d_cnt*D + e_cnt*E <= score)
                        {
                            // If score totals are valid, print data
                            if(a_cnt*A + b_cnt*B + c_cnt*C + d_cnt*D + e_cnt*E == score)
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", a_cnt, b_cnt, c_cnt, d_cnt, e_cnt);
                            e_cnt++;
                        }
                        d_cnt++;
                    }
                    c_cnt++;
                }  
                b_cnt++;
            }
            a_cnt++;
        }

        // Prompt the user for another score
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
    }

    return 0;
}