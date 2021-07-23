#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "VariableHandler.h"
#include "Linked_List_handler.h"
#include "Operators.h"
#include "Seperators.h"
#include "LexerTry.h"
#include "Syntax_Handler.h"
#include "ValidDataType-final.h"
#include "Identifier.h"
#include "TreeFunction.h"
#include "While_Handler.h"
#define IDIENTIFIER_YES 	127
#define IDIENTIFIER_NO	 	126
#define INT_NUM 			124
#define FLOAT_NUM			125
#define BRAEK   		    25
#define CONTINUE		    27

/*From Scope Code */
extern int Scope_Number;
extern int line;
extern char token[30];
extern Variable *Head;
static int init = 0;



void While_Handler ()
{
	printf("iam in while handler..............\n");
	char Bracket_Counter=0;
	char loc_gettocken;
	char flag = 1 ;
	char res ;
	if(Scope_Number == 0){
		printf("%d: error: expected '=', ',', ';', 'asm' or '_attribute_' before '%s' token",line,token);
	}
	//get new tocken it should be identifier or number 
	loc_gettocken = Get_Tocken();
	
	if (loc_gettocken == OPEN_ARCH )
	{
		res = Get_Tocken();
		if (res == IDIENTIFIER_YES)
		{
			//call identifier handler
			Syntax_Handler(0);
		}
		else if (res ==INT_NUM || res == FLOAT_NUM )
		{
			// call syntax number function
			Syntax_Number (0);
		}
		else if(res == ASTRICS )
		{
			// call syntax pointer function
		    Syntax_Pointer();
		}
		else 
		{
			 printf("syntax error in line %d\n",line); 
		}
	}
	else 
	{
		printf("syntax error: missing ( in line %d\n",line); 
		exit(1);
	}		
		
	    res  = Get_Tocken();
	if (res == SEMI_COMMA)
	{
		printf ("you got ; end of statment\n");
		return;
	}
	else if(res == OPEN_BRACKET)
	{
		;
	}
	else
	{
		printf("%d: error: expected expression before %s in while Implementation",line,token);
	    exit(1);
	}
	
	// grammer check on while loop body
	do
	{
		res = Get_Tocken();
		if(res == BRAEK || res == CONTINUE)
		{
			;//BREAK OR CONTINUE CASES
		}
		else if(res == OPEN_BRACKET)
		{
			Bracket_Counter++;
		}
		else if(res == CLOSE_BRACKET)
		{
			
			if(Bracket_Counter == 0)
			{
				flag = 0;
			}
			else
			{
				Bracket_Counter--;
			}
		}
		else
		{
		TreeDecesion(res);
		}
	}
	while(flag);
}


void Do_While_Handler ()
{
	printf("iam in do while handler\n");
   //get new tocken it should be identifier or number 
	char res ;
	char flag = 1,Bracket_Counter = 0;
	if(Scope_Number == 0){
		printf("%d: error: expected '=', ',', ';', 'asm' or '_attribute_' before '%s' token",line,token);
	}
	do{
		res = Get_Tocken();
		if(res == BRAEK || res == CONTINUE)
		{
			;//BREAK OR CONTINUE CASES
		}
		else if(res == OPEN_BRACKET)
		{
			Bracket_Counter++;
		}
		else if(res == CLOSE_BRACKET)
		{
			
			if(Bracket_Counter == 0)
			{
				flag = 0;
			}
			else
			{
				Bracket_Counter--;
			}
		}
		else
		{
		TreeDecesion(res);
		}
	}
	while(flag);

		int loc_gettocken;
		//Get_Tocken();
	loc_gettocken =  Get_Tocken();
	 	printf("While Hand---> Do implimented well	 %d 	%s\n	",loc_gettocken,token);
	if (strcmp (token,"while")==0 )
	{
		// if we got while call while handler
		loc_gettocken = Get_Tocken();
	
	if (loc_gettocken == OPEN_ARCH )
	{
		res = Get_Tocken();
		if (res == IDIENTIFIER_YES)
		{
			//call identifier handler
			Syntax_Handler(0);
		}
		else if (res ==INT_NUM || res == FLOAT_NUM )
		{
			// call syntax number function
			Syntax_Number (0);
		}
		else if(res == ASTRICS )
		{
			// call syntax pointer function
		    Syntax_Pointer();
		}
		else 
		{
			 printf("syntax error in line %d\n",line); 
		}
	}
	   res  = Get_Tocken();
	if (res == SEMI_COMMA)
	{
		printf ("you got ; end of statment\n");
		return;
	}
	else{
		 printf("syntax error in line %d\n",line); 
	}
	}
	else 
	{
		printf("%d:  error: expected ';' before '{' token",line); 
		exit(1);
	}
}

