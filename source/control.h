#include"data.h"
int menu(BITMAP **buffer1,FONT *font1,BITMAP *main,int *y,int *i);
void Print_Menu(BITMAP **buffer1,FONT *font1,BITMAP *main);
void move_character(BITMAP **buffer,BITMAP **sprite,BITMAP **base,int *pic_positiony,int *pic_positionx,int frame[],int rs,int ls,int us,int ds);
void Input_player(char name[],BITMAP **buffer,int *caret,BITMAP *base,FONT *font1);
int homeg(BITMAP **buffer1,FONT *font3,BITMAP *main2,int *hy,int *i,int month,int day);
void go_to_places(BITMAP *home,BITMAP *church,BITMAP *ch_opt,BITMAP *pub,BITMAP *pub_opt,FONT *font3,BITMAP *school,BITMAP **buffer,int pic_positionx,int pic_positiony,int *i,int *day,int *go_in,Player *p);
void Meet_People(FONT *font3,int pic_positionx,int pic_positiony);
void map_limit(int pic_positionx,int pic_positiony,int *ls,int *ds,int *us,int *rs);
int school1(BITMAP **buffer1,FONT *font6,BITMAP *school,int *sy,int *i);
int job(BITMAP **buffer1,FONT *font3,BITMAP *main2,int *hy,int *opt);
