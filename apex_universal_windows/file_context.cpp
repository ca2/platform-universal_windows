#include "framework.h"
#include "file_context.h"
#include "file_system.h"
#include "dir_system.h"
#include "acme/filesystem/file/exception.h"
#include "acme/filesystem/file/status.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/filesystem/filesystem/acme_path.h"
#include "acme/include/_c_swap.h"
#include "apex/platform/system.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include "acme_universal_windows/native_buffer.h"


#include "_winrt_storage.h"


#include "acme/_operating_system.h"


#include <winrt/Windows.Storage.FileProperties.h>
//#include "_windows_runtime.h"

namespace apex_universal_windows
{


   file_context::file_context()
   {

   }


   file_context::~file_context()
   {

   }


   void file_context::initialize(::particle * pparticle)
   {

      //auto estatus = 

      ::object::initialize(pparticle);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      ::pointer<::apex::system>psystem = acmesystem();

      m_pfilesystem = psystem->m_pfilesystem;

      m_pdirsystem =psystem->m_pdirsystem;

      //      return ::success;

   }


   void file_context::init_system()
   {

      //auto estatus =

//      m_pfilesystem->update_module_path();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return ::success;

   }


   void file_context::calculate_main_resource_memory()
   {

      m_memoryMainResource = as_memory("_matter.zip");

   }


   //bool file_context::FullPath(string & str, const ::string & pszFileIn)

   //{

   //   //if(::apex::file_context::FullPath(str, pszFileIn))

   //   // return true;

   //   if (pszFileIn.case_insensitive_begins("http://"))

   //   {

   //      str = pszFileIn;


   //      return true;

   //   }
   //   else if (pszFileIn.case_insensitive_begins("https://"))

   //   {

   //      str = pszFileIn;


   //      return true;

   //   }
   //   wstring wstrFileIn;
   //   wstrFileIn = utf8_to_unicode(pszFileIn);

   //   wstring wstrFileOut;
   //   bool b = windows_full_path(wstrFileOut.get_buffer(MAX_PATH * 8), wstrFileIn) != false;
   //   if (b)
   //   {
   //      unicode_to_utf8(str, wstrFileOut);
   //   }
   //   return b;
   //}

   //bool file_context::FullPath(wstring & wstrFullPath, const wstring & wstrPath)
   //{

   //   /*      if(::apex::file_context::FullPath(wstrFullPath, wstrPath))
   //   return true;*/

   //   if (wstrPath.case_insensitive_begins(L"http://"))
   //   {
   //      wstrFullPath = wstrPath;
   //      return true;
   //   }
   //   else if (wstrPath.case_insensitive_begins(L"https://"))
   //   {
   //      wstrFullPath = wstrPath;
   //      return true;
   //   }

   //   return windows_full_path(wstrFullPath, wstrPath) != false;

   //}


   //::u32 file_context::GetFileName(const ::string & pszPathName, string & str)

   //{
   //   i32 nMax = MAX_PATH * 8;
   //   wstring wstrPathName;
   //   wstrPathName = utf8_to_unicode(pszPathName);

   //   wstring wstrTitle;
   //   ::u32 user = vfxGetFileName(wstrPathName, wstrTitle.get_buffer(nMax), nMax);
   //   str = unicode_to_utf8(wstrTitle);
   //   return user;
   //}

   //void file_context::GetModuleShortFileName(HINSTANCE hInst, string & strShortName)
   //{
   //   vfxGetModuleShortFileName(hInst, strShortName);
   //}


   ::file::enum_type file_context::get_type(const ::file::path& path)
   {

      auto etype = ::file_context::get_type(path);

      if (etype != ::file::e_type_unknown)
      {

         return etype;

      }

      return acmepath()->get_type(path);

   }


