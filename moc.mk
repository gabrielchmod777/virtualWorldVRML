moc_%.cpp : src/%.h
	$(MOC) -I. -Isrc $< -o $@

clean-moc-extra:
	rm -vf src/moc_*.cpp

clean-am: clean-moc-extra