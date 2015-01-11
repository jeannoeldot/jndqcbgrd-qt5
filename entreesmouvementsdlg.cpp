#include <QDebug>
#include "entreesmouvementsdlg.h"
#include "entreeunmouvementdlg.h"

#include "constantes.h"
#include "ccompte.h"

EntreesMouvementsDlg::EntreesMouvementsDlg(const CCompte &compte, const QString &date, QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    labelDateDuJour->setText(date);

    m_compteAvant = compte;
    m_compteApres = m_compteAvant;

    buttonCategorie01->setText(m_compteAvant.nomCategorie01());
    buttonCategorie02->setText(m_compteAvant.nomCategorie02());
    buttonCategorie03->setText(m_compteAvant.nomCategorie03());
    buttonCategorie04->setText(m_compteAvant.nomCategorie04());
    buttonCategorie05->setText(m_compteAvant.nomCategorie05());
    buttonCategorie06->setText(m_compteAvant.nomCategorie06());
    buttonCategorie07->setText(m_compteAvant.nomCategorie07());
    buttonCategorie08->setText(m_compteAvant.nomCategorie08());
    buttonCategorie09->setText(m_compteAvant.nomCategorie09());
    buttonCategorie10->setText(m_compteAvant.nomCategorie10());
    buttonCategorie11->setText(m_compteAvant.nomCategorie11());
    buttonCategorie12->setText(m_compteAvant.nomCategorie12());
    buttonCategorie13->setText(m_compteAvant.nomCategorie13());
    buttonCategorie14->setText(m_compteAvant.nomCategorie14());
    buttonCategorie15->setText(m_compteAvant.nomCategorie15());
    buttonCategorie16->setText(m_compteAvant.nomCategorie16());
    buttonCategorie17->setText(m_compteAvant.nomCategorie17());
    buttonCategorie18->setText(m_compteAvant.nomCategorie18());
    buttonCategorie19->setText(m_compteAvant.nomCategorie19());
    buttonCategorie20->setText(m_compteAvant.nomCategorie20());

    labelNomSolde->setText(m_compteAvant.nomSolde());

    labelMontantCategorie01->setText(m_compteAvant.montantCategorie01());
    labelMontantCategorie02->setText(m_compteAvant.montantCategorie02());
    labelMontantCategorie03->setText(m_compteAvant.montantCategorie03());
    labelMontantCategorie04->setText(m_compteAvant.montantCategorie04());
    labelMontantCategorie05->setText(m_compteAvant.montantCategorie05());
    labelMontantCategorie06->setText(m_compteAvant.montantCategorie06());
    labelMontantCategorie07->setText(m_compteAvant.montantCategorie07());
    labelMontantCategorie08->setText(m_compteAvant.montantCategorie08());
    labelMontantCategorie09->setText(m_compteAvant.montantCategorie09());
    labelMontantCategorie10->setText(m_compteAvant.montantCategorie10());
    labelMontantCategorie11->setText(m_compteAvant.montantCategorie11());
    labelMontantCategorie12->setText(m_compteAvant.montantCategorie12());
    labelMontantCategorie13->setText(m_compteAvant.montantCategorie13());
    labelMontantCategorie14->setText(m_compteAvant.montantCategorie14());
    labelMontantCategorie15->setText(m_compteAvant.montantCategorie15());
    labelMontantCategorie16->setText(m_compteAvant.montantCategorie16());
    labelMontantCategorie17->setText(m_compteAvant.montantCategorie17());
    labelMontantCategorie18->setText(m_compteAvant.montantCategorie18());
    labelMontantCategorie19->setText(m_compteAvant.montantCategorie19());
    labelMontantCategorie20->setText(m_compteAvant.montantCategorie20());

    m_strMontantSolde = m_compteAvant.montantSolde();
    m_dMontantSolde = m_strMontantSolde.toDouble();
    afficherMontantSolde();

    m_strTextEdit = "";
    textEdit->clear();

    m_funeEntree = false;
    autoriserBoutonAccepter(m_funeEntree);

    m_fposDlgConnu = false;
}

//void EntreesMouvementsDlg::reject()
//{
//    QDialog::reject();
//}

