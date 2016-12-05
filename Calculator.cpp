///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 14 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

///////////////////////////////////////////////////////////////////////////

mainCalculator::mainCalculator( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* sizerCalculator;
	sizerCalculator = new wxBoxSizer( wxVERTICAL );

	textResult = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sizerCalculator->Add( textResult, 0, wxALL|wxEXPAND, 5 );

	lineButtons = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sizerCalculator->Add( lineButtons, 0, wxEXPAND | wxALL, 5 );

	wxGridSizer* sizerButtons;
	sizerButtons = new wxGridSizer( 5, 9, 0, 0 );

	buttonACOS = new wxButton( this, wxID_ANY, wxT("acos"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonACOS, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonASIN = new wxButton( this, wxID_ANY, wxT("asin"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonASIN, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonATAN = new wxButton( this, wxID_ANY, wxT("atan"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonATAN, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonSIGN = new wxButton( this, wxID_ANY, wxT("DspVar="), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonSIGN, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonLPAR = new wxButton( this, wxID_ANY, wxT("("), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonLPAR, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonRPAR = new wxButton( this, wxID_ANY, wxT(")"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonRPAR, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonSQRT = new wxButton( this, wxID_ANY, wxT("sqrt"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonSQRT, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonPOWER = new wxButton( this, wxID_ANY, wxT("^"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonPOWER, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonClear = new wxButton( this, wxID_ANY, wxT("ClrScr"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonClear, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonACOSH = new wxButton( this, wxID_ANY, wxT("acosh"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonACOSH, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonASINH = new wxButton( this, wxID_ANY, wxT("asinh"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonASINH, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonATANH = new wxButton( this, wxID_ANY, wxT("atanh"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonATANH, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonVariable = new wxButton( this, wxID_ANY, wxT("var="), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonVariable, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonSEVEN = new wxButton( this, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonSEVEN, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonEIGHT = new wxButton( this, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonEIGHT, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonNINE = new wxButton( this, wxID_ANY, wxT("9"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonNINE, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonPLUS = new wxButton( this, wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonPLUS, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonBack = new wxButton( this, wxID_ANY, wxT("BckSpc"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonBack, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonCOS = new wxButton( this, wxID_ANY, wxT("cos"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonCOS, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonSIN = new wxButton( this, wxID_ANY, wxT("sin"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonSIN, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonTAN = new wxButton( this, wxID_ANY, wxT("tan"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonTAN, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonConstant = new wxButton( this, wxID_ANY, wxT("const="), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonConstant, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonFOUR = new wxButton( this, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonFOUR, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonFIVE = new wxButton( this, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonFIVE, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonSIX = new wxButton( this, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonSIX, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonMINUS = new wxButton( this, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonMINUS, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonReset = new wxButton( this, wxID_ANY, wxT("RstMem"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonReset, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonCOSH = new wxButton( this, wxID_ANY, wxT("cosh"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonCOSH, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonSINH = new wxButton( this, wxID_ANY, wxT("sinh"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonSINH, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonTANH = new wxButton( this, wxID_ANY, wxT("tanh"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonTANH, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonComma = new wxButton( this, wxID_ANY, wxT(","), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonComma, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonONE = new wxButton( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonONE, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonTWO = new wxButton( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonTWO, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonTHREE = new wxButton( this, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonTHREE, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonTIMES = new wxButton( this, wxID_ANY, wxT("*"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonTIMES, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonDISP = new wxButton( this, wxID_ANY, wxT("DspVal"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonDISP, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonEXP = new wxButton( this, wxID_ANY, wxT("exp"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonEXP, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonLOG = new wxButton( this, wxID_ANY, wxT("log"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonLOG, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonLN = new wxButton( this, wxID_ANY, wxT("ln"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonLN, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonColon = new wxButton( this, wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonColon, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonZero = new wxButton( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonZero, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonDecimal = new wxButton( this, wxID_ANY, wxT("."), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonDecimal, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonEE = new wxButton( this, wxID_ANY, wxT("EE"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonEE, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonDIVIDE = new wxButton( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonDIVIDE, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	buttonReturn = new wxButton( this, wxID_ANY, wxT("Return"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonReturn, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	sizerCalculator->Add( sizerButtons, 1, wxEXPAND, 5 );


	this->SetSizer( sizerCalculator );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	buttonACOS->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAcos ), NULL, this );
	buttonASIN->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAsin ), NULL, this );
	buttonATAN->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAtan ), NULL, this );
	buttonSIGN->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSign ), NULL, this );
	buttonLPAR->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnLpar ), NULL, this );
	buttonRPAR->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnRpar ), NULL, this );
	buttonSQRT->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSqrt ), NULL, this );
	buttonPOWER->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnPower ), NULL, this );
	buttonClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnClear ), NULL, this );
	buttonACOSH->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAcosh ), NULL, this );
	buttonASINH->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAsinh ), NULL, this );
	buttonATANH->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAtanh ), NULL, this );
	buttonVariable->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnVariable ), NULL, this );
	buttonSEVEN->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSeven ), NULL, this );
	buttonEIGHT->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnEight ), NULL, this );
	buttonNINE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnNine ), NULL, this );
	buttonPLUS->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnPlus ), NULL, this );
	buttonBack->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnBack ), NULL, this );
	buttonCOS->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnCos ), NULL, this );
	buttonSIN->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSin ), NULL, this );
	buttonTAN->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnTan ), NULL, this );
	buttonConstant->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnConstant ), NULL, this );
	buttonFOUR->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnFour ), NULL, this );
	buttonFIVE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnFive ), NULL, this );
	buttonSIX->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSix ), NULL, this );
	buttonMINUS->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnMinus ), NULL, this );
	buttonReset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnReset ), NULL, this );
	buttonCOSH->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnCosh ), NULL, this );
	buttonSINH->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSinh ), NULL, this );
	buttonTANH->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnTanh ), NULL, this );
	buttonComma->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnComma ), NULL, this );
	buttonONE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnOne ), NULL, this );
	buttonTWO->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnTwo ), NULL, this );
	buttonTHREE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnThree ), NULL, this );
	buttonTIMES->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnTimes ), NULL, this );
	buttonDISP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnDisplay ), NULL, this );
	buttonEXP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnExp ), NULL, this );
	buttonLOG->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnLog ), NULL, this );
	buttonLN->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnLn ), NULL, this );
	buttonColon->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnColon ), NULL, this );
	buttonZero->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnZero ), NULL, this );
	buttonDecimal->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnDecimal ), NULL, this );
	buttonEE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnEE ), NULL, this );
	buttonDIVIDE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnDivide ), NULL, this );
	buttonReturn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnReturn ), NULL, this );
}

