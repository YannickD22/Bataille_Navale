#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define PORTEAVIONID 4
#define CROISEURID 3
#define TORPILLEURID 2
#define SOUSMARINID 1

void waitFor (unsigned int secs){

    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

int doRand(int startVal, int endVal){

    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}

int main()
{

    while(1){

        int joueur1[18][24] = {0};
        int joueur2[18][24] = {0};
        int bateau[4];
        int ii = 0;
        int jj = 0;
        int kk = 0;
        int yJ1 = 0;
        int yJ2 = 0;
        int xJ2 = 0;
        int xJ1 = 0;
        int tailleX = 0;
        int tailleY = 0;

        printf("Choisissez la longueur de votre plateau : ");
        scanf("%d", &tailleX);
        printf("\n");
        fflush(stdin);
        printf("Choisissez la largeur de votre plateau : ");
        scanf("%d", &tailleY);
        printf("\n");
        fflush(stdin);

        //Placement bateau JOUEUR1
        for(ii=0;ii<5;ii++){
            xJ1=doRand(0, 17);
            yJ1=doRand(0, 23);
            for(jj=0;jj<ii;jj++){
                joueur1[xJ1][yJ1] = ii;
                joueur1[xJ1+jj][yJ1] = ii;
            }
        }

        //Placement bateau JOUEUR2
        for(ii=0;ii<5;ii++){
            xJ2=doRand(0, 17);
            yJ2=doRand(0, 23);
            for(jj=0;jj<ii;jj++){
                joueur2[xJ2][yJ2] = ii;
                joueur2[xJ2-jj][yJ2] = ii;
            }
        }

        printf("Plateau de l'IA 1 :\n");

        //PLATEAU JOUEUR1
        for(ii = 0;ii < tailleX; ii++){
            printf("\n");
            for(jj = 0;jj < tailleY; jj++){
                printf("%d ", joueur1[ii][jj]);
            }
        }

        printf("\n");
        printf("\n");
        printf("Plateau de l'IA 2 :\n");

        //PLATEAU JOUEUR2
        for(ii = 0;ii < tailleX; ii++){
            printf("\n");
            for(jj = 0;jj < tailleY; jj++){
                printf("%d ", joueur2[ii][jj]);
            }
        }

        printf("\n");
        printf("\n");

        printf("\n");
        printf("\n");

    }

return 0;

}
