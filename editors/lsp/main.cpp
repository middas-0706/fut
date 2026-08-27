// main.cpp - Language Server Protocol (LSP) server
//
// Copyright (C) 2026  Piotr Fusik
//
// This file is part of Fusion Transpiler,
// see https://github.com/fusionlanguage/fut
//
// Fusion Transpiler is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Fusion Transpiler is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Fusion Transpiler.  If not, see http://www.gnu.org/licenses/

#include <iostream>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

#include "lsp.hpp"

class CppFusionLanguageServer : public FusionLanguageServer
{
protected:
	std::string readStdin(int length) const override
	{
		std::string result(length, '\0');
		std::cin.read(&result.front(), length);
		if (!std::cin)
			result.clear();
		return result;
	}
};

int main()
{
#ifdef _WIN32
	_setmode(_fileno(stdin), _O_BINARY);
	_setmode(_fileno(stdout), _O_BINARY);
	_setmode(_fileno(stderr), _O_BINARY);
#endif
	CppFusionLanguageServer s;
	return s.serve();
}