void EntreesMouvementsDlg::accept()
{
//    m_strChaineImprimable
    m_strChaineImprimable = "LISTE DES MOUVEMENTS SUR LE COMPTE :" + FINLIGNE;
    m_strChaineImprimable += FINLIGNE;
    m_strChaineImprimable += "NC   DATE   MOTIFS BÉNÉFICIAIRES                              DÉBIT     CRÉDIT " + FINLIGNE;
    m_strChaineImprimable += m_strTextEdit;

    m_compteApres.setMontantCategorie01(formaterMontant(m_compteAvant.montantCategorie01()));
    m_compteApres.setMontantCategorie02(formaterMontant(m_compteAvant.montantCategorie02()));
    m_compteApres.setMontantCategorie03(formaterMontant(m_compteAvant.montantCategorie03()));
    m_compteApres.setMontantCategorie04(formaterMontant(m_compteAvant.montantCategorie04()));
    m_compteApres.setMontantCategorie05(formaterMontant(m_compteAvant.montantCategorie05()));
    m_compteApres.setMontantCategorie06(formaterMontant(m_compteAvant.montantCategorie06()));
    m_compteApres.setMontantCategorie07(formaterMontant(m_compteAvant.montantCategorie07()));
    m_compteApres.setMontantCategorie08(formaterMontant(m_compteAvant.montantCategorie08()));
    m_compteApres.setMontantCategorie09(formaterMontant(m_compteAvant.montantCategorie09()));
    m_compteApres.setMontantCategorie10(formaterMontant(m_compteAvant.montantCategorie10()));
    m_compteApres.setMontantCategorie11(formaterMontant(m_compteAvant.montantCategorie11()));
    m_compteApres.setMontantCategorie12(formaterMontant(m_compteAvant.montantCategorie12()));
    m_compteApres.setMontantCategorie13(formaterMontant(m_compteAvant.montantCategorie13()));
    m_compteApres.setMontantCategorie14(formaterMontant(m_compteAvant.montantCategorie14()));
    m_compteApres.setMontantCategorie15(formaterMontant(m_compteAvant.montantCategorie15()));
    m_compteApres.setMontantCategorie16(formaterMontant(m_compteAvant.montantCategorie16()));
    m_compteApres.setMontantCategorie17(formaterMontant(m_compteAvant.montantCategorie17()));
    m_compteApres.setMontantCategorie18(formaterMontant(m_compteAvant.montantCategorie18()));
    m_compteApres.setMontantCategorie19(formaterMontant(m_compteAvant.montantCategorie19()));
    m_compteApres.setMontantCategorie20(formaterMontant(m_compteAvant.montantCategorie20()));

    m_compteApres.setMontantSolde(formaterMontant(m_compteAvant.montantSolde()));

    QDialog::accept();
}

