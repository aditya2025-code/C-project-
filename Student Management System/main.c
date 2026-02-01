#include <stdio.h>
#include <stdlib.h>

FILE *fp = NULL;
FILE *temp = NULL;
int n, n1;

void logo();
void diplaymenu();
void returnmenu();
void studentadd();
void viewstudent();
void searchstud();
void updatestud();
void deletestud();
int idexist(int);

typedef struct student
{
  int id;
  char name[30];
  char dept[20];
} S;

int main()
{
  logo();
  do
  {
    diplaymenu();
    n1 = n;
    if (n == 0)
      break;
    switch (n)
    {
    case 1:
    {
      studentadd();
      break;
    }
    case 2:
    {
      viewstudent();
      break;
    }
    case 3:
    {
      searchstud();
      break;
    }
    case 4:
    {
      updatestud();
      break;
    }
    case 5:
    {
      deletestud();
      break;
    }
    default:
      printf("=================================\n");
      printf("Entered Wrong input\n");
    }
    if (n1 != 1)
    {
    start:
      returnmenu();
      if (n == 2)
        return 0;
      else if (n == 1)
        continue;
      else
      {
        printf("=================================\n");
        printf("Entered Wrong input\n");
        goto start;
      }
    }

  } while (n != 0);
  printf("=================================");
  return 0;
}

void logo()
{
  printf(" _______________________________________\n");
  printf("|                                       |\n");
  printf("|      STUDENT MANAGEMENT SYSTEM        |\n");
  printf("|_______________________________________|\n\n");
}

void diplaymenu()
{
  printf("=================================\n");
  printf("--------Display Main Menu--------\n");
  printf("=================================\n");
  printf("1. Add Student\n2. View Students\n3. Search Student\n4. Update Student\n5. Delete Student\n0. Exit\n");
  printf("=================================\n");
  printf("Enter Your Choice:\t");
  scanf("%d", &n);
}

void returnmenu()
{
  printf("=================================\n");
  printf("---------Return to Menu----------\n");
  printf("=================================\n");
  printf("1. Yes\n2. No\n");
  printf("=================================\nEnter Your Choice:\t");
  scanf(" %d", &n);
}

void studentadd()
{
  printf("=================================\n");
  printf("-----------Add Student-----------\n");
  printf("=================================\n");

  S s1;

  do
  {
    printf("Enter Student ID: ");
    scanf("%d", &s1.id);
    if (idexist(s1.id))
      printf("ID already exist!!\n");
  } while (idexist(s1.id));

  printf("Enter Student Name: ");
  scanf("\n%[^\n]%*c", s1.name);

  printf("Enter Student Department: ");
  scanf("\n%[^\n]%*c", s1.dept);

  fp = fopen("student.txt", "a");
  if (fp == NULL)
  {
    printf("File error");
  }

  fprintf(fp, "%d %s %s\n", s1.id, s1.name, s1.dept);
  fclose(fp);
  printf("=================================\n");
  printf("----Student Added Successfully---\n");
  printf("=================================\n");
  printf("---------Add or Return?----------\n");
  printf("=================================\n");
  printf("1. Add More\n2. Return to Menu\n0. Exit\n");
  printf("=================================\nEnter Your Choice:\t");
  scanf(" %d", &n);

  if (n == 1)
    studentadd();
}

void viewstudent()
{
  printf("=================================\n");
  printf("---------View Student------------\n");
  printf("=================================\n");

  char ch;

  fp = fopen("student.txt", "r");

  if (fp == NULL)
  {
    printf("Error:No file Exist");
    exit(1);
  }

  printf("ID  -  Name  - Dept.\n");

  while ((ch = fgetc(fp)) != EOF)
  {

    printf("%c", ch);
  }

  fclose(fp);

  printf("\n");
}

void searchstud()
{
  printf("=================================\n");
  printf("---------Search Student----------\n");
  printf("=================================\n");

  int key_id;

  printf("Enter Student ID : ");
  scanf("%d", &key_id);
  printf("=================================\n");

  S s2;
  int found = 0;

  fp = fopen("student.txt", "r");

  if (fp == NULL)
  {
    printf("Error:No file Exist");
    exit(1);
  }

  while ((fscanf(fp, "%d %[^ ]%*c %[^\n]%*c", &s2.id, s2.name, s2.dept)) == 3)
  {

    if (s2.id == key_id)
    {
      printf("ID  -  Name  - Dept.\n");
      printf("%d %s %s\n", s2.id, s2.name, s2.dept);
      found = 1;
      break;
    }
  }

  fclose(fp);

  if (found == 0)
    printf("Student Not Found\n");
}

void updatestud()
{
  printf("=================================\n");
  printf("----------Update Student---------\n");
  printf("=================================\n");

  S s3;
  int key_id, found = 0, new_id;

  printf("Enter ID to update: ");
  scanf("%d", &key_id);
  printf("=================================\n");
  fp = fopen("student.txt", "r");
  temp = fopen("temp.txt", "w");

  if (fp == NULL || temp == NULL)
    printf("File error");

  while (fscanf(fp, "%d %[^ ]%*c %[^\n]%*c", &s3.id, s3.name, s3.dept) == 3)
  {
    if (s3.id == key_id)
    {

      printf("Enter Student Name: ");
      scanf("\n%[^\n]%*c", s3.name);
      printf("Enter Student Dept.: ");
      scanf("\n%[^\n]%*c", s3.dept);
      fprintf(temp, "%d %s %s\n", s3.id, s3.name, s3.dept);
      found = 1;
    }

    else
    {
      fprintf(temp, "%d %s %s\n", s3.id, s3.name, s3.dept);
    }
  }

  fclose(fp);
  fclose(temp);

  remove("student.txt");
  rename("temp.txt", "student.txt");

  (found == 1) ? printf("=================================\nUpdated Successfully\n") : printf("ID not found\n");
}

void deletestud()
{
  printf("=================================\n");
  printf("----------Delete Student---------\n");
  printf("=================================\n");

  S s4;
  int key_id, found = 0;

  printf("Enter ID to Delete: ");
  scanf("%d", &key_id);
  printf("=================================\n");

  fp = fopen("student.txt", "r");
  temp = fopen("temp.txt", "w");

  while (fscanf(fp, "%d %[^ ]%*c %[^\n]%*c", &s4.id, s4.name, s4.dept) == 3)
  {
    if (s4.id == key_id)
    {
      found = 1;
    }
    else
    {
      fprintf(temp, "%d %s %s\n", s4.id, s4.name, s4.dept);
    }
  }

  fclose(fp);
  fclose(temp);

  remove("student.txt");
  rename("temp.txt", "student.txt");

  (found == 1) ? printf("=================================\nDeleted Successfully\n") : printf("ID not found\n");
}

int idexist(int x)
{
  S s5;
  fp = fopen("student.txt", "r");
  if (fp == NULL)
  {
    printf("File error\n");
  }
  while (fscanf(fp, "%d %[^ ]%*c %[^\n]%*c", &s5.id, s5.name, s5.dept) == 3)
  {
    if (s5.id == x)
    {
      fclose(fp);
      return 1;
    }
  }
  fclose(fp);
  return 0;
}