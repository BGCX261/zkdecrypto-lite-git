/*Window Functions*/

//init key dialog

//homophone dialog
inline int MatchStringTemplate(std::string sTemp, std::string sWord)
{
	int length=sTemp.length();

	if(length!=sWord.length()) return 0;

	for(int i=0; i<length; i++)
	{
		if(sTemp.at(i)=='*') continue; //wild card
		
		else if(sTemp.at(i)>='0' && sTemp.at(i)<='9') //pattern number
			for(int j=0; j<length; j++) //compare word letter at each position
			{
				if(sTemp.at(j)<'0' || sTemp.at(j)>'9') continue; //not a pattern number
				if(sTemp.at(j)==sTemp.at(i) && sWord.at(j)!=sWord.at(i)) return 0; //same pattern number, different word letter
				
			//  REMOVING THE LINE BELOW ALLOWS FOR BETTER PATTERN MATCHING FOR HOMOPHONICS, perhaps better as an option.
			//	if(sTemp.at(j)!=sTemp.at(i) && sWord.at(j)==sWord.at(i)) return 0; //different pattern number, same word letter
			
			}

		else if(sTemp.at(i)!=sWord.at(i)) return 0; //exact letter	
	}

	return 1;
}
