#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

class C_Citations
{

private:
	std::wstring str_pageBuffer;
	std::wstring romanNumerals = L"ivxlcdm\u2181\u2182\u2187\u2188";
	std::wstring upperRomanNumerals = L"IVXLCDM\u2181\u2182\u2187\u2188";
	uint32_t j{ 0 };
	uint32_t numeral{ 0 };

public:
	wchar_t w_pageBuffer[25];
	void parsePageNumber(bool bIsIncrement);
};

