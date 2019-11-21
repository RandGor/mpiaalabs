#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "sha256.h"
#include "bruteforce.h"
#include "conio.h"

typedef std::chrono::high_resolution_clock hrc;

namespace {
	class Timer {
	public:
		Timer() {}

		void start() {
			begin = hrc::now();
		}

		double getTime() {
			return std::chrono::duration<double>(hrc::now() - begin).count();
		}

	private:
		hrc::time_point begin;
	};
}

int main(int argc, char* argv[]) {
    int result = Catch::Session().run(argc, argv);

	std::string alphabet = "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	Timer t;

	for (int alen = 5; alen <= 10; alen++)
	{
		for (int wlen = 6; wlen <= 10; wlen++)
		{
			t.start();
			std::vector<std::string> words = all_words(alphabet.substr(0, alen), wlen);
			std::string pass = words[rand() % words.size()];
			bruteforce(alphabet.substr(0, alen), wlen, sha256(pass));
			

			printf("Alphabet: %d, Length: %d, time: %10.5f sec\n",alen,wlen, t.getTime());
		}
	}
	_getch();
    return result;
}
