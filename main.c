#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

int main()
{
    int signaalBoot;
    int wegverkeer;
    int motorBrug = 0;
        // motorBrug = 0 -> Brug staat stil
        // motorBrug = 1 -> Brug gaat omhoog
        // motorBrug = -1 -> Brug gaat omlaag
    int sensorOpen = 0;
        // sensor die checkt of de brug volledig open is
    int sensorDicht = 1;
        // sensor die checkt of de brug volledig dicht is
    int hoogte = 0;
    int brugAan = 1;

    void sensorChecker()
    {
        while(sensorDicht) // Als brug dicht is
        {
            printf("Boot signaal? 1 of 0: ");
            scanf("%d",&signaalBoot);
            if(!signaalBoot)
            {
                printf("Dicht\n");
                break;
            }
            printf("Wegverkeer? 1 of 0: ");
            scanf("%d",&wegverkeer);

            // Check voor boten en wegverkeer
            if(signaalBoot && !wegverkeer)
            {
                sensorDicht = 0;
                motorBrug = 1;
                break;
            }


            printf("Dicht\n");

        }

        while(motorBrug == 1) // Als brug aan het openen is
        {
            // Stuur motor aan

            printf("Aan het openen\n");
            hoogte++;
            sleep(1);
            if(hoogte == 5)
            {
                motorBrug = 0;
                sensorOpen = 1;
                break;
            }
        }


        while(sensorOpen) // Als brug open is
        {
            // Check of boot voorbij is

            printf("Open\n");
            printf("Boot signaal? 1 of 0: ");
            scanf("%d",&signaalBoot);
            if(!signaalBoot)
            {
                sensorOpen = 0;
                motorBrug = -1;
                break;
            }

        }

        while(motorBrug == -1) // Als brug aan het sluiten is
        {
            // Stuur motor aan

            printf("Aan het sluiten\n");
            hoogte--;
            sleep(1);
            if(hoogte == 0)
            {
                motorBrug = 0;
                sensorDicht = 1;
                printf("Dicht\n");
                break;
            }
        }
    }

//-------------------------------------------------------------------------------------//
    while(brugAan)
    {
       sensorChecker();
    }

    return 0;
}
