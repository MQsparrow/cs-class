#include <stdio.h>
#define lvup_atk 200
#define lvup_dfn 100
#define lvup_maxHp 20
#define lvup_maxMp 15
#define T 2

typedef struct pokemon{
    int id;
    char name[10];
    int level;
    int attack;
    int defense;
    int Hp;
    int Mp;
    int maxHp;
    int maxMp;
    int costMp;
}Pokemon;

// TODO: upgrade and recover the Pokémon
void level_up(Pokemon *P){
    if(P->level < 5){
        P->level++;
        P->attack+=lvup_atk;
        P->defense+=lvup_dfn;
        P->maxHp+=lvup_maxHp;
        P->maxMp+=lvup_maxMp;
    }
    P->Hp = P->maxHp;
    P->Mp = P->maxMp;
}

// TODO: simulate and print the process of the battle
void battle(Pokemon *A, Pokemon *B){
    int turn = 0, t1, t2;
    Pokemon* p[2];
    p[0] = A; p[1] = B;
    while(1){
        t1 = p[turn]->Mp+T; t2 = p[turn]->maxMp;
        p[turn]->Mp = (t1<t2?t1:t2);
        if(!p[turn]->Hp && !p[(turn+1)%2]->Hp){
            printf("Draw\n\n");
            break;
        }
        else if(!p[(turn+1)%2]->Hp){
            printf("%s is the winner! %s died in vain...\n\n", p[turn]->name, p[(turn+1)%2]->name);
            break;
        }
        else if(!p[turn]->Hp){
            printf("%s is the winner! %s died in vain...\n\n", p[(turn+1)%2]->name, p[turn]->name);
            break;
        }
        if(p[turn]->costMp<=p[turn]->Mp){
            t1 = p[turn]->attack - p[(turn+1)%2]->defense; t2 = 0;
            int damage = 2*p[turn]->level*(t1>t2?t1:t2)/100;
            p[turn]->Mp-=p[turn]->costMp;
            t1 = p[(turn+1)%2]->Hp - damage; t2 = 0;
            p[(turn+1)%2]->Hp = (t1>t2?t1:t2);

            printf("%s used Headbutt!\n", p[turn]->name);
            printf("%s now has %d HP.\n", p[(turn+1)%2]->name, p[(turn+1)%2]->Hp);
            if(!p[turn]->Hp && !p[(turn+1)%2]->Hp){
                printf("Draw\n\n");
                break;
            }
            else if(!p[(turn+1)%2]->Hp){
                printf("%s is the winner! %s died in vain...\n\n", p[turn]->name, p[(turn+1)%2]->name);
                break;
            }
            else if(!p[turn]->Hp){
                printf("%s is the winner! %s died in vain...\n\n", p[(turn+1)%2]->name, p[turn]->name);
                break;
            }
        }
        else{
            t1 = p[turn]->Mp+T; t2 = p[turn]->maxMp;
            p[turn]->Mp = (t1<t2?t1:t2);
            printf("%s used Rest!\n", p[turn]->name);
            printf("%s now has %d MP.\n", p[turn]->name, p[turn]->Mp);
            if(!p[turn]->Hp && !p[(turn+1)%2]->Hp){
                printf("Draw\n\n");
                break;
            }
            else if(!p[(turn+1)%2]->Hp){
                printf("%s is the winner! %s died in vain...\n\n", p[turn]->name, p[(turn+1)%2]->name);
                break;
            }
            else if(!p[turn]->Hp){
                printf("%s is the winner! %s died in vain...\n\n", p[(turn+1)%2]->name, p[turn]->name);
                break;
            }
        }
        turn = (turn+1)%2;
    }
}
