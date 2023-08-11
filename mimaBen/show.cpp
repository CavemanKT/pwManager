#include <stdio.h>
#include "show.h"

void PrintMenu() {
	printf("Welcome to my Password manager!\n");
	printf("Input your choice: \n");
	printf("1. Show all passwords\n");		// PrintAllInfo(nCount);
	printf("2. Create a new password\n");   // AddInfo(&Count);
	printf("3. Edit a password\n");         // UpdateMima(nCount);
	printf("4. Search a password\n");		// PrintOneInfo(nCount);
	printf("5. Delete a password\n");		// DeleteMima(&nCOunt);
	printf("6. Exit\n");					// exit
}