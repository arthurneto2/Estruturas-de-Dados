APPS = ./apps
SRC = ./src
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
LIB = ./lib

FLAGS = -O3 -Wall
LIBS = -led -L $(LIB)

all: compobj dolib compapp

compobj:\
	$(OBJ)/float_vector.o \
	$(OBJ)/mytime.o\
	$(OBJ)/doubly_list.o


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

dolib:\
	$(LIB)/libed.a

$(LIB)/%.a: $(OBJ)/*.o
	ar -rsc $@ $(OBJ)/*.o

compapp: $(BIN)/lista_duplamente

$(BIN)/%: $(APPS)/%.c $(OBJ)/*.o
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@
	
run:
	$(BIN)/lista_duplamente
	
clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/*