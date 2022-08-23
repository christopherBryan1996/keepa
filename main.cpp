 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
 
#include <stdio.h>
#include <string.h>
 

int main(int argc, char** argv) {
	
	char fname[1024]="DB/car_ad.csv";
	 
	FILE *file = fopen(fname, "r");
	
	if(!file)
	{
		printf("Could not open the file\n");
		return 0;
	}
	std::cout << file;
	char content[1024];
	while(fgets(content, 1024, file))
	{
		char *v = strtok(content, ",");
		while(v)
		{
			printf("%s ", v);
			v = strtok(NULL, ",");
		}
		printf("\n");
	}
	fclose(file);
	
	std::cout << "Hello world!\n";
	return 0;
}
