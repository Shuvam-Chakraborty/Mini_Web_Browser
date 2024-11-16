#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMap>
#include <QStack>
#include <QScrollArea>
#include <QFont>
#include <QPushButton>
#include <QFrame>
#include <QPair>
#include <QTextBrowser>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QTextListFormat>
#include <QTextDocument>
#include <QDesktopServices>
#include <QUrl>
#include <QSet>
#include <QTextBlock>
#include <QTextList>


#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>

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

void* ptr2;
int out=0;
sem_t* emp ;
sem_t* filled ;
sem_t* bsem ;


int n;


#define SIZE_OF_PAGE 20*1024

struct ASTNode {
    QString tag;
    QString content;
    int indentLevel;
    QList<ASTNode*> children;
    
    ASTNode(const QString& t, const QString& c, int level) 
        : tag(t), content(c), indentLevel(level) {}
    
    ~ASTNode() {
        qDeleteAll(children);
    }
};

class MiniBrowser : public QMainWindow {
    Q_OBJECT

public:
    MiniBrowser(ASTNode* root, QWidget* parent = nullptr) : QMainWindow(parent) {
        QWidget* centralWidget = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);
        textBrowser = new QTextBrowser(this);
        layout->addWidget(textBrowser);
        
        textBrowser->setOpenLinks(false);
        textBrowser->setOpenExternalLinks(true);
        textBrowser->setReadOnly(true);
        textBrowser->document()->setDefaultStyleSheet(defaultCSS);
        
        connect(textBrowser, &QTextBrowser::anchorClicked, this, &MiniBrowser::handleLink);
        
        QTextCursor cursor(textBrowser->document());
        renderAST(root, cursor);
        
        setCentralWidget(centralWidget);
        resize(800, 600);
    }

private slots:
    void handleLink(const QUrl& url) {
        QString href = url.toString();
        if (href.startsWith("#")) {
            QString anchor = href.mid(1);
        } else {
            QDesktopServices::openUrl(url);
        }
    }

