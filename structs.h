/**
 * @file structs.h
 * @brief General header for Rummy bot
 *
 * @author Hashfastr
 * @date 5/28/18
 * @bug None (so far)
 * @todo Add discard linked list
 *       Add UI
 *       Change each player's hand to a data structure that also holds guesses and probility
 *       Sort hand by best outcome
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1024 // length of strings
#define DECKSIZE 52 // the size of a deck, shouldn't really be changed

struct player { // data for a player
       char name[LEN]; // the name of the player
       char curhand[LEN]; // probably update to a structure to hold more data
};

struct cards { // singly linked list of the location of each card type
        struct player *player_data; // pointer to the card's owner

        struct cards *next; // pointer to the next card of the same type that is known
};

struct game_data {
        int numplayers; // the total number of players
        int mainplayer; // the player the bot is
        int decks; // how many decks are in play
        int handsize; // the current hand size

        // for liverpool
        int threes; // how many three of a kinds are in the goal
        int straights; // how many straights are in the goal

        int unknown_cards[DECKSIZE]; // an array of cards which location is unknown
        struct cards known_cards[DECKSIZE]; // a structure array of cards which their location is known

        struct player *player_data; // a pointer array of all of the players currently playing
};

void print_screen(struct game_data *info); // print the screen
void play_liver(struct game_data *info); // play a game of liverpool rummy
void play_500(struct game_data *info); // play a game of rummy 500
void play_gin(struct game_data *info); // play a game of gin rummy
void init_hand(struct game_data *info); // initialize all player's hands
