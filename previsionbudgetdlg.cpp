#include <QDebug>
//#include <QtGui/QRegExpValidator>
#include <QRegExpValidator>
#include "previsionbudgetdlg.h"

#include "constantes.h"
#include "ccompte.h"

PrevisionBudgetDlg::PrevisionBudgetDlg(const CCompte &compte, const QString &date, QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    labelDateDuJour->setText(date);

    m_compteAvant = compte;
    m_compteApres = m_compteAvant;

    QRegExp regExp("[+][0-9]{1,5}[.][0-9]{2,2}");

    lineEditRevenu->setValidator(new QRegExpValidator(regExp, this));

    lineEditDepense01->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense02->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense03->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense04->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense05->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense06->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense07->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense08->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense09->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense10->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense11->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense12->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense13->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense14->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense15->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense16->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense17->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense18->setValidator(new QRegExpValidator(regExp, this));
    lineEditDepense19->setValidator(new QRegExpValidator(regExp, this));

    labelNom01->setText(m_compteApres.nomCategorie01());
    labelNom02->setText(m_compteApres.nomCategorie02());
    labelNom03->setText(m_compteApres.nomCategorie03());
    labelNom04->setText(m_compteApres.nomCategorie04());
    labelNom05->setText(m_compteApres.nomCategorie05());
    labelNom06->setText(m_compteApres.nomCategorie06());
    labelNom07->setText(m_compteApres.nomCategorie07());
    labelNom08->setText(m_compteApres.nomCategorie08());
    labelNom09->setText(m_compteApres.nomCategorie09());
    labelNom10->setText(m_compteApres.nomCategorie10());
    labelNom11->setText(m_compteApres.nomCategorie11());
    labelNom12->setText(m_compteApres.nomCategorie12());
    labelNom13->setText(m_compteApres.nomCategorie13());
    labelNom14->setText(m_compteApres.nomCategorie14());
    labelNom15->setText(m_compteApres.nomCategorie15());
    labelNom16->setText(m_compteApres.nomCategorie16());
    labelNom17->setText(m_compteApres.nomCategorie17());
    labelNom18->setText(m_compteApres.nomCategorie18());
    labelNom19->setText(m_compteApres.nomCategorie19());
    labelNom20->setText(m_compteApres.nomCategorie20());
    labelNomSolde->setText(m_compteApres.nomSolde());

//    m_strMontantSolde = m_compteApres.montantSolde();
    m_strMontantSolde = m_compteAvant.montantSolde();
    m_dMontantSolde = m_strMontantSolde.toDouble();

    afficherMontantSolde();
    afficherMontantBudget();
}

//void CreationCompteDlg::reject()
//{
//    QDialog::reject();
//}

void PrevisionBudgetDlg::accept()
{
    m_strChaineImprimable = "REVENU(S) ET BUDGET / DEPENSES :" + FINLIGNE;
    m_strChaineImprimable += FINLIGNE;
    m_strChaineImprimable += "Montant Revenu(s)/Pension(s) : ";
    m_strChaineImprimable += formaterMontant(lineEditRevenu->text()) + FINLIGNE;
    m_strChaineImprimable += FINLIGNE;
    m_strChaineImprimable += "CATEGORIE     " + ESPACES3 + "PRÉVISION" + ESPACES3 + "  BUDGET " + FINLIGNE;
    m_strChaineImprimable += FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie01() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense01->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie01()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie02() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense02->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie02()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie03() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense03->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie03()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie04() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense04->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie04()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie05() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense05->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie05()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie06() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense06->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie06()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie07() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense07->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie07()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie08() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense08->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie08()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie09() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense09->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie09()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie10() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense10->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie10()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie11() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense11->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie11()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie12() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense12->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie12()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie13() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense13->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie13()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie14() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense14->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie14()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie15() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense15->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie15()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie16() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense16->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie16()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie17() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense17->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie17()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie18() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense18->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie18()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie19() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense19->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie19()) + FINLIGNE;
    m_strChaineImprimable += m_compteApres.nomCategorie20() + ESPACES3;
    m_strChaineImprimable += formaterMontant(lineEditDepense20->text()) + ESPACES3;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantCategorie20()) + FINLIGNE;
    m_strChaineImprimable += FINLIGNE;
    m_strChaineImprimable += ESPACES9 + ESPACES5 + m_compteApres.nomSolde() + ESPACE1;
    m_strChaineImprimable += formaterMontant(m_compteApres.montantSolde()) + FINLIGNE;

    QDialog::accept();
}

