#include <stdio.h>
#include <sqlite3.h>
// #include <string.h>


// https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
int main(int argc, char *argv[]) {
	// database name
	char dbName[] = "example.db";
	// 
	sqlite3 *db;
	FILE *dbFile;
	
	if (dbFile = fopen(dbName, "r")) {
		fclose(dbFile);
	}
	else {
		char *sql = "CREATE TABLE WEBPAGE("  \
		"URL        TEXT NOT NULL," \
		"TITLE      TEXT," \
		"COMMENT    TEXT);";
		sqlite3_open(dbName, &db);
		sqlite3_exec(db, sql, NULL, NULL, NULL);
		sqlite3_close(db);
		printf("not here\n");
	}
	
	
	
	
	
	
	
	
	
	
}
	/*
	if(sqlite3_open_v2(dbName, &db, 2, NULL)) {
		printf("error opening database\n");
	}
	
	sqlite3_close(db);
	
	
	
	*/
	
	/*
	if(strcmp(argv[1], "-a") == 0) 
	{
		// 2nd argument is url
		// duplicate error
		
		
		
		printf("add\n");
	}
	else if(strcmp(argv[1], "-s") == 0) 
	{
		// search* for extended search
		printf("search\n");
	}
	else if(strcmp(argv[1], "-e") == 0) 
	{
		// -u = url, -t = tag, -c = comment, = title
		printf("edit\n");
	}
	else if(strcmp(argv[1], "-d") == 0) 
	{
		// delete/remove
		printf("delete\n");
	}
	
	
	
	return 0;
}
*/
/*
webpage
	url
	title
	comment

tag
	name

webpage_tag
	webpage_rowid
	tag_rowid

add 
search
edit
*/











