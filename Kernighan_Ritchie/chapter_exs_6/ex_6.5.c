#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *s);
int main(void)
{
	char *names[] = {"MAX", "MIN", "AVG", NULL};
	char *defs[] = {"100", "0", "50", NULL};
	
	for (int i = 0; names[i] != NULL; i++)
		install(names[i], defs[i]);

	for (int i = 0; names[i] != NULL; i++) {
		struct nlist *np = lookup(names[i]);
		if (np != NULL)
			printf("%s: %s\n", np->name, np->defn);
		else
			printf("%s not found\n", names[i]);
	}
	undef("MAX");
	struct nlist *np = lookup("MAX");
	if (np != NULL)
		printf("MAX: %s\n", np->defn);
	else
		printf("MAX not found\n");

	return 0;
}


struct nlist *lookup(char *s) 
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0)
			return np;
	}

	return NULL;
}

struct nlist *install(char *name, char *defn) 
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else {
		free((void *) np->defn);
	}
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

void undef(char *s) 
{
	unsigned hashval = hash(s);
	struct nlist *prev = NULL;
	struct nlist *np = hashtab[hashval];

	while (np != NULL) {
		if (strcmp(s, np->name) == 0) {
			if (prev == NULL)
				hashtab[hashval] = np->next;
			else
				prev->next = np->next;
			free((void *) np->name);
			free((void *) np->defn);
			free((void *) np);
			return;
		}
		prev = np;
		np = np->next;
	}
}

