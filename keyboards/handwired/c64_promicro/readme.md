# c64_promicro

![c64_promicro](https://www.sparkfun.com/media/catalog/product/cache/a793f13fd3d678cea13d28206895ba0c/1/2/12640-01a.jpg)

*C64 keyboard wired to a pro micro USB board*

* Keyboard Maintainer: [jeanpihet](https://github.com/jeanpihet)
* Hardware Supported: promicro
* Hardware Availability: [Sparkun Pro Micro](https://www.sparkfun.com/pro-micro-5v-16mhz.html)

Keyboard matrix from http://sta.c64.org/cbm64kbdlay.html

Make example for this keyboard (after setting up your build environment):
    qmk compile -kb handwired/c64_promicro -km default

Flashing example for this keyboard:
    qmk flash -kb handwired/c64_promicro -km default
    Press Reset button twice


See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
