#include <stdio.h>
#include <time.h>
#include <math.h>


FILE* logFile;
void itsTime(char* event){
	char buffer[80];
	time_t rawTime; 
    struct tm * timeInfo;
    time ( &rawTime );
    timeInfo = localtime(&rawTime);
	strftime(buffer, 80, "[%Y.%m.%d %H:%M:%S]", timeInfo); 
	fprintf(logFile, "%s %s.\n", buffer, event); 
	
}


int main(void){
	
	
	double x, z, result, vector[2];
	char file_1[16], file_2[16];
	char buffer[80];
	FILE *binFile, *textFile;
	itsTime("Program started");
	logFile = fopen("log.log", "a");
	itsTime("Program started");
	
    scanf("%s", file_1, sizeof(file_1));
	binFile = fopen(file_1, "rb");
	fread(vector, sizeof(double), 2, binFile);
	x = vector[0]; z = vector[1];
	sprintf(buffer, "Parameters file \"%s\" opened. X=%lf, Z=%lf", file_1, x, z); 
	itsTime(buffer);
	
	result = sqrt(exp(x-1/sin(z)));
	sprintf(buffer, "Expression calculated. Result = %lf", result);
	itsTime(buffer);
	fclose(binFile);
	
	scanf("%s", file_2, sizeof(file_2));
	textFile = fopen(file_2, "w");
	fprintf(textFile, "%lf\n", result);
	fclose(textFile);
	sprintf(buffer, "Output file \"%s\" saved", file_2); 
	itsTime(buffer);
	itsTime("Program ended");
	fclose(logFile);
	
	getchar();
	getchar();
	
}