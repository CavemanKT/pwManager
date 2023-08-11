#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

#include "crud.h"
#include "fileOpener.h"
#include "data.h"
#include "show.h"
#include "priviledgeControl.h"
#include "flowControl.h"


int main() {

	int nCount = 0;
	int nSelect = 0;

	adminCheck();
	start:
	
	// initialization
	ReadMimaInfo(&nCount);				// encrypt & decrypt
	
	//print menu
	while (1)
	{
		PrintMenu();

		// check if it's a number
		int keyCode = _getch();
		if(keyCode >= 49 && keyCode <= 54)  
		{
			nSelect = keyCode - 48;
		}
		else {
			printf("\nEnter that damn number again !\n\n");
			hitToContinue();
			waitForMenu(SecCd);
			goto start;
		}

		switch (nSelect)
		{
		case showAll:
			//print all info
			PrintAllInfo(nCount);  // Done
			hitToContinue();
			waitForMenu(SecCd);
			goto start;
			break;
		case add:
			//addInfo
			AddInfo(&nCount);		// Done
			SaveFile(nCount);		// Done
			hitToContinue();
			waitForMenu(SecCd);
			goto start;
			break;
		case edit:
			//update
			AlterInfo(nCount);		// Done
			SaveFile(nCount);		// Done
			hitToContinue();
			waitForMenu(SecCd);
			goto start;
			break;
		case search:
			//print one info
			PrintOneInfo(nCount);	// Done
			hitToContinue();
			waitForMenu(SecCd);
			goto start;
			break;
		case del:
			//delete
			DeleteInfo(&nCount);	// Done
			SaveFile(nCount);		// Done
			hitToContinue();
			waitForMenu(SecCd);
			goto start;
			break;
		case exitTheProgram:
			//exit
			printf("See you next time.\n");
			printf("exit\n");
			exit(0);
			break;
		default:
			printf("ERROR!\n");
			hitToContinue();
			waitForMenu(SecCd);
			goto start;
			break;
		}


		break;
	}




	system("pause");
	system("cls");
	return 0;
}
