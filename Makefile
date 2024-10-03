# Define the C++ compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Define the source files and the executable name
SRC = main.cpp article.cpp filereader.cpp filewriter.cpp solution.cpp
EXE = P2

# Define the object files
OBJ = $(SRC:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(EXE) $(OBJ)

.PHONY: all clean

