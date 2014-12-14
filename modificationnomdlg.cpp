#include <QDebug>

#include "modificationnomdlg.h"

#include "constantes.h"
#include "ccompte.h"

ModificationNomDlg::ModificationNomDlg(const CCompte &compte, QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    m_compteAvant = compte;
    m_compteApres = m_compteAvant;

    labelNom01->setText(m_compteAvant.nomCategorie01());
    labelNom02->setText(m_compteAvant.nomCategorie02());
    labelNom03->setText(m_compteAvant.nomCategorie03());
    labelNom04->setText(m_compteAvant.nomCategorie04());
    labelNom05->setText(m_compteAvant.nomCategorie05());
    labelNom06->setText(m_compteAvant.nomCategorie06());
    labelNom07->setText(m_compteAvant.nomCategorie07());
    labelNom08->setText(m_compteAvant.nomCategorie08());
    labelNom09->setText(m_compteAvant.nomCategorie09());
    labelNom10->setText(m_compteAvant.nomCategorie10());
    labelNom11->setText(m_compteAvant.nomCategorie11());
    labelNom12->setText(m_compteAvant.nomCategorie12());
    labelNom13->setText(m_compteAvant.nomCategorie13());
    labelNom14->setText(m_compteAvant.nomCategorie14());
    labelNom15->setText(m_compteAvant.nomCategorie15());
    labelNom16->setText(m_compteAvant.nomCategorie16());
    labelNom17->setText(m_compteAvant.nomCategorie17());
    labelNom18->setText(m_compteAvant.nomCategorie18());
    labelNom19->setText(m_compteAvant.nomCategorie19());
    labelNom20->setText(m_compteAvant.nomCategorie20());

    lineEditNom01->setText(m_compteApres.nomCategorie01());
    lineEditNom02->setText(m_compteApres.nomCategorie02());
    lineEditNom03->setText(m_compteApres.nomCategorie03());
    lineEditNom04->setText(m_compteApres.nomCategorie04());
    lineEditNom05->setText(m_compteApres.nomCategorie05());
    lineEditNom06->setText(m_compteApres.nomCategorie06());
    lineEditNom07->setText(m_compteApres.nomCategorie07());
    lineEditNom08->setText(m_compteApres.nomCategorie08());
    lineEditNom09->setText(m_compteApres.nomCategorie09());
    lineEditNom10->setText(m_compteApres.nomCategorie10());
    lineEditNom11->setText(m_compteApres.nomCategorie11());
    lineEditNom12->setText(m_compteApres.nomCategorie12());
    lineEditNom13->setText(m_compteApres.nomCategorie13());
    lineEditNom14->setText(m_compteApres.nomCategorie14());
    lineEditNom15->setText(m_compteApres.nomCategorie15());
    lineEditNom16->setText(m_compteApres.nomCategorie16());
    lineEditNom17->setText(m_compteApres.nomCategorie17());
    lineEditNom18->setText(m_compteApres.nomCategorie18());
    lineEditNom19->setText(m_compteApres.nomCategorie19());
    lineEditNom20->setText(m_compteApres.nomCategorie20());
}

//void CreationCompteDlg::reject()
//{
//    QDialog::reject();
//}

void ModificationNomDlg::accept()
{
    m_compteApres.setNomCategorie01(formaterNomCategorie(lineEditNom01->text()));
    m_compteApres.setNomCategorie02(formaterNomCategorie(lineEditNom02->text()));
    m_compteApres.setNomCategorie03(formaterNomCategorie(lineEditNom03->text()));
    m_compteApres.setNomCategorie04(formaterNomCategorie(lineEditNom04->text()));
    m_compteApres.setNomCategorie05(formaterNomCategorie(lineEditNom05->text()));
    m_compteApres.setNomCategorie06(formaterNomCategorie(lineEditNom06->text()));
    m_compteApres.setNomCategorie07(formaterNomCategorie(lineEditNom07->text()));
    m_compteApres.setNomCategorie08(formaterNomCategorie(lineEditNom08->text()));
    m_compteApres.setNomCategorie09(formaterNomCategorie(lineEditNom09->text()));
    m_compteApres.setNomCategorie10(formaterNomCategorie(lineEditNom10->text()));
    m_compteApres.setNomCategorie11(formaterNomCategorie(lineEditNom11->text()));
    m_compteApres.setNomCategorie12(formaterNomCategorie(lineEditNom12->text()));
    m_compteApres.setNomCategorie13(formaterNomCategorie(lineEditNom13->text()));
    m_compteApres.setNomCategorie14(formaterNomCategorie(lineEditNom14->text()));
    m_compteApres.setNomCategorie15(formaterNomCategorie(lineEditNom15->text()));
    m_compteApres.setNomCategorie16(formaterNomCategorie(lineEditNom16->text()));
    m_compteApres.setNomCategorie17(formaterNomCategorie(lineEditNom17->text()));
    m_compteApres.setNomCategorie18(formaterNomCategorie(lineEditNom18->text()));
    m_compteApres.setNomCategorie19(formaterNomCategorie(lineEditNom19->text()));
    m_compteApres.setNomCategorie20("ECONOMIE=RESTE");

    QDialog::accept();
}

QString ModificationNomDlg::formaterNomCategorie(const QString &nom)
{
    QString str = "";
    if (nom.length() < 14)
    {
        int nbespaces = 14 - nom.length();
        str = nom;
        for (int i = 0; i < nbespaces; ++i)
        {
            str += " ";
        }
    }
    else
    {
        str = nom;
    }
    str.replace(SEPARATEUR, " ");
    // qDebug() << "ModificationNomDlg:: QString nom catégorie formaté :" << str;
    return str;
}
