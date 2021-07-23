
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LexerTry.h"

#include "Identifier.h"
#include "Operators.h"
#include "Seperators.h"
#include "KeyWord.h"
#include "ValidDataType-final.h"

#include "VariableHandler.h"
#include "PointerHandler.h"
#include "FunctionHandler.h"
#include "ArrayHandler.h"

#include "IF_Handler.h"
#include "TreeFunction.h"



#define ERROR	-1

extern char token[30];
extern int line;

char If_Handler ( void)
{	
	char Token = Get_Tocken();
	
	Condition:
	/* check the condition */
	if (Token == OPEN_ARCH)
	{
		Token = Get_Tocken();
		switch (Token)
		{
			case IDIENTIFIER_YES: 
			{
				Syntax_Handler(0); 
			}
			break;

			case INT_NUM:
			case FLOAT_NUM:	
			{
				Syntax_Number(0);	
			}
			break;
			
			case ASTRICS: 
			{
				Syntax_Pointer();	
			}
			break;
		}
	}
	else
	{	
		printf("%d: error expected '(' before '%s' Token",line, token);
		return ERROR;
	}
	
	Token = Get_Tocken();
	
	Body:
	/* Check body */
	/* Compound statment body */
	if (Token == OPEN_BRACKET)
		{
			while (Token != CLOSE_BRACKET)
			{
				TreeDecesion(Token);
				Token = Get_Tocken();
			}
		}
	/* Single statment body */
	else
	{
		TreeDecesion(Token);
	}
	
	Token = Get_Tocken();
	if (Token == ELSE)
	{
		Token = Get_Tocken();
		
		if (Token == IF)
			goto Condition;
		
		else 
			goto Body;
	}
	return 1;
}
