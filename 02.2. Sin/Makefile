all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	gcc -o target/main/sin src/main/main.c -lm

buildTest:
	mkdir -p target/test
	gcc -o target/test/sinTest -Dmain=_main src/main/main.c src/test/mainTest.c -lm

runTest:
	./target/test/sinTest

clean:
	rm -rf target