#pragma once
#include "pch.h"
#include "FileSystem.h"

class FileSystem;

class AObserver
{
public:
	virtual ~AObserver() {};

	virtual void HandleEvent(const std::shared_ptr<FileSystem>&) = 0;
};

class MyPath : public AObserver
{
public:
	MyPath(const std::shared_ptr<std::string>& name) : m_name { name } {}
	virtual void HandleEvent(const std::shared_ptr<FileSystem>&) override;

	const std::shared_ptr<std::string>& GetName() const;

private:
	std::shared_ptr<std::string> m_name;
};