#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101
#define MAXWORD 100
#define BUFSIZE 100
struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

static struct nlist *hashtab[HASHSIZE];
char buf[BUFSIZE];
int bufp = 0;
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
unsigned hash(char *);
int getword(char *, int);
int getch(void);
void ungetch(int);

int main()
{
	char word[MAXWORD];
	char defn[MAXWORD];
	char name[MAXWORD];
	int c;

	while ((c = getword(word, MAXWORD)) != EOF) {
		if (strcmp(word, "#define") == 0) {
			getword(name, MAXWORD);
			getword(defn, MAXWORD);
			install(name, defn);
		} else {
			struct nlist *p;
			if ((p = lookup(word)) != NULL) {
			   printf("%s", p->defn);	
			} else {
				printf("%s", word);
			}
		}
		if (c == '\n' || c == ' ') {
			printf("%c", c);
		}
	}
	return 0;
}

unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 *hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
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
	} else 
		free((void *) np->defn);
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 
{
	if (bufp >= BUFSIZE)
		printf("ungetch: слишком много символов\n");
	else
		buf[bufp++] = c;
}

int getword(char *word, int lim) 
{
	int c, d;
	char *w = word;

	while (isspace(c = getch()))
	;

	if (c != EOF)
		*w++ = c;

	if (c == '"' || c == '\'') {
		while ((d = getch()) != c) {
			*w++ =d;
		}
		*w++ = d;
	} else if (c == '/') {
		if ((d = getch()) == '*') {
			*w++ = d;
			while ((d = getch()) != EOF) {
				if (d == '*' && (d = getch()) == '/')
					break;
				ungetch(d);
			}
		} else {
			ungetch(d);
		}
	
	} else if (!isalpha(c) && c != '_') {
		*w = '\0';
		return c;
	}

	for (; --lim > 0; w++) {
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';

	return word[0];
}

