#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crud.h"
#include "data.h"



// 1. showAll
void PrintAllInfo(int nCount) {

	printf("Here you go..\n\n\n");
	printf("\n------------------------------------------------------------------------------\n");
	printf("|  website  |  username  |  password  |  remark  |\n");
	
	for (int i = 0; i < nCount; i++) {
		printf("\n------------------------------------------------------------------------------\n");
		printf("|  %s  |  %s  |  %s  |  %s  |", g_pInfo[i].WebSite, g_pInfo[i].Username, g_pInfo[i].Mima, g_pInfo[i].Remark);
		printf("\n-----------------------------------------------------------------------------\n");

	}

	printf("\n\n\nCompleted the printing.\n\n\n");


}

// 2. create 
void AddInfo(int* pCount)
{
	printf("Please input a website: \n");
	scanf_s("%s", g_pInfo[*pCount].WebSite, 50);
	printf("Please input a username: \n");
	scanf_s("%s", g_pInfo[*pCount].Username, 50);
	printf("please input a password: \n");
	scanf_s("%s", g_pInfo[*pCount].Mima, 50);
	printf("please input a remark: \n");
	scanf_s("%s", g_pInfo[*pCount].Remark, 50);
	(*pCount)++;

	if (*pCount == g_num) {
		P_TEXTINFO pTemp = (P_TEXTINFO)malloc(g_num * 2 * sizeof(TEXTINFO));  // we get g_num everytime we open the file;
		memcpy(pTemp, g_pInfo, g_num * sizeof(TEXTINFO));
		free(g_pInfo);
		// g_pInfo get new memory space now.
		g_pInfo = pTemp;
		g_num *= 2;
		return;
	}
}

// 3. modify
void AlterInfo(int nCount) {
	printf("please input the website you need to modify.\n");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 50);
	for (int i = 0; i < nCount; i++) {
		if (strcmp(g_pInfo[i].WebSite, buf) == 0) {
			printf("please input a new website: \n");
			scanf_s("%s", g_pInfo[i].WebSite, 50);
			printf("please input a new username: \n");
			scanf_s("%s", g_pInfo[i].Username, 50);
			printf("please input a new password: \n");
			scanf_s("%s", g_pInfo[i].Mima, 50);
			printf("please input a new remark: \n");
			scanf_s("%s", g_pInfo[i].Remark, 50);
			return;
		}
	}
	printf("no such website\n");
	return;
}

// 4. search
void PrintOneInfo(int nCount) {   // nCount here is the total number of records.
	nCount++;
	int nFind = 0;
	char yes[10] = "NO";

		printf("please input the website you need to search.\n");
		char buf[50] = { 0 };
		scanf_s("%s", buf, 50);
		printf("\n------------------------------------------------------------------------------\n");
		printf("|  website  |  username  |  password  |  remark  |\n");
		for (int i = 0; i < nCount; i++) {
			if (strcmp(g_pInfo[i].WebSite, buf) == 0) {
				printf("\n-----------------------------------------------------------------------------\n");
				printf("| %s | %s | %s | %s |\n", g_pInfo[i].WebSite, g_pInfo[i].Username, g_pInfo[i].Mima, g_pInfo[i].Remark);
				printf("\n-----------------------------------------------------------------------------\n");

				nFind = 1;
			}
		}
		if (nFind == 0) {
			printf("no such website\n");
		}

	return;
}

// 5. del
void DeleteInfo(int* pCount) {
	printf("Please input the website you need to delete.\n");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 50);
	for (int i = 0; i < *pCount; i++) {
		if (strcmp(g_pInfo[i].WebSite, buf) == 0) {
			printf("\n%s is found", buf);

			for (int j = i; j < *pCount - 1; j++) {
				g_pInfo[j] = g_pInfo[j + 1];
			}
			(*pCount)--;
			printf("\nDeleted successfully.\n");
			return;
		}
	}
	printf("\nFail to delete..\n");
	return;
}
