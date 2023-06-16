%option noyywrap
%{
	#include<stdio.h>
%}

%%
[a-z . 0-9]+@[a-z]+".com"|".in" {printf("valid email");}
.+ {printf("Not valid");}
%%
int main()
{
	yylex();
	return 0;
}
