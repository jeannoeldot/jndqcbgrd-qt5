#ifndef ENTREESMOUVEMENTSDLG_H
#define ENTREESMOUVEMENTSDLG_H

#include "ui_entreesmouvementsdlg.h"
#include "ccompte.h"

class CCompte;

class EntreesMouvementsDlg : public QDialog, private Ui::EntreesMouvementsDlg
{
    Q_OBJECT

public:
    explicit EntreesMouvementsDlg(const CCompte &compte, const QString &date, QWidget *parent = 0);
    CCompte compteModified() const { return m_compteApres; }
    QString chaineImprimable() const { return m_strChaineImprimable; }

private slots:

    void on_buttonCategorie01_clicked();
    void on_buttonCategorie02_clicked();
    void on_buttonCategorie03_clicked();
    void on_buttonCategorie04_clicked();
    void on_buttonCategorie05_clicked();
    void on_buttonCategorie06_clicked();
    void on_buttonCategorie07_clicked();
    void on_buttonCategorie08_clicked();
    void on_buttonCategorie09_clicked();
    void on_buttonCategorie10_clicked();
    void on_buttonCategorie11_clicked();
    void on_buttonCategorie12_clicked();
    void on_buttonCategorie13_clicked();
    void on_buttonCategorie14_clicked();
    void on_buttonCategorie15_clicked();
    void on_buttonCategorie16_clicked();
    void on_buttonCategorie17_clicked();
    void on_buttonCategorie18_clicked();
    void on_buttonCategorie19_clicked();
    void on_buttonCategorie20_clicked();

protected slots:
//  virtual void reject();
  virtual void accept();

private:
    QString formaterMontant(const QString &montant);

    void calculerMontantSolde(const double dentree);
    void afficherMontantSolde();

    void autoriserBoutonAccepter(const bool f);

    CCompte m_compteAvant;
    CCompte m_compteApres;

    QString m_strMontantSolde;
    double m_dMontantSolde;

    bool m_funeEntree;
    QString m_strTextEdit;

    QString m_strChaineImprimable;

    bool m_fposDlgConnu;
    QPoint m_posDlg;
};

#endif // ENTREESMOUVEMENTSDLG_H
