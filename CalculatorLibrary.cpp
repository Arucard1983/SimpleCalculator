#include "CalculatorLibrary.h"
#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY( AlgebraicVariableArray);
WX_DEFINE_OBJARRAY( TokenArray);


// An internal funcion (cannot access directly) to find the real array adress of a given variable
int AlgebraicVariableVector::FindVariableAdress(wxString varname)
{
  for (int i=0; i<this->GetCount(); i++)
  {
    if (this->Item(i).GetName() == varname)
        return i;
  }
  return wxNOT_FOUND;
}

// Try to find a variable on the array with the same name as argument. Return the sucefulness.
bool AlgebraicVariableVector::Find(wxString name)
{
  for (int i=0; i<this->GetCount(); i++)
  {
    if (this->Item(i).GetName() == name)
        return true;
  }
  return false;
}

// Try to find a variable on the array with the same name as argument, and return their value.
double AlgebraicVariableVector::FindGet(wxString name)
{
  for (int i=0; i<this->GetCount(); i++)
  {
    if (this->Item(i).GetName() == name)
        return this->Item(i).GetValue();
  }
  return NAN;
}

// Try to find a variable on the array with the same name as argument, while changes their numeric value. Return the sucefulness.
bool AlgebraicVariableVector::FindReplace(wxString name, long double newvalue)
{
  for (int i=0; i<this->GetCount(); i++)
  {
    if (this->Item(i).GetName() == name)
    {
       this->Item(i).SetValue(newvalue);
       return true;
    }
  }
  return false;
}




