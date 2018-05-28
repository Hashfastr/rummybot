/**
 * @file liver.c
 * @brief Function file for Liverpool rummy
 *
 * @author Hashfastr 
 * @date 5/28/18
 * @bug None (so far)
 * @todo Add discard linked list
 *       Add UI
 *       Change each player's hand to a data structure that also holds guesses and probility
 *       Sort hand by best outcome
 */

#include "structs.h"

void play_liver (struct game_data *info)
{
        int cont = 1;
        char buf[LEN];

        init_hand(info);

        while (cont) {
                // get the amount of three of a kinds to accomplish
                memset(buf, 0, sizeof(char) * LEN);
                printf("Number of three of a kinds?\n> ");
                fgets(buf, LEN, stdin);
                info->threes = atoi(buf);

                // get the amount of straights to accomplish
                memset(buf, 0, sizeof(char) * LEN);
                printf("Number of straights?\n> ");
                fgets(buf, LEN, stdin);
                info->threes = atoi(buf);

                print_screen(info);
        }
}
