#ifndef DATA_
#define DATA_
#include "player.h"
struct Attribute
{
    char name[18]="";
    int value=0;
};
struct Player
{
    char name[13]="";
    int money=0;
    Attribute attributes[10];
    int num_attributes=0;

};
class Ex_player
{
private:
    char name[13]="";
    char rule_[21]="";
public:
    char* GetName(){return name;}
    char* GetRule(){return rule_;}
   void Create(char myname[],char ru[]);
};
class Player_data
{
private:
    Ex_player *players_;
    int num_players=0;
public:
    bool Load_Story();
    bool AddPlayers(Ex_player p);
    void Print(BITMAP *movie3,FONT *font3);
    void Destroy();
};
#endif // DATA_
int CreateAttribute(Attribute att[]);
void job(BITMAP *jobs,Player *p,int job_opt,FONT *font3);
void CreatePlayer(Player *p,const char name[],Attribute att[],int num);
bool save(Player p,int month,int day,FONT *font3);
bool Load(Player *p,int *month,int *day,char name[],FONT *font3);
void Church_Get_Points(int cy,Player *p,FONT *font3);
void School_Get_Points(int i,Player *p,FONT *font3,int money);
void Pub_Get_Points(int py,Player *p,FONT *font3);
void abilities(BITMAP *ability,const Player *p,FONT *font3);
int Check(const char com,int a,int r);
int Rematch(Player p,const char attribute[],const char com,const char condition[]);
int Match(const Player p,FONT *font3);
void Write_Story(char trule[],char tname[]);
