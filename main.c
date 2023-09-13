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

    int stoplichtBoot = 1;
    int stoplichtVerkeer = 0;
        //1 is rood, 0 is groen

    void sensorChecker()
    {
        while(sensorDicht) // Als brug dicht is
        {
            printf("Het stoplicht van de boten is: %d\n" ,stoplichtBoot);
            printf("Het stoplicht van het verkeer is: %d\n" ,stoplichtVerkeer);

            printf("Boot signaal? 1 of 0: ");
            scanf("%d",&signaalBoot);
            if(!signaalBoot)
            {
                printf("Dicht\n");
                break;
            }

            stoplichtVerkeer = 1;
            printf("Het stoplicht van het verkeer is: %d\n" ,stoplichtVerkeer);

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

            stoplichtBoot = 0;
            printf("Het stoplicht van de boten is %d\n" ,stoplichtBoot);

            printf("Boot signaal? 1 of 0: ");
            scanf("%d",&signaalBoot);
            if(!signaalBoot)
            {
                sensorOpen = 0;
                motorBrug = -1;
                break;
            }

        }

        if(!signaalBoot)
        {
            stoplichtBoot = 1;
            printf("Het stoplicht van de boten is %d\n" ,stoplichtBoot);
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
    stoplichtVerkeer = 0;
    printf("Het stoplicht van het verkeer is %d\n" ,stoplichtVerkeer);
    }

//-------------------------------------------------------------------------------------//
    while(brugAan)
    {
       sensorChecker();
    }

    return 0;
}
