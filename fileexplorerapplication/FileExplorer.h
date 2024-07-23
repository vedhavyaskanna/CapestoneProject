#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <iostream>
#include <string>
#include <filesystem>

class FileExplorer {
private:
    std::string currentPath;

public:
    FileExplorer();
    void listFiles();
    void changeDirectory(const std::string& path);
    void copyFile(const std::string& src, const std::string& dest);
    void moveFile(const std::string& src, const std::string& dest);
    void deleteFile(const std::string& path);
    void createFile(const std::string& path);
    void searchFiles(const std::string& name);
    void changePermissions(const std::string& path, mode_t mode);
    std::string getCurrentPath() const;
};

#endif // FILEEXPLORER_H