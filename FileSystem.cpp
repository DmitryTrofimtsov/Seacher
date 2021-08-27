#include "pch.h"
#include "FileSystem.h"


void FileSystem::SearchPath(const std::shared_ptr<std::string>& searchFile)
{
	if (searchFile->find("*.", 0) != std::string::npos) {
		searchFile->erase(0, 1);
		SearchFileUsingMask(searchFile);
	}
	else {
		SearchFileUsingName(searchFile);
	}
}

const std::list<std::shared_ptr<fs::path>>& FileSystem::GetObserverPaths() const
{
	return m_observerPaths;
}

void FileSystem::NotifyObserver()
{
	m_observer->HandleEvent(this->shared_from_this());
}

void FileSystem::SearchFileUsingName(const std::shared_ptr<std::string>& searchFile)
{
	std::vector<fs::path> pathes{ fs::recursive_directory_iterator(*m_rootFile), {} };
	fs::path search_file{ *searchFile };

	for (auto& p : pathes) {

		if (p.filename() == search_file) {
			m_observerPaths.push_back(std::make_shared<fs::path>(p));
		}
	}
	NotifyObserver();
}

void FileSystem::SearchFileUsingMask(const std::shared_ptr<std::string>& searchFile)
{
	std::vector<fs::path> pathes{ fs::recursive_directory_iterator(*m_rootFile), {} };

	for (auto& p : pathes) {

		//std::cout << *searchFile << std::endl;

		if (p.filename().string().find(*searchFile) != std::string::npos) {
			m_observerPaths.push_back(std::make_shared<fs::path>(p));
		}
	}
	NotifyObserver();
}
