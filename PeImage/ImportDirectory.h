#pragma once
#include "PeImageFwd.h"
#include "DirectoryBase.h"
namespace PeDecoder
{
	// UNDONE: 
	class ImportDirectory :
		public Detail::DirectoryBase<DataDirectoryEntryType::Import>
	{
	public:
		typedef ImportDirectoryIterator iterator;
		// 这里的size表示整个结构包括thunk和name的大小
		using DirectoryBase::DirectoryBase;
		iterator begin();
		iterator end();
	};

	

}  // namespace PeDecoder
