##
# shortsync
##

# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
CFLAGS  = -g -Wall -lyaml-cpp

# The build target
TARGET = shortsync

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o bin/$(TARGET) $(TARGET).cpp

clean:
	sudo rm -f /usr/local/bin/$(TARGET)
	sudo rm -f /usr/share/licenses/$(TARGET)/LICENSE
	sudo rm -f /usr/share/doc/$(TARGET)/README.org
	sudo rm -f /usr/share/man/man1/$(TARGET).1
	sudo rm -f /usr/share/man/man1/$(TARGET).1.gz

install: clean
	chmod 775 bin/$(TARGET)
	chmod 644 LICENSE README.org $(TARGET).1
	mkdir -p $(HOME)/.config/shortsync/shortcut-files && cp -nru config/* -t $(HOME)/.config/shortsync/
	chmod 777 $(HOME)/.config/shortsync/*
	sudo cp -f $(TARGET).1 -t /usr/share/man/man1
	sudo mkdir -p /usr/share/licenses/$(TARGET) && sudo cp -f LICENSE -t /usr/share/licenses/$(TARGET)
	sudo mkdir -p /usr/share/doc/$(TARGET) && sudo cp -f README.org -t /usr/share/doc/$(TARGET)
	sudo cp -f bin/$(TARGET) -t /usr/local/bin

uninstall: clean
	sudo rm -rf ~/.config/shortsync
