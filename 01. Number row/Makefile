all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	gcc -o target/main/number src/main/main.c

buildTest:
	mkdir -p target/test
	gcc -o target/test/numberTest -Dmain=_main src/main/main.c src/test/mainTest.c

runTest:
	./target/test/numberTest

clean:
	rm -rf target