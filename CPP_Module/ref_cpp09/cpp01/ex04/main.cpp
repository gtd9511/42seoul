#include "replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	Replace rep(argv[1], argv[2], argv[3]);
	rep.do_replace();
}