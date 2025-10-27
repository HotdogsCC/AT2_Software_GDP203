#pragma once
#include <iostream>
#include <fstream>

//old error logger that is not a singleton
class ErrorLogger
{
private:
	// private file handle
	std::ofstream* outputFile;

public:
	//constructor opens file
	ErrorLogger()
	{
		outputFile = new std::ofstream("errorLog.txt");
	}

	//destructor closes file
	~ErrorLogger()
	{
		outputFile->close();
	}

	//write error to log file
	void LogError(const char* errorString)
	{
		(*outputFile) << errorString << '\n';
	}
};

//new error logger that IS a singleton
class SingletonErrorLogger
{
private:
	std::ofstream* outputFile;

	//private construct/destructor
	SingletonErrorLogger()
	{
		outputFile = new std::ofstream("errorLog.txt");
	}
	~SingletonErrorLogger()
	{
		outputFile->close();
	}

public:
	//get the static instance of our class
	static SingletonErrorLogger& GetInstance()
	{
		static SingletonErrorLogger instance;
		return instance;
	}

	//log a string into the output text file
	void LogError(const char* error)
	{
		*outputFile << error << '\n';
	}
};

//singleton template class
template <typename T>
class Singleton
{
public:
	static T& GetInstance()
	{
		static T instance;
		return instance;
	}
protected:
	Singleton() {}
	~Singleton() {}
public:
	//disable copy and assignment constructors
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
};

//error logger using template
class ErrorLoggerTemplatedSingleton : public Singleton<ErrorLoggerTemplatedSingleton>
{
private:
	friend class Singleton<ErrorLoggerTemplatedSingleton>;
	std::ofstream* outputFile;
	ErrorLoggerTemplatedSingleton()
	{
		outputFile = new std::ofstream("errorLog.txt");
	}

public:
	void LogError(const char* errorString)
	{
		(*outputFile) << errorString << std::endl;
	}
};
