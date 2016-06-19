#include <allegro.h>
#include"picture.h"
bool create_buffer(BITMAP **buffer)
{
    *buffer = create_bitmap(960,720);
    if(!buffer) return false;
    clear_bitmap(*buffer);
    return true;
}
bool change_new_picture(BITMAP *base,BITMAP **buffer1)
{
    if(!create_buffer(buffer1))
    {
        return false;
    }
    blit(base,*buffer1,0, 0,0,0,SCREEN_W,SCREEN_H);
    blit(*buffer1,screen,0, 0,0,0,SCREEN_W,SCREEN_H);
    return true;
}
void character_picture(BITMAP *base,BITMAP *buffer1,BITMAP *sprite,int x, int y)
{
    blit( base, buffer1, 0, 0, 0, 0,  SCREEN_W,  SCREEN_H );
    draw_sprite(screen,buffer1,0,0);
    blit(sprite,buffer1,0, 0,x ,y,46,79);
    draw_sprite(screen,buffer1,0,0);
}
bool load_bitmap(BITMAP **buffer1,BITMAP **sprite,BITMAP **base,BITMAP **main1,BITMAP **base1,BITMAP **ch_opt,BITMAP **church,BITMAP **pub_opt,BITMAP **pub,BITMAP **home,BITMAP **school,BITMAP **trainer,BITMAP **sweeper,BITMAP **saleswoman,BITMAP **ability,BITMAP **movie2,BITMAP **movie3,BITMAP **records_)
{
    *main1 = load_bitmap( "menu.bmp", NULL );
    if(main1==0) return false;
    *base1=load_bitmap( "getname.bmp", NULL );
    if(base1==0) return false;
    *sprite= load_bitmap ("aa-8.bmp",NULL);
    if(sprite==0) return false;
    *base = load_bitmap( "8-960.bmp", NULL );
    if(base==0) return false;
    *home = load_bitmap( "home.bmp", NULL );
    if(home==0) return false;
    *ch_opt= load_bitmap ("pray.bmp",NULL);
    if(ch_opt==0) return false;
    *church = load_bitmap( "Church.bmp", NULL);
    if(church==0) return false;
    *pub_opt= load_bitmap ("wine.bmp",NULL);
    if(pub_opt==0) return false;
    *pub = load_bitmap( "pub.bmp", NULL );
    if(pub==0) return false;
    *school= load_bitmap( "school.bmp", NULL );
    if(school==0) return false;
    *trainer= load_bitmap ("trainer.bmp",NULL);
    if(trainer==0) return false;
    *sweeper = load_bitmap( "sweeper.bmp", NULL );
    if(sweeper==0) return false;
    *saleswoman= load_bitmap( "saleswoman.bmp", NULL );
    if(saleswoman==0) return false;
    *ability=load_bitmap( "abilities.bmp", NULL );
    if(ability==0) return false;
    *movie2 = load_bitmap( "2.bmp", NULL);
    if(*movie2==0) return false;
    *movie3 = load_bitmap( "3.bmp", NULL);
    if(*movie3==0) return false;
    *records_ = load_bitmap( "record.bmp", NULL);
    if(*movie3==0) return false;
    return true;
}
void rule(BITMAP **end_,char rules[])
{
    char pname[20]="";
    strcpy(pname,rules);
    strcat(pname,".bmp");
    *end_=load_bitmap( pname, NULL );
    blit(*end_,screen,0, 0,0,0,SCREEN_W,SCREEN_H);

}
void Movie_(BITMAP *movie2,BITMAP *movie3,FONT *font3)
{
    blit(movie2,screen,0, 0,0,0,SCREEN_W,SCREEN_H);
    rest(10000);
    blit(movie3,screen,0, 0,0,0,SCREEN_W,SCREEN_H);
    rest(10000);
}
void destroy_picture(BITMAP *buffer1,BITMAP *sprite,BITMAP *base,BITMAP *main1,BITMAP *base1,BITMAP *ch_opt,BITMAP *church,BITMAP *pub_opt,BITMAP *pub,BITMAP *home,BITMAP *school,BITMAP *trainer,BITMAP *sweeper,BITMAP *saleswoman,BITMAP *ability,BITMAP *movie2,BITMAP *movie3,BITMAP *records_)
{
    destroy_bitmap(sprite);
    destroy_bitmap(home);
    destroy_bitmap(base);
    destroy_bitmap(main1);
    destroy_bitmap(ch_opt);
    destroy_bitmap(church);
    destroy_bitmap(pub_opt);
    destroy_bitmap(pub);
    destroy_bitmap(school);
    destroy_bitmap(buffer1);
    destroy_bitmap(base1);
    destroy_bitmap(trainer);
    destroy_bitmap(sweeper);
    destroy_bitmap(saleswoman);
    destroy_bitmap(ability);
    destroy_bitmap(movie2);
    destroy_bitmap(movie3);
    destroy_bitmap(records_);


}

