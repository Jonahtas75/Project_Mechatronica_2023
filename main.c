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

    void brugChecker()
    {
        while(sensorDicht) // Als brug dicht is
        {
            // Check voor boten en wegverkeer
            if(signaalBoot && !wegverkeer)
            {
                sensorDicht = 0;
                motorBrug = 1;
                break;
            }


            printf("dicht\n");
            sleep(1);
            printf("Boot signaal?\n");
            scanf("%d",&signaalBoot);
            printf("Wegverkeer?\n");
            scanf("%d",&wegverkeer);
        }

        while(motorBrug == 1) // Als brug aan het openen is
        {
            // Stuur motor aan

            printf("openen\n");
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

            printf("open\n");
            sleep(1);
            printf("Boot signaal?\n");
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

            printf("sluiten\n");
            hoogte--;
            sleep(1);
            if(hoogte == 0)
            {
                motorBrug = 0;
                sensorDicht = 1;
                break;
            }
        }
    }

//-------------------------------------------------------------------------------------//
    printf("Boot signaal?\n");
    scanf("%d",&signaalBoot);
    printf("Wegverkeer?\n");
    scanf("%d",&wegverkeer);

    while(brugAan)
    {
       brugChecker();
    }

    return 0;
}
