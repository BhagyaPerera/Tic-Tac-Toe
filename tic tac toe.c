#include<stdio.h>
#include<conio.h>


char square[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
int position[9];

//To print the game Board//
    void designGameBoard(char computerSymbol,char playerSymbol);

//To find the player movement//
    void playerMoving(char playerSymbol,int move,char computerSymbol);

//To find the computer movement//
    void computerMoving(char computerSymbol,char playerSymbol);

//To find the winner//
    void findWinner(char computerSymbol,char playerSymbol,int *winner);


int main(){


        char symbol,computerSymbol,playerSymbol;
        int winner,replay;
        int move=0;
        int lap=1;

do{


    if((lap%4==1)||(lap%4==3)){//when player won the toss//

        printf(" .....Congratulations!!!You won the toss:\n\n");

        printf("Enter the 'X' for play with X and Enter the 'O' for play with O:");
        scanf("%c",&symbol);


        if(symbol=='X'){
            playerSymbol='X';//player select to play withX//
            computerSymbol='O';
        }

        else if(symbol=='O'){
            playerSymbol='O';//player Select to play with O//
            computerSymbol='X';
        }

        else{
            printf("Invalid symbol please Enter the Symbol again:\n\n");
            scanf("%c",&symbol);

                    if(symbol=='X'){
                    playerSymbol='X';//player select to play withX//
                    computerSymbol='O';
                    }

                    else if(symbol=='O'){
                    playerSymbol='O';//player Select to play with O//
                    computerSymbol='X';
                    }



        }

                while(move<10){
                designGameBoard(computerSymbol,playerSymbol);
                playerMoving(playerSymbol,move,computerSymbol);
                computerMoving(computerSymbol,playerSymbol);
                findWinner(computerSymbol,playerSymbol,&winner);
                system("cls");

                    if(winner==1){
                    printf("\n\n\n\n....Congratulations You won!!!......\n");
                    break;
                    }

                    else if(winner==2){
                    printf("\n\n\n\n......You lost the game..Please Try again....\n");
                    break;
                    }

                    else
                    move++;

            }


    }


    else if((lap%4==0)||(lap%4==2)){//computer select to play first//

            printf("\n.................You lost the toss..computer play first...\n");

            if(lap%4==0){
                computerSymbol='X';
                playerSymbol='O';//computer select to play with X//


            }
            else{
                computerSymbol='O';
                playerSymbol='X';//computer select play with O//

            }




        square[1][1]=computerSymbol;

            while(move<10){

                designGameBoard(computerSymbol,playerSymbol);
                playerMoving(playerSymbol,move,computerSymbol);
                computerMoving(computerSymbol,playerSymbol);
                findWinner(computerSymbol,playerSymbol,&winner);
                system("cls");

                if(winner==1){
                   printf("\n\n\n\n\n\n....Congratulations You won!!!......\n");
                    break;
                }
                else if(winner==2){
                    printf("\n\n\n\nYou lost the game..Please Try again....\n");
                    break;
                }

                else
                move++;


          }
    }
    else{
        printf("ERROR\n");
    }


        printf("\n\nTo replay press 1:\n");// To replay game//
        scanf("%d",&replay);
        system("cls");
        lap++;
        move=0;
        square[0][0]=' ';
        square[0][1]=' ';
        square[0][2]=' ';
        square[1][0]=' ';
        square[1][1]=' ';
        square[1][2]=' ';
        square[2][0]=' ';
        square[2][1]=' ';
        square[2][2]=' ';
        winner=0;
        }while(replay==1);

return 0;

}


void designGameBoard(char computerSymbol,char playerSymbol){

        system("cls");
        printf("\n\t\t\t\tTic Tac Toe\n");

        printf("Player  :%c\t\t\t\t",playerSymbol);
        printf("Computer:%c\n",computerSymbol);


        printf("\t\t\t\t ____________________________\n");
        printf("\t\t\t\t|        |         |         |\n");
        printf("\t\t\t\t|    %c   |   %c     |   %c     |\n",square[0][0],square[0][1],square[0][2]);
        printf("\t\t\t\t|        |         |         |\n");
        printf("\t\t\t\t ____________________________\n");
        printf("\t\t\t\t|        |         |         |\n");
        printf("\t\t\t\t|    %c   |   %c     |   %c     |\n",square[1][0],square[1][1],square[1][2]);
        printf("\t\t\t\t|        |         |         |\n");
        printf("\t\t\t\t ____________________________\n");
        printf("\t\t\t\t|        |         |         |\n");
        printf("\t\t\t\t|    %c   |   %c     |   %c     |\n",square[2][0],square[2][1],square[2][2]);
        printf("\t\t\t\t|        |         |         |\n");
        printf("\t\t\t\t ____________________________\n");

}



void playerMoving(char playerSymbol,int move,char computerSymbol){

int choice;
    printf("Choose a square to enter the Symbol:");
    scanf("%d",&choice);

        if((choice==1)&&(square[0][0]==' '))
            square[0][0]=playerSymbol;

        else if((choice==2)&&(square[0][1]==' '))
            square[0][1]=playerSymbol;

        else if((choice==3)&&(square[0][2]==' '))
            square[0][2]=playerSymbol;


        else if((choice==4)&&(square[1][0]==' '))
            square[1][0]=playerSymbol;

        else if((choice==5)&&(square[1][1]==' '))
            square[1][1]=playerSymbol;

        else if((choice==6)&&(square[1][2]==' '))
            square[1][2]=playerSymbol;

        else if((choice==7)&&(square[2][0]==' '))
            square[2][0]=playerSymbol;

        else if((choice==8)&&(square[2][1]==' '))
            square[2][1]=playerSymbol;

        else if((choice==9)&&(square[2][2]==' '))
            square[2][2]=playerSymbol;

        else if(choice>9){
            printf("\n\nInvalid choice\n");
            printf("Please re-enter to the another square:\n\n\n ");
            move--;
            playerMoving(playerSymbol,move,computerSymbol);
        }
        else{
            printf("\n\n*****Square filled*******\n");//when player enter the symbol to filled square//
            printf("Please re-enter:\n\n\n");
            move--;
            playerMoving(playerSymbol,move,computerSymbol);

        }





}

void computerMoving(char computerSymbol,char playerSymbol){

    int row123,row456,row789,row147,row258,row369,row159,row357;



    //calculate row123 value//

            if(((square[0][0]=='X')&&(square[0][1]=='X'))||((square[0][0]=='X')&&(square[0][2]=='X'))||((square[0][1]=='X')&&(square[0][2]=='X')))
                row123=100;

            else if(((square[0][0]=='O')&&(square[0][1]=='O'))||((square[0][0]=='O')&&(square[0][2]=='O'))||((square[0][1]=='O')&&(square[0][2]=='O')))
                row123=1000;

            else if((square[0][0]=='X')||(square[0][1]=='X')||(square[0][2]=='X'))
                row123=9;


            else if((square[0][0]=='O')||(square[0][1]=='O')||(square[0][2]=='O'))
                row123=10;


            else if((square[0][0]==' ')&&(square[0][1]==' ')&&(square[0][2]==' '))
                row123=1;

            else if(((square[0][0]=='X')&&(square[0][1]=='O'))||((square[0][1]=='X')&&(square[0][0]=='O'))||((square[0][0]=='X')&&(square[0][2]=='O'))||((square[0][2]=='X')&&(square[0][0]=='O'))||((square[0][1]=='X')&&(square[0][2]=='O'))||((square[0][2]=='X')&&(square[0][1]=='O')))
                row123=0;

            else
            printf("** ");


    //To calculate 456 row Value//


        if(((square[1][0]=='X')&&(square[1][1]=='X'))||((square[1][0]=='X')&&(square[1][2]=='X'))||((square[1][1]=='X')&&(square[1][2]=='X')))
            row456=100;


        else if(((square[1][0]=='O')&&(square[1][1]=='O'))||((square[1][0]=='O')&&(square[1][2]=='O'))||((square[1][1]=='O')&&(square[1][2]=='O')))
            row456=1000;


        else if((square[1][0]=='X')||(square[1][1]=='X')||(square[1][2]=='X'))
            row456=9;



        else if((square[1][0]=='O')||(square[1][1]=='O')||(square[1][2]=='O'))
            row456=10;


        else if((square[1][0]==' ')&&(square[1][1]==' ')&&(square[1][2]==' '))
            row456=1;


        else if(((square[1][0]=='X')&&(square[1][1]=='O'))||((square[1][1]=='X')&&(square[1][0]=='O'))||((square[1][0]=='X')&&(square[1][2]=='O'))||((square[1][2]=='X')&&(square[1][0]=='O'))||((square[1][1]=='X')&&(square[1][2]=='O'))||((square[0][2]=='X')&&(square[0][1]=='O')))
            row456=0;


        else
            printf(" ");


     //calculate 789row value//

        if(((square[2][0]=='X')&&(square[2][1]=='X'))||((square[2][0]=='X')&&(square[2][2]=='X'))||((square[2][1]=='X')&&(square[2][2]=='X')))
            row789=100;

        else if(((square[2][0]=='O')&&(square[2][1]=='O'))||((square[2][0]=='O')&&(square[2][2]=='O'))||((square[2][1]=='O')&&(square[2][2]=='O')))
            row789=1000;

        else if((square[2][0]=='X')||(square[2][1]=='X')||(square[2][2]=='X'))

            row789=9;

        else if((square[2][0]=='O')||(square[2][1]=='O')||(square[2][2]=='O'))
            row789=10;

        else if((square[2][0]==' ')&&(square[2][1]==' ')&&(square[2][2]==' '))
            row789=1;


        else if(((square[2][0]=='X')&&(square[2][1]=='O'))||((square[2][1]=='X')&&(square[2][0]=='O'))||((square[2][0]=='X')&&(square[2][2]=='O'))||((square[2][2]=='X')&&(square[2][0]=='O'))||((square[2][1]=='X')&&(square[2][2]=='O'))||((square[0][2]=='X')&&(square[2][1]=='O')))
            row789=0;

         else
            printf(" ");


    //Calculate row147 Value//

        if(((square[0][0]=='X')&&(square[1][0]=='X'))||((square[2][0]=='X')&&(square[1][0]=='X'))||((square[0][0]=='X')&&(square[2][0]=='X')))
            row147=100;

        else if(((square[0][0]=='O')&&(square[1][0]=='O'))||((square[2][0]=='O')&&(square[1][0]=='O'))||((square[0][0]=='O')&&(square[2][0]=='O')))
            row147=1000;


        else if((square[0][0]=='X')||(square[1][0]=='X')||(square[2][0]=='X'))
            row147=9;

        else if((square[0][0]=='O')||(square[1][0]=='O')||(square[2][0]=='O'))
            row147='X';

        else if((square[0][0]==' ')&&(square[1][0]==' ')&&(square[2][0]==' '))
            row147=1;

        else if(((square[0][0]=='X')&&(square[1][0]=='O'))||((square[1][0]=='X')&&(square[0][0]=='O'))||((square[2][0]=='X')&&(square[0][0]=='O'))||((square[0][0]=='X')&&(square[2][0]=='O'))||((square[1][0]=='X')&&(square[2][0]=='O'))||((square[2][0]=='X')&&(square[1][0]=='O')))
            row147=0;

        else
            printf(" ");




    //calculate 258 row Value//

        if(((square[0][1]=='X')&&(square[1][1]=='X'))||((square[2][1]=='X')&&(square[1][1]=='X'))||((square[0][1]=='X')&&(square[2][1]=='X')))
            row258=100;

        else if(((square[0][1]=='O')&&(square[1][1]=='O'))||((square[2][1]=='O')&&(square[1][1]=='O'))||((square[0][1]=='O')&&(square[2][1]=='O')))
            row258=1000;

        else if((square[0][1]=='X')||(square[1][1]=='X')||(square[2][1]=='X'))
            row258=9;

        else if((square[0][1]=='O')||(square[1][1]=='O')||(square[2][1]=='O'))
            row258=10;

        else if((square[0][1]==' ')&&(square[1][1]==' ')&&(square[2][1]==' '))
            row258=1;

        else if(((square[1][1]=='X')&&(square[0][1]=='O'))||((square[0][1]=='X')&&(square[1][1]=='O'))||((square[2][1]=='X')&&(square[0][1]=='O'))||((square[0][1]=='X')&&(square[2][1]=='O'))||((square[1][1]=='X')&&(square[2][1]=='O'))||((square[2][1]=='X')&&(square[1][1]=='O')))
            row258=0;

        else
            printf(" ");



    //calculate 369 row value//


        if(((square[0][2]=='X')&&(square[1][2]=='X'))||((square[2][2]=='X')&&(square[1][2]=='X'))||((square[0][2]=='X')&&(square[2][2]=='X')))
            row369=100;

        else if(((square[0][2]=='O')&&(square[1][2]=='O'))||((square[2][2]=='O')&&(square[1][2]=='O'))||((square[0][2]=='O')&&(square[2][2]=='O')))
            row369=1000;


        else if((square[0][2]=='X')||(square[1][2]=='X')||(square[2][2]=='X'))
            row369=9;


        else if((square[0][2]==0)||(square[1][2]==0)||(square[2][2]==0))
            row369='X';

        else if((square[0][2]==1)&&(square[1][2]==8)&&(square[2][2]==9))
            row369=1;

        else if(((square[1][2]=='X')&&(square[0][2]=='O'))||((square[0][2]=='X')&&(square[1][2]=='O'))||((square[2][2]=='X')&&(square[0][2]=='O'))||((square[0][2]=='X')&&(square[2][2]=='O'))||((square[1][2]=='X')&&(square[2][2]=='O'))||((square[2][2]=='X')&&(square[1][2]=='O')))
            row369=0;

        else
            printf(" ");


    //calculate 159row value//



        if(((square[0][0]=='X')&&(square[1][1]=='X'))||((square[2][2]=='X')&&(square[1][1]=='X'))||((square[0][0]=='X')&&(square[2][2]=='X')))

            row159=100;

        else if(((square[0][0]=='O')&&(square[1][1]=='O'))||((square[2][2]=='O')&&(square[1][1]=='O'))||((square[0][0]=='O')&&(square[2][2]=='O')))
            row159=1000;


        else if((square[0][0]=='X')||(square[1][1]=='X')||(square[2][2]=='X'))
            row159=9;


        else if((square[0][0]=='O')||(square[1][1]=='O')||(square[2][2]=='O'))
            row159=10;

        else if((square[0][0]==' ')&&(square[1][1]==' ')&&(square[2][2]==' '))
            row159=1;

        else if(((square[1][1]=='X')&&(square[0][0]=='O'))||((square[0][0]=='X')&&(square[1][1]=='O'))||((square[2][2]=='X')&&(square[0][0]=='O'))||((square[0][0]=='X')&&(square[2][2]=='O'))||((square[1][1]=='X')&&(square[2][2]=='O'))||((square[2][2]=='X')&&(square[1][1]=='O')))
            row159=0;

        else
            printf(" ");



    //calculate 357 row Value//


        if(((square[0][2]=='X')&&(square[1][1]=='X'))||((square[2][0]=='X')&&(square[1][1]=='X'))||((square[0][2]=='X')&&(square[2][0]=='X')))
            row357=100;


        else if(((square[0][2]=='O')&&(square[1][1]=='O'))||((square[2][0]=='O')&&(square[1][1]=='O'))||((square[0][2]=='O')&&(square[2][0]=='O')))
            row357=1000;


        else if((square[0][2]=='X')||(square[1][1]=='X')||(square[2][0]=='X'))
            row357=9;


        else if((square[0][2]=='O')||(square[1][1]=='O')||(square[2][0]=='O'))
            row357=10;


        else if((square[0][2]==' ')&&(square[1][1]==' ')&&(square[2][0]==' '))
            row357=1;


        else if(((square[0][2]=='X')&&(square[1][1]=='O'))||((square[1][1]=='X')&&(square[0][2]=='O'))||((square[2][0]=='X')&&(square[0][2]=='O'))||((square[0][2]=='X')&&(square[2][0]=='O'))||((square[1][1]=='X')&&(square[2][0]=='O'))||((square[2][0]=='X')&&(square[1][1]=='O')))
            row159=0;

        else
            printf(" ");





        //find position value//


        if(square[0][0]==' ')
            position[1]=row123+row147+row159;
        else
            position[1]=0;

        if(square[0][1]==' ')
            position[2]=row123+row258;
        else
            position[2]=0;

        if(square[0][2]==' ')
            position[3]=row123+row357+row369;
        else
            position[3]=0;

        if(square[1][0]==' ')
            position[4]=row147+row456;
        else
            position[4]=0;

        if(square[1][1]==' ')
            position[5]=row456+row159+row357+row258;
        else
            position[5]=0;

        if(square[1][2]==' ')
            position[6]=row456+row369;
        else
            position[6]=0;

        if(square[2][0]==' ')
            position[7]=row789+row147+row357;
        else
            position[7]=0;

        if(square[2][1]==' ')
            position[8]=row789+row258;
        else
            position[8]=0;

        if(square[2][2]==' ')
            position[9]=row789+row369+row159;
        else
            position[9]=0;



//To find the maximum position value//

        int maximum=position[1];
        int i;

        for(i=1;i<10;i++){

            if(position[i]>maximum){
            maximum=position[i];
            }
            i++;
        }


        //move the computer symbol to relevant square//


        if((maximum==position[1])&&(square[0][0]=' '))
             square[0][0]=computerSymbol;

        else if((maximum==position[2])&&(square[0][1]=' '))
             square[0][1]=computerSymbol;

        else if((maximum==position[3])&&(square[0][2]=' '))
            square[0][2]=computerSymbol;

        else if((maximum==position[4])&&(square[1][0]=' '))
              square[1][0]=computerSymbol;

        else if((maximum==position[5])&&(square[1][1]=' '))
              square[1][1]=computerSymbol;


        else if((maximum==position[6])&&(square[1][2]=' '))
              square[1][2]=computerSymbol;


        else if((maximum==position[7])&&(square[2][0]=' '))
              square[2][0]=computerSymbol;


        else if((maximum==position[8])&&(square[2][1]=' '))
              square[2][1]=computerSymbol;


        else if((maximum==position[9])&&(square[2][2]=' '))
             square[2][2]=computerSymbol;


        else
            printf("****");



}

void findWinner(char computerSymbol,char playerSymbol,int*winner ){

    //Game draw  winner:0//
    //Player win winner:1//
    //Computer win winner:2//


            if(square[0][0]==square[0][1]&&square[0][1]==square[0][2]){
                if(square[0][0]==playerSymbol){
                *winner=1;
                }
                else if(square[0][0]==computerSymbol){
                *winner=2;
                }

                else
                designGameBoard(computerSymbol,playerSymbol);


            }

            else if(square[1][0]==square[1][1]&&square[1][1]==square[1][2]){

                if(square[1][0]==playerSymbol){
                *winner=1;
                }

                else if(square[1][0]==computerSymbol){
                *winner=2;
                }


                else
                designGameBoard(computerSymbol,playerSymbol);


            }

            else if(square[2][0]==square[2][1]&&square[2][1]==square[2][2]){

                if(square[2][0]==playerSymbol){
                *winner=1;
                }

                else if(square[2][0]==computerSymbol){
                *winner=2;
                }

                else
                designGameBoard(computerSymbol,playerSymbol);


            }

            else if(square[0][0]==square[1][0]&&square[1][0]==square[2][0]){


                if(square[0][0]==playerSymbol){
                *winner=1;
                }

                else if(square[0][0]==computerSymbol){
                 *winner=2;
                }

                else
                designGameBoard(computerSymbol,playerSymbol);

            }

            else if(square[0][1]==square[1][1]&&square[1][1]==square[2][1]){

                if(square[0][1]==playerSymbol){
                *winner=1;
                }

                else if(square[0][1]==computerSymbol){
                *winner=2;
                }

                else
                designGameBoard(computerSymbol,playerSymbol);

            }


            else if(square[0][2]==square[1][2]&&square[1][2]==square[2][2]){

                if(square[0][2]==playerSymbol){
                *winner=1;
                }

                else if(square[0][2]==computerSymbol){
                *winner=2;
                }

                else
                designGameBoard(computerSymbol,playerSymbol);

            }

             else if(square[0][0]==square[1][1]&&square[1][1]==square[2][2]){

                if(square[0][0]==playerSymbol){
                *winner=1;
                }
                else if(square[0][0]==computerSymbol){
                 *winner=2;
                }
                else
                designGameBoard(computerSymbol,playerSymbol);

             }

             else if(square[2][0]==square[1][1]&&square[1][1]==square[0][2]){

                if(square[2][0]==playerSymbol){
                *winner=1;
                }

                else if(square[2][0]==computerSymbol){
                *winner=2;
                }


                else
                designGameBoard(computerSymbol,playerSymbol);


             }

             else if((square[0][0]!=' ')&&(square[0][1]!=' ')&&(square[0][2]!=' ')&&(square[1][0]!=' ')&&(square[1][1]!=' ')&&(square[1][2]!=' ')&&(square[2][0]!=' ')&&(square[2][1]!=' ')&&(square[2][2]!=' '))
                *winner=0;

            else
                designGameBoard(computerSymbol,playerSymbol);



}
