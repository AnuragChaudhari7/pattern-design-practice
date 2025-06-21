CXX = clang++
CXXFLAGS = -Wall -std=c++17
TARGET = main.out
SRC = main.cpp Account.cpp CheckingAccount.cpp SavingsAccount.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm $(TARGET)
