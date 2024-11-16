# Mini Web Browser Project

## Project Overview
This project is a custom-built mini web browser designed to render simple HTML web pages. It was developed as an assignment to demonstrate key concepts in web parsing, rendering, and multi-threaded programming.

## Key Components
* **HTML Page Fetching**: A network handling system is implemented to fetch and locally cache HTML pages using HTTP requests.
* **DOM Parser**: A custom parser converts HTML documents into a Document Object Model (DOM), represented as an Abstract Syntax Tree (AST).
* **Rendering Engine**: A GUI rendering system is created using the Qt framework. This system displays elements like text, images, and links through custom widgets and QPainter.
* **Multi-Process and Multi-Threading Support**: The project supports multiple processes and threads, enabling parallel management of multiple tabs.
* **Browser History**: Basic functionality for browser history management, allowing navigation between previously visited pages.

## Project Structure
The project is organized into two main directories:
* **documentation**: Contains header files, source code for the network manager, and other related documentation.
* **project**: Includes source files, build scripts, and generated HTML datasets for testing the browser's capabilities.

## Features Implemented
* Custom HTML parser with support for basic HTML tags
* GUI rendering using Qt Widgets
* Multi-threaded and multi-process architecture for concurrent tab handling
* Browser history storage for user navigation

## Acknowledgements
This project is part of the COP701 course assignment.

