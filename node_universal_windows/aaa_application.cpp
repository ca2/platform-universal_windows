#include "framework.h"
#include "apex/operating_system.h"


namespace aura
{



   //void application::impl_term1()
   //{


   //}

   //
   //
   //   __IMPLEMENT_APPLICATION_RELEASE_TIME();


   application::application() :
   //      ::object(pobject)
   //   {
   //
   //      //m_pthreadimpl.create(this);
   //
   //      //m_pthreadimpl->m_pthread = this;
   //
   //      get_context_system()                    =  papp->get_application()->get_context_system();
   //
   //      m_atomApp = m_atomSystemTopic    = nullptr;
   //
   //   }


   //application::~application()
   //{

   //}


   //void application::_001OnFileNew()
   //{

   //}


   //::user::document *  application::_001OpenDocumentFile(::payload payloadFile)
   //{

   //   return nullptr;

   //}




   //bool application::_001OnDDECommand(const ::string & pcsz)

   //{

   //   __UNREFERENCED_PARAMETER(pcsz);


   //   return false;

   //}


   //HINSTANCE application::GetHinstance()
   //{

   //   return nullptr;

   //}

   //string application::get_version()
   //{

   //   unichar pszModuleFilePath[MAX_PATH + 1];

   //   GetModuleFileNameW(nullptr, pszModuleFilePath, MAX_PATH + 1);


   //   ::u32 dw;

   //   ::u32 dwResSize = GetFileVersionInfoSizeW(
   //                     pszModuleFilePath,

   //                     &dw);


   //   if (dwResSize > 0)
   //   {
   //    
   //      memory memory;
   //      
   //      memory.set_size(dwResSize);

   //      if (GetFileVersionInfoW(
   //            pszModuleFilePath,

   //            0,
   //            dwResSize,
   //         memory.get_data()))

   //      {
   //         ::u32 cbTranslate;
   //         struct LANGANDCODEPAGE
   //         {
   //            ::u16 wLanguage;
   //            ::u16 wCodePage;
   //         } *pTranslate;


   //         // read the list of languages and code pages.

   //         VerQueryValue(memory.get_data(),
   //                       TEXT("\\VarFileInfo\\Translation"),
   //                       (LPVOID*)&pTranslate,
   //                       &cbTranslate);

   //         string strKey;

   //         for( ::u32 u = 0; u < (cbTranslate/sizeof(struct LANGANDCODEPAGE)); u++ )
   //         {

   //            char * psz;

   //            ::u32 uSize;

   //            //strKey.Format(
   //            //"\\StringFileInfo\\%04x%04x\\FileDescription",
   //            //pTranslate[u].wLanguage,
   //            //pTranslate[u].wCodePage);

   //            strKey.Format(
   //            "\\StringFileInfo\\%04x%04x\\FileVersion",
   //            pTranslate[u].wLanguage,
   //            pTranslate[u].wCodePage);


   //            // Retrieve file description for language and code page "i".
   //            if (VerQueryValue(memory.get_data(),
   //               (char *)(const ::string &)strKey,
   //               (LPVOID*)&psz,
   //               &uiSize))
   //            {

   //               string strVersion(psz, uiSize);

   //               return strVersion;

   //            }

   //         }

   //      }

   //   }

   //   return "";

   //}

   //void application::show_wait_cursor(bool bShow)
   //{

   //   if (bShow)
   //   {

   //      hcursor hcursorWait = ::LoadCursor(nullptr, IDC_WAIT);

   //      hcursor hcursorPrevious = ::SetCursor(hcursorWait);

   //   }
   //   else
   //   {

   //      //         ::SetCursor(m_hcurWaitCursorRestore);
   //   }

   //}




   //string application::veriwell_multimedia_music_midi_get_default_implementation_name()
   //{
   //   return system()->implementation_name("music_midi", "mmsystem");
   //}

   //string application::multimedia_audio_mixer_get_default_implementation_name()
   //{
   //   return system()->implementation_name("audio_mixer", "mmsystem");
   //}

   //string application::multimedia_audio_get_default_implementation_name()
   //{

   //   string str;

   //   if (acmefile()->exists(         auto psystem = system();

         auto pacmedir = psystem->m_pacmedirectory;

pacmedir->system() / "config\\system\\audio.txt"))
   //   {

   //      str = acmefile()->as_string(         auto psystem = system();

         auto pacmedir = psystem->m_pacmedirectory;

pacmedir->system() / "config\\system\\audio.txt");

   //   }
   //   else
   //   {

   //      ::file::path strPath;

   //      strPath = ::dir::appdata() / "audio.txt";

   //      str = acmefile()->as_string(strPath);

   //   }

   //   if (str.has_char())
   //      return "audio_" + str;
   //   else
   //      return "audio_mmsystem";

   //}


   //int_bool application::window_set_mouse_cursor(::windowing::window * pwindow, hcursor hcursor)
   //{

   //   if (!::SetCursor(hcursor))
   //   {

   //      return false;

   //   }

   //   return true;

   //}



} // namespace windows





//
//void __node_init_main_data(::particle * pparticle, HINSTANCE hInstance, HINSTANCE hPrevInstance, char * pCmdLine, ::display edisplay)

//{
//
//
//   ::comm::command * pmaininitdata = __new ::windows::command;
//
//
//   pmaininitdata->m_hInstance = hInstance;
//   pmaininitdata->m_hPrevInstance = hPrevInstance;
//   pmaininitdata->m_strCommandLine = unicode_to_utf8(::GetCommandLineW());
//   pmaininitdata->m_nCmdShow = nCmdShow;
//
//   papp->startup_command(pmaininitdata);
//
//}
//

