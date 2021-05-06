CC = g++
CFLAGS = -Wall -Werror -O2 -g
CLIBS = -lSDL2
DEPS = main.cpp

.PHONY: all
all: main

.SECONDEXPANSION:
DEP_PATH := $(addprefix src/,$(DEPS))
main: $(DEP_PATH)
	$(CC) $(CFLAGS) -o main $(DEP_PATH) $(CLIBS)

.PHONY: clean
clean:
	rm Get_Key_Var_SDL Key_Value_SDL
