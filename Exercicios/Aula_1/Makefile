all:
	flex -o lexer.yy.c lexer.l
	gcc -o lexer lexer.yy.c -lfl
	./lexer < t.txt