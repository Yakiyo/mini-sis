files := main.cpp sqlite/sqlite3.o src/db.cpp

build: $(files)
	g++ -o main $(files) -Isqlite

sql:
	gcc -o sqlite/sqlite3.o -c sqlite/sqlite3.c