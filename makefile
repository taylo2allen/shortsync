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
	rm -f /usr/local/bin/$(TARGET)

install: clean
	chmod 755 shortcut-files/* config.yaml $(TARGET)
	chmod 644 LICENSE README.org $(TARGET).1
	cp -np $(TARGET).1 /usr/share/man/man1/$(TARGET).1
	cp -np LICENSE /usr/share/licenses/$(TARGET)/LICENSE
	cp -np README.org /usr/share/doc/$(TARGET)/README.org
	cp -np config.yaml ~/.config/shortsync/shortcut-configs
	cp -np bin/$(TARGET) /usr/local/bin/$(TARGET)
	cp -npr shortcut-files/* ~/.config/shortsync/shortcut-files

uninstall:
	rm -rf ~/.config/shortsync
	rm -f /usr/local/bin/$(TARGET)
	rm -f /usr/share/licenses/${pkgname}/LICENSE
	rm -f /usr/share/doc/$(TARGET)/README.org
	rm -f /usr/share/man/man1/$(TARGET).1
