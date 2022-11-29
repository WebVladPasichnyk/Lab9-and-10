#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct input
{
    int N = 100;
    float T = 0.02;
    float h = T / N;
    float w = 2 * 3.14159 / T;
    float num = 100;
};
float signal (float t)
{
   return sin(t) * t;
}

int main()
{
    struct input inp;
    FILE* f = fopen("sign.txt", "w+");
    float s[inp.N], t[inp.N];
    for (int i = 0; i < inp.N; i++)
    {
        t[i] = i * inp.h;
        s[i] = signal(t[i]);
        fprintf(f, "%f\n", s[i]);
    }

    FILE* a0_file = fopen("a0.txt", "w+");
    float sum = 0, a0 = 0;
    for (int i = 0; i < inp.N; i++)
    {
        sum += signal(t[i]);
        a0 = 2 * inp.h * sum / inp.T;
        fprintf(a0_file, "%f\n", a0);
    }
    FILE* ak_file = fopen("ak.txt", "w+");
    FILE* bk_file = fopen("bk.txt", "w+");
    float a[inp.N], b[inp.N];
    for (int k = 1; k <= inp.num; k++)
        {
            sum = 0;
            for (int i = 0; i < inp.N; i++)
            {
                sum += signal(t[i]) * cos(k * inp.w * t[i]);
                a[k] = 2 * inp.h * sum / inp.T;
            }
            fprintf(ak_file, "%f\n", a[k]);
            sum = 0;
            for (int i = 0; i < inp.N; i++)
            {
                sum += signal(t[i]) * sin(k * inp.w * t[i]);
                b[k] = 2 * inp.h * sum / inp.T;
            }
            fprintf(bk_file, "%f\n", b[k]);

        }
    FILE* sum_file = fopen("sum.txt", "w+");
    FILE* res_file = fopen("res.txt", "w+");
    float sm;
    for(int i = 0; i < inp.N; i++)
    {
        sm = a0/2;
        t[i] = i * inp.h;
        for(int k = 1; k <=inp.num; k++)
        {
            sm += a[k] * cos(k * inp.w * t[i]) + b[k] * sin(k * inp.w * t[i]);

        }
        fprintf(sum_file, "%f %f\n", t[i], sm);
        fprintf(res_file, "%f\n", sm);

    }
    fclose(bk_file); fclose(ak_file); fclose(a0_file); fclose(sum_file);
    return 0;
}
