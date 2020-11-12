SRC = unity/unity_source.c\
src/interview.c\
test/interview_test.c\
main.c

INC = -Iunity\
-Iinc\
-Itest

PROJECT_NAME = INTERVIEW.exe

BUILD = build
$(PROJECT_NAME): $(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME)

run:$(PROJECT_NAME)
	./${PROJECT_NAME}
doc:
	make -C documentation

clean:
	rm -rf $(PROJECT_NAME) documentation/html
