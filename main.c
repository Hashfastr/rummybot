/**
 * @file main.c
 * @brief The main function for the Rummybot
 * @details Sets up data and data structures then calls a game to start 
 *
 * @author Hashfastr
 * @date 5/28/18
 * @bug None (so far)
 * @todo Add discard linked list
 *       Add UI
 *       Change each player's hand to a data structure that also holds guesses and probility
 *       Sort hand by best outcome
 *       Maybe add raw mode for better output?
 *       Add makefile
 */

#include "structs.h"

int main() {
        char buf[LEN];
        int cont = 1, i;

        while (cont) { // loop until valid input
                printf("Game type? [l, 5, g]\n> ");
                fgets(buf, LEN, stdin); // get input

                switch (buf[0]) { // if we got valid input then stop the loop
                        case 'l':
                        case '5':
                        case 'g':
                                cont--;
                                break;
                }
        }

        struct game_data *info = malloc(sizeof(struct game_data *));

        // get number of players
        memset(buf, 0, sizeof(char) * LEN);
        printf("Number of players?\n> ");
        fgets(buf, LEN, stdin);
        info->numplayers = atoi(buf);

        // get number of decks
        memset(buf, 0, sizeof(char) * LEN);
        printf("Number of decks?\n> ");
        fgets(buf, LEN, stdin);
        info->decks = atoi(buf);

        // malloc the player data
        info->player_data = malloc(sizeof(struct player) * info->numplayers);

        // get player names
        for (i = 0; i < info->numplayers; i++) {
                memset(buf, 0, sizeof(char) * LEN);
                printf("Name of player #1?\n> ");
                fgets(info->player_data[i].name, LEN, stdin); 
        }

        switch (buf[0]) {
                case 'l':
                        play_liver(info);
                        break;
                case '5':
                        play_500(info);
                        break;
                case 'g':
                        play_gin(info);
                        break;
        }

        free(info);
        free(info->player_data);
}
