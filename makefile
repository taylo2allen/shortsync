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
	chmod 755 shortcut-files/* config.yaml bin/$(TARGET)
	chmod 644 LICENSE README.org $(TARGET).1
	sudo cp -f $(TARGET).1 /usr/share/man/man1
	sudo cp -f LICENSE /usr/share/licenses/$(TARGET)
	sudo cp -f README.org /usr/share/doc/$(TARGET)
	sudo cp -f bin/$(TARGET) /usr/local/bin
	cp -n config.yaml $(HOME)/.config/shortsync/shortcut-configs
	cp -nr shortcut-files $(HOME)/.config/shortsync

uninstall:
	rm -rf ~/.config/shortsync
	rm -f /usr/local/bin/$(TARGET)
	rm -f /usr/share/licenses/$(TARGET)/LICENSE
	rm -f /usr/share/doc/$(TARGET)/README.org
	rm -f /usr/share/man/man1/$(TARGET).1
