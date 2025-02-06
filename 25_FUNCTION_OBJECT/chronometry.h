// chronometry.h
#include <chrono>
#include <iostream>
#include <functional> // std::invoke

// github.com/codenuri/CPPINTER_V3 에서
// cmc.h 파일의 아래 부분에
// class stop_watch 이후 모든 코드 복사하세요

class stop_watch
{
	std::chrono::system_clock::time_point start;
	bool log_at_finish;
public:
	stop_watch(bool b = false) : log_at_finish(b) { start = std::chrono::system_clock::now(); }
	~stop_watch() { if (log_at_finish) log(); }

	std::chrono::duration<double> stop()
	{
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

		return std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	}
	void log()
	{
		std::cout << stop().count() << " seconds." << std::endl;
	}
};


template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args)
{
	stop_watch sw(true);
	return std::invoke(std::forward<F>(f), std::forward<Types>(args)...);
}