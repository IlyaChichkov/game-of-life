all: dir main clean

dir:
	@if [ -d "./debug" ]; then \
	echo 'remove...'; \
	rm -rf ./debug; \
	else \
	echo 'exist'; \
	fi
	mkdir ./debug;

some:

main:
	gcc main.c game.c utils.c -o ./debug/main
	echo 'Program started...'
	clear
	./debug/main
	@echo ''

clean:
	@rm -rf ./debug