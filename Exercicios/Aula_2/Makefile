# Variáveis
LEXER_FILE = calculadora.l
OUTPUT_FILE = lexer

# Regras
all:
	flex -l -o $(OUTPUT_FILE).yy.c $(LEXER_FILE)
	gcc -o $(OUTPUT_FILE) $(OUTPUT_FILE).yy.c -lfl
	./$(OUTPUT_FILE) < calculadora.txt

# Se você quiser passar o nome do arquivo `.l` como parâmetro
# Exemplo: make LEXER_FILE=outro_arquivo.l
