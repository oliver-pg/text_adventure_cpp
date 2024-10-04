CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O2

SRC_DIR = src
INC_DIR = include

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)

text_adventure: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o text_adventure $(OBJ_FILES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) text_adventure
