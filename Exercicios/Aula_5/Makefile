all: calc

calc.tab.c calc.tab.h:	calc.y
	bison -t -v -d calc.y -Wcounterexamples

lex.yy.c: calc.l calc.tab.h
	flex calc.l

calc: lex.yy.c calc.tab.c calc.tab.h
	gcc -o calc calc.tab.c lex.yy.c calcUtils.c
	./calc

clean:
	rm calc calc.tab.c lex.yy.c calc.tab.h calc.output
