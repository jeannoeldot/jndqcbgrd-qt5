#ifndef ENTREEUNMOUVEMENTDLG_H
#define ENTREEUNMOUVEMENTDLG_H

#include "ui_entreeunmouvementdlg.h"

class EntreeUnMouvementDlg : public QDialog, private Ui::EntreeUnMouvementDlg
{
    Q_OBJECT

public:
    explicit EntreeUnMouvementDlg(const QString &nomcategorie, QWidget *parent = 0);
    QString chaineImprimable() const { return m_strChaineImprimable; }
    double montant() const { return m_dMontant; }
    QPoint position() const { return m_posDlg; }

protected slots:
//  virtual void reject();
  virtual void accept();

private slots:
    void on_lineEditDate_textChanged(const QString &arg1);
    void on_lineEditNumChq_textChanged(const QString &arg1);
    void on_lineEditBenef_textChanged(const QString &arg1);
    void on_lineEditMontant_textChanged();

private:
    QString formaterMontant(const QString &montant);
    QString formaterEntree(const QString &entree, const int nbcar);

    double m_dMontant;
    QString m_strChaineImprimable;

    QPoint m_posDlg;

};

#endif // ENTREEUNMOUVEMENTDLG_H
