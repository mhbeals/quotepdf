#include "stdafx.h"
#include "C_Citations.h"
#include "RomanNumerals.h"

void C_Citations::parsePageNumber(bool bIsIncrement)
{
	/// if it is a numeral
	if (isdigit(w_pageBuffer[0])) 
	{
		numeral = std::stoi(w_pageBuffer);

		bIsIncrement ? numeral++ : numeral--;

		str_pageBuffer = std::to_wstring(numeral) + std::wstring(1, NULL);
		copy(str_pageBuffer.begin(), str_pageBuffer.end(), w_pageBuffer);
	}

	/// if it is a roman numeral
	else if (romanNumerals.find(w_pageBuffer[0]) != std::wstring::npos 
		     || 
		     upperRomanNumerals.find(w_pageBuffer[0]) != std::wstring::npos) 
	{
		numeral = RomanNumerals::convertFullRomanNumeralToNumeral(w_pageBuffer + std::wstring(1, NULL));

		bIsIncrement ? numeral++ : numeral--;

		if (romanNumerals.find(w_pageBuffer[0]) != std::wstring::npos)
		{
			str_pageBuffer = RomanNumerals::convertFullNumeralToRomanNumeral(numeral);
		}
		else
		{
			str_pageBuffer = RomanNumerals::convertFullNumeralToUpperRomanNumeral(numeral);
		}
		
		copy(str_pageBuffer.begin(), str_pageBuffer.end(), w_pageBuffer);

	}

	else // if it isn't a valid page number 
	{
	}

}