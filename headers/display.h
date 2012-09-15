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

//call when key is changed to decode and display plain text
void SetPlain()
{
	return;
	if(!siSolveInfo.running) 
		siSolveInfo.best_score=calcscore(message,message.GetLength(),message.GetPlain());
}


inline void SetDlgInfo()
{
	if(!bMsgLoaded) return;
	
	if(siSolveInfo.running) //set key to hillclimber best if running
	{
		if(iSolveType==SOLVE_HOMO) {message.cur_map.FromKey(siSolveInfo.best_key); message.Decode();}
	}
		
	SetPlain();
	
	//info on tabs, tabu tab is updated only when a tabu is made
	
	
}


void SetSolveTypeFeatures()
{
	int menu_state;
	//decoding info
	message.SetDecodeType(iSolveType);
	if(ASCIPHER_TYPE) message.cur_map.AsCipher();
	message.InitKeys();
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
