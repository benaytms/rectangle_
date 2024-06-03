.PHONY: all clean copy_SFML

CXX = g++
CXXFLAGS = -Wall -std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = rectangle
TARGET_DIR = ./main
TARGET_PATH = $(TARGET_DIR)/$(TARGET)

SRCS = ./main/main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET_PATH)

$(TARGET_PATH): copy_SFML $(OBJS)
	mkdir -p $(TARGET_DIR)
	$(CXX) $(OBJS) -o $(TARGET_PATH) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

copy_SFML:
	sudo cp -r ./main/SFML /usr/include/
	sudo cp -r ./main/SFML /usr/local/include/

clean:
	rm -rf $(OBJS) $(TARGET_PATH)
