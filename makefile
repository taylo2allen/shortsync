##
# shortsync
##

TARGET = shortsync

build:
	make -C build/ -k all
	cp -nru build/shortsync bin/

clean:
	sudo rm -f /usr/local/bin/$(TARGET)
	sudo rm -f /usr/share/licenses/$(TARGET)/LICENSE
	sudo rm -f /usr/share/doc/$(TARGET)/README.md
	sudo rm -f /usr/share/man/man1/$(TARGET).1
	sudo rm -f /usr/share/man/man1/$(TARGET).1.gz

install: clean
	make -C build/ -k all
	cp -nru build/shortsync bin/
	chmod 775 bin/$(TARGET)
	chmod 644 LICENSE README.md $(TARGET).1
	mkdir -p $(HOME)/.config/shortsync/shortcut-files && cp -nru config/* -t $(HOME)/.config/shortsync/
	chmod 777 $(HOME)/.config/shortsync/*
	sudo cp -f $(TARGET).1 -t /usr/share/man/man1
	sudo mkdir -p /usr/share/licenses/$(TARGET) && sudo cp -f LICENSE -t /usr/share/licenses/$(TARGET)
	sudo mkdir -p /usr/share/doc/$(TARGET) && sudo cp -f README.md -t /usr/share/doc/$(TARGET)
	sudo cp -f bin/$(TARGET) -t /usr/local/bin

uninstall: clean
	sudo rm -rf ~/.config/shortsync
