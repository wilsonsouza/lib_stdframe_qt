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
#include <std.tablefields.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   template <class T = TableFields *, class H = QHash<std::ustring, T>>
   class _DYNAMICLINK LabelModels: public QList<T>
   {
   public:
      typedef H THashStringTableFieldsPointer;
      typedef enum EListToHashMapper
      { 
         FIELDNAME  = 1, 
         FIELDALIAS = 2, 
         FIELDMASK  = 4, 
         FIELDLABEL = 8
      } EListToHashMapper;
   public:
      explicit LabelModels(QList<T> const & lList = QList<T>());
      LabelModels<T, H> & operator+(T _ptr);
      LabelModels<T, H> & operator+(LabelModels<T, H> const & lmModels);

      StringList GetFormattedQueryFieldsToAlias();
      StringList GetListFieldAlias();
      StringList GetListFieldNames();
      StringList GetListLabelNames();
      StringList GetListFieldMasks();
      StringList ConvertFieldNamesToLabelNames();

      QHash<std::ustring, std::ustring> GetListToStringHashMapper(EListToHashMapper hID);
      H GetListToHashMapper(EListToHashMapper hID);

      void Select(std::ustring const & strFields = std::ustring());
      void Select(StringList const & strListField);
      void SetToken(std::ustring const & strToken = std::ustring());
      void From(std::ustring const & strFrom = std::ustring());
      void LeftJoin(std::ustring const & strData);
      void InnerJoin(std::ustring const & strData);
      void On(std::ustring const & strConstraint);
      void Where(std::ustring const & strConstraint);
      void OrderBy(std::ustring const & strFields);
      void OrderBy(StringList const & strListFields);

      __declspec(property(get=GetListLabelNames)) StringList LabelNames;
      __declspec(property(get=GetListFieldNames)) StringList FieldNames;
      __declspec(property(get=GetListFieldAlias)) StringList FieldAlias;
      __declspec(property(get=GetListFieldMasks)) StringList FieldMasks;
      __declspec(property(get=GetFormattedQueryFieldsToAlias)) StringList FormattedQueryFieldsToAlias;

      CREATE_PROPERTY_READWRITE(std::ustring, m_str, std::ustring const &, SQLFormatted, std::ustring const &)
      CREATE_PROPERTY_READWRITE(std::ustring, m_str, std::ustring const &, TableName, std::ustring const &)
   };
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline LabelModels<T, H>::LabelModels(QList<T> const & lList):
   QList<T>(lList)
   {
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline LabelModels<T, H> & LabelModels<T, H>::operator+(T _ptr)
   {
      QList<T>::append(_ptr);
      return *this;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline LabelModels<T, H> & LabelModels<T, H>::operator+(
      LabelModels<T, H> const & lmModels)
   {
      for(const_iterator i = lmModels.begin(); i != lmModels.end(); i++)
         QList<T>::append(i.operator*());

      return *this;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline StringList LabelModels<T, H>::
      GetFormattedQueryFieldsToAlias()
   {
      StringList strOut = StringList();

      for(const_iterator i = begin(); i != end(); i++)
      {
         T pObj = i.operator*();
         /**/
         if(!pObj->strFieldAlias.trimmed().isEmpty() && !pObj->strFieldAlias.trimmed().isEmpty())
            strOut << std::ustring("%1 as [%2]").arg(pObj->strFieldName).arg(pObj->strFieldAlias);
      }
      return strOut;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline StringList LabelModels<T, H>::
      ConvertFieldNamesToLabelNames()
   {
      StringList strOut = StringList();

      for(const_iterator i = begin(); i != end(); i++)
      {
         T pPtr = i.operator*();
         /**/
         if(!pPtr->strFieldAlias.trimmed().isEmpty() && !pPtr->strLabelName.trimmed().isEmpty())
            strOut << std::ustring("%1 as [%2]").arg(pPtr->strFieldName).arg(pPtr->strLabelName);
      }
      return strOut;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline StringList LabelModels<T, H>::GetListFieldAlias()
   {
      StringList strOut = StringList();
      /**/
      for(const_iterator i = begin(); i != end(); i++)
         if(!i.operator*()->strFieldAlias.trimmed().isEmpty())
            strOut << i.operator*()->strFieldAlias;
      return strOut;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline StringList LabelModels<T, H>::GetListFieldNames()
   {
      StringList strOut = StringList();

      for(const_iterator i = begin(); i != end(); i++)
         if(!i.operator*()->strFieldName.trimmed().isEmpty())
            strOut << i.operator*()->strFieldName;
      return strOut;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline StringList LabelModels<T, H>::GetListLabelNames()
   {
      StringList strOut = StringList();

      for(const_iterator i = begin(); i != end(); i++)
         if(!i.operator*()->strLabelName.trimmed().isEmpty())
            strOut << i.operator*()->strLabelName;
      return strOut;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline StringList LabelModels<T, H>::GetListFieldMasks()
   {
      StringList strOut = StringList();

      for(const_iterator i = begin(); i != end(); i++)
         if(!i.operator*()->strFieldMask.trimmed().isEmpty())
            strOut << i.operator*()->strFieldMask;
      return strOut;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline H LabelModels<T, H>::
      GetListToHashMapper(EListToHashMapper hID)
   {
      H hHash;

      for(const_iterator i = begin(); i != end(); i++)
      {
         T pObj = i.operator*();

         if(hID == FIELDNAME && !pObj->strFieldName.trimmed().isEmpty())
            hHash.operator[](pObj->strFieldName) = pObj;
         else if(hID == FIELDALIAS && !pObj->strFieldAlias.trimmed().isEmpty())
            hHash.operator[](pObj->strFieldAlias) = pObj;
         else if(hID == FIELDMASK && !pObj->strFieldMask.trimmed().isEmpty())
            hHash.operator[](pObj->strFieldMask) = pObj;
         else if(hID == FIELDLABEL && !pObj->strLabelName.trimmed().isEmpty())
            hHash.operator[](pObj->strLabelName) = pObj;
      }
      return hHash;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline QHash<std::ustring, std::ustring> LabelModels<T, H>::
      GetListToStringHashMapper(EListToHashMapper hID)
   {
      QHash<std::ustring, std::ustring> hHash;

      for(const_iterator i = begin(); i != end(); i++)
      {
         T pObj = i.operator*();

         if(hID == FIELDNAME && !pObj->strFieldName.trimmed().isEmpty() && !pObj->strFieldAlias.trimmed().isEmpty())
            hHash.operator[](pObj->strFieldName) = pObj->strFieldAlias;
         else if(hID == FIELDALIAS && !pObj->strFieldName.trimmed().isEmpty() && !pObj->strFieldAlias.trimmed().isEmpty())
            hHash.operator[](pObj->strFieldAlias) = pObj->strFieldName;
         else if(hID == FIELDMASK && !pObj->strFieldMask.trimmed().isEmpty() && !pObj->strFieldName.trimmed().isEmpty())
            hHash.operator[](pObj->strFieldMask) = pObj->strFieldName;
         else if(hID == FIELDLABEL && !pObj->strLabelName.trimmed().isEmpty() && !pObj->strFieldName.trimmed().isEmpty())
            hHash.operator[](pObj->strLabelName) = pObj->strFieldName;
      }
      return hHash;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline void LabelModels<T, H>::Select(std::ustring const & strFieldList)
   {
      if(strFieldList.length() == 0)
         m_strSQLFormatted = std::ustring(" select %1 ").arg(FieldNames.join(","));
      else
         m_strSQLFormatted = std::ustring(" select %1 ").arg(strFieldList);
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline void LabelModels<T, H>::Select(StringList const & strListField)
   {
      if(strListField.count() > 0)
         m_strSQLFormatted = std::ustring("select %1 ").arg(strListField.join(","));
      else
         m_strSQLFormatted = std::ustring(" select %1 ").arg(FieldNames.join(","));
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline void LabelModels<T, H>::SetToken(std::ustring const & strToken)
   {
      if(!strToken.isEmpty())
         m_strSQLFormatted += std::ustring(" %1 ").arg(strToken);
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline void LabelModels<T, H>::From(std::ustring const & strFrom)
   {
      if(!strFrom.isEmpty())
         m_strSQLFormatted += std::ustring(" from %1 ").arg(strFrom);
      else
         m_strSQLFormatted += std::ustring(" from %1 ").arg(m_strTableName);         

      if(!strFrom.isEmpty())
         m_strTableName = strFrom;
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline void LabelModels<T, H>::LeftJoin(std::ustring const & strData)
   {
      m_strSQLFormatted += std::ustring("\nleft join %1 ").arg(strData);
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline void LabelModels<T, H>::InnerJoin(std::ustring const & strData)
   {
      m_strSQLFormatted += std::ustring("\ninner join %1 ").arg(strData);
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline void LabelModels<T, H>::On(std::ustring const & strConstraint)
   {
      m_strSQLFormatted += std::ustring(" on %1 ").arg(strConstraint);
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline void LabelModels<T, H>::Where(std::ustring const & strConstraint)
   {
      m_strSQLFormatted += std::ustring(" where %1 ").arg(strConstraint);
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline void LabelModels<T, H>::OrderBy(std::ustring const & strFields)
   {
      m_strSQLFormatted += std::ustring(" order by %1 ").arg(strFields);
   }
   //-----------------------------------------------------------------------------------------------//
   template <class T, class H> __inline void LabelModels<T, H>::OrderBy(StringList const & strListFields)
   {
      m_strSQLFormatted += std::ustring(" order by %1 ").arg(strListFields.join(","));
   }
   //-----------------------------------------------------------------------------------------------//
};
