# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -IcodeC
LDFLAGS =
SRCS = main.c implementationAVL.c traitementAVL.c traitementChainon.c
OBJS = $(SRCS:.c=.o)
TARGET = C-Wire

# Règle pour créer l'éxécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Règle pour compiler les fichiers
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour effacer les exécutables
clean:
	rm -f $(OBJS) $(TARGET) *.o