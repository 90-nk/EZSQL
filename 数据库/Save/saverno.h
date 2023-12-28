// database_operations.h
#ifndef DATABASE_OPERATIONS_H
#define DATABASE_OPERATIONS_H

#include <string>

// 声明 createDatabase 函数
void createDatabase(const std::string& dbname);

// 声明 createTable 函数
void createTable(const std::string& tbname, const std::string& dbname);

#endif // DATABASE_OPERATIONS_H