private:
    QTextBrowser* textBrowser;

    void renderAST(ASTNode* root, QTextCursor& cursor) {
        if (!root) return;
        renderElement(root, cursor);
    }

    bool inList = false;
    bool inOrderedList = false;
    bool inNavigation = false;
    int currentListNumber = 1;
    bool inParagraph = false;
    bool inPreformatted = false;
    bool inBlockquote = false;
    QStack<QString> tagStack;

	void renderElement(ASTNode* node, QTextCursor& cursor) {
	    if (!node) return;
	    
	    tagStack.push(node->tag);
	    
	    QTextBlockFormat blockFormat = cursor.blockFormat();
	    
	    if (node->tag == "ul" || node->tag == "ol") {
	        inList = true;
	        inOrderedList = (node->tag == "ol");
	        currentListNumber = 1;
	        blockFormat.setLeftMargin(10);
	        blockFormat.setTopMargin(10);
	        cursor.setBlockFormat(blockFormat);
	    }
	    else if (node->tag == "li") {
	        QTextCharFormat format;
	        blockFormat.setLeftMargin(40);
	        cursor.setBlockFormat(blockFormat);
	        
	        format.setForeground(QBrush(Qt::black));
	        if (inOrderedList) {
	            cursor.insertText(QString::number(currentListNumber++) + ". ", format);
	        } else if (inList) {
	            cursor.insertText(QString(QChar(0x2022)) + " ", format);
	        }
	    }
	    else if (node->tag == "nav") {
	        inNavigation = true;
	        blockFormat.setBackground(QBrush(QColor("#f8f9fa")));
	        blockFormat.setTopMargin(10);
	        blockFormat.setBottomMargin(20);
	        cursor.setBlockFormat(blockFormat);
	    }
	    else if (node->tag == "p") {
	        inParagraph = true;
	        blockFormat.setTopMargin(10);
	        blockFormat.setBottomMargin(10);
	        cursor.setBlockFormat(blockFormat);
	    }
	    else if (node->tag == "pre" || node->tag == "code") {
		    inPreformatted = true;
		    QTextCharFormat format;
		    format.setFontFamily("Courier New");
		    format.setFontPointSize(10);
		    format.setBackground(QBrush(QColor("#f0f0f0")));
		    format.setForeground(QBrush(Qt::black));
		    cursor.setCharFormat(format);
		    
		    QTextBlockFormat blockFormat = cursor.blockFormat();
		    blockFormat.setTopMargin(5);
		    blockFormat.setBottomMargin(5);
		    blockFormat.setLeftMargin(20);
		    cursor.setBlockFormat(blockFormat);
		}
	    else if (node->tag == "blockquote") {
	        inBlockquote = true;
	        blockFormat.setLeftMargin(40);
	        blockFormat.setBackground(QBrush(QColor("#f9f9f9")));
	        cursor.setBlockFormat(blockFormat);
	    }
	    else if (node->tag == "text") {
	        QTextCharFormat format;
	        
	        bool isLinkText = tagStack.contains("a");
	        
	        if (isLinkText) {
	            format.setForeground(QBrush(QColor("#0366d6")));
	            format.setFontUnderline(true);
	            format.setAnchor(true);
	        }
	        
	        for (const QString& tag : tagStack) {
	            if (tag == "strong") format.setFontWeight(QFont::Bold);
	            else if (tag == "em") format.setFontItalic(true);
	            else if (tag == "u") format.setFontUnderline(true);
	            else if (tag == "small") format.setFontPointSize(8);
	            else if (tag.startsWith("h") && tag.length() == 2) {
	                int level = tag[1].digitValue();
	                if (level >= 1 && level <= 5) {
	                    format.setFontWeight(QFont::Bold);
	                    format.setFontPointSize(24 - (level * 2));
	                }
	            }
	        }
	        
	        if (inPreformatted) {
			    format.setFontFamily("Courier New");
			    format.setFontPointSize(10);
			    format.setBackground(QBrush(QColor("#f0f0f0")));
			    format.setForeground(QBrush(Qt::black));
			}
	
	        if (inParagraph) {
	            cursor.insertText(node->content + " ", format);
	        } else {
	            cursor.insertText(node->content + "\n", format);
	        }
	    }
	    else if (node->tag == "img") {
	        QTextImageFormat imageFormat;
	        imageFormat.setWidth(150);
	        imageFormat.setHeight(150);
	        imageFormat.setName(QString("[Image: %1]").arg(node->content));
	        cursor.insertImage(imageFormat);
	    }
	    else if (node->tag.startsWith("h") && node->tag.length() == 2) {
	        blockFormat.setTopMargin(15);
	        blockFormat.setBottomMargin(15);
	        cursor.setBlockFormat(blockFormat);
	    }
	    
	    for (ASTNode* child : node->children) {
	        renderElement(child, cursor);
	    }
	    
	    if (node->tag == "p") {
	        cursor.insertText("\n");
	        inParagraph = false;
	    } else if (node->tag == "pre" || node->tag == "code") {
	        cursor.insertText("\n");
	    }
	    
	    if (node->tag == "nav") inNavigation = false;
	    else if (node->tag == "ul" || node->tag == "ol") {
	        inList = false;
	        inOrderedList = false;
	        currentListNumber = 1;
	        blockFormat.setLeftMargin(0);
	        cursor.setBlockFormat(blockFormat);
	    }
	    else if (node->tag == "li") {
	        blockFormat.setLeftMargin(40);
	        cursor.setBlockFormat(blockFormat);
	    }
	    else if (node->tag == "pre" || node->tag == "code") inPreformatted = false;
	    else if (node->tag == "blockquote") inBlockquote = false;
	    
	    tagStack.pop();
	}
	
    const QString defaultCSS = R"(
        body { line-height: 1.6; }
        blockquote { 
            margin: 15px 0 15px 20px;
            padding: 10px;
            border-left: 3px solid #ccc;
            background-color: #f9f9f9;
            font-style: italic;
        }
        pre { 
            font-family: monospace;
            background-color: #f0f0f0;
            padding: 15px;
            margin: 15px 0;
            border-radius: 5px;
        }
        a { color: #0066cc; text-decoration: underline; }
        small { font-size: 80%; }
        p { margin: 10px 0; }
        ul, ol { 
            margin: 10px 0;
            padding-left: 0;
        }
        li { margin: 5px 0; }
        nav {
            background-color: #f8f9fa;
            padding: 10px;
            margin-bottom: 20px;
        }
        .text-content {
            max-width: 800px;
            margin: 0 auto;
            padding: 20px;
        }
    )";
};

