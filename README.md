# COMPILER-DESIGN-BASICS-IN-C
*COMPANY*: CODTECH IT SOLUTIONS
*NAME*: ADI BAIS
*INTERN ID*: CT04DG2170
*DOMAIN*: C PROGRAMMING
*DURATION*: 4 WEEKS
*MENTOR*: NEELA SANTOSH

*DESCRIPTION*:

The presented C program is a basic lexical analyzer, which allows users to input C code, store it in a file, and then analyze that code to identify and classify keywords, identifiers, and operators. Lexical analysis is the first step in compiler design, where source code is broken into tokens. This program simulates that process in a simplified form.

The program offers a menu-driven interface with three options:

Create a file and enter code

Perform lexical analysis

Exit the program

The user begins by choosing to create a file. The createFile() function opens a file in write mode and allows the user to enter multiple lines of C code. The code entry is terminated when the user types END on a new line. This code is saved to the file for analysis.

The core logic lies in the lexicalAnalyze() function. It reads the file character by character and classifies the text into three main types: keywords, identifiers, and operators.

Keywords are predefined reserved words in C like int, float, if, else, etc. The program uses an array of strings to store C keywords and compares every parsed word against this list.

Identifiers are user-defined names like variable or function names. If a word begins with a letter or underscore and is not a keyword, it is considered an identifier.

Operators are symbols that perform operations. The program detects single-character operators such as +, -, *, /, and compound operators like ==, !=, >=, and <=.

The program uses helper functions like isKeyword() and isOperator() to simplify classification. It also makes use of functions like fgetc() and ungetc() to carefully read and push back characters when needed. This allows accurate tokenization of code.

Numeric values (constants) are detected by checking for digits, although the program currently skips their output for simplicity. This functionality can be extended to classify numbers as well.

This lexical analyzer helps beginners understand how a compiler tokenizes source code. Although simplified, it introduces fundamental concepts like:

Token recognition

Keyword vs identifier differentiation

Handling of compound symbols

Basic file I/O in C

Character-level parsing

The code is modular and can be expanded further to include support for:

Numeric literals

String and character constants

Comments (//, /* */)

Delimiters (like ;, ,, {, })

In conclusion, this C program provides a basic yet effective simulation of lexical analysis. It teaches essential principles of compiler design and C programming, making it a valuable learning tool for students and beginners in systems programming or language processing. The use of file operations, string comparison, character classification, and conditional logic makes it both practical and educational
