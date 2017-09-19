#pragma once

#include <string>
#include <regex>

class C_PDFQuotation
{

private:
	std::wstring str_Quotation;
	std::wstring str_Citation;
	wchar_t w_QuotationBuffer[10240];
	wchar_t w_CitationBuffer[300];

public:
	C_PDFQuotation();
	~C_PDFQuotation();
	void CreateQuotationCitation();
	void RemoveLineBreaks();
	void RemoveCitations();
	void RemoveFootnotes();
};
