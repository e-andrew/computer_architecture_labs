SOURCE_DIR=src
OBJECT_DIR=obj
INCLUDE_DIR=include
BUILT_DIR=make.build

SHARED_OBJECT=command.so
EXECUTABLE=command.exe
OBJECTS=main.o command_rules.o command_line.o syntax_check.o key_executor.o execute_command.o
OBJECTS_IN_DIR=$(OBJECT_DIR)/command_rules.o $(OBJECT_DIR)/command_line.o $(OBJECT_DIR)/syntax_check.o $(OBJECT_DIR)/key_executor.o $(OBJECT_DIR)/execute_command.o

all: archive
	g++ $(OBJECT_DIR)/main.o $(BUILT_DIR)/$(SHARED_OBJECT) -o $(BUILT_DIR)/$(EXECUTABLE)

archive: $(OBJECTS)
	g++ -shared $(OBJECTS_IN_DIR) -o $(BUILT_DIR)/$(SHARED_OBJECT)

main.o: $(SOURCE_DIR)/main.cpp
	g++ -c $(SOURCE_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJECT_DIR)/main.o

command_rules.o: $(SOURCE_DIR)/command_rules.cpp $(INCLUDE_DIR)/command_rules.h
	g++ -c $(SOURCE_DIR)/command_rules.cpp -I$(INCLUDE_DIR) -o $(OBJECT_DIR)/command_rules.o

command_line.o: $(SOURCE_DIR)/command_line.cpp $(INCLUDE_DIR)/command_line.h
	g++ -c $(SOURCE_DIR)/command_line.cpp -I$(INCLUDE_DIR) -o $(OBJECT_DIR)/command_line.o

syntax_check.o: $(SOURCE_DIR)/syntax_check.cpp $(INCLUDE_DIR)/syntax_check.h
	g++ -c $(SOURCE_DIR)/syntax_check.cpp -I$(INCLUDE_DIR) -o $(OBJECT_DIR)/syntax_check.o

key_executor.o: $(SOURCE_DIR)/key_executor.cpp $(INCLUDE_DIR)/key_executor.h
	g++ -c $(SOURCE_DIR)/key_executor.cpp -I$(INCLUDE_DIR) -o $(OBJECT_DIR)/key_executor.o

execute_command.o: $(SOURCE_DIR)/execute_command.cpp $(INCLUDE_DIR)/execute_command.h
	g++ -c $(SOURCE_DIR)/execute_command.cpp -I$(INCLUDE_DIR) -o $(OBJECT_DIR)/execute_command.o

clean:
	del $(OBJECT_DIR)\*.o
	del $(BUILT_DIR)\*.so
	del $(BUILT_DIR)\$(EXECUTABLE)