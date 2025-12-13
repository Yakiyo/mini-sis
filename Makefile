files := main.cpp db/db.cpp db/student.cpp sqlite/sqlite3.o

build: $(files)
	g++ -o main $(files) -Isqlite

sql:
	gcc -o sqlite/sqlite3.o -c sqlite/sqlite3.c