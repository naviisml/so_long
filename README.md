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

### Debian/Ubuntu

```
make all -f Makefile.linux
```

<div align=center>Made with tons of ☕ and ❤️ by <a href="https://github.com/naviisml">Navi</a></div>
