#include "network/NetworkManager.h"
#include "parser/HTML2AST.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    try {
        NetworkManager networkManager("cache");

        string url = "http://localhost:8000/html_page_1.html";  // Updated URL
        if (argc > 1) {
            url = argv[1];
        }

        cout << "Fetching page: " << url << endl;

        string content = networkManager.fetchPage(url);
        if (content.empty()) {
            cerr << "Failed to fetch page content" << endl;
            return 1;
        }

        cout << "Page fetched successfully. Parsing content..." << endl;

        AST ast;
        string output_file = "parsed_output.txt";
        if (ast.parseFromString(content, output_file)) {
            cout << "Parsing successful! AST written to " << output_file << endl;
        } else {
            cerr << "Failed to parse HTML content" << endl;
            return 1;
        }

        return 0;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}

