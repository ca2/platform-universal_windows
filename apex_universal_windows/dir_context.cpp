#include "framework.h"
#include "dir_context.h"
#include "dir_system.h"
#include "file_system.h"
#include "acme/constant/id.h"
//#include <Shlobj.h>
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/parallelization/task_flag.h"
#include "apex/platform/system.h"
#include "acme_universal_windows/acme_directory.h"


#include "acme/_operating_system.h"


#undef new
#include <winrt/Windows.Storage.h>
//#include "_windows_runtime.h"


namespace apex_universal_windows
{


   dir_context::dir_context()
   {


   }


   dir_context::~dir_context()
   {

   }


   void dir_context::initialize(::particle * pparticle)
   {

      //auto estatus = 
      
      ::object::initialize(pparticle);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      ::pointer<::apex::system>psystem = acmesystem();

      m_pfilesystem = psystem->m_pfilesystem;

      m_pdirsystem =  psystem->m_pdirsystem;

      string strPath = ::winrt::Windows::Storage::ApplicationData::Current().LocalFolder().Path().begin();

      INFORMATION("ApplicationData::Current().LocalFolder()=" << strPath);

      m_pathLocalFolder = strPath;

   }


   void dir_context::init_system()
   {

      //auto estatus = 
      
      ::dir_context::init_system();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //auto pdocument = create_xml_document();

      //if (pdocument->load(m_pcontext->m_papexcontext->file().as_string(::dir::appdata() / "configuration/directory.xml")))
      //{

      //   //xxdebug_box("win_dir::initialize (configuration)", "win_dir::initialize", 0);

      //   if (pdocument->root()->get_name() == "directory_configuration")
      //   {

      //      ::file::path pathFolderTime = pdocument->root()->get_child_value("time");

      //      if (m_pcontext->m_papexcontext->dir().is(pathFolderTime))
      //      {

      //         m_pdirsystem->m_strTimeFolder = pathFolderTime;

      //      }

      //      ::file::path pathFolderNetseed = pdocument->root()->get_child_value("netseed");

      //      if (m_pcontext->m_papexcontext->dir().is(pathFolderNetseed))
      //      {

      //         m_pdirsystem->m_strNetSeedFolder = pathFolderNetseed;

      //      }

      //   }

      //}

      //return ::success;

   }


   inline bool myspace(char ch)
   {
      return ch == ' ' ||
         ch == '\t' ||
         ch == '\r' ||
         ch == '\n';
   }



   //string dir_context::path(const ::string & pszFolder, strsize iLenFolder, const ::string & pszRelative, strsize iLenRelative, const ::string & psz2, strsize iLen2, bool bUrl)
   //{

   //   bool bEmptyRelative = iLenRelative == 0 || pszRelative == nullptr || *pszRelative == '\0';
   //   bool bEmpty2 = iLen2 == 0 || psz2 == nullptr || *psz2 == '\0';

   //   if(bEmptyRelative && bEmpty2)
   //      return pszFolder;

   //   string strPath;
   //   char * psz;


   //   if(bEmptyRelative)
   //   {
   //      pszRelative = psz2;
   //      iLenRelative = iLen2;
   //   }

   //   while((pszFolder[iLenFolder - 1] == '\\' || pszFolder[iLenFolder - 1] == '/') && iLenFolder > 0)
   //   {
   //      if(bUrl)
   //      {
   //         if((iLenFolder - 2) >= 0 && (pszFolder[iLenFolder - 2] == '\\' || pszFolder[iLenFolder - 2] == '/' || pszFolder[iLenFolder - 2] == ':'))
   //         {
   //            if(pszFolder[iLenFolder - 2] == ':')
   //            {
   //               break;
   //            }
   //            else
   //            {
   //               if((iLenFolder - 3) >= 0 && (pszFolder[iLenFolder - 3] == ':'))
   //               {
   //                  iLenFolder--;
   //                  break;
   //               }
   //            }
   //         }
   //         else
   //         {
   //            iLenFolder--;
   //         }
   //      }
   //      else
   //      {
   //         iLenFolder--;
   //      }
   //   }

