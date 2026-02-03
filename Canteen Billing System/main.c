#include <stdio.h>
#include <stdlib.h>

FILE *fp = NULL;
FILE *temp = NULL;

int n, n1, sum, count;
char data;

typedef struct customer
{
  int bill_id;
  char name[20];
  int total_amount;
} Cus;

Cus c1;

void logo();
void mainmenu();
void takename();
void showitemmenu();
void showingbill();
void billidgen();
void saverecord();
void allrecords();

int main()
{
  logo();

  do
  {
    mainmenu();
    switch (n)
    {
    case 1:

      takename();
      sum = 0;
      count = 0;

      do
      {
        showitemmenu();
      } while (n1 != 2);

      c1.total_amount = sum;
      showingbill();
      // printf("Total = %d\n", sum);
      saverecord();

      break;

    case 2:
      allrecords();
      break;
    }
  } while (n);

  return 0;
}

void logo()
{
  printf(" __________________________________\n");
  printf("|                                  |\n");
  printf("|      CANTEEN BILLING SYSTEM      |\n");
  printf("|__________________________________|\n\n");
}

void mainmenu()
{
start:
  printf("++++++++++++++++++++++++++++++++++++\n");
  printf("|             Main Menu            |\n");
  printf("++++++++++++++++++++++++++++++++++++\n");
  printf("1. Start Purchase\n2. All Records\n0. Exit\n");
  printf("++++++++++++++++++++++++++++++++++++\n");
  printf("Enter Your Choise:\t");
  scanf("%d", &n);

  if (n > 2)
  {
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Entered Wrong input\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
  }
}

void takename()
{
  printf("++++++++++++++++++++++++++++++++++++\n");
  printf("Enter Customer Name: ");
  scanf(" %[^\n]%*c", c1.name);
}

