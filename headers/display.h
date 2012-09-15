#pragma warning( disable : 4244)	// STOP MSVS2005 WARNINGS
#pragma warning( disable : 4267)

/*Dialog Info Functions*/

//add line breaks to text
void BreakText(char *dest, const char *src)
{
	int dest_index=0;
	
	for(int src_index=0; src[src_index]; src_index++)
	{
		dest[dest_index++]=src[src_index];
		
		if(((src_index+1)%iLineChars)==0)
			{dest[dest_index++]='\r'; dest[dest_index++]='\n';}
	}
	
	dest[dest_index]='\0';
}

//set given text to clipboard
void SetClipboardText(const char *szClipText)
{
}

//set given text to clipboard
void GetClipboardText(char *szClipText)
{
}

//set window title
void SetTitle()
{
}

/*Text Display*/

//reset text scrollbar
void SetScrollBar()
{	
	
}

//draw outline/underline for range of characters
void OutlineChars()
{
}

//draw all the necessary outlines/underlines
void DrawOutlines()
{
	
}

void OutputText(int bSection)
{
}

//refresh text display
void SetText()
{
}

//update when the selected symbol changes
void UpdateSelectedSymbol()
{
}

//handle click in text area
int TextClick(int click_x, int click_y)
{
	return 1;
}

void SetTextSel(int iIndex)
{
}

//draw white rects on text areas, and set up cliping paths
void ClearTextAreas()
{
	
}

void SetLineChars(int new_line_chars, int display=true)
{
}

//set font size
void SetCharSize()
{
}

//call when key is changed to decode and display plain text
void SetPlain()
{
	return;
	if(!siSolveInfo.running) 
		siSolveInfo.best_score=calcscore(message,message.GetLength(),message.GetPlain());
}

/*Solve Tab Display*/

void AddPattern(NGRAM *pattern)
{
}

//refresh pattern list
void SetPatterns()
{
	
}

void SetSort(int iNewSort)
{
}

//refresh key list
void SetMonoKey()
{
}

void SetDiKey()
{
}

void SetKey()
{
	if(0) SetDiKey();
	else SetMonoKey();
}

//update symbol in list
void UpdateSymbol(int index)
{
}

void UpdateDigraph(int index)
{
	
}

//refresh solver info
inline void SetSolve()
{

}

/*Analysis Tab Display*/

//refresh symbol table
inline void SetTable()
{
}

//refresh letter frequency list
void SetFreq()
{
}

/*Word List Display*/

//put all dictionary words in text into the StringArray
int GetWordList(const char *text)
{
	return 1;
}

//set the word list box
void SetWordList()
{
	
}

inline void SetGraph()
{
}

inline void SetSolveTabInfo()		{SetKey(); SetSolve();}
inline void SetAnalysisTabInfo()	{SetTable(); SetFreq(); }
inline void SetWordListTabInfo()	{if(!siSolveInfo.running) SetWordList();}

inline void SetStatsTabInfo()
{
	
}

inline void SetContactTabInfo()
{
	
}

void SetMainStatus()
{
}

void SetKeyEdit()
{
}

inline void SetDlgInfo()
{
	if(!bMsgLoaded) return;
	
	if(siSolveInfo.running) //set key to hillclimber best if running
	{
		if(iSolveType==SOLVE_HOMO) {message.cur_map.FromKey(siSolveInfo.best_key); message.Decode();}
		SetKeyEdit();
	}
		
	SetPlain();
	
	//info on tabs, tabu tab is updated only when a tabu is made
	SetSolveTabInfo(); SetAnalysisTabInfo(); SetWordListTabInfo(); SetStatsTabInfo(); 
	
}

void GetKeyEdit()
{
}

void SetSolveTypeFeatures()
{
	int menu_state;
	//decoding info
	message.SetDecodeType(iSolveType);
	if(ASCIPHER_TYPE) message.cur_map.AsCipher();
	message.InitKeys();
	SetKeyEdit();
}

//call when the cipher is changed, i.e. symbol merge
void SetCipher()
{	
}

//resize the children in the text window
void ResizeText(int iNewWidth, int iNewHeight)
{
	
}

void ShowTab(int iTab)
{

}

//create right click menu
void CreateTextMenu()
{
	
}
