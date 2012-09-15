#if 0

#pragma warning( disable : 4244)	// STOP MSVS2005 WARNINGS
#pragma warning( disable : 4267)


inline void SetDlgInfo()
{
	if(!bMsgLoaded) return;
	
	if(siSolveInfo.running) //set key to hillclimber best if running
	{
		if(iSolveType==SOLVE_HOMO) {message.cur_map.FromKey(siSolveInfo.best_key); message.Decode();}
	}	
}


void SetSolveTypeFeatures()
{
  return;
	int menu_state;
	//decoding info
	message.SetDecodeType(iSolveType);
	if(ASCIPHER_TYPE) message.cur_map.AsCipher();
	message.InitKeys();
}
#endif