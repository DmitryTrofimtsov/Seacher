#include "pch.h"
#include "AObserver.h"

const int size_max = 64;

void MyPath::HandleEvent(const std::shared_ptr<FileSystem>& fSys)
{
	if (fSys->GetObserverPaths().empty()) {
		std::cout << "File is not exist.\n";
		return;
	}

	std::cout << "\nNumber of files found: " << fSys->GetObserverPaths().size() << std::endl;
	for (const auto& p : fSys->GetObserverPaths()) {
		std::cout << *p << std::endl;

		std::ifstream in(p->string(), std::ios_base::in | std::ios_base::binary);
		if (in.is_open()) {
			char buf[size_max];
			in.seekg(0, std::ios::beg);
			in.getline(buf, size_max);
			std::cout << buf << std::endl;
			in.close();
		}
	}
}

const std::shared_ptr<std::string>& MyPath::GetName() const
{
	return m_name;
}
