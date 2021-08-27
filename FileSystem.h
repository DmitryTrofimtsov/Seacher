#pragma once
#include "pch.h"
#include "AObserver.h"

class AObserver;

class FileSystem : public std::enable_shared_from_this<FileSystem>
{
public:
	FileSystem(const std::shared_ptr<std::string>& rootFile, const std::shared_ptr<AObserver>& observer)
		: m_rootFile{ rootFile }, m_observer{observer} {}

	void SearchPath(const std::shared_ptr<std::string>&);
	const std::list<std::shared_ptr<fs::path>>& GetObserverPaths() const;

private:
	std::shared_ptr<std::string> m_rootFile;
	std::shared_ptr<AObserver> m_observer;
	std::list<std::shared_ptr<fs::path>> m_observerPaths;

	void NotifyObserver();
	void SearchFileUsingName(const std::shared_ptr<std::string>& searchFile);
	void SearchFileUsingMask(const std::shared_ptr<std::string>& searchFile);
};

