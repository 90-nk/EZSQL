#include <filesystem>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct ColumnInfo {
    std::string name;
    std::string type;
    bool isPrimary;

    ColumnInfo(std::string name, std::string type, bool isPrimary = false)
        : name(std::move(name)), type(std::move(type)), isPrimary(isPrimary) {}
};


struct TableInfo {
    std::vector<ColumnInfo> columns;
};




void createDatabase(const std::string& dbname) {
    std::filesystem::path savePath = "./Save/db"; // 设置数据库路径
    try {
        if (std::filesystem::create_directory(savePath)) {
            std::cout << "Database saver not exist, CREATING one\n";
        } else {
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    std::filesystem::path dbPath = "./Save/db/dbsave" + dbname; // 设置数据库路径
    try {
        if (std::filesystem::create_directory(dbPath)) {
            std::cout << "Database " << dbname << " created successfully.\n";
        } else {
            std::cout << "Database " << dbname << " already exists.\n";
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void createTable(const std::string& tbname, const std::string& dbname) {
    std::filesystem::path tbPath = "./Save/db/" + dbname + "/"+ (tbname + ".csv"); // 设置数据库路径
    TableInfo tableInfo;
    try {
        if (!std::filesystem::exists(tbPath)) {
            std::ofstream tableFile(tbPath);
            // 写入列头
            for (size_t i = 0; i < tableInfo.columns.size(); ++i) {
                tableFile << tableInfo.columns[i].name;
                if (i < tableInfo.columns.size() - 1) tableFile << ",";
            }
            tableFile << "\n";

            std::cout << "Tablefile " << tbname << " created successfully.\n";
            
        } else {
            std::cout << "Table " << tbname << " already exists.\n";
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}



int main() {
    TableInfo studentsTable;
    studentsTable.columns.push_back(ColumnInfo("id", "int", true));
    studentsTable.columns.push_back(ColumnInfo("name", "string"));

    createTable("studentsTable", "dbsave");
    return 0;
}