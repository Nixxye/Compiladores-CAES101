# Regras
all:
	bison -d parser.y -o parser.tab.c
	flex -l -o lexer.yy.c lexer.l
	gcc parser.tab.c lexer.yy.c -Wall -o tinycompiler
	./tinycompiler < test.txt

# Se você quiser passar o nome do arquivo `.l` como parâmetro
# Exemplo: make LEXER_FILE=outro_arquivo.l