   //   while(*pszRelative != '\0' && (*pszRelative == '\\' || *pszRelative == '/') && iLenRelative > 0)
   //   {
   //      pszRelative++;
   //      iLenRelative--;
   //   }

   //   if(bEmptyRelative || bEmpty2)
   //   {
   //      psz = strPath.get_buffer(iLenFolder + 1 + iLenRelative);

   //      ansi_count_copy(psz, pszFolder, iLenFolder);

   //      if(ansi_count_compare_ci(&psz[iLenFolder - 5], ".zip:", 5) == 0)

   //      {
   //         iLenFolder--;
   //      }
   //      else
   //      {
   //         psz[iLenFolder] = '/';

   //      }
   //      ansi_count_copy(&psz[iLenFolder + 1], pszRelative, iLenRelative);

   //      psz[iLenFolder + 1 + iLenRelative] = '\0';

   //      {
   //         if(bUrl)
   //         {
   //            while(*psz++ != '\0')

   //               if(*psz == '\\') *psz = '/';

   //         }
   //         else
   //         {
   //            while(*psz++ != '\0')

   //               if(*psz == '/') *psz = '\\';

   //         }
   //      }
   //      strPath.ReleaseBuffer(iLenFolder + 1 + iLenRelative);
   //      return strPath;
   //   }

   //   while((pszRelative[iLenRelative - 1] == '\\' || pszRelative[iLenRelative - 1] == '/') && iLenRelative > 0)
   //   {
   //      iLenRelative--;
   //   }

   //   while(*psz2 != '\0' && (*psz2 == '\\' || *psz2 == '/') && iLen2 > 0)
   //   {
   //      psz2++;
   //      iLen2--;
   //   }

   //   psz = strPath.get_buffer(iLenFolder + 1 + iLenRelative + 1 + iLen2);

   //   ansi_count_copy(psz, pszFolder, iLenFolder);

   //   psz[iLenFolder] = '/';

   //   ansi_count_copy(&psz[iLenFolder + 1], pszRelative, iLenRelative);

   //   psz[iLenFolder + 1 + iLenRelative] = '/';

   //   ansi_count_copy(&psz[iLenFolder + 1 + iLenRelative + 1], psz2, iLen2);

   //   psz[iLenFolder + 1 + iLenRelative + 1 + iLen2] = '\0';

   //   {
   //      if(bUrl)
   //      {
   //         while(*psz++ != '\0')

   //            if(*psz == '\\') *psz = '/';

   //      }
   //      else
   //      {
   //         while(*psz++ != '\0')

   //            if(*psz == '/') *psz = '\\';

   //      }
   //   }
   //   strPath.ReleaseBuffer(iLenFolder + 1 + iLenRelative + 1 + iLen2);
   //   return strPath;
   //}

   //string dir_context::relpath(const string & pcszSource,const string & lpcszRelative)

   //{
   //   const scoped_string & strRequest;
   //   if(::url::is_url(pcszSource,&pszRequest))

   //   {
   //      if(::str().begins(pcszRelative,astr.Slash))

   //      {
   //         return path((const ::string &)string(pcszSource,pszRequest - lpcszSource),lpcszRelative);

   //      }
   //      else if(*pszRequest == '\0' || ::str().ends(pcszSource,"/"))

   //      {
   //         return path(pcszSource,lpcszRelative);

   //      }
   //      else
   //      {
   //         return path((const ::string &)name(pcszSource),lpcszRelative);

   //      }
   //   }
   //   else
   //   {
   //      if(::str().ends(pcszSource,"\\") || ::str().ends(lpcszSource,"/"))

   //      {
   //         return path(pcszSource,lpcszRelative);

