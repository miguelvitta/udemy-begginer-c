#include <stdio.h>

#define MONTHS 12
#define YEARS 5

int main()
{
    float rainfall[YEARS][MONTHS] = {
        {2.4, 6.5, 0.7, 6.1, 4.1, 11.4, 10.3, 9.4, 9.8, 9.0, 5.3, 0.6},
        {1.2, 6.4, 1.0, 8.5, 3.9, 12.9, 11.7, 8.3, 7.9, 5.7, 7.8, 1.4},
        {3.1, 6.9, 0.8, 7.9, 5.9, 10.1, 10.4, 7.7, 8.0, 6.9, 4.5, 1.9},
        {3.9, 6.0, 0.9, 8.0, 3.5, 10.7, 9.5, 9.4, 9.3, 4.8, 5.8, 2.1},
        {4.1, 6.1, 1.1, 6.1, 4.1, 9.8, 8.9, 8.5, 9.6, 7.9, 6.7, 1.8},
    };
    float totalRainfall = 0.0;
    float averageYearlyRainfall = 0.0;
    float averageMonthlyRainfall = 0.0;

    printf("\t YEAR\t\tRAINFALL(inches)\n");
    for(int i = 0; i < YEARS; i++) {
        averageYearlyRainfall = 0.0;
        for(int j = 0; j < MONTHS; j++) {
            averageYearlyRainfall += rainfall[i][j];
        }
        printf("\t%5d \t%15.1f\n", 2020 + i, averageYearlyRainfall);
        totalRainfall += averageYearlyRainfall;
    }
    printf("\n\tThe total rainfall was %.1f and the yearly average is %.1f inches.\n\n", totalRainfall, totalRainfall / YEARS);

    printf("\tMONTHLY AVERAGES: \n\n");
    printf("\tJan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDez\n\t");
    for(int i = 0; i < MONTHS; i++) {
        averageMonthlyRainfall = 0.0;
        for(int j = 0; j < YEARS; j++) {
            averageMonthlyRainfall += rainfall[j][i];
        }
        printf("%4.1f\t", averageMonthlyRainfall);
    }
    printf("\n");

    return 0;
}
