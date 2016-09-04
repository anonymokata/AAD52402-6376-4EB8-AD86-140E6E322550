SUBDIRS = src tests

.PHONY: all $(SUBDIRS)
all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

tests: src


SUBCLEAN = $(addsuffix .clean,$(SUBDIRS))
.PHONY: clean $(SUBCLEAN)
clean: $(SUBCLEAN)
$(SUBCLEAN): %.clean:
	$(MAKE) -C $* clean


SUBTEST = $(addsuffix .test,tests)
.PHONY: test $(SUBTEST)
test: $(SUBTEST)
$(SUBTEST): %.test:
	$(MAKE) -C $* test
