#ifndef DOG_H
#define DOG_H
/**
 * struct dog - structure that stores information
 *
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
#endif /* DOG_H */
