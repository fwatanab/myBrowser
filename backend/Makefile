TARGET = myBrowser

SRCS = main.cpp src/Network.cpp src/Node.cpp src/Parser.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./inc -I/Users/sukakaedefutoshi/.brew/opt/openssl@3/include
LIBS = -L/Users/sukakaedefutoshi/.brew/opt/openssl@3/lib -lcurl -lssl -lcrypto

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(TARGET)

re: fclean all
