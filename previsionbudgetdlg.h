#ifndef PREVISIONBUDGETDLG_H
#define PREVISIONBUDGETDLG_H

#include "ui_previsionbudgetdlg.h"
#include "ccompte.h"

class CCompte;

class PrevisionBudgetDlg : public QDialog, private Ui::PrevisionBudgetDlg
{
    Q_OBJECT

public:
    explicit PrevisionBudgetDlg(const CCompte &compte, const QString &date, QWidget *parent = 0);
    CCompte compteModified() const { return m_compteApres; }
    QString chaineImprimable() const { return m_strChaineImprimable; }

private slots:
    void on_lineEditRevenu_textChanged();
    void on_lineEditDepense01_textChanged();
    void on_lineEditDepense02_textChanged();
    void on_lineEditDepense03_textChanged();
    void on_lineEditDepense04_textChanged();
    void on_lineEditDepense05_textChanged();
    void on_lineEditDepense06_textChanged();
    void on_lineEditDepense07_textChanged();
    void on_lineEditDepense08_textChanged();
    void on_lineEditDepense09_textChanged();
    void on_lineEditDepense10_textChanged();
    void on_lineEditDepense11_textChanged();
    void on_lineEditDepense12_textChanged();
    void on_lineEditDepense13_textChanged();
    void on_lineEditDepense14_textChanged();
    void on_lineEditDepense15_textChanged();
    void on_lineEditDepense16_textChanged();
    void on_lineEditDepense17_textChanged();
    void on_lineEditDepense18_textChanged();
    void on_lineEditDepense19_textChanged();

protected slots:
//  virtual void reject();
  virtual void accept();
private:
    void calculerMontantSolde();
    void afficherMontantSolde();

    void calculerMontantCat20();

    void afficherMontantBudget();
    QString formaterMontant(const QString &montant);

    CCompte m_compteAvant;
    CCompte m_compteApres;

    QString m_strChaineImprimable;

    QString m_strMontantSolde;
    double m_dMontantSolde;

    QString m_strMontantCat20;
    double m_dMontantCat20;

    double m_dMontantRevenu;

};

#endif // PREVISIONBUDGETDLG_H
