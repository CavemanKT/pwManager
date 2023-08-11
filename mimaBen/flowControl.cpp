#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "flowControl.h"  // header
#include "data.h"   // need constant

int countdown(int sec) {
	printf("\n\nGo to menu in %d seconds......\n\n", sec--);
	Sleep(1000);
	system("cls");
	return sec;
}
void waitForMenu(int count) {
	int sec = count;
	system("cls");
	while (sec > 0) {
		sec = countdown(sec);
	}
}

void hitToContinue() {
	printf("hit enter to continue...");
	system("pause");
}