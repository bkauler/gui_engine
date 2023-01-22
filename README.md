## gui_engine

Please read the original README here:

https://github.com/AlxHnr/gui_engine/blob/master/README.md

This fork of gui_engine is intended to create statically-linked standalone executables to run in the initramfs (initrd) of a Linux operation system, rendering to the Linux framebuffer.

The original example.c statically-linked with musl, SDL 1.2, is 306KB.
Converted from the 8x8 fonts inbuilt to SDL_gfx to TTF, again statically-linked with SDL, SDL_ttf, freetype and png, is 560KB. Snapshot with RobotoMono TTF:

![example-ttf](https://user-images.githubusercontent.com/4200448/213897154-78b1d1eb-ded3-4a78-a87e-b1a0fb806d0e.png)

The build environment, that cross-compiles the packages, with musl and static libraries, is at the author's oe-qky-kirkstone project:

https://github.com/bkauler/oe-qky-kirkstone

Currently the project is on hold, for a couple of reasons. One of them is this:

https://github.com/AlxHnr/gui_engine/issues/4

The second reason is that the author would like the UI to be usable via keyboard. TAB key to move between widgets, up-down arrows to select items in drop-down list, ENTER key to choose.

There are posts about gui_engine on the author's blog; for example:

https://bkhome.org/news/202301/guiengine-project-put-on-hold.html
