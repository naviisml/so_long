# C Minilibx Boilerplate

This is a C Boilerplate for my future C projects on Codam using Minilibx. This boilerplate allows me to start projects swiftly with a pre-made template.

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
git clone https://github.com/naviisml/c-minilibx-boilerplate.git
```

**Step 2. Add the submodules**

```
git submodule init
git submodule update
```

### Debian/Ubuntu

**Step 1. Install this repository**

```
git clone https://github.com/naviisml/c-minilibx-boilerplate.git
```

**Step 2. Add the submodules**

```
git submodule init
git submodule update
```

**Step 3. Installing the dependencies**

```
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
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
