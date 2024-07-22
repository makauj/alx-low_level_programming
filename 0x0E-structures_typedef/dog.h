#ifndef DOG_H
#define DOG_H
/**
 * struct dog - structure that stores information
 * @name: pointer to the dog's name
 * @age:dog's age (int)
 * @owner: pointer to the name of the dog's owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
/* new typedef for dog as dog_t */
typedef struct dog dog_t;

/* Function prototype for initializing struct dog */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif /* DOG_H */
