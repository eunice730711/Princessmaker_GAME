#include <allegro.h>
//#include<iostream>
#include <stdio.h>
#include"music.h"
#include"control.h"
#include"data.h"
#include"picture.h"
#include"player.h"
BITMAP *buffer1=0,*sprite=0,*base=0,*main1=0,*base1=0,*ch_opt=0,*church=0,*pub_opt=0,*pub=0,*home=0,*school=0,*trainer=0,*sweeper=0,*saleswoman=0,*ability=0;
BITMAP *movie2=0,*movie3=0,*records_=0;
SAMPLE *music=0,*music1=0;
enum {STRAT_GAME=0,LOAD_GAME,RECORDS,OVER_GAME};
enum {GO_OUT=0,PART_TIME_JOB,ABLITIES,EXIT_GAME};
enum {TRAINER=0,SWEEPER,SALEWOMAN,HOME};
int main()
{
    int y=115,hy=200,jy=200,i=0,j=0,num=0,pic_positiony=240, pic_positionx=345,frame[4]= {0};
    int ds=1,ls=1,rs=1,us=1,go_in=0,job_opt=0,month=1,day=1;
    int num_attribute=0,ok=0,done=0;
    Attribute attribute[10];
    Player person;
    Player_data people;
    char name[21]="";
    char ASCII=' ';

    allegro_init();//initailize allegro
    install_keyboard();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
    set_color_depth(16);

    num_attribute=CreateAttribute(attribute);
    if (set_gfx_mode(GFX_SAFE, 960,720, 0,0))
    {
        allegro_message("Unable to set graphics mode.\n");
        return 0;
    }

    if (!create_buffer(&buffer1)) // initialize
    {
        allegro_message("Unable to initialize.\n");
        return 0;
    }
    FONT* font1=load_font("font1.pcx",NULL,NULL);
    if(font1==0) return 0;
    FONT* font2=load_font("font2.pcx",NULL,NULL);
    if(font2==0) return 0;
    FONT* font3=load_font("font3.pcx",NULL,NULL);
    load_bitmap(&buffer1,&sprite,&base,&main1,&base1,&ch_opt,&church,&pub_opt,&pub,&home,&school,&trainer,&sweeper,&saleswoman,&ability,&movie2,&movie3,&records_);
    Base_music(&music,"base_mu");
    do
    {
        people.Load_Story();
        day=1;
        do//the main screen of the game
        {
            i=menu(&buffer1,font1,main1,&y,&i);
            readkey();
        }

        while(!key[KEY_ENTER]);
        switch ( i )/*Start Game */
        {
        case STRAT_GAME:/*New Game */
        case LOAD_GAME:
            change_new_picture(base1,&buffer1);
            do
            {
                do
                {
                    Input_player(name,&buffer1,&num,base1,font2);
                }
                while(!key[KEY_ENTER]);
                CreatePlayer(&person,name,attribute,num_attribute);

                if(i==0) break;
                else if(i==1)
                {
                    ok=Load(&person,&month,&day,name,font3);
                }
            }
            while(i==1&&ok==0);
            do
            {
                create_buffer(&buffer1);
                j=0;
                hy=200;
                jy=200;
                job_opt=0;
                do
                {
                    j=homeg(&buffer1,font3,home,&hy,&j,month,day);
                    readkey();
                }
                while(!key[KEY_ENTER]);
                switch(j)
                {
                case GO_OUT:
                    pic_positiony=350;
                    pic_positionx=450;
                    character_picture(base,buffer1,sprite,pic_positionx,pic_positiony);
                    do
                    {
                        move_character(&buffer1,&sprite,&base,& pic_positiony,&pic_positionx,frame,rs,ls,us,ds);
                        map_limit(pic_positionx,pic_positiony,&ls,&ds,&us,&rs);
                        go_to_places(home,church,ch_opt,pub,pub_opt,font3,school,&buffer1,pic_positionx,pic_positiony,&i,&day,&go_in,&person);
                        Meet_People(font3,pic_positionx,pic_positiony);
                        if(go_in!=0)
                        {
                            readkey();
                            break;
                        }
                    }
                    while(go_in==0);
                    break;
                case PART_TIME_JOB:
                    create_buffer(&buffer1);
                    do
                    {
                        job_opt=job(&buffer1,font3,home,&jy,&job_opt);
                        readkey();
                    }
                    while(!key[KEY_ENTER]);
                    switch(job_opt)
                    {
                    case TRAINER:
                        job(trainer,&person,job_opt,font3);
                        readkey();
                        break;
                    case SWEEPER:
                        job(sweeper,&person,job_opt,font3);
                        readkey();
                        break;
                    case SALEWOMAN:
                        job(saleswoman,&person,job_opt,font3);
                        readkey();
                        break;
                    case HOME:
                        day-=1;
                        break;
                    }
                    break;
                case ABLITIES:
                    abilities(ability,&person,font3);
                    readkey();
                    day-=1;
                    break;
                case EXIT_GAME:
                    change_new_picture(home,&buffer1);
                    textprintf_ex(screen, font3, 50, 520,makecol(255,99,71), makecol(255,255,255),"Do you want to save the game? Y/N");
                    ASCII  = readkey();
                    if ( ASCII==89 || ASCII==121)
                    {
                        done=save(person,month,day,font3);
                    }
                    break;
                }
                if(j==3)
                {
                    change_new_picture(home,&buffer1);
                    if(done==1)
                    {
                        textprintf_ex(screen, font3, 50, 520,makecol(34,139,34), makecol(255,255,255),"The file is saved....BYE~");
                    }
                    else
                    {
                        textprintf_ex(screen, font3, 120, 520,makecol(34,139,34), makecol(255,255,255),"BYE~ BYE~");
                    }
                    break;
                }
                day+=1;
            }
            while(day<=31);
            if(j!=3)
            {
                Change_music(&music,&music1,"ending");
                Match(person,font3);
                Movie_(movie2,movie3,font3);
                Change_music(&music1,&music,"base_mu");
            }
            break;
        case RECORDS:
            people.Print(records_,font3);
            readkey();
            break;
        case OVER_GAME:
            exit(0);
            break;
        }
    }
    while(i!=4);
    readkey();
    destroy_picture(buffer1,sprite,base,main1,base1,ch_opt,church,pub_opt,pub,home,school,trainer,sweeper,saleswoman,ability,movie2,movie3,records_);
    Destroy_music(music,music1);
    people.Destroy();
    return 0;
}
END_OF_MAIN()
