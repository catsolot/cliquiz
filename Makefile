# set the compiler
CC := gcc

# set the compiler flags
CFLAGS := -ggdb3 -O0 --std=c99 -Wall -lm -lsqlite3 -lncurses

# add header files here
HDRS := sqlite3.h type_text.h fuzzy.h

# add source files here
SRCS := main.c type_text.c fuzzy.c

# generate names of object files
OBJS := $(SRCS:.c=.o)

# name of executable
EXEC := cliquiz

# default recipe
all: $(EXEC)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
#$(OBJS): $(@:.o=.c) $(HDRS) Makefile
#	$(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
