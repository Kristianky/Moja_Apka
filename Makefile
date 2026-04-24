prepare:
	rm -rf build
	mkdir build
Mingw:
	cmake -S . -B build -G "MinGW Makefiles"
Dependency:
	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o GraphImage

BServer:
	cmake --build build --target server
BApp:
	cmake --build build --target SiemensTCP