#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TICKETS 12
#define LEN 30

struct ticket {
	int place_number;
	int place_status;
	char surname_psngr[LEN];
	char name_psngr[LEN];
};

void add_psngr(struct ticket p_data[]);
void free_place(struct ticket p_data[]);
void list_place(struct ticket p_data[]);
void delete_place(struct ticket p_data[]);
int compare_tickets(const void *a, const void *b);
void show_sorted_occupied_seats(struct ticket *p_data);

int main(void) 
{
	struct ticket p_data[12];
	FILE *fp;
	char choice;
	char buffer[1000];

	fp = fopen("flight.data", "r");
	if (fp == NULL) {
		fp = fopen("flight.data", "a+");
		for (int i = 0; i < 12; i++) {
			p_data[i].place_number = i + 1;
			p_data[i].place_status = 0;
			strcpy(p_data[i].name_psngr, "n0ne");
			strcpy(p_data[i].surname_psngr, "n0ne");
			fprintf(fp,"%d %d %30s %30s\n", 
					p_data[i].place_number, p_data[i].place_status, p_data[i].name_psngr, p_data[i].surname_psngr);
		}
		fclose(fp);
	} else {
		int i = 0;
		while (fgets(buffer, sizeof(buffer), fp) && i < NUM_TICKETS) {
    		if (sscanf(buffer, "%d %d %s %s",
               &p_data[i].place_number, &p_data[i].place_status, p_data[i].surname_psngr, p_data[i].name_psngr) == 4) {
       	 		i++;
    		} else {
        		printf("Ошибка чтения данных для билета %d\n", i+1);
        		// обработка ошибки
    		}
		}
		fclose(fp);
    }

	
	printf("Для выбора функции введите ее буквенное значение\n");
	printf("a) Показать свободное количество мест\n");
	printf("b) Показать список пустых свободных мест\n");
	printf("с) Показать алфавитный список занятых мест\n");
	printf("d) Назначить пассажиру место\n");
	printf("e) Удалить назначение места\n");
	printf("f) Выйти из программы\n");
	while ((choice = getchar()) != 'f') {
		switch (choice) {
		case 'a' :  free_place(p_data);
					break;
		case 'b' :  list_place(p_data);
					break;
		case 'c' :  show_sorted_occupied_seats(p_data);
					break;
		case 'd' :  add_psngr(p_data);
					break;
		case 'e' :  delete_place(p_data);
				    break;			
		}

	}
	return 0;
}

void add_psngr(struct ticket p_data[]) {
    int ticket_number = 0;
    printf("Введите номер места для пассажира (1-12):\n");
    scanf("%d", &ticket_number);
    getchar(); // Убираем символ новой строки из буфера ввода

    if (ticket_number < 1 || ticket_number > NUM_TICKETS) {
        printf("Некорректный номер места.\n");
        return;
    }

    
    FILE *fp = fopen("flight.data", "r");
    if (fp == NULL) {
        printf("Файл не найден\n");
    } else {
		for (int i = 0; i < NUM_TICKETS; i++) {
            fscanf(fp, "%d %d %s %s\n",
                   &p_data[i].place_number, &p_data[i].place_status, p_data[i].surname_psngr, p_data[i].name_psngr);
        }
        fclose(fp);
    }


    --ticket_number; 

    printf("Введите фамилию пассажира:\n");
    fgets(p_data[ticket_number].surname_psngr, LEN, stdin);
    strtok(p_data[ticket_number].surname_psngr, "\n"); 

    printf("Введите имя пассажира:\n");
    fgets(p_data[ticket_number].name_psngr, LEN, stdin);
    strtok(p_data[ticket_number].name_psngr, "\n"); 

    p_data[ticket_number].place_status = 1; 

    
	fp = fopen("flight.data", "w");
    for (int i = 0; i < NUM_TICKETS; i++) {
		fprintf(fp,"%d %d %30s %30s\n",
                     p_data[i].place_number, p_data[i].place_status, p_data[i].name_psngr, p_data[i].surname_psngr);
    }
    fclose(fp);
}


void free_place(struct ticket p_data[]) 
{
	int count = 0;

	for (int i = 0; i < NUM_TICKETS; i++) {
		if (p_data[i].place_status == 0)
			count++;
	}

	printf("Количество свободных мест %d\n", count);
}

void list_place(struct ticket p_data[])
{
	printf ("Свободны места\n");
	for (int i = 0; i < NUM_TICKETS; i++) {
		if (p_data[i].place_status == 0) {
			printf("%d ", p_data[i].place_number);
		}
	}
	printf("\n");

}


int compare_tickets(const void *a, const void *b) 
{
    struct ticket *ticketA = (struct ticket *)a;
    struct ticket *ticketB = (struct ticket *)b;

    int surname_cmp = strcmp(ticketA->surname_psngr, ticketB->surname_psngr);
    if (surname_cmp == 0) {
        return strcmp(ticketA->name_psngr, ticketB->name_psngr);
    }
    return surname_cmp;
}

void show_sorted_occupied_seats(struct ticket *p_data) 
{
    struct ticket sorted_tickets[NUM_TICKETS];
    memcpy(sorted_tickets, p_data, sizeof(sorted_tickets));

    qsort(sorted_tickets, NUM_TICKETS, sizeof(struct ticket), compare_tickets);

    printf("Алфавитный список занятых мест:\n");
    for (int i = 0; i < NUM_TICKETS; i++) {
        if (sorted_tickets[i].place_status != 0) {  
            printf("Место номер %d, Фамилия пассажира: %s, Имя пассажира: %s\n",
                   sorted_tickets[i].place_number, sorted_tickets[i].surname_psngr, sorted_tickets[i].name_psngr);
        }
    }
}

void delete_place(struct ticket p_data[]) 
{
	printf("Введите место для удаления\n");
	int i = 0;
	scanf("%d", &i);
	--i;
	p_data[i].place_number = i + 1;
    p_data[i].place_status = 0;
    strcpy(p_data[i].name_psngr, "n0ne");
    strcpy(p_data[i].surname_psngr, "n0ne");
	FILE *fp = fopen("flight.data", "w");
	for (int i = 0; i < NUM_TICKETS; i++) {
    	fprintf(fp,"%d %d %30s %30s\n",
                p_data[i].place_number, p_data[i].place_status, p_data[i].name_psngr, p_data[i].surname_psngr);
	}
	fclose(fp);
	printf("Готово!\n");
}


