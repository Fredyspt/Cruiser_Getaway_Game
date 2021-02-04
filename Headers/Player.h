#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player();

    void call_input();
    void return_last_position();

    int x, y;
    int lastX, lastY;

protected:
    

private:
};

#endif  //PLAYER_H