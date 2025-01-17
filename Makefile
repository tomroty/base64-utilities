CC = gcc
CFLAGS = -Wall -Werror -Wextra 
SRC = src/main.c src/base64.c
OUT = base64_encoder

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)