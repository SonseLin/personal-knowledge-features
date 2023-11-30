#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int memofib(int n, int *data)
{
    if (data[n] != 0)
    {
        return data[n];
    }
    int memo;
    if (n <= 1)
    {
        memo = n;
    }
    else
    {
        memo = memofib(n - 1, data) + memofib(n - 2, data);
    }
    data[n] = memo;
    return memo;
}

int main()
{
    int mode, testing, print_values_mode;
    printf("Input 3 numbers: Mode(1 memo, 2 based, 3 comparison), Number of cases and should values be printed\n");
    scanf("%d %d %d", &mode, &testing, &print_values_mode);
    printf("%d test cases\n", testing);
    if (mode == 1)
    {
        printf("You have chosen memo fib\n");
        clock_t start = clock();
        int *arr = calloc(testing, sizeof(int));
        for (int i = 0; i < testing; i++)
        {
            if (print_values_mode)
                printf("%i is %d\n", i, memofib(i, arr));
            else
                memofib(i, arr);
        }
        free(arr);
        clock_t end = clock();
        printf("Time spent on memo fib for %d values is %lf", testing, (double)(end - start) / CLOCKS_PER_SEC);
    }
    else if (mode == 2)
    {
        printf("You have chosen BASED fib\n");
        clock_t start = clock();
        for (int i = 0; i < testing; i++)
        {
            if (print_values_mode)
                printf("%i is %d\n", i, fib(i));
            else
                fib(i);
        }
        clock_t end = clock();
        printf("Time spent on memo fib for %d values is %lf", testing, (double)(end - start) / CLOCKS_PER_SEC);
    }
    else if (mode == 3)
    {
        double time_limit;
        printf("For extra comparison mode input time_limit to cancel infinity loop:\n");
        scanf("%lf", &time_limit);
        clock_t start_memo = clock();
        clock_t start_based = clock();
        clock_t memo_point = start_memo;
        clock_t based_point = start_based;
        int new = 1;
        while (new < testing)
        {
            // calculating memo time;
            start_memo = clock();
            int *arr = calloc(testing, 4);
            for (int i = 0; i < new; i++)
            {
                if (print_values_mode)
                    printf("%i is %d\n", i, memofib(i, arr));
                else
                    memofib(i, arr);
            }
            memo_point = clock();
            double diff_memo = (double)(memo_point - start_memo) / CLOCKS_PER_SEC;
            // calculating based time;
            start_based = clock();
            for (int i = 0; i < new; i++)
            {
                if (print_values_mode)
                    printf("%i is %d\n", i, fib(i));
                else
                    fib(i);
            }
            based_point = clock();
            double diff_based = (double)(based_point - start_based) / CLOCKS_PER_SEC;
            printf("\n\nfor %i values\nMemo costs: %lf seconds;\nBased costs: %lf seconds;\nDifference is %.1lf\n", new, diff_memo, diff_based, diff_based / diff_memo);
            new ++;
            if (diff_based > time_limit || diff_memo > time_limit)
            {
                int s = 1;
                if (diff_based > diff_memo)
                    s = 0;
                if (s == 0)
                {
                    printf("Time for fib based(%.1lf) exceeds time limit setted by %.1lf seconds", diff_based, time_limit);
                }
                else
                {
                    printf("Time for fib memo(%.1lf) exceeds time limit setted by %.1lf seconds", diff_memo, time_limit);
                }
                break;
            }
        }
    }
    return 0;
}