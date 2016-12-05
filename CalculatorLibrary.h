/***************************************************************
 * Name:      CalculatorLibrary.h
 * Purpose:   Algebraic and Text parser library prototypes
 * Author:   
 * Created:   2015-12-01
 * Copyright: 
 * License:
 **************************************************************/

#ifndef CALCULATORLIBRARY_H_INCLUDED
#define CALCULATORLIBRARY_H_INCLUDED
#include "Calculator.h"
#include <cmath>

class AlgebraicVariable;
class Token;
WX_DECLARE_OBJARRAY( AlgebraicVariable, AlgebraicVariableArray);
WX_DECLARE_OBJARRAY( Token, TokenArray);

/***************************************************************
 * Define a dual variable/content in a single object, to handle
 * numerical variables
 * An aditional boolean flag enables to set a variable(true),
 * or a fixed constant (false)
 **************************************************************/
class AlgebraicVariable
{
 private:
 wxString VariableName;
 double VariableValue;
 bool VariableFlag;
 bool VariableLock;
 public:
 AlgebraicVariable(wxString name, long double value){ VariableName=name; VariableValue=value; VariableFlag=true;};
 AlgebraicVariable(wxString name, long double value, bool flag){ VariableName=name; VariableValue=value; VariableFlag=flag;};
 bool IsVariable(){return VariableFlag;};
 bool IsConstant(){return !(VariableFlag);};
 wxString GetName(){return VariableName;};
 double GetValue(){return VariableValue;};
 double SetValue(double newvalue){ VariableValue = newvalue; return VariableValue;};
};

class AlgebraicVariableVector : public AlgebraicVariableArray
{
private:
 int FindVariableAdress(wxString varname);
 public:
 AlgebraicVariableVector(){};
 bool Find(wxString name);
 double FindGet(wxString name);
 bool FindReplace(wxString name, long double newvalue);
 bool NewVariable(wxString name, long double value){AlgebraicVariable temp(name,value,true); this->Add(temp);};
 bool NewConstant(wxString name, long double value){AlgebraicVariable temp(name,value,false); this->Add(temp);};
};

/***************************************************************
 * Manages the tokens generated during tokenization.
 * Some basic syntax and control rules are also implemented
 * The associativity are defined as left=true, and right=false...
 * Since the default operator associativity are left.
 **************************************************************/
class Token
{
 private:
 wxString TokenElement;
 int Priority;
 bool Associativity;
 bool Number;
 bool Variable;
 bool Function;
 bool Operator;
 bool ReservedWord;
 public:
 Token(wxString element){ TokenElement=element; };
 wxString GetValue(){ return TokenElement; };
 bool SetAllFlags(int p, bool a, bool n, bool v, bool f, bool o){ Priority=p; Associativity=a; Number=n; Variable=v; Function=f; Operator=o;};
 int  GetPriority(){ return Priority; };
 bool GetAssociativity(){ return Associativity; };
 bool IsNumber(){ return Number; };
 bool IsVariable(){ return Variable; };
 bool IsFunction(){ return Function; };
 bool IsOperator(){ return Operator; };
 bool CheckIsValidNumber();
 bool CheckIsValidVariable();
 bool CheckIsValidSymbol();
};

class TokenVector : public TokenArray
{
 private:
 bool ClassifyAndCheck();
 bool CheckIsValidNumber(int position);
 bool CheckIsValidVariable(int position);
 bool CheckIsValidSymbol(int position);
 public:
 TokenVector(){};
 bool NewToken(wxString t){ this->Add(Token(t)); return ClassifyAndCheck(); };
};




/***************************************************************
 * Handles the evaluation of an algebraic function
 **************************************************************/
class AlgebraicFunction
{
 private:
 TokenVector InternalFunctionTokens;
 TokenVector RPNTokenStack;
 AlgebraicVariableVector InternalFunctionVariables;
 wxString InternalFunctionString;
 wxString ErrorCode;
 double FunctionValue;
 bool AlgebraicParser();
 bool AlgebraicCompiler();
 bool AlgebraicCalculator();
 long double EvaluateFunction(Token f, long double arg);
 long double EvaluateOperator(Token o, long double arg1, long double arg2);
 public:
 AlgebraicFunction(wxString OriginalExpression);
 wxString GetErrorString(){ return ErrorCode; };
 double GetEval(){return FunctionValue;};
};


#endif // CALCULATORLIBRARY_H_INCLUDED
