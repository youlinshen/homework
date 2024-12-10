## I. A cover page.
### 用bison 和 flex 分析 T語言 <br>
姓名 沈佑霖<br>
學號 411211313<br>
日期 113/12/07<br>
課程 程式語言原理與典型<br>

## II. The problem description.
Use lex (or flex) and yacc (or bison) to implement a front end (including a lexical
analyzer and a syntax recognizer) of the compiler for the T language, showing the
grammar rules applied while parsing.<br>
Ø See an attached file for the lexical rules in details.<br>
Ø You are requested to separate the C code, the Lex specification, the Yacc
specification into distinct files.<br>
## III. Highlight of the way you write the program.
根據上課的講義和上網參考資料,使用老師提供的範例和測試檔案來完成剩下的部分並測試. 

> bison -d -o t_parse.c t_parse.y &emsp;&emsp;// &emsp; t_parse.c &nbsp;t_parse.h<br>
flex -ot_lex.c t_lex.l &emsp;&emsp;// &emsp; t_lex.c<br

>gcc -c t_lex.c  &emsp;&emsp;// &emsp;t_lex.o<br>
gcc -c t_parse.c &emsp;&emsp; // &emsp; t_paqrse.o<br>
gcc -c t2c.c emsp;&emsp; // &emsp; t2c.o<br>
gcc -o parse &nbsp;t_lex.o &nbsp;t2c.o &nbsp;t_parse.o emsp;&emsp; // &emsp; parse<br>

>./parse test.t &emsp;&emsp;// &emsp; 執行 parse 用test.t 測試

## IV. The program listing.

