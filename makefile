
# define building tools
CC		= gcc
LEXER	= flex
YACC	= bison

# define paths
ROOT	= /home/brian/dpl2
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

all: dpl clean

dpl:
	$(LEXER) -o$(LEXOUT) $(LEXFILE)
	$(YACC) -y -d -o $(YACCOUT) $(YACCFILE)
	
	# compile core source
	$(CC) -ggdb -c $(SRC)/*.c

	# compile ext source
	$(CC) -c -I$(SRC) $(EXT)/*.c

	$(CC) -ggdb -o $(PROG) $(OBJS) $(EXT_OBJS)

clean:
	rm -f ./*.o