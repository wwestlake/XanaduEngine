#ifndef XANADU_SINGLE_INCLUDE_XANADUUTILITIES_H
#define XANADU_SINGLE_INCLUDE_XANADUUTILITIES_H


#ifdef XANADUUTILITIES_EXPORTS
#define XANADUUTILITIES_API __declspec(dllexport)
#else
#define XANADUUTILITIES_API __declspec(dllimport)
#endif

#include <string>


namespace Xanadu {
	namespace Utilities {
		class XANADUUTILITIES_API TextFile {
		public:

			TextFile(std::string filename) : _filename(filename)
			{
				_filesize = FileSize();
				_fileContents = ReadTextFile();
			}

			size_t GetFileSize() {
				return _filesize;
			}

			std::string GetContents() {
				return _fileContents;
			}

		private:
			std::string _filename;
			std::string _fileContents;
			size_t _filesize;

			std::string  ReadTextFile();
			size_t  FileSize();

		};
	}
}





#endif
