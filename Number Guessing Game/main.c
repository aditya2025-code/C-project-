#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE *fp = NULL;
int num, n1;
int count, best_count = 9999, usernum;
char score_print;
char name[20], date[30], best_date[30], best_player[20];
time_t t;

void logo();
void startchoise();
void askname();
void randomnum();
void checkguesses();
int playagain();
int twochoise();
void storerecords();
void alltimehigh();
void allscore();

int main()
{

  logo();
  do
  {
    startchoise();

    if (n1 == 1)
    {
      askname();
      do
      {
        randomnum();
        checkguesses();
      } while (playagain());
    }
    else if (n1 == 2)
    {
      switch (twochoise())
      {
      case 1:
        alltimehigh();
        break;
      case 2:
        allscore();
        break;
      }
    }

  } while (n1 != 0);
  return 0;
}

void logo()
{
  printf(" _______________________________________\n");
  printf("|                                       |\n");
  printf("|         NUMBER GUESSING GAME          |\n");
  printf("|_______________________________________|\n\n");
}

void startchoise()
{
  start:
  printf("=================================\n");
  printf("-----------MAIN-MENU-------------\n");
  printf("=================================\n");
  printf("1. Start\n2. High Score\n0. Exit\n");
  printf("=================================\n");
  printf("Enter Your Choise:\t");
  scanf("%d", &n1);

  if (n1 > 2)
  {
    printf("=================================\n");
    printf("Entered Invalid Dicision\n");
    goto start;
    
  }
}

void askname()
{
  printf("=================================\n");
  printf("Enter Player Name:  ");
  scanf(" %[^\n]%*c", name);
  printf("=================================\n");
}

void randomnum()
{
  srand(time(0));
  num = (rand() % 100) + 1;

  printf("Hello,I Am a Secret Number\nBetween 1 to 100, Find Me \nGuess Which Number Am I :)\n");
}

void checkguesses()
{
  count = 0;
  do
  {
    printf("\nEnter Your Guess:\t");
    scanf("%d", &usernum);

    if (usernum < num)
    {
      printf("\nOups! Very Close!!\nhint:(Try Higher)\n");
      count++;
    }
    else if (usernum > num)
    {
      printf("\nAlmost Reached!!\nhint:(Try Lower)\n");
      count++;
    }
    else
    {
      count++;
      storerecords();
      if (count == 1)
        printf("\nYou are not Human!!\n%s,You Found Me\nIn Your 1st Attempts\nThe Secret Number ->    %d\n", name, num);
      else if (count == 2)
        printf("\nAbsolutely unbelievable!!\n%s,You Found Me\nIn Your %dnd Attempts\nThe Secret Number ->    %d\n", name, count, num);
      else if (count == 3)
        printf("\nNo Way!!\n%s,You Found Me\nIn Just %drd Attempts\nThe Secret Number ->    %d\n", name, count, num);
      else
        printf("\nYEASSS!!\n%s,You Found Me\nIn Just %dth Attempts\nThe Secret Number ->    %d\n", name, count, num);
    }
  } while (usernum != num);
}

int playagain()
{
  start:
  int x;
  printf("=================================\n");
  printf("--> Want to Play More++?\n");
  printf("1. Yes\n0. No\n");
  printf("=================================\n");
  printf("Enter your choise:\t");
  scanf("%d", &x);

  if (x > 1)
  {
    printf("=================================\n");
    printf("Entered Invalid Dicision\n");
    goto start;
    }
  if (x == 1)
  {
    printf("=================================\n");
    return 1;
  }
  else
    return 0;
}

int twochoise()
{
  start :
  int x;
  printf("=================================\n");
  printf("1. All Time High Score\n2. Score List\n");
  printf("=================================\n");
  printf("Enter your choise:\t");
  scanf("%d", &x);
  if (x > 2)
  {
    printf("=================================\n");
    printf("Entered Invalid Dicision\n");
    goto start;
  }
  if (x == 1)
  {
    return 1;
  }
  else
    return 2;
}

void storerecords()
{
  t = time(NULL);
  fp = fopen("score.txt", "a");
  if (fp == NULL)
    printf("File error");
  fprintf(fp, "%s %d %s", name, count, ctime(&t));
  fclose(fp);
}

void alltimehigh()
{
  fp = fopen("score.txt", "r");
  if (fp == NULL)
    printf("File error");
  while (fscanf(fp, "%[^ ]%*c %d %[^\n]%*c", name, &count, date) != EOF)
  {
    if (count < best_count)
    {
      best_count = count;
      strcpy(best_player, name);
      strcpy(best_date, date);
    }
  }
  fclose(fp);
  printf("=================================\n");
  printf("    -:All Time High Scorer:-\n");
  printf("_________________________________\n");
  printf("Name      -> %s\n", best_player);
  printf("Attempts  -> %d\n", best_count);
  printf("Date-Time -> \n  \t %s\n", best_date);
}

void allscore()
{
  printf("=================================\n");
  printf("       -:All Score Card:-\n");
  printf("=================================\n");
  printf("|Name|Attempt|Date&time         |\n");
  printf("=================================\n");
  fp = fopen("score.txt", "r");
  if (fp == NULL)
    printf("File error");
  while ((score_print = fgetc(fp)) != EOF)
  {
    printf("%c", score_print);
  }
  fclose(fp);
}