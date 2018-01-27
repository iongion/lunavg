
default: build

build install uninstall where test:
	@cd src;		$(MAKE) $@

clean :
	@cd src;		$(MAKE) $@

cleanall: clean

backup: clean
