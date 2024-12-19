#include <stdio.h>

int main()
{
    short int a = 0;
    int b = 0;
    long int c = 0;
    long long int d = 0;
    char e = '0';
    float f = 0.0;
    double g = 0.0;
    long double h = 0.0;

    size_t as = sizeof(a);
    size_t bs = sizeof(b);
    size_t cs = sizeof(c);
    size_t ds = sizeof(d);
    size_t es = sizeof(e);
    size_t fs = sizeof(f);
    size_t gs = sizeof(g);
    size_t hs = sizeof(h);

    printf("The size of each data type is:\nshort int: %zd\nint: %zd\nlong int: %zd\nlong long int: %zd\nchar: %zd\nfloat: %zd\ndouble: %zd\nlong double: %zd\n", as, bs, cs, ds, es, fs, gs, hs);



    return 0;
}
