CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
INCLUDES = -I include

SRC = src/main.cpp \
      src/matriz.cpp \
      src/gauss.cpp \
      src/gauss_jordan.cpp \
      src/cramer.cpp \
      src/analise.cpp

OBJ = $(SRC:.cpp=.o)

EXEC = cordas

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
