#include <QDebug>
#include "creationcomptedlg.h"
#include "constantes.h"

CreationCompteDlg::CreationCompteDlg(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    m_strMontantSolde = "";  // +0.00
    m_dMontantSolde = 0.00;

    QRegExp regExp("[-|+][0-9]{1,5}[.][0-9]{2,2}");

    lineEditMontant01->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant02->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant03->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant04->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant05->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant06->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant07->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant08->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant09->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant10->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant11->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant12->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant13->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant14->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant15->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant16->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant17->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant18->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant19->setValidator(new QRegExpValidator(regExp, this));
    lineEditMontant20->setValidator(new QRegExpValidator(regExp, this));

    lineEditNom20->setText("ECONOMIE=RESTE");

    labelNomSolde->setText("      SOLDE : ");

}

//void CreationCompteDlg::reject()
//{
//    QDialog::reject();
//}

void CreationCompteDlg::accept()
{    
    m_compteApres.setNomCategorie01(formaterNomCategorie(lineEditNom01->text()));
    m_compteApres.setMontantCategorie01(formaterMontant(lineEditMontant01->text()));
    m_compteApres.setNomCategorie02(formaterNomCategorie(lineEditNom02->text()));
    m_compteApres.setMontantCategorie02(formaterMontant(lineEditMontant02->text()));
    m_compteApres.setNomCategorie03(formaterNomCategorie(lineEditNom03->text()));
    m_compteApres.setMontantCategorie03(formaterMontant(lineEditMontant03->text()));
    m_compteApres.setNomCategorie04(formaterNomCategorie(lineEditNom04->text()));
    m_compteApres.setMontantCategorie04(formaterMontant(lineEditMontant04->text()));
    m_compteApres.setNomCategorie05(formaterNomCategorie(lineEditNom05->text()));
    m_compteApres.setMontantCategorie05(formaterMontant(lineEditMontant05->text()));
    m_compteApres.setNomCategorie06(formaterNomCategorie(lineEditNom06->text()));
    m_compteApres.setMontantCategorie06(formaterMontant(lineEditMontant06->text()));
    m_compteApres.setNomCategorie07(formaterNomCategorie(lineEditNom07->text()));
    m_compteApres.setMontantCategorie07(formaterMontant(lineEditMontant07->text()));
    m_compteApres.setNomCategorie08(formaterNomCategorie(lineEditNom08->text()));
    m_compteApres.setMontantCategorie08(formaterMontant(lineEditMontant08->text()));
    m_compteApres.setNomCategorie09(formaterNomCategorie(lineEditNom09->text()));
    m_compteApres.setMontantCategorie09(formaterMontant(lineEditMontant09->text()));
    m_compteApres.setNomCategorie10(formaterNomCategorie(lineEditNom10->text()));
    m_compteApres.setMontantCategorie10(formaterMontant(lineEditMontant10->text()));
    m_compteApres.setNomCategorie11(formaterNomCategorie(lineEditNom11->text()));
    m_compteApres.setMontantCategorie11(formaterMontant(lineEditMontant11->text()));
    m_compteApres.setNomCategorie12(formaterNomCategorie(lineEditNom12->text()));
    m_compteApres.setMontantCategorie12(formaterMontant(lineEditMontant12->text()));
    m_compteApres.setNomCategorie13(formaterNomCategorie(lineEditNom13->text()));
    m_compteApres.setMontantCategorie13(formaterMontant(lineEditMontant13->text()));
    m_compteApres.setNomCategorie14(formaterNomCategorie(lineEditNom14->text()));
    m_compteApres.setMontantCategorie14(formaterMontant(lineEditMontant14->text()));
    m_compteApres.setNomCategorie15(formaterNomCategorie(lineEditNom15->text()));
    m_compteApres.setMontantCategorie15(formaterMontant(lineEditMontant15->text()));
    m_compteApres.setNomCategorie16(formaterNomCategorie(lineEditNom16->text()));
    m_compteApres.setMontantCategorie16(formaterMontant(lineEditMontant16->text()));
    m_compteApres.setNomCategorie17(formaterNomCategorie(lineEditNom17->text()));
    m_compteApres.setMontantCategorie17(formaterMontant(lineEditMontant17->text()));
    m_compteApres.setNomCategorie18(formaterNomCategorie(lineEditNom18->text()));
    m_compteApres.setMontantCategorie18(formaterMontant(lineEditMontant18->text()));
    m_compteApres.setNomCategorie19(formaterNomCategorie(lineEditNom19->text()));
    m_compteApres.setMontantCategorie19(formaterMontant(lineEditMontant19->text()));

    m_compteApres.setNomCategorie20("ECONOMIE=RESTE");
    m_compteApres.setMontantCategorie20(formaterMontant(lineEditMontant20->text()));

    m_compteApres.setNomSolde("      SOLDE : ");
    m_compteApres.setMontantSolde(formaterMontant(m_strMontantSolde));

    QDialog::accept();
}

