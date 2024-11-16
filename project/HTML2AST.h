#ifndef HTML2AST_H
#define HTML2AST_H

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <iostream>

using namespace std;

class ASTNode {
public:
    string tag;
    string content;
    vector<shared_ptr<ASTNode>> children;
    int tab;
    bool visited;

    ASTNode(const string& t = "", const string& c = "", int tabCount = 0)
        : tag(t), content(c), tab(tabCount), visited(false) {}
    
    void addChild(shared_ptr<ASTNode> child) {
        children.push_back(child);
    }
};

class AST {
private:
    shared_ptr<ASTNode> root;
    ofstream outFile;
    
    string getAttribute(const string& content, const string& attribute) {
        string attributePattern = attribute + "=\"";
        size_t start = content.find(attributePattern);
        if (start != string::npos) {
    	    start += attributePattern.length();
            size_t end = content.find("\"", start);
            if (end != string::npos) {
            	return content.substr(start, end - start);
            }
    	}
    	return "";
    }


    void writeNodeToFile(shared_ptr<ASTNode> node) {
        if (!node || node->visited) return;

        node->visited = true;
        string indent(node->tab * 2, ' ');
        
	if (node->tag == "img") {
	    string src = getAttribute(node->content,"src");
	    string alt = getAttribute(node->content,"alt");
	    string width = getAttribute(node->content,"width");
	    string height = getAttribute(node->content,"height");
    
	    outFile << indent << "img: ";
    
	    if (!src.empty()) outFile << "src=" << src;
	    if (!alt.empty()) outFile << " alt=" << alt;
	    if (!width.empty()) outFile << " width=" << width;
	    if (!height.empty()) outFile << " height=" << height;
    
	    outFile << endl;
	    return;
	}
	
	if (node->tag == "a") {
    	    outFile << indent << "a: ";
	    string href = getAttribute(node->content,"href");
    	    if (!href.empty()) outFile << "href=" << href;
 	    outFile << endl;
	}
        else {
            if (!node->tag.empty()) {
                 outFile << indent << node->tag << ": ";
            }
            if (!node->content.empty()) {
                outFile << node->content << endl;
            }
	    else {
	        outFile << endl;
	    }
	}
        for (auto& child : node->children) {
            writeNodeToFile(child);
        }
    }

    void resetVisited(shared_ptr<ASTNode> node) {
        if (!node) return;
        node->visited = false;
        for (auto& child : node->children) {
            resetVisited(child);
        }
    }

public:
    AST() : root(nullptr) {}

    void setRoot(shared_ptr<ASTNode> node) {
        root = node;
    }

    shared_ptr<ASTNode> getRoot() {
        return root;
    }

    bool writeToFile(const string& filename) {
        outFile.open(filename);
        if (!outFile.is_open()) {
            return false;
        }

        // Reset all visited flags before traversal
        resetVisited(root);

        // Perform preorder traversal and write to file
        writeNodeToFile(root);

        outFile.close();
        return true;
    }
    
};

// Global variables declaration
extern AST htmlAst;
extern shared_ptr<ASTNode> currentNode;

// Stack to keep track of nodes during parsing
static vector<shared_ptr<ASTNode>> nodeStack;

// Function declarations for the parser
inline void startElement(const string& tag, const string& content = "") {
    auto newNode = make_shared<ASTNode>(tag, content, nodeStack.size());
    
    if (nodeStack.empty()) {
        // This is the root node
        htmlAst.setRoot(newNode);
    } else {
        // Add as child to current parent
        nodeStack.back()->addChild(newNode);
    }
    
    nodeStack.push_back(newNode);
    currentNode = newNode;
}

inline void endElement() {
    if (!nodeStack.empty()) {
        nodeStack.pop_back();
        currentNode = nodeStack.empty() ? nullptr : nodeStack.back();
    }
}

inline void addContent(const string& content) {
    if (currentNode) {
        if (!currentNode->content.empty()) {
            currentNode->content += " ";
        }
        currentNode->content += content;
    }
}

#endif // HTML2AST_H