>t_lex.l

    %{
    #include "t2c.h"
    #include "t_parse.h"
    %}

    %x C_COMMENT

    ID  [A-Za-z][A-Za-z0-9]*
    DIG [0-9][0-9]*
    RNUM {DIG}"."{DIG}
    NQUO [^"]

    %%

    WRITE		{return lWRITE;}
    READ		{return lREAD;}
    IF		{return lIF;}
    ELSE		{return lELSE;}
    RETURN		{return lRETURN;}
    BEGIN		{return lBEGIN;}
    END		{return lEND;}
    MAIN		{return lMAIN;}
    INT		{return lINT;}
    REAL		{return lREAL;}
    ";"		{return lSEMI;}
    ","		{return lCOMMA;}
    "("		{return lLP;}
    ")"		{return lRP;}
    "+"		{return lADD;}
    "-"		{return lMINUS;}
    "*"		{return lTIMES;}
    "/"		{return lDIVIDE;}
    ">"		{return lGT;}
    "<"		{return lLT;}
    ":="		{return lASSIGN;}
    "=="		{return lEQU;}
    "!="		{return lNEQ;}
    ">="		{return lGE;}
    "<="		{return lLE;}

    [a-zA-Z][a-zA-Z0-9]*        {return lID;}
    [0-9]+    {return lINUM;}
    [0-9]+\.[0-9]+      {return lRNUM;}



    \"{NQUO}*\"	{sscanf(yytext,"%s", qstr); return lQSTR;}
    "/*"		{ BEGIN(C_COMMENT); }
    <C_COMMENT>"*/"	{ BEGIN(INITIAL); }
    <C_COMMENT>\n	{ }
    <C_COMMENT>.	{ }
    [ \t\n]		{}
    .		{}

    %%

    int yywrap() {return 1;}

    void print_lex( int t ) {
        switch( t ) {
        case lWRITE: printf("WRITE\n");
            break;
        case lREAD: printf("READ\n");
            break;
        case lIF: printf("IF\n");
            break;
        case lELSE: printf("ELSE\n");
            break;
        case lRETURN: printf("RETURN\n");
            break;
        case lBEGIN: printf("BEGIN\n");
            break;
        case lEND: printf("END\n");
            break;
        case lMAIN: printf("MAIN\n");
            break;
        case lSTRING: printf("STRING\n");
            break;
        case lINT: printf("INT\n");
            break;
        case lREAL: printf("REAL\n");
            break;
        case lSEMI: printf("SEMI\n");
            break;
        case lCOMMA: printf("COMMA\n");
            break;
        case lLP: printf("LP\n");
            break;
        case lRP: printf("RP\n");
            break;
        case lADD: printf("ADD\n");
            break;
        case lMINUS: printf("MINUS\n");
            break;
        case lTIMES: printf("TIMES\n");
            break;
        case lDIVIDE: printf("DIVIDE\n");
            break;
        case lASSIGN: printf("ASSIGN\n");
            break;
        case lEQU: printf("EQU\n");
            break;
        case lNEQ: printf("NEQ\n");
            break;
        case lID: printf("ID(%s)\n", name);
            break;
        case lINUM: printf("INUM(%d)\n", ival);
            break;
        case lRNUM: printf("RNUM(%f)\n", rval);
            break;
        case lQSTR: printf("QSTR(%s)\n", qstr);
            break;
        default: printf("******** lexical error!!!");
        }
    }

>t_parse.y

    %{
        #include <stdio.h>
        #include <stdlib.h>
        #include "t2c.h"
        #include "t_parse.h"
    %}

    %token lWRITE lREAD lIF lASSIGN
    %token lRETURN lBEGIN lEND
    %left  lEQU lNEQ lGT lLT lGE lLE
    %left  lADD lMINUS
    %left  lTIMES lDIVIDE
    %token lLP lRP
    %token lINT lREAL lSTRING
    %token lELSE
    %token lMAIN
    %token lSEMI lCOMMA
    %token lID lINUM lRNUM lQSTR

    %expect 1

    %%
    prog	:	mthdcls
            { printf("Program -> MethodDecls\n");
            printf("Parsed OK!\n"); }
        |
            { printf("****** Parsing failed!\n"); }	
        ;

    mthdcls	:	mthdcl mthdcls
            { printf("MethodDecls -> MethodDecl MethodDecls\n"); }	
        |	mthdcl
            { printf("MethodDecls -> MethodDecl\n"); }	
        ;

    type	:	lINT
            { printf("Type -> INT\n"); }	
        |	lREAL
            { printf("Type -> REAL\n"); }	
        ;

    mthdcl	:	type lMAIN lID lLP formals lRP block
            { printf("MethodDecl -> Type MAIN ID LP Formals RP Block\n"); }	
        |	type lID lLP formals lRP block
            { printf("MethodDecl -> Type ID LP Formals RP Block\n"); }	
        ;

    formals	:	formal oformal
            { printf("Formals -> Formal OtherFormals\n"); }	
        |
            { printf("Formals -> \n"); }	
        ;

    formal	:	type lID
            { printf("Formal -> Type ID\n"); }	
        ;

    oformal	:	lCOMMA formal oformal
            { printf("OtherFormals -> COMMA Formal OtherFormals\n"); }	
        |
            { printf("OtherFormals -> \n"); }	
        ;

    block   : lBEGIN statements lEND
            { printf("Block -> BEGIN Statements END\n"); }
        ;

    statements : statement statements
            { printf("Statements -> Statement Statements\n"); }
        | statement
            { printf("Statements -> Statement\n"); }
        ;

    statement : block
            { printf("Statement -> Block\n"); }
        | localvar_decl
            { printf("Statement -> LocalVarDecl\n"); }
        | assign_stmt
            { printf("Statement -> AssignStmt\n"); }
        | return_stmt
            { printf("Statement -> ReturnStmt\n"); }
        | if_stmt
            { printf("Statement -> IfStmt\n"); }
        | write_stmt
            { printf("Statement -> WriteStmt\n"); }
        | read_stmt
            { printf("Statement -> ReadStmt\n"); }
        ;

    localvar_decl : type lID lSEMI
            { printf("LocalVarDecl -> Type ID ;\n"); }
        | type lID lASSIGN expression lSEMI
            { printf("LocalVarDecl -> Type ID := Expression ;\n"); }
        ;

    assign_stmt : lID lASSIGN expression lSEMI
            { printf("AssignStmt -> ID := Expression ;\n"); }
        ;

    return_stmt : lRETURN expression lSEMI
            { printf("ReturnStmt -> RETURN Expression ;\n"); }
        ;

    if_stmt : lIF lLP bool_expr lRP statement
            { printf("IfStmt -> IF ( BoolExpr ) Statement\n"); }
        | lIF lLP bool_expr lRP statement lELSE statement
            { printf("IfStmt -> IF ( BoolExpr ) Statement ELSE Statement\n"); }
        ;

    write_stmt : lWRITE lLP expression lCOMMA lQSTR lRP lSEMI
            { printf("WriteStmt -> WRITE ( Expression , QString ) ;\n"); }
        ;

    read_stmt : lREAD lLP lID lCOMMA lQSTR lRP lSEMI
            { printf("ReadStmt -> READ ( ID , QString ) ;\n"); }
        ;

    expression : multiplicative_expr
            { printf("Expression -> MultiplicativeExpr\n"); }
        | expression lADD multiplicative_expr
            { printf("Expression -> Expression + MultiplicativeExpr\n"); }
        | expression lMINUS multiplicative_expr
            { printf("Expression -> Expression - MultiplicativeExpr\n"); }
        ;

    multiplicative_expr : primary_expr
            { printf("MultiplicativeExpr -> PrimaryExpr\n"); }
        | multiplicative_expr lTIMES primary_expr
            { printf("MultiplicativeExpr -> MultiplicativeExpr * PrimaryExpr\n"); }
        | multiplicative_expr lDIVIDE primary_expr
            { printf("MultiplicativeExpr -> MultiplicativeExpr / PrimaryExpr\n"); }
        ;

    primary_expr : lINUM
            { printf("PrimaryExpr -> Integer\n"); }
        | lRNUM
            { printf("PrimaryExpr -> Real\n"); }
        | lID
            { printf("PrimaryExpr -> ID\n"); }
        | lLP expression lRP
            { printf("PrimaryExpr -> ( Expression )\n"); }
        | lID lLP actual_params lRP
            { printf("PrimaryExpr -> ID ( ActualParams )\n"); }
        ;

    bool_expr : expression lEQU expression
            { printf("BoolExpr -> Expression == Expression\n"); }
        | expression lNEQ expression
            { printf("BoolExpr -> Expression != Expression\n"); }
        | expression lGT expression
            { printf("BoolExpr -> Expression > Expression\n"); }
        | expression lGE expression
            { printf("BoolExpr -> Expression >= Expression\n"); }
        | expression lLT expression
            { printf("BoolExpr -> Expression < Expression\n"); }
        | expression lLE expression
            { printf("BoolExpr -> Expression <= Expression\n"); }
        ;

    actual_params : expression
            { printf("ActualParams -> Expression\n"); }
        | actual_params lCOMMA expression
            { printf("ActualParams -> Expression , ActualParams\n"); }
        ;
    // Statements and Expressions

    %%

    int yyerror(char *s)
    {
        printf("%s\n",s);
        return 1;
    }

>t2c.c

    #include <stdio.h>
    #include "t2c.h"
    #include "t_parse.h"

    char name[16];
    int ival;
    float rval;
    char qstr[80];

    int main(int argc,char *argv[]) {
        int t;

        yyin = fopen(argv[1],"r");
        t = yyparse();
    }



## V. Test run results.

>./parse test.t 

    Type -> INT
    Type -> INT
    Formal -> Type ID
    Type -> INT
    Formal -> Type ID
    OtherFormals -> 
    OtherFormals -> COMMA Formal OtherFormals
    Formals -> Formal OtherFormals
    Type -> INT
    LocalVarDecl -> Type ID ;
    Statement -> LocalVarDecl
    PrimaryExpr -> ID
    MultiplicativeExpr -> PrimaryExpr
    PrimaryExpr -> ID
    MultiplicativeExpr -> MultiplicativeExpr * PrimaryExpr
    Expression -> MultiplicativeExpr
    PrimaryExpr -> ID
    MultiplicativeExpr -> PrimaryExpr
    PrimaryExpr -> ID
    MultiplicativeExpr -> MultiplicativeExpr * PrimaryExpr
    Expression -> Expression - MultiplicativeExpr
    AssignStmt -> ID := Expression ;
    Statement -> AssignStmt
    PrimaryExpr -> ID
    MultiplicativeExpr -> PrimaryExpr
    Expression -> MultiplicativeExpr
    ReturnStmt -> RETURN Expression ;
    Statement -> ReturnStmt
    Statements -> Statement
    Statements -> Statement Statements
    Statements -> Statement Statements
    Block -> BEGIN Statements END
    MethodDecl -> Type ID LP Formals RP Block
    Type -> INT
    Formals -> 
    Type -> INT
    LocalVarDecl -> Type ID ;
    Statement -> LocalVarDecl
    ReadStmt -> READ ( ID , QString ) ;
    Statement -> ReadStmt
    Type -> INT
    LocalVarDecl -> Type ID ;
    Statement -> LocalVarDecl
    ReadStmt -> READ ( ID , QString ) ;
    Statement -> ReadStmt
    Type -> INT
    LocalVarDecl -> Type ID ;
    Statement -> LocalVarDecl
    PrimaryExpr -> ID
    MultiplicativeExpr -> PrimaryExpr
    Expression -> MultiplicativeExpr
    ActualParams -> Expression
    PrimaryExpr -> ID
    MultiplicativeExpr -> PrimaryExpr
    Expression -> MultiplicativeExpr
    ActualParams -> Expression , ActualParams
    PrimaryExpr -> ID ( ActualParams )
    MultiplicativeExpr -> PrimaryExpr
    Expression -> MultiplicativeExpr
    PrimaryExpr -> ID
    MultiplicativeExpr -> PrimaryExpr
    Expression -> MultiplicativeExpr
    ActualParams -> Expression
    PrimaryExpr -> ID
    MultiplicativeExpr -> PrimaryExpr
    Expression -> MultiplicativeExpr
    ActualParams -> Expression , ActualParams
    PrimaryExpr -> ID ( ActualParams )
    MultiplicativeExpr -> PrimaryExpr
    Expression -> Expression + MultiplicativeExpr
    AssignStmt -> ID := Expression ;
    Statement -> AssignStmt
    PrimaryExpr -> ID
    MultiplicativeExpr -> PrimaryExpr
    Expression -> MultiplicativeExpr
    WriteStmt -> WRITE ( Expression , QString ) ;
    Statement -> WriteStmt
    Statements -> Statement
    Statements -> Statement Statements
    Statements -> Statement Statements
    Statements -> Statement Statements
    Statements -> Statement Statements
    Statements -> Statement Statements
    Statements -> Statement Statements
    Block -> BEGIN Statements END
    MethodDecl -> Type MAIN ID LP Formals RP Block
    MethodDecls -> MethodDecl
    MethodDecls -> MethodDecl MethodDecls
    Program -> MethodDecls
    Parsed OK!

>./parse test2.t

    Type -> INT
    Formals -> 
    Type -> REAL
    LocalVarDecl -> Type ID ;
    Statement -> LocalVarDecl
    ReadStmt -> READ ( ID , QString ) ;
    Statement -> ReadStmt
    Type -> REAL
    PrimaryExpr -> Real
    MultiplicativeExpr -> PrimaryExpr
    Expression -> MultiplicativeExpr
    LocalVarDecl -> Type ID := Expression ;
    Statement -> LocalVarDecl
    PrimaryExpr -> ID
    MultiplicativeExpr -> PrimaryExpr
    Expression -> MultiplicativeExpr
    WriteStmt -> WRITE ( Expression , QString ) ;
    Statement -> WriteStmt
    Statements -> Statement
    Statements -> Statement Statements
    Statements -> Statement Statements
    Statements -> Statement Statements
    Block -> BEGIN Statements END
    MethodDecl -> Type MAIN ID LP Formals RP Block
    MethodDecls -> MethodDecl
    Program -> MethodDecls
    Parsed OK!


## VI. Discussion.


這個程式可以測試是否符合語法規範.以後應該要增加註解提高可讀性