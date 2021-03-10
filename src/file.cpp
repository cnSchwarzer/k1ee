﻿#include "k1ee/k1ee.h"  
#include <fstream> 

std::vector<uint8_t> k1ee::read_all_bytes(const std::filesystem::path& path)
{
	using namespace std::filesystem;
	
	if(!exists(path) || is_directory(path))
		throw k1ee::k1ee_runtime_error("file doesn't exist."); 

	auto size = file_size(path);
	
	std::vector<uint8_t> ret(size);

	std::ifstream fin(path, std::ios::binary);

	if(fin.fail())
		throw k1ee::k1ee_runtime_error("open file failed");

	fin.read(reinterpret_cast<char*>(ret.data()), size);

	if(fin.fail())
		throw k1ee::k1ee_runtime_error("read file failed");
	
	return ret;
}

void k1ee::write_all_bytes(const std::filesystem::path& path, const uint8_t* data, size_t size)
{
	using namespace std::filesystem;

	std::ofstream fout(path, std::ios::binary);

	fout.write(reinterpret_cast<const char*>(data), size);
}
