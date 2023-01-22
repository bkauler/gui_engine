ifdef WORKDIR
# compiling in OE
CFLAGS = -I$(WORKDIR)/recipe-sysroot/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT
else
# CFLAGS  = `sdl-config --cflags`
# no, sdl-config is broken on some systems
CFLAGS = -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT
endif
LDFLAGS = -lSDL -lSDL_gfx -lSDL_ttf -lfreetype -lpng16 -lz

.PHONY: all run clean
all: example ask-lang

example: example.c example-theme.c gui_engine.c
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

ask-lang: ask-lang.c example-theme.c gui_engine.c
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

run: example
	./example

clean:
	- rm example
