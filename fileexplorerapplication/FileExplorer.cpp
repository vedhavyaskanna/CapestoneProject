#include "FileExplorer.h"
#include <fstream>
#include <sys/stat.h>
using namespace std;
FileExplorer::FileExplorer() : currentPath(".")
{
}

void FileExplorer::listFiles()
{
    for (const auto& entry : filesystem::directory_iterator(currentPath))
        cout << entry.path() << endl;
}

void FileExplorer::changeDirectory(const string& path)
{
    if (std::filesystem::exists(path) && filesystem::is_directory(path))
    {
        currentPath = path;
    }
    else
     {
        cout << "Invalid directory path" << endl;
    }
}

void FileExplorer::copyFile(const string& src, const string& dest)
 {
    filesystem::copy(src, dest);
}

void FileExplorer::moveFile(const string& src, const string& dest)
 {
    filesystem::rename(src, dest);
}

void FileExplorer::deleteFile(const string& path)
{
    filesystem::remove(path);
}

void FileExplorer::createFile(const string& path)
{
    std::ofstream outfile(path);
    outfile.close();
}

void FileExplorer::searchFiles(const std::string& name)
{
    for (const auto& entry : filesystem::recursive_directory_iterator(currentPath))
    {
        if (entry.path().filename().string().find(name) != string::npos)
         {
            cout << entry.path() << endl;
        }
    }
}

void FileExplorer::changePermissions(const string& path, mode_t mode)
{
    if (chmod(path.c_str(), mode) != 0)
    {
        cout << "Failed to change file permissions" << std::endl;
    }
}

string FileExplorer::getCurrentPath() const {
    return currentPath;
}




