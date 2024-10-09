# Mini Web Browser

## Description

Mini Web Browser is a lightweight web browser project that focuses on HTML to AST (Abstract Syntax Tree) generation. It includes functionalities for parsing HTML pages and managing network operations.

## Features

- HTML to AST generation
- Basic network management
- Supports loading HTML files from a specified dataset

## Prerequisites

- CMake (version 3.10 or higher)
- A C++ compiler (e.g., g++, clang++)
- Python (for running the `gen_html.py` script)

## Installation

1. Clone the repository:
   ```bash
   git clone git@github.com:Shuvam-Chakraborty/Mini_Web_Browser.git
   cd Mini_Web_Browser
   ```

2. Build the project:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Usage

1. Run the compiled executable:
   ```bash
   ./minibrowser
   ```

2. Load HTML pages from the html_dataset directory to test the functionality.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any improvements or bugs.
