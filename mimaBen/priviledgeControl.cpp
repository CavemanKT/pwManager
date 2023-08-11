#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priviledgeControl.h"
#include "data.h"

void adminCheck() {

	char adminAccount[50];
	char adminPw[50];
	printf("Please confirm you are administrator.\n");
	printf("enter admin username please: \n");
	scanf_s("%s", adminAccount, 50);
	printf("enter admin password please: \n");
	scanf_s("%s", adminPw, 50);
	if (strcmp(adminAccount, username) || strcmp(adminPw, password)) {
		printf("wrong username or password\n\n");
		exit(0);
		return;
	}
	else {
		printf("welcome administrator\n");
		printf("you can continue your operation. \n\n");

	}





}
