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
    printf("\t\t\t\t      4)BACK  \t\t\t            5)QUIT \n");
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
int math_question()
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
int movie_question()
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
int science_question()
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
int gk_question()
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
int gaming_question()
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
int iqtest_question()
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
int mindgame_question()
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
void easy_time()
{
    int h=0,m=5,s=0,ms=0;
    while(1)
    {
        printf("      \t\t\t\t\t\t\t\t\t\t\t\t\t\t%d:%d:%d\r",h,m,s);
        Sleep(1000);
        if(s!=0)
        {
            s--;
        }
        if(s==0 && m!=0)
        {
            s=59;
            m--;
        }
        if(h==0 && m==0 && s==0)
        {
            exit(0);
        }
    }
}
void back_operation()
{
    int n;
    printf("\n\n\t\t\t\t\tCHOOSE AN OPTION\n\n\n");
    printf("\t\t\t\t---------------                   ---------------\n");
    printf("\t\t\t\t     1)BACK  \t\t             2)EXIT  \n");
    printf("\t\t\t\t---------------                   ---------------\n\n\n\n");
    printf("CHOOSE AN OPTION: ");
    scanf("%d",&n);
    if(n==1)
    {
    } if(n==2)
    {
        system("cls");
        printf("\a\n\t\t\t\t\tThank you for playing QUIZ-O-MANIA!!\n\n\n\n");
        exit(0);
    }
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
void gaming()
{
    system("cls");
    printf("\n\n\n\t\t\t\t               -----------------\n");
    printf("\t\t\t\t           /    QUIZ-O-MANIA    /      \n");
    printf("\t\t\t\t            -----------------\n\n\n");
    printf("\t\t\t\t\tYOU HAVE SELECTED GAMING CATAGORY......\n\n");
    printf("\t\t\t\t\tPRESS ENTER TO BEGIN YOUR QUIZ-O-MANIA....\n");
    fgetc(stdin);
    getchar();
    system("cls");
    int choice, diff, score, entry;
    score=gaming_question();
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
            printf("Player %d, enter a number:  ", player);
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
    score=gaming_question();
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
    score=gaming_question();
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
        printf("\t\t\t\t               --------------\n");
        printf("\t\t\t\t                  3)EXIT           \n");
        printf("\t\t\t\t               --------------\n\n\n");
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
                printf("\t\t\t\t               --------------\n");
                printf("\t\t\t\t                  7)GAMING           \n");
                printf("\t\t\t\t               --------------\n\n\n");
                printf("\t\t\t\t--------------                   --------------\n");
                printf("\t\t\t\t   8)BACK  \t\t\t    9)EXIT  \n");
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
                    gaming();
                }
                if(catagory==8)
                {
                    break;
                }
                if(catagory==9)
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
