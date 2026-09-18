#include <iostream>
#include <mysqlx/xdevapi.h> // Main header for X DevAPI

int main() {
    try {
        // Establish connection session
        mysqlx::Session sess("mysqlx://root:manjeet@2002#@127.0.0.1:3306");
        
        // Select schema (database)
        mysqlx::Schema db = sess.getSchema("test_db");
        
        // Execute a traditional SQL statement
        mysqlx::SqlResult result = sess.sql("SELECT id, name FROM users").execute();
        
        // Loop through rows
        for (mysqlx::Row row : result.fetchAll()) {
            std::cout << "ID: " << row[0] << " | Name: " << row[1] << std::endl;
        }
    } 
    catch (const mysqlx::Error &err) {
        std::cerr << "Error: " << err.what() << std::endl;
    }
    return 0;
}