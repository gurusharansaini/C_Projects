#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>



int Heart = 3;
long Score = 0,Heighest=0;
int Heigh =24,width =60;
int game_started = 0;
char choice;
int i,j;
int x=10,y=20;
int Fruits = 0;

FILE * fp;

void Game_started();
void Red_partision();
void Blue_partision();
void Black_partision();
void Border();
void cyan_partision();
void player();
void Move_up();
void Move_down();
void Move_left();
void Move_right();
void Control();
void Fruit_Partision();
void Position_change();
void Lost_Heart();
void conditions();
void Game_over();



void main(){
    clrscr();
     if(game_started ==0){
       Game_started();
   }
    fp = fopen("Game.txt","r");
    fscanf(fp,"%ld",&Heighest);
    fclose(fp);

    Red_partision();
    Blue_partision();
    cyan_partision();
    Black_partision();
    player();
    Control();
getch();
}

void Game_started(){

    game_started = 1;

    window(1,1,80,70);
    textbackground(BLUE);
    clrscr();

    window(10,6,70,20);
    textbackground(BLACK);
    clrscr();


    textcolor(RED);
    gotoxy(23,2); cprintf("Welcome to our game");
    gotoxy(27,5); cprintf("developed by:");

    textcolor(YELLOW);
    gotoxy(5,2); cprintf("----------------:");
    gotoxy(43,2); cprintf(":----------------");



    gotoxy(15,5); cprintf("------------:");
    gotoxy(40,5); cprintf(":------------");

    textcolor(YELLOW);
    gotoxy(27,7); cprintf("VIKASH SAINI");


    textcolor(YELLOW+BLINK);
    gotoxy(5,11); cprintf("Press any key");


    choice = getch();

    if(choice == 'a') exit(0);

    textcolor(YELLOW);
    gotoxy(5,12); cprintf("loading.....");

    textcolor(WHITE);
    gotoxy(5,13);
    for(i = 0;i<53;i++) cprintf("%c",220);

    textcolor(RED);
    gotoxy(5,13);
    for(i = 0;i<53;i++) {
	cprintf("%c",220);
	delay(160);
    }

}


void Red_partision(){

    window(61,1,80,10);
    textbackground(RED);
    clrscr();

    textcolor(WHITE);
    gotoxy(2,2); cprintf("----:CONTROL:----");


    textcolor(BLUE);
    gotoxy(3,4); cprintf("W");
    gotoxy(3,5); cprintf("A");
    gotoxy(3,6); cprintf("S");
    gotoxy(3,7); cprintf("D");
    gotoxy(3,8); cprintf("Space");


    textcolor(WHITE);
    gotoxy(5,4); cprintf(":- For go up");
    gotoxy(5,5); cprintf(":- For got left");
    gotoxy(5,6); cprintf(":- For go down");
    gotoxy(5,7); cprintf(":- For go Right");
    gotoxy(6,8); cprintf(":- For exit");

}

void Blue_partision()
{
    window(61,11,80,17);
    textbackground(BLUE);
    clrscr();


    textcolor(WHITE);
    gotoxy(2,2); cprintf("-----:score:-----");

    textcolor(YELLOW);
    gotoxy(2,4); cprintf("Fruits:- ");
    gotoxy(2,5); cprintf("Hearts:- ");


    gotoxy(2,6);
    if (Heart == 3)
    {
        cprintf("Life:- %c %c %c",3,3,3);
    }
    else if(Heart == 3)
    {
        cprintf("Life:- %c %c",3,3);
    }
    else if (Heart == 1)
    {
        cprintf("Life:- %c",3);
    }
    else{
        textcolor(RED+BLINK);
        cprintf("No Hearts");
    }
    gotoxy(12,4); cprintf("%ld",Score);
    gotoxy(12,5); cprintf("%ld",Heighest);
    

}

void cyan_partision(){

    window(61,18,80,25);
    textbackground(CYAN);
    clrscr();


    textcolor(RED);
    gotoxy(2,2); cprintf("-----:score:------");

    if(game_started == 1){
        textcolor(WHITE);
        gotoxy(8,4); cprintf("PLAYER");
    }
    else if (Heart == -1)
    {
        textcolor(YELLOW);
        gotoxy(7,4); cprintf("GAME OVER");
    }
    
}

void Black_partision(){

    window(1,1,60,25);
    textbackground(BLACK);
    clrscr();
    Border();
}

