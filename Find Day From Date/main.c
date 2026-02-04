#include <stdio.h>

FILE *fp = NULL;

int year, month, date;
int total_days, refer_year;
int refer_month;
int day, weekd, n;
char dataprint;
char month_nam[12][10] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "Augest",
    "September",
    "October",
    "November",
    "December"};
char week_day[7][10] = {
    "Saterday",
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday"};

void logo();
void mainmenu();
void takeinput();
void yeardays();
void monthdays();
void checkmonth();
void finalday();
void calculateday();
void savetheday();
void showdata();

int main()
{
  logo();
  do
  {
    mainmenu();
    if (n == 1)
      calculateday();
    else if (n == 2)
      showdata();
  } while (n != 0);
  return 0;
}

void logo()
{
  printf("\n\t\t#######################################\n");
  printf("\t\t########### DAY CALCULATOR ############\n");
  printf("\t\t#######################################\n\n");
}

void mainmenu()
{
  printf("\t\t=======================================\n");
  printf("\t\t--------------Main-Menu----------------\n");
  printf("\t\t=======================================\n");
  printf("\t\t1. Open Day Calculator\n");
  printf("\t\t2. Show All Saved Dates\n");
  printf("\t\t0. Exit\n");
  printf("\t\t=======================================\n");
  printf("\t\tEnter Your Choise:\t");
  scanf("%d", &n);
}

void takeinput()
{
start:
  printf("\t\t=======================================\n");
  printf("\t\t-> Enter The Year: ");
  scanf("%d", &year);
  if (year < 1600)
  {
    printf("\t\t--------x---------x----------x---------\n");
    printf("\t\t%d is too old to calculate,\n\t\ttry after 1600\n", year);
    printf("\t\t--------x---------x----------x---------\n");
    goto start;
  }
menu:
  printf("\t\t-> Enter The Month(1-12): ");
  scanf("%d", &month);
  if (month > 12 || month < 1)
  {
    printf("\t\t--------x---------x----------x---------\n");
    printf("\t\t%d is not a month number,\n\t\ttry between 1 to 12\n", month);
    printf("\t\t--------x---------x----------x---------\n");
    goto menu;
  }
end:
  printf("\t\t-> Enter The Date(1-31): ");
  scanf("%d", &date);
  if (date > 31 || date < 1)
  {
    printf("\t\t--------x---------x----------x---------\n");
    printf("\t\t%d is not any month day,\n\t\ttry between 1 to 31\n", date);
    printf("\t\t--------x---------x----------x---------\n");
    goto end;
  }
  printf("\t\t=======================================\n");
}

void yeardays()
{
  total_days = 0;
  refer_year = 1600;
  while (refer_year < year)
  {
    total_days += 365;
    if ((refer_year % 400 == 0) || (refer_year % 4 == 0 && refer_year % 100 != 0))
      total_days++;
    refer_year++;
  }
}

void monthdays()
{
  refer_month = 1;
  while (refer_month < month)
  {
    switch (refer_month)
    {
    case 1:
      total_days += 31;
      break;
    case 2:
      total_days += 28;
      if ((refer_year % 400 == 0) || (refer_year % 4 == 0 && refer_year % 100 != 0))
        total_days++;
      break;
    case 3:
      total_days += 31;
      break;
    case 4:
      total_days += 30;
      break;
    case 5:
      total_days += 31;
      break;
    case 6:
      total_days += 30;
      break;
    case 7:
      total_days += 31;
      break;
    case 8:
      total_days += 31;
      break;
    case 9:
      total_days += 30;
      break;
    case 10:
      total_days += 31;
      break;
    case 11:
      total_days += 30;
      break;
    case 12:
      total_days += 31;
      break;
    }
    refer_month++;
  }
}

void finalday()
{
  printf("\t\t%d, %s, %d ->", date, month_nam[month - 1], year);
  total_days += (date - 1);
  day = total_days % 7;
  switch (day)
  {
  case 0:
    printf("\tSaterday\n");
    weekd = 0;
    break;
  case 1:
    printf("\tSunday\n");
    weekd = 1;
    break;
  case 2:
    printf("\tMonday\n");
    weekd = 2;
    break;
  case 3:
    printf("\tTuesday\n");
    weekd = 3;
    break;
  case 4:
    printf("\tWednesday\n");
    weekd = 4;
    break;
  case 5:
    printf("\tThursday\n");
    weekd = 5;
    break;
  case 6:
    printf("\tFriday\n");
    weekd = 6;
    break;
  }
  savetheday();
}

void calculateday()
{
  takeinput();
  yeardays();
  monthdays();
  finalday();
}

void savetheday()
{
  fp = fopen("saved_year.txt", "a");
  if (fp == NULL)
    printf("Fill error\n");
  fprintf(fp, "\t\t%d, %s, %d -> %s\n", year, month_nam, date, week_day[weekd]);
  fclose(fp);
}

void showdata()
{
  printf("\t\t=======================================\n");
  printf("\t\t-------DATE-------------DAY------------\n");
  fp = fopen("saved_year.txt", "r");
  if (fp == NULL)
    printf("Fill error\n");
  while ((dataprint = fgetc(fp)) != EOF)
  {
    printf("%c", dataprint);
  }
  fclose(fp);
  printf("\t\t---------------------------------------\n");
}