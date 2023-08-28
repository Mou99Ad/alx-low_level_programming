#ifndef DOG_H
#define DOG_H
/**
 * struct dog - Represents information about a dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
*/

typedef struct dog
{
	char *name;
	float age;
	char *owner;
}
dog_t;  /* Define the new type dog_t */
void init_dog(dog_t *d, char *name, float age, char *owner);
void print_dog(dog_t *d);
dog_t *new_dog(char *name, float age, char *owner);



#endif
