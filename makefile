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

install: clean
	mkdir -p $(HOME)/.config/shortsync/
	cp -nru config/* -t /$(HOME)/.config/shortsync
	chmod 755 config/* bin/$(TARGET)
	chmod 644 LICENSE README.org $(TARGET).1
	sudo cp -f $(TARGET).1 /usr/share/man/man1
	sudo cp -f LICENSE /usr/share/licenses/$(TARGET)
	sudo cp -f README.org /usr/share/doc/$(TARGET)
	sudo cp -f bin/$(TARGET) /usr/local/bin

uninstall:
	sudo rm -rf ~/.config/shortsync
	sudo rm -f /usr/local/bin/$(TARGET)
	sudo rm -f /usr/share/licenses/$(TARGET)/LICENSE
	sudo rm -f /usr/share/doc/$(TARGET)/README.org
	sudo rm -f /usr/share/man/man1/$(TARGET).1
