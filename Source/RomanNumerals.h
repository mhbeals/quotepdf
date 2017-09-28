#pragma once
#include <string>
#include <algorithm>

namespace RomanNumerals
{
	// Requires wstring array of roman numerals; used as part of tallyRomanNumearls
	int convertSingleRomanNumeralToNumeral(wchar_t);
	
	// Requires wstring array of numbers; used as part of convertFullNumeralToRomanNumeral
	std::wstring convertSingleNumeralToRomanNumeral(wchar_t, int);
	std::wstring convertSingleNumeralToUpperRomanNumeral(wchar_t, int);
	
	// input a wstring of roman numerals; returns a int numeral
	// int_buffer = RomanNumerals::convertFullRomanNumeralToNumeral(str_buffer);
	int convertFullRomanNumeralToNumeral(std::wstring);

	// input a int number; returns a wstring roman numeral 
	// str_buffer = RomanNumerals::convertFullNumeralToRomanNumeral(stoi(str_buffer));
	std::wstring convertFullNumeralToRomanNumeral(int);
	std::wstring convertFullNumeralToUpperRomanNumeral(int);
};

