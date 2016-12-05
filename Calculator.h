///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 14 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/textdlg.h>
#include <wx/msgdlg.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class mainCalculator
///////////////////////////////////////////////////////////////////////////////
class mainCalculator : public wxFrame
{
	private:

	protected:
		wxTextCtrl* textResult;
		wxStaticLine* lineButtons;
		wxButton* buttonACOS;
		wxButton* buttonASIN;
		wxButton* buttonATAN;
		wxButton* buttonSIGN;
		wxButton* buttonLPAR;
		wxButton* buttonRPAR;
		wxButton* buttonSQRT;
		wxButton* buttonPOWER;
		wxButton* buttonClear;
		wxButton* buttonACOSH;
		wxButton* buttonASINH;
		wxButton* buttonATANH;
		wxButton* buttonVariable;
		wxButton* buttonSEVEN;
		wxButton* buttonEIGHT;
		wxButton* buttonNINE;
		wxButton* buttonPLUS;
		wxButton* buttonBack;
		wxButton* buttonCOS;
		wxButton* buttonSIN;
		wxButton* buttonTAN;
		wxButton* buttonConstant;
		wxButton* buttonFOUR;
		wxButton* buttonFIVE;
		wxButton* buttonSIX;
		wxButton* buttonMINUS;
		wxButton* buttonReset;
		wxButton* buttonCOSH;
		wxButton* buttonSINH;
		wxButton* buttonTANH;
		wxButton* buttonComma;
		wxButton* buttonONE;
		wxButton* buttonTWO;
		wxButton* buttonTHREE;
		wxButton* buttonTIMES;
		wxButton* buttonDISP;
		wxButton* buttonEXP;
		wxButton* buttonLOG;
		wxButton* buttonLN;
		wxButton* buttonColon;
		wxButton* buttonZero;
		wxButton* buttonDecimal;
		wxButton* buttonEE;
		wxButton* buttonDIVIDE;
		wxButton* buttonReturn;

		// Virtual event handlers, overide them in your derived class
		virtual void OnAcos( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAsin( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAtan( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSign( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLpar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRpar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSqrt( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPower( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClear( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAcosh( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAsinh( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAtanh( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVariable( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSeven( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEight( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNine( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBack( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCos( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSin( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTan( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnConstant( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFour( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFive( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSix( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMinus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReset( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCosh( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSinh( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTanh( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnComma( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOne( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTwo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnThree( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimes( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDisplay( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnColon( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnZero( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDecimal( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEE( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDivide( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReturn( wxCommandEvent& event ) { event.Skip(); }


	public:

		mainCalculator( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Scientific Calculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~mainCalculator();

};

#endif //__CALCULATOR_H__