void EntreesMouvementsDlg::on_buttonCategorie01_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie01(), "01", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie01();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie01(formaterMontant(mntapres));
        labelMontantCategorie01->setText(m_compteAvant.montantCategorie01());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "01 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie02_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie02(), "02", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie02();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie02(formaterMontant(mntapres));
        labelMontantCategorie02->setText(m_compteAvant.montantCategorie02());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "02 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie03_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie03(), "03", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie03();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie03(formaterMontant(mntapres));
        labelMontantCategorie03->setText(m_compteAvant.montantCategorie03());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "03 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie04_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie04(), "04", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie04();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie04(formaterMontant(mntapres));
        labelMontantCategorie04->setText(m_compteAvant.montantCategorie04());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "04 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie05_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie05(), "05", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie05();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie05(formaterMontant(mntapres));
        labelMontantCategorie05->setText(m_compteAvant.montantCategorie05());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "05 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie06_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie06(), "06", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie06();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie06(formaterMontant(mntapres));
        labelMontantCategorie06->setText(m_compteAvant.montantCategorie06());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "06 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie07_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie07(), "07", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie07();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie07(formaterMontant(mntapres));
        labelMontantCategorie07->setText(m_compteAvant.montantCategorie07());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "07 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie08_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie08(), "08", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie08();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie08(formaterMontant(mntapres));
        labelMontantCategorie08->setText(m_compteAvant.montantCategorie08());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "08 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie09_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie09(), "09", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie09();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie09(formaterMontant(mntapres));
        labelMontantCategorie09->setText(m_compteAvant.montantCategorie09());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "09 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie10_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie10(), "10", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie10();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie10(formaterMontant(mntapres));
        labelMontantCategorie10->setText(m_compteAvant.montantCategorie10());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "10 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie11_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie11(), "11", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie11();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie11(formaterMontant(mntapres));
        labelMontantCategorie11->setText(m_compteAvant.montantCategorie11());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "11 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie12_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie12(), "12", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie12();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie12(formaterMontant(mntapres));
        labelMontantCategorie12->setText(m_compteAvant.montantCategorie12());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "12 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie13_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie13(), "13", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie13();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie13(formaterMontant(mntapres));
        labelMontantCategorie13->setText(m_compteAvant.montantCategorie13());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "13 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie14_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie14(), "14", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie14();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie14(formaterMontant(mntapres));
        labelMontantCategorie14->setText(m_compteAvant.montantCategorie14());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "14 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie15_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie15(), "15", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie15();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie15(formaterMontant(mntapres));
        labelMontantCategorie15->setText(m_compteAvant.montantCategorie15());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "15 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie16_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie16(), "16", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie16();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie16(formaterMontant(mntapres));
        labelMontantCategorie16->setText(m_compteAvant.montantCategorie16());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "16 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie17_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie17(), "17", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie17();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie17(formaterMontant(mntapres));
        labelMontantCategorie17->setText(m_compteAvant.montantCategorie17());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "17 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie18_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie18(), "18", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie18();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie18(formaterMontant(mntapres));
        labelMontantCategorie18->setText(m_compteAvant.montantCategorie18());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "18 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie19_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie19(), "19", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie19();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie19(formaterMontant(mntapres));
        labelMontantCategorie19->setText(m_compteAvant.montantCategorie19());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "19 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::on_buttonCategorie20_clicked()
{
    EntreeUnMouvementDlg dialog(m_compteAvant.nomCategorie20(), "20", this);
    if (true == m_fposDlgConnu)
    {
        dialog.move(m_posDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        double dentree = dialog.montant();
        QString mntavant = m_compteAvant.montantCategorie20();
        double davant = mntavant.toDouble();
        davant = davant + dentree;
        QString mntapres = QString::number(davant, 'f', 2);
        m_compteAvant.setMontantCategorie20(formaterMontant(mntapres));
        labelMontantCategorie20->setText(m_compteAvant.montantCategorie20());

        calculerMontantSolde(dentree);
        afficherMontantSolde();

        QString str = "20 ";
        str += dialog.chaineImprimable();
        m_strTextEdit += str + FINLIGNE;
        textEdit->append(str);

        m_funeEntree = true;
        autoriserBoutonAccepter(m_funeEntree);

        m_posDlg = dialog.position();
        m_fposDlgConnu = true;
    }
}

void EntreesMouvementsDlg::calculerMontantSolde(const double dentree)
{
    QString mntavant = m_compteAvant.montantSolde();
    double davant = mntavant.toDouble();
    davant = davant + dentree;
    QString mntapres = QString::number(davant, 'f', 2);
    m_compteAvant.setMontantSolde(formaterMontant(mntapres));
    m_strMontantSolde = m_compteAvant.montantSolde();
    m_dMontantSolde = m_strMontantSolde.toDouble();
}

void EntreesMouvementsDlg::afficherMontantSolde()
{
    QPalette palette;
    QBrush brush;
    QBrush brushRouge(QColor(255, 0, 0, 255));   // Rouge
    QBrush brushNoir(QColor(0, 0, 0, 255));   // Noir
    brush = brushNoir;
    if (m_dMontantSolde < 0.00)
    {
        brush = brushRouge;
    }
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    labelMontantSolde->setPalette(palette);
    labelMontantSolde->setText(m_strMontantSolde);
}

QString EntreesMouvementsDlg::formaterMontant(const QString &montant)
{
    QString str = "";
    if (montant.length() < 9)
    {
        int nbespaces = 9 - montant.length();
        for (int i = 0; i < nbespaces; ++i)
        {
            str += " ";
        }
        str += montant;
    }
    else
    {
        str = montant;
    }
    str.replace(SIGNE_PLUS, " ");
    // qDebug() << "QString montant formaté :" << str;
    return str;
}

void EntreesMouvementsDlg::autoriserBoutonAccepter(const bool f)
{
    accepterButton->setEnabled(f);
}
