# Nombre del archivo ejecutable
TARGET = bin/client

# Fuentes y encabezados
SRCS = $(wildcard src/*.cpp)
HDRS = $(wildcard lib/*.hpp include/*.hpp)

# Compilador y opciones
CXX = g++
CXXFLAGS = -pthread

# Dirección IP y puerto
IP = 127.0.0.1
PORT = 8189

all: $(TARGET)

$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

.PHONY: clean run

clean:
	rm -f $(TARGET)

run:
	./$(TARGET) $(IP) $(PORT)