void CreationCompteDlg::on_lineEditMontant01_textChanged()
{
    bool mntok = lineEditMontant01->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom02->setPlaceholderText("Nom Catégorie");
        lineEditNom02->setEnabled(mntok);
        lineEditMontant02->setPlaceholderText("+/-12345.67");
        lineEditMontant02->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant02_textChanged()
{
    bool mntok = lineEditMontant02->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom03->setPlaceholderText("Nom Catégorie");
        lineEditNom03->setEnabled(mntok);
        lineEditMontant03->setPlaceholderText("+/-12345.67");
        lineEditMontant03->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant03_textChanged()
{
    bool mntok = lineEditMontant03->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom04->setPlaceholderText("Nom Catégorie");
        lineEditNom04->setEnabled(mntok);
        lineEditMontant04->setPlaceholderText("+/-12345.67");
        lineEditMontant04->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant04_textChanged()
{
    bool mntok = lineEditMontant04->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom05->setPlaceholderText("Nom Catégorie");
        lineEditNom05->setEnabled(mntok);
        lineEditMontant05->setPlaceholderText("+/-12345.67");
        lineEditMontant05->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant05_textChanged()
{
    bool mntok = lineEditMontant05->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom06->setPlaceholderText("Nom Catégorie");
        lineEditNom06->setEnabled(mntok);
        lineEditMontant06->setPlaceholderText("+/-12345.67");
        lineEditMontant06->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant06_textChanged()
{
    bool mntok = lineEditMontant06->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom07->setPlaceholderText("Nom Catégorie");
        lineEditNom07->setEnabled(mntok);
        lineEditMontant07->setPlaceholderText("+/-12345.67");
        lineEditMontant07->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant07_textChanged()
{
    bool mntok = lineEditMontant07->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom08->setPlaceholderText("Nom Catégorie");
        lineEditNom08->setEnabled(mntok);
        lineEditMontant08->setPlaceholderText("+/-12345.67");
        lineEditMontant08->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant08_textChanged()
{
    bool mntok = lineEditMontant08->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom09->setPlaceholderText("Nom Catégorie");
        lineEditNom09->setEnabled(mntok);
        lineEditMontant09->setPlaceholderText("+/-12345.67");
        lineEditMontant09->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant09_textChanged()
{
    bool mntok = lineEditMontant09->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom10->setPlaceholderText("Nom Catégorie");
        lineEditNom10->setEnabled(mntok);
        lineEditMontant10->setPlaceholderText("+/-12345.67");
        lineEditMontant10->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant10_textChanged()
{
    bool mntok = lineEditMontant10->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom11->setPlaceholderText("Nom Catégorie");
        lineEditNom11->setEnabled(mntok);
        lineEditMontant11->setPlaceholderText("+/-12345.67");
        lineEditMontant11->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant11_textChanged()
{
    bool mntok = lineEditMontant11->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom12->setPlaceholderText("Nom Catégorie");
        lineEditNom12->setEnabled(mntok);
        lineEditMontant12->setPlaceholderText("+/-12345.67");
        lineEditMontant12->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant12_textChanged()
{
    bool mntok = lineEditMontant12->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom13->setPlaceholderText("Nom Catégorie");
        lineEditNom13->setEnabled(mntok);
        lineEditMontant13->setPlaceholderText("+/-12345.67");
        lineEditMontant13->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant13_textChanged()
{
    bool mntok = lineEditMontant13->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom14->setPlaceholderText("Nom Catégorie");
        lineEditNom14->setEnabled(mntok);
        lineEditMontant14->setPlaceholderText("+/-12345.67");
        lineEditMontant14->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant14_textChanged()
{
    bool mntok = lineEditMontant14->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom15->setPlaceholderText("Nom Catégorie");
        lineEditNom15->setEnabled(mntok);
        lineEditMontant15->setPlaceholderText("+/-12345.67");
        lineEditMontant15->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant15_textChanged()
{
    bool mntok = lineEditMontant15->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom16->setPlaceholderText("Nom Catégorie");
        lineEditNom16->setEnabled(mntok);
        lineEditMontant16->setPlaceholderText("+/-12345.67");
        lineEditMontant16->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant16_textChanged()
{
    bool mntok = lineEditMontant16->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom17->setPlaceholderText("Nom Catégorie");
        lineEditNom17->setEnabled(mntok);
        lineEditMontant17->setPlaceholderText("+/-12345.67");
        lineEditMontant17->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant17_textChanged()
{
    bool mntok = lineEditMontant17->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom18->setPlaceholderText("Nom Catégorie");
        lineEditNom18->setEnabled(mntok);
        lineEditMontant18->setPlaceholderText("+/-12345.67");
        lineEditMontant18->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant18_textChanged()
{
    bool mntok = lineEditMontant18->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        lineEditNom19->setPlaceholderText("Nom Catégorie");
        lineEditNom19->setEnabled(mntok);
        lineEditMontant19->setPlaceholderText("+/-12345.67");
        lineEditMontant19->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant19_textChanged()
{
    bool mntok = lineEditMontant19->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
//        lineEditNom20->setPlaceholderText("Nom Catégorie");
//        lineEditNom20->setEnabled(mntok);
        lineEditMontant20->setPlaceholderText("+/-12345.67");
        lineEditMontant20->setEnabled(mntok);
    }
}

void CreationCompteDlg::on_lineEditMontant20_textChanged()
{
    bool mntok = lineEditMontant20->hasAcceptableInput();
    if(true == mntok)
    {
        calculerMontantSolde();
        afficherMontantSolde();
        accepterButton->setEnabled(mntok);
    }
}

void CreationCompteDlg::calculerMontantSolde()
{
    double dmntsolde = 0.00;
    QString str = "";
    bool ok;
    double d;

    str = lineEditMontant01->text();
    // qDebug() << "QString lineEditMontant01 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant02->text();
    // qDebug() << "QString lineEditMontant02 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant03->text();
    // qDebug() << "QString lineEditMontant03 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant04->text();
    // qDebug() << "QString lineEditMontant04 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant05->text();
    // qDebug() << "QString lineEditMontant05 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant06->text();
    // qDebug() << "QString lineEditMontant06 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant07->text();
    // qDebug() << "QString lineEditMontant07 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant08->text();
    // qDebug() << "QString lineEditMontant08 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant09->text();
    // qDebug() << "QString lineEditMontant09 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant10->text();
    // qDebug() << "QString lineEditMontant10 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant11->text();
    // qDebug() << "QString lineEditMontant11 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant12->text();
    // qDebug() << "QString lineEditMontant12 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant13->text();
    // qDebug() << "QString lineEditMontant13 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant14->text();
    // qDebug() << "QString lineEditMontant14 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant15->text();
    // qDebug() << "QString lineEditMontant15 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant16->text();
    // qDebug() << "QString lineEditMontant16 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant17->text();
    // qDebug() << "QString lineEditMontant17 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant18->text();
    // qDebug() << "QString lineEditMontant18 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant19->text();
    // qDebug() << "QString lineEditMontant19 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }
    str = lineEditMontant20->text();
    // qDebug() << "QString lineEditMontant20 :" << str;
    d = str.toDouble(&ok);
    if( true == ok )
    {
        dmntsolde = dmntsolde + d;
        // qDebug() << "double dmntsolde :" << dmntsolde;
    }

    m_dMontantSolde = dmntsolde;
    m_strMontantSolde = QString::number(dmntsolde, 'f', 2);
    // qDebug() << "QString m_strMontantSolde :" << m_strMontantSolde;
}

void CreationCompteDlg::afficherMontantSolde()
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

QString CreationCompteDlg::formaterNomCategorie(const QString &nom)
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
//    qDebug() << "QString nom catégorie formaté :" << str;
    return str;
}

QString CreationCompteDlg::formaterMontant(const QString &montant)
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

