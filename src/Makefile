
ifdef MINGW_PREFIX
MINGW=1
else
LINUX=1
endif

# Lua version
LUAVER?=5.3

# Base install directory
ifdef LINUX
PREFIX?=/usr/local
endif
ifdef MINGW
PREFIX?=$(MINGW_PREFIX)
endif

# Directory where to install Lua modules
L_DIR=$(PREFIX)/share/lua/$(LUAVER)
# Directory where to install Lua C modules
C_DIR=$(PREFIX)/lib/lua/$(LUAVER)
# Directory where to install C headers
H_DIR=$(PREFIX)/include
# Directory where to install C libraries
S_DIR=$(PREFIX)/lib

ifeq ($(D),1)
DEBUG=1
endif

LIBS += `pkg-config --libs lua${LUAVER}` -L./../thirdparty/nanovg/build -lnanovg

ifdef LINUX
LIBS += -lGLEW -lGLU -lGL -lm
endif
ifdef MINGW
LIBS += -lopengl32 -lglew32
endif

# INCDIR = -I./../thirdparty/LuaAutoC -I./../thirdparty/nanovg/src -I./../thirdparty/nanosvg/src
INCDIR = -I./../thirdparty/nanovg/src -I./../thirdparty/nanosvg/src

Tgt	:= lunavg
Src := $(wildcard *.c)
Objs := $(Src:.c=.o)
 
COPT	+= -O2
COPT	+= -O0 -g
#COPT	+= -m32
COPT	+= -Wall -Wextra -Wpedantic
COPT	+= -Wno-unused-function
ifdef MINGW
COPT	+= -Wno-implicit-fallthrough #@@
endif
COPT	+= -std=c11
COPT	+= `pkg-config --cflags lua${LUAVER}`
COPT	+= -DLUAVER=$(LUAVER)
ifdef LINUX
COPT	+= -fPIC
COPT	+= -DLINUX
endif
ifdef MINGW
COPT	+= -DMINGW
endif
ifdef DEBUG
COPT	+= -DDEBUG
COPT	+= -Wshadow -Wsign-compare -Wundef -Wwrite-strings
COPT	+= -Wdisabled-optimization -Wdeclaration-after-statement
COPT	+= -Wmissing-prototypes -Wstrict-prototypes -Wnested-externs
COPT	+= -Wc++-compat -Wold-style-definition
endif

OEXT := so
ifdef MINGW
OEXT := dll
endif

# override CFLAGS = $(COPT) $(INCDIR) -L./../thirdparty/LuaAutoC -llautoc -L./../thirdparty/nanovg/build -lnanovg
override CFLAGS = $(COPT) $(INCDIR) -L./../thirdparty/nanovg/build -lnanovg

default: build

libnanovg_build:
	@echo "Building nanovg"
	@cd ../thirdparty/nanovg;	premake4 --platform=x32 gmake && cd build && $(MAKE) nanovg config=release64

libnanovg_clean:
	@echo "Cleaning nanovg"
	@cd ../thirdparty/nanovg/build &&	$(MAKE) clean

test:
	@echo "Testing"
	lua$(LUAVER) tests.lua

where:
	@echo "PREFIX="$(PREFIX)
	@echo "LUAVER="$(LUAVER)
	@echo $(L_DIR)
	@echo $(C_DIR)
	@echo $(H_DIR)
	@echo $(S_DIR)

clean: libnanovg_clean
	@-rm -f *.$(OEXT) *.o *.err *.map *.S *~ *.log
	@-rm -f $(Tgt).symbols

install:
	@-mkdir -pv $(H_DIR)
	@-mkdir -pv $(C_DIR)
	@-mkdir -pv $(S_DIR)
	@-mkdir -pv $(L_DIR)
	@-cp -fpv $(Tgt).h $(H_DIR)
	@-cp -fpvr ../$(Tgt) $(L_DIR)
	@-cp -fpv $(Tgt).$(OEXT) $(C_DIR)
ifdef MINGW
	@-cp -fpv $(Tgt).$(OEXT) $(C_DIR)
else
	@-ln -fsv $(C_DIR)/$(Tgt).$(OEXT) $(S_DIR)/lib$(Tgt).$(OEXT)
endif

uninstall:
	@-rm -f $(H_DIR)/$(Tgt).h
	@-rm -f $(C_DIR)/$(Tgt).$(OEXT)
	@-rm -f $(S_DIR)/lib$(Tgt).$(OEXT)
	@-rm -fr $(L_DIR)/$(Tgt)
	@-rm -f $(C_DIR)/$(Tgt).$(OEXT)

build: libnanovg_build $(Tgt)

symbols: build
	@objdump -T $(Tgt).$(OEXT) > $(Tgt).symbols

$(Tgt):		$(Objs)
	@echo "Building target $(Tgt)"
	@-$(CC) -shared -o $(Tgt).$(OEXT) $(Objs) $(LIBDIR) $(LIBS)
	@-rm -f $(Objs)
	@echo
