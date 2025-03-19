#include <stdio.h>
#include <stdlib.h>

struct names {
    char first[20];
    char second[20];
};

struct pnames {
    char* first;
    char* second;
};

int main() {
    struct names veep = {"Talia", "Summers"};
    struct pnames treas = {"Brad", "Fallingjaw"};

    printf("%s\n%s\n", veep.first, veep.second);
    printf("%s\n%s\n", treas.first, treas.second);


    return 0;
}