   //      }
   //      else
   //      {
   //         return path((const ::string &)name(pcszSource),lpcszRelative);

   //      }
   //   }
   //}


   //string dir_context::relpath(const string & pcszSource, const string & lpcszRelative, const string & psz2)

   //{
   //   const scoped_string & strRequest;
   //   if(::url::is_url(pcszSource, &pszRequest))

   //   {
   //      if(::str().begins(pcszRelative,astr.Slash))

   //      {
   //         return path((const ::string &) string(pcszSource, pszRequest - lpcszSource), lpcszRelative, psz2);

   //      }
   //      else if(*pszRequest == '\0' || pcszSource.ends("/"))

   //      {
   //         return path(pcszSource, lpcszRelative, psz2);

   //      }
   //      else
   //      {
   //         return path((const ::string &) name(pcszSource), lpcszRelative, psz2);

   //      }
   //   }
   //   else
   //   {
   //      if(pcszSource.ends("\\") || lpcszSource.ends("/"))

   //      {
   //         return path(pcszSource, lpcszRelative, psz2);

   //      }
   //      else
   //      {
   //         return path((const ::string &) name(pcszSource), lpcszRelative, psz2);

   //      }
   //   }
   //}

   ::file::listing & dir_context::root_ones(::file::listing & listing)
   {
      //::u32 dwSize = ::GetLogicalDriveStringsW(0, nullptr);
      //::acme::malloc < LPWSTR > pszAlloc;

      //pszAlloc.alloc((dwSize + 1) * sizeof(WCHAR));

      //LPWSTR psz = pszAlloc;

      //dwSize = ::GetLogicalDriveStringsW(dwSize + 1, psz);


      //string str;

      //while (*psz)
      //{

      //   str.empty();

      //   while (*psz)
      //   {

      //      str += *psz;

      //      psz++;

      //   }
      //   listing.add(::file::path(str));
      //   ::file::path & path = listing.last();
      //   path.m_iDir = 1;
      //   str.trim(":/\\");
      //   listing.m_straTitle.add("Drive " + str);
      //   psz++;

      //}

      return listing;


   }


