/*One day three best friends Petya, Vasya and Tonya decided to form a team and take part in programming contests. Participants are usually offered several problems during programming contests. Long before the start the friends decided that they will implement a problem if at least two of them are sure about the solution. Otherwise, the friends won't write the problem's solution.

This contest offers n problems to the participants. For each problem we know, which friend is sure about the solution. Help the friends find the number of problems for which they will write a solution.

Input
The first input line contains a single integer n (1 ≤ n ≤ 1000) — the number of problems in the contest. Then n lines contain three integers each, each integer is either 0 or 1. If the first number in the line equals 1, then Petya is sure about the problem's solution, otherwise he isn't sure. The second number shows Vasya's view on the solution, the third number shows Tonya's view. The numbers on the lines are separated by spaces.

Output
Print a single integer — the number of problems the friends will implement on the contest.*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, k, l, m;
    int p = 0;
    // no of problems
    scanf("%d", &n);
    printf("\n");
    int opinions[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            opinions[i][j] = 0;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            scanf("%d", &opinions[k][l]);
            if (opinions[k][l] != 0 && opinions[k][l] != 1)
            {
                exit(0);
            }
        }
        printf("\n");
    }
    for (m = 0; m < n; m++)
    {
        if ((opinions[m][0] == opinions[m][1] || opinions[m][1] == opinions[m][2] || opinions[m][0] == opinions[m][2]))
        {
            if ((opinions[m][0] && opinions[m][1] || opinions[m][1] && opinions[m][2] || opinions[m][0] && opinions[m][2]) == 1)
            {
                p++;
            }
        }
    }
    printf("%d", p);

    return 0;
}