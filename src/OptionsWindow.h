#pragma once

#include <wx/wx.h>
#include "EnumWrapper.h"
#include <unordered_map>

template<typename enumType>
class OptionsDialog : public wxDialog
{
public:

	OptionsDialog(wxWindow* parent, const wxString& title, EnumWrapper<enumType>* option1, EnumWrapper<enumType>* option2, EnumWrapper<enumType>* option3, EnumWrapper<enumType>* option4)
		: wxDialog(parent, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
	{


		wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
		printf("we even get to the modal");
		/*wxButton* btnOption1 = new wxButton(this, 1, (std::string)(*option1));
		wxButton* btnOption2 = new wxButton(this, 2, (std::string)(*option2));
		wxButton* btnOption3 = new wxButton(this, 3, (std::string)(*option3));
		wxButton* btnOption4 = new wxButton(this, 4, (std::string)(*option4));*/

		wxButton* btnOption1 = new wxButton(this, 1, "hey");
		wxButton* btnOption2 = new wxButton(this, 2, "hey");
		wxButton* btnOption3 = new wxButton(this, 3, "hey");
		wxButton* btnOption4 = new wxButton(this, 4, "hey");

		sizer->Add(btnOption1, 0, wxALL | wxEXPAND, 5);
		sizer->Add(btnOption2, 0, wxALL | wxEXPAND, 5);
		sizer->Add(btnOption3, 0, wxALL | wxEXPAND, 5);
		sizer->Add(btnOption4, 0, wxALL | wxEXPAND, 5);

		SetSizerAndFit(sizer);

		btnOption1->Bind(wxEVT_BUTTON, &OptionsDialog::OnButtonClicked, this);
		btnOption2->Bind(wxEVT_BUTTON, &OptionsDialog::OnButtonClicked, this);
		btnOption3->Bind(wxEVT_BUTTON, &OptionsDialog::OnButtonClicked, this);
		btnOption4->Bind(wxEVT_BUTTON, &OptionsDialog::OnButtonClicked, this);

	}
private:
	void OnButtonClicked(wxCommandEvent& event)
	{
		// End the modal loop and return the button's id
		EndModal(event.GetId());
	}
};

template<typename enumType>
class OptionsWindow : public wxFrame
{
public:

	OptionsWindow(const wxString& title, EnumWrapper<enumType>* option1, EnumWrapper<enumType>* option2, EnumWrapper<enumType>* option3, EnumWrapper<enumType>* option4)
		: wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
	{

		options[1] = option1;
		options[2] = option2;
		options[3] = option3;
		options[4] = option4;


		wxPanel* panel = new wxPanel(this, wxID_ANY);
		wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
		panel->SetSizer(sizer);
	}

	EnumWrapper<enumType>* getOptionsChoice()
	{
		Show(true);
		printf("many many options");
		OptionsDialog<enumType> dialog(this, "Choose an Option", options[1], options[2], options[3], options[4]);
		int retCode = dialog.ShowModal();
		Show(false);
		return options[retCode];
		
	}
private:

	std::unordered_map<int, EnumWrapper<enumType>*> options;
};

	

