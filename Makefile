build-release: src/project.xml.log
	cd src && \
	make build-release
	@cp src/build/cmake-build-release/compile_commands.json .

upload-release: src/project.xml.log
	cd src && \
	make upload-release
	@cp src/build/cmake-build-release/compile_commands.json .

build-debug: src/project.xml.log
	cd src && \
	make build-debug
	@cp src/build/cmake-build-release/compile_commands.json .

upload-debug: src/project.xml.log
	cd src && \
	make upload-debug
	@cp src/build/cmake-build-release/compile_commands.json .

.PHONY: build-release
.PRECIOUS: src/project.xml.log

LBUILD_EXE?=lbuild
src/project.xml.log: src/project.xml
	cd src && \
	$(LBUILD_EXE) build && \
	make cmake
