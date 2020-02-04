main: build/rd_route.o build/speedhack.o
	gcc build/*.o -dynamiclib -o dist.dylib	
build/rd_route.o: build
	gcc rd_route/rd_route.c -c -o build/rd_route.o
build/speedhack.o: build
	gcc speedhack.c -c -o build/speedhack.o
build:
	mkdir build
clean:
	rm -rf build
	rm dist.dylib