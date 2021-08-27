#include "pch.h"
#include "FileSystem.h"


int main()
{
    std::string dir, file;
    std::cout << "Enter directory: ->";
    std::getline(std::cin, dir);
    std::cout << "Enter file or directory: ->";
    std::getline(std::cin, file);

    auto File = std::make_shared<MyPath>(std::make_shared<std::string>(file));

    if (fs::exists(fs::path(dir))) {
        auto FSystem = std::make_shared<FileSystem>(std::make_shared<std::string>(dir), File);
        FSystem->SearchPath(File->GetName());
    }
    else {
        std::cout << "ERROR! Directory " << dir << " is not exist!\n";
    }
    return 0;
}


