#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main( int argc, char **argv )
{
	std::string file_in_name;
	std::string file_out_name;

	int depth = 256;

	std::cout << "Input file name: ";
	std::cin >> file_in_name;

	std::cout << "Output file name: ";
	std::cin >> file_out_name;

	std::cout << "Count of words: ";
	std::cin >> depth;

	std::ifstream fin( file_in_name );
	std::ofstream fout( file_out_name );

	std::vector<uint8_t> buffer;

	char tmp;

	while ( fin.get(tmp) )
	{
		buffer.push_back( (int)tmp );
	}

	fout << "WIDTH=8;" << std::endl;
	fout << "DEPTH="<< depth <<";" << std::endl;

	fout << std::endl;

	fout << "ADDRESS_RADIX=UNS;" << std::endl;
	fout << "DATA_RADIX=UNS;" << std::endl;

	fout << std::endl;

	fout << "CONTENT BEGIN" << std::endl;

	for ( int i = 0; i < buffer.size(); i++ )
	{
		fout << "\t" << i << " : " << (int)buffer[i] << ";" << std::endl;
	}

	fout << "\t" << "[" << buffer.size() << ".."<< ( depth - 1 ) <<"] : 0;" << std::endl;

	fout << "END;" << std::endl;

	fin.close();
	fout.close();

    return 0;
}

