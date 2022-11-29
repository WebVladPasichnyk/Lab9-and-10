#include <stdio.h>
#include <math.h>

int main()
{
    FILE* f = fopen("res.txt", "r");
    float s[100]; char str [15];
    for(int i = 0; i < 100; i++)
    {
        fgets(str, 15, f);
        s[i] = atof (str);
    }
    float nmin = s[0], nmax = s[0], imin, imax;
    for(int i = 0; i < 100; i++)
    {
        if(s[i] > nmax)
        {
            nmax = s[i];
            imax = i;
        }
        if(s[i] < nmin)
        {
            nmin = s[i];
            imin = i;
        }
    }
    printf("nmin = %f, imin = %i, \nnmax = %f, imax = %i", nmin, (int)imin, nmax, (int)imax);
    fclose(f);
}
