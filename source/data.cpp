#include <allegro.h>
#include<stdio.h>
#include<string.h>
#include"data.h"
#include"picture.h"
#include<conio.h>
enum {PAINTING=0,DANCE,SCIENCE,FENCING,MAGIC,EXIT};

int CreateAttribute(Attribute att[])
{
    FILE *fp;
    int num=0;
    fp=fopen("attributes.txt","r");
    if(fp==0)
    {
        printf("The file didn't open.\n");
        return 0;
    }
    else
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s",att[num].name);
            num+=1;
        }
        fclose(fp);
        return num;
    }
}
void job(BITMAP *jobs,Player *p,int job_opt,FONT *font3)
{
    blit( jobs, screen, 0, 0, 0, 0,  SCREEN_W,  SCREEN_H );
    switch(job_opt)
    {
    case 0:
        textprintf_ex(screen, font3, 60, 550,makecol(255,0,0),-1,"%s +10",p->attributes[1].name);
        textprintf_ex(screen, font3, 60, 580,makecol(255,0,0), -1,"%s +5",p->attributes[7].name);
        textprintf_ex(screen, font3, 60, 610,makecol(255,0,0), -1,"money $+300");
        p->attributes[1].value+=10;
        p->attributes[7].value+=5;
        p->money+=300;
        break;
    case 1:
        textprintf_ex(screen, font3, 60, 550,makecol(255,0,0), makecol(255,255,255),"%s +10",p->attributes[4].name);
        textprintf_ex(screen, font3, 60, 600,makecol(255,0,0), makecol(255,255,255),"%s +5",p->attributes[2].name);
        textprintf_ex(screen, font3, 60, 650,makecol(255,0,0), makecol(255,255,255),"money $+100");
        p->attributes[2].value+=5;
        p->attributes[4].value+=10;
        p->money+=100;
        break;
    case 2:
        textprintf_ex(screen, font3, 60, 550,makecol(255,0,0), makecol(255,255,255),"%s +15",p->attributes[4].name);
        textprintf_ex(screen, font3, 60, 600,makecol(255,0,0), makecol(255,255,255),"money $+200");
        p->attributes[4].value+=15;
        p->money+=200;
        break;
    default:
        break;
    }
}
void CreatePlayer(Player *p,const char name[],Attribute att[],int num)
{
    int i=0;
    strcpy(p->name,name);
    for(i=0; i<num; i++)
    {
        strcpy(p->attributes[i].name,att[i].name);
        p->attributes[i].value=0;
    }
    p->num_attributes=i;
    p->money=1000;

}
void Church_Get_Points(int cy,Player *p,FONT *font3)
{
    switch(cy)
    {
    case 80:
        textprintf_ex(screen, font3, 60, 550,makecol(0,0,205), makecol(255,255,255),"%s +5",p->attributes[5].name);
        p->attributes[5].value+=5;
        rest(2600);
        readkey();
        break;
    case 145:
        if(p->money>=200)
        {
            textprintf_ex(screen, font3, 60, 550,makecol(255,0,0), makecol(255,255,255),"%s +15",p->attributes[5].name);
            textprintf_ex(screen, font3, 60, 600,makecol(255,0,0), makecol(255,255,255),"money $-200");
            p->attributes[5].value+=15;
            p->money-=200;
        }
        else
        {
            textprintf_ex(screen, font3, 60, 550,makecol(255,0,0), makecol(255,255,255),"You don't have enough money!!");

        }
        rest(3600);
        break;
    case 210:
        textprintf_ex(screen, font3, 60, 550,makecol(255,0,0), makecol(255,255,255),"You watch other people praying and do nothing today!!");
        rest(3600);
        break;
    }
}
void Pub_Get_Points(int py,Player *p,FONT *font3)
{
    switch(py)
    {
    case 158:
        if(p->money>=500)
        {
            int num;
            srand(time(0));
            num=rand()%6+1;
            textprintf_ex(screen, font3, 60, 550,makecol(0,0,205), makecol(0,255,0),"You are rolling the dise... ");
            rest(1500);
            if(num==1||num==2||num==3)
            {
                textprintf_ex(screen, font3, 60, 580,makecol(0,0,205),makecol(0,255,0),"You get %d and earn $1000",num);
                p->money+=1000;
            }
            else if(num==4||num==5||num==6)
            {
                textprintf_ex(screen, font3, 60, 580,makecol(255,0,0), makecol(0,255,0),"You get %d and lose $500",num);
                p->money-=500;
            }
        }
        else
        {
            textprintf_ex(screen, font3, 60, 550,makecol(255,255,255), makecol(255,0,0),"Gamblers: Hey! you don't have money! Get out of here!!!");
        }
        textprintf_ex(screen, font3, 60, 610,makecol(255,0,0), makecol(255,255,255),"%s +30",p->attributes[6].name);
        p->attributes[6].value+=30;
        rest(3600);
        break;
    case 258:
        if(p->money>=200)
        {
            textprintf_ex(screen, font3, 60, 550,makecol(0,0,255), makecol(255,255,255),"%s +15",p->attributes[6].name);
            textprintf_ex(screen, font3, 60, 600,makecol(0,0,255), makecol(255,255,255),"money $-200");
            p->attributes[6].value+=15;
            p->money-=200;
        }
        else
        {
            textprintf_ex(screen, font3, 60, 550,makecol(255,0,0), makecol(0,0,0),"Oops! I don't have enough money!!");
        }
        rest(3600);
        break;
    case 358:
        textprintf_ex(screen, font3, 60, 550,makecol(255,0,0), makecol(255,255,255),"You did nothing today.....");
        rest(3600);
        break;
    }
}
void School_Get_Points(int i,Player *p,FONT *font3,int money)
{
    if(money<200&&i>=0&&i<=4)
    {
        textprintf_ex(screen, font3, 280, 660,makecol(255,0,0), makecol(255,255,255),"Sorry! You don't have enough money!");
        rest(2600);
    }
    else
    {
        switch(i)
        {
        case PAINTING:
            textprintf_ex(screen, font3, 280, 400,makecol(0,0,255), makecol(255,255,255),"%s +30",p->attributes[3].name);
            if(p->attributes[6].value>=5)
            {
                textprintf_ex(screen, font3, 280, 350,makecol(0,0,255), makecol(255,255,255),"%s -5",p->attributes[6].name);
                p->attributes[6].value-=5;
            }
            textprintf_ex(screen, font3, 280, 450,makecol(0,0,255), makecol(255,255,255),"money $-200");
            p->attributes[3].value+=30;
            p->money-=200;
            rest(2600);
            break;
        case DANCE:
            textprintf_ex(screen, font3, 280, 350,makecol(0,0,255), makecol(255,255,255),"%s +20",p->attributes[3].name);
            textprintf_ex(screen, font3, 280, 400,makecol(0,0,255), makecol(255,255,255),"%s +20",p->attributes[0].name);
            textprintf_ex(screen, font3, 280, 450,makecol(0,0,255), makecol(255,255,255),"money $-200");
            p->attributes[3].value+=20;
            p->attributes[0].value+=20;
            p->money-=200;
            rest(2600);
            break;
        case SCIENCE:
            textprintf_ex(screen, font3, 280, 350,makecol(0,0,255), makecol(255,255,255),"%s +20",p->attributes[1].name);
            textprintf_ex(screen, font3, 280, 400,makecol(0,0,255), makecol(255,255,255),"money $-200");
            p->attributes[1].value+=20;
            p->money-=200;
            rest(2600);
            break;
        case FENCING:
            textprintf_ex(screen, font3, 280, 350,makecol(0,0,255), makecol(255,255,255),"%s +25",p->attributes[2].name);
            textprintf_ex(screen, font3, 280, 400,makecol(0,0,255), makecol(255,255,255),"money $-200");
            p->attributes[2].value+=25;
            p->money-=200;
            rest(2600);
            break;
        case MAGIC:
            textprintf_ex(screen, font3, 280, 350,makecol(0,0,255), makecol(255,255,255),"%s +30",p->attributes[7].name);
            textprintf_ex(screen, font3, 280, 400,makecol(0,0,255), makecol(255,255,255),"%s +15",p->attributes[2].name);
            textprintf_ex(screen, font3, 280, 450,makecol(0,0,255), makecol(255,255,255),"money $-200");
            p->attributes[2].value+=15;
            p->attributes[7].value+=30;
            p->money-=200;
            rest(2600);
            break;
        case EXIT:
            textprintf_ex(screen, font3, 280, 400,makecol(255,0,0), makecol(255,255,255),"You went to school but just idled around...");
            rest(2600);
            break;
        }
    }
}
void abilities(BITMAP *ability,const Player *p,FONT *font3)
{
    clear(screen);
    int y=30;
    blit(ability,screen,0, 0,0,0,SCREEN_W,SCREEN_H);
    textprintf_ex(screen, font3, 20, 15,makecol(0,0,255),-1,"Name: %s ",p->name);
    textprintf_ex(screen, font3, 20, 40,makecol(0,0,0), -1,"Money: %d ",p->money);
    for(int i=0; i<8; i++)
    {
        textprintf_ex(screen, font3, 652,y+2,makecol(0,0,0),-1,"%5s: %3d",p->attributes[i].name,p->attributes[i].value);
        textprintf_ex(screen, font3, 650,y,makecol(255,0,255),-1,"%5s: %3d",p->attributes[i].name,p->attributes[i].value);//reprint to prettify word
        y+=35;
    }
}
bool save(Player p,int month,int day,FONT *font3)
{
    FILE *fp;
    char fname[17]="",ASCII=' ';
    strcpy(fname,p.name);
    strcat(fname,".txt");
    fp=fopen(fname,"r");
    if(fp!=0)
    {
        textprintf_ex(screen, font3, 50, 520,makecol(0,0,0), makecol(255,255,255),"Do you want to overwrite the data? Y/N");
        ASCII  = readkey();
        fclose(fp);
    }
    if ( ASCII==89 || ASCII==121||fp==0)
    {
        fp=fopen(fname,"w");
        fprintf(fp,"%s %d %d/%d\n",p.name,p.money,month,day);
        for(int i=0; i<p.num_attributes; i++)
        {
            fprintf(fp,"%s %d",p.attributes[i].name,p.attributes[i].value);
            fprintf(fp,"\n");
        }
        fprintf(fp,"#");
        fclose(fp);
        return true;
    }
    else
    {
        return false;
    }
}
bool Load(Player *p,int *month,int *day,char name[],FONT *font3)
{
    FILE *fp;
    char fname[17]="";
    strcpy(fname,p->name);
    strcat(fname,".txt");
    fp=fopen(fname,"r");
    if(fp==0)
    {
        textprintf_ex(screen, font3, 60, 550,makecol(0,0,0), makecol(255,255,255),"No data ! "
                      "Please use [Backspace] and input another one!");
        return false;
    }
    else
    {
        fscanf(fp,"%s %d %d/%d",p->name,&p->money,month,day);
        for(int i=0; i<p->num_attributes; i++)
        {
            fscanf(fp,"%s %d",p->attributes[i].name,&p->attributes[i].value);
        }
        return true;
    }
}
int Check(const char com,int a,int r)
{
    if(com=='>')
    {
        if(a>r) return 1;
    }
    else
    {
        if(a<r) return 1;
    }
    return 0;
}
int Rematch(const Player p,const char attribute[],const char com,const char condition[])
{
    int val=0;
    for(int i=0; i<p.num_attributes; i++)
    {
        if(strcmp(p.attributes[i].name,attribute)==0)
        {
            if(atoi(condition)!=0)
            {
                val=atoi(condition);
                if(Check(com,p.attributes[i].value,val)==1) return 1;
            }
            else
            {
                for(int j=0; j<p.num_attributes; j++)
                {
                    if(strcmp(p.attributes[j].name,condition)==0 && Check(com,p.attributes[i].value,p.attributes[j].value)==1) return 1;
                }
            }
        }
    }
    return 0;
}
int Match(Player p,FONT *font3)
{
    BITMAP *end_=0;
    FILE *fp=fopen("ending.txt", "r");
    if(fp==0)
    {
        printf("The file didn't open.\n");
        return 0;
    }
    while(!feof(fp))
    {
        int de=0;
        char ch=' ',com=' ',rules[30]=" ",attribute[18]="",condition[18]="";
        fscanf(fp,"%s",rules);
        if(feof(fp))break;
        while(ch!='\n')
        {
            if(feof(fp))break;
            if(ch=='(' && de==0)
            {
                if(feof(fp))break;
                fscanf(fp,"%s %c %s",attribute,&com,condition);
                condition[strlen(condition)-1]='\0';
                if(Rematch(p,attribute,com,condition)==0)
                {
                    de=1;
                }
            }
            fscanf(fp,"%c",&ch);
        }
        if(de==0)
        {
            rule(&end_,rules);
            textprintf_ex(screen, font3, 50, 25,makecol(0,0,0), makecol(255,255,255),"You become a %s",rules);
            rest(10000);
            Write_Story(rules,p.name);
            destroy_bitmap(end_);
            return 1;
        }
    }
    rule(&end_,"nobody");
    textprintf_ex(screen, font3, 50, 25,makecol(0,0,0), makecol(255,255,255),"You become nobody");
    Write_Story("nobody",p.name);
    rest(10000);
    return 1;
}
void Ex_player::Create(char myname[],char ru[])
{
    strcpy(name,myname);
    strcpy(rule_,ru);
}
void Write_Story(char trule[],char tname[])
{
    FILE *fp=fopen("ex_ending.txt","r");
    if(fp==0)
    {
        fp=fopen("ex_ending.txt","w");
        fprintf(fp,"%s %s\n",tname,trule);
    }
    else
    {
        fclose(fp);
        fp=fopen("ex_ending.txt","a");
        fprintf(fp,"%s %s\n",tname,trule);
    }
    fclose(fp);
}
bool Player_data::Load_Story()
{
    num_players=0;
    char temname[21]="";
    char tru[21]="";
    Ex_player new_;
    FILE *fp=fopen("ex_ending.txt","r");
    if(fp==0) return false;
    while(fscanf(fp,"%s %s",temname,tru)==2)
    {
        new_.Create(temname,tru);
        if(AddPlayers(new_)==false) return false;
    }
    fclose(fp);
    return true;
}
bool Player_data::AddPlayers(Ex_player p)
{
    Ex_player *newp=(Ex_player*)malloc(sizeof(Ex_player)*(num_players+1));
    if(newp==0) return false;
    for(int i=0; i<num_players; i++)
    {
        newp[i]=players_[i];
    }
    newp[num_players]=p;
    free(players_);
    players_=newp;
    num_players+=1;
    return true;
}
void Player_data::Print(BITMAP *movie3,FONT *font3)
{
    int j=0;
    blit(movie3,screen,0, 0,0,0,SCREEN_W,SCREEN_H);
    if(num_players==0) textprintf_ex(screen, font3, 50, 25+j,makecol(0,0,0), makecol(255,255,255),"No one has played this game before");
    for(int i=0; i<num_players; i++)
    {
        textprintf_ex(screen, font3, 50, 25+j,makecol(0,0,0), makecol(255,255,255),"%s %s",players_[i].GetName(),players_[i].GetRule());
        j+=50;
    }
}
void Player_data::Destroy()
{
    free(players_);
    num_players=0;
}

