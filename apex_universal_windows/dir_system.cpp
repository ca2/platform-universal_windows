#include "framework.h"
#include "apex/operating_system.h"
#include <Shlobj.h>
#include "acme/filesystem/filesystem/acme_dir.h"
#include "acme_universal_windows/acme_dir.h"
//#include "_windows.h"
//#include "acme/os/windows_common/cotaskptr.h"

//#include "apex/xml/_.h"


namespace universal_windows
{


   dir_system::dir_system()
   {


   }


   dir_system::~dir_system()
   {

   }



   ::e_status dir_system::initialize(::object * pobject)
   {

      auto estatus = ::dir_system::initialize(pobject);

      if (!estatus)
      {

         return estatus;

      }

      m_pathInstall = m_psystem->m_pacmedir->install();

      //m_psystem->m_pacmedir->m_pplatformdir->_shell_get_special_folder_path(
        // nullptr,
         //m_strCommonAppData,
         //CSIDL_COMMON_APPDATA,
         //false);
      //shell_get_special_folder_path(
      // nullptr,
      //m_pathProfile,
      //CSIDL_PROFILE,
      //false);

      //m_pathHome = m_psystem->m_pacmedir->m_pplatformdir->_get_known_folder(FOLDERID_Profile);

      string strHome = getenv("USERPROFILE");

      strHome.trim();

      if (strHome.has_char())
      {

         m_pathHome = strHome;

      }
      else
      {

         m_pathHome = m_pathInstall / "home";

      }

      //m_pathCa2Config = m_psystem->m_pacmedir->ca2roaming();

      m_pathCa2Config = m_pathInstall / "ca2/config";

      m_strCommonAppData = m_pathInstall / "commonappdata";

      m_strAppData = m_pathInstall / "appdata";

      //m_psystem->m_pacmedir->m_pplatformdir->_shell_get_special_folder_path(
      //   nullptr,
      //   m_strPrograms,
      //   CSIDL_PROGRAMS,
      //   false);
      //m_psystem->m_pacmedir->m_pplatformdir->_shell_get_special_folder_path(
      //   nullptr,
      //   m_strCommonPrograms,
      //   CSIDL_COMMON_PROGRAMS,
      //   false);

      {

         //string strRelative;
         //strRelative = install();
         //index iFind = strRelative.find(':');
         //if (iFind >= 0)
         //{
         //   strsize iFind1 = strRelative.reverse_find("\\", iFind);
         //   strsize iFind2 = strRelative.reverse_find("/", iFind);
         //   strsize iStart = maximum(iFind1 + 1, iFind2 + 1);
         //   strRelative = strRelative.Left(iFind - 1) + "_" + strRelative.Mid(iStart, iFind - iStart) + strRelative.Mid(iFind + 1);
         //}



      }

      if (m_strTimeFolder.is_empty())
      {

         m_strTimeFolder = m_psystem->m_pacmedir->appdata() / "time";

      }

      if (m_strNetSeedFolder.is_empty())
      {

         m_strNetSeedFolder = m_psystem->m_pacmedir->install() / "net";

      }

               auto psystem = m_psystem;

         auto pacmedir = psystem->m_pacmedir;

pacmedir->create(m_strTimeFolder);
      //xxdebug_box("win_dir::initialize (m_strTimeFolder)", "win_dir::initialize", 0);

if (!pacmedir->is(m_strTimeFolder))
{
   return false;

}

          /*     auto psystem = m_psystem;

         auto pacmedir = psystem->m_pacmedir;*/

pacmedir->create(m_strTimeFolder / "time");

      //xxdebug_box("win_dir::initialize", "win_dir::initialize", 0);

      return ::success;

   }


   ::e_status dir_system::init_system()
   {

      auto estatus = ::dir_system::init_system();

      if (!estatus)
      {

         return estatus;

      }


      return ::success;

   }







   //::file::path dir_system::application_installer_folder(const ::file::path& pathExe, string strAppId, const ::string & pszPlatform, const ::string & pszConfiguration, const ::string & pszLocale, const ::string & pszSchema)
   //{

   //   string strFolder = pathExe.folder();

   //   strFolder.replace(":", "");

   //   return m_psystem->m_pacmedir->ca2roaming() / "appdata" / strFolder / strAppId / pszPlatform / pszConfiguration / pszLocale / pszSchema;

   //}




   //::file::path dir_system::get_application_path(string strAppId, const ::string & pszPlatform, const ::string & pszConfiguration)
   //{

   //   ::file::path pathFolder;

   //   pathFolder = m_psystem->m_pacmedir->stage(strAppId, pszPlatform, pszConfiguration);

   //   string strName;

   //   strName = ::process::app_id_to_app_name(strAppId);

   //   ::file::path path;

   //   path = pathFolder / (strName + ".exe");

   //   return path;

   //}


   // ::file::path dir_system::get_last_run_application_path_file(string strAppId)
   // {

   //    ::file::path pathFile = m_psystem->m_pacmedir->local() / "appdata" / strAppId / "last_run_path.txt";

   //    return pathFile;

   // }


   // ::file::path dir_system::get_last_run_application_path(string strAppId)
   // {

   //    ::file::path pathFile = get_last_run_application_path_file(strAppId);

   //    ::file::path path = ::m_psystem->m_pacmefile->as_string(pathFile);

   //    return path;

   // }



} // namespace windows



