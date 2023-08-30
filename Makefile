CC=g++
CFLAGS=-c -Wall
LDFLAGS=

# TODO: Your source file names are inconsistent, choose one naming style, let's say snake_case or
#       PascalCase or whatever and remain consistent!
SOURCES=main.cpp interactive_equation_solver.cpp MeasurementError.cpp Tests.cpp PrintSolution.cpp TestsFromFile.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# TODO: What if header changes? Will your necessary file automatically recompile, or won't it?
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
