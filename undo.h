#ifndef UNDO_H
#define UNDO_H
#include <QStack> /*!< Pour pouvoir utiliser Qstack*/
#include <iostream>
#include "element.h"

/**
 class CUndo {
    private:
        QStack <QStack<Element *>*> Piledo;
        QStack <QStack<Element *>*> Pileundo;
        long    m_growsize;     // Adjust for faster saves
        long    m_undoLevels;   // Requested Undolevels
        long    m_chkpt;

        void AddUndo(*QStack<Element *>);
       void AddRedo(CMemFile *pFile);
        void Load(CMemFile*);
       void Store(CMemFile*);
       void ClearRedoList();

   public:

        // Here are the hooks into the CDocument class
       virtual void Serialize(CArchive& ar) = 0 ;
       virtual void DeleteContents() = 0 ;

        // User accessable functions
       CUndo(long undolevels = , long = 3768);   // Constructor
       ~CUndo();           // Destructor
       bool CanUndo();     // Returns TRUE if can Undo
       bool CanRedo();     // Returns TRUE if can Redo
       void Undo();        // Restore next Undo state
        void Redo();        // Restore next Redo state
       void CheckPoint();  // Save current state
       void EnableCheckPoint();
       void DisableCheckPoint();
    };

   // Constructor
   inline CUndo::
   CUndo(long undolevels, long growsize) :
       m_growsize(growsize), m_undoLevls(undolevels),
       m_chkpt()
   {
           ;
   }

   // Remove contents of the redo list
   inline void CUndo::
   ClearRedoList()
   {
       // Clear redo list
       POSITION pos = m_redolist.GetHeadPosition();
       CMemFile* nextFile = NULL;
       while(pos) {
           nextFile = (CMemFile *) m_redolist.GetNext(pos);
            delete nextFile;
       }
       m_redolist.RemoveAll();
   }

   // Destructor
   inline CUndo::
   ~CUndo()
   {
       // Clear undo list
        POSITION pos = m_undolist.GetHeadPosition();
       CMemFile  *nextFile = NULL;
       while(pos) {
           nextFile = (CMemFile *) m_undolist.GetNext(pos);
           delete nextFile;
       }
       m_undolist.RemoveAll();

       // Clear redo list
       ClearRedoList();
    }

   // Checks undo availability, may be used to enable menus
   inline BOOL CUndo::
   CanUndo()
   {
       return (m_undolist.GetCount() >  );
   }

   // Checks redo availability, may be used to enable menus
    inline BOOL CUndo::
   CanRedo()
   {
       return (m_redolist.GetCount() > );
   }

   // Adds state to the beginning of undo list
   inline void CUndo::
   AddUndo(CMemFile* file)
   {
        // Remove old state if there are more than max allowed
       if (m_undolist.GetCount() > m_undoLevels) {
           CMemFile* pFile = (CMemFile *) m_undolist.RemoveTail();
           delete pFile;
       }
       // Add new state to head of undo list
       m_undolist.AddHead(file);
   }

    // Saves current object into CMemFile instance
     inline void CUndo::
    Store(CMemFile* file)
    {
        file->SeekToBegin();
        CArchive ar(file, CArchive::store);
        Serialize(ar);
        ar.Close();
    }

   // Loads CMemfile instance to current object
    inline void CUndo::
   Load(CMemFile* file)
   {
       DeleteContents();
       file->SeekToBegin();
       CArchive ar(file, CArchive::load);
       Serialize(ar);
       ar.Close();
   }

    // Save current object state to Undo list
   inline void CUndo::
   CheckPoint()
   {
       if (m_chkpt <= ) {
           CMemFile* file = new CMemFile(m_growsize);
           Store(file);
           AddUndo(file);
           ClearRedoList();
       }
    }

   inline void CUndo::
   EnableCheckPoint()
   {
       if (m_chkpt > ) {
           m_chkpt--;
       }
   }

    inline void CUndo::
   DisableCheckPoint()
   {
       m_chkpt++;
   }

   // Place CMemFile instnace on Redo list
   inline void CUndo::
   AddRedo(CMemFile *file)
   {
        // Move state to head of redo list
       m_redolist.AddHead(file);
   }

   // Perform an Undo command
   inline void CUndo::
   Undo()
   {
       if (CanUndo()) {
           // Remember that the head of the undo list
            // is the current state. So we just move that
           // to the Redo list and load then previous state.
           CMemFile *pFile = (CMemFile *) m_undolist.GetHead();
           m_undolist.RemoveHead();
           AddRedo(pFile);
           pFile = (CMemFile *)m_undolist.GetHead();
           Load(pFile);
       }
   }

    //Perform a Redo Command
   inline void CUndo::
   Redo()
   {
       if (CanRedo()) {
           CMemFile *pFile = (CMemFile *) m_redolist.GetHead() ;
            m_redolist.RemoveHead();
           AddUndo(pFile);
           Load(pFile);
      }
}*/
#endif // UNDO_H
