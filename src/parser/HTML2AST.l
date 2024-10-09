%{
#include <string>
#include <cstring>
#include "HTML2AST.h"
#include "HTML2AST.tab.hpp"

using namespace std;
%}

%option noyywrap

%%

"<!DOCTYPE html>"                               { /* ignore */ }
"<html>"                                        { return HTML_OPEN; }
"</html>"                                       { return HTML_CLOSE; }
"<head>"                                        { return HEAD_OPEN; }
"</head>"                                       { return HEAD_CLOSE; }
"<title>"                                       { return TITLE_OPEN; }
"</title>"                                      { return TITLE_CLOSE; }
"<body>"                                        { return BODY_OPEN; }
"</body>"                                       { return BODY_CLOSE; }
"<nav>"                                         { return NAV_OPEN; }
"</nav>"                                        { return NAV_CLOSE; }
"<ul>"                                          { return UL_OPEN; }
"</ul>"                                         { return UL_CLOSE; }
"<li>"                                          { return LI_OPEN; }
"</li>"                                         { return LI_CLOSE; }
"<header>"                                      { return HEADER_OPEN; }
"</header>"                                     { return HEADER_CLOSE; }
"<h1>"                                          { return H1_OPEN; }
"</h1>"                                         { return H1_CLOSE; }
"<h2>"                                          { return H2_OPEN; }
"</h2>"                                         { return H2_CLOSE; }
"<h3>"                                          { return H3_OPEN; }
"</h3>"                                         { return H3_CLOSE; }
"<h4>"                                          { return H4_OPEN; }
"</h4>"                                         { return H4_CLOSE; }
"<h5>"                                          { return H5_OPEN; }
"</h5>"                                         { return H5_CLOSE; }
"<p>"                                           { return P_OPEN; }
"</p>"                                          { return P_CLOSE; }
"<section>"                                     { return SECTION_OPEN; }
"</section>"                                    { return SECTION_CLOSE; }
"<article>"                                     { return ARTICLE_OPEN; }
"</article>"                                    { return ARTICLE_CLOSE; }
"<aside>"                                       { return ASIDE_OPEN; }
"</aside>"                                      { return ASIDE_CLOSE; }
"<footer>"                                      { return FOOTER_OPEN; }
"</footer>"                                     { return FOOTER_CLOSE; }
"<a"[^>]*">"                                    { yylval.text = strdup(yytext); return A_OPEN; }
"</a>"                                          { return A_CLOSE; }
"<img"[^>]*">"                                  { yylval.text = strdup(yytext); return IMG; }
"<strong>"                                      { return STRONG_OPEN; }
"</strong>"                                     { return STRONG_CLOSE; }
"<em>"                                          { return EM_OPEN; }
"</em>"                                         { return EM_CLOSE; }
"<u>"                                           { return U_OPEN; }
"</u>"                                          { return U_CLOSE; }
"<small>"                                       { return SMALL_OPEN; }
"</small>"                                      { return SMALL_CLOSE; }
"<blockquote>"                                  { return BLOCKQUOTE_OPEN; }
"</blockquote>"                                 { return BLOCKQUOTE_CLOSE; }
"<pre>"                                         { return PRE_OPEN; }
"</pre>"                                        { return PRE_CLOSE; }
"<code>"                                        { return CODE_OPEN; }
"</code>"                                       { return CODE_CLOSE; }
"<ol>"                                          { return OL_OPEN; }
"</ol>"                                         { return OL_CLOSE; }
[^\n<>]+                                        { yylval.text = strdup(yytext); return TEXT; }
[ \t\n]+                                        { /* ignore whitespace */ }
.                                               { /* ignore */ }

%%
