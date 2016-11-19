//---------------------------------------------------------------------------

#ifndef mainUH
#define mainUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------

#include "tVAM.h"
#include <Dialogs.hpp>
#include <Mask.hpp>

class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *grpbHead;
	TGroupBox *grpbItems;
	TMemo *mLines;
	TLabel *Label1;
	TComboBox *cbInvoiceSings;
	TComboBox *cbInvoiceSings1;
	TLabel *Label2;
	TDateTimePicker *dtHeadTransfer;
	TDateTimePicker *dtItemsTransfer;
	TLabel *Label3;
	TEdit *edtHeadInvNr;
	TLabel *Label4;
	TEdit *edtItemsInvNr;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TDateTimePicker *dtHeadPay;
	TLabel *Label8;
	TDateTimePicker *dtItemsPay;
	TLabel *Label9;
	TEdit *edtItemsSum;
	TLabel *Label10;
	TEdit *edtItemSum;
	TLabel *Label11;
	TEdit *edtEVID;
	TLabel *Label12;
	TEdit *edtVPID;
	TBitBtn *bbtnAddItem;
	TEdit *edtItemsCents;
	TEdit *edtItemCents;
	TBitBtn *bbtnSave;
	TSaveDialog *dlgSave;
	void __fastcall bbtnAddItemClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall bbtnSaveClick(TObject *Sender);


private:	// User declarations
	char thousand_sep; // to be able to restore the locale
	__int64 sum;

	TFormatSettings fs;
	TVAM *vam;
	TObject *headObjects[6];
	TObject *itemObjects[8];

	void CreateFileDate(std::wstring& str);
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif

