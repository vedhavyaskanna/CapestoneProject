#include "FileExplorer.h"
using namespace std;
int main()
{
    FileExplorer explorer;
    string command, path, dest;
    while (true)
     {
        cout << "Current Directory: " << explorer.getCurrentPath() << endl;
        cout << "Commands: ls---> , cd---> , cp--->, mv--->, rm--->, touch--->, search--->, chmod--->, exit." << endl;
        cout << "> ";
        cin >> command;

        if (command == "ls")
        {
            explorer.listFiles();
        }
        else if (command == "cd")
        {
            cin >> path;
            explorer.changeDirectory(path);
        }
        else if (command == "cp")
        {
            cin >> path >> dest;
            explorer.copyFile(path, dest);
        }
        else if (command == "mv")
        {
            cin >> path >> dest;
            explorer.moveFile(path, dest);
        }
         else if (command == "rm")
         {
            cin >> path;
            explorer.deleteFile(path);
        }
        else if (command == "touch")
         {
            cin >> path;
            explorer.createFile(path);
        }
        else if (command == "search")
        {
            cin >> path;
            explorer.searchFiles(path);
        }
        else if (command == "chmod")
         {
            mode_t mode;
            cin >> path >> std::oct >> mode;
            explorer.changePermissions(path, mode);
        }
         else if (command == "exit")
         {
            break;
        }
         else
         {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