   bool dir_context::enumerate(::file::listing & listing)
   {

      //if (listing.m_bRecursive)
      //{


      //   index iStart = listing.get_size();


      //   {

      //      __scoped_restore(listing.m_pathUser);

      //      __scoped_restore(listing.m_pathFinal);

      //      __scoped_restore(listing.m_eextract);

      //      if (::dir_context::ls(listing))
      //      {

      //         return true;

      //      }

      //      listing.m_estatus = ::success;

      //      ::file::listing dira;

      //      ls_dir(dira, listing.m_pathUser);

      //      for (i32 i = 0; i < dira.get_count(); i++)
      //      {

      //         ::file::path dir_context = dira[i];

      //         if (dir_context == listing.m_pathUser)
      //         {

      //            continue;

      //         }

      //         listing.m_pathUser = dir_context;

      //         if (listing.m_eextract != e_extract_all)
      //         {

      //            listing.m_eextract = e_extract_none;

      //         }

      //         m_pcontext->m_papexcontext->dir().ls(listing);

      //      }

      //   }

      //   //file_find file_find;

      //   //bool bWorking = file_find.find_file(listing.m_pathUser / "*") != false;

      //   //if (bWorking)
      //   //{

      //   //   while (bWorking)
      //   //   {

      //   //      bWorking = file_find.find_next_file() != false;

      //   //      if (!file_find.IsDots() && file_find.GetFilePath() != listing.m_pathUser)
      //   //      {

      //   //         if ((listing.m_bDir && file_find.IsDirectory()) || (listing.m_bFile && !file_find.IsDirectory()))
      //   //         {

      //   //            if (matches_wildcard_criteria_ci(listing.m_straPattern, file_find.GetFileName()))
      //   //            {

      //   //               listing.add(file_find.GetFilePath());

      //   //               listing.last().m_iSize = file_find.get_length();

      //   //               listing.last().m_iDir = file_find.IsDirectory() != false;

      //   //            }

      //   //         }

      //   //      }

      //   //   }

      //   //}
      //   //else
      //   //{

      //   //   listing.m_statusresult = ::error_failed;

      //   //}

      //   //for (index i = iStart; i < listing.get_size(); i++)
      //   //{

      //   //   listing[i].m_iRelative = listing.m_pathUser.get_length() + 1;

      //   //}

      //}
      //else
      //{

         if (::dir_context::enumerate(listing))
         {

            return true;

         }

         //listing.m_estatus = ::success;

         auto pacmedirectory = acmedirectory();

         return pacmedirectory->enumerate(listing);

         //if (listing.m_pathFinal.is_empty())
         //{

         //   listing.m_pathFinal = m_pcontext->m_papexcontext->defer_process_path(listing.m_pathUser);

         //}

      //   auto folder = windows_runtime_folder(this, listing.m_pathUser);

      //   if(folder)
      //   {

      //      winrt::Windows::Storage::Search::QueryOptions options;

      //      options.FolderDepth(::winrt::Windows::Storage::Search::FolderDepth::Shallow);

      //      auto items = folder.CreateItemQueryWithOptions(options).GetItemsAsync().get();

      //      for(auto item : items)
      //      {

      //         bool bFolder = item.IsOfType(::winrt::Windows::Storage::StorageItemTypes::Folder);

      //         bool bFile = item.IsOfType(::winrt::Windows::Storage::StorageItemTypes::File);
      //         
      //         if ((listing.m_bDir && bFolder)|| (listing.m_bFile && bFile))
      //         {

      //            string strName = item.Name().begin();

      //            if (strName.case_insensitive_begins("resident_"))
      //            {

      //               TRACE("resident_*");
      //            }

      //            if (matches_wildcard_criteria_ci(listing.m_straPattern, strName))
      //            {

      //               string strPath = item.Path().begin();

      //               listing.add(strPath);

      //               auto basic_properties = item.GetBasicPropertiesAsync().get();

      //               listing.last().m_iSize = basic_properties.Size();

      //               listing.last().m_iDir = bFolder ? 1 : 0;

      //            }

      //         }

      //      }

      //   }

      //}

      //return listing;

   }


   //bool dir_context::ls_relative_name(::file::listing & listing)
   //{


   //   if (listing.m_bRecursive)
   //   {

   //      // to finish;

   //      index iStart = listing.get_size();

   //      {

   //         __scoped_restore(listing.m_pathUser);

   //         __scoped_restore(listing.m_pathFinal);

   //         __scoped_restore(listing.m_eextract);

   //         if (::dir_context::ls(listing))
   //         {

   //            //listing.m_statusresult = ::error_failed;

   //            return true;

   //         }

   //         listing.m_estatus = ::success;

   //         ::file::listing dira;

   //         ls_dir(dira, listing.m_pathUser);

   //         for (i32 i = 0; i < dira.get_count(); i++)
   //         {

   //            ::file::path dir_context = dira[i];

   //            if (dir_context == listing.m_pathUser)
   //            {

   //               continue;

   //            }

   //            listing.m_pathUser = dir_context;

   //            if (listing.m_eextract != e_extract_all)
   //            {

   //               listing.m_eextract = e_extract_none;

   //            }

   //            m_pcontext->m_papexcontext->dir().ls(listing);

   //         }

   //      }

   //      //file_find file_find;

   //      //bool bWorking = file_find.find_file(listing.m_pathFinal / "*") != false;

   //      //if (bWorking)
   //      //{

   //      //   while (bWorking)
   //      //   {

   //      //      bWorking = file_find.find_next_file() != false;

   //      //      if (!file_find.IsDots() && file_find.GetFilePath() != listing.m_pathFinal)
   //      //      {