   ::payload file_context::length(const ::file::path & path)
   {

      //::payload varRet;

      //varRet = ::file_context::length(path);

      //if (!varRet.is_null())
      //{
      // 
      //   return varRet;

      //}

      string strRelative = path;

      string strPrefix;

      auto folder = windows_runtime_folder(this, strRelative, strPrefix);

      if (folder)
      {

         auto hstrName = __hstring(strRelative);

         auto item = folder.TryGetItemAsync(hstrName).get();

         if (item)
         {

            if (item.IsOfType(winrt::Windows::Storage::StorageItemTypes::File))
            {
               
               winrt::Windows::Storage::StorageFile file=nullptr;

               item.as(file);

               if (file)
               {

                  auto basicproperties = file.GetBasicPropertiesAsync().get();

                  if (basicproperties)
                  {

                     return basicproperties.Size();

                  }

               }

            }

         }

      }

      WIN32_FILE_ATTRIBUTE_DATA data;

      if (GetFileAttributesExW(wstring(path), GetFileExInfoStandard, &data))
      {
         
         return make64_from32(data.nFileSizeLow, data.nFileSizeHigh);

      }

      return ::e_type_null;

   }


   ::payload file_context::length(const ::file::path & path, ::payload * pvarQuery)
   {

      // TODO: I don't remember what pvarQuery is used for, in the time of reimplementation
      // of this function. Maybe you should consider it in some case(s).

      return ::file_context::length(path, pvarQuery);

   }


   void file_context::transfer(const ::file::path & pszNew, const ::file::path & psz)
   {

      auto file = windows_runtime_file(this, psz, 0, 0, OPEN_EXISTING, 0);

      if (file == nullptr)
      {

         throw ::exception(error_io, "file::file_context::move Could not move file, could not open source file");

      }

      string strDirOld = psz.folder();
      string strDirNew = pszNew.folder();
      string strNameOld = psz.name();
      string strNameNew = pszNew.name();

      if (strDirOld == strDirNew)
      {

         if (strNameOld == strNameNew)
         {

            return;

         }
         else
         {

            auto hstrNameNew = __hstring(strNameNew);

            file.RenameAsync(hstrNameNew).get();

         }

      }
      else
      {

         string strPrefix;

         ::winrt::Windows::Storage::StorageFolder folder = windows_runtime_folder(this, strDirNew, strPrefix);

         if (strNameOld == strNameNew)
         {

            file.MoveAsync(folder).get();

         }
         else
         {
            
            auto hstrNameNew = __hstring(strNameNew);
            
            file.MoveAsync(folder, hstrNameNew).get();

         }

      }

   }


   void file_context::erase(const ::file::path & psz)
   {

      acmefile()->erase(psz);
      //{
      //
      //   return error_failed;

      //}

      //return ::success;

   }


   bool file_context::is_read_only(const ::file::path & psz)
   {

#ifdef WINDOWS_DESKTOP

      u32 dwAttrib = windows_get_file_attributes(psz);

      if (dwAttrib & FILE_ATTRIBUTE_READONLY)
      {

         return true;

      }

      return false;

#elif defined(UNIVERSAL_WINDOWS)

      //throw ::exception(todo);

#else

      struct stat st;

      if (stat(psz, &st) != 0)
         return true;

      return !(st.st_mode & S_IWUSR);

#endif

      return false;

   }


   file_pointer file_context::resource_get_file(const ::file::path & path)
   {

#ifdef WINDOWS_DESKTOP

      auto pfile = create_memory_file();

      int iId = atoi(path);

      string strExtension = path.final_extension();

      strExtension.make_upper();

      const scoped_string & str = strExtension;

      if (strExtension == "HTML")
      {

         psz = (const ::string &)RT_HTML;

      }

      ::pointer<::apex::system>psystem = acmesystem();

      if (read_resource_as_memory(*pfile->get_primitive_memory(), (HINSTANCE) psystem->m_hinstance, iId, psz))
      {

         return pfile;

      }

#else

      throw_todo();

#endif

      return nullptr;

   }


   bool file_context::get_last_write_time(FILETIME * pfiletime, const ::string & strFilename)
   {

      WIN32_FILE_ATTRIBUTE_DATA data;

      zero(data);

      if (!GetFileAttributesExW(wstring(strFilename), GetFileExInfoStandard, &data))
      {

         return false;

      }

      *pfiletime = data.ftLastWriteTime;

      return true;

   }


   //void file_context::get_status(::file::file_status & rStatus, const ::file::path & path)
   //{

   //   auto pathFull = acmepath()->_final(path);

   //   wstring wstrFullName(pathFull);

   //   WIN32_FIND_DATAW findFileData;
   //   
   //   HANDLE hFind = FindFirstFileW((LPWSTR)(const ::wide_character *)wstrFullName, &findFileData);
   //   
   //   if (hFind == INVALID_HANDLE_VALUE)
   //   {
   //    
   //      DWORD lasterror = ::GetLastError();

