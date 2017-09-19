#include "stdafx.h"
#include "C_PDFQuotation.h"

extern HWND hInput;
extern HWND hOutput;
extern HWND hAuthor;
extern HWND hTitle;
extern HWND hYear;
extern HWND hPage;

C_PDFQuotation::C_PDFQuotation()
{
}

C_PDFQuotation::~C_PDFQuotation()
{
}

void C_PDFQuotation::CreateQuotationCitation() // Assembles citation to quotation from meta-data fields
{
	GetWindowTextW(hAuthor, w_CitationBuffer, 300);
	str_Citation = w_CitationBuffer;
	GetWindowTextW(hTitle, w_CitationBuffer, 300);
	str_Citation = L"\" [" + str_Citation + L", " + w_CitationBuffer + L", ";
	GetWindowTextW(hYear, w_CitationBuffer, 300);
	str_Citation = str_Citation + w_CitationBuffer + L", ";
	GetWindowTextW(hPage, w_CitationBuffer, 300);
	str_Citation = str_Citation + w_CitationBuffer + L"]";
}

void C_PDFQuotation::RemoveLineBreaks() // Removes carriage returns or line breaks
{
	// Removes carriage returns and simple line breaks
	std::wregex r_lb(L"[\r\n]"); 

	GetWindowTextW(hInput, w_QuotationBuffer, 10240);
	str_Quotation = std::regex_replace(w_QuotationBuffer, r_lb, L" ");	

	CreateQuotationCitation();

	str_Quotation = L"\"" + str_Quotation + str_Citation + std::wstring(1, NULL);

	std::copy(str_Quotation.begin(), str_Quotation.end(), w_QuotationBuffer);
	SetWindowTextW(hOutput, w_QuotationBuffer);
}

void  C_PDFQuotation::RemoveCitations() // Removes in-text citations
{
	// (Name[ or : or ,]Year[ or : or ,][p. or pp.][23-3 or iv-vi]) 
	// Must include (Year) or (p. 232 or pp. 232-32) but everything else is optional
	std::wregex r_itc(L"(\\s*\\([\\w-'\\.\\s]*[\\s:,]*\\d{4}[,:\\s]*(p\\.\\s+|pp\\.\\s+)*[\\d-\u2013\u2014\\w]*\\)|\\s*\\((p\\.\\s+|pp\\.\\s+)*[\\d-\u2013\u2014]+\\))");
	
	GetWindowTextW(hOutput, w_QuotationBuffer, 10240);
	str_Quotation = std::regex_replace(w_QuotationBuffer + std::wstring(1, NULL), r_itc, L"");

	std::copy(str_Quotation.begin(), str_Quotation.end(), w_QuotationBuffer);
	SetWindowTextW(hOutput, w_QuotationBuffer);
}

void  C_PDFQuotation::RemoveFootnotes() // Removes footnote numerals
{
	//.123
	// Doesn't remove endnotes as searching for .iv would cause more harm than good
	std::wregex r_fn(L"\\.\\d+"); 

	GetWindowTextW(hOutput, w_QuotationBuffer, 10240);
	str_Quotation = std::regex_replace(w_QuotationBuffer + std::wstring(1, NULL), r_fn, L".");

	std::copy(str_Quotation.begin(), str_Quotation.end(), w_QuotationBuffer);
	SetWindowTextW(hOutput, w_QuotationBuffer);
}