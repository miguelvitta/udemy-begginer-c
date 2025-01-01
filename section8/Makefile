CC = gcc
CFLAGS = -Wall -Wextra -Wshadow
DEBUG_FLAGS = -g3 -ggdb

SRCS = $(shell find . -type f -name '*.c')

BINARIES = $(SRCS:.c=)

all: $(BINARIES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lm

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(BINARIES)

.PHONY: clean
clean:
	rm -f $(BINARIES)