   //      auto estatus = ::windows::last_error_status(lasterror);

   //      throw ::exception(estatus);

   //   }

   //   FindClose(hFind);

   //   rStatus.m_attribute = (::u8)(findFileData.dwFileAttributes & ~FILE_ATTRIBUTE_NORMAL);

   //   rStatus.m_filesize = make64_from32(findFileData.nFileSizeLow, findFileData.nFileSizeHigh);

   //   file_time_to_time(&rStatus.m_ctime.m_time, (file_time_t *)&findFileData.ftCreationTime);
   //   file_time_to_time(&rStatus.m_atime.m_time, (file_time_t *)&findFileData.ftLastAccessTime);
   //   file_time_to_time(&rStatus.m_mtime.m_time, (file_time_t *)&findFileData.ftLastWriteTime);

   //   if (rStatus.m_ctime.get_time() == 0)
   //   {

   //      rStatus.m_ctime = rStatus.m_mtime;

   //   }

   //   if (rStatus.m_atime.get_time() == 0)
   //   {

   //      rStatus.m_atime = rStatus.m_mtime;

   //   }

   //}

   //void file_context::set_status(const ::file::path & path,const ::file::file_status& status)
   //{

   //   wstring pszFileName(path);

   //   ::u32 wAttr;
   //   FILETIME creationTime;
   //   FILETIME lastAccessTime;
   //   FILETIME lastWriteTime;
   //   LPFILETIME pCreationTime = nullptr;

   //   LPFILETIME pLastAccessTime = nullptr;

   //   LPFILETIME pLastWriteTime = nullptr;


   //   if((wAttr = windows_get_file_attributes((LPWSTR)(const ::wide_character *)pszFileName)) == (::u32)-1L)

   //      file_exception::throw_os_error((::i32)GetLastError());

   //   if((::u32)status.m_attribute != wAttr && (wAttr & readOnly))
   //   {
   //      // set file attribute, only if currently readonly.
   //      // This way we will be able to modify the time assuming the
   //      // caller changed the file from readonly.

   //      if(!SetFileAttributesW((LPWSTR)(const ::wide_character *)pszFileName,(::u32)status.m_attribute))

   //         file_exception::throw_os_error((::i32)GetLastError());
   //   }

   //   // last modification time
   //   if(status.m_mtime.get_time() != 0)
   //   {
   //      ::apex::TimeToFileTime(status.m_mtime,&lastWriteTime);
   //      pLastWriteTime = &lastWriteTime;


   //      // last access time
   //      if(status.m_atime.get_time() != 0)
   //      {
   //         ::apex::TimeToFileTime(status.m_atime,&lastAccessTime);
   //         pLastAccessTime = &lastAccessTime;

   //      }

   //      // create time
   //      if(status.m_ctime.get_time() != 0)
   //      {
   //         ::apex::TimeToFileTime(status.m_ctime,&creationTime);
   //         pCreationTime = &creationTime;

   //      }

   //      HANDLE hFile = ::CreateFileW((LPWSTR)(const ::wide_character *)pszFileName,GENERIC_READ | GENERIC_WRITE,

   //         FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,
   //         nullptr);

   //      if(hFile == INVALID_HANDLE_VALUE)
   //         file_exception::throw_os_error((::i32)::GetLastError());

   //      if(!SetFileTime((HANDLE)hFile,pCreationTime,lpLastAccessTime,lpLastWriteTime))

   //         file_exception::throw_os_error((::i32)::GetLastError());

   //      if(!::CloseHandle(hFile))
   //         file_exception::throw_os_error((::i32)::GetLastError());
   //   }

   //   if((::u32)status.m_attribute != wAttr && !(wAttr & readOnly))
   //   {
   //      if(!SetFileAttributes((char *)pszFileName,(::u32)status.m_attribute))

   //         file_exception::throw_os_error((::i32)GetLastError());
   //   }
   //}


   //void file::SetStatus(const ::string & pszFileName,const ::file::file_status& status)

   //{
   //   ::u32 wAttr;
   //   FILETIME creationTime;
   //   FILETIME lastAccessTime;
   //   FILETIME lastWriteTime;
   //   LPFILETIME pCreationTime = nullptr;

