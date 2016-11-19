/**
 * mainU.cpp / VAM.exe
 *
 * This application can generate a custom formatted text file.
 * The format specified by the NAV (a Hungarian Government Comitee).
 *
 * @author Istvan Vig
 * @copyright DENSO Manufactruing Hungary Ltd.
 * @since 05/11/2012
 */
/**
 * Version history
 *
 * 06/11/2012
 * 1.0.1.0
 * - Modified cbInvoiceSings content: it holds explanations for the numbers.
 * - Error correction: VAM::Items array size checking in order to avoid
 *   overflow.
 * - Enter constant IDs.
 *
 * 15/11/2012
 * 1.0.2.0
 * - Error correction: both EVID and VPID can contain alphanumeric characters.
 *   They type has been replaced from unsigned long to std::wstring.
 *
 */
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;

void TfrmMain::CreateFileDate(std::wstring& str) {
	wchar_t *datestr = new wchar_t[1024];
	unsigned short year, month, day;
	TDateTime dt = this->dtHeadTransfer->DateTime;

	dt.DecodeDate(&year, &month, &day);

	wsprintf(datestr,
		L"%02d%02d",
		month, day);

	str.append(datestr);

	delete [] datestr;
}
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner), sum(0), thousand_sep(0x00)
{
	vam = new TVAM();

	fs.Create();
	thousand_sep = fs.ThousandSeparator;

	fs.ThousandSeparator = ' ';
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormShow(TObject *Sender)
{
	headObjects[0] = this->cbInvoiceSings;
	headObjects[1] = this->edtHeadInvNr;
	headObjects[2] = this->dtHeadTransfer;
	headObjects[3] = this->dtHeadPay;
	headObjects[4] = this->edtItemsSum;
	headObjects[5] = this->edtItemsCents;

	itemObjects[0] = this->cbInvoiceSings1;
	itemObjects[1] = this->edtItemsInvNr;
	itemObjects[2] = this->dtItemsTransfer;
	itemObjects[3] = this->dtItemsPay;
	itemObjects[4] = this->edtItemSum;
	itemObjects[5] = this->edtItemCents;
	itemObjects[6] = this->edtEVID;
	itemObjects[7] = this->edtVPID;

	this->dtHeadTransfer->Date = TDateTime::CurrentDate();
	this->dtHeadPay->Date = TDateTime::CurrentDate();
	this->dtItemsTransfer->Date = TDateTime::CurrentDate();
	this->dtItemsPay->Date = TDateTime::CurrentDate();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::bbtnAddItemClick(TObject *Sender)
{
	try {
		sum += StrToInt(this->edtItemSum->Text);
		this->edtItemsSum->Text = IntToStr(sum);
	}
	catch (EConvertError& e) {
		MessageBox(this->Handle, L"Csak számot adjon meg!", L"Hiba", 16);
		this->edtItemSum->SetFocus();
		return;
	}

	int res = vam->Add(headObjects, itemObjects);

	if (res==1) {
		MessageBox(this->Handle, L"Nem lehet több tételt hozzáadni!", L"Hiba", 16);
	}
	else if (res==2) {
    	MessageBox(this->Handle, L"Hiányzik egy adat!", L"Hiba", 16);
	}

	vam->DisplayItems(this->mLines);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	fs.ThousandSeparator = thousand_sep;

	delete vam;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::bbtnSaveClick(TObject *Sender)
{
	std::wstring name_template = L"D8";
	wchar_t *endptr;

	name_template.append(
		FormatFloat("00",
					wcstol(this->cbInvoiceSings->Text.w_str(), &endptr, 10)
		).w_str()
		);
	this->CreateFileDate(name_template);
	name_template.append(L".txt");

	dlgSave->FileName = name_template.c_str();

	if (dlgSave->Execute()) {
		mLines->Lines->SaveToFile(dlgSave->FileName);
	}
}
//---------------------------------------------------------------------------
