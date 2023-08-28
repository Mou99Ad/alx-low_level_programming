#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees memory allocated for a dog
 * @d: Pointer to a dog_t instance
*/

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);   /* Free the memory for the name */
		free(d->owner);  /* Free the memory for the owner */
		free(d);         /* Free the memory for the struct itself */
	}
}
