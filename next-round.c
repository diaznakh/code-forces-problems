/*"Contestant who earns a score equal to or greater than the k-th place finisher's score will advance to the next round, as long as the contestant earns a positive score..." — an excerpt from contest rules.

A total of n participants took part in the contest (n ≥ k), and you already know their scores. Calculate how many participants will advance to the next round.

Input
The first line of the input contains two integers n and k (1 ≤ k ≤ n ≤ 50) separated by a single space.

The second line contains n space-separated integers a1, a2, ..., an (0 ≤ ai ≤ 100), where ai is the score earned by the participant who got the i-th place. The given sequence is non-increasing (that is, for all i from 1 to n - 1 the following condition is fulfilled: ai ≥ ai + 1).

Output
Output the number of participants who advance to the next round.*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, k, b;
    int p = 0;
    scanf("%d %d", &n, &k);
    if (k < 1 || k > 50 || k > n)
    {
        exit(0);
    }
    int points[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &points[i]);
        if (points[i] < 0 || points[i] > 100)
        {
            exit(0);
        }
    }
    b = k - 1;
    for (int j = 0; j < n; j++)
    {
        if (points[j] >= points[b])
        {
            if (points[j] == 0)
            {
                p--;
            }
            p++;
        }
    }
    printf("%d", p);

    return 0;
}