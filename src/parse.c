#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int NumCards(FILE * fpointer){
    unsigned int numCards = 0;
    char * p;

    char tempString[5];
    while(fgets(tempString, 5, fpointer))
    {
        if((p = strchr(tempString, '\n')) != NULL)
            *p ='\0';

        if(strcmp(tempString, "----") == 0)
            numCards++;
    }
    rewind(fpointer);

    return numCards;
}

void MakeCard(FILE * fp, struct Card * card)
{
    char tmp[100];
    char * ans = malloc(sizeof(char) * 1000);
    char * question = malloc(sizeof(char) * 1000);
    char * p;

    fgets(tmp, 100, fp);

    fgets(ans, 1000, fp);
    card->answer = ans;
    if((p = strchr(ans, '\n')) != NULL)
        *p ='\0';

    fgets(tmp, 100, fp);

    fgets(question, 1000, fp);
    card->question = question;
    if((p = strchr(question, '\n')) != NULL)
        *p ='\0';
}


struct Card * MakeDeck(char * path)
{
    FILE * fpointer = fopen(path, "r");
    unsigned int numCards = NumCards(fpointer);
    struct Card * deck = malloc(numCards * sizeof(struct Card));
    char tmp[5];
    char * p;
    int i = 0;

    while(fgets(tmp, 5, fpointer)){
        if((p = strchr(tmp, '\n')) != NULL)
            *p ='\0';
        if(strcmp(tmp, "----") == 0)
        {
            MakeCard(fpointer, &deck[i]);
            i++;
        }
    }

    return deck;
}
