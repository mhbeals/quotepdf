#include "stdafx.h"
#include "RomanNumerals.h"

int RomanNumerals::convertSingleRomanNumeralToNumeral(wchar_t character)
{
	if (character == L'i' || character == L'I') { return 1; }
	else if (character == L'v' || character == L'V') { return 5; }
	else if (character == L'x' || character == L'X') { return 10; }
	else if (character == L'l' || character == L'L') { return 50; }
	else if (character == L'c' || character == L'C') { return 100; }
	else if (character == L'd' || character == L'D') { return 500; }
	else if (character == L'm' || character == L'M') { return 1000; }
	else if (character == L'\u2181') { return 5000; }
	else if (character == L'\u2182') { return 10000; }
	else if (character == L'\u2187') { return 50000; }
	else if (character == L'\u2188') { return 100000; }

	else { return 0; }
}

std::wstring RomanNumerals::convertSingleNumeralToRomanNumeral(wchar_t tally, int position)
{
	if (position == 0)
	{
		if (tally == '1') { return L"i" + std::wstring(1, NULL);}
		else if (tally == '2') { return L"ii" + std::wstring(1, NULL);}
		else if (tally == '3') { return L"iii" + std::wstring(1, NULL);}
		else if (tally == '4') { return L"iv" + std::wstring(1, NULL);}
		else if (tally == '5') { return L"v" + std::wstring(1, NULL);}
		else if (tally == '6') { return L"vi" + std::wstring(1, NULL);}
		else if (tally == '7') { return L"vii" + std::wstring(1, NULL);}
		else if (tally == '8') { return L"viii" + std::wstring(1, NULL);}
		else if (tally == '9') { return L"ix" + std::wstring(1, NULL);}
		else { return L""; }
	}
	else if (position == 1)
	{
		if (tally == '1') { return L"x"; }
		else if (tally == '2') { return L"xx"; }
		else if (tally == '3') { return L"xxx"; }
		else if (tally == '4') { return L"xl"; }
		else if (tally == '5') { return L"l"; }
		else if (tally == '6') { return L"lx"; }
		else if (tally == '7') { return L"lxx"; }
		else if (tally == '8') { return L"lxxx"; }
		else if (tally == '9') { return L"xc"; }
		else { return L""; }
	}
	else if (position == 2)
	{
		if (tally == '1') { return L"c"; }
		else if (tally == '2') { return L"cc"; }
		else if (tally == '3') { return L"ccc"; }
		else if (tally == '4') { return L"cd"; }
		else if (tally == '5') { return L"d"; }
		else if (tally == '6') { return L"dc"; }
		else if (tally == '7') { return L"dcc"; }
		else if (tally == '8') { return L"dccc"; }
		else if (tally == '9') { return L"cm"; }
		else { return L""; }
	}
	else if (position == 3)
	{
		if (tally == '1') { return L"m"; }
		else if (tally == '2') { return L"mm"; }
		else if (tally == '3') { return L"mmm"; }
		else if (tally == '4') { return L"m\u2181"; }
		else if (tally == '5') { return L"\u2181"; }
		else if (tally == '6') { return L"\u2181m"; }
		else if (tally == '7') { return L"\u2181mm"; }
		else if (tally == '8') { return L"\u2181mmm"; }
		else if (tally == '9') { return L"m\u2182"; }
		else { return L""; }
	}
	else if (position == 4)
	{
		if (tally == '1') { return L"\u2182"; }
		else if (tally == '2') { return L"\u2182\u2182"; }
		else if (tally == '3') { return L"\u2182\u2182\u2182"; }
		else if (tally == '4') { return L"\u2182\u21817"; }
		else if (tally == '5') { return L"\u2187"; }
		else if (tally == '6') { return L"\u2187\u2182"; }
		else if (tally == '7') { return L"\u2187\u2182\u2182"; }
		else if (tally == '8') { return L"\u2187\u2182\u2182\u2182"; }
		else if (tally == '9') { return L"\u2182\u2188"; }
		else { return L""; }
	}
}

