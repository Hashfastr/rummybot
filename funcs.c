/**
 * @file funcs.c
 * @brief General functions for Rummy bot
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

void init_hand(struct game_data *info)
{
        int i;
        for (i = 0; i < info->numplayers; i++) {
                if (i != info->mainplayer)
                        memset(info->player_data[i].curhand, '?', sizeof(char) * info->handsize);
        }

        // enter user hand
        for (i = 0; i < info->handsize; i++) {
               printf("Enter card number %d/%d\n> ", i + 1, info->handsize); 
        }
}
