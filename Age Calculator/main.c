#include <stdio.h>
#include <time.h>

int n;
int year, month, day;
int c_year, c_month, c_day;

time_t t;

struct tm *current;

enum monthnum
{
  jan = 1,
  feb,
  march,
  april,
  may,
  june,
  july,
  aug,
  sept,
  oct,
  nov,
  dec
};

void logo();
void mainmenu();
int takeinput();
int presentdate();
int calculatedays(int);
int leapyear(int);
int calculatemon(int, int);

int main()
{
  logo();
  do
  {
    int t_day;
    mainmenu();
    if (n == 1)
    {
      printf("Hello,I'm going count total day \nYou have passed on Earth\n\n");
      t_day = presentdate() - takeinput();
      printf("---------------------------------\n");
      printf("Total Days =      \t%d\n", t_day);
      printf("---------------------------------\n");
      printf("After all the calculation.... \nMy report says you have passed.. \n%d days on this planet....\nKeep growing...\n", t_day);
    }
  } while (n);
  return 0;
}

void logo()
{
  printf("\n\n\t:::::::::::::::::::::::::::::::::::::::::\n");
  printf("\t:::::::::::::AGE::CALCULATOR:::::::::::::\n");
  printf("\t:::::::::::::::::::::::::::::::::::::::::\n\n");
}

void mainmenu()
{
  printf("=================================\n");
  printf("------------Main Menu------------\n");
start:
  printf("=================================\n");
  printf("1. Open\n0. Exit\n");
  printf("---------------------------------\n");
  printf("Enter your choise:\t");

  scanf("%d", &n);
  printf("---------------------------------\n");
  if (n > 1)
  {
    printf("Entered wrong input!!\n");
    goto start;
  }
}

int takeinput()
{
  int birth_day;
  printf("Enter Birth-Year:\t");
  scanf("%d", &year);
  printf("Enter Birth-Month:\t");
  scanf("%d", &month);
  printf("Enter Birth-Day:\t");
  scanf("%d", &day);
  birth_day = calculatedays(year) + calculatemon(month, year) + day;
  // printf("year = %d\n", birth_day);
  return birth_day;
}

int presentdate()
{
  int birth_days;
  t = time(NULL);
  current = localtime(&t);
  c_year = current->tm_year + 1900;
  c_month = current->tm_mon + 1;
  c_day = current->tm_mday;
  birth_days = calculatedays(c_year) + calculatemon(c_month, c_year) + c_day;
  // printf("Current Date: %d-%d-%d\n", c_day, c_month, c_year);
  // printf("year = %d\n", birth_days);
  return birth_days;
}

int calculatedays(int y)
{
  int p_year = 0, b_day = 0;
  while (p_year != (y - 1))
  {
    if (leapyear(p_year))
      b_day += 366;
    else
      b_day += 365;
    p_year++;
  }
  return b_day;
}

int leapyear(int y)
{
  if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
    return 1;
  else
    return 0;
}

int calculatemon(int m, int y)
{
  int p_m = 1, b_day = 0;
  while (p_m != (m - 1))
  {
    switch (p_m)
    {
    case jan:
      b_day += 31;
      break;
    case feb:
      if (leapyear(y))
        b_day += 29;
      else
        b_day += 28;
      break;
    case march:
      b_day += 31;
      break;
    case april:
      b_day += 30;
      break;
    case may:
      b_day += 31;
      break;
    case june:
      b_day += 30;
      break;
    case july:
      b_day += 31;
      break;
    case aug:
      b_day += 31;
      break;
    case sept:
      b_day += 30;
      break;
    case oct:
      b_day += 31;
      break;
    case nov:
      b_day += 30;
      break;
    case dec:
      b_day += 31;
      break;
    }
    p_m++;
  }
  return b_day;
}