#include <stdio.h>
#include "names_st.h"

void get_names(names * pn)
{
	int i;
	printf("Пожалуйста, введите имя: ");
	fgets(pn->first, SLEN, stdin);
	i = 0;
	while(pn->first[i] != '\n' && pn->first[i] != '\0')
		i++;
	if (pn->first[i] == '\n')
		pn->first[i] = '\0';
	else 
		while(getchar() != '\n')
			continue;
	printf("Пожалуйста, введите фамилию: ");
	fgets(pn->last, SLEN, stdin);
	i = 0;
	while(pn->last[i] != '\n' && pn->last[i] != '\0')
		i++;
	if (pn->last[i] == '\n')
		pn->last[i] = '\0';
	else 
		while(getchar() != '\n')
			continue;
}

void show_names(const names *pn)
{
	printf("%s %s", pn->first, pn->last);
}

