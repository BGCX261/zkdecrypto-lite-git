#ifndef _FILES_H
#define _FILES_H

#include "zodiac.h"

void GetBaseName(const char *filename, char *&basename);
int GetFilename(char *szName, const char *szInitDir, int bSave);
void OpenWith(char *szFileName);
void NewMessageInfo(char *filename);
int LoadMessage(char *filename, int type);
int LoadMap(char *filename);
int LoadINI();
int SaveINI();

#endif