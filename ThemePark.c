#include <stdio.h>
#include <stdlib.h>

int p[5];
int v[5], i;
float a[3];
float rideprofit;
int max = 0;
float b[5];
int temp1;
int temp2;
int temp3;
void prize(int i)
{
    scanf("%d", &p[i]);
}
void visitors(int i)
{
    scanf("%d", &v[i]);
}

float profit(int i)
{

    rideprofit = v[i] * p[i];

    return rideprofit;
}

int main()
{

    printf(" Prizes of each rides\n\n");

    for (int i = 0; i < 5; i++)
    {

        printf("prize of ride %d: Rs", i + 1);

        prize(i);
    }

    printf("\n\n");

    for (int i = 0; i < 5; i++)
    {

        b[i] = 0;
    }

    int days = 1;

    while (days <= 3)
    {

        printf(" PROFIT ANALYSIS OF DAY %d\n\n", days);

        for (int i = 0; i < 5; i++)
        {
            printf("Tickets sold Of Ride %d is: ", i + 1);

            visitors(i);
        }

        printf("\n");

        float totalprofit = 0;

        for (int i = 0; i < 5; i++)
        {

            totalprofit += v[i] * p[i];
        }

        printf("\n\n");

        max = 0;

        for (int i = 0; i < 5; i++)
        {

            if (profit(i) > max)
            {

                max = profit(i);

                temp1 = i;
            }
        }

        float per1 = (profit(temp1) / totalprofit) * 100;

        printf("> Total profit of day %d is: %f Rs.\n", days, totalprofit);

        printf("> The most profitable ride is: %d.\n", temp1 + 1);

        printf("> Total profit from the ride %d is: %fRs.\n", temp1 + 1, profit(temp1));

        printf("> The ride %d is contribute %f percentage in the total profit of the day.\n", temp1 + 1, per1);

        printf("\n\n");

        a[days - 1] = totalprofit;
        for (int i = 0; i < 5; i++)
        {

            b[i] += profit(i);
        }

        days++;
    }

    max = 0;

    float sum = 0;

    for (int i = 0; i < 3; i++)
    {

        sum += a[i];

        if (a[i] > max)
        {

            max = a[i];

            temp2 = i;
        }
    }

    max = 0;

    for (int i = 0; i < 5; i++)
    {

        if (b[i] > max)
        {

            max = b[i];

            temp3 = i;
        }
    }

    printf(" 3 DAYS PROFIT REPORT OF THE THEME PARK\n\n");

    float per2 = (b[temp3] / sum) * 100;

    printf("> Total profit of  THREE DAYS is %f Rs.\n", sum);
    printf("> Record breaking day of the given days is %d day.\n", temp2 + 1);

    printf("> The most profitable ride of this data is ride no.%d.\n", temp3 + 1);

    printf("> Total profit from the ride %d in this  is %f Rs.\n", temp3 + 1, b[temp3]);

    printf("> Ride %d contributed %f percentage in the total profit of the week.\n", temp3 + 1, per2);

    return 0;
}
