%{
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "HTML2AST.h"

using namespace std;

extern int yylex();
void yyerror(const char *s);
extern char* yytext;

AST htmlAst;
shared_ptr<ASTNode> currentNode = nullptr;
extern FILE* yyin;
void reset_parser();
%}

%union {
    char* text;
}

%token <text> TEXT IMG A_OPEN
%token HTML_OPEN HTML_CLOSE HEAD_OPEN HEAD_CLOSE TITLE_OPEN TITLE_CLOSE
%token BODY_OPEN BODY_CLOSE NAV_OPEN NAV_CLOSE UL_OPEN UL_CLOSE
%token LI_OPEN LI_CLOSE HEADER_OPEN HEADER_CLOSE H1_OPEN H1_CLOSE
%token H2_OPEN H2_CLOSE H3_OPEN H3_CLOSE H4_OPEN H4_CLOSE
%token H5_OPEN H5_CLOSE P_OPEN P_CLOSE SECTION_OPEN SECTION_CLOSE
%token ARTICLE_OPEN ARTICLE_CLOSE ASIDE_OPEN ASIDE_CLOSE
%token FOOTER_OPEN FOOTER_CLOSE A_CLOSE
%token STRONG_OPEN STRONG_CLOSE EM_OPEN EM_CLOSE U_OPEN U_CLOSE
%token SMALL_OPEN SMALL_CLOSE BLOCKQUOTE_OPEN BLOCKQUOTE_CLOSE
%token PRE_OPEN PRE_CLOSE CODE_OPEN CODE_CLOSE OL_OPEN OL_CLOSE

%%

document:
    HTML_OPEN { startElement("html"); } 
    head body 
    HTML_CLOSE { endElement(); }
    ;

head:
    HEAD_OPEN { startElement("head"); }
    title 
    HEAD_CLOSE { endElement(); }
    ;

title:
    TITLE_OPEN TEXT TITLE_CLOSE { startElement("title"); addContent($2); free($2); endElement(); }
    ;

body:
    BODY_OPEN { startElement("body"); }
    elements 
    BODY_CLOSE { endElement(); }
    ;

elements:
    element elements
    | /* empty */
    ;

element:
    nav | ul | li | a | text | header | h1 | h2 | h3 | h4 | h5 | p | section 
    | article | strong | em | u | small | blockquote | pre | code | ol | aside 
    | footer | img
    ;

nav:
    NAV_OPEN { startElement("nav"); }
    elements 
    NAV_CLOSE { endElement(); }
    ;

ul:
    UL_OPEN { startElement("ul"); }
    elements 
    UL_CLOSE { endElement(); }
    ;

li:
    LI_OPEN { startElement("li"); }
    elements 
    LI_CLOSE { endElement(); }
    ;

a:
    A_OPEN { startElement("a", $1); free($1); }
    elements 
    A_CLOSE { endElement(); }
    ;

header:
    HEADER_OPEN { startElement("header"); }
    elements 
    HEADER_CLOSE { endElement(); }
    ;

h1:
    H1_OPEN { startElement("h1"); }
    elements 
    H1_CLOSE { endElement(); }
    ;

h2:
    H2_OPEN { startElement("h2"); }
    elements 
    H2_CLOSE { endElement(); }
    ;

h3:
    H3_OPEN { startElement("h3"); }
    elements 
    H3_CLOSE { endElement(); }
    ;

h4:
    H4_OPEN { startElement("h4"); }
    elements 
    H4_CLOSE { endElement(); }
    ;

h5:
    H5_OPEN { startElement("h5"); }
    elements 
    H5_CLOSE { endElement(); }
    ;

p:
    P_OPEN { startElement("p"); }
    elements 
    P_CLOSE { endElement(); }
    ;

section:
    SECTION_OPEN { startElement("section"); }
    elements 
    SECTION_CLOSE { endElement(); }
    ;

article:
    ARTICLE_OPEN { startElement("article"); }
    elements 
    ARTICLE_CLOSE { endElement(); }
    ;

strong:
    STRONG_OPEN { startElement("strong"); }
    elements 
    STRONG_CLOSE { endElement(); }
    ;

em:
    EM_OPEN { startElement("em"); }
    elements 
    EM_CLOSE { endElement(); }
    ;

u:
    U_OPEN { startElement("u"); }
    elements 
    U_CLOSE { endElement(); }
    ;

small:
    SMALL_OPEN { startElement("small"); }
    elements 
    SMALL_CLOSE { endElement(); }
    ;

blockquote:
    BLOCKQUOTE_OPEN { startElement("blockquote"); }
    elements 
    BLOCKQUOTE_CLOSE { endElement(); }
    ;

pre:
    PRE_OPEN { startElement("pre"); }
    elements 
    PRE_CLOSE { endElement(); }
    ;

code:
    CODE_OPEN { startElement("code"); }
    elements 
    CODE_CLOSE { endElement(); }
    ;

ol:
    OL_OPEN { startElement("ol"); }
    elements 
    OL_CLOSE { endElement(); }
    ;

aside:
    ASIDE_OPEN { startElement("aside"); }
    elements 
    ASIDE_CLOSE { endElement(); }
    ;

footer:
    FOOTER_OPEN { startElement("footer"); }
    elements 
    FOOTER_CLOSE { endElement(); }
    ;

img:
    IMG { 
        startElement("img", $1);
        endElement();
        free($1);
    }
    ;

text:
    TEXT {
        startElement("text"); 
        addContent($1);
        free($1);
        endElement();
    }
    ;

%%

void yyerror(const char *s) {
    cerr << "Error: " << s << endl;
}

void reset_parser() {
    currentNode = nullptr;
    htmlAst = AST();
}
