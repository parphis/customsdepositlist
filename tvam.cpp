/**
 * tVAM.cpp / TVAM class
 *
 * Spceial class to store the specific lines determined by the NAV.
 *
 * @author Istvan Vig
 * @copyright DENSO Manufacturing Hungary Ltd.
 * @since 05/11/2012
 */
//---------------------------------------------------------------------------


#pragma hdrstop

#include "tvam.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

/**
 * Add new strings for the head and items strings.
 * The added strings are formatted according to the HeadFormat and
 * ItemFormat strings.
 *
 * @param **head TObject
 * @param **item TObject
 * @return int 0: no error; 1: no more memory to hold the items; 2: something
 *   data is missing from the UI;
 */
int TVAM::Add(TObject **head, TObject **item) {
	wchar_t *endptr;
	long invoice_signs, invoice_nr, sum, cents;
	unsigned short transfer_year, transfer_month, transfer_day, pay_year,
		pay_month, pay_day;
	unsigned int invoice_signs_i, invoice_nr_i, sum_i, cents_i;
	unsigned short transfer_year_i, transfer_month_i, transfer_day_i,
		pay_year_i, pay_month_i, pay_day_i;
	TDateTime transfer, pay;

	if ( (reinterpret_cast<TComboBox*>(head[0])->Text=="") ||
		 (reinterpret_cast<TComboBox*>(head[1])->Text=="") ||
		 (reinterpret_cast<TComboBox*>(head[2])->Text=="") ||
		 (reinterpret_cast<TComboBox*>(head[3])->Text=="") ||
		 (reinterpret_cast<TComboBox*>(head[4])->Text=="") ||
		 (reinterpret_cast<TComboBox*>(head[5])->Text=="") ||
		 (reinterpret_cast<TComboBox*>(item[0])->Text=="") ||
		 (reinterpret_cast<TComboBox*>(item[1])->Text=="") ||
		 (reinterpret_cast<TComboBox*>(item[2])->Text=="") ||
		 (reinterpret_cast<TComboBox*>(item[3])->Text=="") ||
		 (reinterpret_cast<TComboBox*>(item[4])->Text=="") ||
		 (reinterpret_cast<TComboBox*>(item[5])->Text=="")
	)
	{
		return 2;
	}

	std::wstring i(this->Items);

	// collect the head strings
	invoice_signs = wcstol((reinterpret_cast<TComboBox*>(head[0])->Text.w_str()),
		&endptr, 10);
	invoice_nr = wcstol((reinterpret_cast<TEdit*>(head[1])->Text.w_str()),
		&endptr, 10);
	sum = wcstol((reinterpret_cast<TEdit*>(head[4])->Text.w_str()), &endptr, 10);
	cents = wcstol((reinterpret_cast<TEdit*>(head[5])->Text.w_str()), &endptr, 10);

	transfer = reinterpret_cast<TDateTimePicker*>(head[2])->DateTime;
	pay = reinterpret_cast<TDateTimePicker*>(head[3])->DateTime;

	transfer.DecodeDate(&transfer_year, &transfer_month, &transfer_day);
	pay.DecodeDate(&pay_year, &pay_month, &pay_day);

	wsprintf(this->Head,
		this->HeadFormat,
		invoice_signs, transfer_year, transfer_month, transfer_day,
		invoice_nr,
		pay_year, pay_month, pay_day, sum, cents);

	if (!i.empty()) {
		wcscat(this->Items, L"\n");
	}

	// collect the item strings
	invoice_signs_i = wcstol((reinterpret_cast<TComboBox*>(item[0])->Text.w_str()),
		&endptr, 10);
	invoice_nr_i = wcstol((reinterpret_cast<TEdit*>(item[1])->Text.w_str()),
		&endptr, 10);
	sum_i = wcstol((reinterpret_cast<TEdit*>(item[4])->Text.w_str()), &endptr, 10);
	cents_i = wcstol((reinterpret_cast<TEdit*>(item[5])->Text.w_str()), &endptr, 10);

	std::wstring evid(reinterpret_cast<TEdit*>(item[6])->Text.w_str());
	std::wstring vpid(reinterpret_cast<TEdit*>(item[7])->Text.w_str());

	transfer = reinterpret_cast<TDateTimePicker*>(item[2])->DateTime;
	pay = reinterpret_cast<TDateTimePicker*>(item[3])->DateTime;

	transfer.DecodeDate(&transfer_year_i, &transfer_month_i, &transfer_day_i);
	pay.DecodeDate(&pay_year_i, &pay_month_i, &pay_day_i);

	memcpy(ItemsTemp, "\0", MAX_ITEM_SIZE);

	wsprintf(ItemsTemp,
		this->ItemFormat,
		invoice_signs_i, transfer_year_i, transfer_month_i, transfer_day_i,
		invoice_nr_i,
		pay_year_i, pay_month_i, pay_day_i, sum_i, cents_i, evid.c_str(), vpid.c_str());

	if (wcslen(this->Items)+wcslen(ItemsTemp) < MAX_ITEM_SIZE) {
		wcsncat(this->Items, ItemsTemp, wcslen(ItemsTemp));
	}
	else {
		return 1;
	}

	return 0;
}

/**
 * Displays the head and the item in the given TMemo component.
 *
 * @param m TMemo
 */
void TVAM::DisplayItems(TMemo *m) {
	m->Lines->Clear();
	m->Lines->Add(this->Head);
	m->Lines->Add(this->Items);
}
