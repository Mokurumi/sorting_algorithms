#ifndef DECK_H
#define DECK_H

#include <stddef.h>

/**
 * enum kind_e - Enumeration of card kinds (suits)
 * @SPADE: Spades
 * @HEART: Hearts
 * @CLUB: Clubs
 * @DIAMOND: Diamonds
 */
typedef enum kind_e
{
	SPADE,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Structure representing a playing card
 * @value: The value of the card (e.g., "Ace," "King," "2")
 * @kind: The kind (suit) of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Structure representing a node in a deck of cards
 * @card: Pointer to the card represented by this node
 * @prev: Pointer to the previous node in the deck (NULL if none)
 * @next: Pointer to the next node in the deck (NULL if none)
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
