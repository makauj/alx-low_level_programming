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

/* Function prototype for initializing a dog structure */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
