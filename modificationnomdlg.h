#ifndef MODIFICATIONNOMDLG_H
#define MODIFICATIONNOMDLG_H

#include "ui_modificationnomdlg.h"
#include "ccompte.h"

class CCompte;

class ModificationNomDlg : public QDialog, private Ui::ModificationNomDlg
{
    Q_OBJECT

public:
    explicit ModificationNomDlg(const CCompte &compte, QWidget *parent = 0);
    CCompte compteModified() const { return m_compteApres; }

protected slots:
//  virtual void reject();
  virtual void accept();

private:
    QString formaterNomCategorie(const QString &nom);

    CCompte m_compteAvant;
    CCompte m_compteApres;
};

#endif // MODIFICATIONNOMDLG_H
