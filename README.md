# Compiler

### Description
A simple Lexical Analyzer, Syntax Analyzer, Semantics Analyzer and Three Address Code for the language `C+-`.

* `project.l` is the Lexical Analyzer.
* `project.y` is the Parser (Syntax Analyzer, Semantics Analyzer and Three Address Code)
* `lex.yy.c` is the compiled file from `project.l`
* `y.tab.c` is the compiled file from `project.y`

### How To Test (In Container):
Run `docker run maxpok/compiler`.

### How To Run (In Linux):
* `chmod +x run.sh`
* Run `sh ./run.sh`

##### NOTE:
Make sure you have bison, flex and gcc installed.