   //   LPFILETIME pLastAccessTime = nullptr;

   //   LPFILETIME pLastWriteTime = nullptr;


   //   if((wAttr = GetFileAttributes((char *)pszFileName)) == (::u32)-1L)

   //      file_exception::throw_os_error((::i32)GetLastError());

   //   if((::u32)status.m_attribute != wAttr && (wAttr & readOnly))
   //   {
   //      // set file attribute, only if currently readonly.
   //      // This way we will be able to modify the time assuming the
   //      // caller changed the file from readonly.

   //      if(!SetFileAttributes((char *)pszFileName,(::u32)status.m_attribute))

   //         file_exception::throw_os_error((::i32)GetLastError());
   //   }

   //   // last modification time
   //   if(status.m_mtime.get_time() != 0)
   //   {
   //      ::apex::TimeToFileTime(status.m_mtime,&lastWriteTime);
   //      pLastWriteTime = &lastWriteTime;


   //      // last access time
   //      if(status.m_atime.get_time() != 0)
   //      {
   //         ::apex::TimeToFileTime(status.m_atime,&lastAccessTime);
   //         pLastAccessTime = &lastAccessTime;

   //      }

   //      // create time
   //      if(status.m_ctime.get_time() != 0)
   //      {
   //         ::apex::TimeToFileTime(status.m_ctime,&creationTime);
   //         pCreationTime = &creationTime;

   //      }

   //      HANDLE hFile = ::CreateFile(pszFileName,GENERIC_READ | GENERIC_WRITE,

   //         FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,
   //         nullptr);

   //      if(hFile == INVALID_HANDLE_VALUE)
   //         file_exception::throw_os_error((::i32)::GetLastError());

   //      if(!SetFileTime((HANDLE)hFile,pCreationTime,lpLastAccessTime,lpLastWriteTime))

   //         file_exception::throw_os_error((::i32)::GetLastError());

   //      if(!::CloseHandle(hFile))
   //         file_exception::throw_os_error((::i32)::GetLastError());
   //   }

   //   if((::u32)status.m_attribute != wAttr && !(wAttr & readOnly))
   //   {
   //      if(!SetFileAttributes((char *)pszFileName,(::u32)status.m_attribute))

   //         file_exception::throw_os_error((::i32)GetLastError());
   //   }
   //}

   
   //void file_context::set_status(const ::file::path & path, const ::file::file_status & status)
   //{

   //   wstring pszFileName(path);


   //   ::u32 wAttr;
   //   FILETIME creationTime;
   //   FILETIME lastAccessTime;
   //   FILETIME lastWriteTime;
   //   LPFILETIME pCreationTime = nullptr;

   //   LPFILETIME pLastAccessTime = nullptr;

   //   LPFILETIME pLastWriteTime = nullptr;


   //   if ((wAttr = ::windows::get_file_attributes(path)) == (::u32)INVALID_FILE_ATTRIBUTES)
   //   {

   //      auto dwLastError = ::GetLastError();

   //      auto estatus = ::windows::last_error_status(dwLastError);

   //      auto errorcode = ::windows::last_error_error_code(dwLastError);

   //      throw ::file::exception(estatus, errorcode, path, "!::windows_get_file_attributes");

   //   }

   //   if ((::u32)status.m_attribute != wAttr && (wAttr & FILE_ATTRIBUTE_READONLY))
   //   {
   //      // set file attribute, only if currently readonly.
   //      // This way we will be able to modify the time assuming the
   //      // caller changed the file from readonly.

   //      if (!SetFileAttributesW((LPWSTR)(const ::wide_character *)pszFileName, (::u32)status.m_attribute))
   //      {

   //         auto dwLastError = ::GetLastError();

   //         auto estatus = ::windows::last_error_status(dwLastError);

   //         auto errorcode = ::windows::last_error_error_code(dwLastError);

   //         throw ::file::exception(estatus, errorcode, pszFileName, "!::SetFileAttributes");

   //      }

   //   }

   //   // last modification time
   //   if (status.m_mtime.get_time() != 0)
   //   {
   //      
   //      time_to_file_time((file_time_t *) &lastWriteTime, &status.m_mtime.m_time);

   //      pLastWriteTime = &lastWriteTime;

   //      // last access time
   //      if (status.m_atime.get_time() != 0)
   //      {

