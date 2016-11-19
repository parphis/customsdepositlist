//---------------------------------------------------------------------------

#ifndef tvamH
#define tvamH

#include <StdCtrls.hpp>
#include <ComCtrls.hpp>
#include <string>
//---------------------------------------------------------------------------

class TVAM {
private:
	const unsigned long MAX_HEAD_SIZE;
	const unsigned long MAX_ITEM_SIZE;
	std::wstring FileName;
	wchar_t *Head;
	wchar_t *Items;
	wchar_t *ItemsTemp;
	std::wstring FileNameFormat;
	wchar_t *HeadFormat;
	wchar_t *ItemFormat;
public:
	TVAM(void) :
		MAX_HEAD_SIZE(1024),
		MAX_ITEM_SIZE(MAX_HEAD_SIZE*5),
		FileName(L""),
		FileNameFormat(L"%02d%02d%02d%02d.txt"),
												// XXSShhnn.txt (customerID [XX]
												// invoiceNr [SS]
												// month day [hhnn])
		HeadFormat(L"%02d%04d%02d%02d%08d%04d%02d%02d%011d%02d                            "),
												// invoiceNr[XX]
												// transferDate[YYYYMMDD] as the date in the file name
												// taxNr [99999999]
												// payDate [YYYYMMDD]
												// sumTransfer [0002459219900] 11 char Ft + 2 char Ft/100
												// reserved space*28
		ItemFormat(L"%02d%04d%02d%02d%08d%04d%02d%02d%011d%02d%s  %s")
												// invoiceNr[XX]
												// transferDate[YYYYMMDD] as the date in the file name
												// taxNr char*8
												// payDate [YYYYMMDD]
												// moneyTransfer [0002459219900] 11 char Ft + 2 char Ft/100
												// EVID char*14
												// reserved space*2
												// VPID char or space*12
	{
		Head = new wchar_t[MAX_HEAD_SIZE];
		Items = new wchar_t[MAX_ITEM_SIZE];
		ItemsTemp = new wchar_t[MAX_ITEM_SIZE];

		memcpy(Head, "\0", MAX_HEAD_SIZE);
		memcpy(Items, "\0", MAX_ITEM_SIZE);
	}
	~TVAM(void){
		delete [] ItemsTemp;
		delete [] Items;
		delete [] Head;
	}

	int Add(TObject **head, TObject **item);
	void DisplayItems(TMemo *m);
};
#endif