std::wstring RomanNumerals::convertSingleNumeralToUpperRomanNumeral(wchar_t tally, int position)
{
	if (position == 0)
	{
		if (tally == '1') { return L"I" + std::wstring(1, NULL); }
		else if (tally == '2') {return L"II" + std::wstring(1, NULL);}
		else if (tally == '3') {return L"III" + std::wstring(1, NULL);}
		else if (tally == '4') {return L"IV" + std::wstring(1, NULL);}
		else if (tally == '5') {return L"V" + std::wstring(1, NULL);}
		else if (tally == '6') {return L"VI" + std::wstring(1, NULL);}
		else if (tally == '7') {return L"VII" + std::wstring(1, NULL);}
		else if (tally == '8') {return L"VIII" + std::wstring(1, NULL);}
		else if (tally == '9') {return L"IX" + std::wstring(1, NULL);}
		else { return L""; }
	}
	else if (position == 1)
	{
		if (tally == '1') { return L"X"; }
		else if (tally == '2') { return L"XX"; }
		else if (tally == '3') { return L"XXX"; }
		else if (tally == '4') { return L"XL"; }
		else if (tally == '5') { return L"L"; }
		else if (tally == '6') { return L"LX"; }
		else if (tally == '7') { return L"LXX"; }
		else if (tally == '8') { return L"LXXX"; }
		else if (tally == '9') { return L"XC"; }
		else { return L""; }
	}
	else if (position == 2)
	{
		if (tally == '1') { return L"C"; }
		else if (tally == '2') { return L"CC"; }
		else if (tally == '3') { return L"CCC"; }
		else if (tally == '4') { return L"CD"; }
		else if (tally == '5') { return L"D"; }
		else if (tally == '6') { return L"DC"; }
		else if (tally == '7') { return L"DCC"; }
		else if (tally == '8') { return L"DCCC"; }
		else if (tally == '9') { return L"CM"; }
		else { return L""; }
	}
	else if (position == 3)
	{
		if (tally == '1') { return L"M"; }
		else if (tally == '2') { return L"MM"; }
		else if (tally == '3') { return L"MMM"; }
		else if (tally == '4') { return L"M\u2181"; }
		else if (tally == '5') { return L"\u2181"; }
		else if (tally == '6') { return L"\u2181M"; }
		else if (tally == '7') { return L"\u2181MM"; }
		else if (tally == '8') { return L"\u2181MMM"; }
		else if (tally == '9') { return L"M\u2182"; }
		else { return L""; }
	}
	else if (position == 4)
	{
		if (tally == '1') { return L"\u2182"; }
		else if (tally == '2') { return L"\u2182\u2182"; }
		else if (tally == '3') { return L"\u2182\u2182\u2182"; }
		else if (tally == '4') { return L"\u2182\u21817"; }
		else if (tally == '5') { return L"\u2187"; }
		else if (tally == '6') { return L"\u2187\u2182"; }
		else if (tally == '7') { return L"\u2187\u2182\u2182"; }
		else if (tally == '8') { return L"\u2187\u2182\u2182\u2182"; }
		else if (tally == '9') { return L"\u2182\u2188"; }
		else { return L""; }
	}
}

int RomanNumerals::convertFullRomanNumeralToNumeral(std::wstring str_buffer)
{
	int int_buffer[25]{ 0 };
	int r{ 0 };
	int tally{ 0 };

	for_each(str_buffer.begin(), str_buffer.end(), [&](wchar_t x) {int_buffer[r] = convertSingleRomanNumeralToNumeral(x); r++; });

	for (size_t m = 0; m < str_buffer.size();)
	{
		if (int_buffer[m] != NULL) // if 0 is not 0
		{
			if (int_buffer[m] >= int_buffer[m + 1])
			{
				if (int_buffer[m + 1] >= int_buffer[m + 2])
				{
					if (int_buffer[m + 2] >= int_buffer[m + 3]) // if 0-3 are in descending order
					{
						if (int_buffer[m + 3] >= int_buffer[m + 4])
						{
							tally += int_buffer[m]
								+ int_buffer[m + 1]
								+ int_buffer[m + 2]
								+ int_buffer[m + 3];
							m = m + 4;
							continue;
						}
						else
						{
							tally += int_buffer[m]
								+ int_buffer[m + 1]
								+ int_buffer[m + 2];
							m = m + 3;
							continue;
						}
					}
					else // if only 0-2 are in descending order
					{
						tally += int_buffer[m]
							+ int_buffer[m + 1];
						m = m + 2;
						continue;
					}
				}
				else // if only 0-1 are in descending order
				{
					tally += int_buffer[m];
					m = m + 1;
					continue;
				}
			}
			else // if 0 is smaller than 1
			{
				tally += int_buffer[m + 1]
					- int_buffer[m];
				m = m + 2;
				continue;
			}
		}
		break;
	}
	return tally;
}

 std::wstring RomanNumerals::convertFullNumeralToRomanNumeral(int tally)
{
	std::wstring str_tally = std::to_wstring(tally);
	int tallySize = str_tally.size() - 1;
	std::wstring str_returnBuffer{ L"" };

	for (int j = 0; j < str_tally.size(); j++)
	{
		str_returnBuffer += RomanNumerals::convertSingleNumeralToRomanNumeral(str_tally[j], tallySize - j);
	}

	return str_returnBuffer + std::wstring(1, NULL);
}

 std::wstring RomanNumerals::convertFullNumeralToUpperRomanNumeral(int tally)
 {
	 std::wstring str_tally = std::to_wstring(tally);
	 int tallySize = str_tally.size() - 1;
	 std::wstring str_returnBuffer{ L"" };

	 for (int j = 0; j < str_tally.size(); j++)
	 {
		 str_returnBuffer += RomanNumerals::convertSingleNumeralToUpperRomanNumeral(str_tally[j], tallySize - j);
	 }

	 return str_returnBuffer + std::wstring(1, NULL);
 }