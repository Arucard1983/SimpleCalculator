/***************************************************************
 * Name:      CalculatorApp.cpp
 * Purpose:   Scientific Calculator
 * Author:    
 * Created:   2015-12-01
 * Copyright: 
 * License:
 **************************************************************/


#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "CalculatorApp.h"
#include "ScientificCalculator.h"

IMPLEMENT_APP(CalculatorApp);

bool CalculatorApp::OnInit()
{

    ScientificCalculator* frame = new ScientificCalculator(0L);

    frame->Show();

    return true;
}
