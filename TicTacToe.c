#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

char matrix[3][3];
int cordiX,cordiY;

void Draw_Rect();
void gotoxy(int x, int y);
void Draw_matrix();
void get_player();
void init_Matrix();
void get_computer();
char Check_win();


int main()
{

    int i=0,check = 1;
    SetConsoleTitle("Tic Tac Toe developed by Raghuwanshi !");
    //Draw_Rect();

    Draw_matrix();
    init_Matrix();


    while(check) {

        get_player();
        get_computer();
        Draw_matrix();
        if(Check_win()=='X'||Check_win()=='0')
        {
            printf(Check_win()=='X'?"\n\nCongratulations you have won !!":"\n\nSorry you have lose !!");
            check = 0;
        }
    }

 /*   int i=0;
    while(i++<=4) {
        get_player();
        get_computer();
      //  Draw_matrix();
    }
   /* int i=0,x,y;
    while(i++<=10) {

    printf("Enter x and Y : ");
    scanf("%d  %d",&x,&y);
        printf("%d  %d\n",Cordi_X(x),Cordi_Y(y));
    }
*/
getch();
}

COORD coord = {0,0}; //set the cordinate 0,0{top most left}
void gotoxy(int x, int y)
{
    coord.X = x,coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void init_Matrix()
{
    auto int i,j;

    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
          matrix[i][j] = ' ';
}

void Draw_Rect()
{
    auto int i;
    gotoxy(0,0);
    printf("%c",201);

    for(i=1; i<120; i++)
    {
        gotoxy(i,0);
        if(i==119)
            printf("%c",187);
        else
            printf("%c",205);
    }

    for(i=1; i<45; i++)
    {
        gotoxy(0,i);
        if(i==7)
            printf("%c",204);
        else
            printf("%c",186);
    }

    gotoxy(0,45);
    printf("%c",200);

    for(i=1; i<45; i++)
    {
        gotoxy(119,i);
        if(i==7)
            printf("%c",185);
        else
            printf("%c",186);
    }

    for(i=1; i<119; i++)
    {
        gotoxy(i,7);
        printf("%c",205);

    }

    gotoxy(119,45);
    printf("%c",188);

    for(i=1; i<119; i++)
    {
        gotoxy(i,45);
        printf("%c",205);

    }
}

void Draw_matrix()
{
    auto int i;

    for(i=0; i<3; i++)
    {
        printf("%c  |%c  |%c  ",matrix[i][0],matrix[i][1],matrix[i][2]);
        printf("\n   |   |  ");
        if(i!=2)
            printf("\n===|===|===\n");
    }
}

void get_player()
{
    int X,Y;

    printf("\nEnter x and y cordinate for your move :");
    scanf("%d %d",&cordiX,&cordiY);

    cordiX--;
    cordiY--;

    if((matrix[cordiX][cordiY] != ' ')||(Check_posi(cordiX,cordiY)==0)||cordiX>=3||cordiY>=3)
    {
        printf("\nInvalid move ! try again !");
        get_player();
    }

    else {
                matrix[cordiX][cordiY] = 'X';

    }
}

int Check_posi(int x,int y)
{
    if(matrix[x][y]!='X'&&matrix[x][y]!='0')
        return 1;
    else
        return 0;
}

void get_computer() {

    int temp1 = rand()%3;

    int temp2 = rand()%3;

    if((matrix[temp1][temp2] != ' ')||(Check_posi(temp1,temp2)==0))
    {
        get_computer();
    }

    else
        matrix[temp1][temp2] = '0';
}

char Check_win() {
    int i;

    for(i=0; i<=2; i++) {
        if((matrix[i][0]==matrix[i][1])&&(matrix[i][0]==matrix[i][2]))
            return matrix[i][0];
        }

    for(i=0; i<=2; i++) {
        if((matrix[0][i]==matrix[1][i])&&(matrix[0][i]==matrix[2][i]))
            return matrix[0][i];
        }

    if(matrix[0][0]==matrix[1][1]&&matrix[0][0]==matrix[2][2])
        return matrix[0][0];

    if(matrix[0][2]==matrix[1][1]&&matrix[0][2]==matrix[2][0])
        return matrix[0][2];
}

int Cordi_X() {

    int temp;
    srand ( time(NULL) );

    temp = rand()%3;

    return temp;
}

int Cordi_Y() {
    int temp;
    srand ( time(NULL) );

    temp = rand()%3;

    return temp;
}
