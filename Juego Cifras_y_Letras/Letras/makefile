LIB = lib
INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g


all: letras cantidad


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
	
cantidad: $(OBJ)/Cantidad_Letras.o $(OBJ)/Diccionario.o $(OBJ)/Letra.o
	$(CXX) -I./$(INC) -o $(BIN)/Cantidad_Letras $(OBJ)/Cantidad_Letras.o $(OBJ)/Diccionario.o $(OBJ)/Letra.o

$(OBJ)/Cantidad_Letras.o: $(SRC)/Cantidad_Letras.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Cantidad_Letras.o $(SRC)/Cantidad_Letras.cpp


# test_diccionario: $(OBJ)/testdiccionario.o $(OBJ)/diccionario.o
# 	$(CXX) -I./$(INC) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o $(OBJ)/Diccionario.o

letras: $(OBJ)/Letras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Conjunto_Letras.o $(OBJ)/Letra.o $(OBJ)/Diccionario.o
	$(CXX) -I./$(INC) -o $(BIN)/Letras $(OBJ)/Letras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Conjunto_Letras.o $(OBJ)/Letra.o $(OBJ)/Diccionario.o

$(OBJ)/Letras.o: $(SRC)/Letras.cpp $(SRC)/Bolsa_Letras.cpp $(SRC)/Conjunto_Letras.cpp $(SRC)/Letra.cpp $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Letras.o $(SRC)/Letras.cpp

$(OBJ)/Bolsa_Letras.o: $(SRC)/Bolsa_Letras.cpp $(SRC)/Conjunto_Letras.cpp $(SRC)/Letra.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Bolsa_Letras.o $(SRC)/Bolsa_Letras.cpp

$(OBJ)/Conjunto_Letras.o: $(SRC)/Conjunto_Letras.cpp $(SRC)/Letra.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Conjunto_Letras.o $(SRC)/Conjunto_Letras.cpp

$(OBJ)/Letra.o: $(SRC)/Letra.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Letra.o $(SRC)/Letra.cpp

# $(OBJ)/testdiccionario.o: $(SRC)/testdiccionario.cpp $(SRC)/Diccionario.cpp
# 	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp

$(OBJ)/Diccionario.o: $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f $(BIN)/* doc/html/*