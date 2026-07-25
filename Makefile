all: build

build:
	@mkdir -p build
	@cd build && cmake .. && cmake --build .
	@echo ""
	@echo "========================================="
	@echo " Build Success!"
	@echo " Run your program using the command below:"
	@echo " ./build/shared_Ptr.tsk"
	@echo " Run your tests using the command below:"
	@echo " ./build/test/tests.tsk"
	@echo "========================================="
	@echo ""

clean:
	@rm -rf build
	@echo "Build directory cleaned."

.PHONY: all build clean
