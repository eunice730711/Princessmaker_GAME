#include <allegro.h>
#include"picture.h"
#include"control.h"
#include"data.h"
#include<stdio.h>
#include<time.h>
void move_character(BITMAP **buffer,BITMAP **sprite,BITMAP **base,int *pic_positiony,int *pic_positionx,int frame[],int rs,int ls,int us,int ds)
{
    blit( *base, *buffer, 0, 0, 0, 0,  SCREEN_W,  SCREEN_H );
    if ((key[KEY_LEFT])&&(!key[KEY_RIGHT])&&(!key[KEY_UP])&&(!key[KEY_DOWN]))//Left
    {
        draw_sprite(screen,*buffer,0,0);
        switch(frame[0])
        {
        case 0:
            blit(*sprite,*buffer,0, 79,*pic_positionx ,*pic_positiony,46,79);
            break;
        case 1:
            blit(*sprite,*buffer,54, 79,*pic_positionx ,*pic_positiony,46,79);
            break;
        case 2:
            blit(*sprite,*buffer,106, 79,*pic_positionx ,*pic_positiony,46,79);
            break;
        }
        draw_sprite(screen,*buffer,0,0);
        if (ls!=0)
        {
            *pic_positionx -=5;
        }
        frame[0]++;
    }
    else if((!key[KEY_LEFT])&&(key[KEY_RIGHT])&&(!key[KEY_UP])&&(!key[KEY_DOWN]))     //Right
    {
        draw_sprite(screen,*buffer,0,0);
        switch(frame[1])
        {
        case 0:
            blit(*sprite,*buffer,0, 161,*pic_positionx ,*pic_positiony,46,79);
            break;
        case 1:
            blit(*sprite,*buffer,52, 161,*pic_positionx ,*pic_positiony,46,79);
            break;
        case 2:
            blit(*sprite,*buffer,106, 161,*pic_positionx ,*pic_positiony,46,79);
            break;

        }
        draw_sprite(screen,*buffer,0,0);
        if (rs!=0)
        {
            *pic_positionx +=5;
        }
        frame[1]++;
    }
    else if((!key[KEY_LEFT])&&(!key[KEY_RIGHT])&&(key[KEY_UP])&&(!key[KEY_DOWN]))  //up
    {
        draw_sprite(screen,*buffer,0,0);
        switch(frame[2])
        {
        case 0:
            blit(*sprite,*buffer,3, 243,*pic_positionx ,*pic_positiony,46,79);
            break;
        case 1:
            blit(*sprite,*buffer,56, 243,*pic_positionx ,*pic_positiony,46,79);
            break;
        case 2:
            blit(*sprite,*buffer,109, 243,*pic_positionx ,*pic_positiony,46,79);
            break;
        }
        draw_sprite(screen,*buffer,0,0);
        if (us!=0)
        {
            *pic_positiony -=5;
        }
        frame[2]++;
    }
    else if ((!key[KEY_LEFT])&&(!key[KEY_RIGHT])&&(!key[KEY_UP])&&(key[KEY_DOWN])) //down
    {
        draw_sprite(screen,*buffer,0,0);
        switch(frame[3])
        {
        case 0:
            blit(*sprite,*buffer,0, 0,*pic_positionx ,*pic_positiony,46,79);
            break;
        case 1:
            blit(*sprite,*buffer,56, 0,*pic_positionx ,*pic_positiony,46,79);
            break;
        case 2:
            blit(*sprite,*buffer,109, 0,*pic_positionx ,*pic_positiony,46,79);
            break;
        }
        draw_sprite(screen,*buffer,0,0);
        if (ds!=0)
        {
            *pic_positiony +=5;
        }
        frame[3]++;
    }
    for(int i=0; i<4; i++)
    {
        if(frame[i]==3)
        {
            frame[i]=0;
        }
    }
    readkey();
    rest(50);
    clear_bitmap(*buffer);
}
void map_limit(int pic_positionx,int pic_positiony,int *ls,int *ds,int *us,int *rs)
{
    ///-------------------------------------------------- -----Limite Left Side

    if ((pic_positionx==335 && pic_positiony<=170 && pic_positiony>=105)||(pic_positionx==290 && pic_positiony<=180 && pic_positiony>=120)||(pic_positionx<=195 && pic_positiony<=270 && pic_positiony>=200) ///Limite Left Side
            ||(pic_positionx==260 && pic_positiony<=230 && pic_positiony>=220)||(pic_positionx==270 && pic_positiony<=240 && pic_positiony>=230)||(pic_positionx==280 && pic_positiony<=250 && pic_positiony>=240)
            ||(pic_positionx==290 && pic_positiony<=260 && pic_positiony>=250)||(pic_positionx<=300 && pic_positiony<=565 && pic_positiony>=260)||(pic_positionx<=305 && pic_positiony<=600 && pic_positiony>=565)
            ||(pic_positionx==245 && pic_positiony<=620 && pic_positiony>=600)||(pic_positionx==595 && pic_positiony<=125 && pic_positiony>=105))
    {
        *ls=0;
    }
    else
    {
        *ls=1;
    }
    ///------------------------------------------------Limite Right Side---
    if ((pic_positionx>=720 && pic_positiony<=177 && pic_positiony>=105)||(pic_positionx==640 && pic_positiony>=140 && pic_positiony<=340 )||(pic_positionx>=825 && pic_positiony>=330 && pic_positiony<=370 )  ///----Limite Right Side---
            ||(pic_positionx>=750 && pic_positiony>=370 && pic_positiony<=385 )||(pic_positionx>=740 && pic_positiony>=385 && pic_positiony<=400 )||(pic_positionx>=730 && pic_positiony>=400 && pic_positiony<=415 )
            ||(pic_positionx>=720 && pic_positiony>=415 && pic_positiony<=430 )||(pic_positionx>=710 && pic_positiony>=430 && pic_positiony<=445 )||(pic_positionx>=700 && pic_positiony>=445 && pic_positiony<=460 )
            ||(pic_positionx>=690 && pic_positiony>=460 && pic_positiony<=475 )||(pic_positionx>=680 && pic_positiony>=475 && pic_positiony<=490 )||(pic_positionx==700 && pic_positiony>=490 && pic_positiony<=610 )
            ||(pic_positionx==220 && pic_positiony>=215 && pic_positiony<=250 )||(pic_positionx==535 && pic_positiony>=105 && pic_positiony<=135 )||(pic_positionx==270 && pic_positiony>=105 && pic_positiony<=175 )
            ||(pic_positionx==610 && pic_positiony>=250 && pic_positiony<=360 ))
    {
        *rs=0;
    }
    else
    {
        *rs=1;
    }
    /// -------------------------------------------------Limite Up Side---
    if ((pic_positiony<=105)||(pic_positionx>=640 && pic_positionx<=745 && pic_positiony==345 )||(pic_positionx>=690 && pic_positionx<=700 && pic_positiony==495)||(pic_positionx>=700 && pic_positionx<=760 && pic_positiony==595 )   ///--Limite Up Side---
            ||(pic_positionx>=215 && pic_positionx<=245 && pic_positiony==625 )||(pic_positionx>=245 && pic_positionx<=305 && pic_positiony==595 )||(pic_positionx>=255 && pic_positionx<=335 && pic_positiony<=190 )||(pic_positionx>=200 && pic_positionx<=255 && pic_positiony<=150 )
            ||(pic_positionx>=535 && pic_positionx<=590 && pic_positiony==135 )||(pic_positionx>=635 && pic_positionx<=675 && pic_positiony==360 ))
    {
        *us=0;
    }
    else
    {
        *us=1;
    }

/// ----------------------------------------------------------------------Limite Down Side---
    if ((pic_positionx>=640 &&pic_positionx<=720 && pic_positiony==125)||(pic_positionx<=830 && pic_positionx>=765 && pic_positiony==370)||(pic_positionx<=765 && pic_positionx>=755 && pic_positiony==385)  ///--Limite Down Side-
            ||(pic_positionx<=755 && pic_positionx>=745 && pic_positiony==400)||(pic_positionx<=745 && pic_positionx>=735 && pic_positiony==415)||(pic_positionx<=735 && pic_positionx>=725 && pic_positiony==430)
            ||(pic_positionx<=725 && pic_positionx>=715 && pic_positiony==445)||(pic_positionx<=715 && pic_positionx>=705 && pic_positiony==460)||(pic_positionx<=705 && pic_positionx>=695 && pic_positiony==475)
            ||(pic_positionx<=695 && pic_positionx>=685 && pic_positiony==490)||(pic_positionx<=230 && pic_positionx>=180 && pic_positiony==250)||(pic_positionx<=270 && pic_positionx>=230 && pic_positiony==225)
            ||(pic_positionx<=285 && pic_positionx>=270 && pic_positiony==250)||(pic_positionx<=300 && pic_positionx>=285 && pic_positiony==275)||(pic_positionx<=310 && pic_positionx>=300 && pic_positiony==565)
            ||(pic_positionx<=640 && pic_positionx>=630 && pic_positiony==250)||(pic_positionx<=630 && pic_positionx>=620 && pic_positiony==320)||( pic_positiony>=650))
    {
        *ds=0;
    }
    else
    {
        *ds=1;
    }
}
void go_to_places(BITMAP *home,BITMAP *church,BITMAP *ch_opt,BITMAP *pub,BITMAP *pub_opt,FONT *font3,BITMAP *school,BITMAP **buffer,int pic_positionx,int pic_positiony,int *i,int *day,int *go_in,Player *p)
{
    int cx=10,cy=80,px=30,py=158,sy=430;
    *go_in=0; //--for home
    if (pic_positionx<=190 && pic_positiony<=200 && pic_positiony>=105) ///------------------------ Go Home
    {
        *go_in=1;
        *day-=1;
    }
    else if (pic_positionx<=205 && pic_positiony>=620) /// ******************************* Go Church
    {
        *go_in=2;
        create_buffer(buffer);
        do
        {
            if (key[KEY_UP]&&cy>=145)
            {
                cy-=65;
            }
            if (key[KEY_DOWN]&&cy<=145)
            {
                cy+=65;
            }
            rest(200);
            draw_sprite(screen,*buffer,0,0);
            blit( church, *buffer, 0,0, 0, 0,  SCREEN_W,  SCREEN_H );
            draw_sprite(screen,*buffer,0,0);
            blit(ch_opt,*buffer,0,0,cx,cy,100,100);
            draw_sprite(screen, *buffer, 0,0);
        }
        while(!key[KEY_ENTER]);
        Church_Get_Points(cy,p,font3);
    }
    else if (pic_positionx>=745 && pic_positiony<=325 && pic_positiony>=265)
    {
        ///------------------------------------------------ Go to school
        int i=0;
        *go_in=3;
        create_buffer(buffer);
        do
        {
            i=school1(buffer,font3,school,&sy,&i);
            readkey();
        }
        while(!key[KEY_ENTER]);
        School_Get_Points(i,p,font3,p->money);
    }
    else if (pic_positionx>=760 && pic_positiony>=595)
    {
        ///--+++++++++++++++++++++++++++++++++++++++----------- Go Pub
        *go_in=4;
        do
        {
            rest(150);
            if (key[KEY_UP]&&py>=258)
            {
                py-=100;

            }
            if (key[KEY_DOWN]&&py<=258)
            {
                py+=100;

            }
            draw_sprite(screen,*buffer,0,0);
            blit(pub, *buffer, 0,0, 0, 0,  SCREEN_W,  SCREEN_H );
            draw_sprite(screen,*buffer,0,0);
            blit(pub_opt,*buffer,0,0,px ,py,100,100);
            draw_sprite(screen, *buffer, 0,0);
        }
        while(!key[KEY_ENTER]);
        Pub_Get_Points(py,p,font3);
    }

}
void Meet_People(FONT *font3,int pic_positionx,int pic_positiony)
{
    int chance=0;
    if ((pic_positionx>=280 &&pic_positionx<=325&& pic_positiony==190) ||(pic_positionx==335 &&pic_positiony>=115&& pic_positiony<=165))
    {
        ///--+++++++++++++++++++++++++++++++++++++++----------- Meet girl
        srand(time(0));
        chance=rand()%3;
        switch(chance)
        {
        case 0:
            textprintf_ex(screen, font3, 25, 100,makecol(255,255,255), -1,"Hello~do you really known the game rules?");
            textprintf_ex(screen, font3, 25, 125,makecol(255,255,255), -1,"You have one month and the game will over!");
            break;
        case 1:
            textprintf_ex(screen, font3, 220, 100,makecol(255,255,255), -1,"Hey! Do you know the yellow");
            textprintf_ex(screen, font3, 220, 125,makecol(255,255,255), -1,"bear has a lot of secrets?");
            break;
        case 2:
            textprintf_ex(screen, font3, 240, 125,makecol(255,255,255), -1,"I have met you before!");
            break;
        }
        readkey();
        readkey();

    }
    else if ((pic_positionx>=545 &&pic_positionx<=595&& pic_positiony==135) ||(pic_positionx>=535 &&pic_positionx<=595 &&pic_positiony>=105&& pic_positiony<=130))
    {
        ///--+++++++++++++++++++++++++++++++++++++++----------- Meet boy
        srand(time(0));
        chance=rand()%3;
        switch(chance)
        {
        case 0:
            textprintf_ex(screen, font3, 430, 45,makecol(255,255,255),makecol(0,0,0),"The house at the lower right corner");
            textprintf_ex(screen, font3, 430, 70,makecol(255,255,255),makecol(0,0,0),"is the pub! You can gamble there!");
            break;
        case 1:
            textprintf_ex(screen, font3, 430, 70,makecol(255,255,255),makecol(0,0,0),"The yellow bear is my friend!");
            break;
        case 2:
            textprintf_ex(screen, font3, 450, 70,makecol(255,255,255), makecol(0,0,0),"Hey!! DON'T BOTHER ME!");
            break;
        }
        readkey();
        readkey();
    }
    else if ((pic_positionx>=640 &&pic_positionx<=685&& pic_positiony==360) ||(pic_positionx==610 &&pic_positiony>=305&& pic_positiony<=360))
    {
        ///--+++++++++++++++++++++++++++++++++++++++----------- Meet bear
        srand(time(0));
        chance=rand()%3;
        switch(chance)
        {
        case 0:
            textprintf_ex(screen, font3, 630, 302,makecol(255,255,255),-1, "MO~Ma50v50");
            textprintf_ex(screen, font3, 630, 300,makecol(255,0,0),-1, "MO~Ma50v50");
            break;
        case 1:
            textprintf_ex(screen, font3, 630, 302,makecol(255,255,255),-1,"MO~~C15#I15!bq");
            textprintf_ex(screen, font3, 630, 300,makecol(255,0,0),-1,"MO~~C15#I15!bq");
            break;
        case 2:
            textprintf_ex(screen, font3, 630, 302,makecol(255,255,255),-1, "MO~~~T150s50~");
            textprintf_ex(screen, font3, 630, 300,makecol(255,0,0),-1, "MO~~~T150s50~");
            break;
        }
        readkey();
        readkey();
    }
}
void Input_player(char name[],BITMAP **buffer,int *num,BITMAP *base,FONT *font1)
{
    int  newkey   = readkey();
    char ASCII    = newkey ;
    /* a character key was pressed; add it to the string */
    if(ASCII >= 32 && ASCII <= 126)
    {
        name[*num] = ASCII;
        *num+=1;
        name[*num] = '\0';
    }
    else if(key[KEY_BACKSPACE])
    {

        if (*num > 0) *num-=1;
        name[*num] = '\0';
    }
    clear(*buffer);
    blit(base,*buffer,0, 0,0,0,SCREEN_W,SCREEN_H);
    textout_ex(*buffer, font1, name, 523, 319,  makecol( 255, 255, 255),-1);
    textout_ex(*buffer, font1, name, 525, 318,  makecol( 0, 0, 255),-1);
    blit(*buffer, screen, 0, 0, 0, 0, 960, 640);
}
int menu(BITMAP **buffer1,FONT *font1,BITMAP *main,int *y,int *i)
{
    char manu[4][15]= { "Start Game","Load Game","Records","Exit"};
    int position[4]= {115,165,215,265};
    blit( main, *buffer1, 0,0, 0, 0,  SCREEN_W,  SCREEN_H );
    for(int i=0; i<4; i++)
    {
        textprintf_ex(*buffer1, font1, 180, position[i],makecol(255, 255, 0), -1,manu[i] );
    }
    if (key[KEY_UP]&&*y>115&&*i>0)
    {
        *y-=50;
        *i-=1;
    }
    if (key[KEY_DOWN]&&*y<265&&*i<3)
    {
        *y+=50;
        *i+=1;
    }
    textprintf_ex(*buffer1, font1, 180, *y,makecol(255, 255, 255), -1, manu[*i]);
    blit( *buffer1, screen, 0, 0, 0, 0,  SCREEN_W,  SCREEN_H );
    clear(*buffer1);
    clear_keybuf();
    return *i;
}
int school1(BITMAP **buffer1,FONT *font6,BITMAP *school,int *sy,int *i)
{
    char school_s[6][15]= { "Painting"," Dance"," Scince","Fencing"," Magic","  Exit"};
    int position[6]= {430,460,490,520,550,580};
    blit( school, *buffer1, 0,0, 0, 0,  SCREEN_W,  SCREEN_H );
    for(int i=0; i<6; i++)
    {
        textprintf_ex(*buffer1, font6, 110, position[i],makecol(0,0,255), -1,school_s[i] );
    }

    if (key[KEY_UP]&&*sy>430&&*i>0)
    {
        *sy-=30;
        *i-=1;
    }
    if (key[KEY_DOWN]&&*sy<580&&*i<6)
    {
        *sy+=30;
        *i+=1;
    }
    textprintf_ex(*buffer1, font6, 112, *sy,makecol(184,134,11), -1, school_s[*i]);
    textprintf_ex(*buffer1, font6, 110, *sy,makecol(220,20,60), -1, school_s[*i]);
    blit( *buffer1, screen, 0, 0, 0, 0,  SCREEN_W,  SCREEN_H );
    clear(*buffer1);
    clear_keybuf();
    return *i;
}
int homeg(BITMAP **buffer1,FONT *font3,BITMAP *main2,int *hy,int *i,int month,int day)
{
    char home_s[4][15]= { "    Go out","Part-time job","   Abilities","  Exit game"};
    int position[4]= {200,285,370,455};
    blit( main2, *buffer1, 0,0, 0, 0,  SCREEN_W,  SCREEN_H );
    for(int i=0; i<4; i++)
    {
        textprintf_ex(*buffer1, font3, 102, position[i],makecol(0,0,0), -1,home_s[i] );
        textprintf_ex(*buffer1, font3, 750, 20,makecol(0,0,0), makecol(255,255,255),"Month:%d Day:%d",month,day);
    }
   for(int i=0; i<4; i++)
    {
        textprintf_ex(*buffer1, font3, 104, position[i],makecol(255,140,0), -1,home_s[i] );
    }
    if (key[KEY_UP]&&*hy>200&&*i>0)
    {
        *hy-=85;
        *i-=1;
    }
    if (key[KEY_DOWN]&&*hy<455&&*i<4)
    {
        *hy+=85;
        *i+=1;
    }
    textprintf_ex(*buffer1, font3, 104, *hy,makecol(34,139,34), -1, home_s[*i]);
    blit( *buffer1, screen, 0, 0, 0, 0,  SCREEN_W,  SCREEN_H );
    clear(*buffer1);
    clear_keybuf();
    return *i;
}
int job(BITMAP **buffer1,FONT *font3,BITMAP *main2,int *jy,int *opt)
{
    char job_s[4][15]= { "    trainer","  sweeper"," saleswoman","   Home"};
    int position[4]= {200,285,370,455};
    blit( main2, *buffer1, 0,0, 0, 0,  SCREEN_W,  SCREEN_H );
    for(int i=0; i<4; i++)
    {
        textprintf_ex(*buffer1, font3, 102, position[i],makecol(0,0,0), -1,job_s[i] );
    }
    for(int i=0; i<4; i++)
    {
        textprintf_ex(*buffer1, font3, 104, position[i],makecol(255,140,0), -1,job_s[i] );
    }
    if (key[KEY_UP]&&*jy>200&&*opt>0)
    {
        *jy-=85;
        *opt-=1;
    }
    if (key[KEY_DOWN]&&*jy<455&&*opt<4)
    {
        *jy+=85;
        *opt+=1;
    }
    textprintf_ex(*buffer1, font3, 104, *jy,makecol(34,139,34), -1, job_s[*opt]);
    blit( *buffer1, screen, 0, 0, 0, 0,  SCREEN_W,  SCREEN_H );
    clear(*buffer1);
    clear_keybuf();
    return *opt;
}




