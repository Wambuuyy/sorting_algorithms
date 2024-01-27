#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * compare_cards - Compare two card nodes for sorting.
 * @card1: First card node.
 * @card2: Second card node.
 * Return: Negative value if card1 should be before card2,
 *         positive value if card1 should be after card2,
 *         and 0 if they are equal.
 */
int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = ((const deck_node_t *)card1)->card;
    const card_t *c2 = ((const deck_node_t *)card2)->card;

    int value_cmp = strcmp(c1->value, c2->value);
    if (value_cmp != 0)
        return value_cmp;

    return c1->kind - c2->kind;
}

/**
 * sort_deck - Sort a deck of cards in ascending order.
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
    size_t deck_size = 52;

    if (deck == NULL || *deck == NULL)
        return;

    /* Convert the deck linked list to an array for qsort */
    deck_node_t **deck_array = malloc(deck_size * sizeof(deck_node_t *));
    if (deck_array == NULL)
        return;

    deck_node_t *current = *deck;
    for (size_t i = 0; i < deck_size; ++i)
    {
        deck_array[i] = current;
        current = current->next;
    }

    /* Sort the array using qsort */
    qsort(deck_array, deck_size, sizeof(deck_node_t *), compare_cards);

    /* Rebuild the linked list from the sorted array */
    for (size_t i = 0; i < deck_size; ++i)
    {
        deck_array[i]->prev = (i > 0) ? deck_array[i - 1] : NULL;
        deck_array[i]->next = (i < deck_size - 1) ? deck_array[i + 1] : NULL;
    }

    /* Update the head of the linked list */
    *deck = deck_array[0];

    /* Free the temporary array */
    free(deck_array);
}
