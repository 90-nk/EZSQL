#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include "../Save/saver.h"
#include "../Index/BPlusTreewhy.h"

// 将输入字符串分割为单词
std::vector<std::string> tokenize(const std::string& str) {
    std::istringstream iss(str);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

// 处理CREATE DATABASE命令
void handleCreateDatabase(const std::vector<std::string>& tokens) {
    if (tokens.size() != 3) {
        std::cout << "Syntax error in CREATE DATABASE command\n";
        return;
    }
    std::string dbName = tokens[2];
    std::cout << "Creating database: " << dbName << "\n";
    // 这里添加创建数据库的逻辑
    createDatabase(dbName);
}

void handleCreateTable(const std::vector<std::string>& tokens, const std::string& dbName) {
    if (tokens.size() < 3
    && tokens[2] != "("
    && tokens[tokens.size() - 1] != ")") {
        std::cout << "Syntax error in CREATE DATABASE command\n";
        return;
    }
    std::string tbName = tokens[2];
    std::cout << "Creating Table " << tbName << "\n";
    // 这里添加创建数据库的逻辑
    createTable(tbName, dbName);//表的创建
    


}

//处理DROP命令
void handleDropDatabase(const std::vector<std::string>& tokens) {
    if (tokens.size() != 3) {
        std::cout << "Syntax error in DROP DATABASE command\n";
        return;
    }
    std::string dbName = tokens[2];
    std::cout << "Dropping database: " << dbName << "\n";
    // 这里添加删除数据库的逻辑
    

}

void handleDropTable(const std::vector<std::string>& tokens) {
    if (tokens.size() != 3) {
        std::cout << "Syntax error in DROP TABLE command\n";
        return;
    }
    std::string tbName = tokens[2];
    std::cout << "Dropping Table " << tbName << "\n";
    // 这里添加删除数据库的逻辑

}

//处理USE命令
void handleUseDatabase(const std::vector<std::string>& tokens) {
    if (tokens.size() != 2) {
        std::cout << "Syntax error in USE DATABASE command\n";
        return;
    }
    std::string dbName = tokens[1];
    std::cout << "Using database: " << dbName << "\n";
    // 这里添加使用数据库的逻辑

}

//处理SELECT命令
void handleSelect(const std::vector<std::string>& tokens) {
    if (tokens.size() != 4) {//未完成where条件子句
        std::cout << "Syntax error in SELECT command\n";
        return;
    }
    std::string tbName = tokens[3];
    std::string column = tokens[1];
    std::cout << "Selecting" << column << "from table: " << tbName << "\n";
    // 这里添加查询的逻辑

}

//处理INSERT命令
void handleInsert(const std::vector<std::string>& tokens) {
    if (tokens.size() != 4) {//未完成插入括号内的值
        std::cout << "Syntax error in INSERT command\n";
        return;
    }
    std::string tbName = tokens[3];
    std::cout << "Inserting into table: " << tbName << "\n";
    // 这里添加插入的逻辑

}

//处理DELETE命令
void handleDelete(const std::vector<std::string>& tokens) {
    if (tokens.size() != 4) {//未完成where条件子句
        std::cout << "Syntax error in DELETE command\n";
        return;
    }
    std::string tbName = tokens[3];
    std::cout << "Deleting from table: " << tbName << "\n";
    // 这里添加删除的逻辑

}
//处理UPDATE命令
void handleUpdate(const std::vector<std::string>& tokens) {
    if (tokens.size() != 4) {
        std::cout << "Syntax error in UPDATE command\n";
        return;
    }
    std::string tbName = tokens[3];
    std::cout << "Updating table: " << tbName << "\n";
    // 这里添加更新的逻辑

}





// 解析器主函数
void parseSQL(const std::string& sql) {
    auto tokens = tokenize(sql);
    if (tokens.empty()) return;

    if (tokens[0] == "CREATE" && tokens.size() > 1) {//CREATE命令
        if (tokens[1] == "DATABASE") {
            handleCreateDatabase(tokens);//处理CREATE DATABASE命令
        } else if (tokens[1] == "TABLE") {
            // 处理CREATE TABLE命令
            std::cout << "Please input the name of database: ";
            std::string dbName;
            std::cin >> dbName;
            handleCreateTable(tokens, dbName);//处理CREATE TABLE命令
            
        }
        // 其他CREATE命令...
    } else if (tokens[0] == "DROP" && tokens.size() > 1) {//DROP命令
        if(tokens[1] == "DATABASE") {
            handleDropDatabase(tokens);//处理DROP DATABASE命令
        } else if (tokens[1] == "TABLE") {
            handleDropTable(tokens);//处理DROP TABLE命令
        }
        
    } else if (tokens[0] == "USE") {//USE命令
        handleUseDatabase(tokens);//处理USE DATABASE命令
    } else if (tokens[0] == "SELECT") {
        handleSelect(tokens);//处理SELECT命令
    } else if (tokens[0] == "INSERT") {
        handleInsert(tokens);//处理INSERT命令
    } else if (tokens[0] == "DELETE") {
        handleDelete(tokens);//处理DELETE命令
    } else if (tokens[0] == "UPDATE") {
        handleUpdate(tokens);//处理UPDATE命令
    } else {
        std::cout << "Unknown command: " << tokens[0] << "\n";
        return;
    }

}

int main() {
    //语法解析测试
    std::string sql;
    while (std::getline(std::cin, sql)  && sql != "exit") {
        parseSQL(sql);
    }


    // B+树测试
    BPlusTree<int, int> tree(3, {{1, 'A'}, {5, 'B'}, {7, 'C'}, {9, 'D'}, {10, 'E'}});
    tree.print();
}
