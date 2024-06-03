CXX = g++
CXXFLAGS = -Wall -std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = rectangle
TARGET_DIR = ./targetFolder
TARGET_PATH = $(TARGET_DIR)/$(TARGET)

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET_PATH)

$(TARGET_PATH): $(OBJS)
	mkdir -p $(TARGET_DIR)
	$(CXX) $(OBJS) -o $(TARGET_PATH) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET_DIR)


