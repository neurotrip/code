#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100
#define GROUPLEN 6

char buf[BUFSIZE];
int bufp = 0;

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int getch(void);
void ungetch(int c);

int main(void)
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);

    return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {
        p = (struct tnode *)malloc(sizeof(struct tnode));
        (*p).word = strdup(w);
        (*p).count = 1;
        (*p).left = (*p).right = NULL;
    } else if ((cond = strncmp(w, (*p).word, GROUPLEN)) == 0) {
        (*p).count++;
    } else if (cond < 0) {
        (*p).left = addtree((*p).left, w);
    } else {
        (*p).right = addtree((*p).right, w);
    }

    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint((*p).left);
		if ((*p).count > 1) {
        	printf("%4d %s\n", (*p).count, (*p).word);
		}
        treeprint((*p).right);
    }
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}

int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        *w = getch();
        if (!isalnum(*w) && *w != '_') {
            if (*w == '/') {
                if ((c = getch()) == '*') {
                    while ((*w = getch()) != EOF) {
                        if (*w == '*' && (c = getch()) == '/')
                            break;
                        ungetch(c);
                    }
                } else if (c == '/') {
                    while ((*w = getch()) != EOF && *w != '\n')
                        ;
                } else {
                    ungetch(c);
                }
            } else if (*w == '\"' || *w == '\'') {
                char quote = *w;
                while ((*w = getch()) != EOF && *w != quote)
                    ;
            } else if (*w == '#') {
                while ((*w = getch()) != EOF && *w != '\n')
                    ;
            } else {
                ungetch(*w);
                break;
            }
        }
    }

    *w = '\0';
    return word[0];
}

