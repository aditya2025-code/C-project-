#include <stdio.h>

// char board[3][3] = {
//     {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int choise, move_x, move_y, count;
int player_x = 1, player_y = 2;

void logo();
void mainmenu();
void rule();
void diplayboard(char board[][3]);
void diplayboard2();
void takemove(char board[][3]);
int validatemove(char board[][3], int);
void updateboard(char board[][3], int, int);
int checkwin(char board[][3], int, int);
int checkdraw(char board[][3]);

int main()
{
  logo();
  do
  {
    mainmenu();
    if (choise == 1)
    {
      char board[3][3] = {
          {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
      rule();
      diplayboard2();
      takemove(board);
    }
  } while (choise);
  printf("\n");
  return 0;
}

void logo()
{
  printf("\n\n\t-----+------+-----\n");
  printf("\t TIC |  TAC | TOE \n");
  printf("\t-----+------+-----\n\n");
}

void mainmenu()
{
start:
  printf("====================================\n");
  printf("              Main-Menu\n");
  printf("====================================\n");
  printf("1. Start\n0. Exit\n");
  printf("====================================\n");
  printf("Enter Your Choise:\t");
  scanf("%d", &choise);
  printf("====================================\n");
  if (choise > 1)
  {
    printf("Entered wrong input!!\n");
    goto start;
  }
}

void rule()
{
  printf("------------------------------------\n");
  printf("              :Rule: \n");
  printf("------------------------------------\n");
  printf("IKYK but still I have to tell you \nthat this is a Multiplayer game \nwhere player 'X' have to input the \nvalid cell no. & the other player'O' \nalso until the game win or draw\n");
  printf("------------------------------------\n");
}

void diplayboard(char board[][3])
{
  printf("\t  %c   |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
  printf("\t------+-----+------\n");
  printf("\t  %c   |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
  printf("\t------+-----+------\n");
  printf("\t  %c   |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
}

void diplayboard2()
{

  printf("\t  1   |  2  |  3  \n");
  printf("\t------+-----+------\n");
  printf("\t  4   |  5  |  6  \n");
  printf("\t------+-----+------\n");
  printf("\t  7   |  8  |  9  \n");
}

void takemove(char board[][3])
{
  count = 0;
  do
  {
  start:
    printf("------------------------------------\n");
    printf("Player X, enter your move:\t ");
    scanf("%d", &move_x);
    printf("------------------------------------\n");
    if (validatemove(board, move_x))
    {
      count++;
      // printf("Move Valid :)\n");
      updateboard(board, move_x, player_x);
      printf("------------------------------------\n");
      diplayboard(board);
      if (checkwin(board, player_x, count))
        break;
      if (count > 7)
      {
        if (checkdraw(board) == 0)
          break;
      }
    }
    else
    {
      printf("Move invalid :/\n");
      goto start;
    }
    printf("------------------------------------\n");
  menu:
    printf("Player O, enter your move:\t ");
    scanf("%d", &move_y);
    printf("------------------------------------\n");
    if (validatemove(board, move_y))
    {
      count++;
      // printf("Move Valid :)\n");
      updateboard(board, move_y, player_y);
      printf("------------------------------------\n");
      diplayboard(board);
      if (checkwin(board, player_y, count))
        break;
    }
    else
    {
      printf("Move invalid :/\n");
      printf("------------------------------------\n");
      goto menu;
    }
  } while (checkdraw(board));
}

int validatemove(char board[][3], int n)
{
  if (n >= 0 && n <= 9)
  {
    switch (n)
    {
    case 1:
      if (board[0][0] == ' ')
        return 1;
      break;
    case 2:
      if (board[0][1] == ' ')
        return 1;
      break;
    case 3:
      if (board[0][2] == ' ')
        return 1;
      break;
    case 4:
      if (board[1][0] == ' ')
        return 1;
      break;
    case 5:
      if (board[1][1] == ' ')
        return 1;
      break;
    case 6:
      if (board[1][2] == ' ')
        return 1;
      break;
    case 7:
      if (board[2][0] == ' ')
        return 1;
      break;
    case 8:
      if (board[2][1] == ' ')
        return 1;
      break;
    case 9:
      if (board[2][2] == ' ')
        return 1;
      break;
    }
  }
  return 0;
}

void updateboard(char board[][3], int x, int player)
{
  switch (x)
  {
  case 1:
    if (player == 1)
      board[0][0] = 'X';
    else
      board[0][0] = 'O';
    break;
  case 2:
    if (player == 1)
      board[0][1] = 'X';
    else
      board[0][1] = 'O';
    break;
  case 3:
    if (player == 1)
      board[0][2] = 'X';
    else
      board[0][2] = 'O';
    break;
  case 4:
    if (player == 1)
      board[1][0] = 'X';
    else
      board[1][0] = 'O';
    break;
  case 5:
    if (player == 1)
      board[1][1] = 'X';
    else
      board[1][1] = 'O';
    break;
  case 6:
    if (player == 1)
      board[1][2] = 'X';
    else
      board[1][2] = 'O';
    break;
  case 7:
    if (player == 1)
      board[2][0] = 'X';
    else
      board[2][0] = 'O';
    break;
  case 8:
    if (player == 1)
      board[2][1] = 'X';
    else
      board[2][1] = 'O';
    break;
  case 9:
    if (player == 1)
      board[2][2] = 'X';
    else
      board[2][2] = 'O';
    break;
  }
}

int checkwin(char board[][3], int player, int check)
{
  if (check > 4)
  {
    if ((board[0][0] == board[0][1] && board[0][1] == board[0][2]) || (board[1][0] == board[1][1] && board[1][1] == board[1][2]) || (board[2][0] == board[2][1] && board[2][1] == board[2][2]))
    {
      printf("------------------------------------\n");
      if (player == 1)
        printf("Player X is winner!!\n");
      else
        printf("Player O is winner!!\n");
      return 1;
    }
    else if ((board[0][0] == board[1][0] && board[1][0] == board[2][0]) || (board[0][1] == board[1][1] && board[1][1] == board[2][1]) || (board[0][2] == board[1][2] && board[1][2] == board[2][2]))
    {
      printf("------------------------------------\n");
      if (player == 1)
        printf("Player X is winner!!\n");
      else
        printf("Player O is winner!!\n");
      return 1;
    }
    else if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
      printf("------------------------------------\n");
      if (player == 1)
        printf("Player X is winner!!\n");
      else
        printf("Player O is winner!!\n");
      return 1;
    }
  }
  return 0;
}

int checkdraw(char board[][3])
{
  int i, j, c = 0;
  for (int i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      if (board[i][j] == 'X' || board[i][j] == 'O')
        c++;
    }
  }
  if (c == 9)
  {
    printf("------------------------------------\n");
    printf("Game Draw,better luck next time\n");
    return 0;
  }
  else
    return 1;
}