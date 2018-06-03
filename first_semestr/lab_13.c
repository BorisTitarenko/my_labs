#include <stdio.h>
#include <stdlib.h>

#define NAME 20

struct students{
	int id;
	char name[NAME];
	char surname[NAME];
	int age;
	int marks[6];
	double middle_mark;
	struct students *next;
};

typedef struct students Students;

void fill_structs(Students ** , char *);
void process_students(Students **);
void show_students(const Students *);
void release_structs(Students **);


int main(int argc, char * argv[]){
	if (argc == 1){
		printf("no input files");
		return 1;
	}
	else{
		Students * start= 0;
		fill_structs(&start, argv[1]);
		show_students(start);
		process_students(&start);
		show_students(start);
		release_structs(&start);
	}
	getchar();
	getchar();
	return 0;
}
void fill_structs(Students ** start, char * path){
	Students * p = malloc(sizeof(Students));
	FILE *table;
	table = fopen(path, "r");
	int id, day, month, year;
	do{
		fscanf(table, "%i.%s %s %*[ \t|]%i.%i.%i %*[ |]%i %i %i %i %i %i\r\n", 
		&(p->id), p->name, p->surname, &day, &month, &year, p->marks, p->marks+1, p->marks+2, p->marks+3,
		p->marks+4, p->marks+5);
		int age =  2017*365 - (year * 365 + month * 30 + day);
		p->age = age;
		p->middle_mark = (double)(p->marks[0] + p->marks[1] + p->marks[2] + 
		p->marks[3] + p->marks[4] + p->marks[5])/6; 
		if (!(*start)){
			*start = p;
		}
		Students * p_next = malloc(sizeof(Students));
		p->next = p_next;
		p = p_next;	 
		
	}while(!feof(table));
	
	fclose(table);
	p->next = NULL;
	
}

void process_students(Students ** head){
	Students * curent = *head;
	double middle_age = 0;
	int count = 0;
	while(curent->next){
		middle_age += curent->age;
		count++;
		curent = curent->next;
	}
	middle_age /= count;
	curent = *head;
	
	while(curent->next){
		if((double)curent->age < middle_age || curent->marks[1]==3){
			Students * temp = *head;
			if (curent != (*head)){
				while(temp->next != curent){
					temp = temp->next;
				}
				temp->next = curent->next;
				free(curent);
				curent = temp->next;
			}
			else{
				curent = *head = (*head)->next;
				free(temp);
			}
		}
		else{
			curent = curent->next;
		}
	}
	
    Students *new_head = NULL;
    while (*head != NULL ){
        Students *new_temp = *head;
        *head = (*head)->next;
        if ( new_head == NULL || new_temp->middle_mark > new_head->middle_mark ){
            new_temp->next = new_head;
            new_head = new_temp;
        }
        else{
            Students *current = new_head;
            while ( current->next != NULL && !( new_temp->middle_mark > current->next->middle_mark) ){                   
                  current = current->next;
            }                
            new_temp->next = current->next;
            current->next = new_temp;
        }
    }
	*head = new_head;
}	
void show_students(const Students * head){
	printf("\n\n\n\n");
	while(head->next){
		printf("%-15s %-15s  %f\n", head->name, head->surname, head->middle_mark);
		head = head->next;
	}
}
void release_structs(Students ** head){
	while((*head)->next){
		Students * curent = *head;
		*head = (*head)->next;
		free(curent);
	}
}