void showitemmenu()
{
start:
  printf("++++++++++++++++++++++++++++++++++++\n\n");
  printf("------------Combo-offer------------\n");
  printf("1. Vat,Dal,Sobji            : Rs.30\n");
  printf("2. Vat,Manso-tarkari        : Rs.55\n");
  printf("3. Ruti,Dal,Sobji           : Rs.25\n");
  printf("4. Ruti,Manso-tarkari       : Rs.50\n");
  printf("-------------Spicy-Meal------------\n");
  printf("5. Veg-Chowmine             : Rs.35\n");
  printf("6. Mix-Chowmine             : Rs.55\n");
  printf("7. Egg roll                 : Rs.40\n");
  printf("8. Chicken roll             : Rs.60\n");
  printf("9. Veg Pakora(5piece)       : Rs.35\n");
  printf("10. Chicken Pakora(5piece)  : Rs.60\n");
  printf("---------------Drinks--------------\n");
  printf("11. Cold Drink(100 ml)      : Rs.20\n");
  printf("12. Coca-Cola(100 ml)       : Rs.25\n");
  printf("-----------------------------------\n\n");

  printf("++++++++++++++++++++++++++++++++++++\n");

  printf("Enter Your Choise:\t");
  scanf("%d", &n1);
  printf("++++++++++++++++++++++++++++++++++++\n");

  if (n1 == 1)
  {
    sum += 30;
    count++;
    printf("-----------------------------------\n");
    printf("Vat,Dal,Sobji Purchased\n");
    printf("-----------------------------------\n");
  }
  else if (n1 == 2)
  {
    sum += 55;
    count++;
    printf("-----------------------------------\n");
    printf("Vat,Manso-tarkari Purchased\n");
    printf("-----------------------------------\n");
  }
  else if (n1 == 3)
  {
    sum += 25;
    count++;
    printf("-----------------------------------\n");
    printf("Ruti,Dal,Sobji Purchased\n");
    printf("-----------------------------------\n");
  }
  else if (n1 == 4)
  {
    sum += 50;
    count++;
    printf("-----------------------------------\n");
    printf("Ruti,Manso-tarkari Purchased\n");
    printf("-----------------------------------\n");
  }
  else if (n1 == 5)
  {
    sum += 35;
    count++;
    printf("-----------------------------------\n");
    printf("Veg-Chowmine Purchased\n");
    printf("-----------------------------------\n");
  }
  else if (n1 == 6)
  {
    sum += 55;
    count++;
    printf("-----------------------------------\n");
    printf("Mix-Chowmine Purchased\n");
    printf("-----------------------------------\n");
  }
  else if (n1 == 7)
  {
    sum += 40;
    count++;
    printf("-----------------------------------\n");
    printf("Egg roll Purchased\n");
    printf("-----------------------------------\n");
  }
  else if (n1 == 8)
  {
    sum += 60;
    count++;
    printf("-----------------------------------\n");
    printf("Chicken roll Purchased\n");
    printf("-----------------------------------\n");
  }
  else if (n1 == 9)
  {
    sum += 35;
    count++;
    printf("-----------------------------------\n");
    printf("Veg Pakora(5piece) Purchased\n");
    printf("-----------------------------------\n");
  }
  else if (n1 == 10)
  {
    sum += 60;
    count++;
    printf("-----------------------------------\n");
    printf("Chicken Pakora(5piece) Purchased\n");
    printf("-----------------------------------\n");
  }
  else if (n1 == 11)
  {
    sum += 20;
    count++;
    printf("-----------------------------------\n");
    printf("Cold Drink(100 ml) Purchased\n");
    printf("-----------------------------------\n");
  }
  else if (n1 == 12)
  {
    sum += 25;
    count++;
    printf("-----------------------------------\n");
    printf("Coca-Cola(100 ml) Purchased\n");
    printf("-----------------------------------\n");
  }
  else
  {
    printf("Entered Wrong input\n");
    goto start;
  }

menu:
  printf("------------Want-More-?-------------\n");
  printf("1. Yes\n2. No,Bill..\n");
  printf("------------------------------------\n");
  printf("Enter Your Choise:\t");
  scanf("%d", &n1);

  if (n1 == 1)
    goto start;
  else if (n1 != 2)
  {
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Entered Wrong input\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
    goto menu;
  }
}

void billidgen()
{
  int id;

  fp = fopen("billid.txt", "r");

  if (fp == NULL)
  {
    printf("File Error");
  }

  else
  {
    fscanf(fp, "%d", &id);
  }

  fclose(fp);

  temp = fopen("temp.txt", "w");

  if (temp == NULL)
  {
    printf("file error");
    exit(1);
  }

  c1.bill_id = id + 1;

  fprintf(temp, "%d", c1.bill_id);

  fclose(temp);

  remove("billid.txt");
  rename("temp.txt", "billid.txt");
}

void showingbill()
{
  billidgen();
  printf("++++++++++++++++++++++++++++++++++++\n");
  printf("\n--------------Bill--------------\n");
  printf("Billing id ->\t%d\n", c1.bill_id);
  printf("Name       ->\t%s\n", c1.name);
  printf("Total bill ->\tRs.%d/-\n", c1.total_amount);
  printf("--------------------------------\n\n");
}

void saverecord()
{
  fp = fopen("All_records.txt", "a");

  if (fp == NULL)
  {
    printf("File Error");
  }

  fprintf(fp, "%d  %s  Rs.%d/-\n", c1.bill_id, c1.name, c1.total_amount);

  fclose(fp);
}

void allrecords()
{
  printf("++++++++++++++++++++++++++++++++++++\n");
  printf("ID  -  Name  - Amount Purchased\n");
  printf("-------------------------------\n");

  fp = fopen("All_records.txt", "r");

  if (fp == NULL)
  {
    printf("File Error");
  }

  while ((data = fgetc(fp)) != EOF)
    printf("%c", data);

  fclose(fp);

  printf("-------------------------------\n");
}