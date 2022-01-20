# so_long

This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.

## Features

- ???

## Requirements

- gcc
- make
- MacOS Dependencies:
	- OpenGL
- Linux Dependencies:
	- X11 include files (package xorg)
	- XShm extension must be present (package libxext-dev)
	- Utility functions from BSD systems - development files (package libbsd-dev)

## Installation

### MacOS

**Step 1. Install this repository**

```
git clone https://github.com/naviisml/so_long.git
```

**Step 2. Add the submodules**

```
git submodule init
git submodule update
```

### Debian/Ubuntu

**Step 1. Installing the dependencies**

```
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

**Step 2. Install this repository**

```
git clone https://github.com/naviisml/so_long.git
```

**Step 3. Add the submodules**

```
git submodule init
git submodule update
```

## Usage

### MacOS

```
make all
```

```
./so_long <path/to/map.ber>
```

### Debian/Ubuntu

```
make all -f Makefile.linux
```

```
./so_long <path/to/map.ber>
```

## Map

The maps used for this game must be made with the following rules in mind;
- Map must be rectangular
- Map must contain one exit
- Map must contain one collectible
- Map must contain one starting position
- Map must be surrounded by walls
- Map can be composed of only these 5 characters:
	- 0 for an empty space
	- 1 for a wall
	- C for a collectible
	- E for a map exit
	- P for the player’s starting position

**Simple example**

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

<div align=center>Made with tons of ☕ and ❤️ by <a href="https://github.com/naviisml">Navi</a></div>
