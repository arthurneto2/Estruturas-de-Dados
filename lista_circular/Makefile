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
	$(OBJ)/mytime.o

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

dolib:\
	$(LIB)/libed.a

$(LIB)/%.a: $(OBJ)/*.o
	ar -rsc $@ $<

compapp: $(BIN)/teste_float_vector

$(BIN)/%: $(APPS)/%.c $(OBJ)/*.o
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@
	
run:
	$(BIN)/teste_float_vector
	
clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/*