   //      //         if ((listing.m_bDir && file_find.IsDirectory()) || (listing.m_bFile && !file_find.IsDirectory()))
   //      //         {

   //      //            if (matches_wildcard_criteria_ci(listing.m_straPattern, file_find.GetFileName()))
   //      //            {

   //      //               listing.add(file_find.GetFilePath());

   //      //               listing.last().m_iSize = file_find.get_length();

   //      //               listing.last().m_iDir = file_find.IsDirectory() != false;

   //      //            }

   //      //         }

   //      //      }

   //      //   }

   //      //}
   //      //else
   //      //{

   //      //   listing.m_statusresult = ::error_failed;

   //      //}

   //      //for (index i = iStart; i < listing.get_size(); i++)
   //      //{

   //      //   listing[i].m_iRelative = listing.m_pathUser.get_length() + 1;

   //      //}

   //   }
   //   else
   //   {

   //      if (::dir_context::ls(listing))
   //      {

   //         return true;

   //      }

   //      //file_find file_find;

   //      //bool bWorking;

   //      //bWorking = file_find.find_file(listing.m_pathFinal / "*");

   //      //if (!bWorking)
   //      //{

   //      //   return listing;

   //      //}

   //      //while (bWorking)
   //      //{

   //      //   bWorking = file_find.find_next_file();

   //      //   if (!file_find.IsDots())
   //      //   {

   //      //      if ((listing.m_bDir && file_find.IsDirectory()) || (listing.m_bFile && !file_find.IsDirectory()))
   //      //      {

   //      //         ::file::path pathName = file_find.GetFileName();

   //      //         //if (strFile.case_insensitive_begins("resident_"))
   //      //         //{

   //      //         //   TRACE("resident_*");
   //      //         //}

   //      //         if (matches_wildcard_criteria_ci(listing.m_straPattern, pathName))
   //      //         {

   //      //            listing.add(pathName);

   //      //            //listing.last().m_iSize = file_find.get_length();

   //      //            //listing.last().m_iDir = file_find.IsDirectory() != false;

   //      //         }

   //      //      }

   //      //   }

   //      //}

   //   }

   //   //return listing;

   //   return ::succeeded(listing.m_estatus);

   //}


   //bool dir_context::is_impl(const ::file::path & pcszPath)

   //{

   //   if (::dir_context::is_impl(pcszPath))

   //   {

   //      return true;

   //   }

   //   ::u32 dwAttrib;

   //   dwAttrib = windows_get_file_attributes(pcszPath);

   //   bool bIsDir = (dwAttrib != INVALID_FILE_ATTRIBUTES) && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY);

   //   return bIsDir;

   //}


   bool dir_context::name_is(const ::file::path & str)
   {

      strsize iLast = str.length() - 1;

      while (iLast >= 0)
      {
         if (str.m_begin[iLast] != '\\' && str.m_begin[iLast] != '/' && str.m_begin[iLast] != ':')
            break;
         iLast--;
      }
      while (iLast >= 0)
      {
         if (str.m_begin[iLast] == '\\' || str.m_begin[iLast] == '/' || str.m_begin[iLast] == ':')
            break;
         iLast--;
      }
      if (iLast >= 0)
      {
         while (iLast >= 0)
         {
            if (str.m_begin[iLast] != '\\' && str.m_begin[iLast] != '/' && str.m_begin[iLast] != ':')
            {
               iLast++;
               break;
            }
            iLast--;
         }
      }
      else
      {
         return true; // assume empty string is root_ones directory
      }

      bool bIsDir;

      if (::task_flag().is_set(e_task_flag_compress_is_dir) && iLast >= 3 && !ansi_count_compare_ci(&((const ::string &)str)[iLast - 3], ".zip", 4))
      {

         //m_isdirmap.set(str.left(iLast + 1), true, 0);

         return true;

      }

      ::u32 dwAttrib;

      dwAttrib = ::windows::get_file_attributes(str);

      bIsDir = (dwAttrib != INVALID_FILE_ATTRIBUTES) && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY);

