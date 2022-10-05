# cc and flags
CC = g++
CXXFLAGS = -std=c++11 -g -Wall

# folders
INCLUDE_FOLDER = ./include/
BIN_FOLFER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/
OUTPUT_FOLFER = ./output/

# all sourcers, obs, and header files
MAIN = main
TARGET = tp01
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLFER)$(TARGET) $(OBJ)

run:
	./bin/tp01

clean: 
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLFER)* $(OUTPUT_FOLFER)*
	clear