mainCalculator::~mainCalculator()
{
	// Disconnect Events
	buttonACOS->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAcos ), NULL, this );
	buttonASIN->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAsin ), NULL, this );
	buttonATAN->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAtan ), NULL, this );
	buttonSIGN->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSign ), NULL, this );
	buttonLPAR->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnLpar ), NULL, this );
	buttonRPAR->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnRpar ), NULL, this );
	buttonSQRT->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSqrt ), NULL, this );
	buttonPOWER->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnPower ), NULL, this );
	buttonClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnClear ), NULL, this );
	buttonACOSH->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAcosh ), NULL, this );
	buttonASINH->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAsinh ), NULL, this );
	buttonATANH->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnAtanh ), NULL, this );
	buttonVariable->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnVariable ), NULL, this );
	buttonSEVEN->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSeven ), NULL, this );
	buttonEIGHT->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnEight ), NULL, this );
	buttonNINE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnNine ), NULL, this );
	buttonPLUS->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnPlus ), NULL, this );
	buttonBack->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnBack ), NULL, this );
	buttonCOS->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnCos ), NULL, this );
	buttonSIN->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSin ), NULL, this );
	buttonTAN->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnTan ), NULL, this );
	buttonConstant->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnConstant ), NULL, this );
	buttonFOUR->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnFour ), NULL, this );
	buttonFIVE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnFive ), NULL, this );
	buttonSIX->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSix ), NULL, this );
	buttonMINUS->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnMinus ), NULL, this );
	buttonReset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnReset ), NULL, this );
	buttonCOSH->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnCosh ), NULL, this );
	buttonSINH->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnSinh ), NULL, this );
	buttonTANH->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnTanh ), NULL, this );
	buttonComma->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnComma ), NULL, this );
	buttonONE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnOne ), NULL, this );
	buttonTWO->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnTwo ), NULL, this );
	buttonTHREE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnThree ), NULL, this );
	buttonTIMES->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnTimes ), NULL, this );
	buttonDISP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnDisplay ), NULL, this );
	buttonEXP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnExp ), NULL, this );
	buttonLOG->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnLog ), NULL, this );
	buttonLN->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnLn ), NULL, this );
	buttonColon->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnColon ), NULL, this );
	buttonZero->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnZero ), NULL, this );
	buttonDecimal->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnDecimal ), NULL, this );
	buttonEE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnEE ), NULL, this );
	buttonDIVIDE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnDivide ), NULL, this );
	buttonReturn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainCalculator::OnReturn ), NULL, this );

}
