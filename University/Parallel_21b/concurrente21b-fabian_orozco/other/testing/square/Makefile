APPNAME=square

$(APPNAME): $(APPNAME).c
	cc -g -std=c11 -Wall -Wextra $(APPNAME).c -o $(APPNAME) # -pthread

all: $(APPNAME) lint

lint: 
	cpplint --filter=-readability/casting $(APPNAME).c

clean:
	rm -f $(APPNAME)