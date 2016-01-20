//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012, 2013
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012, 2013
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   //-----------------------------------------------------------------------------------------------//
   namespace IndexMedicalStatus
   {
      static unsigned int const IDDAFASTADO = 0,
                                IDDFALECIDO = 1,
                                IDDTRANSFERIDO = 2,
                                IDDAUSENTE = 3,
                                IDDCASSADO = 4,
                                IDDATIVO = 5,
                                IDDPRIMARIA = 6,
                                IDDSUSPENSO = 7,
                                IDDCANCELADO = 8,
                                IDDAPOSENTADO= 9,
                                IDDDESCONHECIDO = 0xA;
   };
   //-----------------------------------------------------------------------------------------------//
   typedef QHash<QChar, std::ustring> EmployeeStatusMapper;
   typedef QHash<QChar, QIcon> EmployeeStatusIconsMapper;
   //-----------------------------------------------------------------------------------------------//
   template <class T = StringList> 
   class _DYNAMICLINK CommonImpl: public T
   {
   public:
      CommonImpl();
      virtual ~CommonImpl();
      T & GetFederalUnits();
      T & GetMedicalStatus();
      EmployeeStatusMapper GetEmployeeStatus();
      EmployeeStatusIconsMapper GetEmployeeStatusIcons();
   };
   //-----------------------------------------------------------------------------------------------//
   template <class T> __inline CommonImpl<T>::CommonImpl():T()
   {
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T> __inline CommonImpl<T>::~CommonImpl()
   {
      clear();
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T> __inline T & CommonImpl<T>::GetFederalUnits()
   {
      clear();
      *this << "AC" << "AL" << "AM" << "AP" << "BA" << "CE" << "DF" 
            << "ES" << "EX" << "GO" << "IM" << "MA" << "MG" << "MS" 
            << "MT" << "PA" << "PB" << "PE" << "PI" << "PR" << "RJ" 
            << "RN" << "RO" << "RR" << "RS" << "SC" << "SE" << "SP" 
            << "TO";
      return *this;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T> __inline T & CommonImpl<T>::GetMedicalStatus()
   {
      clear();
      *this << "Afastado" << "Falecido" << "Transferido" << "Ausente" << "Cassado" << "Ativo" 
            << ustring("Primária")<< "Suspenso" << "Cancelado" << "Aposentado" << "Desconhecido";
      return *this;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T> __inline EmployeeStatusMapper CommonImpl<T>::GetEmployeeStatus()
   {
      EmployeeStatusMapper es;

      es.operator[](Qt::Key_A) = "Ativo";
      es.operator[](Qt::Key_I) = "Inativo";
      es.operator[](Qt::Key_D) = "Demitido";
      return es;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T> __inline EmployeeStatusIconsMapper CommonImpl<T>::GetEmployeeStatusIcons()
   {
      EmployeeStatusIconsMapper es;

      es.operator[](Qt::Key_A) = Icons::Common().OK;
      es.operator[](Qt::Key_I) = Icons::Common().DENIED;
      es.operator[](Qt::Key_D) = Icons::Common().CANCEL;
      return es;
   }
};
//-----------------------------------------------------------------------------------------------//
