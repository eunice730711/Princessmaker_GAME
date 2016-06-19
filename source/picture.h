bool create_buffer(BITMAP **buffer);
bool change_new_picture(BITMAP *base1,BITMAP **buffer1);
void character_picture(BITMAP *base,BITMAP *buffer1,BITMAP *sprite,int x, int y);
bool load_bitmap(BITMAP **buffer1,BITMAP **sprite,BITMAP **base,BITMAP **main1,BITMAP **base1,BITMAP **ch_opt,BITMAP **church,BITMAP **pub_opt,BITMAP **pub,BITMAP **home,BITMAP **school,BITMAP **trainer,BITMAP **sweeper,BITMAP **saleswoman,BITMAP **ability,BITMAP **movie2,BITMAP **movie3,BITMAP **records_);
void rule(BITMAP **end_,char rules[]);
void Movie_(BITMAP *movie2,BITMAP *movie3,FONT *fon3);
void destroy_picture(BITMAP *buffer1,BITMAP *sprite,BITMAP *base,BITMAP *main1,BITMAP *base1,BITMAP *ch_opt,BITMAP *church,BITMAP *pub_opt,BITMAP *pub,BITMAP *home,BITMAP *school,BITMAP *trainer,BITMAP *sweeper,BITMAP *saleswoman,BITMAP *ability,BITMAP *movie2,BITMAP *movie3,BITMAP *records_);
