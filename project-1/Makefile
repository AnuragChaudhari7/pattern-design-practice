CXX = clang++
CXXFLAGS = -Wall -std=c++17
TARGET = main.out
SRC = ./*.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm $(TARGET)
