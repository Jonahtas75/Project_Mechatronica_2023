#include <stdio.h>
#include <stdlib.h>

int main()
{
    int signaalBoot = 1;
    int wegverkeer = 0;
    int motorBrug = 0;
    // motorBrug = 0 -> brug staat stil
    // motorBrug = 1 -> brug gaat omhoog
    // motorBrug = -1 -> brug gaat omlaag

    printf("Boot signaal?\n");
    scanf("%d",&signaalBoot);
    printf("Wegverkeer?\n");
    scanf("%d",&wegverkeer);

    if(signaalBoot && !wegverkeer)
    {
        motorBrug = 1;
    }

    while(motorBrug == 1)
    {
        printf("openen\n");

    }
    return 0;
}
