#ifndef INGAME_H
#define INGAME_H


class ingame
{
public:
    char om[15][15];

    ingame();

    int on_click(int i, int j, char c);

    void setting();


private:

    int check_win(int a, int b, char c);
};

#endif // INGAME_H
