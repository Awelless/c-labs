all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	gcc -o target/main/repair src/main/main.c -lm

buildTest:
	mkdir -p target/test
	gcc -o target/test/repairTest -Dmain=_main src/main/main.c src/test/mainTest.c -lm

runTest:
	./target/test/repairTest

clean:
	rm -rf target