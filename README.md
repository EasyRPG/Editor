# EasyRPG Editor

EasyRPG Editor is a game editor to create EasyRPG games. It can import
RPG Maker 2000 and 2003 games using liblcf to read RPG Maker game data.

EasyRPG Editor is part of the EasyRPG Project. More information is
available at the project website: https://easyrpg.org/


## Documentation

Documentation is available at the documentation wiki: https://wiki.easyrpg.org


## Requirements

- [liblcf] for RPG Maker data reading.
- [Qt] (>= 5.2)
- Qt multimedia


## Daily builds

Up to date binaries for assorted platforms are available at our continous
integration service:

https://ci.easyrpg.org/view/Editor-Qt/


## Source code

EasyRPG Editor development is hosted by GitHub, project files are available
in this git repository:

https://github.com/EasyRPG/Editor-Qt

Released versions are also available at our Download Archive:

https://easyrpg.org/downloads/editor/


## Building

Building requirements:

- CMake

Step-by-step instructions:

    cmake . # generate Makefile
    make    # compile the executable

    
## Running EasyRPG Editor

Run the generated executable in the "bin" folder.


## Bug reporting

Available options:

* File an issue at https://github.com/EasyRPG/Editor-Qt/issues
* Open a thread at https://community.easyrpg.org/
* Chat with us via IRC: [#easyrpg at irc.freenode.net]


## License

EasyRPG Editor is free software available under the GPLv3 license.
See the file [COPYING] for license conditions.


[liblcf]: https://github.com/EasyRPG/liblcf
[Qt]: https://www.qt.io
[#easyrpg at irc.freenode.net]: https://kiwiirc.com/nextclient/#ircs://irc.freenode.net/#easyrpg?nick=rpgguest??
[COPYING]: COPYING