      //      m_isdirmap.set(str.left(iLast + 1), bIsDir, bIsDir ? 0 : ::GetLastError());

      return bIsDir;

   }


   ::file::path dir_context::time()
   {
      
      return m_pdirsystem->m_strTimeFolder;

   }


   ::file::path dir_context::stage()
   {
   
      return install() / "stage";

   }

   
   ::file::path dir_context::stageapp()
   {

      return install() / "basis";

   }

   
   ::file::path dir_context::netseed()
   {

      return m_pdirsystem->m_strNetSeedFolder;

   }


   //::file::path dir_context::module()
   //{

   //   ::pointer<::apex::system>psystem = acmesystem();

   //   return psystem->m_pacmedirectory->module->m_pathModule;

   //}


   //::file::path dir_context::ca2module()
   //{

   //   ::pointer<::apex::system>psystem = acmesystem();

   //   return psystem->m_pdirsystem->m_pathCa2Module;

   //}


   ::file::path dir_context::time_square()
   {

      return time() / "time";

   }


   ::file::path dir_context::time_log(const ::string & strId)
   {

      return appdata() / "log" / strId;

   }


   //bool dir_context::mk(const ::file::path & path)
   //{

   //   if (is(path))
   //   {

   //      return true;

   //   }

   //   ::file::path_array stra;

   //   path.ascendants_path(stra);

   //   index i = stra.get_upper_bound();

   //   for (; i >= 0; i--)
   //   {

   //      string strDir = stra[i];

   //      if (is(strDir))
   //      {

   //         break;

   //      }

   //   }

   //   if (i < 0)
   //   {

   //      return true;

   //   }

   //   for (; i < stra.get_count(); i++)
   //   {

   //      string strDir = stra[i];

   //      acmedirectory()->create(strDir);
   //      {

   //         //            m_isdirmap.set(strDir, true, 0);

   //      }
   //      else
   //      {

   //         DWORD dwError = ::GetLastError();

   //         if (dwError == ERROR_ALREADY_EXISTS)
   //         {

   //            string str;

   //            str = "\\\\?\\" + strDir;

   //            str.trim_right("\\/");

   //            try
   //            {

   //               m_pcontext->m_papexcontext->file().del(str);

   //            }
   //            catch (...)
   //            {

   //            }

   //            str = stra[i];

   //            str.trim_right("\\/");

   //            try
   //            {

   //               m_pcontext->m_papexcontext->file().del(str);

   //            }
   //            catch (...)
   //            {

   //            }

   //            if (acmedirectory()->create_directory(strDir))
   //            {

   //               //                  m_isdirmap.set(strDir, true, 0);

   //               continue;

   //            }

   //            //   m_isdirmap.set(strDir, false, 0);

   //            dwError = ::GetLastError();

   //            WCHAR * pwszError;

   //            FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, nullptr, dwError, 0, (WCHAR *) &pwszError, 8, nullptr);

   //            //TRACE("dir_context::mk CreateDirectoryW last error(%d)=%s", dwError, pszError);

   //            ::LocalFree(pwszError);

   //            //m_isdirmap.set(stra[i], false);

   //            return false;

   //         }

   //      }

   //   }

   //   return true;

   //}


   //bool dir_context::rm(const ::file::path & path, bool bRecursive)
   //{

   //   if (bRecursive)
   //   {
   //      
   //      ::file::listing patha;

   //      ls(patha, path);

   //      for (auto & pathItem : patha)
   //      {

   //         if (is(pathItem))
   //         {

   //            rm(pathItem, true);

   //         }
   //         else
   //         {

   //            ::DeleteFileW(wstring(pathItem));

   //         }

   //      }

   //   }

   //   return RemoveDirectoryW(wstring(path)) != false;

   //}


   //::file::path dir_context::name(const ::file::path & path1)
   //{
   //   const scoped_string & str = path1 + strlen(path1) - 1;
   //   while(psz >= path1)
   //   {
   //      if(*psz != '\\' && *psz != '/' && *psz != ':')
   //         break;
   //      psz--;
   //   }
   //   while(psz >= path1)
   //   {
   //      if(*psz == '\\' || *psz == '/' || *psz == ':')
   //         break;
   //      psz--;
   //   }
   //   if(psz >= path1) // strChar == "\\" || strChar == "/"
   //   {
   //      const scoped_string & strEnd = psz;
   //      /*while(psz >= path1)
   //      {
   //         if(*psz != '\\' && *psz != '/' && *psz != ':')
   //            break;
   //         psz--;
   //      }*/
   //      return string(path1, pszEnd - path1 + 1);
   //   }
   //   else
   //   {
   //      return "";
   //   }
   //}

   ::file::path dir_context::name(const ::file::path & str)
   {

      strsize iLast = str.length() - 1;

      while (iLast >= 0)
      {
         if (str.m_begin[iLast] != '\\' && str.m_begin[iLast] != '/' && str.m_begin[iLast] != ':')
            break;
         iLast--;
      }
      while (iLast >= 0)
      {
         if (str.m_begin[iLast] == '\\' || str.m_begin[iLast] == '/' || str.m_begin[iLast] == ':')
            break;
         iLast--;
      }
      if (iLast >= 0)
      {
         while (iLast >= 0)
         {
            if (str.m_begin[iLast] != '\\' && str.m_begin[iLast] != '/' && str.m_begin[iLast] != ':')
               break;
            iLast--;
         }
         return str.left(iLast + 1);
      }
      else
      {
         return "";
      }
   }



   ::file::path dir_context::trash_that_is_not_trash(const ::file::path & psz)
   {
      if (psz.is_empty())
         return "";

      if (psz[1] == ':')
      {
         string strDir = name(psz);
         string str;
         str = strDir.left(2);
         str += "\\trash_that_is_not_trash\\";
         string strFormat;
         ::earth::time time;
         time = ::earth::time::now();
         strFormat.format("%04d-%02d-%02d %02d-%02d-%02d\\", time.year(), time.month(), time.day(), time.hour(), time.minute(), time.second());
         str += strFormat;
         if (strDir.m_begin[2] == '\\')
         {
            str += strDir.substr(3);
         }
         else
         {
            str += strDir.substr(2);
         }
         return str;
      }

      return "";
   }

   
   ::file::path dir_context::appdata(const ::string & strAppId)
   {

      return ::dir_context::appdata(strAppId);

   }


   ::file::path dir_context::commonappdata_root()
   {

      return m_pdirsystem->m_strCommonAppData;

   }


   ::file::path dir_context::userquicklaunch()
   {

      return m_pdirsystem->m_strAppData / "Microsoft\\Internet Explorer\\Quick Launch";

   }


   ::file::path dir_context::userprograms()
   {

      return m_pdirsystem->m_strPrograms;

   }


   ::file::path dir_context::commonprograms()
   {

      return m_pdirsystem->m_strCommonPrograms;

   }


   bool dir_context::is_inside_time(const ::file::path & pszPath)
   {

      return is_inside(time(), pszPath);

   }


   bool dir_context::is_inside(const ::file::path & pszDir, const ::file::path & pszPath)
   {

      return pszDir.case_insensitive_begins(pszPath);

   }


   bool dir_context::has_subdir(const ::file::path & pathFolder)
   {

      ::file::listing listing;

      listing.set_folder_listing(pathFolder);

      enumerate(listing);

      return listing.has_element();

      //file_find file_find;

      //bool bWorking;

      //bWorking = file_find.find_file(pszDir / "*.*");

      //while (bWorking)
      //{

      //   bWorking = file_find.find_next_file();

      //   if (file_find.IsDirectory() && !file_find.IsDots())
      //   {

      //      return true;

      //   }

      //}

      return false;

   }

   //bool file::GetStatus(const ::string & pszFileName,::file::file_status& rStatus)

   //{
   //   // attempt to fully qualify path first
   //   wstring wstrFullName;
   //   wstring wstrFileName;
   //   wstrFileName = utf8_to_unicode(pszFileName);

   //   if(!windows_full_path(wstrFullName,wstrFileName))
   //   {
   //      rStatus.m_strFullName.empty();
   //      return false;
   //   }
   //   unicode_to_utf8(rStatus.m_strFullName,wstrFullName);

   //   WIN32_FIND_DATA findFileData;
   //   HANDLE hFind = FindFirstFile((char *)pszFileName,&findFileData);

   //   if(hFind == INVALID_HANDLE_VALUE)
   //      return false;
   //   VERIFY(FindClose(hFind));

   //   // strip attribute of NORMAL bit, our API doesn't have a "normal" bit.
   //   rStatus.m_attribute = (::u8)(findFileData.dwFileAttributes & ~FILE_ATTRIBUTE_NORMAL);

   //   // get just the low ::u32 of the file size_i32
   //   ASSERT(findFileData.nFileSizeHigh == 0);
   //   rStatus.m_size = (::i32)findFileData.nFileSizeLow;

   //   // convert times as appropriate
   //   rStatus.m_ctime = ::earth::time(findFileData.ftCreationTime);
   //   rStatus.m_atime = ::earth::time(findFileData.ftLastAccessTime);
   //   rStatus.m_mtime = ::earth::time(findFileData.ftLastWriteTime);

   //   if(rStatus.m_ctime.get_time() == 0)
   //      rStatus.m_ctime = rStatus.m_mtime;

   //   if(rStatus.m_atime.get_time() == 0)
   //      rStatus.m_atime = rStatus.m_mtime;

   //   return true;
   //}

   
   ::file::path dir_context::document()
   {

      return "document://";

   }


   ::file::path dir_context::desktop()
   {

      //::file::path path;

      //acmedirectory()->m_pplatformdir->_shell_get_special_folder_path(
      //   nullptr,
      //   path,
      //   CSIDL_DESKTOP,
      //   false);

      //return path;

      return "desktop://";

   }

   ::file::path dir_context::download()
   {

      //::file::path path;

      //path = acmedirectory()->m_pplatformdir->_get_known_folder(FOLDERID_Downloads);

      //return path;

      return "download://";

   }


   ::file::path dir_context::music()
   {

      //::file::path path;

      //acmedirectory()->m_pplatformdir->_shell_get_special_folder_path(
      //   nullptr,
      //   path,
      //   CSIDL_MYMUSIC,
      //   false);

      //return path;

      return "music://";

   }


   ::file::path dir_context::video()
   {

      //::file::path path;

      //acmedirectory()->m_pplatformdir->_shell_get_special_folder_path(
      //   nullptr,
      //   path,
      //   CSIDL_MYVIDEO,
      //   false);

      //return path;

      return "video://";

   }


   ::file::path dir_context::image()
   {

      //::file::path path;

      //acmedirectory()->m_pplatformdir->_shell_get_special_folder_path(
      //   nullptr,
      //   path,
      //   CSIDL_MYPICTURES,
      //   false);

      //return path;

      return "image://";

   }


   ::file::path dir_context::onedrive()
   {

      //registry::key key;

      //if (key._open(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Onedrive", false))
      //{


      //}

      //if (key._open(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Window\\CurrentVersion\\SkyDrive", false))
      //{

      //   string strPath;

      //   if (key._get("UserFolder", strPath))
      //   {

      //      return strPath;

      //   }

      //}

      //return "";

      return "onedrive://";

   }


   ::file::path dir_context::dropbox()
   {

      return "dropbox://";

   }


} // namespace apex_universal_windows



