cc=gcc
flags=-Wall -Wextra -Werror

all: masterDB

masterDB: modules_db.o shared.o master_modules.o master_levels.o master_status_events.o test.o
	$(cc) modules_db.o shared.o master_modules.o master_levels.o master_status_events.o test.o -o masterDB
modules_db.o: modules_db.c
	$(cc) $(flags) -c modules_db.c
shared.o: shared.c
	$(cc) $(flags) -c shared.c
master_modules.o: master_modules.c
	$(cc) $(flags) -c master_modules.c
master_levels.o: master_levels.c
	$(cc) $(flags) -c master_levels.c
master_status_events.o: master_status_events.c
	$(cc) $(flags) -c master_status_events.c
# ------
test.o: test.c
	$(cc) $(flags) -c test.c
# ------
clean:
	rm -f *.o
	rm -f masterDB
rebuild: clean all
do:
# do default DB
	rm -f ../materials/*.db
	cp ../materials/new_folder/*.db ../materials/
run:
	clear
	make rebuild
	rm -f *.o
	clear
	./masterDB
git:
	git add shared*
	git add modules_db*
	git add master_*   
	git add test.*