void Border(){
    for (i=1; i <= Heigh; i++)
    {
        for ( j = 1; j <= width; j++)
        {
            if (i==1||i==Heigh||j==1||j==width)
            {
                printf("%c",219);
            }else
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }
    
}



void player(){
    textcolor(WHITE);
    gotoxy(x,y);cprintf("8");
}

void Control(){

    while(1){
        choice = getch();
        switch(choice){

            case ' ': 
            
                if(Score > Heighest){
                fp = fopen("Game.txt","w");
                fprintf(fp,"%ld",Score);
                fclose(fp);
    }

            
            exit(0);

            case 72:
            case 'W':
            case 'w': Move_up(); break;

            case 75:
            case 'A':
            case 'a':Move_left(); break;

            case 80:
            case 'S':
            case 's':Move_down(); break;

            case 77:
            case 'D':
            case 'd':Move_right(); break;

        }
    }
}

//ok
void Move_up(){

        do{
            if(y != 2){
                y--;
                Black_partision();
                player();
                Fruit_Partision();

            }else if(y == 2){

                Lost_Heart();
            }
            conditions();
            delay(80);
        }while(!kbhit());


}
//ok
void Move_down(){

            do{
            if(y != 23){
                y++;
                Black_partision();
                player();
                Fruit_Partision();

            }else if(y == 23){

                Lost_Heart();
            }
            conditions();
            delay(80);
        }while(!kbhit());

}
//ok
void Move_left(){

        do{
            if(x != 2){
                x--;
                Black_partision();
                player();
                Fruit_Partision();

            }else if(x == 2){

                Lost_Heart();
            }
            conditions();
            delay(80);
        }while(!kbhit());




}



//ok
void Move_right(){

            do{
            if(x != 59){
                x++;
                Black_partision();
                player();
                Fruit_Partision();

            }else if(x == 59){

                Lost_Heart();
            }
            conditions();
            delay(80);
        }while(!kbhit());

}


void Fruit_Partision(){

    textcolor(YELLOW);
    switch(Fruits){
        Lable:
            case 0: gotoxy(52,3);cprintf("%c",5); break;
            case 1: gotoxy(30,7);cprintf("%c",5); break;
            case 2: gotoxy(3,14);cprintf("%c",5); break;
            case 3: gotoxy(10,2);cprintf("%c",5); break;
            case 4: gotoxy(15,17);cprintf("%c",5); break;
            case 5: gotoxy(40,20);cprintf("%c",5); break;
            case 6: gotoxy(17,10);cprintf("%c",5); break;
            case 7: gotoxy(40,13);cprintf("%c",5); break;
            case 8: gotoxy(30,16);cprintf("%c",5); break;
            case 9: gotoxy(52,15);cprintf("%c",5); break;
            case 10: gotoxy(20,14);cprintf("%c",5); break;
            case 11: Fruits = 0; goto Lable;

    }
}


void conditions(){
    if(x==52 && y==3) Position_change();
    else if(x==30 && y==7) Position_change();
    else if(x ==3  && y ==14 ) Position_change();
    else if(x ==10  && y ==2 ) Position_change();
    else if(x ==15  && y ==17 ) Position_change();
    else if(x ==40  && y ==10 ) Position_change();
    else if(x ==17  && y ==13) Position_change();
    else if(x ==30  && y ==16 ) Position_change();
    else if(x ==52  && y ==15 ) Position_change();
    else if(x == 20 && y == 14) Position_change();
    


}

void Position_change(){

    Black_partision();
    player();
    Fruits++;
    Fruit_Partision();
    Score++;
    Blue_partision();
}


void Lost_Heart(){
    Heart--;
    if(Heart != -1){
        Blue_partision();
        window(1,1,60,25);
        textbackground(BLACK);
        clrscr();

        Border();


        textcolor(RED);
        gotoxy(27,7); cprintf("Warning");

        textcolor(GREEN);
        gotoxy(13,8); cprintf("-------------------------------"); 
        gotoxy(13,15); cprintf("-----------------------");

        textcolor(YELLOW);
        gotoxy(20,9); cprintf("You have loss 1 heart");
        gotoxy(25,10); cprintf("And now you ");
        gotoxy(22,11); cprintf("only Have %d Hearts",Heart);


        textcolor(CYAN+BLACK);
        gotoxy(18,17); cprintf("Press any key..");
        getch();
        delay(500);
        main();
    }else{
        game_started =0;
        cyan_partision();
        Heart =3;
        Game_over();
    }
}

void Game_over(){
    if(Score > Heighest){
        fp = fopen("Game.txt","w");
        fprintf(fp,"%ld",Score);
        fclose(fp);
    }

    window(1,1,80,25);
    textbackground(BLACK);
    clrscr();


    Border();
    textcolor(RED);
    gotoxy(25,4); cprintf("Game over");
    gotoxy(26,10); cprintf("Your score");
    gotoxy(27,16); cprintf("choice");
    
    textcolor(GREEN);
    gotoxy(16,5); cprintf("-------------------------------");
    gotoxy(18,11); cprintf("------------------------");
    gotoxy(15,17); cprintf("--------------------");


    textcolor(YELLOW + BLACK);
    gotoxy(25,4); cprintf("Game over");

     textcolor(YELLOW);
    gotoxy(30,12); cprintf("%ld",Score);
    gotoxy(20,18); cprintf("Press 1 for play again");
    gotoxy(23,20); cprintf("Press 2 for exit");


    choice = getch();

    switch(choice){
        case '1':
            Score =0;
            game_started =1;
            main();
            break;
        case '2': exit(0);
        default : Game_over(); 

    }


}

