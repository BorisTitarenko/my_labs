#include <stdio.h>
#include <time.h>
#include <string.h>
#define SIZE 100000

void fill_array(int array[], int array_2[]);
void swap(int array[], int pos1, int pos2);
void qs_sort(int array[], int start, int end);
void ins_sort(int array_2[]);
void check_array(int array[], int array_2[]);

int main(void){
	int array[SIZE];
	int array_2[SIZE];
	fill_array(array, array_2);
	
	clock_t start = clock();
	qs_sort(array, 0, SIZE-1);
	clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time of work first sorting = %f seconds\n", seconds);
	
	start = clock();
	ins_sort(array_2);
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time of work second sorting = %f seconds\n", seconds);
	
	check_array(array, array_2);
	
	getchar();
	getchar();
}
void fill_array(int array[], int array_2[]){
	FILE * numfile;
	numfile = fopen("random.txt", "rb");
	fread(array, sizeof(int), SIZE, numfile);
	memcpy(array_2, array, sizeof(int)*SIZE);
	fclose(numfile);

}
void swap(int array[], int  pos1, int  pos2) {  
	int tmp; 
	tmp=array[pos1]; 
	array[pos1]=array[pos2];  
	array[pos2]=tmp; }
	
void qs_sort(int array[], int start, int end){

  int l = start, r = end;
  int piv = array[(l + r) / 2]; 
  while (l <= r)
  {
    while (array[l] < piv){
		l++;}
    while (array[r] > piv){
		r--;}
    if (l <= r){
		swap (array, l++, r--);}
	}
	if (start< r){
		qs_sort (array, start, r);}
	if (end > l){
		qs_sort (array, l, end);}
} 

void ins_sort(int array_2[]){
	for (int i = 0; i < SIZE; i++){
		for(int j=i+1;j>0 && array_2[j-1] > array_2[j]; j--){
			swap(array_2, j-1, j);
		}
	}
}

void check_array(int array[], int array_2[]){
	int flag = 1;
	flag = 1;
	for(int i = 1; i < SIZE; i++){
		if(array[i] > array[i+1]){
			flag = 0;
			break;}
	}
	if (flag){printf("first array sorted corectly\n");}
	else {printf("first array sorted incorectly\n");}

	flag = 1;
	for(int i = 0; i < SIZE; i++){
		if(array_2[i] > array_2[i+1]){
			flag = 0;
			break;}
	}
	if (flag){printf("second array sorted corectly\n");}
	else {printf("second array sorted incorectly\n");}
}