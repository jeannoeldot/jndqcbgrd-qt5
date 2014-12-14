#ifndef CREATIONCOMPTEDLG_H
#define CREATIONCOMPTEDLG_H

#include "ui_creationcomptedlg.h"
#include "ccompte.h"

class CCompte;

class CreationCompteDlg : public QDialog, private Ui::CreationCompteDlg
{
    Q_OBJECT

public:
    explicit CreationCompteDlg(QWidget *parent = 0);
    CCompte compteModified() const { return m_compteApres; }

private slots:
    void on_lineEditMontant01_textChanged();
    void on_lineEditMontant02_textChanged();
    void on_lineEditMontant03_textChanged();
    void on_lineEditMontant04_textChanged();
    void on_lineEditMontant05_textChanged();
    void on_lineEditMontant06_textChanged();
    void on_lineEditMontant07_textChanged();
    void on_lineEditMontant08_textChanged();
    void on_lineEditMontant09_textChanged();
    void on_lineEditMontant10_textChanged();
    void on_lineEditMontant11_textChanged();
    void on_lineEditMontant12_textChanged();
    void on_lineEditMontant13_textChanged();
    void on_lineEditMontant14_textChanged();
    void on_lineEditMontant15_textChanged();
    void on_lineEditMontant16_textChanged();
    void on_lineEditMontant17_textChanged();
    void on_lineEditMontant18_textChanged();
    void on_lineEditMontant19_textChanged();
    void on_lineEditMontant20_textChanged();

private:
    void calculerMontantSolde();
    void afficherMontantSolde();
    QString formaterNomCategorie(const QString &nom);
    QString formaterMontant(const QString &montant);

    CCompte m_compteApres;

    QString m_strMontantSolde;
    double m_dMontantSolde;

protected slots:
//  virtual void reject();
  virtual void accept();
};

#endif // CREATIONCOMPTEDLG_H
