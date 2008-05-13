
# define building tools
CC		= gcc
LEXER	= flex
YACC	= bison

# define paths
ROOT	= /Users/brian/Development/dpl
BIN		= $(ROOT)/bin
SRC		= $(ROOT)/src
EXT		= $(SRC)/ext

# define program specifics
PROG		= $(BIN)/dpl

LEXFILE		= $(SRC)/dpl_scanner.l
YACCFILE	= $(SRC)/dpl_parser.y
LEXOUT		= $(SRC)/dpl_scanner.c
YACCOUT		= $(SRC)/dpl_parser.c

SRCS		= $(LEXOUT) $(YACCOUT) main.c variables.c

OBJS		= hash.o stack.o dpl_api.o dpl_scanner.o dpl_parser.o main.o variables.o arrays.o functions.o operators.o control_structs.o file.o
EXT_OBJS	= string.o math.o array.o

all: dpl

dpl_scanner.c:
	$(LEXER) -o$(LEXOUT) $(LEXFILE)

dpl_parser.c:
	$(YACC) -y -d -o $(YACCOUT) $(YACCFILE)

hash.o:
	$(CC) -c $(SRC)/hash.c -o $(SRC)/hash.o

stack.o:
	$(CC) -c $(SRC)/stack.c -o $(SRC)/stack.o

dpl_api.o:
	$(CC) -c $(SRC)/dpl_api.c -o $(SRC)/dpl_api.o

dpl_scanner.o: dpl_scanner.c
	$(CC) -c $(SRC)/dpl_scanner.c -o $(SRC)/dpl_scanner.o

dpl_parser.o: dpl_parser.c
	$(CC) -c $(SRC)/dpl_parser.c -o $(SRC)/dpl_parser.o

main.o:
	$(CC) -c $(SRC)/main.c -o $(SRC)/main.o

variables.o:
	$(CC) -c $(SRC)/variables.c -o $(SRC)/variables.o

arrays.o:
	$(CC) -c $(SRC)/arrays.c -o $(SRC)/arrays.o

functions.o:
	$(CC) -c $(SRC)/functions.c -o $(SRC)/functions.o

operators.o:
	$(CC) -c $(SRC)/operators.c -o $(SRC)/operators.o

control_structs.o:
	$(CC) -c $(SRC)/control_structs.c -o $(SRC)/control_structs.o

file.o:
	$(CC) -c $(SRC)/file.c -o $(SRC)/file.o

dpl: hash.o stack.o dpl_api.o dpl_scanner.o dpl_parser.o main.o variables.o arrays.o functions.o operators.o control_structs.o file.o
	
	$(CC) -c -I$(SRC) $(EXT)/*.c
	
	$(CC) -o $(PROG) $(SRC)/hash.o $(SRC)/stack.o $(SRC)/dpl_api.o \
		$(SRC)/dpl_scanner.o $(SRC)/dpl_parser.o $(SRC)/main.o \
		$(SRC)/variables.o $(SRC)/arrays.o $(SRC)/functions.o \
		$(SRC)/operators.o $(SRC)/control_structs.o $(SRC)/file.o \
		string.o math.o array.o

clean:
	rm -f *.o
	rm -f $(PROG) $(LEXOUT) $(YACCOUT)
	