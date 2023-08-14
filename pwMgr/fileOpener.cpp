#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "fileOpener.h"
#include "data.h"

void ReadMimaInfo(int* pCount)
{
	FILE* fp = NULL;
	int nError = fopen_s(&fp, "mimaInfo.txt", "rb+");

	if (nError != 0) { // nError is equal to 2 here if we can't open the file
		printf("fail to open the file.\n");
		g_pInfo = (TEXTINFO*)malloc(initialVal * sizeof(TEXTINFO));
		//memset(g_pInfo, 0, initialVal * sizeof(TEXTINFO));
		g_num = initialVal;
		*pCount = 0;
		return;
	}

	// 3. if opened, read the head info.
	fread(&g_num, 4, 1, fp);  // read the total number of records
	fread(pCount, 4, 1, fp); // read the number of records of password -- mima

	if (g_num == 0)
	{
		printf("no records.\n");
	}
	// set the memory according to the total number of records
	g_pInfo = (TEXTINFO*)malloc(g_num * sizeof(TEXTINFO));
	memset(g_pInfo, 0, g_num * sizeof(TEXTINFO));

	// 4. read the info
	fscanf_s(fp, "\n");
	for (int i = 0; i < *pCount; i++){
		fscanf_s(fp, "%s\n", g_pInfo[i].WebSite, 50);
		for (int j = 0; j < strlen(g_pInfo[i].WebSite); j++){     // every inner loop here is to decrypt the string when saving into the file.
			g_pInfo[i].WebSite[j] = g_pInfo[i].WebSite[j] ^ SecretKey;
		}
		fscanf_s(fp, "%s\n", g_pInfo[i].Username, 50);
		for (int j = 0; j < strlen(g_pInfo[i].Username); j++) {
			g_pInfo[i].Username[j] = g_pInfo[i].Username[j] ^ SecretKey;
		}
		fscanf_s(fp, "%s\n", g_pInfo[i].Mima, 50);
		for (int j = 0; j < strlen(g_pInfo[i].Mima); j++) {
			g_pInfo[i].Mima[j] = g_pInfo[i].Mima[j] ^ SecretKey;
		}
		fscanf_s(fp, "%s\n", g_pInfo[i].Remark, 50);
		for (int j = 0; j < strlen(g_pInfo[i].Remark); j++) {
			g_pInfo[i].Remark[j] = g_pInfo[i].Remark[j] ^ SecretKey;
		}
	}

	// 5. close the file
	fclose(fp);
}




void SaveFile(int nCount)
{
	// 1. open the file
	FILE* fp = NULL;
	int nError = fopen_s(&fp, "mimaInfo.txt", "wb+");
	if (nError != 0) { // most likely to be zero here because we can create a file even if there is no file unless it's system error.
		return;
	}

	// 2. read the head info and write the number of records;
	fwrite(&g_num, 4, 1, fp);
	fwrite(&nCount, 4, 1, fp);

	// 3. write the info
	fprintf(fp, "\n");
	for (int i = 0; i < nCount; i++) {
		for (int j = 0; j < strlen(g_pInfo[i].WebSite); j++)       // every inner loop here is to encrypt the string when saving into the file.
		{
			g_pInfo[i].WebSite[j] ^= SecretKey;
		}
		fprintf(fp, "%s\n", g_pInfo[i].WebSite);
		for (int j = 0; j < strlen(g_pInfo[i].Username); j++)
		{
			g_pInfo[i].Username[j] ^= SecretKey;
		}
		fprintf(fp, "%s\n", g_pInfo[i].Username);
		for (int j = 0; j < strlen(g_pInfo[i].Mima); j++)
		{
			g_pInfo[i].Mima[j] ^= SecretKey;
		}
		fprintf(fp, "%s\n", g_pInfo[i].Mima);
		for (int j = 0; j < strlen(g_pInfo[i].Remark); j++)
		{
			g_pInfo[i].Remark[j] ^= SecretKey;
		}
		fprintf(fp, "%s\n", g_pInfo[i].Remark);

	}
	// 4. close the file
	printf("Closing the file.\n");
	fclose(fp);
}