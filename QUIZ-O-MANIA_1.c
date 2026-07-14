#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<stdlib.h>
#include<windows.h>
#include <unistd.h>
struct Player_info
{
    char name[100];
    char id[100];
    int games;
    int hscore;
    int flag;
} player[10000], log;
void filesave()
{
    FILE*ptr;
    ptr=fopen("savefile.txt", "w");
    int i, j;
    for (i=0; i<1000; i++)
    {
        for (j=0; player[i].name[j]!='\0'; j++)
            if (player[i].name[j]==' ')
                player[i].name[j]='_';
        for (j=0; player[i].id[j]!='\0'; j++)
            if (player[i].id[j]==' ')
                player[i].id[j]='_';
        if (player[i].flag==0)
            continue;
        fprintf(ptr, "%s\n", player[i].name);
        fprintf(ptr, "%s\n", player[i].id);
        fprintf(ptr, "%d\n", player[i].games);
        fprintf(ptr, "%d\n", player[i].hscore);
        fprintf(ptr, "%d\n", player[i].flag);
    }
    fclose(ptr);
}
void fileload()
{
    FILE*ptr;
    ptr=fopen("savefile.txt", "r");
    int i=0, j;
    for (i=0; i<1000; i++)
    {
        player[i].flag=0;
        player[i].hscore=0;
        player[i].games=0;
    }
    i=0;
    while ((fscanf(ptr, "%s%s%d%d%d", player[i].name, player[i].id, &player[i].games, &player[i].hscore, &player[i].flag)) != EOF)
    {
        for (j=0; player[i].name[j]!='\0'; j++)
            if (player[i].name[j]=='_')
                player[i].name[j]=' ';
        for (j=0; player[i].id[j]!='\0'; j++)
            if (player[i].id[j]=='_')
                player[i].id[j]=' ';
        i++;
    }
    fclose(ptr);
}
int login()
{
    int i;
    printf("\n\n\n\n\n\t\t\t\t\t               -----------------\n");
    printf("\t\t\t\t\t                  WELCOME           \n");
    printf("\t\t\t\t\t             /       TO      /     \n");
    printf("\t\t\t\t\t               QUIZ-O-MANIA           \n");
    printf("\t\t\t\t\t            -----------------\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t----------------------------------------------\n");
    printf("\t\t\t\t\t\tLOGIN TO SAVE YOUR QUIZ-O-MANIA\n");
    printf("\t\t\t\t\t----------------------------------------------");
    printf("\n\t\t\t\t\tName: ");
    gets(log.name);
    printf("\t\t\t\t\tID: ");
    gets(log.id);
    printf("\t\t\t\t\t________________________________________");

    printf("\n\t\t\t\t\tLogging in.");
    system("cls");
    for(i=0; i<1000; i++)
    {
        if(strcmp(log.name, player[i].name)==0)
        {
            strcpy(player[i].id, log.id);
            return i;
        }
    }
    printf(".");
    for(i=0; i<1000; i++)
    {
        if(player[i].flag==0)
        {
            player[i].flag=1;
            strcpy(player[i].name, log.name);
            strcpy(player[i].id, log.id);
            return i;
        }
    }
    printf(".");
}
int phase1()
{
    int input;
    printf("\n\n\n\t\t\t\t\t               -----------------\n");
    printf("\t\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t-------------------                   -------------------\n");
    printf("\t\t\t\t 1)Start the game  \t\t\t 2)Leaderboard  \n");
    printf("\t\t\t\t-------------------                   -------------------\n\n\n");
    printf("\t\t\t\t\t          ---------------------\n");
    printf("\t\t\t\t\t           3)Remove your info           \n");
    printf("\t\t\t\t\t          ---------------------\n\n\n");
    printf("\t\t\t\t-------------------                   -------------------\n");
    printf("\t\t\t\t      4)BACK  \t\t\t            5)EXIT \n");
    printf("\t\t\t\t-------------------                   -------------------\n\n\n");
    printf("CHOOSE AN OPTION:");
    scanf("%d", &input);
    system("cls");
    return input;
}
void phase2(int i)
{
    int input;
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\n\t\t\t\t\t      Remove Your Informations?");
    printf("\n\n\n\n\t\t\t\t---------------                   ---------------\n");
    printf("\t\t\t\t     1)YES  \t\t               2)NO  \n");
    printf("\t\t\t\t---------------                   ---------------\n\n\n\n");
    printf("CHOOSE AN OPTION:");
    scanf("%d", &input);
    if(input==1)
    {
        player[i].flag=0;
        printf("\n\t\t\t\t\tDone!");
        printf("\n\t\t\t\t\tPLEASE WAIT A FEW SEC!");
        sleep(1);
    }
    system("cls");
}
void leaderboard()
{
    int i;
    filesave();
    fileload();
    for(i=0; i<10000; i++)
    {
        if(player[i].flag==1)
        {
            printf("\n\t\t\t\t-------------------------------------------------");
            printf("\n\t\t\t\t| Player Name\t: %s", player[i].name);
            printf("\n\t\t\t\t| Player ID\t: %s", player[i].id);
            printf("\n\t\t\t\t| Games Played\t: %d", player[i].games);
            printf("\n\t\t\t\t| High Score\t: %d", player[i].hscore);
            printf("\n\t\t\t\t-------------------------------------------------\n");
        }
    }
    printf("\n\n\t\t\t\t\tPress Enter to continue...");
    getchar();
    getchar();
    system("cls");
}
int sports_question()
{
    int score=0;
    int input[10], i=0;
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t1.National Sports Day (NSD) is celebrated\n");
    printf("\t\t\t\t\ton which date in India?\n");
    printf("\n\t\t\t\t\t1) August 28\t\t");
    printf("2) August 29\n");
    printf("\t\t\t\t\t3) August 26\t\t");
    printf("4) August 27");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 1) August 28");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");

    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\t2.Former Australian captain Mark Taylor has");
    printf("\n\t\t\t\t\thad several nicknames over his playing career.");
    printf("\n\t\t\t\t\tWhich of the following was NOT one of them?\n");
    printf("\n\t\t\t\t\t1)Tubby\t\t\t");
    printf("2)Stodge");
    printf("\n\t\t\t\t\t3)Helium Bat\t\t");
    printf("4)Stumpy");
    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 4)Stumpy ");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\t3.Which was the 1st non Test playing country");
    printf("\n\t\t\t\t\tto beat India in an international match?\n");
    printf("\n\t\t\t\t\t1)Canada\t\t");
    printf("2)Sri Lanka");
    printf("\n\t\t\t\t\t3)Zimbabwe\t\t");
    printf("4)East Africa");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 2)Sri Lanka");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t4.Track and field star Carl Lewis won how");
    printf("\n\t\t\t\t\tmany gold medals at the 1984 Olympic games?\n");
    printf("\n\t\t\t\t\t1)Two \t\t\t");
    printf("2)Three");
    printf("\n\t\t\t\t\t3)Four\t\t\t");
    printf("4)Eight");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 3)Four");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\t5. Which county did Ravi Shastri play for?\n");
    printf("\n\t\t\t\t\t1)Glamorgan \t\t");
    printf("2)Leicestershire");
    printf("\n\t\t\t\t\t3)Gloucestershire\t");
    printf("4)Lancashire");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)Glamorgan");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\t6. How long are professional Golf Tour");
    printf("\n\t\t\t\t\tplayers allotted per shot?\n");
    printf("\n\t\t\t\t\t1)45 seconds\t\t");
    printf("2)25 seconds");
    printf("\n\t\t\t\t\t3)1 minute\t\t");
    printf("4) 2 minutes");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1) 45 seconds");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\t7. Which team emerged winner of the UEFA");
    printf("\n\t\t\t\t\tChampions League title in 2022?\n");
    printf("\n\t\t\t\t\t1)Real Madrid\t\t");
    printf("2)FC Barcelona");
    printf("\n\t\t\t\t\t3)Bryan Munich\t\t");
    printf("4)Inter Milan");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)Real Madrid");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\t8. In cricket which of the following fielding");
    printf("\n\t\t\t\t\tpositions is behind the batsman?\n");
    printf("\n\t\t\t\t\t1)Mid-wicket\t\t");
    printf("2)First slip");
    printf("\n\t\t\t\t\t3)Cover\t\t\t");
    printf("4)Mid off");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)First slip");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t9.Which of the following team won the ICC");
    printf("\n\t\t\t\t\tWomen's World Cup 2022?\n");
    printf("\n\t\t\t\t\t1)Australia\t\t");
    printf("2)England");
    printf("\n\t\t\t\t\t3)West Indies\t\t");
    printf("4)India");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)Australia");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\t10.What does Olympic Flame symbolize?\n");
    printf("\n\t\t\t\t\t1)Zeal to play sports\t\t");
    printf("\n\t\t\t\t\t2)Challenges");
    printf("\n\t\t\t\t\t3)Continuity\t\t");
    printf("\n\t\t\t\t\t4)Integrity");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)Continuity");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    return score;
}
int history_question()
{
    int score=0;
    int input[10], i=0;
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t1. Which river flows across the India\n");
    printf("\t\t\t\t\tBangladesh border?\n");
    printf("\n\t\t\t\t\t1) Hooghly River\t\t");
    printf("2) Ichamati River\n");
    printf("\t\t\t\t\t3) Brahmaputra River\t\t");
    printf("4) Suma River");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 2) Ichamati River");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");

    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\t2.The Asian nation of Bangladesh is ");
    printf("\n\t\t\t\t\talmost completely enveloped by one country.");
    printf("\n\t\t\t\t\tWhich nation has a large land border with Bangladesh?\n");
    printf("\n\t\t\t\t\t1)Japan\t\t\t");
    printf("2)China");
    printf("\n\t\t\t\t\t3)India\t\t\t");
    printf("4)Russia");
    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 3)India ");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\t3.Situated in South Asia, Bangladesh is bordered ");
    printf("\n\t\t\t\t\tby India and which country to the south-east?\n");
    printf("\n\t\t\t\t\t1)Myanmar\t\t");
    printf("2)Nepal");
    printf("\n\t\t\t\t\t3)Pakistan\t\t");
    printf("4)Bhutan");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 1)Myanmar");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t4.Dhaka is capital of Bangladesh.");
    printf("\n\t\t\t\t\tOn which river it is situated?\n");
    printf("\n\t\t\t\t\t1)Jamuna \t\t\t");
    printf("2)Padma");
    printf("\n\t\t\t\t\t3)Buriganga\t\t\t");
    printf("4)Meghna");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 3)Buriganga");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\t5.The nation of Bangladesh was formed from ");
    printf("\n\t\t\t\t\tthe historic region of Bengal.1");
    printf("\n\t\t\t\t\tIn which year did it gain independence?\n");
    printf("\n\t\t\t\t\t1)1522 \t\t");
    printf("2)1890");
    printf("\n\t\t\t\t\t3)1971\t\t");
    printf("4)1947");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)1971");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\t6. Which city became the capital of ");
    printf("\n\t\t\t\t\tBangladesh when it gained independence?\n");
    printf("\n\t\t\t\t\t1)Tehran\t\t");
    printf("2)Jakarta");
    printf("\n\t\t\t\t\t3)Dhaka\t\t\t");
    printf("4) Kabul");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3) Dhaka");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\t7. In 1971 after a bloody resistance, Bangladesh");
    printf("\n\t\t\t\t\tofficially gained independence from which nation?\n");
    printf("\n\t\t\t\t\t1)Pakistan\t\t");
    printf("2)United Kingdom");
    printf("\n\t\t\t\t\t3)France\t\t");
    printf("4)India");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)Pakistan");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\t8. Bangladesh is bordered by two countries. Which ones?");
    printf("\n\t\t\t\t\tcountries. Which ones?\n");
    printf("\n\t\t\t\t\t1)Nepal and Bhutan\t\t");
    printf("2)India and Nepal");
    printf("\n\t\t\t\t\t3)India and Myanmar\t\t");
    printf("4)Myanmar and Nepal");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)India and Myanmar");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t9.Which city is called the Healthy City of Bangladesh?\n");
    printf("\n\t\t\t\t\t1)Dhaka\t\t\t");
    printf("2)Chittagong");
    printf("\n\t\t\t\t\t3)Barishal\t\t");
    printf("4)Bogra");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)Chittagong");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\t10.Which body of water is found directly");
    printf("\n\t\t\t\t\tsouth of Bangladesh?\n");
    printf("\n\t\t\t\t\t1)Red Sea\t\t");
    printf("\n\t\t\t\t\t2)Pacific Ocean");
    printf("\n\t\t\t\t\t3)Bay of Bengal\t\t");
    printf("\n\t\t\t\t\t4)Yellow Sea");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)Bay of Bengal");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    return score;
}
int math_question()
{
    int score=0;
    int input[10], i=0;
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t1.Find the sum of 111 + 222 + 333\n");
    printf("\n\t\t\t\t\t1)700\t\t");
    printf("2)666\n");
    printf("\t\t\t\t\t3)100\t\t");
    printf("4)10");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 2)666");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");

    printf("\n\t\t\t\t\t_____________________________");
    printf("\n\t\t\t\t\t2. Subtract 457 from 832\n");
    printf("\n\t\t\t\t\t1)375\t\t");
    printf("2)57");
    printf("\n\t\t\t\t\t3)478\t\t");
    printf("4)234");
    printf("\n\t\t\t\t\t_____________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 1)375");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t________________________________");
    printf("\n\t\t\t\t\t3.50 times 5 is equal to\n");
    printf("\n\t\t\t\t\t1)2500\t\t");
    printf("2)505");
    printf("\n\t\t\t\t\t3)500\t\t");
    printf("4)None of these");
    printf("\n\t\t\t\t\t________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 3)500");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t4. 90   /   10 --\n");
    printf("\n\t\t\t\t\t1)9 \t\t\t");
    printf("2)10");
    printf("\n\t\t\t\t\t3)900\t\t\t");
    printf("4)1");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 1)9");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t______________________________");
    printf("\n\t\t\t\t\t5. Simplify: 26 + 32 - 12\n");
    printf("\n\t\t\t\t\t1)0\t\t");
    printf("2)32");
    printf("\n\t\t\t\t\t3)56\t\t");
    printf("4)46");
    printf("\n\t\t\t\t\t______________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:4)46");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\t6. Find the product of 72 * 3\n");
    printf("\n\t\t\t\t\t1)216\t\t");
    printf("2)7230");
    printf("\n\t\t\t\t\t3)106\t\t");
    printf("4) 372");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1) 216");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\t7. Solve : 200 - (96 / 4)\n");
    printf("\n\t\t\t\t\t1)105\t\t");
    printf("2)176");
    printf("\n\t\t\t\t\t3)26\t\t");
    printf("4)16");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)176");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t__________________________");
    printf("\n\t\t\t\t\t8. Solve : 24 + 4 / 4\n");
    printf("\n\t\t\t\t\t1)25\t\t");
    printf("2)6");
    printf("\n\t\t\t\t\t3)28\t\t");
    printf("4)7");
    printf("\n\t\t\t\t\t__________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)25");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t9.Simplify : 3 + 6 * (5 + 4) / 3 - 7\n");
    printf("\n\t\t\t\t\t1)11\t\t");
    printf("2)16");
    printf("\n\t\t\t\t\t3)14\t\t");
    printf("4)15");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)14");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\t10.Simplify :150 / (6 + 3 * 8) - 5\n");
    printf("\n\t\t\t\t\t1)2\t\t");
    printf("2)5");
    printf("\n\t\t\t\t\t3)0\t\t");
    printf("4)none of these");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)0");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    return score;
}
int movie_question()
{
    int score=0;
    int input[10], i=0;
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t1.The code in The Matrix comes from what food recipes?\n");
    printf("\n\t\t\t\t\t1)Sushi recipes\t\t\t");
    printf("2)Dumpling recipes\n");
    printf("\t\t\t\t\t3)Stir-fry recipes\t\t");
    printf("4)Pad thai recipes");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 1)Sushi recipes");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");

    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\t2.Who actually drew the sketch of Rose in Titanic?\n");
    printf("\n\t\t\t\t\t1)Leonardo DiCaprio\t\t");
    printf("2)Billy Zane");
    printf("\n\t\t\t\t\t3)James Cameron\t\t\t");
    printf("4)Kathy Bates");
    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 4)James Cameron ");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\t3.How many Infinity Stones are there?\n");
    printf("\n\t\t\t\t\t1)Five\t\t");
    printf("2)Six");
    printf("\n\t\t\t\t\t3)seven\t\t");
    printf("4)eight");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 2)Six");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t4.Who was the first Black person to win an Oscar?\n");
    printf("\n\t\t\t\t\t1)Hattie McDaniel \t\t");
    printf("2)Sidney Poitier");
    printf("\n\t\t\t\t\t3)Dorothy Dandridge\t\t");
    printf("4)James Earl Jones");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 1)Hattie McDaniel");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\t5.Hawkeye has how many children?\n");
    printf("\n\t\t\t\t\t1)1\t\t");
    printf("2)2");
    printf("\n\t\t\t\t\t3)3\t\t");
    printf("4)4");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)3");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\t6.What year was the first Iron Man movie released,");
    printf("\n\t\t\t\t\tkicking off the Marvel Cinematic Universe?\n");
    printf("\n\t\t\t\t\t1)2005\t\t");
    printf("2)2008");
    printf("\n\t\t\t\t\t3)2010\t\t");
    printf("4)2012");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)2008");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\t7.What is the name of Thor’s hammer?\n");
    printf("\n\t\t\t\t\t1)Vanir\t\t");
    printf("2)Mjolnir");
    printf("\n\t\t\t\t\t3)Aesir\t\t");
    printf("4)Norn");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)Mjolnir");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\t8. Before becoming Vision, what is ");
    printf("\n\t\t\t\t\tthe name of Iron Man’s A.I. butler?\n");
    printf("\n\t\t\t\t\t1)H.O.M.E.R.\t\t\t");
    printf("2)J.A.R.V.I.S.");
    printf("\n\t\t\t\t\t3)A.L.F.R.E.D.\t\t\t");
    printf("4)M.A.R.V.I.N.");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)J.A.R.V.I.S.");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t9.What is the real name of the Black Panther?\n");
    printf("\n\t\t\t\t\t1)T’Challa\t\t");
    printf("2)M’Baku");
    printf("\n\t\t\t\t\t3)N’Jadaka\t\t");
    printf("4)N’Jobu");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)T’Challa");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\t10.What is the alien race Loki sends");
     printf("\n\t\t\t\t\tto invade Earth in The Avengers?\n");
    printf("\n\t\t\t\t\t1)The Chitauri\t\t");
    printf("\n\t\t\t\t\t2)The Kree");
    printf("\n\t\t\t\t\t3)The Skrulls\t\t");
    printf("\n\t\t\t\t\t4)The Flerkens");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)The Chitauri");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    return score;
}
int science_question()
{
    int score=0;
    int input[10], i=0;
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t1.Which of the following is used in pencils?\n");
    printf("\n\t\t\t\t\t1) Graphite\t\t");
    printf("2) Silicon\n");
    printf("\t\t\t\t\t3) Charcoal\t\t");
    printf("4) Phosphorous");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 1) Graphite");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");

    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\t2.Chemical formula for water is--\n");
    printf("\n\t\t\t\t\t1)NaA1O2\t\t\t");
    printf("2)H2O");
    printf("\n\t\t\t\t\t3)Al2O3\t\t\t\t");
    printf("4)CaSiO3");
    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 2)H2O ");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\t3.Which of the following is a non metal that ");
    printf("\n\t\t\t\t\tremains liquid at room temperature?\n");
    printf("\n\t\t\t\t\t1)Phosphorous\t\t");
    printf("2)Bromine");
    printf("\n\t\t\t\t\t3)Chlorine\t\t");
    printf("4)Helium");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 2)Bromine");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t4.Washing soda is the common name for\n");
    printf("\n\t\t\t\t\t1)Sodium carbonate \t\t");
    printf("2)Calcium bicarbonate");
    printf("\n\t\t\t\t\t3)Sodium bicarbonate\t\t");
    printf("4)Calcium carbonate");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 1)Sodium carbonate");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\t5. Which of the gas is not known as green house gas?\n");
    printf("\n\t\t\t\t\t1)Methane \t\t");
    printf("2)Nitrous oxide");
    printf("\n\t\t\t\t\t3)Carbon dioxide\t");
    printf("4)Hydrogen");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:4)Hydrogen");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\t6. Bromine is a\n");
    printf("\n\t\t\t\t\t1)black solid\t\t");
    printf("2)red liquid");
    printf("\n\t\t\t\t\t3)colourless gas\t");
    printf("4)highly inflammable gas");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)red liquid");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\t7. The hardest substance available on earth is\n");
    printf("\n\t\t\t\t\t1)Gold\t\t\t");
    printf("2)Iron");
    printf("\n\t\t\t\t\t3)Diamond\t\t");
    printf("4)Platinum");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)Diamond");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\t8. Which of the following is used as a lubricant?\n");
    printf("\n\t\t\t\t\t1)Graphite\t\t\t");
    printf("2)Silica");
    printf("\n\t\t\t\t\t3)Iron Oxide\t\t\t");
    printf("4)Diamond");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)Graphite");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t9.The average salinity of sea water is\n");
    printf("\n\t\t\t\t\t1)3%\t\t");
    printf("2)3.5%");
    printf("\n\t\t\t\t\t3)2.5%\t\t");
    printf("4)2%");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)3.5%");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\t10.The group of metals Fe, Co, Ni ");
    printf("\n\t\t\t\t\tmay best called as\n");
    printf("\n\t\t\t\t\t1)transition metals\t\t");
    printf("\n\t\t\t\t\t2)main group metals");
    printf("\n\t\t\t\t\t3)alkali metals\t\t");
    printf("\n\t\t\t\t\t4)rare metals");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)transition metals");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    return score;
}
int gk_question()
{
    int score=0;
    int input[10], i=0;
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t1.Which animal lays eggs?\n");
    printf("\n\t\t\t\t\t1)Dog\t\t");
    printf("2)Cat\n");
    printf("\t\t\t\t\t3)Duck\t\t");
    printf("4)Sheep");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 3)Duck");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");

    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\t2.A male cow is called?\n");
    printf("\n\t\t\t\t\t1)Ox\t\t\t");
    printf("2)Dog");
    printf("\n\t\t\t\t\t3)Sheep\t\t\t");
    printf("4)Monkey");
    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 1)Ox ");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\t3.All animals need food, air, and ____ to survive.\n");
    printf("\n\t\t\t\t\t1)House\t\t\t");
    printf("2)Water");
    printf("\n\t\t\t\t\t3)Chocolate\t\t");
    printf("4)Fruits");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 2)Water");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t4.When you push something, you apply ____.\n");
    printf("\n\t\t\t\t\t1)Force\t\t\t");
    printf("2)Acceleration");
    printf("\n\t\t\t\t\t3)Mass\t\t\t");
    printf("4)Compression");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 1)Force");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\t5.What is Earth’s only natural satellite?\n");
    printf("\n\t\t\t\t\t1)Sun\t\t");
    printf("2)Mars");
    printf("\n\t\t\t\t\t3)Venus\t\t");
    printf("4)Moon");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:4)Moon");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\t6.Which is the largest animal on earth?\n");
    printf("\n\t\t\t\t\t1)Shark\t\t\t");
    printf("2)Elephant");
    printf("\n\t\t\t\t\t3)Blue whale\t\t");
    printf("4)Giraffe");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)Blue whale");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\t7.What part of the body helps you move?\n");
    printf("\n\t\t\t\t\t1)Eyes\t\t\t");
    printf("2)Lungs");
    printf("\n\t\t\t\t\t3)Pancreas\t\t");
    printf("4)Muscles");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:4)Muscles");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\t8.The two holes of the nose are called?\n");
    printf("\n\t\t\t\t\t1)Eyelids\t\t");
    printf("2)Nostrils");
    printf("\n\t\t\t\t\t3)Nails\t\t\t");
    printf("4)Hair");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)Nostrils");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t9. What star shines in the day and provides light?\n");
    printf("\n\t\t\t\t\t1)Moon\t\t");
    printf("2)Venus");
    printf("\n\t\t\t\t\t3)Mars\t\t");
    printf("4)Sun");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:4)Sun");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\t10.What energy emerges from motion?\n");
    printf("\n\t\t\t\t\t1)Potential energy\t\t");
    printf("\n\t\t\t\t\t2)Electrical energy");
    printf("\n\t\t\t\t\t3)Kinetic energy\t\t");
    printf("\n\t\t\t\t\t4)Gravitational energy");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)Kinetic energy");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    return score;
}
int iqtest_question()
{
    int score=0;
    int input[10], i=0;
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t1.What are clothes made of?\n");
    printf("\n\t\t\t\t\t1)Cloth\t\t");
    printf("2)Paper\n");
    printf("\t\t\t\t\t3)Wood\t\t");
    printf("4)Glass");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 1)Cloth");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");

    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\t2.What is the color of blood?\n");
    printf("\n\t\t\t\t\t1)Blue\t\t\t");
    printf("2)Yellow");
    printf("\n\t\t\t\t\t3)Black\t\t\t");
    printf("4)Red");
    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 4)Red ");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\t3.Which has the sweetest taste?\n");
    printf("\n\t\t\t\t\t1)Spaghetti\t\t");
    printf("2)Hot dogs");
    printf("\n\t\t\t\t\t3)Honey\t\t\t");
    printf("4)Peanut Butter");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 3)Honey");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t4.Which tastes the most sour?\n");
    printf("\n\t\t\t\t\t1)Apple\t\t\t");
    printf("2)Banana");
    printf("\n\t\t\t\t\t3)Orange\t\t");
    printf("4)Lemon");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 4)Lemon");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\t5. Which is the hottest?\n");
    printf("\n\t\t\t\t\t1)Light bulb\t\t");
    printf("2)Pancake");
    printf("\n\t\t\t\t\t3)Flame\t\t\t");
    printf("4)Gun");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)Flame");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\t6.Which is the coldest?");
    printf("\n\t\t\t\t\tplayers allotted per shot?\n");
    printf("\n\t\t\t\t\t1)Ice\t\t");
    printf("2)Water");
    printf("\n\t\t\t\t\t3)Rain\t\t");
    printf("4)Glass");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)Ice");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\t7.Which is used for making holes in wood?\n");
    printf("\n\t\t\t\t\t1)Pliers\t\t");
    printf("2)Hammer");
    printf("\n\t\t\t\t\t3)Plane\t\t\t");
    printf("4)Drill");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:4)Drill");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\t8.Which is used when playing baseball?\n");
    printf("\n\t\t\t\t\t1)Basket\t\t");
    printf("2)Racket");
    printf("\n\t\t\t\t\t3)Mitt\t\t\t");
    printf("4)Stick");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)Mitt");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t9.Which is used when making clothes?\n");
    printf("\n\t\t\t\t\t1)String\t\t");
    printf("2)Plastic");
    printf("\n\t\t\t\t\t3)Pattern\t\t");
    printf("4)Nails");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)String");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\t10.Which is used to make concrete?\n");
    printf("\n\t\t\t\t\t1)Mud\t\t");
    printf("\n\t\t\t\t\t2)Sand");
    printf("\n\t\t\t\t\t3)Plaster\t\t");
    printf("\n\t\t\t\t\t4)Asphalt");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)Sand");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    return score;
}
int mindgame_question()
{
    int score=0;
    int input[10], i=0;
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t1.I have a face and have two hands,");
    printf("\n\t\t\t\t\t  but no legs. What am I?\n");
    printf("\n\t\t\t\t\t1)Ball\t\t");
    printf("2)Cat\n");
    printf("\t\t\t\t\t3)Bat\t\t");
    printf("4)Clock");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 4)Clock");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");

    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\t2.I have a neck, but don’t have a head. What am I?\n");
    printf("\n\t\t\t\t\t1)Table\t\t\t");
    printf("2)Candle");
    printf("\n\t\t\t\t\t3)Bottle\t\t");
    printf("4)Comb");
    printf("\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 2)Candle ");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\t3.I have an eye, but cannot see with it. What am I?\n");
    printf("\n\t\t\t\t\t1)Man\t\t");
    printf("2)Bird");
    printf("\n\t\t\t\t\t3)Box\t\t");
    printf("4)Needle");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==4)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 4)Needle");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t4.You can break me, but you cannot touch me. What am I?\n");
    printf("\n\t\t\t\t\t1)Wall\t\t\t");
    printf("2)Comb");
    printf("\n\t\t\t\t\t3)Promise\t\t");
    printf("4)Bottle");
    printf("\n\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is: 3)Promise");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\t5. I have a head and a tail, but no body. What am I?\n");
    printf("\n\t\t\t\t\t1)Coin\t\t");
    printf("2)Wall");
    printf("\n\t\t\t\t\t3)Chair\t\t");
    printf("4)Box");
    printf("\n\t\t\t\t\t__________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)Coin");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\t6.I’m taller when I’m young, but become");
    printf("\n\t\t\t\t\t  shorter as I grow older. What am I?\n");
    printf("\n\t\t\t\t\t1)Table\t\t");
    printf("2)Candle");
    printf("\n\t\t\t\t\t3)Bottle\t");
    printf("4)Comb");
    printf("\n\t\t\t\t\t______________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)Candle");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\t7.I have a lot of teeth, but I can’t ");
    printf("\n\t\t\t\t\t  eat with it. What am I?\n");
    printf("\n\t\t\t\t\t1)Bottle\t\t");
    printf("2)Bowl");
    printf("\n\t\t\t\t\t3)Comb\t\t\t");
    printf("4)Chair");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==3)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:3)Comb");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\t8.I run through various cities, villages and fields,");
    printf("\n\t\t\t\t\t  but I cannot move. What am I?\n");
    printf("\n\t\t\t\t\t1)Table\t\t\t");
    printf("2)Road");
    printf("\n\t\t\t\t\t3)Chair\t\t\t");
    printf("4)Wall");
    printf("\n\t\t\t\t\t_____________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==2)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:2)Road");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_________________________________________");
    printf("\n\t\t\t\t\t9.I have leaflets, but do not have any branches. What am I?\n");
    printf("\n\t\t\t\t\t1)Book\t\t\t");
    printf("2)Needle");
    printf("\n\t\t\t\t\t3)Candle\t\t");
    printf("4)Table");
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)Book");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\t10.You can make it, but you can’t see ");
    printf("\n\t\t\t\t\t   it with your eyes. What is it?\n");
    printf("\n\t\t\t\t\t1)Noise\t\t");
    printf("\n\t\t\t\t\t2)Clip");
    printf("\n\t\t\t\t\t3)Fence\t\t");
    printf("\n\t\t\t\t\t4)Clock");
    printf("\n\t\t\t\t\t_____________________________________");
    printf("\n\t\t\t\t\tAns: ");
    scanf("%d", &input[i]);
    if(input[i]==1)
    {
        score++;
        printf("\n\t\t\t\t\tCorrect Answer!");
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Answer! Correct answer is:1)Noise");
        sleep(1);
    }
    i++;
    sleep(1);
    system("cls");
    return score;
}
void result(int score, int entry, int diff)
{
    printf("\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tYou Got %d out of 10", score);
    printf("\n\t\t\t\t\tYour score: %d", score);
    printf("\n\t\t\t\t\t________________________________________");
    if(score>player[entry].hscore)
    {
        printf("\n\t\t\t\t\tCongratulations!");
        printf("\n\t\t\t\t\tYou've set a new High Score!");
        printf("\n\t\t\t\t\t________________________________________");
        player[entry].hscore=score;
    }
    printf("\n\t\t\t\t\tPress Enter to continue...");
    getchar();
    getchar();
    system("cls");
}
void sports()
{
    system("cls");
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t\tYOU HAVE SELECTED SPORTS CATAGORY......\n\n");
    printf("\t\t\t\t\tPRESS ENTER TO BEGIN YOUR QUIZ-O-MANIA....\n");
    fgetc(stdin);
    getchar();
    system("cls");
    int choice, diff, score, entry;
    score=sports_question();
    player[entry].games++;
    score*=1;
    result(score, entry, diff);
}
void history()
{
    system("cls");
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t\tYOU HAVE SELECTED HISTORY CATAGORY......\n\n");
    printf("\t\t\t\t\tPRESS ENTER TO BEGIN YOUR QUIZ-O-MANIA....\n");
    fgetc(stdin);
    getchar();
    system("cls");
    int choice, diff, score, entry;
    score=history_question();
    player[entry].games++;
    score*=1;
    result(score, entry, diff);
}
void math()
{
    system("cls");
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t\tYOU HAVE SELECTED MATH CATAGORY......\n\n");
    printf("\t\t\t\t\tPRESS ENTER TO BEGIN YOUR QUIZ-O-MANIA....\n");
    fgetc(stdin);
    getchar();
    system("cls");
    int choice, diff, score, entry;
    score=math_question();
    player[entry].games++;
    score*=1;
    result(score, entry, diff);
}
void movie()
{
    system("cls");
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t\tYOU HAVE SELECTED MOVIE CATAGORY......\n\n");
    printf("\t\t\t\t\tPRESS ENTER TO BEGIN YOUR QUIZ-O-MANIA....\n");
    fgetc(stdin);
    getchar();
    system("cls");
    int choice, diff, score, entry;
    score=movie_question();
    player[entry].games++;
    score*=1;
    result(score, entry, diff);
}
void science()
{
    system("cls");
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t\tYOU HAVE SELECTED SCIENCE CATAGORY......\n\n");
    printf("\t\t\t\t\tPRESS ENTER TO BEGIN YOUR QUIZ-O-MANIA....\n");
    fgetc(stdin);
    getchar();
    system("cls");
    int choice, diff, score, entry;
    score=science_question();
    player[entry].games++;
    score*=1;
    result(score, entry, diff);
}
void gk()
{
    system("cls");
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t\tYOU HAVE SELECTED GENAREL KNOWLEDGE CATAGORY......\n\n");
    printf("\t\t\t\t\tPRESS ENTER TO BEGIN YOUR QUIZ-O-MANIA....\n");
    fgetc(stdin);
    getchar();
    system("cls");
    int choice, diff, score, entry;
    score=gk_question();
    player[entry].games++;
    score*=1;
    result(score, entry, diff);
}
void board(char* square)
{
    system("COLOR 3");
    system("cls");
    printf("\t\t\t\t\t\tTIC-TAC-TOE\n\n");
    printf("\t\t\t\t\tPlayer 1 (X)  -  Player 2 (O)\n\n\n");
    printf("\t\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t\t  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("\t\t\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t\t  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("\t\t\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t\t  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("\t\t\t\t\t\t     |     |     \n\n");
}
int checkwin(char* square)
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
             != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return  - 1;
}
void tictactoe()
{
    system("cls");
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t\t\tTIC-TAC-TOE\n\n\n\n");
    printf("\t\t\t\t\tPRESS ENTER TO START THE GAME:\n");
    fgetc(stdin);
    getchar();
    system("cls");
    int playagain;
    do
    {
        char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        int player = 1, i, choice;
        char mark;
        do
        {
            board(square);
            player = (player % 2) ? 1 : 2;
            printf("\n\n\nEnter 0 to quit the game");
            printf("\n\nPlayer %d, enter a number:  ", player);
            scanf("%d", &choice);
            mark = (player == 1) ? 'X' : 'O';
            if (choice == 1 && square[1] == '1')
                square[1] = mark;
            else if (choice == 2 && square[2] == '2')
                square[2] = mark;
            else if (choice == 3 && square[3] == '3')
                square[3] = mark;
            else if (choice == 4 && square[4] == '4')
                square[4] = mark;
            else if (choice == 5 && square[5] == '5')
                square[5] = mark;
            else if (choice == 6 && square[6] == '6')
                square[6] = mark;
            else if (choice == 7 && square[7] == '7')
                square[7] = mark;
            else if (choice == 8 && square[8] == '8')
                square[8] = mark;
            else if (choice == 9 && square[9] == '9')
                square[9] = mark;
            else if (choice == 0 )
                break;
            else
            {
                printf("Invalid move ");
                player--;
                getch();
            }
            i = checkwin(square);
            player++;
        }
        while (i ==  - 1);
        board(square);
        if (i == 1)
        {
            printf("\n\n\t\t\t\t               -------------------\n");
            printf("\t\t\t\t                ==>\aPlayer %d win            \n",--player);
            printf("\t\t\t\t               -------------------\n\n\n");
        }
        else
        {
            printf("\n\n\t\t\t\t               ---------------\n");
            printf("\t\t\t\t                  \aGAME DRAW           \n");
            printf("\t\t\t\t               ---------------\n\n\n");
        }
        getch();
        system("cls");
        printf("\t\t\t\t\tDO YOU WANT TO PALY AGAIN?\n\n\n\n\n");
        printf("\t\t\t\t--------------                   --------------\n");
        printf("\t\t\t\t   1)YES  \t\t\t    2)NO  \n");
        printf("\t\t\t\t--------------                   --------------\n");
        scanf("%d",&playagain);
    }
    while(playagain==1);
    system("cls");
    printf("\a\n\t\t\t\t\tThank you for playing QUIZ-O-MANIA!!\n\n\n\n");
    exit(0);
}
int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;
void setup()
{
    gameover = 0;
    x = height / 2;
    y = width / 2;
label1:
    fruitx = rand() % 20;
    if (fruitx == 0)
        goto label1;
label2:
    fruity = rand() % 20;
    if (fruity == 0)
        goto label2;
    score = 0;
}
void draw()
{
    system("cls");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == width - 1
                    || j == 0
                    || j == height - 1)
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitx
                         && j == fruity)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("score = %d", score);
    printf("\n");
    printf("press X to quit the game");
}
void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}
void logic()
{
    sleep(0.01);
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }
    if (x < 0 || x > height
            || y < 0 || y > width)
        gameover = 1;
    if (x == fruitx && y == fruity)
    {
label3:
        fruitx = rand() % 20;
        if (fruitx == 0)
            goto label3;
label4:
        fruity = rand() % 20;
        if (fruity == 0)
            goto label4;
        score += 10;
    }
}
void snake()
{
    system("cls");
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t\t\tSNAKE\n\n\n\n");
    printf("\t\t\t\t\tPRESS ENTER TO START THE GAME:\n");
    fgetc(stdin);
    getchar();
    system("cls");
    int playagain;
    do
    {
        int m, n;
        setup();
        while (!gameover)
        {
            draw();
            input();
            logic();
        }
        system("cls");
        printf("\t\t\t\t\tDO YOU WANT TO PALY AGAIN?\n\n\n\n\n");
        printf("\t\t\t\t--------------                   --------------\n");
        printf("\t\t\t\t   1)YES  \t\t\t    2)NO  \n");
        printf("\t\t\t\t--------------                   --------------\n");
        scanf("%d",&playagain);
    }
    while(playagain==1);
    system("cls");
    printf("\a\n\t\t\t\t\tThank you for playing QUIZ-O-MANIA!!\n\n\n\n");
    exit(0);
}
void iqtest()
{
    system("cls");
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t\t\tIQ TEST\n\n\n\n");
    printf("\t\t\t\t\tPRESS ENTER TO START THE GAME:\n");
    fgetc(stdin);
    getchar();
    system("cls");
    int choice, diff, score, entry;
    score=iqtest_question();
    player[entry].games++;
    score*=1;
    result(score, entry, diff);
}
void mindgame()
{
    system("cls");
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t\t\tMIND GAME\n\n\n\n");
    printf("\t\t\t\t\tPRESS ENTER TO START THE GAME:\n");
    fgetc(stdin);
    getchar();
    system("cls");
    int choice, diff, score, entry;
    score=mindgame_question();
    player[entry].games++;
    score*=1;
    result(score, entry, diff);
}
void start_game()
{
    char cont='y';
    while(cont=='y')
    {
        system("cls");
        printf("\n\n\n\t\t\t\t               -----------------\n");
        printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
        printf("\t\t\t\t            -----------------\n\n\n");
        printf("\t\t\t\t--------------                   --------------\n");
        printf("\t\t\t\t   1)QUIZ  \t\t\t    2)GAMES  \n");
        printf("\t\t\t\t--------------                   --------------\n\n\n");
        printf("\t\t\t\t--------------                   --------------\n");
        printf("\t\t\t\t   3)BACK  \t\t\t    4)EXIT  \n");
        printf("\t\t\t\t--------------                   --------------\n\n\n");
        int choice;
        printf("\n\nCHOOSE AN OPTION: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            while(cont=='y')
            {
                system("cls");
                printf("\t\t\t\t\tSELECT A CATAGORY TO START:\n\n\n\n");
                printf("\t\t\t\t--------------                   --------------\n");
                printf("\t\t\t\t   1)SPORTS  \t\t\t   2)HISTORY  \n");
                printf("\t\t\t\t--------------                   --------------\n\n\n");
                printf("\t\t\t\t--------------                   --------------\n");
                printf("\t\t\t\t   3)MATH  \t\t\t    4)MOVIE  \n");
                printf("\t\t\t\t--------------                   --------------\n\n\n");
                printf("\t\t\t\t--------------                   --------------\n");
                printf("\t\t\t\t   5)SCIENCE  \t\t\t    6)GK  \n");
                printf("\t\t\t\t--------------                   --------------\n\n\n");
                printf("\t\t\t\t--------------                   --------------\n");
                printf("\t\t\t\t   7)BACK  \t\t\t    8)EXIT  \n");
                printf("\t\t\t\t--------------                   --------------\n\n\n");
                int catagory;
                printf("CHOOSE AN OPTION: ");
                scanf("%d",&catagory);
                if(catagory==1)
                {
                    sports();
                }
                if(catagory==2)
                {
                    history();
                }
                if(catagory==3)
                {
                    math();
                }
                if(catagory==4)
                {
                    movie();
                }
                if(catagory==5)
                {
                    science();
                }
                if(catagory==6)
                {
                    gk();
                }
                if(catagory==7)
                {
                    break;
                }
                if(catagory==8)
                {
                    system("cls");
                    printf("\a\n\t\t\t\t\tThank you for playing QUIZ-O-MANIA!!\n\n\n\n");
                    exit(0);
                }
                cont='y';
                system("cls");
                continue;
            }

        }
        if(choice==2)
        {
            while(cont=='y')
            {
                system("cls");
                printf("\t\t\t\t\tSELECT A GAME TO PLAY:\n\n\n\n");
                printf("\t\t\t\t---------------                   ---------------\n");
                printf("\t\t\t\t 1)TIC-TAC-TOE  \t\t      2)SNAKE  \n");
                printf("\t\t\t\t---------------                   ---------------\n\n\n");
                printf("\t\t\t\t---------------                   ---------------\n");
                printf("\t\t\t\t   3)IQTEST  \t\t           4)MIND GAME  \n");
                printf("\t\t\t\t---------------                   ---------------\n\n\n");
                printf("\t\t\t\t--------------                   --------------\n");
                printf("\t\t\t\t   5)BACK  \t\t\t    6)EXIT  \n");
                printf("\t\t\t\t--------------                   --------------\n\n\n");
                int catagory_game;
                printf("CHOOSE AN OPTION: ");
                scanf("%d",&catagory_game);
                if(catagory_game==1)
                {
                    tictactoe();
                }
                if(catagory_game==2)
                {
                    snake();
                }
                if(catagory_game==3)
                {
                    iqtest();
                }
                if(catagory_game==4)
                {
                    mindgame();
                }
                if(catagory_game==5)
                {
                    break;
                }
                if(catagory_game==6)
                {
                    system("cls");
                    printf("\a\n\t\t\t\t\tThank you for playing QUIZ-O-MANIA!!\n\n\n\n");
                    exit(0);
                }
            }
            cont='y';
            system("cls");
            continue;
        }
        if(choice==3)
        {
            system("cls");
            break;
        }
        if(choice==4)
        {
            system("cls");
            printf("\a\n\t\t\t\t\tThank you for playing QUIZ-O-MANIA!!\n\n\n\n");
            exit(0);
        }
    }
}
int main()
{
    system("COLOR 2");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPRESS ENTER TO START QUIZ-O-MANIA");
    getchar();
    system("cls");
    fileload();
    int choice, diff, score, entry;
point_a:
    entry=login();
menu:
    choice=phase1();
    if(choice==1)
    {
        start_game();
        goto menu;
    }
    else if(choice==2)
    {
        leaderboard();
        goto menu;
    }
    else if(choice==3)
    {
        phase2(entry);
        getchar();
        filesave();
        goto point_a;
    }
    else if(choice==4)
    {
        getchar();
        goto point_a;
    }
    else if(choice==5)
    {
        system("cls");
        printf("\a\n\t\t\t\t\tThank you for playing QUIZ-O-MANIA!!\n\n\n\n");
        exit(0);
    }
    return 0;
}
