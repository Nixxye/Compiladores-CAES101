all:
	flex -o lexerPage3.yy.c lexerPage3.l
	gcc -o lexerPage3 lexerPage3.yy.c -lfl
	./lexerPage3 < t.txt