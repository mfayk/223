/*-------------------------*/
/* list.h                  */
#ifndef LIST_H_
#define LIST_H_

/* This header should not depend on any other headers. */

/** pointer to opaque list type to be defined in list.c. */
typedef struct list *list;
/** list data pointer. not to be dereferenced or freed by the list. */
typedef void *list_data;

/** Allocates and initializes a new empty list.
 *
 * Returns a new empty list or NULL if there was an error.
 */
list list_init(void);

/* Destroys the list and frees its memory.
 *
 * Frees all memory allocated for the list. List data is not freed.
 */
void list_finalize(list lst);

/** Inserts at the head of the list.
 *
 * DATA becomes the new head of the list and DATA's successor is the
 * previous head of the list. DATA must not be NULL.
 *
 * The current item is set to DATA.
 *
 * On error the list is not modified.
 *
 * Returns DATA or NULL on error.
 */
list_data list_insert(list lst, list_data data);

/** Appends to the tail of the list.
 *
 * DATA becomes the new tail and DATA's predecessor is the previous
 * tail of the list. DATA must not be NULL.
 *
 * The current item is set to DATA.
 *
 * On error the list is not modified.
 *
 * Returns DATA or NULL on error.
 */
list_data list_append(list lst, list_data data);

/** Inserts before the current item.
 *
 * DATA's predecessor will be the current item's predecessor. DATA's
 * successor will be the current item. DATA must not be NULL.
 *
 * The current item becomes DATA.
 *
 * It is an error if the current item is NULL. On error the list is
 * not modified.
 *
 * Returns DATA or NULL on error.
 */
list_data list_insert_before(list lst, list_data data);

/** Inserts after the current item.
 *
 * DATA's predecessor will be the current item. DATA's successor will
 * be the current item's successor.  DATA must not be NULL.
 *
 * The current item becomes DATA.
 *
 * It is an error if the current item is NULL. On error the list is
 * not modified.
 *
 * Returns DATA or NULL on error.
 */
list_data list_insert_after(list lst, list_data data);

/** Removes the current item from the list.
 *
 * Sets the new current item to the successor of the removed current
 * item. Does nothing if the current item is NULL.
 *
 * Returns the removed item (may be NULL).
 */
list_data list_remove(list lst);

/** Returns the list head.
 *
 * Sets the current item to the list head or NULL.
 *
 * Returns the list head or NULL if the list is empty.
 */
list_data list_first(list lst);

/** Moves the current item forward in the list.
 *
 * Sets the new current item to the successor of the current item. If
 * the current item is the list tail or the current item is NULL then
 * the new current item is NULL.
 *
 * Returns the new current item.
 */
list_data list_next(list lst);

/** Moves the current item backward in the list.
 *
 * Sets the new current item to the predecessor of the current
 * item. If the current item is the list head or the current item is
 * NULL then the new current item is NULL.
 *
 * Returns the new current item.
 */
list_data list_prev(list lst);

/** Returns the list tail.
 *
 * Sets the current item to the list tail or NULL.
 *
 * Returns the list tail or NULL if the list is empty.
 */
list_data list_last(list lst);

/** Returns the current item of the list.
 *
 * Returns the current item of LST (may return NULL).
 */
list_data list_curr(list lst);

#endif  /* LIST_H_ */
/*-------------------------*/
