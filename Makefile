CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp interactive_equation_solver.cpp MeasurementError.cpp Tests.cpp PrintSolution.cpp TestsFromFile.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
