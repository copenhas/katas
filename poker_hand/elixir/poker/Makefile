.PHONY: test tags

default: tags test

test:
	mix test

tags:
	ctags -R .

check:
	dialyzer ./ebin --fullpath --no_check_plt -Wno_return
