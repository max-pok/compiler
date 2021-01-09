flex project.l
yacc project.y
cc -o project y.tab.c -lfl
./project < input_code.txt