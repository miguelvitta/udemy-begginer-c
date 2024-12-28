CC = gcc
CFLAGS = -Wall -Wextra -Wshadow

SRCS = $(shell find . -type f -name '*.c')

BINARIES = $(SRCS:.c=)

all: $(BINARIES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lm

.PHONY: clean
clean:
	rm -f $(BINARIES)
