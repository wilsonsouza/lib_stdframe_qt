//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   namespace Icons
   {
      class _DYNAMICLINK IconsPath: virtual public QObject
      {
      public:
         IconsPath()
         {
            m_Path = qApp->libraryPaths()[0];
         }

         DECLARE_OPERATOR(IconsPath);
         CREATE_PROPERTY_READONLY(std::ustring, m_str, Path);
      };

      class _DYNAMICLINK File: public IconsPath
      {
      public:
         QIcon NEW;
         QIcon OPEN;
         QIcon CLOSE;
         QIcon SAVE;
         QIcon SAVE_AS;
         QIcon PRINT;
         QIcon PRINT_SETUP;
         QIcon PRINT_VIEW;
         QIcon PRINT_PAGE_SETUP;
         QIcon CHANGE_USER;
         QIcon LOGOFF;
         QIcon EXIT;
         QIcon RECENT_FILES;
      public:
         File():IconsPath()
         {
            NEW         = QIcon(m_Path + "Action-File-new.ico");
            OPEN = QIcon(m_Path + "Action-edit.ico");
            CLOSE = QIcon(m_Path + "App-restart.ico");
            SAVE = QIcon(m_Path + "App-write.ico");
            PRINT = QIcon(m_Path + "Action-File-print.ico");
            PRINT_VIEW = QIcon(m_Path + "Action-frame-print.ico");
            CHANGE_USER = QIcon(m_Path + "App-user.ico");
            LOGOFF = QIcon(m_Path + "App-logout.ico");
            EXIT = QIcon(m_Path + "Action-exit.ico");
            SAVE_AS = QIcon(m_Path + "Device-zip-mount.ico");
            PRINT_SETUP = QIcon(m_Path + "Device-print-class.ico");
            PRINT_PAGE_SETUP = QIcon(m_Path + "Filesystem-folder-print.ico");
            RECENT_FILES = QIcon(m_Path + "Action-history.ico");
         }
         virtual ~File(){}
         DECLARE_OPERATOR(File)
      };
      //-----------------------------------------------------------------------------------------------//
      class _DYNAMICLINK Edit: public IconsPath
      {
      public:
         QIcon UNDO;
         QIcon CUT;
         QIcon PASTE;
         QIcon COPY;
         QIcon REMOVE;
         QIcon FIND_REPLACE;
         QIcon GOTO;
      public:
         Edit():IconsPath()
         {
            UNDO           = QIcon(m_Path + "Action-reload.ico");
            CUT            = QIcon(m_Path + "Action-cut.ico");
            PASTE          = QIcon(m_Path + "Action-paste.ico");
            COPY           = QIcon(m_Path + "Action-copy.ico");
            REMOVE         = QIcon(m_Path + "Action-delete.ico");
            FIND_REPLACE   = QIcon(m_Path + "Action-find.ico");
            GOTO           = QIcon(m_Path + "goto.ico");
         }
         virtual ~Edit(){}

         DECLARE_OPERATOR(Edit)
      };
      //-----------------------------------------------------------------------------------------------//
      class _DYNAMICLINK Window: public IconsPath
      {
      public:
         QIcon CLOSEALL;
         QIcon CLOSE;
         QIcon PREVIOUS;
         QIcon NEXT;
         QIcon TILE;
         QIcon TABBED;
         QIcon REFRESH;
         QIcon HIDE;
         QIcon MAXIMIZE;
         QIcon MINIMIZE;
         QIcon DOCUMENT;
      public:
         Window():IconsPath()
         {
            CLOSEALL = QIcon(m_Path + "Action-view-remove.ico");
            CLOSE    = QIcon(m_Path + "Action-remove.ico");
            PREVIOUS = QIcon(m_Path + "Fleche gauche bleue.ico");
            NEXT     = QIcon(m_Path + "Fleche droite bleue.ico");
            TILE     = QIcon(m_Path + "Action-view-left-right.ico");
            TABBED   = QIcon(m_Path + "Action-tab.ico");
            REFRESH  = QIcon(m_Path + "Actualiser.ico");
            HIDE     = QIcon(m_Path + "Action-tab-remove.ico");
            MAXIMIZE = QIcon(m_Path + "Action-window-fullscreen.ico");
            MINIMIZE = QIcon(m_Path + "Action-window-no-fullscreen.ico");
            DOCUMENT = QIcon(m_Path + "App-knode.ico");
         }
         virtual ~Window(){}
         DECLARE_OPERATOR(Window)
      };
      //-----------------------------------------------------------------------------------------------//
      class _DYNAMICLINK Style: public IconsPath
      {
      public:
         QIcon MACINTOSH;
         QIcon WINDOWS;
         QIcon MOTIF;
      public:
         Style():IconsPath()
         {
            MACINTOSH     = QIcon(m_Path + "mac_colored.ico");
            WINDOWS       = QIcon(m_Path + "windows.ico");
            MOTIF         = QIcon(m_Path + "App-x.ico");
         }
         virtual ~Style(){}
         DECLARE_OPERATOR(Style)
      };
      //-----------------------------------------------------------------------------------------------//
      class _DYNAMICLINK Common: public IconsPath
      {
      public:
         QIcon OK;
         QIcon APPLOGINMANAGER;
         QIcon PASSWORD;
         QIcon LOGINMANAGER;
         QIcon HELPINDEX;
         QIcon BACK;
         QIcon FAIL;
         QIcon CONTACTS;
         QIcon LOGOUT;
         QIcon MAIL;
         QIcon MYDOCUMENTS;
         QIcon RELOAD;
         QIcon DENIED;
         QIcon EXCLAMATION;
         QIcon FAQ;
         QIcon DOWN;
         QIcon UP;
         QIcon LEFT;
         QIcon RIGHT;
         QIcon INFORMATION;
         QIcon PUBLIC;
         QIcon QUESTION;
         QIcon WORKING;
         QIcon VALID;
         QIcon FONTS;
         QIcon UPDATECACHE;
         QIcon STATISTICS;
         QIcon COINS;
         QIcon MEDICO;
         QIcon MINUS;
         QIcon PLUS;
         QIcon DBSTATUS;
         /**/
         QIcon INSERT;
         QIcon CHANGE;
         QIcon CANCEL;
         QIcon VIEW;
         QIcon IMPORT;
         QIcon EXPORT;
         QIcon PRINT;
         QIcon PRINTPREVIEW;
         QIcon PRINTSETUP;
         QIcon PRINTPAGE;
         QIcon CUT;
      public:
         Common():IconsPath()
         {
            FONTS = QIcon(m_Path + "App-fonts.ico");
            OK = QIcon(m_Path + "ok.png");
            APPLOGINMANAGER = QIcon(m_Path + "App-login-manager.ico");
            PASSWORD = QIcon(m_Path + "password.png");
            LOGINMANAGER = QIcon(m_Path + "Login Manager.png");
            HELPINDEX = QIcon(m_Path + "App-help-index.ico");
            BACK         = QIcon(m_Path + "back.png");
            FAIL         = QIcon(m_Path + "error.png");
            CONTACTS     = QIcon(m_Path + "evolution-contacts.png");
            LOGOUT       = QIcon(m_Path + "logout.png");
            MAIL         = QIcon(m_Path + "mail.png");
            MYDOCUMENTS  = QIcon(m_Path + "mydocuments.png");
            RELOAD       = QIcon(m_Path + "Actualiser.ico");
            DENIED       = QIcon(m_Path + "Ad Aware.ico");
            CANCEL       = QIcon(m_Path + "Action-cancel.ico");
            EXCLAMATION  = QIcon(m_Path + "Exclamation.ico");
            FAQ          = QIcon(m_Path + "faq.ico");
            DOWN         = QIcon(m_Path + "Fleche bas bleue.ico");
            UP           = QIcon(m_Path + "Fleche haut bleue.ico");
            LEFT         = QIcon(m_Path + "Fleche gauche bleue.ico");
            RIGHT        = QIcon(m_Path + "Fleche droite bleue.ico");
            INFORMATION  = QIcon(m_Path + "Information.ico");
            PUBLIC       = QIcon(m_Path + "Information.ico");
            QUESTION     = QIcon(m_Path + "Information.ico");
            WORKING      = QIcon(m_Path + "Travaux.ico");
            VALID        = QIcon(m_Path + "Validé.ico");
            UPDATECACHE  = QIcon(m_Path + "App-cache.ico");
            STATISTICS   = QIcon(m_Path + "App-chart.ico");
            COINS        = QIcon(m_Path + "coins.ico");
            MEDICO       = QIcon(m_Path + "App-virussafe-injection.ico");
            /**/
            MINUS        = QIcon(m_Path + "action-remove.ico");
            PLUS         = QIcon(m_Path + "action-edit-add.ico");
            /**/
            DBSTATUS     = QIcon(m_Path + "Action-db-status.ico");
            /**/
            INSERT       = QIcon(m_Path + "insertdoc.png");
            CHANGE       = QIcon(m_Path + "App-write.ico");
            VIEW         = QIcon(m_Path + "App-xeyes.ico");
            IMPORT       = QIcon(m_Path + "App-warehause.ico");
            EXPORT       = QIcon(m_Path + "App-navigator.ico");
            PRINT        = QIcon(m_Path + "App-kjobviewer-printer.ico");
            PRINTPREVIEW = QIcon(m_Path + "App-kde-print-fax.ico");
            PRINTSETUP   = QIcon(m_Path + "Action-file-quick-print.ico");
            PRINTPAGE    = QIcon(m_Path + "Action-frame-print.ico");
            /**/
            CUT          = QIcon(m_Path + "Blue-Scissors.ico");
         }
         virtual ~Common(){}
         DECLARE_OPERATOR(Common)
      };
      //-----------------------------------------------------------------------------------------------//
      class _DYNAMICLINK User: public IconsPath
      {
      public:
         QIcon PASSWORD;
         QIcon MANAGER;
      public:
         User():IconsPath()
         {
            PASSWORD = QIcon(m_Path + "password.png"); //Common::PASSWORD;
            MANAGER = QIcon(m_Path + "login manager.png"); //Common::LOGINMANAGER;
         }
         virtual ~User(){}
         DECLARE_OPERATOR(User)
      };
      //-----------------------------------------------------------------------------------------------//
      class _DYNAMICLINK Tools: public IconsPath
      {
      public:
         QIcon PREFERENCES;
      public:
         Tools():IconsPath()
         {
            PREFERENCES      = QIcon(m_Path + "App-package-utilities.ico");
         }
         virtual ~Tools(){}
         DECLARE_OPERATOR(Tools)
      };
      //-----------------------------------------------------------------------------------------------//
      class _DYNAMICLINK Help: public IconsPath
      {
      public:
         QIcon INDEX;
         QIcon HELPINDEX;
      public:
         Help():IconsPath()
         {
            INDEX = QIcon(m_Path + "App-help-index.ico");
            HELPINDEX = QIcon(m_Path + "help_index.png");
         }
         virtual ~Help(){}
         DECLARE_OPERATOR(Help);
      };
   }; //Icons
   //-----------------------------------------------------------------------------------------------//
   template <class I = Icons::Common> 
   class _DYNAMICLINK IconsImpl: public I, virtual public QObject
   {
   public:
      IconsImpl();
      virtual ~IconsImpl(){}
      virtual QIcon const Load(std::ustring const & strName);

      DECLARE_OPERATOR(IconsImpl);
      set_property(ustring, Path);
   };
   //-----------------------------------------------------------------------------------------------//
   template <class I> __inline IconsImpl<I>::IconsImpl():I()
   {
   }
   //-----------------------------------------------------------------------------------------------//
   template <class I> __inline QIcon const IconsImpl<I>::Load(std::ustring const & strName)
   {
      if(m_Path.isEmpty())
         SetPath(strName);

      return QIcon(std::ustring("%1/%2").arg(m_Path).arg(strName));
   }
   //-----------------------------------------------------------------------------------------------//
   typedef IconsImpl<Icons::File> FileIcons;
   typedef IconsImpl<Icons::Edit> EditIcons;
   typedef IconsImpl<Icons::Common> CommonIcons;
   typedef IconsImpl<Icons::Help> HelpIcons;
   typedef IconsImpl<Icons::Style> StyleIcons;   
   typedef IconsImpl<Icons::Tools> ToolsIcons;  
   typedef IconsImpl<Icons::User>  UserIcons;
   typedef IconsImpl<Icons::Window> WindowIcons;
   //-----------------------------------------------------------------------------------------------//
   template <class F = FileIcons,
             class E = EditIcons,
             class C = CommonIcons,
             class H = HelpIcons,
             class S = StyleIcons,
             class T = ToolsIcons,
             class U = UserIcons,
             class W = WindowIcons>
   class _DYNAMICLINK IconsImplEx: public IconsImpl<QIcon>
   {
   public:
      IconsImplEx();
      virtual ~IconsImplEx(){}

      set_property(std::shared_ptr<F>, File);
      set_property(std::shared_ptr<E>, Edit);
      set_property(std::shared_ptr<C>, Common);
      set_property(std::shared_ptr<H>, Help);
      set_property(std::shared_ptr<S>, Style);
      set_property(std::shared_ptr<T>, Tools);
      set_property(std::shared_ptr<U>, User);
      set_property(std::shared_ptr<W>, Window);
   };
   //-----------------------------------------------------------------------------------------------//
   template <class TF, class TE, class TC, class TH, class TS, class TT, class TU, class TW>
   __inline IconsImplEx<TF, TE, TC, TH, TS, TT, TU, TW>::IconsImplEx():IconsImpl<QIcon>()
   {
      m_File = std::shared_ptr<TF>(new TF());
      m_Edit = std::shared_ptr<TE>(new TE());
      m_Common = std::shared_ptr<TC>(new TC());
      m_Help = std::shared_ptr<TH>(new TH());
      m_Style = std::shared_ptr<TS>(new TS());
      m_Tools = std::shared_ptr<TT>(new TT());
      m_User = std::shared_ptr<TU>(new TU());
      m_Window = std::shared_ptr<TW>(new TW());
   }
   //-----------------------------------------------------------------------------------------------//
};