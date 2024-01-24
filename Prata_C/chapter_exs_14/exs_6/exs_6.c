#include <stdio.h>
#include <string.h>
#define LEN 50

struct player {
	char name[LEN];
	char surname[LEN];
	int points;
	int number;
	int action_1;
	int action_2;
	int action_3;
	double mid;
};

int main()
{
	FILE *fp;
	int i = 0;
	int count = 0;
	int p_ct = 0;
	size_t len1, len2;
	struct player players[10];
	fp = fopen("p_ct.data", "r");
	if (fp != NULL) {
          fscanf(fp, "%d", &p_ct);
          fclose(fp);
      }
      else {
          fp = fopen("p_ct.data", "w");
          p_ct = 0;
          fprintf(fp, "%d", p_ct);
          fclose(fp);
      }

	printf("Введите данные игрока\n");
	printf ("Введите имя\n");
	while (fgets(players[i].name, LEN, stdin) != NULL && players[i].name[0] != EOF) {
		
		printf("Введите фамилию\n");
		fgets(players[i].surname, LEN, stdin);
		printf("Введите количество очков\n");
		scanf("%d", &players[i].points);
		printf("Введите действие 1\n");
		scanf("%d", &players[i].action_1);
		printf("Введите дейтсвие 2\n");
		scanf("%d", &players[i].action_2);
		printf("Введите дейтсвие 3\n");
		scanf("%d", &players[i].action_3);
		
		
		len1 = strlen(players[i].name);
		len2 = strlen(players[i].surname);
		if (players[i].name[len1 - 1] == '\n' && players[i].surname[len2 - 1] == '\n')
		{
			players[i].name[len1 - 1] = '\0';
			players[i].surname[len2 - 1] = '\0';
		}
		i++;
		count++;
		p_ct++;
		printf("Введите имя\n");
		fgets(players[i].name, LEN, stdin);
	}
	
	fp = fopen("game_counter.data", "r");
	int game_counter = 0;
	if (fp != NULL) {
		fscanf(fp, "%d", &game_counter);
		fclose(fp);
	}
	else {
		fp = fopen("game_counter.data", "w");
		game_counter = 1;
		fprintf(fp, "%d", game_counter);
		fclose(fp);
	}


	 	
	fp = fopen("player.data", "a");
	int j = 1;
	fprintf (fp, "ИГРА НОМЕР %d\n", game_counter);
	for (int i = 0; i < count; i++) {	
		fprintf(fp, "%d ", j);
		fputs(players[i].name, fp);
		fputs(" ",fp);
		fputs(players[i].surname, fp);
		fputs(" ",fp);
		fprintf(fp, "%d ",players[i].points);
		fprintf(fp, "%d ",players[i].action_1);
		fprintf(fp, "%d ",players[i].action_2);
		fprintf(fp, "%d ",players[i].action_3);
		fputs("\n",fp);
		j++;
	}
	fclose(fp);
	game_counter++;	
	fp = fopen("game_counter.data","w");
    fprintf(fp, "%d", game_counter);
    fclose(fp);

	fp = fopen("p_ct.data","w");
	fprintf(fp, "%d", p_ct);
	fclose(fp);

	fp = fopen("players.data", "r");

	printf ("Вывод всех и подсчёт\n");

	char buffer[1000];
	int index = 0;
		while (fgets(buffer, 1000, fp) != NULL && index < p_ct) {
			if (sscanf(buffer, "%d %49s %49s %d %d %d %d", 
						&players[index].number, players[index].name, players[index].surname, &players[index].points, 
						&players[index].action_1, &players[index].action_2, &players[index].action_3) == 7) {

				printf("Игрок %d: %s %s, Очки: %d, Действия: %d, %d, %d\n",
               			players[index].number, players[index].name, players[index].surname, 
							players[index].points, players[index].action_1, players[index].action_2, players[index].action_3);
			}	
			index++;
		}
	
	fclose(fp);

	return 0;
}

