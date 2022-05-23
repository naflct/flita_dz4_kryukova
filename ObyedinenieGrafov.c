#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define S 101
#define F 101
#define X 101
#define C 200
#define G 200

int maximum(int a, int b)
{
    if (a > b)
        return a;
    else return b;
}

int main()
{
    int n = 0, n1 = 0, i, j, nmax;
    int A[S][S], B[F][F], SUM[X][X];
    char m[C], m1[G];
    FILE* graph1, * graph2;

    printf("Obyedineniye grafov\n\n");
    
    graph1 = fopen("graph1.txt", "r");
    fscanf(graph1, "%n", &m[0]);

    for (i = 0; (m[i] = fgetc(graph1)) != '\n'; i++) {
        if (m[i] != ' ' && m[i] != '\t')
            n++;
    }
    printf("razmer 1 grafa: %d\n", n);
    fclose(graph1);
    
    graph1 = fopen("graph1.txt", "r");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) {
            fscanf(graph1, "%d", &A[i][j]);
        }
    }

    fclose(graph1);

    graph2 = fopen("graph2.txt", "r");
    fscanf(graph2, "%n", &m1[0]);

    for (i = 0; (m1[i] = fgetc(graph2)) != '\n'; i++) {
        if (m1[i] != ' ' && m1[i] != '\t')
            n1++;
    }

    printf("razmer 2 grafa: %d\n\n", n1);
    fclose(graph2);

    graph2 = fopen("graph2.txt", "r");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n1; j++) {
            fscanf(graph2, "%d", &B[i][j]);
        }
    }
    fclose(graph2);

    nmax = n;
    if (n1 > n)
        nmax = n1;

    for (i = 0; i < nmax; i++)
    {
        for (j = 0; j < nmax; j++)
        {
            SUM[i][j] = 0;

            if (((A[i][j] == 0) || maximum(i,j)>=n) && ((B[i][j] == 0) || maximum(i, j) >= n1))
                SUM[i][j] = 0;
            else
                SUM[i][j] = 1;
        }
    }

    printf("Matritsa smezhnosti obyedinennogo grafa: \n");
    for (i = 0; i < nmax; ++i)
    {
        for (j = 0; j < nmax; ++j)
            printf("%d\t", SUM[i][j]);
        printf("\n");
    }
}