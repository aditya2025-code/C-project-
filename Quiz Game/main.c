#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int random[50];
char name[20];

struct question
{
  char quest[1000];
  char option[4][200];
  int answer;
} q[50];

enum options
{
  A = 1,
  B,
  C,
  D
};

void logo();
void mainmenu();
void takeplayername();
void gamestart();
void readquestion();
void randomquestion();
int printquestions();
int answercheck(int);
int saverecord(int);
void gamerecords();
void allscores();
void highscore();

int main()
{
  int n;
  logo();
  do
  {
  start:
    mainmenu();
    scanf("%d", &n);
    if (n == 0)
      break;
    if (n == 1)
      gamestart();
    else if (n == 2)
      gamerecords();
    else
    {
      printf("----------------------------------\n");
      printf("You Entered Wrong input\n");
      goto start;
    }
  } while (n);

  return 0;
}

void logo()
{
  printf("\n\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
  printf("\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
  printf("\t%%%%%%%%%%%%%%%%%% < QUIZ GAME > %%%%%%%%%%%%%%%%%%\n");
  printf("\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
  printf("\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
}

void mainmenu()
{
  printf("==================================\n");
  printf("        Main Menu\n");
  printf("==================================\n");
  printf("1. start\n2. Game-Records\n0. Exit\n");
  printf("==================================\n");
  printf("Enter your choise:\t");
}

void takeplayername()
{
  printf("==================================\n");
  printf("Enter username:\t");
  scanf(" %[^\n]%*c", name);
}

void gamestart()
{
  int score;
  takeplayername();
  srand(time(NULL));
  readquestion();
  printf("==================================\n");
  printf("Read & understand carefully then\nGive Your answer correctly :)\n");
  score = printquestions();
  printf("----------------------------------\n");
  // printf("Name ->\t%s\n", name);
  printf("%s,You Scored ( %d / 5 )\n", name, score);
  if (saverecord(score))
  {
    printf("----------------------------------\n");
    printf("Record saved successfully\n");
  }
}

void readquestion()
{
  int i = 0, count;
  FILE *fp = fopen("questions.txt", "r");

  if (fp == NULL)
  {
    printf("File error\n");
    // return 0;
  }

  char line[300];

  while (fgets(line, sizeof(line), fp))
  {

    // Read only question lines
    if (line[0] != 'Q')
      continue;

    q[i].quest[0] = '\0';
    strcat(q[i].quest, line);

    // Multi-line question support
    while (fgets(line, sizeof(line), fp))
    {
      if (line[0] == 'A' && line[1] == ')')
        break;
      strcat(q[i].quest, line);
    }

    // Options
    strcpy(q[i].option[0], line);
    fgets(q[i].option[1], 200, fp);
    fgets(q[i].option[2], 200, fp);
    fgets(q[i].option[3], 200, fp);

    // Skip blank line
    fgets(line, sizeof(line), fp);

    // Read answer
    fgets(line, sizeof(line), fp);
    q[i].answer = atoi(line);

    i++; // next question random
  }

  fclose(fp);
}

void randomquestion()
{
  for (int i = 0; i < 50; i++)
  {
    random[i] = i;
  }

  for (int i = 50 - 1; i > 0; i--)
  {
    int j = rand() % (i + 1);

    int temp = random[i];
    random[i] = random[j];
    random[j] = temp;
  }
}

int printquestions()
{
  int score = 0;

  randomquestion();
  for (int k = 0; k < 5; k++)
  {
    int qi = random[k]; // random question random

    printf("----------------------------------\n");
    printf("%d %s", k + 1, q[qi].quest);
    printf("----------------------------------\n");
    printf("%s", q[qi].option[0]);
    printf("%s", q[qi].option[1]);
    printf("%s", q[qi].option[2]);
    printf("%s", q[qi].option[3]);
    score += answercheck(qi);
  }
  return score;
}

int answercheck(int qi)
{
  int score = 0;
  int user_ans;
  char user_answer;
  char right_ans;
start:
  printf("----------------------------------\n");
  printf("Your answer (A/B/C/D):\t");
  scanf(" %c", &user_answer);
  if (user_answer >= 'a' && user_answer <= 'd' || user_answer >= 'A' && user_answer <= 'D')
    ;
  else
    goto start;

  if (user_answer >= 'a' && user_answer <= 'd')
    user_answer -= 32;
  switch (user_answer)
  {
  case 'A':
    user_ans = 1;
    break;
  case 'B':
    user_ans = 2;
    break;
  case 'C':
    user_ans = 3;
    break;
  case 'D':
    user_ans = 4;
    break;
  }

  switch (q[qi].answer)
  {
  case A:
    right_ans = 'A';
    break;
  case B:
    right_ans = 'B';
    break;
  case C:
    right_ans = 'C';
    break;
  case D:
    right_ans = 'D';
    break;
  }

  printf("----------------------------------\n");
  if (user_ans == q[qi].answer)
  {
    score++;
    printf("YES!! Correct Answer\n");
  }
  else
    printf("No!! Wrong Answer,\nCorrect Answer is %c\n", right_ans);
  return score;
}

int saverecord(int score)
{
  FILE *fp = fopen("records.txt", "a");
  if (fp == NULL)
  {
    printf("File error\n");
    return 0;
  }
  fprintf(fp, "%d \t%s\n", score, name);
  fclose(fp);
  return 1;
}

void gamerecords()
{
  int n;
  printf("----------------------------------\n");
start:
  printf("          Game-Records\n");
  printf("----------------------------------\n");
  printf("1. Highest Scorer\n2. All Scores\n");
  printf("----------------------------------\n");
  printf("Enter your choise:\t");
  scanf("%d", &n);
  printf("----------------------------------\n");
  if (n == 1)
    highscore();
  else if (n == 2)
    allscores();
  else
    goto start;
}

void highscore()
{
  int score;
  int high_score = 0;
  char best_player[20];
  printf("   -:All Time Highest Scorer:-\n");
  printf("----------------------------------\n");
  FILE *fp = fopen("records.txt", "r");
  if (fp == NULL)
  {
    printf("File error\n");
    exit(1);
  }
  while (fscanf(fp, "%d %s", &score, name) != EOF)
  {
    if (score > high_score)
    {
      high_score = score;
      strcpy(best_player, name);
    }
  }
  fclose(fp);
  printf("Name  -> %s\n", best_player);
  printf("Score -> %d out of 5\n", high_score);
}

void allscores()
{
  char data;
  FILE *fp = fopen("records.txt", "r");
  if (fp == NULL)
  {
    printf("File error\n");
    exit(1);
  }
  printf("Score - Name\n");
  printf("----------------------------------\n");
  while ((data = fgetc(fp)) != EOF)
    printf("%c", data);
  fclose(fp);
  printf("----------------------------------\n");
}