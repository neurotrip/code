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

void data_insert(struct player players[], int *count, int *player_count);
void data_fprint(struct player players[], FILE *fp, int *game_counter, int *count);
int main()
{
	FILE *fp;
	int count = 0;
	int player_count = 0; 
	struct player players[10];


	fp = fopen("player_count.data", "r");
	if (fp != NULL) {
          fscanf(fp, "%d", &player_count);
          fclose(fp);
      }
      else {
          fp = fopen("player_count.data", "w");
          player_count = 0;
          fprintf(fp, "%d", player_count);
          fclose(fp);
      }


	printf("Введите данные игрока\n");
	printf ("Введите имя\n");

	data_insert(players, &count, &player_count);  	
	printf ("player_count%d count%d\n", player_count, count);

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
	data_fprint(players, fp, &game_counter, &count);
	fclose(fp);
	game_counter++;	
	fp = fopen("game_counter.data","w");
    fprintf(fp, "%d", game_counter);
    fclose(fp);

	fp = fopen("player_count.data","w");
	fprintf(fp, "%d", player_count);
	fclose(fp);

	fp = fopen("player.data", "r");
	if (fp == NULL) {
		perror("Ошибка");
		return 1;
	}

	printf ("Вывод всех и подсчёт\n");

	char buffer[1000];
	int index = 0;
	int game_count_buf = 0;
		while (fgets(buffer, 1000, fp) != NULL && index < player_count) {
			if (strstr(buffer, "ИГРА НОМЕР") != NULL) {
        		sscanf(buffer, "ИГРА НОМЕР %d", &game_count_buf);
        		printf("ИГРА НОМЕР %d\n", game_count_buf);
			}
		 	if  (sscanf(buffer, "%d %49s %49s %d %d %d %d", 
						&players[index].number, players[index].name, players[index].surname, &players[index].points, 
						&players[index].action_1, &players[index].action_2, &players[index].action_3) == 7) {
				

				players[index].mid = players[index].points + players[index].action_1 +
									 players[index].action_2 + players[index].action_3;

				printf("Игрок %d: %s %s, Очки: %d, Действия: %d, %d, %d, Среднее значение: %.2lf\n",
               			players[index].number, players[index].name, players[index].surname, 
							players[index].points, players[index].action_1, players[index].action_2, players[index].action_3, players[index].mid);
				index++;	
			}
			
			
			
			
		}
	
	fclose(fp);

	return 0;
}


void data_insert(struct player players[], int *count, int *player_count)
{

	size_t len1, len2;
	int i = 0;
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
        (*count)++;
        (*player_count)++;
        printf("Введите имя\n");
        fgets(players[i].name, LEN, stdin);
    }
	
}

void data_fprint(struct player players[], FILE *fp, int *game_counter, int *count)
{	
	int j = 1;
    fprintf (fp, "ИГРА НОМЕР %d\n", *game_counter);
    for (int i = 0; i < *count; i++) {
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
}
