INC = ./include
OBJ = ./obj
SRC = ./src
BIN = ./bin
DOC = ./doc
CXX = g++
CPPFLAGS = -Wall -g -c

# ************ Compilación de módulos ************

all: diccionario

diccionario: $(OBJ)/testdiccionario.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o $(OBJ)/diccionario.o -I$(INC)

$(OBJ)/testdiccionario.o: $(SRC)/testdiccionario.cpp $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp -I$(INC)

$(OBJ)/diccionario.o: $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/diccionario.o $(SRC)/Diccionario.cpp -I$(INC)


# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*
	rm -f $(BIN)/*

mrproper : clean
	rm -r $(DOC)/html $(DOC)/latex

# ************ Documentación ***********
doxy :
	doxygen $(DOC)/letras.doxy