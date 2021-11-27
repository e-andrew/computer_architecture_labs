SOURCE_DIR=src
OBJECT_DIR=obj
INCLUDE_DIR=include
BUILT_DIR=make.build

SHARED_OBJECT=libcalculator.so
EXECUTABLE=main.exe

all: archive
	g++ $(OBJECT_DIR)/main.o $(BUILT_DIR)/$(SHARED_OBJECT) -o $(BUILT_DIR)/$(EXECUTABLE)

archive: main.o calculator.o
	g++ -shared $(OBJECT_DIR)/calculator.o -o $(BUILT_DIR)/$(SHARED_OBJECT)

main.o: $(SOURCE_DIR)/main.cpp
	g++ -c $(SOURCE_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJECT_DIR)/main.o

calculator.o: $(SOURCE_DIR)/calculator.cpp $(INCLUDE_DIR)/calculator.h
	g++ -c $(SOURCE_DIR)/calculator.cpp -I$(INCLUDE_DIR) -o $(OBJECT_DIR)/calculator.o

clean:
	del $(OBJECT_DIR)\*.o
	del $(BUILT_DIR)\*.so
	del $(BUILT_DIR)\$(EXECUTABLE)