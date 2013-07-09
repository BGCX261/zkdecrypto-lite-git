#ifndef _ZODIAC_H
#define _ZODIAC_H

#include "map.h"
#include "z340.h"
#include <map>
#include <string>

//program
#define PROG_NAME	"ZKDecrypto"
#define PROG_VER	"Version 1.2"

//language
#define LANG_DIR	"language"
#define LANG_ENG	"eng"
#define LANG_SPA	"spa"
#define LANG_GER	"ger"
#define LANG_ITA	"ita"
#define LANG_FRE	"fre"

//language IoC
#define IOC_ENG		.0665
#define IOC_SPA		.0746
#define IOC_GER		.0788
#define IOC_ITA		.0746
#define IOC_FRE		.0777
#define IOC_POR		.0746
#define IOC_RUS		.0677
#define IOC_RAND	.0385

#define DIOC		.0075
#define CHI			.55
#define ENT			4.1

//text constants
#define CHAR_WIDTH  7
#define CHAR_HEIGHT 12
#define TEXT_POS	0 //HWND_TOPMOST

#define MAX_EXTRA	104

//macros
#define IN_RECT(X,Y,R)	(IS_BETWEEN(X,R.left,R.right) && IS_BETWEEN(Y,R.top,R.bottom))
#define DIGRAPH_MODE	((iSolveType==SOLVE_DISUB || iSolveType==SOLVE_PLAYFAIR || iSolveType==SOLVE_DBLPLAY)? 1:0) //digraph key and display
#define DEFRACTION_TYPE (iSolveType==SOLVE_ADFGX || iSolveType==SOLVE_ADFGVX || iSolveType==SOLVE_CEMOPRTU) //plain text half as long as cipher
#define ASCIPHER_TYPE	(DEFRACTION_TYPE) //set key as cipher characters
#define TRANSPOSE_TYPE	(iSolveType==SOLVE_PERMUTE || iSolveType==SOLVE_COLTRANS || iSolveType==SOLVE_DOUBLE || iSolveType==SOLVE_TRIPPLE)
#define ALLOW_LOWERCASE (TRANSPOSE_TYPE || iSolveType==SOLVE_CEMOPRTU || iSolveType==SOLVE_SUBPERM || iSolveType==SOLVE_COLVIG)

//cipher/key data & files
extern Message message; //cipher & main key
extern Message undo_message;
extern Message redo_message; //undo/redo messages
extern int undo_line_size;
extern int redo_line_size;
extern char szCipherName[1024];
extern char szKeyName[1024];
extern char szPlainName[1024];
extern char szGraphName[1024]; //filenames

extern char *szCipherBase;
extern char *szKeyBase; //file basenames
extern char szLanguage[32];
extern int bMsgLoaded;
extern int bMapLoaded;
extern int bUndo;
extern int iNumber;
extern int iCurTab;

extern char szString[128];
extern char szStringTitle[128];
extern char szNumberTitle[128]; //word, exclude string

typedef std::map<std::string,int> STRMAP;
extern STRMAP dictionary, tabu_list, word_list;


//solver data
extern int iPriority;
extern int iLang;
extern char szExtraLtr[MAX_EXTRA+1];
extern int iBruteSymbols;
extern int iBatchBestScore;
extern char lprgcBatchBestKey[4096];
extern int iSolveType;
extern int iBlockSize;


#endif

