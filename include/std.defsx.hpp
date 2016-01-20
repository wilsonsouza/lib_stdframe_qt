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
#include <std.icons.hpp>
#include <std.captions.hpp>
#include <std.menuitemdata.hpp>
#include <std.submenuitemdata.hpp>
#include <std.action.hpp>
#include <std.menu.hpp>
#include <std.widget.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK EditItems: public MenuItems, public Icons::Edit
   {
   public:
      EditItems():MenuItems(Captions::Edit::NAME), Icons::Edit()
      {
         operator+(new MenuItemData(Captions::Edit::UNDO, UNDO));
         operator+(new MenuItemData(Captions::Edit::REDO));
         Separator();
         operator+(new MenuItemData(Captions::Edit::CUT, CUT));
         operator+(new MenuItemData(Captions::Edit::PASTE, PASTE));
         operator+(new MenuItemData(Captions::Edit::COPY, COPY));
         operator+(new MenuItemData(Captions::Edit::REMOVE, REMOVE));
         Separator();
         operator+(new MenuItemData(Captions::Edit::SELECT_ALL));
         operator+(new MenuItemData(Captions::Edit::FIND_REPLACE, FIND_REPLACE));
         operator+(new MenuItemData(Captions::Edit::GOTO, GOTO));
      }
      DECLARE_OPERATOR(EditItems)
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK ViewItems: public MenuItems
   {
   public:
      ViewItems():MenuItems(Captions::View::NAME)
      {
         using namespace Captions::View;

         operator+(new MenuItemData(TOOLBAR));
         operator+(new MenuItemData(STATUSBAR));
      }
      DECLARE_OPERATOR(ViewItems)
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK UserItems: public MenuItems, public Icons::User
   {
   public:
      UserItems():MenuItems(Captions::User::NAME), Icons::User()
      {
         operator+(new MenuItemData(Captions::User::PASSWORD, PASSWORD));
         operator+(new MenuItemData(Captions::User::PERMISSION));
         Separator();
         operator+(new MenuItemData(Captions::User::MANAGER, MANAGER));
      }
      DECLARE_OPERATOR(UserItems)
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK ToolsItems: public MenuItems, public Icons::Tools
   {
   public:
      ToolsItems():MenuItems(Captions::Tools::NAME), Icons::Tools()
      {
         operator+(new MenuItemData(Captions::Tools::PREFERENCES, PREFERENCES));
      }
      DECLARE_OPERATOR(ToolsItems)
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK HelpLibbsItems: public MenuItems, public Icons::Help
   {
   public:
      HelpLibbsItems():MenuItems(Captions::Help::NAME), Icons::Help()
      {
         std::ustring strabout = Captions::Help::ABOUT.arg(QApplication::instance()->applicationName());

         operator+(new MenuItemData(Captions::Help::INDEX, INDEX));
         Separator();
         operator+(new MenuItemData(Captions::Help::LIBBS));
         operator+(new MenuItemData(Captions::Help::DEDALUS));
         Separator();
         operator+(new MenuItemData(Captions::Help::ABOUT));
      }
      DECLARE_OPERATOR(HelpLibbsItems)
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK HelpWRDeveloperInfoItems: public MenuItems, public Icons::Help
   {
   public:
      HelpWRDeveloperInfoItems():MenuItems(Captions::Help::NAME), Icons::Help()
      {
         operator+(new MenuItemData(Captions::Help::INDEX, INDEX));
         Separator();
         operator+(new MenuItemData(Captions::Help::WRDEVINFO));
         Separator();
         operator+(new MenuItemData(Captions::Help::ABOUT));
      }
      DECLARE_OPERATOR(HelpWRDeveloperInfoItems)
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK FileItems: public MenuItems, public Icons::File
   {
   public:
      FileItems():MenuItems(Captions::File::NAME), Icons::File()
      {
         operator+(new MenuItemData(Captions::File::NEW, NEW));
         operator+(new MenuItemData(Captions::File::OPEN, OPEN));
         operator+(new MenuItemData(Captions::File::CLOSE, CLOSE));
         Separator();
         operator+(new MenuItemData(Captions::File::SAVE, SAVE));
         operator+(new MenuItemData(Captions::File::SAVE_AS, SAVE_AS));
         Separator();
         operator+(new MenuItemData(Captions::File::PRINT, PRINT));
         operator+(new MenuItemData(Captions::File::PRINT_VIEW, PRINT_VIEW));
         operator+(new MenuItemData(Captions::File::PRINT_SETUP, PRINT_SETUP));
         operator+(new MenuItemData(Captions::File::PRINT_PAGE_SETUP, PRINT_PAGE_SETUP));
         Separator();
         operator+(new MenuItemData(Captions::File::RECENT_FILES));
         Separator();                                          
         operator+(new MenuItemData(Captions::File::IMPORT));
         operator+(new MenuItemData(Captions::File::EXPORT));
         Separator();
         operator+(new MenuItemData(Captions::File::CHANGE_USER, CHANGE_USER));
         operator+(new MenuItemData(Captions::File::LOGOFF, LOGOFF));
         Separator();
         operator+(new MenuItemData(Captions::File::EXIT, EXIT, true));
      }
      DECLARE_OPERATOR(FileItems);
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK AnalyzerItems: public MenuItems
   {
   public:
      AnalyzerItems():MenuItems(Captions::Analyzer::NAME)
      {
         operator+(new MenuItemData(Captions::Analyzer::PAGE));
      }
      DECLARE_OPERATOR(AnalyzerItems)
   };
   //-----------------------------------------------------------------------------------------------//
   //show mode
   namespace Window
   {
      namespace Mode
      {
         static const unsigned int NORMAL = 0x01af;
         static const unsigned int MAXIMIZED = 0x02df;
         static const unsigned int MINIMIZED = 0x04ef;
         static const unsigned int HIDE = 0x08ab;
      };

      //window states
      namespace States
      {
         static const unsigned int NOSTATE = Qt::WindowNoState;
         static const unsigned int MINIMIZED = Qt::WindowMinimized;
         static const unsigned int MAXIMIZED = Qt::WindowMaximized;
         static const unsigned int FULLSCREEN = Qt::WindowFullScreen;
         static const unsigned int ACTIVE = Qt::WindowActive;
      };

      //window Modality
      namespace Modality
      {
         static const unsigned int NONMODAL = Qt::NonModal;
         static const unsigned int WINDOWMODAL = Qt::WindowModal;
         static const unsigned int APPLICATIONMODAL = Qt::ApplicationModal;
      };
   };
   //class Names and inherits
   #define CLASSNAME(object, Name) object->inherits(std::ustring("%1").arg(#Name).toStdString().c_str())

   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK StyleItems: public MenuItems, public Icons::Style
   {
   public:
      StyleItems():MenuItems(Captions::Style::NAME), Icons::Style()
      {
         operator+(new MenuItemData(Captions::Style::CDE));
         operator+(new MenuItemData(Captions::Style::MACINTOSH, MACINTOSH));
         operator+(new MenuItemData(Captions::Style::MOTIF, Tokens::nullIcon, true));
         operator+(new MenuItemData(Captions::Style::PLASTIQUE));
         operator+(new MenuItemData(Captions::Style::VISTA, Tokens::nullIcon));
         operator+(new MenuItemData(Captions::Style::WINDOWS, WINDOWS, true));
         operator+(new MenuItemData(Captions::Style::XP, Tokens::nullIcon, true));
         operator+(new MenuItemData(Captions::Style::FUSION, Tokens::nullIcon, true));
      }
      DECLARE_OPERATOR(StyleItems)
   };
   //-----------------------------------------------------------------------------------------------//
   class _DYNAMICLINK WindowItems: public MenuItems, public Icons::Window
   {
   public:
      WindowItems():MenuItems(Captions::Window::NAME), Icons::Window()
      {
         operator+(new MenuItemData(Captions::Window::MAXIMIZE, MAXIMIZE));
         operator+(new MenuItemData(Captions::Window::MINIMIZE, MINIMIZE));
         operator+(new MenuItemData(Captions::Window::NEXT, NEXT));
         operator+(new MenuItemData(Captions::Window::PREVIOUS, PREVIOUS));
         operator+(new MenuItemData(Captions::Window::REFRESH, REFRESH));
         Separator();
         operator+(new MenuItemData(Captions::Window::CLOSE, CLOSE));
         operator+(new MenuItemData(Captions::Window::CLOSEALL, CLOSEALL));
         Separator();
         operator+(new MenuItemData(Captions::Window::CASCADE));
         operator+(new MenuItemData(Captions::Window::TILE, TILE));
         operator+(new MenuItemData(Captions::Window::HIDE, HIDE));
         operator+(new MenuItemData(Captions::Window::SHOW));
         Separator();
         operator+(new MenuItemData(Captions::Window::TABBED, TABBED));
         operator+(new MenuItemData(Captions::Window::DOCUMENT, DOCUMENT));
      }
      DECLARE_OPERATOR(WindowItems)
   };
};