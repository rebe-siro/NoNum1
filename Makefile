TARGET=app

build:
	g++ *.cpp -o $(TARGET)

brun: build
	./$(TARGET)

run:
	./$(TARGET)
