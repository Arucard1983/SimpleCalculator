#include "ScientificCalculator.h"
#include "CalculatorLibrary.h"

ScientificCalculator::ScientificCalculator( wxWindow* parent )
:
mainCalculator( parent )
{

}

void ScientificCalculator::OnAcos( wxCommandEvent& event )
{
 wxString data = wxT("acos()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnAsin( wxCommandEvent& event )
{
 wxString data = wxT("asin()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnAtan( wxCommandEvent& event )
{
 wxString data = wxT("atan()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnSign( wxCommandEvent& event )
{
 wxTextEntryDialog *dialog = new wxTextEntryDialog(this,wxT("Insert the variable name to be displayed"),wxT("Recall Stored Variable"),wxEmptyString);
 if (dialog->ShowModal() == wxID_OK)
 {
 wxString data = dialog->GetValue() + wxT("=0");
 textResult->WriteText(data);
 }
 delete dialog;
}

void ScientificCalculator::OnLpar( wxCommandEvent& event )
{
 wxString data = wxT("(");
 textResult->WriteText(data);
}

void ScientificCalculator::OnRpar( wxCommandEvent& event )
{
 wxString data = wxT(")");
 textResult->WriteText(data);
}

void ScientificCalculator::OnSqrt( wxCommandEvent& event )
{
 wxString data = wxT("sqrt()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnPower( wxCommandEvent& event )
{
 wxString data = wxT("^");
 textResult->WriteText(data);
}

void ScientificCalculator::OnClear( wxCommandEvent& event )
{
 textResult->Clear();
}

void ScientificCalculator::OnAcosh( wxCommandEvent& event )
{
 wxString data = wxT("acosh()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnAsinh( wxCommandEvent& event )
{
 wxString data = wxT("asinh()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnAtanh( wxCommandEvent& event )
{
 wxString data = wxT("atanh()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnVariable( wxCommandEvent& event )
{
 wxTextEntryDialog *dialog = new wxTextEntryDialog(this,wxT("Insert a variable name."),wxT("Define New Variable"),wxEmptyString);
 if (dialog->ShowModal() == wxID_OK)
 {
 wxString data = dialog->GetValue() + wxT("?=");
 textResult->WriteText(data);
 }
 delete dialog;
}

void ScientificCalculator::OnSeven( wxCommandEvent& event )
{
 wxString data = wxT("7");
 textResult->WriteText(data);
}

void ScientificCalculator::OnEight( wxCommandEvent& event )
{
 wxString data = wxT("8");
 textResult->WriteText(data);
}

void ScientificCalculator::OnNine( wxCommandEvent& event )
{
 wxString data = wxT("9");
 textResult->WriteText(data);
}

void ScientificCalculator::OnPlus( wxCommandEvent& event )
{
 wxString data = wxT("+");
 textResult->WriteText(data);
}

void ScientificCalculator::OnBack( wxCommandEvent& event )
{
 textResult->Remove(textResult->GetLastPosition()-1,textResult->GetLastPosition());
}

void ScientificCalculator::OnCos( wxCommandEvent& event )
{
 wxString data = wxT("cos()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnSin( wxCommandEvent& event )
{
 wxString data = wxT("sin()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnTan( wxCommandEvent& event )
{
 wxString data = wxT("tan()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnConstant( wxCommandEvent& event )
{
 wxTextEntryDialog *dialog = new wxTextEntryDialog(this,wxT("Insert a constant name."),wxT("Define New Constant"),wxEmptyString);
 if (dialog->ShowModal() == wxID_OK)
 {
 wxString data = dialog->GetValue() + wxT("=");
 textResult->WriteText(data);
 }
 delete dialog;
}

void ScientificCalculator::OnFour( wxCommandEvent& event )
{
 wxString data = wxT("4");
 textResult->WriteText(data);
}

void ScientificCalculator::OnFive( wxCommandEvent& event )
{
 wxString data = wxT("5");
 textResult->WriteText(data);
}

void ScientificCalculator::OnSix( wxCommandEvent& event )
{
 wxString data = wxT("6");
 textResult->WriteText(data);
}

void ScientificCalculator::OnMinus( wxCommandEvent& event )
{
 wxString data = wxT("-");
 textResult->WriteText(data);
}

void ScientificCalculator::OnReset( wxCommandEvent& event )
{
 textResult->Clear();
}

void ScientificCalculator::OnCosh( wxCommandEvent& event )
{
 wxString data = wxT("cosh()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnSinh( wxCommandEvent& event )
{
 wxString data = wxT("sinh()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnTanh( wxCommandEvent& event )
{
 wxString data = wxT("tanh()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnComma( wxCommandEvent& event )
{
 wxString data = wxT(",");
 textResult->WriteText(data);
}

void ScientificCalculator::OnOne( wxCommandEvent& event )
{
 wxString data = wxT("1");
 textResult->WriteText(data);
}

void ScientificCalculator::OnTwo( wxCommandEvent& event )
{
 wxString data = wxT("2");
 textResult->WriteText(data);
}

void ScientificCalculator::OnThree( wxCommandEvent& event )
{
 wxString data = wxT("3");
 textResult->WriteText(data);
}

void ScientificCalculator::OnTimes( wxCommandEvent& event )
{
 wxString data = wxT("*");
 textResult->WriteText(data);
}

void ScientificCalculator::OnDisplay( wxCommandEvent& event )
{
 textResult->Clear();
}

void ScientificCalculator::OnExp( wxCommandEvent& event )
{
 wxString data = wxT("exp()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnLog( wxCommandEvent& event )
{
 wxString data = wxT("log()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnLn( wxCommandEvent& event )
{
 wxString data = wxT("ln()");
 textResult->WriteText(data);
}

void ScientificCalculator::OnColon( wxCommandEvent& event )
{
 wxString data = wxT(":");
 textResult->WriteText(data);
}

void ScientificCalculator::OnZero( wxCommandEvent& event )
{
 wxString data = wxT("0");
 textResult->WriteText(data);
}

void ScientificCalculator::OnDecimal( wxCommandEvent& event )
{
 wxString data = wxT(".");
 textResult->WriteText(data);
}

void ScientificCalculator::OnEE( wxCommandEvent& event )
{
 wxString data = wxT("E");
 textResult->WriteText(data);
}

void ScientificCalculator::OnDivide( wxCommandEvent& event )
{
 wxString data = wxT("/");
 textResult->WriteText(data);
}

void ScientificCalculator::OnReturn( wxCommandEvent& event )
{
 AlgebraicFunction *fx = new AlgebraicFunction(textResult->GetValue());
 if(fx->GetErrorString().Len()>0)
 {
  wxMessageDialog *dialog = new wxMessageDialog(this, fx->GetErrorString(), wxT("Evaluation Failure!"), wxOK );
  dialog->ShowModal();
  delete dialog;
 }
 else
 {
  wxMessageDialog *dialog = new wxMessageDialog(this, wxString::Format(wxT("%f"),fx->GetEval()), wxT("Results..."), wxOK );
  dialog->ShowModal();
  delete dialog;
 }
 delete fx;
}
