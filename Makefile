CC = gcc
CFLAGS = -Wall

INC_DIRS = inc
SRC_DIRS = src
OBJ_DIR_ROOT = obj

SOURCES := $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJECTS := $(SOURCES:%.c=obj/%.o)
INCLUDES := $(foreach dir, $(INC_DIRS), -I$(dir))

TEST_EXECUTABLE=main

.PHONY: clean run set-up

set-up:
	$(foreach dir, $(SRC_DIRS), mkdir -p $(OBJ_DIR_ROOT)/$(dir))

$(OBJ_DIR_ROOT)/%.o : %.c set-up
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_EXECUTABLE) : $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

run : $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

clean:
	rm -rf obj/*
	rm $(TEST_EXECUTABLE)
