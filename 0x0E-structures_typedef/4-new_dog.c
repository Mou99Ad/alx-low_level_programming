#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the new dog_t instance, or NULL if allocation fails
*/

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog_ptr;

	new_dog_ptr = malloc(sizeof(dog_t));  /* Allocate memory for the new dog */
	if (new_dog_ptr == NULL)
		return (NULL);

	new_dog_ptr->name = name;  /* Store a copy of the name */
	new_dog_ptr->age = age;
	new_dog_ptr->owner = owner;  /* Store a copy of the owner */

	return (new_dog_ptr);
}