// Check the array of Tokens and classify along thier types.
// The priority rules are the following:
// 0: For numbers, variables, parenthesis, commas and colons, since it had special rules
// 1: For assigment operator "="
// 2: For sum "+" and minus "-"
// 3: For product "*" and division "/"
// 4: For power "^", and the only one with right (false flag) associativity
// 5: For the built-in functions, since it had the highest priority on evaluation order.
bool TokenVector::ClassifyAndCheck()
{
 // Begin the main cycle
  for (int i=0; i<this->GetCount(); i++)
  {
   if (this->CheckIsValidNumber(i)) // If the token is a valid number, it will set the default flags as a number
   {
    this->Item(i).SetAllFlags(0,true,true,false,false,false);
   }
   else if (this->CheckIsValidSymbol(i)) // If the token is a valid symbol, then it requires futher details
   {
    if (this->Item(i).GetValue() == wxT("+"))
     this->Item(i).SetAllFlags(2,true,false,false,false,true);
    else if (this->Item(i).GetValue() == wxT("-"))
     this->Item(i).SetAllFlags(2,true,false,false,false,true);
    else if (this->Item(i).GetValue() == wxT("*"))
     this->Item(i).SetAllFlags(3,true,false,false,false,true);
    else if (this->Item(i).GetValue() == wxT("/"))
     this->Item(i).SetAllFlags(3,true,false,false,false,true);
    else if (this->Item(i).GetValue() == wxT("^"))
     this->Item(i).SetAllFlags(4,false,false,false,false,true);
    else if (this->Item(i).GetValue() == wxT("="))
     this->Item(i).SetAllFlags(1,true,false,false,false,true);
    else if (this->Item(i).GetValue() == wxT("("))
     this->Item(i).SetAllFlags(0,true,false,false,false,true);
    else if (this->Item(i).GetValue() == wxT(")"))
     this->Item(i).SetAllFlags(0,true,false,false,false,true);
    else if (this->Item(i).GetValue() == wxT(":"))
     this->Item(i).SetAllFlags(0,true,false,false,false,true);
    else if (this->Item(i).GetValue() == wxT(","))
     this->Item(i).SetAllFlags(0,true,false,false,false,true);
    else if (this->Item(i).GetValue() == wxT("?"))
     this->Item(i).SetAllFlags(0,true,false,false,false,true);
    else
      return false;
   }
   else if (this->CheckIsValidVariable(i)) // If the token is a valid variable, first we need to check against the list of built-in functions, and special words
   {
    if (this->Item(i).GetValue() == wxT("asin"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("sin"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("asinh"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("sinh"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("acos"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("cos"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("acosh"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("cosh"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("atan"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("tan"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("atanh"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("tanh"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("exp"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("log"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("ln"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else if (this->Item(i).GetValue() == wxT("sqrt"))
     this->Item(i).SetAllFlags(5,true,false,false,true,false);
    else
     this->Item(i).SetAllFlags(0,true,false,true,false,false); // If don`t belong to the built-in words, then it`s a variable
   }
   else // If nothing are valid, return a failure.
    return false;
  }
  return true; // Return true, since the whole process was done.
}

// Verify the consistency of a number
bool Token::CheckIsValidNumber()
{
 double temp;
 return (this->GetValue().ToDouble(&temp));
}

// Verify the consistency of a number
bool TokenVector::CheckIsValidNumber(int position)
{
 double temp;
 return (this->Item(position).GetValue().ToDouble(&temp));
}

// Verify the consistency of an alfanumeric string
bool Token::CheckIsValidVariable()
{
  wxString temp = wxT("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
  wxString temp0 = wxT("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
  wxString character;
  int counter;
  for (int i=0; i<this->GetValue().Len(); i++)
  {
    character = this->GetValue().GetChar(i);
    if (i == 0)
     counter = temp0.Find(character);
    else
     counter = temp.Find(character);
    if (counter == wxNOT_FOUND)
    {
      return false;
    }
  }
  return true;
}

// Verify the consistency of an alfanumeric string
bool TokenVector::CheckIsValidVariable(int position)
{
  wxString temp = wxT("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
  wxString temp0 = wxT("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
  wxString character;
  int counter;
  for (int i=0; i<this->Item(position).GetValue().Len(); i++)
  {
    character = this->Item(position).GetValue().GetChar(i);
    if (i == 0)
     counter = temp0.Find(character);
    else
     counter = temp.Find(character);
    if (counter == wxNOT_FOUND)
    {
      return false;
    }
  }
  return true;
}

// Verify the consistency of a valid symbol
bool Token::CheckIsValidSymbol()
{
 wxString temp = wxT("()?=:,^*/-+");
  wxString character;
  int counter;
  for (int i=0; i<this->GetValue().Len(); i++)
  {
    character = this->GetValue().GetChar(i);
    counter = temp.Find(character);
    if (counter == wxNOT_FOUND)
    {
      return false;
    }
  }
  return true;
}

// Verify the consistency of a valid symbol
bool TokenVector::CheckIsValidSymbol(int position)
{
 wxString temp = wxT("()?=:,^*/-+");
  wxString character;
  int counter;
  for (int i=0; i<this->Item(position).GetValue().Len(); i++)
  {
    character = this->Item(position).GetValue().GetChar(i);
    counter = temp.Find(character);
    if (counter == wxNOT_FOUND)
    {
      return false;
    }
  }
  return true;
}

// Generate the array of tokens from the original string.
// The main three types of tokens are:
// Numeric Token: Which represent a number, including in the scientific notation form.
// Symbol Token: A single character token, which is almost easy to tokenize.
// Variable Token: Any array of alfanumerical characters. The first character should be a letter.
bool AlgebraicFunction::AlgebraicParser()
{
 wxString cache,character;
 for(int i=0; i<InternalFunctionString.Len(); i++)
 {
   character.Clear();
   character = InternalFunctionString.GetChar(i);
   Token *testchar = new Token(character);
   Token *testcache = new Token(cache + character);
   Token *testnumber = new Token(cache + character + wxT("0"));
   // Empty characters will not produce any new token, but will tokenize any remaining characters left on temporary memory
   if (character == wxT(" ") || character == wxT("\t") || character == wxT("\n"))
   {
     if(cache.Len()>0)
     {
       if(InternalFunctionTokens.NewToken(cache))
        {
         cache.Clear();
        }
       else
        {
         ErrorCode = wxT("Syntax Error: Invalid Token \"") + cache + wxT("\"");
         return false;
        }
     }
   }
   // Any operator character, except the "-" or "+" due to the fact may belong to a number token, are simply tokenized
   else if (testchar->CheckIsValidSymbol() && testchar->GetValue() != wxT("+") && testchar->GetValue() != wxT("-"))
   {
     if(cache.Len()>0)
     {
       if(InternalFunctionTokens.NewToken(cache))
        {
         cache.Clear();
         if(!(InternalFunctionTokens.NewToken(character)))
         {
         ErrorCode = wxT("Syntax Error: Invalid Operator Symbol \"") + character + wxT("\"");
         return false;
         }
        }
       else
        {
         ErrorCode = wxT("Syntax Error: Invalid Token \"") + cache + wxT("\"");
         return false;
        }
     }
     else
     {
      cache.Clear();
      if(!(InternalFunctionTokens.NewToken(character)))
       {
         ErrorCode = wxT("Syntax Error: Invalid Operator Symbol \"") + character + wxT("\"");
         return false;
       }
     }
   }
   // Next case will handle the little fry when the current character is a "-" or "+" symbol
   else if (character == wxT("-") || character == wxT("+"))
   {
     // Picking the next character
     wxString nextchar;
     if (InternalFunctionString.Len()-i>1)
      nextchar = InternalFunctionString.GetChar(i+1);
     if(cache.Len()>0)
     {
       // Testing for number compability, i.e., (123.5e)(+/-)(0)
       Token *testsci = new Token(cache + character + nextchar);
       if (testsci->CheckIsValidNumber())
       {
         cache = cache + character;
       }
       else
       {
         // Store the current cache, and the new symbol as separate tokens.
       if(InternalFunctionTokens.NewToken(cache))
        {
         cache.Clear();
         if(!(InternalFunctionTokens.NewToken(character)))
         {
         ErrorCode = wxT("Syntax Error: Invalid Operator Symbol \"") + cache + wxT("\"");
         return false;
         }
        }
       else
        {
         ErrorCode = wxT("Syntax Error: Invalid Token \"") + cache + wxT("\"");
         return false;
        }
       }
       delete testsci;
     }
     else
     {
      // Testing for number compability, i.e., (+/-)(0)
       Token *testnum = new Token(character + nextchar);
       if (testnum->CheckIsValidNumber())
       {
         cache = cache + character;
       }
       else
       {
         // Otherwise just tokenize the current symbol
        cache.Clear();
        if(!(InternalFunctionTokens.NewToken(character)))
        {
         ErrorCode = wxT("Syntax Error: Invalid Operator Symbol \"") + character + wxT("\"");
         return false;
        }
       }
       delete testnum;
     }
   }
   // If the current character are an alfanumeric one, just add to the current cache
   else if (testcache->CheckIsValidNumber() || testcache->CheckIsValidVariable() || testnumber->CheckIsValidNumber())
    {
         cache = cache + character;
    }
   // And the default case will bring a fatal error
   else
    {
      ErrorCode = wxT("Syntax Error: Invalid or Unknown Symbol \"") + character + wxT("\"");
      return false;
    }
   delete testchar;
   delete testcache;
   delete testnumber;
 }
 // Store the remaining temporary cache as a new token, if applicable
 if(cache.Len()>0)
     {
       if(InternalFunctionTokens.NewToken(cache))
        {
         cache.Clear();
        }
       else
        {
         ErrorCode = wxT("Syntax Error: Invalid Token  \"") + cache + wxT("\"");
         return false;
        }
     }
 // And finishes the procedure
  return true;
}

// Evaluate the numerical values of built-in functions, using the STL library
long double AlgebraicFunction::EvaluateFunction(Token f, long double arg)
{
 if(f.GetValue() == wxT("sin"))
  return std::sin(arg);
 else if(f.GetValue() == wxT("asin"))
  return std::asin(arg);
 else if(f.GetValue() == wxT("sinh"))
  return std::sinh(arg);
 else if(f.GetValue() == wxT("asinh"))
  return std::log(arg + std::sqrt(arg*arg+1));
 else if(f.GetValue() == wxT("cos"))
  return std::cos(arg);
 else if(f.GetValue() == wxT("acos"))
  return std::acos(arg);
 else if(f.GetValue() == wxT("cosh"))
  return std::cosh(arg);
 else if(f.GetValue() == wxT("acosh"))
  return std::log(arg + std::sqrt(arg*arg-1));
 else if(f.GetValue() == wxT("tan"))
  return std::tan(arg);
 else if(f.GetValue() == wxT("atan"))
  return std::atan(arg);
 else if(f.GetValue() == wxT("tanh"))
  return std::tanh(arg);
 else if(f.GetValue() == wxT("atanh"))
  return std::log(arg + 1)/2 - std::log(arg - 1)/2;
 else if(f.GetValue() == wxT("sqrt"))
  return std::sqrt(arg);
 else if(f.GetValue() == wxT("exp"))
  return std::exp(arg);
 else if(f.GetValue() == wxT("ln"))
  return std::log(arg);
 else if(f.GetValue() == wxT("log"))
  return std::log10(arg);
 else
  return NAN;
}

// Evaluate numerically the built-in arithmetic operators.
long double AlgebraicFunction::EvaluateOperator(Token o, long double arg1, long double arg2)
{
 if(o.GetValue() == wxT("+"))
  return arg2 + arg1;
 else if(o.GetValue() == wxT("-"))
  return arg2 - arg1;
 else if(o.GetValue() == wxT("*"))
  return arg2 * arg1;
 else if(o.GetValue() == wxT("/"))
  return arg2 / arg1;
 else if(o.GetValue() == wxT("^"))
  return std::pow(arg2,arg1);
 else
  return NAN;
}

// Convert the token array to the RPN format, which is more manegable to evaluate numerical data.
bool AlgebraicFunction::AlgebraicCompiler()
{
 RPNTokenStack.Clear();
 TokenVector LocalOperatorStack;
 // Start the Shunting-Yard main cicle
 for(int i=0; i<InternalFunctionTokens.GetCount(); i++)
 {
  // If the current toke is a number, just copy to the output stack
  if (InternalFunctionTokens.Item(i).IsNumber())
  {
   RPNTokenStack.Add(InternalFunctionTokens.Item(i));
  }
  // A variable follows the same rule, since it is a symbolic place for a number.
  else if (InternalFunctionTokens.Item(i).IsVariable())
  {
   RPNTokenStack.Add(InternalFunctionTokens.Item(i));
  }
  // The "?" token also copy to the output stack, and should be placed after a variable, but it is not checked here.
  else if (InternalFunctionTokens.Item(i).GetValue() == wxT("?"))
  {
   RPNTokenStack.Add(InternalFunctionTokens.Item(i));
  }
  // The "=" token will copy to the stack, and it is the lowest precedence operator.
  else if (InternalFunctionTokens.Item(i).GetValue() == wxT("="))
  {
   LocalOperatorStack.Add(InternalFunctionTokens.Item(i));
  }
  // Any function token will be sent to the operator stack
  else if (InternalFunctionTokens.Item(i).IsFunction())
  {
   LocalOperatorStack.Add(InternalFunctionTokens.Item(i));
  }
  // The comma "," operator will flush the entire operator stack, and it should not have some symbols like the left parenthesis left
  else if (InternalFunctionTokens.Item(i).GetValue() == wxT(","))
  {
   for(int j=0; j<LocalOperatorStack.GetCount(); j++)
   {
    if (LocalOperatorStack.Item(LocalOperatorStack.GetCount()-1-j).GetValue() == wxT("("))
     {
      ErrorCode = wxT("Syntax Error: Variable separator \",\" out-of-place");
      return false;
     }
     else
     {
      RPNTokenStack.Add(LocalOperatorStack.Item(LocalOperatorStack.GetCount()-1-j));
     }
   }
   LocalOperatorStack.Clear();
  }
  // The colon ":" operator will also flush the entire operator stack as the previous case, but at the end, the colon symbol will be exported to the output stack
  else if (InternalFunctionTokens.Item(i).GetValue() == wxT(":"))
  {
   for(int j=0; j<LocalOperatorStack.GetCount(); j++)
   {
    if (LocalOperatorStack.Item(LocalOperatorStack.GetCount()-1-j).GetValue() == wxT("("))
     {
      ErrorCode = wxT("Syntax Error: Multistatement operator \":\" out-of-place");
      return false;
     }
     else
     {
      RPNTokenStack.Add(LocalOperatorStack.Item(LocalOperatorStack.GetCount()-1-j));
     }
   }
   LocalOperatorStack.Clear();
   RPNTokenStack.Add(InternalFunctionTokens.Item(i));
  }
  // If the operator stack is empty, any operator will be sent to the operator stack
  else if (InternalFunctionTokens.Item(i).IsOperator() && LocalOperatorStack.GetCount() == 0 )
  {
   LocalOperatorStack.Add(InternalFunctionTokens.Item(i));
  }
  // If the current token is an arithmetic operator, then start the following cycle...
  else if (InternalFunctionTokens.Item(i).IsOperator() && InternalFunctionTokens.Item(i).GetPriority() > 0 )
  {
    // Start the popping cycle
    int OriginalStackSize = LocalOperatorStack.GetCount();
    for (int j=0; j<OriginalStackSize; j++)
    {
     // If the current token is left associative and their priority are equal or less than the operator stack priority, pop that operator to the output stack
     if (InternalFunctionTokens.Item(i).GetAssociativity() && (InternalFunctionTokens.Item(i).GetPriority() <= LocalOperatorStack.Last().GetPriority()))
     {
      RPNTokenStack.Add(LocalOperatorStack.Item(LocalOperatorStack.GetCount()-1));
      LocalOperatorStack.RemoveAt(LocalOperatorStack.GetCount()-1);
     }
     // If the current token is right associative and their priority are  less than the operator stack priority, pop that operator to the output stack
     else if (!(InternalFunctionTokens.Item(i).GetAssociativity()) && (InternalFunctionTokens.Item(i).GetPriority() < LocalOperatorStack.Last().GetPriority()))
     {
      RPNTokenStack.Add(LocalOperatorStack.Item(LocalOperatorStack.GetCount()-1));
      LocalOperatorStack.RemoveAt(LocalOperatorStack.GetCount()-1);
     }
     else // Stop the popping
     {
      j = OriginalStackSize;
     }  
    }
    // Push the current token to the operator stack
    LocalOperatorStack.Add(InternalFunctionTokens.Item(i));
  }
  // A left parenthesis just copy to the stack
  else if (InternalFunctionTokens.Item(i).GetValue() == wxT("("))
  {
   LocalOperatorStack.Add(InternalFunctionTokens.Item(i));
  }
  // A right parenthesis will flush the operator stack until a left parenthesis are found, and both discarded. Also, it should not cross with commas, colons and assigments
  else if (InternalFunctionTokens.Item(i).GetValue() == wxT(")"))
  {
   int OriginalStackSize = LocalOperatorStack.GetCount();
   bool FoundLeftParenthesis = false;
   for(int j=0; j<OriginalStackSize; j++)
   {
    if (LocalOperatorStack.Last().GetValue() == wxT("("))
     {
      // If found a left parenthesis, delete it and finishes the flusing cycle
      LocalOperatorStack.RemoveAt(LocalOperatorStack.GetCount()-1);
       j = OriginalStackSize;
       FoundLeftParenthesis = true;
      // Also check if the first top of the operator stack is a function (since their arguments are bounded by parenthesis)
      if (LocalOperatorStack.GetCount()>0)
      {
        if(LocalOperatorStack.Last().IsFunction()) // If so, then copy the function token to the output stack
        {
          RPNTokenStack.Add(LocalOperatorStack.Last());
          LocalOperatorStack.RemoveAt(LocalOperatorStack.GetCount()-1);
        }
      }
     }
     else if (LocalOperatorStack.Last().GetValue() == wxT("="))
     {
      ErrorCode = wxT("Syntax Error: Assigment operator \"=\" out-of-place");
      return false;
     }
     else if (LocalOperatorStack.Last().GetValue() == wxT(":"))
     {
      ErrorCode = wxT("Syntax Error: Multistatement operator \":\" out-of-place");
      return false;
     }
     else if (LocalOperatorStack.Last().GetValue() == wxT(","))
     {
      ErrorCode = wxT("Syntax Error: Variable separator \",\" out-of-place");
      return false;
     }
     else
     {
      RPNTokenStack.Add(LocalOperatorStack.Last());
      LocalOperatorStack.RemoveAt(LocalOperatorStack.GetCount()-1);
     }
   }
   if (!(FoundLeftParenthesis))
   {
      ErrorCode = wxT("Syntax Error: Parenthesis Mismatch");
      return false;
   }
  }
  // An unknown token will trigger a fatal error
  else
  {
      ErrorCode = wxT("Fatal Error: Undefined Variable, Function or Operator: \"") + InternalFunctionTokens.Item(i).GetValue() + wxT("\"");
      return false;
  }
 }
 // Flush the remaining operator stack
 for(int k=0; k<LocalOperatorStack.GetCount(); k++)
   {
    if (LocalOperatorStack.Item(LocalOperatorStack.GetCount()-1-k).GetValue() == wxT("("))
     {
      ErrorCode = wxT("Syntax Error: Parenthesis Mismatch");
      return false;
     }
     else
     {
      RPNTokenStack.Add(LocalOperatorStack.Item(LocalOperatorStack.GetCount()-1-k));
     }
   }
   LocalOperatorStack.Clear();
 // Exit the procedure
   return true;
}

// Implements a postfix calculator, using the tokens previously converted to the RPN stack, and return the numerical values.
bool AlgebraicFunction::AlgebraicCalculator()
{
 // The internal register stack required for temporary memory use the variable class, using the following convention:
 // A standard number will be treated as a _NULL_ variable.
 // A variable will have the default "true" value, otherwise a constant it will be "false".
 // A parameter accepts strings as arguments, and do not accept algebraic expressions.
 AlgebraicVariableVector RegisterStack;

 // Begin the RPN processing main cycle, which is similar to a computer low-level program
 for (int i=0; i<RPNTokenStack.GetCount(); i++)
 {
   // A number token are converted to a double precision constant and pop to the register stack.
   if (RPNTokenStack.Item(i).IsNumber())
   {
    double temp;
    RPNTokenStack.Item(i).GetValue().ToDouble(&temp);
    RegisterStack.NewConstant(wxT("_NULL_"),temp);
   }
   // A variable are simply moved to the register stack with the same name, and a null value.
   else if (RPNTokenStack.Item(i).IsVariable())
   {
    RegisterStack.NewConstant(RPNTokenStack.Item(i).GetValue(),0.0);
   }
   // The special "?" token will find and check if the last element of register is a variable, and replace if necessary.
   else if (RPNTokenStack.Item(i).GetValue() == wxT("?"))
   {
    if(RegisterStack.GetCount()>0) // Requires at least one argument
    {
     if(RegisterStack.Item(RegisterStack.GetCount()-1).GetName() != wxT("_NULL_")) // And cannot be a number!
     {
      double temp = RegisterStack.Item(RegisterStack.GetCount()-1).GetValue();
      wxString tempvar = RegisterStack.Item(RegisterStack.GetCount()-1).GetName();
      RegisterStack.RemoveAt(RegisterStack.GetCount()-1);
      RegisterStack.NewVariable(tempvar,temp);
     }
     else
     {
      ErrorCode = wxT("Syntax Error: Invalid Variable Name: \"") + RegisterStack.Item(RegisterStack.GetCount()-1).GetName() + wxT("\""); // Invalid syntax format.
      return false;
     }
    }
    else
    {
      ErrorCode = wxT("Declaration Error: Variable suffix \"?\" without the variable name itself!"); // Invalid syntax format.
      return false;
    }
   }
   // The assigment operator expect two arguments from the register stack, where the first argument will be copied to the second one.
   else if (RPNTokenStack.Item(i).GetValue() == wxT("="))
   {
     if(RegisterStack.GetCount()>1) // Requires at least two arguments
     {
        // The left argument is the new variable, or the parameter
        wxString tempvar = RegisterStack.Item(RegisterStack.GetCount()-2).GetName(); // Get the variable name
        if (InternalFunctionVariables.Find(tempvar)) // check the presence of the new declared variable/constant
        {
          if(RegisterStack.Item(RegisterStack.GetCount()-2).IsConstant())
          {
            ErrorCode = wxT("Declaration Error: Cannot redefine the constant, since it already values \"") + RegisterStack.Item(RegisterStack.GetCount()-2).GetName() + wxT(" = ") + wxString::Format( wxT("%.10e"), InternalFunctionVariables.FindGet(RegisterStack.Item(RegisterStack.GetCount()-2).GetName())) + wxT("\""); // A constant cannot be redefined!
            return false;
          }
          else if(RegisterStack.Item(RegisterStack.GetCount()-2).IsVariable())
          {
            double temp = RegisterStack.Item(RegisterStack.GetCount()-1).GetValue(); // Get the variable value
            InternalFunctionVariables.FindReplace(tempvar,temp); // Store the new variable
            RegisterStack.RemoveAt(RegisterStack.GetCount()-1); // Delete the two arguments from the register stack
            RegisterStack.RemoveAt(RegisterStack.GetCount()-1);
          }
          else
          {
            ErrorCode = wxT("Declaration Error: Invalid variable name format, \"") + RegisterStack.Item(RegisterStack.GetCount()-2).GetName() + wxT("\", for the assignment operator \"=\"."); // A constant cannot be redefined!
            return false;
          }
        }
        else // It's a new variable/constant
        {
         if(RegisterStack.Item(RegisterStack.GetCount()-2).IsConstant() || RegisterStack.Item(RegisterStack.GetCount()-2).IsVariable())
          {
            double temp;
            // Check the validity of the right argument, which can be a number or an already known variable, or even a parameter argument
           if (RegisterStack.Item(RegisterStack.GetCount()-1).GetName() == wxT("_NULL_"))
           {
           temp = RegisterStack.Item(RegisterStack.GetCount()-1).GetValue(); // Get the variable value
           }
           else
           {
            if(InternalFunctionVariables.Find(RegisterStack.Item(RegisterStack.GetCount()-1).GetName())) // Verify if the variable are defined
            {
            temp = InternalFunctionVariables.FindGet(RegisterStack.Item(RegisterStack.GetCount()-1).GetName()); // Get the variable value
            }
            else
            {
            ErrorCode = wxT("Declaration Error: Undefined Variable: \"") + RegisterStack.Item(RegisterStack.GetCount()-1).GetName() + wxT("\"");
            return false;
            }
           }
            InternalFunctionVariables.NewConstant(tempvar,temp); // Store the new constant
            RegisterStack.RemoveAt(RegisterStack.GetCount()-1); // Delete the two arguments from the register stack
            RegisterStack.RemoveAt(RegisterStack.GetCount()-1);
          }
          else
          {
            ErrorCode = wxT("Declaration Error: Invalid variable name format, \"") + RegisterStack.Item(RegisterStack.GetCount()-2).GetName() + wxT("\", for the assignment operator \"=\"."); 
            return false;
          }
        }
     }
     else
     {
      ErrorCode = wxT("Declaration Error: Assigment operator \"=\" without valid arguments"); // Invalid syntax format.
      return false;
     }
   }
  // The colon ":" operator will delete the entire register stack, while try to store the last numerical value to the output variable.
  else if (RPNTokenStack.Item(i).GetValue() == wxT(":"))
  {
    if (RegisterStack.GetCount() == 0) // Empty register stack
    {
     RegisterStack.Clear();
    }
    else if (RegisterStack.GetCount() == 1) // One value stored
    {
     if (RegisterStack.Item(RegisterStack.GetCount()-1).GetName() == wxT("_NULL_")) // Numerical tokens will be stored to the output variable
      {
       FunctionValue = RegisterStack.Item(RegisterStack.GetCount()-1).GetValue();
       RegisterStack.Clear();
      }
      else if(InternalFunctionVariables.Find(RegisterStack.Item(RegisterStack.GetCount()-1).GetName()))
      {
       FunctionValue = InternalFunctionVariables.FindGet(RegisterStack.Item(RegisterStack.GetCount()-1).GetName());
      }
      else
      {
        ErrorCode = wxT("Declaration Error: Undefined Variable: \"") + RegisterStack.Item(RegisterStack.GetCount()-1).GetName() + wxT("\"");
        return false;
      }
    }
    else
    {
      ErrorCode = wxT("Syntax Error: Invalid numerical expression"); // Invalid syntax format.
      return false;
    }
  }
 // Verify the evaluation of a function, while take care the potential numerical overflows using the STL library.
  else if (RPNTokenStack.Item(i).IsFunction())
  {
    if (RegisterStack.GetCount() > 0)
    {
      if (RegisterStack.Item(RegisterStack.GetCount()-1).GetName() != wxT("_NULL_")) // If the argument are a variable
      {
        if (InternalFunctionVariables.Find(RegisterStack.Item(RegisterStack.GetCount()-1).GetName()))
        {
          double temp = InternalFunctionVariables.FindGet(RegisterStack.Item(RegisterStack.GetCount()-1).GetName());
          double f = this->EvaluateFunction(RPNTokenStack.Item(i),temp);
          // Non-numerical values will trigger an exception
          if (std::isfinite(f))
          {
           RegisterStack.RemoveAt(RegisterStack.GetCount()-1);
           RegisterStack.NewVariable(wxT("_NULL_"),f);
          }
          else
          {
             ErrorCode = wxT("Numerical Error: Non-numeric result during evaluation.");
             return false;
          }
        }
        else
        {
          ErrorCode = wxT("Declaration Error: Undefined Variable: \"") + RegisterStack.Item(RegisterStack.GetCount()-1).GetName() + wxT("\"");
          return false;
        }
      }
      else // If the argument are a number
      {
       double f = this->EvaluateFunction(RPNTokenStack.Item(i),RegisterStack.Item(RegisterStack.GetCount()-1).GetValue());
          // Non-numerical values will trigger an exception
          if (std::isfinite(f))
          {
           RegisterStack.RemoveAt(RegisterStack.GetCount()-1);
           RegisterStack.NewVariable(wxT("_NULL_"),f);
          }
          else
          {
             ErrorCode = wxT("Numerical Error: Non-numeric result during evaluation.");
             return false;
          }
      }
    }
    else
    {
      ErrorCode = wxT("Syntax Error: Function without valid argument."); // Invalid syntax format.
      return false;
    }
  }
 // Evaluate an arithmetic operator, and use the STL library to handle invalid numerical results
  else if (RPNTokenStack.Item(i).IsOperator() && RPNTokenStack.Item(i).GetPriority() > 0)
  {
    if (RegisterStack.GetCount() > 1)
    {
      double temp1,temp2;
      wxString tempvar1,tempvar2;
      // First argument
      if (RegisterStack.Item(RegisterStack.GetCount()-1).GetName() != wxT("_NULL_"))
      {
       tempvar1 = RegisterStack.Item(RegisterStack.GetCount()-1).GetName();
       if (InternalFunctionVariables.Find(RegisterStack.Item(RegisterStack.GetCount()-1).GetName()))
        {
          temp1 = InternalFunctionVariables.FindGet(RegisterStack.Item(RegisterStack.GetCount()-1).GetName());
        }
        else
        {
          ErrorCode = wxT("Declaration Error: Undefined Variable: \"") + RegisterStack.Item(RegisterStack.GetCount()-1).GetName() + wxT("\"");
          return false;
        }
      }
      else
      {
        temp1 = RegisterStack.Item(RegisterStack.GetCount()-1).GetValue();
      }
      // Second argument
      if (RegisterStack.Item(RegisterStack.GetCount()-2).GetName() != wxT("_NULL_"))
      {
       tempvar2 = RegisterStack.Item(RegisterStack.GetCount()-2).GetName();
       if (InternalFunctionVariables.Find(RegisterStack.Item(RegisterStack.GetCount()-2).GetName()))
        {
          temp2 = InternalFunctionVariables.FindGet(RegisterStack.Item(RegisterStack.GetCount()-2).GetName());
        }
        else
        {
          ErrorCode = wxT("Declaration Error: Undefined Variable: \"") + RegisterStack.Item(RegisterStack.GetCount()-2).GetName() + wxT("\"");
          return false;
        }
      }
      else
      {
        temp2 = RegisterStack.Item(RegisterStack.GetCount()-2).GetValue();
      }
      // Evaluate the result
      double f = this->EvaluateOperator(RPNTokenStack.Item(i),temp1,temp2);
      // Non-numerical values will trigger an exception
          if (std::isfinite(f))
          {
           RegisterStack.RemoveAt(RegisterStack.GetCount()-1);
           RegisterStack.RemoveAt(RegisterStack.GetCount()-1);
           RegisterStack.NewVariable(wxT("_NULL_"),f);
          }
          else
          {
             ErrorCode = wxT("Numerical Error: Non-numeric result during evaluation.");
             return false;
          }
    }
    else
    {
      ErrorCode = wxT("Syntax Error: Arithmetic operator without valid arguments."); // Invalid syntax format.
      return false;
    }
  }
  // Case default will also trigger an exception
  else
  {
    ErrorCode = wxT("Syntax Error: Invalid or Unknown Operator: \"") + RPNTokenStack.Item(i).GetValue() + wxT("\"."); // Invalid syntax format.
    return false;
  }
 }
 // Evaluate the remaining register stack members
    if (RegisterStack.GetCount() == 0) // Empty register stack
    {
     FunctionValue = 0;
    }
    else if (RegisterStack.GetCount() == 1) // One value stored
    {
     if (RegisterStack.Item(RegisterStack.GetCount()-1).GetName() == wxT("_NULL_")) // Numerical tokens will be store the output variable
      {
       FunctionValue = RegisterStack.Item(RegisterStack.GetCount()-1).GetValue();
       RegisterStack.Clear();
      }
      else if(InternalFunctionVariables.Find(RegisterStack.Item(RegisterStack.GetCount()-1).GetName()))
      {
       FunctionValue = InternalFunctionVariables.FindGet(RegisterStack.Item(RegisterStack.GetCount()-1).GetName());
      }
      else
      {
       RegisterStack.Clear();
      }
    }
    else
    {
      ErrorCode = wxT("Syntax Error: Invalid numerical expression"); // Invalid syntax format.
      return false;
    }
  return true;
}

// Main Function Constructor, which simply guides the three main algebraic procedures to obtain a numeric value from the user input
AlgebraicFunction::AlgebraicFunction(wxString OriginalExpression)
{
 InternalFunctionString = OriginalExpression;
 if(this->AlgebraicParser())
 {
  if(this->AlgebraicCompiler())
  {
   if(this->AlgebraicCalculator())
   {
     ErrorCode.Clear();
   }
  }
 }
}
