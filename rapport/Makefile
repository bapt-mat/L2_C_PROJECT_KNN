SOURCE = rapport

LATEX_CMD = pdflatex

LATEX_OPTIONS = -interaction=nonstopmode

all: $(SOURCE).pdf

$(SOURCE).pdf: $(SOURCE).tex
	$(LATEX_CMD) $(LATEX_OPTIONS) $(SOURCE).tex
	$(LATEX_CMD) $(LATEX_OPTIONS) $(SOURCE).tex

clean:
	rm -f *.out *.aux *.log *.nav *.snm *.toc

clean_all:
	rm -f *.pdf *.out *.aux *.log *.nav *.snm *.toc
