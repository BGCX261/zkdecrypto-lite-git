/*File Functions*/

void GetBaseName(const char *filename, char *&basename) 
{
	if(filename[0]!='\0') basename=(char*)strrchr(filename,'\\')+1;
	else basename=NULL;
}

//open/save file name dialog
int GetFilename(char *szName, const char *szInitDir, int bSave)
{
	return 0;
}

//shell execute file
void OpenWith(char *szFileName)
{
}

void NewMessageInfo(char *filename)
{
	//get message filename
	strcpy(szCipherName,filename);
	GetBaseName(szCipherName,szCipherBase);

	//get info
	siSolveInfo.best_score=0;
	bMsgLoaded=true;
	bMapLoaded=false;
	siSolveInfo.best_key[0]='\0';
	if(ASCIPHER_TYPE) message.cur_map.AsCipher();

	//setup window
	bUndo=false;
		
	

	//block size
	int max_block=message.GetLength();
	if(iSolveType==SOLVE_DBLPLAY) max_block>>=1;

	tabu_list.clear();
}

int LoadMessage(char *filename, int type)
{
	int loaderror=false;

	switch(type) 
	{
		case 0: if(!message.Read(filename)) loaderror=true; break; //read as ascii
		case 1: if(!message.ReadNumeric(filename)) loaderror=true; break; //read as numeric
	}

	if(loaderror) //error loading file
	{
		printf("Cannot open %s",(const char*)filename);
		return 0;
	}

	NewMessageInfo(filename);

	return 1;
}

int LoadMap(char *filename)
{
	//Map temp_map;
	
	if(!message.cur_map.Read(filename))
	{
		printf("Cannot open %s",filename);
		return 0;
	}

	siSolveInfo.best_key[0]='\0';
	
	//update symbols from loaded map
	//message.cur_map+=temp_map;

	//get map filename
	strcpy(szKeyName,filename);
	GetBaseName(szKeyName,szKeyBase);

	//get info
	siSolveInfo.best_score=0;
	bMapLoaded=true;
	message.Decode();

	//setup window
	bUndo=false;
	
	SetDlgInfo();

	return 1;
}

//save plaintext to file/clipboard
int SavePlain(char *filename)
{
	return 1;
}

//load zodiac font zkdfont.ttf
int LoadFONT()
{
	return 1;
}

//remove zodiac font zkdfont.ttf
int RemoveFONT()
{
	return 1;
}

//read cribs text file
void LoadCribs()
{
	
}

int LoadTabu(char *filename)
{
	return 1;
}

int SaveTabu(char *filename)
{
	return 1;
}

//read configuration file
int LoadINI()
{
	FILE *ini_file;
	char option[32], value[1024];
	char *comment;
	int read;

	char* szText = "zodiac.ini";

	if(!(ini_file=fopen(szText,"r"))) return 0;

	while((read=fscanf(ini_file,"%s = %[^\n]\n",option,value))!=EOF)
	{
		if(read==1) value[0]='\0';

		//end option/value at comment symbol
		comment=strchr(option,'#'); if(comment) *comment='\0';
		comment=strchr(option,'#'); if(comment) *comment='\0';

		
		if(!strcasecmp(option,"cipher")) strcpy(szCipherName,value);
		else if(!strcasecmp(option,"key")) strcpy(szKeyName,value);
		else if(!strcasecmp(option,"plain")) strcpy(szPlainName,value);
		else if(!strcasecmp(option,"fail")) siSolveInfo.max_tabu=atoi(value);
		else if(!strcasecmp(option,"swap")) siSolveInfo.swaps=atoi(value);
		else if(!strcasecmp(option,"revert")) siSolveInfo.max_tol=atoi(value);
		else if(!strcasecmp(option,"lang")) iLang=atoi(value);
		else if(!strcasecmp(option,"extra")) {if(value[0]=='*') value[0]='\0'; strcpy(szExtraLtr,value);}
		else if(!strcasecmp(option,"solve")) iSolveType=atoi(value);
		else if(!strcasecmp(option,"key_len")) message.SetKeyLength(atoi(value));
		else if(!strcasecmp(option,"tableu_alpha")) {message.SetTableuAlphabet(value);}
	}

	fclose(ini_file);

	return 1;
}

//save configuration file
int SaveINI()
{
	return 1;
}