   //         time_to_file_time((file_time_t *)&lastAccessTime, &status.m_atime.m_time);

   //         pLastAccessTime = &lastAccessTime;

   //      }

   //      // create time
   //      if (status.m_ctime.get_time() != 0)
   //      {

   //         time_to_file_time((file_time_t *)&creationTime, &status.m_ctime.m_time);

   //         pCreationTime = &creationTime;

   //      }

   //      HANDLE hFile = hfile_create(path, GENERIC_READ | GENERIC_WRITE,

   //         FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
   //         nullptr);

   //      if (hFile == INVALID_HANDLE_VALUE)
   //      {

   //         auto dwLastError = ::GetLastError();

   //         auto estatus = ::windows::last_error_status(dwLastError);

   //         auto errorcode = ::windows::last_error_error_code(dwLastError);

   //         throw ::file::exception(estatus, errorcode, path, "hfile_create == INVALID_HANDLE_VALUE");

   //      }

   //      if (!SetFileTime((HANDLE)hFile, pCreationTime, pLastAccessTime, pLastWriteTime))
   //      {

   //         auto dwLastError = ::GetLastError();

   //         auto estatus = ::windows::last_error_status(dwLastError);

   //         auto errorcode = ::windows::last_error_error_code(dwLastError);

   //         throw ::file::exception(estatus, errorcode, path, "!::SetFileTime");

   //      }

   //      if (!::CloseHandle(hFile))
   //      {

   //         auto dwLastError = ::GetLastError();

   //         auto estatus = ::windows::last_error_status(dwLastError);

   //         auto errorcode = ::windows::last_error_error_code(dwLastError);

   //         throw ::file::exception(estatus, errorcode, path, "!::CloseHandle");

   //      }

   //   }

   //   if ((::u32)status.m_attribute != wAttr && !(wAttr & FILE_ATTRIBUTE_READONLY))
   //   {

   //      if (!SetFileAttributesW((LPWSTR)(const ::wide_character *)pszFileName, (::u32)status.m_attribute))
   //      {

   //         auto dwLastError = ::GetLastError();

   //         auto estatus = ::windows::last_error_status(dwLastError);

   //         auto errorcode = ::windows::last_error_error_code(dwLastError);

   //         throw ::file::exception(estatus, errorcode, pszFileName, "!::SetFileAttributesW");

   //      }

   //   }

   //   //return ::success;

   //}


   //::e_status file_context::update_module_path()
   //{

   //   auto estatus = ::file_context::update_module_path();

   //   if(!estatus)
   //{
   //   
   //   return estatus;
   //   
   //}

   //   return estatus;

   //}

   


   file_pointer file_context::get_file(const ::payload & payloadFile, ::file::e_open eopen, ::pointer < ::file::exception > * ppfileexception)
   {

      return ::apex_windows_common::file_context::get_file(payloadFile, eopen, ppfileexception);

   }


   ::file_pointer file_context::create_native_file(const ::file::path & path, ::file::e_open eopen, ::pointer < ::file::exception > * ppfileexception)
   {

      if (::windows::is_win32_accessible(path))
      {

         return ::apex_windows_common::file_context::create_native_file(path, eopen, ppfileexception);

      }

      string strRelative = path;

      string strPrefix;

      auto folder = windows_runtime_folder(m_pcontext, strRelative, strPrefix);

      if (folder)
      {

         auto hstrName = __hstring(strRelative);

         auto item = folder.TryGetItemAsync(hstrName).get();

         if (!item)
         {

            item = folder.CreateFileAsync(hstrName).get();

         }

         if (item.IsOfType(::winrt::Windows::Storage::StorageItemTypes::File))
         {

            ::winrt::Windows::Storage::StorageFile file = nullptr;

            item.as(file);

            if (file)
            {

               auto pfile = __new(::acme_universal_windows::native_buffer(file, eopen));

               return pfile;

            }

         }

      }

      ::file_pointer pfile;

      m_pcontext->__construct(pfile);

      pfile->open(path, eopen);

      return pfile;

   }


   ::file::path file_context::dropbox_info_network_payload()
   {

      //::file::path pathJson;

      //pathJson = acmedirectory()->user_appdata_local() / "Dropbox/info.json";

      //return pathJson;

      return {};

   }


} // namespace apex_universal_windows


