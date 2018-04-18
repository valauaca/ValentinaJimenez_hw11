pos.png vel.png phase.png: try.txt VJ_graph.py

	python VJ_graph.py

try.txt: ./a.out

	./a.out> try.txt

a.out: ValentinaJimenez_hw11.cpp
	c++ ValentinaJimenez_hw11.cpp
	
