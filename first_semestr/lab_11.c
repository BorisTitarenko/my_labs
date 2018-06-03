#include <stdio.h>
#define STUDENTS 20
#define NAME 30
struct students{
	char name[NAME];
	char surname[NAME];
	int age;
	int marks[4];
};
struct array{
	char name[NAME];
	char surname[NAME];
	double middle_mark;
};
void fill_struct(struct students * );
void sort_students(struct students * , struct array *);
void display( struct array *, int );
void swap(struct array * , int pos_1, int pos_2);

int main(void) {
	struct students data[STUDENTS] ;
	struct array upper_middle[STUDENTS];
	fill_struct(data);
	
	sort_students(data, upper_middle);
	
}

void fill_struct(struct students * data) {
	FILE *table;
	table = fopen("students.txt", "r");
	for (int i = 0; i < STUDENTS && !feof(table); i++) {
		int day, month, year, id;
		fscanf(table, "%i.%s %s %*[ \t|]%i.%i.%i %*[ |]%i %i %i %i\r\n",&id, &data[i].name, &data[i].surname, &day, &month, &year, 
		&data[i].marks[0], &data[i].marks[1], &data[i].marks[2], &data[i].marks[3]);
		data[i].age = 2017*365 - (year * 365 + month * 30 + day);
	}
	fclose(table);
}
void swap(struct array * upper_middle,int pos_1, int pos_2){
	struct array temp = upper_middle[pos_1];
	upper_middle[pos_1]= upper_middle[pos_2];
	upper_middle[pos_2]=temp;
	}
void sort_students(struct students * data, struct array * upper_middle){
	int sum = 0, index;
	for(int i = 0; i < STUDENTS; i++){
		sum += data[i].age;
	}
	double a = (double)sum/STUDENTS;
	index = 0;
	for (int i = 0; i < STUDENTS; i++){
		if (data[i].age > a ){
			memcpy(upper_middle[index].name, data[i].name, sizeof(char)*STUDENTS);
			memcpy(upper_middle[index].surname, data[i].surname, sizeof(char)*STUDENTS);
			upper_middle[index].middle_mark = (double)(data[i].marks[0] +
			data[i].marks[1] + data[i].marks[2] + data[i].marks[3])/4;
			index++;
		}
	}
			
	for (int i = 0; i < index-1; i++){
		for(int j=i+1;j>0 && upper_middle[j-1].middle_mark < upper_middle[j].middle_mark; j--){
			swap(upper_middle, j-1, j);}
	}	
	display(upper_middle, index);
}
  
void  display(struct array * upper_middle, int n){
	for (int i = 0; i < n; i++){
		printf("%-15s %-15s %6.2f\n", upper_middle[i].name, upper_middle[i].surname, upper_middle[i].middle_mark);
	}
}




