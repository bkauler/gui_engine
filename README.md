## gui_engine

Please read the original README here:

https://github.com/AlxHnr/gui_engine/blob/master/README.md

This fork of gui_engine is intended to create statically-linked standalone executables to run in the initramfs (initrd) of a Linux operation system, rendering to the Linux framebuffer.

The original example.c statically-linked with musl, SDL 1.2, is 306KB.
Converted from the 8x8 fonts inbuilt to SDL_gfx to TTF, again statically-linked with SDL, SDL_ttf, freetype and png, is 560KB. Snapshot with RobotoMono TTF:

![example-ttf](https://github.com/bkauler/gui_engine/example-ttf.png)

The build environment, that cross-compiles the packages, with musl and static libraries, is at the author's oe-qky-kirkstone project:

https://github.com/bkauler/oe-qky-kirkstone

Currently the project is on hold, for a couple of reasons. One of them is this:

https://github.com/AlxHnr/gui_engine/issues/4

The second reason is that the author would like the UI to be usable via keyboard. TAB key to move between widgets, up-down arrows to select items in drop-down list, ENTER key to choose.