ASTNode* parseAST(const QString& astText) {
    QStringList lines = astText.split('\n');
    QStack<ASTNode*> stack;
    ASTNode* root = nullptr;
    
    for (const QString& line : lines) {
        if (line.trimmed().isEmpty()) continue;
        
        int indentLevel = line.indexOf(line.trimmed()) / 2;
        QString trimmedLine = line.trimmed();
        
        QString tag = trimmedLine.split(':').first();
        QString content = trimmedLine.contains(": ") ? 
                         trimmedLine.split(": ").last().trimmed() : "";
                         
        ASTNode* newNode = new ASTNode(tag, content, indentLevel);
        
        while (!stack.isEmpty() && stack.top()->indentLevel >= indentLevel) {
            stack.pop();
        }
        
        if (stack.isEmpty()) {
            root = newNode;
        } else {
            stack.top()->children.append(newNode);
        }
        
        stack.push(newNode);
    }
    
    return root;
}

void call_renderer(int argc, char *argv[],string ast){
	QApplication app(argc, argv);

    // QFile file("/mnt/c/Users/91798/Downloads/renderhtml/ast.txt");
    // if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    //     qWarning("Could not open AST file.");
    //     return -1;
    // }
    
    // QTextStream in(&file);
    // QString astText = in.readAll();
    // file.close();

	QString astText = QString::fromStdString(ast);

    ASTNode* root = parseAST(astText);
    MiniBrowser browser(root);
    browser.setWindowTitle("Mini Browser");
    browser.show();

    int result = app.exec();
    delete root;
    return;
}

void printstring_from_buffer(void* ptr,int index){
     cout<<((char*)ptr)+SIZE_OF_PAGE*index<< endl;
    return;
}

vector<thread> threadVector;

void consumer_func(int argc, char *argv[]){

	

    string ast;
    while(1)
    {
        //cout<<"hello\n";

        sem_wait(filled);
        sem_wait(bsem);

        

        // ofstream outputFile("rendering_"+ to_string(out)+".txt");
        
        string ast= ((char*)ptr2)+SIZE_OF_PAGE*out;

        
        
		threadVector.push_back(thread(call_renderer,argc,argv,ast));
		

        
        

        out=(out+1)%n;

        // outputFile.close();

        
        
        

        


        
        
        

        //cout<<"hello";

        sem_post(bsem);
        sem_post(emp);


        
        




    }

	

    

}



int main(int argc, char *argv[]) {
    const char* n_shared_name = "/size_of_buffer";
    int shm_fd1 = shm_open(n_shared_name, O_RDWR, 0666);
    void* ptr1 = mmap(0, sizeof(int), PROT_READ, MAP_SHARED, shm_fd1, 0);
    

    n=*((int*)(ptr1));
    
    //shared memory storing strings
    const char* storing_web_pages = "/asts";
    int shm_fd2 = shm_open(storing_web_pages,O_RDWR, 0666);  
    ptr2 = mmap(0, SIZE_OF_PAGE*n*sizeof(char), PROT_WRITE, MAP_SHARED, shm_fd2, 0);
    

    //html.y will put data into following 




    
    emp = sem_open("/emp_dup", 0);
    filled = sem_open("/filled_dup", 0);
    bsem = sem_open("/bsem_dup", 0);

    consumer_func(argc, argv);

	for (auto& temp : threadVector) {
        
            temp.join();
        
    }

    
    munmap(ptr1, sizeof(int));
    close(shm_fd1);
    shm_unlink(n_shared_name);

    munmap(ptr2, SIZE_OF_PAGE*n*sizeof(char));
    close(shm_fd2);
    shm_unlink(storing_web_pages);

    return 0;

}

#include "main.moc"
