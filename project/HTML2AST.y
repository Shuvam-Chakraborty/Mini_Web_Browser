%{
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "HTML2AST.h"
#include<fstream>
#include <sstream>
#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h>           
#include <unistd.h>  
#include <semaphore.h>
#include <cstdio>   
#include <thread>



using namespace std;

extern int yylex();
void yyerror(const char *s);
extern char* yytext;
extern int yyparse(void);
extern FILE* yyin;

// Initialize global AST
AST htmlAst;
shared_ptr<ASTNode> currentNode = nullptr;
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
      nav | ul | li | a | text | header | h1 | h2 | h3 | h4 | h5 | p | section | article | strong | em | u | small | blockquote | pre | code | ol | aside | footer | img
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

//consumer

void* ptr2;
int out=0;
sem_t* emp ;
sem_t* filled ;
sem_t* bsem ;

int n;

//producer functions and vars
void* ptr2_dup;
int in_dup=0;
sem_t* emp_dup ;
sem_t* filled_dup ;
sem_t* bsem_dup ;



#define SIZE_OF_PAGE 20*1024


//producer for html.y
// void* ptr2_dup;
// int in_dup=0;
// sem_t* emp_dup ;
// sem_t* filled_dup ;
// sem_t* bsem_dup ;


void printstring_from_buffer(void* ptr,int index){
     cout<<((char*)ptr)+SIZE_OF_PAGE*index<< endl;
    return;
}


void copystring_to_buffer(void*ptr, string temp,int index){

    strcpy(static_cast<char*>(ptr)+SIZE_OF_PAGE*index, temp.c_str());

    return;
}


string calling_parser(){
    ofstream outputFile("example"+ to_string(out)+".txt");

    outputFile << ((char*)ptr2)+SIZE_OF_PAGE*out;
    outputFile.close();

    FILE* file = fopen(("example"+ to_string(out)+".txt").c_str(), "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    // Set Flex's input source to the file
    yyin = file;

    // Parse the input
    yyparse();
    htmlAst.writeToFile("example_ast"+ to_string(out)+".txt");

    // Close the file
    fclose(file);

    ifstream inputFile("example_ast"+ to_string(out)+".txt");

    string fileContents((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

    inputFile.close();

    //deleting the previous file
    const char* filename = ("example"+ to_string(out)+".txt").c_str();
    remove(filename);
    remove(("example_ast"+ to_string(out)+".txt").c_str());
    return fileContents;

}





void consumer_func(){

    string ast;
    while(1)
    {

        sem_wait(filled);
        sem_wait(bsem);

        ast=calling_parser();

        
        //cout<<ast<<endl;
        

        out=(out+1)%n;


        

        

        sem_post(bsem);
        sem_post(emp);

        //cout<<ast;
        sem_wait(emp_dup);
        sem_wait(bsem_dup);
        
        copystring_to_buffer(ptr2_dup,ast,in_dup);
        //printstring_from_buffer(ptr2_dup,in_dup);
        //cout<<ast;
        in_dup=(in_dup+1)%n;
        

        sem_post(bsem_dup);
        sem_post(filled_dup);

        //cout<<ast;


    }

    

}





//bison -d -o HTML2AST.tab.cpp HTML2AST.y
//flex -o HTML2AST.lex.cpp HTML2AST.l
//g++ HTML2AST.tab.cpp HTML2AST.lex.cpp HTML2AST.h -o consumer
 int main() {
     
    const char* n_shared_name = "/size_of_buffer";
    int shm_fd1 = shm_open(n_shared_name, O_RDWR, 0666);
    void* ptr1 = mmap(0, sizeof(int), PROT_READ, MAP_SHARED, shm_fd1, 0);
    

    n=*((int*)(ptr1));
    //shared memory storing strings
    const char* storing_web_pages = "/strings";
    int shm_fd2 = shm_open(storing_web_pages,O_RDWR, 0666);  
    ptr2 = mmap(0, SIZE_OF_PAGE*n*sizeof(char), PROT_WRITE, MAP_SHARED, shm_fd2, 0);
    

    //html.y will put data into following 

    //shared memory storing strings
    const char* asts = "/asts";
    shm_unlink(asts);

    int shm_fd2_dup = shm_open(asts, O_CREAT | O_RDWR, 0666);  

    //size of memory is 20*1024*40(each webpage can have atmost 20*1024 characters and we could have atmost 40 webpages)
    ftruncate(shm_fd2_dup, SIZE_OF_PAGE*n*sizeof(char));  
    ptr2_dup = mmap(0, SIZE_OF_PAGE*n*sizeof(char), PROT_WRITE, MAP_SHARED, shm_fd2_dup, 0);



    emp = sem_open("/emp", 0);
    filled = sem_open("/filled", 0);
    bsem = sem_open("/bsem", 0);

    //unlinking if we already have the semophore with same name
    sem_unlink("/emp_dup");
    sem_unlink("/filled_dup");
    sem_unlink("/bsem_dup");

    //semophores have to be declared before forking the consumer
    emp_dup = sem_open("/emp_dup", O_CREAT, 0644, n);
    filled_dup = sem_open("/filled_dup", O_CREAT, 0644, 0);
    bsem_dup = sem_open("/bsem_dup", O_CREAT, 0644, 1);

    pid_t pid1 =fork();  

    if (pid1 == 0) 
    {
        //cout<<"hello\n";
        char *args[] = {nullptr};
        execvp("./ASTRenderer", args);  
        
        
    }

    
    vector<thread> threadVector;
    int number_of_threads;
    
    int thres=10;

    while(thres)

    while(1){
        
        if(opinion=='y'||opinion=='Y')
            threadVector.push_back(thread(consumer_func));
        else
            goto joining_threads;
    }

    joining_threads:
    
    for (auto& temp : threadVector) {
        
            temp.join();
        
    }



    



    
    munmap(ptr1, sizeof(int));
    close(shm_fd1);
    shm_unlink(n_shared_name);

    munmap(ptr2, SIZE_OF_PAGE*n*sizeof(char));
    close(shm_fd2);
    shm_unlink(storing_web_pages);

    munmap(ptr2_dup, SIZE_OF_PAGE*n*sizeof(char));
    close(shm_fd2_dup);

    return 0;

    
 }
