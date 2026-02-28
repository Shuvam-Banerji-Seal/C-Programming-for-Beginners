MODULES := 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20
PDFS := $(addprefix module-,$(addsuffix .pdf,$(MODULES)))
LATEX := pdflatex
LATEXFLAGS := -interaction=nonstopmode

.PHONY: all clean

all: $(PDFS)

# pdflatex is run twice so that cross-references, the table of contents,
# and page numbers are resolved correctly (the first pass collects them,
# the second pass inserts them).
module-%.pdf: module-%.tex
	$(LATEX) $(LATEXFLAGS) $<
	$(LATEX) $(LATEXFLAGS) $<

define MODULE_RULE
.PHONY: module-$(1)
module-$(1): module-$(1).pdf
endef

$(foreach m,$(MODULES),$(eval $(call MODULE_RULE,$(m))))

clean:
	rm -f *.pdf *.aux *.log *.out *.toc *.nav *.snm *.vrb
