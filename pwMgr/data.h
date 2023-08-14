#pragma once
#define showAll 1
#define add 2
#define edit 3
#define search 4
#define del 5
#define exitTheProgram 6


#define initialVal 4
#define SecCd 3
#define SecretKey 7

// manager account
#define username "admin"
#define password "123"

typedef struct _TEXTINFO
{
	char WebSite[50];
	char Username[50];
	char Mima[50];
	char Remark[50];
}TEXTINFO, *P_TEXTINFO;

extern P_TEXTINFO g_pInfo;
extern int g_num;
