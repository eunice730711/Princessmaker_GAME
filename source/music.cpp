#include <allegro.h>
void Base_music(SAMPLE **music,char mname[])
{
    char name[]="";
    strcpy(name,mname);
    strcat(name,".wav");
    *music = load_sample( name );
    play_sample(*music , 255, 128, 1000, 1 );
}
void Change_music(SAMPLE **music,SAMPLE **music1,char mname[])
{
     stop_sample(*music);
     Base_music(music1,mname);
}
void Destroy_music(SAMPLE *music,SAMPLE *music1)
{
    destroy_sample(music);
    destroy_sample(music1);
}

