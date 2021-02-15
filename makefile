PDFDIR=rapport


pdf: $(PDFDIR)/rapport.pdf

$(PDFDIR)/rapport.pdf:
	cd $(PDFDIR)/; pdflatex -synctex=1 -interaction=nonstopmode rapport.tex; cd ../..

clean:
	rm -rf $(PDFDIR)/*.pdf
