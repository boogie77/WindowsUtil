#pragma once
#include "IPeImage.h"
#include "DosHeader.h"
#include "DosStub.h"
#include "NtHeader.h"
#include "SectionHeaders.h"
#include "DataDirectoryEntries.h"
namespace PeDecoder
{
	// FIX: 需要限制buffer最大长度（有时候没办法获取,从pe记录中获取的大小不能保证不是恶意的值，在偏移nt头的时候就有可能被恶意值定向到其它地方）
	// 否则会发生任意位置读写问题
	class PeImage :
		public IPeImage
	{
	public:
		PeImage(void* ptr, bool isMapped);
		// 是否是映射的
		virtual bool IsMapped() const override;
		virtual bool IsPe() const override;
		virtual void* GetBase() const override;
		virtual ImageType GetImageType() const override;
		// 必存在结构
		virtual const unique_ptr<DosHeader>& GetDosHeader() const override;
		virtual unique_ptr<DosStub> GetDosStub() const override;
		virtual const unique_ptr<NtHeader>& GetNtHeader() const override;
		virtual const unique_ptr<SectionHeaders>& GetSections() const override;

		virtual bool HasDirectory(DataDirectoryEntryType index) const override;
		virtual PIMAGE_DATA_DIRECTORY GetDirectoryEntry(DataDirectoryEntryType index) const override;
		virtual DWORD RvaToOffset(DWORD rva) const override;
		virtual ULONGLONG RvaToOffset(ULONGLONG rva) const override;
		virtual DWORD OffsetToRva(DWORD fileOffset) const override;
		virtual PVOID RvaToDataPtr(DWORD rva) const override;
		virtual PVOID RvaToDataPtr(ULONGLONG rva) const override;

	protected:
		PeImage(const PeImage&) = delete;
		PeImage& operator=(const PeImage&) = delete;


		unique_ptr<DosHeader> dosHeader_;
		unique_ptr<NtHeader> ntHeader_;
		mutable unique_ptr<SectionHeaders> sectionHeaders_;

		unsigned char* base_;
		ImageType imageType_;
		bool isPe_;
		bool isMapped_;
		bool hasNtHeader32_;


	};

}  // namespace PeDecoder