void PrevisionBudgetDlg::on_lineEditRevenu_textChanged()
{
    bool mntok = lineEditRevenu->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense01->setPlaceholderText("+12345.67");
        lineEditDepense01->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense01_textChanged()
{
    bool mntok = lineEditDepense01->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense01->text();
        // qDebug() << "QString lineEditDepense01 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie01();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 01 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie01(str);
        }

        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense02->setPlaceholderText("+12345.67");
        lineEditDepense02->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense02_textChanged()
{
    bool mntok = lineEditDepense02->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense02->text();
        // qDebug() << "QString lineEditDepense02 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie02();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 02 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie02(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense03->setPlaceholderText("+12345.67");
        lineEditDepense03->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense03_textChanged()
{
    bool mntok = lineEditDepense03->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense03->text();
        // qDebug() << "QString lineEditDepense03 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie03();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 03 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie03(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense04->setPlaceholderText("+12345.67");
        lineEditDepense04->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense04_textChanged()
{
    bool mntok = lineEditDepense04->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense04->text();
        // qDebug() << "QString lineEditDepense04 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie04();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 04 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie04(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense05->setPlaceholderText("+12345.67");
        lineEditDepense05->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense05_textChanged()
{
    bool mntok = lineEditDepense05->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense05->text();
        // qDebug() << "QString lineEditDepense05 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie05();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 05 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie05(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense06->setPlaceholderText("+12345.67");
        lineEditDepense06->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense06_textChanged()
{
    bool mntok = lineEditDepense06->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense06->text();
        // qDebug() << "QString lineEditDepense06 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie06();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 06 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie06(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense07->setPlaceholderText("+12345.67");
        lineEditDepense07->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense07_textChanged()
{
    bool mntok = lineEditDepense07->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense07->text();
        // qDebug() << "QString lineEditDepense07 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie07();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 07 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie07(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense08->setPlaceholderText("+12345.67");
        lineEditDepense08->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense08_textChanged()
{
    bool mntok = lineEditDepense08->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense08->text();
        // qDebug() << "QString lineEditDepense08 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie08();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 08 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie08(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense09->setPlaceholderText("+12345.67");
        lineEditDepense09->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense09_textChanged()
{
    bool mntok = lineEditDepense09->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense09->text();
        // qDebug() << "QString lineEditDepense09 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie09();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 09 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie09(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense10->setPlaceholderText("+12345.67");
        lineEditDepense10->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense10_textChanged()
{
    bool mntok = lineEditDepense10->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense10->text();
        // qDebug() << "QString lineEditDepense10 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie10();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 10 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie10(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense11->setPlaceholderText("+12345.67");
        lineEditDepense11->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense11_textChanged()
{
    bool mntok = lineEditDepense11->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense11->text();
        // qDebug() << "QString lineEditDepense11 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie11();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 11 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie11(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense12->setPlaceholderText("+12345.67");
        lineEditDepense12->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense12_textChanged()
{
    bool mntok = lineEditDepense12->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense12->text();
        // qDebug() << "QString lineEditDepense12 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie12();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 12 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie12(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense13->setPlaceholderText("+12345.67");
        lineEditDepense13->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense13_textChanged()
{
    bool mntok = lineEditDepense13->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense13->text();
        // qDebug() << "QString lineEditDepense13 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie13();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 13 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie13(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense14->setPlaceholderText("+12345.67");
        lineEditDepense14->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense14_textChanged()
{
    bool mntok = lineEditDepense14->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense14->text();
        // qDebug() << "QString lineEditDepense14 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie14();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 14 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie14(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense15->setPlaceholderText("+12345.67");
        lineEditDepense15->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense15_textChanged()
{
    bool mntok = lineEditDepense15->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense15->text();
        // qDebug() << "QString lineEditDepense15 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie15();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 15 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie15(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense16->setPlaceholderText("+12345.67");
        lineEditDepense16->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense16_textChanged()
{
    bool mntok = lineEditDepense16->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense16->text();
        // qDebug() << "QString lineEditDepense16 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie16();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 16 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie16(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense17->setPlaceholderText("+12345.67");
        lineEditDepense17->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense17_textChanged()
{
    bool mntok = lineEditDepense17->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense17->text();
        // qDebug() << "QString lineEditDepense17 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie17();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 17 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie17(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense18->setPlaceholderText("+12345.67");
        lineEditDepense18->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense18_textChanged()
{
    bool mntok = lineEditDepense18->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense18->text();
        // qDebug() << "QString lineEditDepense18 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie18();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 18 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie18(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        lineEditDepense19->setPlaceholderText("+12345.67");
        lineEditDepense19->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::on_lineEditDepense19_textChanged()
{
    bool mntok = lineEditDepense19->hasAcceptableInput();
    if(true == mntok)
    {
        QString str = "";
        bool ok;
        double d;
        double davant;

        str = lineEditDepense19->text();
        // qDebug() << "QString lineEditDepense19 :" << str;
        d = str.toDouble(&ok);
        if( true == ok )
        {
            str = m_compteAvant.montantCategorie19();
            davant = str.toDouble();
            davant = davant + d;
            // qDebug() << "double 19 apres :" << davant;
            str = QString::number(davant, 'f', 2);
            // qDebug() << "QString str :" << str;
            m_compteApres.setMontantCategorie19(str);
        }
        calculerMontantCat20();
        afficherMontantBudget();
        accepterButton->setEnabled(mntok);
    }
}

void PrevisionBudgetDlg::calculerMontantSolde()
{
    m_strMontantSolde = m_compteAvant.montantSolde();
    m_dMontantSolde = m_strMontantSolde.toDouble();

    QString str = "";
    bool ok;
    double d;

    str = lineEditRevenu->text();
    // qDebug() << "QString lineEditRevenu :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        m_dMontantRevenu = d;
        m_dMontantSolde = m_dMontantSolde + d;
        // qDebug() << "double m_dMontantSolde :" << m_dMontantSolde;
    }
    m_strMontantSolde = QString::number(m_dMontantSolde, 'f', 2);
    // qDebug() << "QString m_strMontantSolde :" << m_strMontantSolde;

    m_compteApres.setMontantSolde(m_strMontantSolde);
}

void PrevisionBudgetDlg::afficherMontantSolde()
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

void PrevisionBudgetDlg::calculerMontantCat20()
{
    QString strMntAvant20 = m_compteAvant.montantCategorie20();
    double dMntAvant20 = strMntAvant20.toDouble();
    // qDebug() << "Double Avant 20 :" << dMntAvant20;

    // CALCUL SOMME DES ENTREES DEPENSES 01 A 19
    QString str = "";
    double dsumcat = 0.00;
    bool ok;
    double d;

    str = lineEditDepense01->text();
    // qDebug() << "QString lineEditDepense01 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense02->text();
     // qDebug() << "QString lineEditDepense02 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense03->text();
     // qDebug() << "QString lineEditDepense03 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense04->text();
     // qDebug() << "QString lineEditDepense04 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense05->text();
     // qDebug() << "QString lineEditDepense05 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense06->text();
     // qDebug() << "QString lineEditDepense06 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense07->text();
     // qDebug() << "QString lineEditDepense07 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense08->text();
     // qDebug() << "QString lineEditDepense08 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense09->text();
     // qDebug() << "QString lineEditDepense09 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense10->text();
     // qDebug() << "QString lineEditDepense10 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense11->text();
     // qDebug() << "QString lineEditDepense11 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense12->text();
     // qDebug() << "QString lineEditDepense12 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense13->text();
     // qDebug() << "QString lineEditDepense13 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense14->text();
     // qDebug() << "QString lineEditDepense14 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense15->text();
     // qDebug() << "QString lineEditDepense15 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense16->text();
     // qDebug() << "QString lineEditDepense16 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense17->text();
     // qDebug() << "QString lineEditDepense17 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense18->text();
     // qDebug() << "QString lineEditDepense18 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }
    str = lineEditDepense19->text();
     // qDebug() << "QString lineEditDepense19 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dsumcat = dsumcat + d;
         // qDebug() << "double dsumcat :" << dsumcat;
    }

    // ICI : dsumcat = Somme des entrées DEPENSES 01 A 19
    // qDebug() << "Double Somme des entrées :" << dsumcat;

    // CALCUL MONTANT ENTREE 20
    d = m_dMontantRevenu - dsumcat;
    // qDebug() << "Double CALCUL MONTANT ENTREE 20 :" << d;

    str = QString::number(d, 'f', 2);
    lineEditDepense20->setText(str);

    dMntAvant20 = dMntAvant20 + m_dMontantRevenu;
    // qDebug() << "Double Avant + Revenu :" << dMntAvant20;

    dMntAvant20 = dMntAvant20 - dsumcat;
    // qDebug() << "Double Avant + Revenu - Somme entrées :" << dMntAvant20;

    m_dMontantCat20 = dMntAvant20;
    m_strMontantCat20 = QString::number(m_dMontantCat20, 'f', 2);
     // qDebug() << "QString m_strMontantCat20 :" << m_strMontantCat20;

    m_compteApres.setMontantCategorie20(m_strMontantCat20);
}

//void PrevisionBudgetDlg::afficherMontantCat14()
//{
//    labelBudget14->setText(m_compteApres.montantCategorie14());
//}

void PrevisionBudgetDlg::afficherMontantBudget()
{
    labelBudget01->setText(m_compteApres.montantCategorie01());
    labelBudget02->setText(m_compteApres.montantCategorie02());
    labelBudget03->setText(m_compteApres.montantCategorie03());
    labelBudget04->setText(m_compteApres.montantCategorie04());
    labelBudget05->setText(m_compteApres.montantCategorie05());
    labelBudget06->setText(m_compteApres.montantCategorie06());
    labelBudget07->setText(m_compteApres.montantCategorie07());
    labelBudget08->setText(m_compteApres.montantCategorie08());
    labelBudget09->setText(m_compteApres.montantCategorie09());
    labelBudget10->setText(m_compteApres.montantCategorie10());
    labelBudget11->setText(m_compteApres.montantCategorie11());
    labelBudget12->setText(m_compteApres.montantCategorie12());
    labelBudget13->setText(m_compteApres.montantCategorie13());
    labelBudget14->setText(m_compteApres.montantCategorie14());
    labelBudget15->setText(m_compteApres.montantCategorie15());
    labelBudget16->setText(m_compteApres.montantCategorie16());
    labelBudget17->setText(m_compteApres.montantCategorie17());
    labelBudget18->setText(m_compteApres.montantCategorie18());
    labelBudget19->setText(m_compteApres.montantCategorie19());
    labelBudget20->setText(m_compteApres.montantCategorie20());
}

QString PrevisionBudgetDlg::formaterMontant(const QString &montant)
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
