#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * card_cmp - Compare two cards for sorting
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 *
 * Return: Negative value if card1 is less than card2, 0 if equal,
 *		 and positive value if card1 is greater than card2.
 */
int card_cmp(const void *card1, const void *card2)
{
	const card_t *c1 = *((const card_t **)card1);
	const card_t *c2 = *((const card_t **)card2);
	int value_cmp = strcmp(c1->value, c2->value);

	if (value_cmp != 0)
		return value_cmp;

	return c1->kind - c2->kind;
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	int i, count;
	card_t *cards[52];
	deck_node_t *current;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	count = 0;
	current = *deck;

	while (current != NULL)
	{
		cards[count++] = (card_t *)current->card;
		current = current->next;
	}

	qsort(cards, count, sizeof(card_t *), card_cmp);

	current = *deck;
	for (i = 0; i < count; i++)
	{
		current->card = cards[i];
		current = current->next;
	}
}
