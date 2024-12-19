# Compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -IcodeC
LDFLAGS =

# Source files
SRCS = codeC/main.c codeC/implementationAVL.c codeC/traitementAVL.c codeC/traitementChainon.c
OBJS = $(SRCS:.c=.o)
TARGET = C-Wire

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET) codeC/*.o

